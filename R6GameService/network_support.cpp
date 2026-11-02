#include "native_addresses.h"
#include "native_records.h"

// Descriptive layout for the29 eight-byte prefix records scanned at native storage0x10093c28.
struct IPv4PrefixRecord {
  uint networkAddress;
  uint prefixWidth;
};
// R6GameService.dll data @ 10093c28 :29 zero-filled records populated by native startup initialization.
IPv4PrefixRecord GInterfaceAddressPrefixes[29] = {};
// R6GameService.dll data @ 10093d10 : cached IPv4 word, initially zero in the PE virtual .data tail.
uint GResolvedIPv4Address = 0;

// Passes original text to provider parser and maps only ffffffff to0 through native mask arithmetic.
// R6GameService.dll @ 1002d5a0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ParseIPv4AddressOrZero(const char *text)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    mov    ecx,eax
    inc    eax
    neg    eax
    sbb    eax,eax
    and    eax,ecx
    ret    0x4
  }
}

// Parses text, then loads current original width and publishes address/width through cached receiver.
// R6GameService.dll @ 1002d4e0 : native control/access order and raw ABI retained.
__declspec(naked) IPv4PrefixRecord * __thiscall InitializeIPv4Prefix(IPv4PrefixRecord *prefix,const char *text,uint width)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   eax
    mov    esi,ecx
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],ecx
    mov    eax,esi
    pop    esi
    ret    0x8
  }
}

// Builds a mask using signed-positive width and cyclic x86 shifts, swaps it, then compares current original addresses.
// Returns masked input upper EAX with AL equality; no width clamp.
// R6GameService.dll @ 1002d5c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MatchesAddressPrefix(uint address,uint network,int width)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    xor    eax,eax
    test   edx,edx
    push   esi
    jle    Branch2
    mov    ecx,0x20
    sub    ecx,edx
  Branch1:
    mov    esi,0x1
    shl    esi,cl
    or     eax,esi
    inc    ecx
    dec    edx
    jne    Branch1
  Branch2:
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonlSlot
    mov    ecx,DWORD PTR [esp+0xc]
    mov    esi,DWORD PTR [esp+0x8]
    and    ecx,eax
    and    eax,esi
    cmp    ecx,eax
    pop    esi
    sete   al
    ret    0xc
  }
}

// Publishes29 native address/prefix rows in order, parsing each literal through the actual helper.
// Partial publications survive failures; final record receiver remains in EAX.
// R6GameService.dll @ 1002d260 : native control/access order and raw ABI retained.
__declspec(naked) IPv4PrefixRecord * __cdecl InitializeInterfaceAddressPrefixes(void)
{
  __asm {
    push   esi
    push   edi
    push   R6GameServiceAddresses::Text0000
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    mov    edi,0x7
    push   R6GameServiceAddresses::Text2000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x4,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    mov    esi,0x8
    push   R6GameServiceAddresses::Text5000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x8,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xc,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text10000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x10,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x14,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text23000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x18,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x1c,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text27000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x20,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x24,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text31000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x28,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x2c,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text69000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x30,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x34,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text70000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x38,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x3c,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text72000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x40,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x44,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text82000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x48,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x4c,0x5
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text84000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x50,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x54,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text88000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x58,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x5c,0x6
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text96000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x60,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x64,0x5
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text127000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x68,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x6c,0x3
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text128000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x70,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x74,esi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    mov    edi,0x10
    push   R6GameServiceAddresses::Text1286600
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x78,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x7c,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text16925400
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x80,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x84,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text1721600
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x88,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x8c,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x90,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x94,0xc
    push   R6GameServiceAddresses::Text19125500
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text192000
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x98,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0x9c,edi
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text1920480
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xa0,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xa4,0x13
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   R6GameServiceAddresses::Text1920640
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xa8,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xac,0x14
    call   R6GameServiceAddresses::ParseIPv4AddressOrZero
    push   0x11
    push   R6GameServiceAddresses::Text19201280
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xb8
    mov    ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xb0,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GInterfaceAddressPrefixes+0xb4,0x12
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    push   edi
    push   R6GameServiceAddresses::Text19216800
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xc0
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    push   esi
    push   R6GameServiceAddresses::Text197000
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xc8
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    push   esi
    push   R6GameServiceAddresses::Text201000
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xd0
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    push   0x17
    push   R6GameServiceAddresses::Text204152640
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xd8
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    push   0x3
    push   R6GameServiceAddresses::Text224000
    mov    ecx,R6GameServiceAddresses::GInterfaceAddressPrefixes+0xe0
    call   R6GameServiceAddresses::InitializeIPv4Prefix
    pop    edi
    pop    esi
    ret
  }
}

