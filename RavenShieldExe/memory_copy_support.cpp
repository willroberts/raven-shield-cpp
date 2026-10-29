#include "native_symbols.hpp"
// Executable appMemcpy specialization; SSE/MMX paths retain native transfer groups, prefetches and fences.
#include "allocation_support.hpp"
#include <mmintrin.h>
#include <xmmintrin.h>

extern "C" int32_t GIsSSE; // Core.dll data import at IAT 1091405c.

// RavenShield.exe @ 10904de0 : CopyExecutableMemory
// Copy with CPU/size-selected forward MMX paths; the REP fallback inherits DF and neither path handles overlap.
void __cdecl CopyExecutableMemory(void *destination, const void *source, uint32_t count)
{
  if (GIsSSE == 0)
  {
    __asm {
      push ebx
      push esi
      push edi
      mov ecx, count
      mov esi, source
      mov edi, destination
      mov ebx, ecx
      shr ecx, 2
      and ebx, 3
      rep movsd
      mov ecx, ebx
      rep movsb
      pop edi
      pop esi
      pop ebx
    }
    return;
  }
  __asm cld
  auto *to = reinterpret_cast<uint8_t *>(destination);
  auto *from = reinterpret_cast<const uint8_t *>(source);
  uint32_t remaining = count;
  if (count >= 0x40)
  {
    if (count <= 0x8000 || count > 0x10000)
    {
      const uint32_t prefix = (8u - reinterpret_cast<uint32_t>(to)) & 7;
      remaining -= prefix;
      for (uint32_t i = 0; i < prefix; ++i) *to++ = *from++;
    }
    uint32_t blocks = remaining >> 6;
    if (blocks < 0x400)
    {
      while (blocks != 0)
      {
        _mm_prefetch(reinterpret_cast<const char *>(from + 0x238), _MM_HINT_NTA);
        for (uint32_t offset = 0; offset < 0x40; offset += 0x10)
        {
          const __m64 first = *reinterpret_cast<const __m64 __unaligned *>(from + offset);
          const __m64 second = *reinterpret_cast<const __m64 __unaligned *>(from + offset + 8);
          *reinterpret_cast<__m64 __unaligned *>(to + offset) = first;
          *reinterpret_cast<__m64 __unaligned *>(to + offset + 8) = second;
        }
        from += 0x40;
        to += 0x40;
        --blocks;
      }
    }
    else
    {
      if (blocks >= 0xc50)
      {
        while (static_cast<int32_t>(blocks) >= 0x80)
        {
          const uint8_t *touch = from + 0x2000;
          for (uint32_t i = 0; i < 0x40; ++i)
          {
            (void)*reinterpret_cast<const volatile uint32_t *>(touch - 0x40);
            (void)*reinterpret_cast<const volatile uint32_t *>(touch - 0x80);
            touch -= 0x80; // Native demand reads run backward over the next 8 KiB before copying it.
          }
          for (uint32_t i = 0; i < 0x80; ++i)
          {
            const __m64 a = *reinterpret_cast<const __m64 __unaligned *>(from);
            const __m64 b = *reinterpret_cast<const __m64 __unaligned *>(from + 8);
            const __m64 c = *reinterpret_cast<const __m64 __unaligned *>(from + 0x10);
            const __m64 d = *reinterpret_cast<const __m64 __unaligned *>(from + 0x18);
            const __m64 e = *reinterpret_cast<const __m64 __unaligned *>(from + 0x20);
            const __m64 f = *reinterpret_cast<const __m64 __unaligned *>(from + 0x28);
            const __m64 g = *reinterpret_cast<const __m64 __unaligned *>(from + 0x30);
            const __m64 h = *reinterpret_cast<const __m64 __unaligned *>(from + 0x38);
            from += 0x40;
            _mm_stream_pi(reinterpret_cast<__m64 *>(to), a);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 8), b);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x10), c);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x18), d);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x20), e);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x28), f);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x30), g);
            _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x38), h);
            to += 0x40;
          }
          blocks -= 0x80;
        }
      }
      while (blocks != 0)
      {
        _mm_prefetch(reinterpret_cast<const char *>(from + 0x238), _MM_HINT_NTA);
        __m64 a = *reinterpret_cast<const __m64 __unaligned *>(from);
        __m64 b = *reinterpret_cast<const __m64 __unaligned *>(from + 8);
        __m64 c = *reinterpret_cast<const __m64 __unaligned *>(from + 0x10);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to), a);
        a = *reinterpret_cast<const __m64 __unaligned *>(from + 0x18);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 8), b);
        b = *reinterpret_cast<const __m64 __unaligned *>(from + 0x20);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x10), c);
        c = *reinterpret_cast<const __m64 __unaligned *>(from + 0x28);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x18), a);
        a = *reinterpret_cast<const __m64 __unaligned *>(from + 0x30);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x20), b);
        b = *reinterpret_cast<const __m64 __unaligned *>(from + 0x38);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x28), c);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x30), a);
        _mm_stream_pi(reinterpret_cast<__m64 *>(to + 0x38), b);
        from += 0x40;
        to += 0x40;
        --blocks;
      }
    }
  }
  for (uint32_t words = (remaining >> 2) & 0xf; words != 0; --words)
  {
    *reinterpret_cast<uint32_t __unaligned *>(to) = *reinterpret_cast<const uint32_t __unaligned *>(from);
    from += 4;
    to += 4;
  }
  for (uint32_t bytes = remaining & 3; bytes != 0; --bytes) *to++ = *from++;
  _mm_empty();
  _mm_sfence(); // Executed even for a zero-byte SSE copy; the fallback has neither instruction.
}
