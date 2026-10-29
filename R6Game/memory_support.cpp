#include "native_addresses.h"
#include "import_bindings.h"

// R6Game.dll @ 10001000 : copy memory through scalar, cached-MMX or non-temporal paths
// Preserves native copy widths/order, caller DF on the scalar path, source probes and MMX/fence effects.
__declspec(naked) void __cdecl CopyMemoryForward(void* destination, const void* source, uint byteCount)
{
    __asm {
        push ebp
        mov ebp,esp
        push ebx
        push esi
        push edi
        // Read the selected Core GIsSSE data import once.
        mov eax,dword ptr [R6GameAddresses::Core_GIsSSESlot]
        cmp dword ptr [eax],0x0
        je scalarCopy
        mov ecx,dword ptr [ebp+0x10]
        mov edi,dword ptr [ebp+0x8]
        mov esi,dword ptr [ebp+0xc]
        mov ebx,ecx
        // Only the accelerated branch clears DF; EBX keeps its post-alignment byte count.
        cld
        cmp ecx,0x40
        jb dwordTailSetup
        cmp ecx,0x8000
        jbe alignDestination
        cmp ecx,0x10000
        jbe copyAlignedBlocks
    alignDestination:
        mov ecx,0x8
        sub ecx,edi
        and ecx,0x7
        sub ebx,ecx
        // Dispatch backward into the one-byte MOVSB sequence for 0..7 alignment bytes.
        neg ecx
        add ecx, offset copyAlignedBlocks
        jmp ecx
        nop
        movsb
        movsb
        movsb
        movsb
        movsb
        movsb
        movsb
        movsb
    copyAlignedBlocks:
        mov ecx,ebx
        shr ecx,0x6
        je loadTailCount
        cmp ecx,0x400
        jae nonTemporalDispatch
        jmp cachedBlockLoop
        lea esp,[esp+0x0]
        // Cached MMX blocks load two words before storing that pair.
    cachedBlockLoop:
        prefetchnta byte ptr [esi+0x238]
        movq mm0,qword ptr [esi]
        movq mm1,qword ptr [esi+0x8]
        movq qword ptr [edi],mm0
        movq qword ptr [edi+0x8],mm1
        movq mm2,qword ptr [esi+0x10]
        movq mm3,qword ptr [esi+0x18]
        movq qword ptr [edi+0x10],mm2
        movq qword ptr [edi+0x18],mm3
        movq mm0,qword ptr [esi+0x20]
        movq mm1,qword ptr [esi+0x28]
        movq qword ptr [edi+0x20],mm0
        movq qword ptr [edi+0x28],mm1
        movq mm2,qword ptr [esi+0x30]
        movq mm3,qword ptr [esi+0x38]
        movq qword ptr [edi+0x30],mm2
        movq qword ptr [edi+0x38],mm3
        add esi,0x40
        add edi,0x40
        dec ecx
        jne cachedBlockLoop
    loadTailCount:
        mov ecx,ebx
    dwordTailSetup:
        shr ecx,0x2
        and ecx,0xf
        // Dispatch backward into the one-byte MOVSD sequence for 0..15 DWORDs.
        neg ecx
        add ecx, offset byteTailSetup
        jmp ecx
    nonTemporalDispatch:
        cmp ecx,0xc50
        jae pagedCopyDispatch
    streamRemainder:
        or ecx,ecx
        je loadTailCount
        lea esp,[esp+0x0]
        // Non-temporal remainder blocks preserve their pipelined read/write order.
    streamedBlockLoop:
        prefetchnta byte ptr [esi+0x238]
        movq mm0,qword ptr [esi]
        add edi,0x40
        movq mm1,qword ptr [esi+0x8]
        add esi,0x40
        movq mm2,qword ptr [esi-0x30]
        movntq qword ptr [edi-0x40],mm0
        movq mm0,qword ptr [esi-0x28]
        movntq qword ptr [edi-0x38],mm1
        movq mm1,qword ptr [esi-0x20]
        movntq qword ptr [edi-0x30],mm2
        movq mm2,qword ptr [esi-0x18]
        movntq qword ptr [edi-0x28],mm0
        movq mm0,qword ptr [esi-0x10]
        movntq qword ptr [edi-0x20],mm1
        movq mm1,qword ptr [esi-0x8]
        movntq qword ptr [edi-0x18],mm2
        movntq qword ptr [edi-0x10],mm0
        dec ecx
        movntq qword ptr [edi-0x8],mm1
        jne streamedBlockLoop
        jmp loadTailCount
    pagedCopyDispatch:
        cmp ecx,0x80
        jl streamRemainder
        // Touch the next 8 KiB backward in pairs before streaming its 128 blocks.
        mov eax,0x40
        add esi,0x2000
        jmp touchSourceLoop
        lea esp,[esp+0x0]
        lea ecx,[ecx+0x0]
    touchSourceLoop:
        mov edx,dword ptr [esi-0x40]
        mov edx,dword ptr [esi-0x80]
        sub esi,0x80
        dec eax
        jne touchSourceLoop
        mov eax,0x80
        jmp streamedPageBlockLoop
        lea esp,[esp+0x0]
        lea ecx,[ecx+0x0]
        // Page blocks load all eight words before issuing any non-temporal store.
    streamedPageBlockLoop:
        movq mm0,qword ptr [esi]
        movq mm1,qword ptr [esi+0x8]
        movq mm2,qword ptr [esi+0x10]
        movq mm3,qword ptr [esi+0x18]
        movq mm4,qword ptr [esi+0x20]
        movq mm5,qword ptr [esi+0x28]
        movq mm6,qword ptr [esi+0x30]
        movq mm7,qword ptr [esi+0x38]
        add esi,0x40
        movntq qword ptr [edi],mm0
        movntq qword ptr [edi+0x8],mm1
        movntq qword ptr [edi+0x10],mm2
        movntq qword ptr [edi+0x18],mm3
        movntq qword ptr [edi+0x20],mm4
        movntq qword ptr [edi+0x28],mm5
        movntq qword ptr [edi+0x30],mm6
        movntq qword ptr [edi+0x38],mm7
        add edi,0x40
        dec eax
        jne streamedPageBlockLoop
        sub ecx,0x80
        jmp pagedCopyDispatch
        mov edi,edi
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
        movsd
    byteTailSetup:
        mov ecx,ebx
        and ecx,0x3
        je finishAccelerated
        rep movsb
        // Every accelerated exit empties MMX/x87 tags and fences stores, even for a zero-size copy.
    finishAccelerated:
        emms
        sfence
        jmp restoreRegisters
    scalarCopy:
        mov ecx,dword ptr [ebp+0x10]
        mov esi,dword ptr [ebp+0xc]
        mov edi,dword ptr [ebp+0x8]
        mov ebx,ecx
        // REP MOVSD/MOVSB use the caller DF unchanged on the non-SSE path.
        shr ecx,0x2
        and ebx,0x3
        rep movsd
        mov ecx,ebx
        rep movsb
    restoreRegisters:
        pop edi
        pop esi
        pop ebx
        pop ebp
        ret
    }
}

// R6Game.dll @ 100012c0 : release an allocation through the current global allocator without a null check
void __cdecl FreeThroughGlobalAllocator(void* memory)
{
    void* allocator = **(void***)R6GameImports::Core_GMallocSlot;
    void* allocation = memory;
    using ReleaseAllocation = void (__thiscall *)(void*, void*);
    ReleaseAllocation release = *(ReleaseAllocation*)(*(byte**)allocator + 8);
    release(allocator, allocation);
}