// Starts Winsock, resolves nonempty text, publishes cached address and copies up to129 formatted bytes in place.
// Null/marker-byte input clears cache; failures preserve it, and callback/partial-publication/raw EAX effects remain explicit.
// R6GameService.dll @ 1002d500 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ResolveAddressText(char *addressText)
{
  __asm {
    sub    esp,0x190
    lea    eax,[esp+0x0]
    push   ebx
    push   eax
    push   0x2
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAStartupSlot
    test   eax,eax
    je     Branch4
  Branch3:
    xor    al,al
    pop    ebx
    add    esp,0x190
    ret    0x4
  Branch4:
    mov    ebx,DWORD PTR [esp+0x198]
    test   ebx,ebx
    je     Branch5
    push   esi
    push   edi
    mov    edi,R6GameServiceAddresses::GRegistrationEmptyText
    mov    esi,ebx
    mov    ecx,0x1
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    pop    edi
    pop    esi
    je     Branch5
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_gethostbynameSlot
    test   eax,eax
    je     Branch3
    mov    eax,DWORD PTR [eax+0xc]
    push   0x81
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [ecx]
    push   eax
    mov    ds:R6GameServiceAddresses::GResolvedIPv4Address,eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    push   eax
    push   ebx
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    mov    al,0x1
    pop    ebx
    add    esp,0x190
    ret    0x4
  Branch5:
    mov    DWORD PTR ds:R6GameServiceAddresses::GResolvedIPv4Address,0x0
    mov    al,0x1
    pop    ebx
    add    esp,0x190
    ret    0x4
  }
}

// Optionally installs the nonfunction base-offset table, then sets invalid handle, error0 and kind byte0.
// Padding remains untouched; returns receiver EAX and ECX from the mutable native scratch, normally zero.
// R6GameService.dll @ 1002d940 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeSocketContext(void *socketContext,int installBaseTable)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je     Branch6
    mov    DWORD PTR [eax],R6GameServiceAddresses::GSocketContextBaseOffsets
  Branch6:
    mov    DWORD PTR [eax+0x4],0xffffffff
    mov    DWORD PTR [eax+0x8],ecx
    mov    BYTE PTR [eax+0xc],cl
    pop    ecx
    ret    0x4
  }
}

// Resolves through bounded formatted stack text or parses cached original text on lookup failure.
// Late output pointer publishes parsed address; only fallback rejects ffffffff, with upper EAX retained.
// R6GameService.dll @ 1002d970 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ResolveIPv4Address(const char *hostName,uint *addressOut)
{
  __asm {
    sub    esp,0x84
    push   esi
    mov    esi,DWORD PTR [esp+0x8c]
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_gethostbynameSlot
    test   eax,eax
    je     Branch7
    mov    eax,DWORD PTR [eax+0xc]
    push   0x81
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    lea    edx,[esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    lea    eax,[esp+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    pop    esi
    mov    ecx,DWORD PTR [esp+0x8c]
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    add    esp,0x84
    ret    0x8
  Branch7:
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    cmp    eax,0xffffffff
    pop    esi
    mov    edx,DWORD PTR [esp+0x8c]
    mov    DWORD PTR [edx],eax
    setne  al
    add    esp,0x84
    ret    0x8
  }
}

// Creates IPv4 stream socket, publishes handle before failure testing, then updates error and successful kind1.
// Failure keeps prior kind; only AL is status, retaining native handle/error upper EAX.
// R6GameService.dll @ 1002d9f0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CreateIPv4StreamSocket(int socketContext)
{
  __asm {
    push   esi
    push   0x0
    push   0x1
    push   0x2
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_socketSlot
    cmp    eax,0xffffffff
    mov    DWORD PTR [esi+0x4],eax
    jne    Branch8
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret
  Branch8:
    mov    DWORD PTR [esi+0x8],0x0
    mov    BYTE PTR [esi+0xc],0x1
    mov    al,0x1
    pop    esi
    ret
  }
}

// Creates IPv4 datagram socket, publishes handle before failure testing, then updates error and successful kind2.
// Failure keeps prior kind; only AL is status, retaining native handle/error upper EAX.
// R6GameService.dll @ 1002da30 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CreateIPv4DatagramSocket(int socketContext)
{
  __asm {
    push   esi
    push   0x0
    push   0x2
    push   0x2
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_socketSlot
    cmp    eax,0xffffffff
    mov    DWORD PTR [esi+0x4],eax
    jne    Branch9
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret
  Branch9:
    mov    DWORD PTR [esi+0x8],0x0
    mov    BYTE PTR [esi+0xc],0x2
    mov    al,0x1
    pop    esi
    ret
  }
}

// Selects an ioctl interface using29 prefixes/current mode, decrementing original ordinal for skipped matches.
// Closes saved socket before output formatting; raw failures, live arguments and unchecked count/output accesses remain native.
// R6GameService.dll @ 1002d600 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall FindIPv4Interface(char *addressOut,char *maskOut,int mode,int ordinal)
{
  __asm {
    sub    esp,0x9ac
    push   ebp
    push   esi
    xor    esi,esi
    mov    BYTE PTR [esp+0xb],0x1
    push   esi
    push   0x2
    push   0x2
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_socketSlot
    cmp    eax,0xffffffff
    mov    DWORD PTR [esp+0x30],eax
    je     Branch24
    push   ebx
    push   edi
    push   esi
    lea    ecx,[esp+0x2c]
    push   esi
    push   ecx
    lea    edx,[esp+0x48]
    push   0x980
    push   edx
    push   esi
    push   esi
    push   0x4004747f
    push   eax
    mov    DWORD PTR [esp+0x4c],esi
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAIoctlSlot
    test   eax,eax
    jne    Branch23
    mov    ecx,DWORD PTR [esp+0x28]
    mov    eax,0xaf286bcb
    mul    ecx
    sub    ecx,edx
    mov    DWORD PTR [esp+0x14],esi
    shr    ecx,1
    add    ecx,edx
    shr    ecx,0x6
    cmp    ecx,esi
    mov    DWORD PTR [esp+0x2c],ecx
    jle    Branch21
    lea    eax,[esp+0x74]
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x1c],ecx
    mov    eax,0x4c
  Branch10:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [edx]
    mov    edx,DWORD PTR [ecx]
    cmp    ebp,0x100007f
    mov    DWORD PTR [esp+0x20],ebp
    mov    DWORD PTR [esp+0x30],edx
    je     Branch18
    test   ebp,ebp
    je     Branch18
    mov    BYTE PTR [esp+0x12],0x0
    mov    esi,R6GameServiceAddresses::GInterfaceAddressPrefixes
    xor    edi,edi
  Branch11:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi]
    push   eax
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::MatchesAddressPrefix
    test   al,al
    jne    Branch12
    add    edi,0x8
    add    esi,0x8
    cmp    edi,0xe8
    jb     Branch11
    mov    cl,BYTE PTR [esp+0x12]
    jmp    Branch13
  Branch12:
    mov    cl,0x1
  Branch13:
    mov    eax,DWORD PTR [esp+0x9c8]
    sub    eax,0x0
    je     Branch14
    dec    eax
    jne    Branch16
    test   cl,cl
    jmp    Branch15
  Branch14:
    cmp    cl,0x1
  Branch15:
    jne    Branch17
  Branch16:
    mov    eax,DWORD PTR [esp+0x9cc]
    test   eax,eax
    je     Branch19
    mov    edi,eax
    dec    edi
    mov    DWORD PTR [esp+0x9cc],edi
  Branch17:
    mov    eax,0x4c
  Branch18:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x18]
    mov    esi,DWORD PTR [esp+0x14]
    add    edx,eax
    add    ecx,eax
    inc    esi
    mov    DWORD PTR [esp+0x1c],edx
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    edx,esi
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x14],esi
    jl     Branch10
    xor    bl,bl
    jmp    Branch20
  Branch19:
    mov    eax,DWORD PTR [esp+0x2c]
    mov    ecx,DWORD PTR [esp+0x14]
    cmp    ecx,eax
    jge    Branch22
    mov    bl,BYTE PTR [esp+0x13]
  Branch20:
    mov    ecx,DWORD PTR [esp+0x38]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    test   bl,bl
    pop    edi
    pop    ebx
    je     Branch24
    mov    edx,DWORD PTR [esp+0x1b]
    mov    eax,DWORD PTR [esp+0x1a]
    mov    ecx,DWORD PTR [esp+0x19]
    and    edx,0xff
    and    eax,0xff
    push   edx
    mov    edx,DWORD PTR [esp+0x9bc]
    and    ecx,0xff
    push   eax
    and    ebp,0xff
    push   ecx
    push   ebp
    push   R6GameServiceAddresses::TextDDDD
    push   edx
    call   R6GameServiceAddresses::sprintf
    mov    eax,DWORD PTR [esp+0x43]
    mov    ecx,DWORD PTR [esp+0x42]
    mov    edx,DWORD PTR [esp+0x41]
    and    eax,0xff
    push   eax
    mov    eax,DWORD PTR [esp+0x44]
    and    ecx,0xff
    and    edx,0xff
    push   ecx
    and    eax,0xff
    push   edx
    push   eax
    mov    eax,DWORD PTR [esp+0x9e4]
    push   R6GameServiceAddresses::TextDDDD
    push   eax
    call   R6GameServiceAddresses::sprintf
    add    esp,0x30
    mov    al,0x1
    pop    esi
    pop    ebp
    add    esp,0x9ac
    ret    0x10
  Branch21:
    mov    ebp,DWORD PTR [esp+0x20]
  Branch22:
    xor    bl,bl
    jmp    Branch20
  Branch23:
    mov    ebp,DWORD PTR [esp+0x20]
    xor    bl,bl
    jmp    Branch20
  Branch24:
    pop    esi
    xor    al,al
    pop    ebp
    add    esp,0x9ac
    ret    0x10
  }
}

// Closes the cached handle even if invalid; only success resets handle/error. Kind byte is untouched.
// Failure stores current provider error and clears only AL; context receiver remains cached across calls.
// R6GameService.dll @ 1002e350 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CloseSocketAndReset(void *socketContext)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    test   eax,eax
    jne    Branch25
    mov    DWORD PTR [esi+0x4],0xffffffff
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret
  Branch25:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret
  }
}

// Writes low argument byte back as a DWORD in the original argument slot and passes that address to FIONBIO.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e380 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSocketNonblocking(void *socketContext,uint enabled)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   ecx
    and    eax,0xff
    mov    edx,DWORD PTR [esi+0x4]
    push   0x8004667e
    push   edx
    mov    DWORD PTR [esp+0x14],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ioctlsocketSlot
    test   eax,eax
    jne    Branch26
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch26:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Stores low argument byte in its original DWORD slot and passes it to TCP_NODELAY without Boolean normalization.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e3c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetTcpNoDelay(void *socketContext,uint enabled)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   0x4
    push   ecx
    mov    edx,DWORD PTR [esi+0x4]
    push   0x1
    and    eax,0xff
    push   0x6
    push   edx
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    test   eax,eax
    jne    Branch27
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch27:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Stores low argument byte in its original DWORD slot and supplies SO_REUSEADDR with length4.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e410 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSocketReuseAddress(void *socketContext,uint enabled)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   0x4
    push   ecx
    mov    edx,DWORD PTR [esi+0x4]
    push   0x4
    and    eax,0xff
    push   0xffff
    push   edx
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    test   eax,eax
    jne    Branch28
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch28:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Stores low argument byte in its original DWORD slot and supplies SO_BROADCAST with length4.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e460 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSocketBroadcast(void *socketContext,uint enabled)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   0x4
    push   ecx
    mov    edx,DWORD PTR [esi+0x4]
    push   0x20
    and    eax,0xff
    push   0xffff
    push   edx
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    test   eax,eax
    jne    Branch29
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch29:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Passes the original full DWORD argument address to SO_SNDBUF, without size validation or normalization.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e4b0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSocketSendBufferSize(void *socketContext,int bufferSize)
{
  __asm {
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x8]
    push   0x4
    mov    ecx,DWORD PTR [esi+0x4]
    push   eax
    push   0x1001
    push   0xffff
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    test   eax,eax
    jne    Branch30
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch30:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Passes the original full DWORD argument address to SO_RCVBUF, without size validation or normalization.
// Provider success clears stored error; failure fetches full error and clears only result AL.
// R6GameService.dll @ 1002e4f0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSocketReceiveBufferSize(void *socketContext,int bufferSize)
{
  __asm {
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x8]
    push   0x4
    mov    ecx,DWORD PTR [esi+0x4]
    push   eax
    push   0x1002
    push   0xffff
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    test   eax,eax
    jne    Branch31
    mov    DWORD PTR [esi+0x8],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch31:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Returns the current stored error DWORD at receiver+8 without querying or clearing provider state.
// R6GameService.dll @ 1002e530 : native control/access order and raw ABI retained.
uint __fastcall GetSocketLastError(int socketContext)
{
  return *reinterpret_cast<const uint *>(static_cast<uint>(socketContext) + 8);
}


// R6GameService.dll data @ 10076c10 : nonfunction base-offset table installed by socket-context initialization.
const R6GameServiceNative::BaseOffsets<1> GSocketContextBaseOffsets = {0, {0x10}};

// Sends with flags0, returning full provider count; only ffffffff queries/stores provider error, otherwise clears it.
// R6GameService.dll @ 1002dd40 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall SendSocketBytes(void *socketContext,uint buffer,uint byteCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    push   0x0
    push   eax
    mov    edx,DWORD PTR [esi+0x4]
    push   ecx
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_sendSlot
    cmp    eax,0xffffffff
    jne    Branch32
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    or     eax,0xffffffff
    pop    esi
    ret    0x8
  Branch32:
    mov    DWORD PTR [esi+0x8],0x0
    pop    esi
    ret    0x8
  }
}

// Receives with flags0; would-block becomes0/error0, provider0 becomes-1/errorffffffff, other failures retain error.
// R6GameService.dll @ 1002dea0 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall ReceiveSocketBytes(void *socketContext,uint buffer,uint byteCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    push   0x0
    push   eax
    mov    edx,DWORD PTR [esi+0x4]
    push   ecx
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvSlot
    cmp    eax,0xffffffff
    jne    Branch34
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2733
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch35
    xor    eax,eax
  Branch33:
    mov    DWORD PTR [esi+0x8],0x0
    pop    esi
    ret    0x8
  Branch34:
    test   eax,eax
    jne    Branch33
    mov    DWORD PTR [esi+0x8],0xffffffff
  Branch35:
    or     eax,0xffffffff
    pop    esi
    ret    0x8
  }
}

// Peeks/grows up to25 times, then consumes and copies sender text/port even if that final receive fails.
// Capacity wraps, sender length persists across calls, recvfrom target caches while socket/payload reload; no local guard.
// R6GameService.dll @ 1002def0 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall ReceiveDatagramWithTextSender(
    void *socketContext,void **buffer,uint capacity,char *addressTextOut,ushort *portOut)
{
  __asm {
    sub    esp,0x18
    push   ebx
    mov    ebx,DWORD PTR [esp+0x20]
    push   ebp
    push   esi
    mov    edx,DWORD PTR [ebx]
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvfromSlot
    mov    esi,ecx
    lea    eax,[esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0x30]
    lea    ecx,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   ecx
    push   0x2
    push   edi
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x28],0x10
    mov    DWORD PTR [esp+0x2c],0x0
    call   ebp
    cmp    eax,0xffffffff
    jne    Branch41
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2738
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch38
  Branch36:
    mov    eax,DWORD PTR [esp+0x14]
    cmp    eax,0x19
    jge    Branch38
    mov    edx,eax
    mov    eax,DWORD PTR [ebx]
    inc    edx
    add    edi,edi
    test   eax,eax
    mov    DWORD PTR [esp+0x14],edx
    je     Branch37
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch37:
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x18]
    push   ecx
    push   edx
    push   0x2
    push   edi
    mov    DWORD PTR [ebx],eax
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    call   ebp
    cmp    eax,0xffffffff
    jne    Branch39
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2738
    mov    DWORD PTR [esi+0x8],eax
    je     Branch36
  Branch38:
    cmp    DWORD PTR [esi+0x8],0x2733
    jne    Branch40
    xor    eax,eax
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch39:
    mov    eax,DWORD PTR [ebx]
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x18]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x4]
    push   edx
    push   0x0
    push   edi
    push   eax
    push   ecx
    call   ebp
    mov    edx,DWORD PTR [esp+0x1c]
    push   0x81
    push   edx
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    push   eax
    mov    eax,DWORD PTR [esp+0x3c]
    push   eax
    call   R6GameServiceAddresses::strncpy
    mov    ecx,DWORD PTR [esp+0x26]
    add    esp,0xc
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    edx,DWORD PTR [esp+0x38]
    mov    WORD PTR [edx],ax
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch40:
    pop    edi
    pop    esi
    pop    ebp
    or     eax,0xffffffff
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch41:
    mov    edx,DWORD PTR [ebx]
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   ecx
    push   0x0
    push   edi
    push   edx
    push   eax
    call   ebp
    mov    ecx,DWORD PTR [esp+0x1c]
    push   0x81
    push   ecx
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    mov    edx,DWORD PTR [esp+0x38]
    push   eax
    push   edx
    call   R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0x26]
    add    esp,0xc
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    ecx,DWORD PTR [esp+0x38]
    mov    WORD PTR [ecx],ax
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  }
}

// Peeks/grows up to25 times, then consumes and publishes sender IPv4/port even if that final receive fails.
// Capacity wraps, sender length persists across calls, recvfrom target caches while socket/payload reload; no local guard.
// R6GameService.dll @ 1002e070 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall ReceiveDatagramWithIPv4Sender(
    void *socketContext,void **buffer,uint capacity,uint *addressOut,ushort *portOut)
{
  __asm {
    sub    esp,0x18
    push   ebx
    mov    ebx,DWORD PTR [esp+0x20]
    push   ebp
    push   esi
    mov    edx,DWORD PTR [ebx]
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvfromSlot
    mov    esi,ecx
    lea    eax,[esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0x30]
    lea    ecx,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   ecx
    push   0x2
    push   edi
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x28],0x10
    mov    DWORD PTR [esp+0x2c],0x0
    call   ebp
    cmp    eax,0xffffffff
    jne    Branch47
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2738
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch44
  Branch42:
    mov    eax,DWORD PTR [esp+0x14]
    cmp    eax,0x19
    jge    Branch44
    mov    edx,eax
    mov    eax,DWORD PTR [ebx]
    inc    edx
    add    edi,edi
    test   eax,eax
    mov    DWORD PTR [esp+0x14],edx
    je     Branch43
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch43:
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x18]
    push   ecx
    push   edx
    push   0x2
    push   edi
    mov    DWORD PTR [ebx],eax
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    call   ebp
    cmp    eax,0xffffffff
    jne    Branch45
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2738
    mov    DWORD PTR [esi+0x8],eax
    je     Branch42
  Branch44:
    cmp    DWORD PTR [esi+0x8],0x2733
    jne    Branch46
    xor    eax,eax
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch45:
    mov    eax,DWORD PTR [ebx]
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x18]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x4]
    push   edx
    push   0x0
    push   edi
    push   eax
    push   ecx
    call   ebp
    mov    edx,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [esp+0x1a]
    mov    edi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push   ecx
    mov    DWORD PTR [edx],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    edx,DWORD PTR [esp+0x38]
    mov    WORD PTR [edx],ax
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch46:
    pop    edi
    pop    esi
    pop    ebp
    or     eax,0xffffffff
    pop    ebx
    add    esp,0x18
    ret    0x10
  Branch47:
    mov    edx,DWORD PTR [ebx]
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    push   ecx
    push   0x0
    push   edi
    push   edx
    push   eax
    call   ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esp+0x1c]
    mov    edi,eax
    mov    eax,DWORD PTR [esp+0x1a]
    push   eax
    mov    DWORD PTR [ecx],edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    ecx,DWORD PTR [esp+0x38]
    mov    WORD PTR [ecx],ax
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x10
  }
}

// Receives once with flags2 iff original low peek byte is nonzero; success publishes current sender address/port.
// Failure tests the already stored error for would-block without querying the provider error.
// R6GameService.dll @ 1002e1d0 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall ReceiveFromSocket(
    void *socketContext,void *buffer,uint byteCount,uint *addressOut,ushort *portOut,char peek)
{
  __asm {
    sub    esp,0x14
    mov    dl,BYTE PTR [esp+0x28]
    push   esi
    neg    dl
    mov    esi,ecx
    lea    eax,[esp+0x4]
    sbb    edx,edx
    push   edi
    lea    ecx,[esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0x28]
    and    edx,0x2
    push   ecx
    mov    ecx,DWORD PTR [esp+0x28]
    push   edx
    mov    edx,DWORD PTR [esi+0x4]
    push   eax
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x20],0x10
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvfromSlot
    mov    edi,eax
    cmp    edi,0xffffffff
    jne    Branch49
    cmp    DWORD PTR [esi+0x8],0x2733
    jne    Branch48
    xor    eax,eax
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    add    esp,0x14
    ret    0x14
  Branch48:
    pop    edi
    or     eax,0xffffffff
    pop    esi
    add    esp,0x14
    ret    0x14
  Branch49:
    mov    eax,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0xe]
    mov    ecx,DWORD PTR [esp+0x10]
    push   edx
    mov    DWORD PTR [eax],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    WORD PTR [ecx],ax
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    add    esp,0x14
    ret    0x14
  }
}

// Queries local endpoint, publishes IPv4 then port and clears stored error; failure queries error and leaves outputs.
// Port conversion receives the full unaligned DWORD at sockaddr+2; only AL is final success status.
// R6GameService.dll @ 1002e260 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall GetSocketLocalIPv4Endpoint(void *socketContext,uint *addressOut,ushort *portOut)
{
  __asm {
    sub    esp,0x14
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x4]
    lea    ecx,[esp+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    push   eax
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x10],0x10
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_getpeernameSlot
    test   eax,eax
    jne    Branch50
    mov    eax,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0xa]
    mov    ecx,DWORD PTR [esp+0xc]
    push   edx
    mov    DWORD PTR [eax],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    ecx,DWORD PTR [esp+0x20]
    mov    WORD PTR [ecx],ax
    mov    DWORD PTR [esi+0x8],0x0
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret    0x8
  Branch50:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    add    esp,0x14
    ret    0x8
  }
}

// Queries peer endpoint, copies up to129 text bytes, publishes port and clears error; failure leaves outputs.
// Text copy precedes current unaligned port read, late original port-output pointer and final AL-only status.
// R6GameService.dll @ 1002e2d0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall GetSocketPeerIPv4Endpoint(void *socketContext,char *addressTextOut,ushort *portOut)
{
  __asm {
    sub    esp,0x14
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x4]
    lea    ecx,[esp+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    push   eax
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x10],0x10
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_getsocknameSlot
    test   eax,eax
    jne    Branch51
    mov    eax,DWORD PTR [esp+0xc]
    push   0x81
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    mov    ecx,DWORD PTR [esp+0x20]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::strncpy
    mov    edx,DWORD PTR [esp+0x16]
    add    esp,0xc
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohsSlot
    mov    ecx,DWORD PTR [esp+0x20]
    mov    WORD PTR [ecx],ax
    mov    DWORD PTR [esi+0x8],0x0
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret    0x8
  Branch51:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    add    esp,0x14
    ret    0x8
  }
}

// Writes family byte2 only for signed low-byte kinds1/2; other kinds preserve output and native EAX residue.
// R6GameService.dll @ 1002d820 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall SelectIPv4FamilyByte(uint endpointKind,byte *familyByte)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    test   al,al
    jle    Branch52
    cmp    al,0x2
    jg     Branch52
    mov    eax,DWORD PTR [esp+0x8]
    mov    BYTE PTR [eax],0x2
  Branch52:
    ret    0x8
  }
}

// Publishes size16, allocates/clears an unchecked record, then fills family/port and cached or resolved IPv4.
// Host pointer caches before allocation; output slot reloads through callbacks. Failed lookup frees current slot, leaving it dangling.
// R6GameService.dll @ 1002d840 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall AllocateResolvedIPv4Record(
    uint endpointKind,const char *hostName,uint port,int *recordOut,uint *recordSizeOut)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    push   esi
    lea    eax,[esp+0x8]
    push   edi
    push   eax
    push   ecx
    call   R6GameServiceAddresses::SelectIPv4FamilyByte
    push   0x10
    mov    edx,DWORD PTR [esp+0x20]
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edx],0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    xor    ecx,ecx
    mov    esi,DWORD PTR [esp+0x18]
    test   edi,edi
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [eax],ecx
    mov    DWORD PTR [eax+0x4],ecx
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    jne    Branch53
    mov    edx,DWORD PTR [esi]
    mov    eax,ds:R6GameServiceAddresses::GResolvedIPv4Address
    movsx  cx,BYTE PTR [esp+0xc]
    mov    DWORD PTR [edx+0x4],eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0x14]
    push   eax
    mov    WORD PTR [edx],cx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonsSlot
    mov    ecx,DWORD PTR [esi]
    pop    edi
    pop    esi
    mov    WORD PTR [ecx+0x2],ax
    mov    al,0x1
    ret    0x14
  Branch53:
    movsx  dx,BYTE PTR [esp+0xc]
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esp+0x14]
    push   ecx
    mov    WORD PTR [eax],dx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonsSlot
    mov    edx,DWORD PTR [esi]
    push   edi
    mov    WORD PTR [edx+0x2],ax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_gethostbynameSlot
    test   eax,eax
    je     Branch54
    mov    eax,DWORD PTR [eax+0xc]
    mov    edx,DWORD PTR [esi]
    pop    edi
    pop    esi
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [edx+0x4],eax
    mov    al,0x1
    ret    0x14
  Branch54:
    mov    ecx,DWORD PTR [esi]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    xor    al,al
    pop    esi
    ret    0x14
  }
}

// Clears the cached output record, writes family2/converted port, then reads current original address or cached IPv4.
// Port caches before clearing; later argument/cache loads and selected-address upper EAX are retained.
// R6GameService.dll @ 1002d900 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall BuildIPv4AddressRecord(uint address,uint port,uint *recordOut)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    mov    ecx,esi
    xor    eax,eax
    mov    edx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [ecx],eax
    push   edx
    mov    DWORD PTR [ecx+0x4],eax
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ecx+0xc],eax
    mov    WORD PTR [esi],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonsSlot
    mov    WORD PTR [esi+0x2],ax
    mov    eax,DWORD PTR [esp+0x8]
    test   eax,eax
    jne    Branch55
    mov    eax,ds:R6GameServiceAddresses::GResolvedIPv4Address
  Branch55:
    mov    DWORD PTR [esi+0x4],eax
    mov    al,0x1
    pop    esi
    ret    0xc
  }
}

// Builds a local IPv4 record and binds current handle; only ffffffff queries error, otherwise clears error and sets AL1.
// R6GameService.dll @ 1002da70 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall BindIPv4Socket(void *socketContext,uint address,uint port)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    sub    esp,0x10
    lea    eax,[esp+0x0]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::BuildIPv4AddressRecord
    test   al,al
    je     Branch56
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[esp+0x4]
    push   0x10
    push   eax
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_bindSlot
    cmp    eax,0xffffffff
    je     Branch56
    mov    DWORD PTR [esi+0x8],0x0
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret    0x8
  Branch56:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    xor    al,al
    pop    esi
    add    esp,0x10
    ret    0x8
  }
}

// Connects through allocated endpoint and native select/set/low-byte SO_ERROR completion path, freeing cached endpoint.
// Raw allocator EAX controls direct success/failure upper bits; cached last-error target and overlapping output/length remain explicit.
// R6GameService.dll @ 1002dad0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectResolvedIPv4(void *socketContext,int hostName,uint port)
{
  __asm {
    sub    esp,0x114
    mov    edx,DWORD PTR [esp+0x11c]
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x10]
    push   edi
    lea    ecx,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esp+0x12c]
    push   ecx
    mov    cl,BYTE PTR [esi+0xc]
    push   edx
    xor    ebx,ebx
    push   eax
    push   ecx
    mov    DWORD PTR [esp+0x2c],ebx
    call   R6GameServiceAddresses::AllocateResolvedIPv4Record
    test   al,al
    je     Branch61
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi+0x4]
    push   edx
    push   edi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_connectSlot
    test   eax,eax
    je     Branch60
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    call   ebp
    cmp    eax,0x2733
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch59
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GSocketConnectTimeoutSeconds
    lea    eax,[esp+0x18]
    mov    DWORD PTR [esp+0x24],ecx
    push   eax
    lea    ecx,[esp+0x24]
    push   ebx
    push   ecx
    push   ebx
    push   0x40
    mov    DWORD PTR [esp+0x34],0x1
    mov    DWORD PTR [esp+0x2c],edx
    mov    DWORD PTR [esp+0x30],ebx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_selectSlot
    cmp    eax,0x1
    jne    Branch57
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[esp+0x20]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ForwardWSAFDIsSet
    test   eax,eax
    je     Branch57
    mov    eax,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x14]
    lea    edx,[esp+0x13]
    push   ecx
    push   edx
    push   0x1007
    push   0xffff
    push   eax
    mov    DWORD PTR [esp+0x28],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_getsockoptSlot
    mov    al,BYTE PTR [esp+0x13]
    push   edi
    cmp    al,bl
    jne    Branch58
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x8],ebx
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0x114
    ret    0x8
  Branch57:
    push   edi
  Branch58:
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    call   ebp
    mov    DWORD PTR [esi+0x8],eax
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x114
    ret    0x8
  Branch59:
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x114
    ret    0x8
  Branch60:
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x8],ebx
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0x114
    ret    0x8
  Branch61:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x114
    ret    0x8
  }
}

// Connects a stack IPv4 endpoint and checks native select/set/low-byte SO_ERROR completion without temporary allocation.
// Cached last-error target, raw converter/provider upper EAX and adjacent option-byte/length layout remain explicit.
// R6GameService.dll @ 1002dc30 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectIPv4(void *socketContext,uint address,uint port)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    sub    esp,0x124
    lea    eax,[esp+0x10]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x130]
    push   edi
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::BuildIPv4AddressRecord
    test   al,al
    je     Branch64
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[esp+0x18]
    push   0x10
    push   eax
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_connectSlot
    test   eax,eax
    je     Branch62
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    call   edi
    cmp    eax,0x2733
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch65
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,ds:R6GameServiceAddresses::GSocketConnectTimeoutSeconds
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x2c],edx
    push   ecx
    lea    edx,[esp+0x2c]
    push   0x0
    push   edx
    push   0x0
    push   0x40
    mov    DWORD PTR [esp+0x3c],0x1
    mov    DWORD PTR [esp+0x24],eax
    mov    DWORD PTR [esp+0x28],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_selectSlot
    cmp    eax,0x1
    jne    Branch63
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[esp+0x28]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::ForwardWSAFDIsSet
    test   eax,eax
    je     Branch63
    mov    ecx,DWORD PTR [esi+0x4]
    lea    edx,[esp+0xc]
    lea    eax,[esp+0xb]
    push   edx
    push   eax
    push   0x1007
    push   0xffff
    push   ecx
    mov    DWORD PTR [esp+0x20],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_getsockoptSlot
    mov    al,BYTE PTR [esp+0xb]
    test   al,al
    jne    Branch63
  Branch62:
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x124
    ret    0x8
  Branch63:
    call   edi
    mov    DWORD PTR [esi+0x8],eax
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x124
    ret    0x8
  Branch64:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
  Branch65:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x124
    ret    0x8
  }
}

// Builds allocated endpoint, sends with flags0, frees cached endpoint before querying failure error and returns raw count.
// Original port argument becomes record-length output; no local EH releases the endpoint on an interrupted provider call.
// R6GameService.dll @ 1002dd80 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall SendSocketBytesToResolvedIPv4(
    void *socketContext,uint buffer,uint byteCount,int hostName,uint port)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0x14]
    push   ebx
    push   esi
    mov    esi,ecx
    lea    eax,[esp+0x1c]
    push   edi
    lea    ecx,[esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0x20]
    push   ecx
    mov    cl,BYTE PTR [esi+0xc]
    push   edx
    push   eax
    push   ecx
    mov    DWORD PTR [esp+0x20],0x0
    call   R6GameServiceAddresses::AllocateResolvedIPv4Record
    test   al,al
    je     Branch67
    mov    edx,DWORD PTR [esp+0x20]
    mov    ebx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esi+0x4]
    push   ebx
    push   0x0
    push   eax
    push   ecx
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_sendtoSlot
    push   ebx
    mov    edi,eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,0xffffffff
    jne    Branch66
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x10
  Branch66:
    mov    eax,edi
    mov    DWORD PTR [esi+0x8],0x0
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x10
  Branch67:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [esi+0x8],eax
    pop    edi
    pop    esi
    or     eax,0xffffffff
    pop    ebx
    pop    ecx
    ret    0x10
  }
}

// Builds stack endpoint and sends with flags0; only ffffffff queries/stores error, otherwise clears error and returns full count.
// R6GameService.dll @ 1002de20 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall SendSocketBytesToIPv4(
    void *socketContext,uint buffer,uint byteCount,uint address,uint port)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0x10
    lea    eax,[esp+0x0]
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [esp+0x28]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::BuildIPv4AddressRecord
    test   al,al
    je     Branch69
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [esp+0x1c]
    lea    eax,[esp+0x8]
    push   0x10
    push   eax
    mov    eax,DWORD PTR [edi+0x4]
    push   0x0
    push   ecx
    push   edx
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_sendtoSlot
    mov    esi,eax
    cmp    esi,0xffffffff
    jne    Branch68
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [edi+0x8],eax
    mov    eax,esi
    pop    edi
    pop    esi
    add    esp,0x10
    ret    0x10
  Branch68:
    mov    DWORD PTR [edi+0x8],0x0
    mov    eax,esi
    pop    edi
    pop    esi
    add    esp,0x10
    ret    0x10
  Branch69:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    mov    DWORD PTR [edi+0x8],eax
    pop    edi
    or     eax,0xffffffff
    pop    esi
    add    esp,0x10
    ret    0x10
  }
}

// R6GameService.dll data @ 1008e080 : initial seconds word copied into select timeout; microseconds are separately zeroed.
uint GSocketConnectTimeoutSeconds = 5;

// Store full address at8, convert through ordinal14, then format saved converted octets high-to-low into cached
// record+c/size16.
// Preserve unaligned scratch loads and imported formatter raw EAX/RET4; address field is not reloaded after
// conversion. Class unresolved.
// R6GameService.dll @ 1005fd50 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall SetIPv4AddressAndFormatText(void *record,uint addressWord)
{
  __asm {
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0xc]
    push    esi
    mov    esi,ecx
    push    eax
    mov    DWORD PTR [esi+0x8],eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohlSlot
    mov    DWORD PTR [esp+0x4],eax
    mov    ecx,DWORD PTR [esp+0x6]
    mov    edx,DWORD PTR [esp+0x7]
    and    eax,0xff
    push    eax
    mov    eax,DWORD PTR [esp+0x9]
    and    eax,0xff
    and    ecx,0xff
    push    eax
    and    edx,0xff
    push    ecx
    push    edx
    push    R6GameServiceAddresses::TextDDDD
    add    esi,0xc
    push    0x10
    push    esi
    call    R6GameServiceAddresses::_snprintf
    add    esp,0x1c
    pop    esi
    add    esp,0x8
    ret    0x4
  }
}
