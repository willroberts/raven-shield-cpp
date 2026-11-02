#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ef80 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo OwnedMapTreeDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080f9c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RegistryTreeDestroyExceptionHandlerFunctionInfo;

// Promotes right child, reloads its left link after first store, then updates current root/parent and backlinks.
// Colors/payloads untouched; raw pivot EAX and partial stores remain native.
// R6GameService.dll @ 10015430 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl RotateOrderedTreeLeft(int node,int *root)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [ecx+0xc],edx
    mov    edx,DWORD PTR [eax+0x8]
    test   edx,edx
    je     Branch1
    mov    DWORD PTR [edx+0x4],ecx
  Branch1:
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [esp+0x8]
    cmp    ecx,DWORD PTR [edx]
    jne    Branch2
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  Branch2:
    mov    edx,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [edx+0x8]
    jne    Branch3
    mov    DWORD PTR [edx+0x8],eax
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  Branch3:
    mov    DWORD PTR [edx+0xc],eax
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  }
}

// Promotes left child, reloads its right link after first store, then updates current root/parent and backlinks.
// Colors/payloads untouched; raw pivot EAX and partial stores remain native.
// R6GameService.dll @ 10015480 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl RotateOrderedTreeRight(int node,int *root)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    DWORD PTR [ecx+0x8],edx
    mov    edx,DWORD PTR [eax+0xc]
    test   edx,edx
    je     Branch4
    mov    DWORD PTR [edx+0x4],ecx
  Branch4:
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [esp+0x8]
    cmp    ecx,DWORD PTR [edx]
    jne    Branch5
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  Branch5:
    mov    edx,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [edx+0xc]
    jne    Branch6
    mov    DWORD PTR [edx+0xc],eax
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  Branch6:
    mov    DWORD PTR [edx+0x8],eax
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [ecx+0x4],eax
    ret
  }
}

// Marks inserted cursor red, repairs red-parent cases with native recolors/inline rotations and blackens current root.
// Cached root-slot address, live node/root reloads and raw repair-cursor EAX remain explicit.
// R6GameService.dll @ 10018160 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl RebalanceOrderedTreeAfterInsertion(char *node,int *root)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    BYTE PTR [eax],0x0
    cmp    eax,DWORD PTR [edi]
    je     Branch31
  Branch7:
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    BYTE PTR [ecx],0x0
    jne    Branch32
    mov    esi,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    cmp    ecx,edx
    jne    Branch18
    mov    edx,DWORD PTR [esi+0xc]
    test   edx,edx
    je     Branch9
    cmp    BYTE PTR [edx],0x0
    jne    Branch9
  Branch8:
    mov    BYTE PTR [ecx],0x1
    mov    BYTE PTR [edx],0x1
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    jmp    Branch30
  Branch9:
    cmp    eax,DWORD PTR [ecx+0xc]
    jne    Branch14
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0xc]
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [eax+0xc],edx
    mov    edx,DWORD PTR [ecx+0x8]
    test   edx,edx
    je     Branch10
    mov    DWORD PTR [edx+0x4],eax
  Branch10:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch11
    mov    DWORD PTR [edi],ecx
    jmp    Branch13
  Branch11:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0x8]
    jne    Branch12
    mov    DWORD PTR [edx+0x8],ecx
    jmp    Branch13
  Branch12:
    mov    DWORD PTR [edx+0xc],ecx
  Branch13:
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [eax+0x4],ecx
  Branch14:
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x1
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [ecx+0x8]
    mov    esi,DWORD PTR [edx+0xc]
    mov    DWORD PTR [ecx+0x8],esi
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch15
    mov    DWORD PTR [esi+0x4],ecx
  Branch15:
    mov    esi,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],esi
    mov    esi,DWORD PTR [edi]
    cmp    ecx,esi
    jne    Branch16
    mov    DWORD PTR [edi],edx
    mov    DWORD PTR [edx+0xc],ecx
    jmp    Branch29
  Branch16:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0xc]
    jne    Branch17
    mov    DWORD PTR [esi+0xc],edx
    mov    DWORD PTR [edx+0xc],ecx
    jmp    Branch29
  Branch17:
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [edx+0xc],ecx
    jmp    Branch29
  Branch18:
    test   edx,edx
    je     Branch19
    cmp    BYTE PTR [edx],0x0
    je     Branch8
  Branch19:
    cmp    eax,DWORD PTR [ecx+0x8]
    jne    Branch24
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test   edx,edx
    je     Branch20
    mov    DWORD PTR [edx+0x4],eax
  Branch20:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch21
    mov    DWORD PTR [edi],ecx
    jmp    Branch23
  Branch21:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch22
    mov    DWORD PTR [edx+0xc],ecx
    jmp    Branch23
  Branch22:
    mov    DWORD PTR [edx+0x8],ecx
  Branch23:
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
  Branch24:
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x1
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    esi,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0xc],esi
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch25
    mov    DWORD PTR [esi+0x4],ecx
  Branch25:
    mov    esi,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],esi
    mov    esi,DWORD PTR [edi]
    cmp    ecx,esi
    jne    Branch26
    mov    DWORD PTR [edi],edx
    jmp    Branch28
  Branch26:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0x8]
    jne    Branch27
    mov    DWORD PTR [esi+0x8],edx
    jmp    Branch28
  Branch27:
    mov    DWORD PTR [esi+0xc],edx
  Branch28:
    mov    DWORD PTR [edx+0x8],ecx
  Branch29:
    mov    DWORD PTR [ecx+0x4],edx
  Branch30:
    mov    ecx,DWORD PTR [edi]
    cmp    eax,ecx
    jne    Branch7
    mov    eax,ecx
    pop    edi
    pop    esi
    mov    BYTE PTR [eax],0x1
    ret
  Branch31:
    mov    ecx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [ecx],0x1
    ret
  Branch32:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    ret
  }
}

// Finds right-subtree minimum or climbs parent/right links using native header edge test; no NULL/cycle validation.
// R6GameService.dll @ 100153b0 : native control/access order and raw ABI retained.
__declspec(naked) int __cdecl OrderedTreeSuccessor(char *node)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    test   eax,eax
    je     Branch34
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch37
  Branch33:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch33
    ret
  Branch34:
    mov    eax,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [eax+0xc]
    jne    Branch36
  Branch35:
    mov    ecx,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    ecx,DWORD PTR [eax+0xc]
    je     Branch35
  Branch36:
    cmp    DWORD PTR [ecx+0xc],eax
    jne    Branch37
    mov    eax,ecx
  Branch37:
    ret
  }
}

// Uses native red-header test, else finds left-subtree maximum or climbs parent/left links; no NULL/cycle validation.
// R6GameService.dll @ 100153f0 : native control/access order and raw ABI retained.
__declspec(naked) int __cdecl OrderedTreePredecessor(char *node)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    cmp    BYTE PTR [ecx],0x0
    jne    Branch38
    mov    eax,DWORD PTR [ecx+0x4]
    cmp    DWORD PTR [eax+0x4],ecx
    jne    Branch38
    mov    eax,DWORD PTR [ecx+0xc]
    ret
  Branch38:
    mov    eax,DWORD PTR [ecx+0x8]
    test   eax,eax
    je     Branch40
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    je     Branch42
  Branch39:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    jne    Branch39
    ret
  Branch40:
    mov    eax,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [eax+0x8]
    jne    Branch42
  Branch41:
    mov    ecx,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    ecx,DWORD PTR [eax+0x8]
    je     Branch41
  Branch42:
    ret
  }
}

// Unlinks requested node, transplants successor when needed, repairs black height and updates live root/extrema.
// Does not free storage; original node argument becomes search scratch then restores, with exact alias/publication order.
// R6GameService.dll @ 10014ff0 : native control/access order and raw ABI retained.
__declspec(naked) char * __cdecl RemoveOrderedTreeNode(
    char *node,int *root,undefined4 *leftmost,undefined4 *rightmost)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   ebx
    push   ebp
    push   esi
    mov    eax,DWORD PTR [edx+0x8]
    push   edi
    test   eax,eax
    mov    ebx,edx
    jne    Branch43
    mov    ebp,DWORD PTR [edx+0xc]
    jmp    Branch54
  Branch43:
    mov    ecx,DWORD PTR [edx+0xc]
    test   ecx,ecx
    jne    Branch44
    mov    ebp,eax
    jmp    Branch54
  Branch44:
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],esi
    mov    ecx,DWORD PTR [esi+0x8]
    test   ecx,ecx
    je     Branch46
  Branch45:
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    test   ecx,ecx
    jne    Branch45
    mov    esi,DWORD PTR [esp+0x14]
  Branch46:
    mov    ebp,DWORD PTR [esi+0xc]
    cmp    esi,edx
    je     Branch53
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax+0x4],edi
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edi+0x8],eax
    mov    eax,DWORD PTR [edx+0xc]
    cmp    edi,eax
    je     Branch48
    mov    ecx,DWORD PTR [edi+0x4]
    test   ebp,ebp
    je     Branch47
    mov    DWORD PTR [ebp+0x4],ecx
  Branch47:
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [eax+0x8],ebp
    mov    eax,DWORD PTR [edx+0xc]
    mov    DWORD PTR [edi+0xc],eax
    mov    eax,DWORD PTR [edx+0xc]
    mov    DWORD PTR [eax+0x4],edi
    jmp    Branch49
  Branch48:
    mov    ecx,edi
  Branch49:
    mov    eax,DWORD PTR [esp+0x18]
    cmp    DWORD PTR [eax],edx
    jne    Branch50
    mov    DWORD PTR [eax],edi
    jmp    Branch52
  Branch50:
    mov    esi,DWORD PTR [edx+0x4]
    cmp    DWORD PTR [esi+0x8],edx
    jne    Branch51
    mov    DWORD PTR [esi+0x8],edi
    jmp    Branch52
  Branch51:
    mov    DWORD PTR [esi+0xc],edi
  Branch52:
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [edi+0x4],eax
    mov    bl,BYTE PTR [edx]
    mov    al,BYTE PTR [edi]
    mov    BYTE PTR [edi],bl
    mov    BYTE PTR [edx],al
    mov    ebx,edx
    jmp    Branch66
  Branch53:
    mov    ebx,DWORD PTR [esp+0x14]
  Branch54:
    mov    ecx,DWORD PTR [ebx+0x4]
    test   ebp,ebp
    je     Branch55
    mov    DWORD PTR [ebp+0x4],ecx
  Branch55:
    mov    eax,DWORD PTR [esp+0x18]
    cmp    DWORD PTR [eax],edx
    jne    Branch56
    mov    DWORD PTR [eax],ebp
    jmp    Branch58
  Branch56:
    mov    esi,DWORD PTR [edx+0x4]
    cmp    DWORD PTR [esi+0x8],edx
    jne    Branch57
    mov    DWORD PTR [esi+0x8],ebp
    jmp    Branch58
  Branch57:
    mov    DWORD PTR [esi+0xc],ebp
  Branch58:
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    DWORD PTR [eax],edx
    jne    Branch62
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    jne    Branch59
    mov    esi,DWORD PTR [edx+0x4]
    mov    DWORD PTR [eax],esi
    jmp    Branch62
  Branch59:
    mov    esi,DWORD PTR [ebp+0x8]
    mov    edi,ebp
    test   esi,esi
    je     Branch61
  Branch60:
    mov    edi,esi
    mov    esi,DWORD PTR [edi+0x8]
    test   esi,esi
    jne    Branch60
  Branch61:
    mov    DWORD PTR [eax],edi
  Branch62:
    mov    eax,DWORD PTR [esp+0x20]
    cmp    DWORD PTR [eax],edx
    jne    Branch66
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    jne    Branch63
    mov    edx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [eax],edx
    jmp    Branch66
  Branch63:
    mov    edx,DWORD PTR [ebp+0xc]
    mov    esi,ebp
    test   edx,edx
    je     Branch65
  Branch64:
    mov    esi,edx
    mov    edx,DWORD PTR [esi+0xc]
    test   edx,edx
    jne    Branch64
  Branch65:
    mov    DWORD PTR [eax],esi
  Branch66:
    cmp    BYTE PTR [ebx],0x0
    je     Branch110
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ebp,DWORD PTR [eax]
    je     Branch109
  Branch67:
    test   ebp,ebp
    je     Branch68
    cmp    BYTE PTR [ebp+0x0],0x1
    jne    Branch109
  Branch68:
    mov    edx,DWORD PTR [ecx+0x8]
    cmp    ebp,edx
    jne    Branch79
    mov    edx,DWORD PTR [ecx+0xc]
    cmp    BYTE PTR [edx],0x0
    jne    Branch73
    mov    BYTE PTR [edx],0x1
    mov    edx,DWORD PTR [ecx+0xc]
    mov    BYTE PTR [ecx],0x0
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0xc],eax
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch69
    mov    DWORD PTR [esi+0x4],ecx
  Branch69:
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ecx,DWORD PTR [eax]
    jne    Branch70
    mov    DWORD PTR [eax],edx
    jmp    Branch72
  Branch70:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0x8]
    jne    Branch71
    mov    DWORD PTR [esi+0x8],edx
    jmp    Branch72
  Branch71:
    mov    DWORD PTR [esi+0xc],edx
  Branch72:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [ecx+0xc]
  Branch73:
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch74
    cmp    BYTE PTR [esi],0x1
    jne    Branch75
  Branch74:
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch86
    cmp    BYTE PTR [esi],0x1
    je     Branch86
  Branch75:
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch76
    cmp    BYTE PTR [esi],0x1
    jne    Branch90
  Branch76:
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch77
    mov    BYTE PTR [esi],0x1
  Branch77:
    mov    esi,DWORD PTR [edx+0x8]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0xc]
    mov    DWORD PTR [edx+0x8],eax
    mov    edi,DWORD PTR [esi+0xc]
    test   edi,edi
    je     Branch78
    mov    DWORD PTR [edi+0x4],edx
  Branch78:
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    edx,DWORD PTR [eax]
    jne    Branch87
    mov    DWORD PTR [eax],esi
    jmp    Branch89
  Branch79:
    cmp    BYTE PTR [edx],0x0
    jne    Branch84
    mov    BYTE PTR [edx],0x1
    mov    edx,DWORD PTR [ecx+0x8]
    mov    BYTE PTR [ecx],0x0
    mov    eax,DWORD PTR [edx+0xc]
    mov    DWORD PTR [ecx+0x8],eax
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch80
    mov    DWORD PTR [esi+0x4],ecx
  Branch80:
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ecx,DWORD PTR [eax]
    jne    Branch81
    mov    DWORD PTR [eax],edx
    jmp    Branch83
  Branch81:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0xc]
    jne    Branch82
    mov    DWORD PTR [esi+0xc],edx
    jmp    Branch83
  Branch82:
    mov    DWORD PTR [esi+0x8],edx
  Branch83:
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [ecx+0x8]
  Branch84:
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch85
    cmp    BYTE PTR [esi],0x1
    jne    Branch95
  Branch85:
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch86
    cmp    BYTE PTR [esi],0x1
    jne    Branch95
  Branch86:
    mov    BYTE PTR [edx],0x0
    mov    edx,DWORD PTR [esp+0x18]
    mov    ebp,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    ebp,DWORD PTR [edx]
    jne    Branch67
    jmp    Branch109
  Branch87:
    mov    edi,DWORD PTR [edx+0x4]
    cmp    edx,DWORD PTR [edi+0xc]
    jne    Branch88
    mov    DWORD PTR [edi+0xc],esi
    jmp    Branch89
  Branch88:
    mov    DWORD PTR [edi+0x8],esi
  Branch89:
    mov    DWORD PTR [esi+0xc],edx
    mov    DWORD PTR [edx+0x4],esi
    mov    edx,DWORD PTR [ecx+0xc]
  Branch90:
    mov    al,BYTE PTR [ecx]
    mov    BYTE PTR [edx],al
    mov    BYTE PTR [ecx],0x1
    mov    edx,DWORD PTR [edx+0xc]
    test   edx,edx
    je     Branch91
    mov    BYTE PTR [edx],0x1
  Branch91:
    mov    edx,DWORD PTR [ecx+0xc]
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0xc],eax
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch92
    mov    DWORD PTR [esi+0x4],ecx
  Branch92:
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ecx,DWORD PTR [eax]
    jne    Branch93
    mov    DWORD PTR [eax],edx
    mov    DWORD PTR [edx+0x8],ecx
    jmp    Branch108
  Branch93:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0x8]
    jne    Branch94
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [edx+0x8],ecx
    jmp    Branch108
  Branch94:
    mov    DWORD PTR [esi+0xc],edx
    mov    DWORD PTR [edx+0x8],ecx
    jmp    Branch108
  Branch95:
    mov    esi,DWORD PTR [edx+0x8]
    test   esi,esi
    je     Branch96
    cmp    BYTE PTR [esi],0x1
    jne    Branch102
  Branch96:
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch97
    mov    BYTE PTR [esi],0x1
  Branch97:
    mov    esi,DWORD PTR [edx+0xc]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edx+0xc],eax
    mov    edi,DWORD PTR [esi+0x8]
    test   edi,edi
    je     Branch98
    mov    DWORD PTR [edi+0x4],edx
  Branch98:
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    edx,DWORD PTR [eax]
    jne    Branch99
    mov    DWORD PTR [eax],esi
    jmp    Branch101
  Branch99:
    mov    edi,DWORD PTR [edx+0x4]
    cmp    edx,DWORD PTR [edi+0x8]
    jne    Branch100
    mov    DWORD PTR [edi+0x8],esi
    jmp    Branch101
  Branch100:
    mov    DWORD PTR [edi+0xc],esi
  Branch101:
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [edx+0x4],esi
    mov    edx,DWORD PTR [ecx+0x8]
  Branch102:
    mov    al,BYTE PTR [ecx]
    mov    BYTE PTR [edx],al
    mov    BYTE PTR [ecx],0x1
    mov    edx,DWORD PTR [edx+0x8]
    test   edx,edx
    je     Branch103
    mov    BYTE PTR [edx],0x1
  Branch103:
    mov    edx,DWORD PTR [ecx+0x8]
    mov    eax,DWORD PTR [edx+0xc]
    mov    DWORD PTR [ecx+0x8],eax
    mov    esi,DWORD PTR [edx+0xc]
    test   esi,esi
    je     Branch104
    mov    DWORD PTR [esi+0x4],ecx
  Branch104:
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ecx,DWORD PTR [eax]
    jne    Branch105
    mov    DWORD PTR [eax],edx
    jmp    Branch107
  Branch105:
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    ecx,DWORD PTR [esi+0xc]
    jne    Branch106
    mov    DWORD PTR [esi+0xc],edx
    jmp    Branch107
  Branch106:
    mov    DWORD PTR [esi+0x8],edx
  Branch107:
    mov    DWORD PTR [edx+0xc],ecx
  Branch108:
    mov    DWORD PTR [ecx+0x4],edx
  Branch109:
    test   ebp,ebp
    mov    eax,ebx
    je     Branch111
    pop    edi
    mov    BYTE PTR [ebp+0x0],0x1
    pop    esi
    pop    ebp
    pop    ebx
    ret
  Branch110:
    mov    eax,ebx
  Branch111:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret
  }
}

// Deletes an owned virtual value, erases its map node and returns the next iterator; the header iterator is unchanged.
// R6GameService.dll @ 100237f0 : shared vtable body; ECX owner, output/node stack words, RET8; EAX=output.
uint * __thiscall EraseOwnedPointerMapNode(void *owner,uint *output,uint node)
{
  if (node == *(uint *)((byte *)owner + 4)) {
    *output = node;
    return output;
  }
  uint value = *(uint *)(node + 0x14);
  if (value != 0) {
    typedef void (__thiscall *DeleteOwnedValue)(void *,uint);
    DeleteOwnedValue destroy = *(DeleteOwnedValue *)*(uint *)value;
    destroy((void *)value,1);
  }
  uint right = *(uint *)(node + 0x0c);
  *(uint *)(node + 0x14) = 0;
  uint next = node;
  if (right != 0) {
    next = right;
    uint left = *(uint *)(next + 8);
    while (left != 0) {
      next = left;
      left = *(uint *)(next + 8);
    }
  } else {
    uint parent = *(uint *)(node + 4);
    while (next == *(uint *)(parent + 0x0c)) {
      next = parent;
      parent = *(uint *)(parent + 4);
    }
    if (*(uint *)(next + 0x0c) != parent) next = parent;
  }
  uint header = *(uint *)((byte *)owner + 4);
  char *detached = RemoveOrderedTreeNode(
      (char *)node,(int *)(header + 4),(undefined4 *)(header + 8),(undefined4 *)(header + 0x0c));
  TailFreeThroughGlobalAllocator(detached);
  uint *count = (uint *)((byte *)owner + 8);
  *count = *count - 1;
  *output = next;
  return output;
}

// Loads a tree header's cached leftmost link into output, returning output and leaving that link in ECX.
// R6GameService.dll @ 10056cb0 : ECX header slot, output stack word, RET4; EAX=output.
undefined4 * __thiscall ReadOrderedTreeLeftmostLink(void *tree,undefined4 *output)
{
  uint head = *static_cast<const uint *>(tree);
  uint leftmost = reinterpret_cast<const uint *>(head)[2];
  *output = leftmost;
  return output;
}

// Frees each right subtree before the current node, then follows left links; never releases payload values.
// R6GameService.dll @ 100239d0 : ECX forwarded context, node stack word, RET4; EAX=incoming for null or last free result.
__declspec(naked) uint __thiscall ReleaseTreeNodeBranch(void *unusedTree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    jz     branch_done
    push   edi
  branch_loop:
    mov    eax,dword ptr [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseTreeNodeBranch
    mov    edi,dword ptr [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jnz    branch_loop
    pop    edi
  branch_done:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Dispatches the owner's complete [leftmost,header) range through its saved vtable, retaining the callback result.
// R6GameService.dll @ 100237d0 : shared body, ECX owner, no stack arguments; virtual slot0x0c consumes two words.
uint __fastcall DispatchMapFullRangeErase(int *owner)
{
  uint pastLast = owner[1];
  uint first = (uint)(owner + 1);
  uint vtable = owner[0];
  ReadOrderedTreeLeftmostLink(owner + 1,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  return (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
}

struct OwnedMapTreeDestroyFrame {
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Frees remaining structural nodes and the header; value ownership belongs to the caller's earlier range dispatch.
// R6GameService.dll @ 10023740 : ECX tree header/count slot, no stack arguments; EAX=header-free result.
uint __fastcall DestroyTreeContents(int *tree)
{
  OwnedMapTreeDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)OwnedMapTreeDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 0;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseTreeNodeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Releases the header referenced by the saved tree slot if structural destruction unwinds.
// R6GameService.dll @ 10064c20 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleaseOwnedMapTreeHeader(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the structural tree destructor's one-state exception metadata.
// R6GameService.dll @ 10064c28 : EAX=1007ef80, inherited-frame JMP10033906.
__declspec(naked) void __cdecl OwnedMapTreeDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::OwnedMapTreeDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Looks up an unsigned map key and dispatches single-node erase, including the header result on a miss.
// R6GameService.dll @ 10038680 : shared ECX owner/key stack word, RET4; EAX is the virtual callback's raw result.
uint __thiscall DispatchOwnedMapKeyErase(void *owner,uint keyWord)
{
  uint header = *(uint *)((byte *)owner + 4);
  uint searchKey = keyWord;
  uint node = *(uint *)(header + 4);
  uint iteratorWord = (uint)owner;
  uint candidate = header;
  while (node != 0) {
    if (*(uint *)(node + 0x10) < searchKey) {
      node = *(uint *)(node + 0x0c);
    } else {
      candidate = node;
      node = *(uint *)(node + 8);
    }
  }
  if (candidate == header || searchKey < *(uint *)(candidate + 0x10)) candidate = header;
  iteratorWord = candidate;
  uint vtable = *(uint *)owner;
  typedef uint (__thiscall *EraseNode)(void *,uint *,uint);
  return (*(EraseNode *)(vtable + 0x10))(owner,&keyWord,iteratorWord);
}

// Frees each right subtree before the current node, then follows left links; never releases payload values.
// R6GameService.dll @ 10038eb0 : ECX forwarded context, node stack word, RET4; EAX=incoming for null or last free result.
__declspec(naked) uint __thiscall ReleasePRNGMapTreeBranch(void *unusedTree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    jz     branch_done
    push   edi
  branch_loop:
    mov    eax,dword ptr [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleasePRNGMapTreeBranch
    mov    edi,dword ptr [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jnz    branch_loop
    pop    edi
  branch_done:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

struct RegistryTreeDestroyFrame {
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Frees remaining structural nodes and the header; value ownership belongs to the caller's earlier range dispatch.
// R6GameService.dll @ 10038790 : ECX tree header/count slot, no stack arguments; EAX=header-free result.
uint __fastcall DestroyPRNGMapTree(int *tree)
{
  RegistryTreeDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistryTreeDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 0;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleasePRNGMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Releases the header referenced by the saved tree slot if structural destruction unwinds.
// R6GameService.dll @ 100669a0 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleaseRegistryTreeHeader(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the one-state header-release metadata shared by four native structural tree destructors.
// R6GameService.dll @ 100669a8 : EAX=10080f9c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl RegistryTreeDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RegistryTreeDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Frees each right subtree before the current node, then follows left links; never releases payload values.
// R6GameService.dll @ 10038e80 : ECX forwarded context, node stack word, RET4; EAX=incoming for null or last free result.
__declspec(naked) uint __thiscall ReleaseHashMapTreeBranch(void *unusedTree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    jz     branch_done
    push   edi
  branch_loop:
    mov    eax,dword ptr [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseHashMapTreeBranch
    mov    edi,dword ptr [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jnz    branch_loop
    pop    edi
  branch_done:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Frees remaining structural nodes and the header; value ownership belongs to the caller's earlier range dispatch.
// R6GameService.dll @ 100384b0 : ECX tree header/count slot, no stack arguments; EAX=header-free result.
uint __fastcall DestroyHashMapTree(int *tree)
{
  RegistryTreeDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistryTreeDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 0;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseHashMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Frees each right subtree before the current node, then follows left links; never releases payload values.
// R6GameService.dll @ 10038ee0 : ECX forwarded context, node stack word, RET4; EAX=incoming for null or last free result.
__declspec(naked) uint __thiscall ReleaseCryptoMapTreeBranch(void *unusedTree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    jz     branch_done
    push   edi
  branch_loop:
    mov    eax,dword ptr [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseCryptoMapTreeBranch
    mov    edi,dword ptr [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jnz    branch_loop
    pop    edi
  branch_done:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Frees remaining structural nodes and the header; value ownership belongs to the caller's earlier range dispatch.
// R6GameService.dll @ 10038a20 : ECX tree header/count slot, no stack arguments; EAX=header-free result.
uint __fastcall DestroyCryptoMapTree(int *tree)
{
  RegistryTreeDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistryTreeDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 0;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseCryptoMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Frees each right subtree before the current node, then follows left links; never releases payload values.
// R6GameService.dll @ 10038f10 : ECX forwarded context, node stack word, RET4; EAX=incoming for null or last free result.
__declspec(naked) uint __thiscall ReleasePKCMapTreeBranch(void *unusedTree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    jz     branch_done
    push   edi
  branch_loop:
    mov    eax,dword ptr [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleasePKCMapTreeBranch
    mov    edi,dword ptr [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jnz    branch_loop
    pop    edi
  branch_done:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Frees remaining structural nodes and the header; value ownership belongs to the caller's earlier range dispatch.
// R6GameService.dll @ 10038cb0 : ECX tree header/count slot, no stack arguments; EAX=header-free result.
uint __fastcall DestroyPKCMapTree(int *tree)
{
  RegistryTreeDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistryTreeDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 0;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleasePKCMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Allocate24 bytes, then read the current record pointer and copy two DWORDs after the allocation+10 check.
// R6GameService.dll @ 10018050 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __thiscall AllocatePairTreeNode(void *unusedTree,uint *payload)
{
  __asm {
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x10]
    test   ecx,ecx
    je     Branch112
    mov    edx,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [ecx],esi
    mov    edx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    pop    esi
  Branch112:
    ret    0x4
  }
}

// Link a DWORD pair using unsigned key/flags, rebalance, count it and store the node through the late output slot.
// R6GameService.dll @ 10056e30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint * __thiscall InsertPairTreeNodeAtHint(
    void *tree,uint *output,uint childHint,uint parentNode,uint *payload,uint forceRight)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push   edi
    je     Branch114
    mov    ecx,DWORD PTR [esp+0x24]
    test   ecx,ecx
    jne    Branch113
    mov    ecx,DWORD PTR [esp+0x18]
    test   ecx,ecx
    jne    Branch114
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esi+0x10]
    cmp    ecx,edx
    jb     Branch114
  Branch113:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch116
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch116
  Branch114:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    jne    Branch115
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [ebx]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch116
  Branch115:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch116
    mov    DWORD PTR [eax+0x8],ebp
  Branch116:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [ebp+0x0],al
    add    edi,0x4
    mov    esi,ebp
    cmp    ebp,DWORD PTR [edi]
    je     Branch132
  Branch117:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch132
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch128
    mov    ecx,DWORD PTR [edx+0xc]
    test   ecx,ecx
    je     Branch119
    cmp    BYTE PTR [ecx],0x0
    jne    Branch119
  Branch118:
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch131
  Branch119:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch124
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch120
    mov    DWORD PTR [ecx+0x4],esi
  Branch120:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch121
    mov    DWORD PTR [edi],eax
    jmp    Branch123
  Branch121:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch122
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch123
  Branch122:
    mov    DWORD PTR [ecx+0xc],eax
  Branch123:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch124:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test   edx,edx
    je     Branch125
    mov    DWORD PTR [edx+0x4],eax
  Branch125:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch126
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch131
  Branch126:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch127
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch131
  Branch127:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch131
  Branch128:
    test   ecx,ecx
    je     Branch129
    cmp    BYTE PTR [ecx],0x0
    je     Branch118
  Branch129:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch130
    mov    esi,eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch130:
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    call   R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch131:
    cmp    esi,DWORD PTR [edi]
    jne    Branch117
  Branch132:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    eax,DWORD PTR [ebx+0x4]
    inc    eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Releases tree nodes if count is nonzero, resets its header/count, then frees the current sentinel.
// Its sole unwind action releases the current first-word pointer again; no node retry or field clear is added.
// R6GameService.dll @ 10018a70 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyStoredValueTree(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyStoredValueTreeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch135
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch134
    push   ebx
  Branch133:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseOrderedTreeBranches
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch133
    pop    ebx
  Branch134:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch135:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Recursively frees each+0c branch, captures the current+8 link, frees its node and follows that captured link.
// Shared tree body has no inferred class ownership; native null/free-path EAX and caller-cleanup width remain explicit.
// R6GameService.dll @ 1001d590 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseOrderedTreeBranches(void *treeContext,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch137
    push   edi
  Branch136:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseOrderedTreeBranches
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch136
    pop    edi
  Branch137:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Releases the first word of the CURRENT saved tree receiver at inherited EBP-10.
// R6GameService.dll @ 10064a50 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyStoredValueTreeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the tree destructor one-state sentinel-release metadata.
// R6GameService.dll @ 10064a58 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyStoredValueTreeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyStoredValueTreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ee20 : native nested tree lifetime record.
const R6GameServiceNative::UnwindEntry DestroyStoredValueTreeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyStoredValueTreeUnwind1},
};

// R6GameService.dll data @ 1007ee28 : native nested tree lifetime record.
const R6GameServiceNative::FuncInfo DestroyStoredValueTreeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyStoredValueTreeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Searches unsigned node keys for the first candidate not below one cached key, returning sentinel if absent.
// R6GameService.dll @ 1001d560 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OrderedTreeLowerBound(void *tree,uint *key)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [eax+0x4]
    test   ecx,ecx
    je     Branch141
    mov    edx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [edx]
  Branch138:
    cmp    DWORD PTR [ecx+0x10],edx
    jb     Branch139
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    jmp    Branch140
  Branch139:
    mov    ecx,DWORD PTR [ecx+0xc]
  Branch140:
    test   ecx,ecx
    jne    Branch138
  Branch141:
    ret    0x4
  }
}

// Finds an unsigned equal key using lower-bound descent, reloading the key word each step and after traversal.
// R6GameService.dll @ 1001daa0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OrderedTreeFind(void *tree,uint *key)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,eax
    test   ecx,ecx
    je     Branch145
    mov    esi,DWORD PTR [edi]
  Branch142:
    cmp    DWORD PTR [ecx+0x10],esi
    jb     Branch143
    mov    edx,ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    jmp    Branch144
  Branch143:
    mov    ecx,DWORD PTR [ecx+0xc]
  Branch144:
    test   ecx,ecx
    jne    Branch142
  Branch145:
    cmp    edx,eax
    je     Branch146
    mov    ecx,DWORD PTR [edi]
    mov    esi,DWORD PTR [edx+0x10]
    cmp    ecx,esi
    jb     Branch146
    mov    eax,edx
  Branch146:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Uses an unsigned-key insertion hint, neighboring iterators or fallback search, then publishes selected node output.
// Direct insertion, temporary word/byte records, hidden stack words and raw helper residues remain explicit.
// R6GameService.dll @ 1001d5c0 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall InsertOrFindOrderedTreeNode(void *tree,uint *output,uint hint,uint *pair)
{
  __asm {
    sub    esp,0x1c
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    mov    ebp,DWORD PTR [esi]
    cmp    edi,DWORD PTR [ebp+0x8]
    jne    Branch178
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esp+0x38]
    test   eax,eax
    ja     Branch155
    mov    edi,DWORD PTR [ebp+0x4]
    mov    cl,0x1
    test   edi,edi
    je     Branch150
    mov    eax,DWORD PTR [ebx]
  Branch147:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebp,edi
    cmp    eax,ecx
    setb   cl
    test   cl,cl
    je     Branch148
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch149
  Branch148:
    mov    edi,DWORD PTR [edi+0xc]
  Branch149:
    test   edi,edi
    jne    Branch147
  Branch150:
    mov    eax,ebp
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch152
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    cmp    ebp,DWORD PTR [eax]
    jne    Branch151
    lea    ecx,[esp+0x38]
    lea    edx,[esp+0x1c]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    push   eax
    jmp    Branch154
  Branch151:
    push   ebp
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch152:
    mov    eax,DWORD PTR [eax+0x10]
    mov    ecx,DWORD PTR [ebx]
    cmp    eax,ecx
    jae    Branch153
    lea    ecx,[esp+0x34]
    lea    edx,[esp+0x20]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    push   eax
    jmp    Branch154
  Branch153:
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x14]
    push   eax
    mov    BYTE PTR [esp+0x17],0x0
    push   ecx
  Branch154:
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],edx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch155:
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [edi+0x10]
    cmp    ecx,eax
    jbe    Branch158
    push   ebx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch156
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch157
  Branch156:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch157
    mov    DWORD PTR [eax+0x8],ebp
  Branch157:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch158:
    jb     Branch159
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch159:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    cmp    ebp,eax
    jne    Branch163
    cmp    edi,eax
    mov    ecx,esi
    push   ebx
    je     Branch160
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch162
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch162
  Branch160:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch161
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch162
  Branch161:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch162
    mov    DWORD PTR [eax+0x8],ebp
  Branch162:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    eax,DWORD PTR [esi]
    add    eax,0x4
    push   eax
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch163:
    mov    edx,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [ebp+0x10]
    cmp    edx,ecx
    jae    Branch170
    mov    ecx,DWORD PTR [edi+0xc]
    push   ebx
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch167
    cmp    edi,eax
    je     Branch164
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch166
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch166
  Branch164:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch165
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch166
  Branch165:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch166
    mov    DWORD PTR [eax+0x8],ebp
  Branch166:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [esi]
    add    edx,0x4
    push   edx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch167:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    edi,eax
    mov    DWORD PTR [ebp+0x8],edi
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    jne    Branch168
    mov    DWORD PTR [eax+0x4],edi
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch169
  Branch168:
    cmp    ebp,DWORD PTR [eax+0x8]
    jne    Branch169
    mov    DWORD PTR [eax+0x8],edi
  Branch169:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],ebp
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch170:
    mov    edi,DWORD PTR [eax+0x4]
    mov    ebp,eax
    test   edi,edi
    mov    cl,0x1
    je     Branch174
  Branch171:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebp,edi
    cmp    edx,ecx
    setb   cl
    test   cl,cl
    je     Branch172
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch173
  Branch172:
    mov    edi,DWORD PTR [edi+0xc]
  Branch173:
    test   edi,edi
    jne    Branch171
  Branch174:
    mov    eax,ebp
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch176
    lea    edx,[esp+0x20]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    cmp    ebp,DWORD PTR [eax]
    jne    Branch175
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x1c]
    push   eax
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch175:
    push   ebp
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch176:
    mov    edx,DWORD PTR [eax+0x10]
    mov    eax,DWORD PTR [ebx]
    cmp    edx,eax
    jae    Branch177
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x18]
    push   eax
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch177:
    lea    edx,[esp+0x13]
    lea    eax,[esp+0x14]
    push   edx
    lea    ecx,[esp+0x28]
    push   eax
    mov    BYTE PTR [esp+0x1b],0x0
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch178:
    cmp    edi,ebp
    jne    Branch180
    mov    ebp,DWORD PTR [ebp+0xc]
    mov    eax,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [ebp+0x10]
    mov    ecx,DWORD PTR [eax]
    cmp    edx,ecx
    mov    ecx,esi
    jae    Branch179
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    push   eax
    push   ebp
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch179:
    push   eax
    lea    eax,[esp+0x28]
    push   eax
    jmp    Branch188
  Branch180:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    mov    ebp,DWORD PTR [esp+0x3c]
    mov    ebx,DWORD PTR [edi+0x10]
    add    esp,0x4
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    ecx,ebx
    setb   bl
    test   bl,bl
    je     Branch182
    cmp    DWORD PTR [eax+0x10],ecx
    jae    Branch182
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch181
    mov    edi,DWORD PTR [esp+0x30]
    push   eax
    push   ebp
    push   eax
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch181:
    push   0x0
    push   ebp
    push   edi
    push   edi
    mov    edi,DWORD PTR [esp+0x40]
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch182:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    add    esp,0x4
    test   bl,bl
    sete   cl
    test   bl,bl
    jne    Branch185
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [edi+0x10]
    cmp    ecx,edx
    setb   cl
    test   cl,cl
    je     Branch186
    cmp    eax,DWORD PTR [esi]
    je     Branch183
    cmp    edx,DWORD PTR [eax+0x10]
    jae    Branch185
  Branch183:
    mov    ecx,DWORD PTR [edi+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch184
    push   edi
    push   ebp
    push   edi
    mov    edi,DWORD PTR [esp+0x3c]
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch184:
    mov    edi,DWORD PTR [esp+0x30]
    push   0x0
    push   ebp
    push   eax
    push   eax
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch185:
    cmp    bl,cl
    jne    Branch187
  Branch186:
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch187:
    lea    edx,[esp+0x24]
    push   ebp
    push   edx
    mov    ecx,esi
  Branch188:
    call   R6GameServiceAddresses::FindOrInsertOrderedTreeNodeByU32Key
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  }
}

// Finds an unsigned pair key or inserts/balances a copied node, publishing iterator and inserted byte.
// Includes the existing-key tail at56e16; preserves saved-key/current-payload reloads and output padding.
// R6GameService.dll @ 10056cc0 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall FindOrInsertOrderedTreeNodeByU32Key(void *tree,uint *output,uint *pair)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,0x1
    mov    edx,DWORD PTR [edi]
    mov    esi,edx
    mov    ebp,DWORD PTR [edx+0x4]
    test   ebp,ebp
    je     Branch192
    mov    eax,DWORD PTR [ebx]
  Branch189:
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    esi,ebp
    cmp    eax,ecx
    setb   cl
    test   cl,cl
    je     Branch190
    mov    ebp,DWORD PTR [ebp+0x8]
    jmp    Branch191
  Branch190:
    mov    ebp,DWORD PTR [ebp+0xc]
  Branch191:
    test   ebp,ebp
    jne    Branch189
  Branch192:
    test   cl,cl
    mov    eax,esi
    je     Branch197
    cmp    esi,DWORD PTR [edx+0x8]
    jne    Branch196
    cmp    esi,edx
    je     Branch193
    test   ebp,ebp
    jne    Branch193
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jb     Branch193
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch195
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch195
  Branch193:
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch194
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch195
  Branch194:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch195
    mov    DWORD PTR [eax+0x8],ebp
  Branch195:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [edi]
    add    edx,0x4
    push   edx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch196:
    push   esi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
  Branch197:
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [eax+0x10]
    cmp    edx,ecx
    jae    Branch201
    cmp    esi,DWORD PTR [edi]
    je     Branch198
    test   ebp,ebp
    jne    Branch198
    cmp    ecx,DWORD PTR [esi+0x10]
    jb     Branch198
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch200
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch200
  Branch198:
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch199
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch200
  Branch199:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch200
    mov    DWORD PTR [eax+0x8],ebp
  Branch200:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [edi]
    add    ecx,0x4
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch201:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ecx],eax
    mov    BYTE PTR [ecx+0x4],0x0
    mov    eax,ecx
    pop    ebx
    ret    0x8
  }
}

// Copies the source word before reloading the source flag byte, preserving output aliases and untouched padding.
// R6GameService.dll @ 10018080 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructWordBytePair(void *output,uint *word,byte *flag)
{
  __asm {
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [eax],edx
    mov    dl,BYTE PTR [ecx]
    mov    BYTE PTR [eax+0x4],dl
    ret    0x8
  }
}

// If count is nonzero, releases nodes in right-node-left order, resets current header links/count, then frees current header.
// Header slot stays dangling; exact lifetime action releases only current header on interruption.
// R6GameService.dll @ 10014df0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseCountedTreeAndHeader(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ReleaseCountedTreeAndHeaderSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch204
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch203
    push   ebx
  Branch202:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseServiceTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch202
    pop    ebx
  Branch203:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch204:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Recurses through+c, reloads+8 after recursion, caches that link across free and iterates it; payloads remain untouched.
// R6GameService.dll @ 10014fc0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseServiceTreeNodes(void *context,void *node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch206
    push   edi
  Branch205:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseServiceTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch205
    pop    edi
  Branch206:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Tail-forwards unchanged receiver to the canonical165d0 tree-storage release body.
// R6GameService.dll @ 100165c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyOrderedTreeWrapperContentsThunk(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::ordered_tree_support_DestroyOrderedTreeWrapperContents
  }
}

// If count is nonzero, releases nodes in right-node-left order, resets current header links/count, then frees current header.
// Header slot stays dangling; exact lifetime action releases only current header on interruption.
// R6GameService.dll @ 100165d0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ordered_tree_support_DestroyOrderedTreeWrapperContents(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ordered_tree_support_DestroyOrderedTreeWrapperContentsSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch209
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch208
    push   ebx
  Branch207:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::FreeOrderedTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch207
    pop    ebx
  Branch208:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch209:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Recurses through+c, reloads+8 after recursion, caches that link across free and iterates it; payloads remain untouched.
// R6GameService.dll @ 10017890 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FreeOrderedTreeNodes(void *context,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch211
    push   edi
  Branch210:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::FreeOrderedTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch210
    pop    edi
  Branch211:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Forwards current inherited saved tree receiver to first-word header release; no remaining-node cleanup.
// R6GameService.dll @ 10064600 : native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCountedTreeAndHeaderUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects14df0 one-state header-release exception record.
// R6GameService.dll @ 10064608 : native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCountedTreeAndHeaderSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReleaseCountedTreeAndHeaderExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Forwards current inherited saved tree receiver to first-word header release; no remaining-node cleanup.
// R6GameService.dll @ 10064800 : native control/access order and raw ABI retained.
__declspec(naked) void ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects165d0 one-state header-release exception record.
// R6GameService.dll @ 10064808 : native control/access order and raw ABI retained.
__declspec(naked) void ordered_tree_support_DestroyOrderedTreeWrapperContentsSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_support_DestroyOrderedTreeWrapperContentsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e890 : native tree-header release lifetime record.
const R6GameServiceNative::UnwindEntry ReleaseCountedTreeAndHeaderUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseCountedTreeAndHeaderUnwind1},
};

// R6GameService.dll data @ 1007e898 : native tree-header release lifetime record.
// R6GameService.dll data @ 1007e890 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReleaseCountedTreeAndHeaderExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ReleaseCountedTreeAndHeaderUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007ea40 : native tree-header release lifetime record.
const R6GameServiceNative::UnwindEntry ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwind1},
};

// R6GameService.dll data @ 1007ea48 : native tree-header release lifetime record.
// R6GameService.dll data @ 1007ea40 : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_support_DestroyOrderedTreeWrapperContentsExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Recurses through current right subtree, caches left node, destroys payload at+10 and frees current node, then follows cached left.
// R6GameService.dll @ 100275c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __thiscall ReleaseTreeNodes(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch213
    push   edi
  Branch212:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReturnEmbeddedBuffer
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch212
    pop    edi
  Branch213:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Returns first node whose unsigned key exceeds captured input key, or header; empty tree does not read key pointer.
// R6GameService.dll @ 10027490 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __thiscall FindStrictUpperBoundCandidate(void *tree,uint *key)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [eax+0x4]
    test   ecx,ecx
    je     Branch217
    mov    edx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [edx]
  Branch214:
    cmp    edx,DWORD PTR [ecx+0x10]
    jae    Branch215
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    jmp    Branch216
  Branch215:
    mov    ecx,DWORD PTR [ecx+0xc]
  Branch216:
    test   ecx,ecx
    jne    Branch214
  Branch217:
    ret    0x4
  }
}

// Find a20-byte unsigned key using one traversal pointer capture and a final descriptor reload.
// R6GameService.dll @ 100282e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall FindTwentyByteKeyNode(void *tree,uint keyDescriptor)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [ecx]
    push   ebp
    push   esi
    push   edi
    mov    edx,DWORD PTR [eax+0x4]
    mov    ebp,eax
    test   edx,edx
    je     Branch222
    mov    ecx,DWORD PTR [esp+0x14]
    push   ebx
    mov    ecx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x10],ecx
  Branch218:
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [edx+0x10]
    mov    ecx,0x14
    xor    ebx,ebx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch219
    sbb    ebx,ebx
    sbb    ebx,0xffffffff
  Branch219:
    test   ebx,ebx
    jl     Branch220
    mov    ebp,edx
    mov    edx,DWORD PTR [edx+0x8]
    jmp    Branch221
  Branch220:
    mov    edx,DWORD PTR [edx+0xc]
  Branch221:
    test   edx,edx
    jne    Branch218
    pop    ebx
  Branch222:
    cmp    ebp,eax
    je     Branch224
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [ebp+0x10]
    mov    ecx,0x14
    mov    esi,DWORD PTR [edx]
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch223
    sbb    edx,edx
    sbb    edx,0xffffffff
  Branch223:
    test   edx,edx
    jl     Branch224
    mov    eax,ebp
  Branch224:
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret    0x4
  }
}

// Allocate/link a key/WORD node at the indicated side, rebalance, increment current count and write the late output slot.
// R6GameService.dll @ 10027f10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InsertUnsignedKeyTreeNodeAtHint(void *tree,uint output,uint hint,uint parent,uint record,uint forceRight)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push   edi
    je     Branch226
    mov    ecx,DWORD PTR [esp+0x24]
    test   ecx,ecx
    jne    Branch225
    mov    ecx,DWORD PTR [esp+0x18]
    test   ecx,ecx
    jne    Branch226
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esi+0x10]
    cmp    ecx,edx
    jb     Branch226
  Branch225:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocateKeyedPairNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch228
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch228
  Branch226:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocateKeyedPairNode
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    jne    Branch227
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [ebx]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch228
  Branch227:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch228
    mov    DWORD PTR [eax+0x8],ebp
  Branch228:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [ebp+0x0],al
    add    edi,0x4
    mov    esi,ebp
    cmp    ebp,DWORD PTR [edi]
    je     Branch244
  Branch229:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch244
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch240
    mov    ecx,DWORD PTR [edx+0xc]
    test   ecx,ecx
    je     Branch231
    cmp    BYTE PTR [ecx],0x0
    jne    Branch231
  Branch230:
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch243
  Branch231:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch236
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch232
    mov    DWORD PTR [ecx+0x4],esi
  Branch232:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch233
    mov    DWORD PTR [edi],eax
    jmp    Branch235
  Branch233:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch234
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch235
  Branch234:
    mov    DWORD PTR [ecx+0xc],eax
  Branch235:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch236:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test   edx,edx
    je     Branch237
    mov    DWORD PTR [edx+0x4],eax
  Branch237:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch238
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch243
  Branch238:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch239
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch243
  Branch239:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch243
  Branch240:
    test   ecx,ecx
    je     Branch241
    cmp    BYTE PTR [ecx],0x0
    je     Branch230
  Branch241:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch242
    mov    esi,eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch242:
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    call   R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch243:
    cmp    esi,DWORD PTR [edi]
    jne    Branch229
  Branch244:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    eax,DWORD PTR [ebx+0x4]
    inc    eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Allocate24 bytes and copy a DWORD key plus WORD payload only when allocation+10 is nonzero.
// R6GameService.dll @ 10028520 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall AllocateKeyedPairNode(uint record)
{
  __asm {
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x10]
    test   ecx,ecx
    je     Branch245
    mov    edx,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [ecx],esi
    mov    dx,WORD PTR [edx+0x4]
    mov    WORD PTR [ecx+0x4],dx
    pop    esi
  Branch245:
    ret    0x4
  }
}

// Choose a side using20-byte keys or flags, allocate/link/rebalance a pair node, count it and write the current output.
// R6GameService.dll @ 100280e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InsertTwentyByteKeyTreeNodeAtHint(void *tree,uint output,uint hint,uint parent,uint record,uint forceRight)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x18]
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    mov    eax,DWORD PTR [esp+0x24]
    je     Branch248
    mov    ecx,DWORD PTR [esp+0x28]
    test   ecx,ecx
    jne    Branch247
    mov    ecx,DWORD PTR [esp+0x1c]
    test   ecx,ecx
    jne    Branch248
    mov    edi,DWORD PTR [ebp+0x10]
    mov    esi,DWORD PTR [eax]
    mov    ecx,0x14
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch246
    sbb    edx,edx
    sbb    edx,0xffffffff
  Branch246:
    mov    esi,DWORD PTR [esp+0x10]
    test   edx,edx
    jl     Branch248
  Branch247:
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebx,eax
    mov    DWORD PTR [ebp+0xc],ebx
    mov    eax,DWORD PTR [esi]
    cmp    ebp,DWORD PTR [eax+0xc]
    jne    Branch250
    mov    DWORD PTR [eax+0xc],ebx
    jmp    Branch250
  Branch248:
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebx,eax
    mov    DWORD PTR [ebp+0x8],ebx
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    jne    Branch249
    mov    DWORD PTR [eax+0x4],ebx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],ebx
    jmp    Branch250
  Branch249:
    cmp    ebp,DWORD PTR [eax+0x8]
    jne    Branch250
    mov    DWORD PTR [eax+0x8],ebx
  Branch250:
    xor    eax,eax
    mov    DWORD PTR [ebx+0x4],ebp
    mov    DWORD PTR [ebx+0x8],eax
    mov    DWORD PTR [ebx+0xc],eax
    mov    edi,DWORD PTR [esi]
    mov    BYTE PTR [ebx],al
    add    edi,0x4
    mov    esi,ebx
    cmp    ebx,DWORD PTR [edi]
    je     Branch265
  Branch251:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch265
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch261
    mov    ecx,DWORD PTR [edx+0xc]
    test   ecx,ecx
    je     Branch252
    cmp    BYTE PTR [ecx],0x0
    jne    Branch252
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [eax+0x4]
    jmp    Branch264
  Branch252:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch257
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch253
    mov    DWORD PTR [ecx+0x4],esi
  Branch253:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch254
    mov    DWORD PTR [edi],eax
    jmp    Branch256
  Branch254:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch255
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch256
  Branch255:
    mov    DWORD PTR [ecx+0xc],eax
  Branch256:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch257:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test   edx,edx
    je     Branch258
    mov    DWORD PTR [edx+0x4],eax
  Branch258:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch259
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch264
  Branch259:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch260
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch264
  Branch260:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch264
  Branch261:
    test   ecx,ecx
    je     Branch262
    cmp    BYTE PTR [ecx],0x0
    jne    Branch262
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch264
  Branch262:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch263
    mov    esi,eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch263:
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    call   R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch264:
    cmp    esi,DWORD PTR [edi]
    jne    Branch251
  Branch265:
    mov    edx,DWORD PTR [edi]
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    ecx,DWORD PTR [eax+0x4]
    inc    ecx
    pop    ebp
    mov    DWORD PTR [eax+0x4],ecx
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebx
    pop    ebx
    pop    ecx
    ret    0x14
  }
}

// Release right subtree, cache current left link, then free node; retain NULL input EAX and last free residue.
// R6GameService.dll @ 10027770 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ReleasePlainTreeNodes(void *context,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch267
    push   edi
  Branch266:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleasePlainTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch266
    pop    edi
  Branch267:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Release right subtree, cache current left link, then free node; retain NULL input EAX and last free residue.
// R6GameService.dll @ 100277a0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_ReleasePlainTreeNodes(void *context,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch269
    push   edi
  Branch268:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch268
    pop    edi
  Branch269:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Release right subtree, cache current left link, then free node; retain NULL input EAX and last free residue.
// R6GameService.dll @ 100277d0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_ReleasePlainTreeNodes2(void *context,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch271
    push   edi
  Branch270:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes2
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch270
    pop    edi
  Branch271:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Release right subtree, cache current left link, then free current +0x10 pointer and node; retain raw EAX.
// R6GameService.dll @ 10027800 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ReleaseFirstWordPayloadTreeNodes(void *context,int node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch273
    push   edi
  Branch272:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseFirstWordPayloadTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch272
    pop    edi
  Branch273:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Find a byte-range key or insert an independent copy, retaining first value on duplicates and raw result address.
// R6GameService.dll @ 10027840 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall FindOrInsertByteDescriptorTreeEntry(
    void *tree,void *result,const void *source)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,ecx
    mov    ebx,DWORD PTR [esp+0x10]
    push   esi
    push   edi
    mov    esi,DWORD PTR [ebp+0x0]
    mov    al,0x1
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    je     Branch277
  Branch274:
    mov    eax,DWORD PTR [edi+0x14]
    mov    ecx,DWORD PTR [edi+0x10]
    mov    edx,DWORD PTR [ebx]
    push   eax
    mov    eax,DWORD PTR [ebx+0x4]
    push   ecx
    push   eax
    push   edx
    mov    esi,edi
    call   R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test   eax,eax
    setl   al
    test   al,al
    je     Branch275
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch276
  Branch275:
    mov    edi,DWORD PTR [edi+0xc]
  Branch276:
    test   edi,edi
    jne    Branch274
  Branch277:
    mov    ecx,esi
    test   al,al
    mov    DWORD PTR [esp+0x18],ecx
    je     Branch282
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch281
    cmp    esi,eax
    je     Branch278
    test   edi,edi
    jne    Branch278
    lea    eax,[esi+0x10]
    push   eax
    push   ebx
    call   R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test   al,al
    jne    Branch278
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CreateByteDescriptorTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch280
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch280
  Branch278:
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CreateByteDescriptorTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch279
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch280
  Branch279:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch280
    mov    DWORD PTR [eax+0x8],edi
  Branch280:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push   edx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch281:
    push   esi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x18],eax
    mov    ecx,eax
  Branch282:
    mov    eax,DWORD PTR [ebx+0x4]
    mov    edx,DWORD PTR [ecx+0x14]
    mov    ecx,DWORD PTR [ecx+0x10]
    push   eax
    mov    eax,DWORD PTR [ebx]
    push   eax
    push   edx
    push   ecx
    call   R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test   eax,eax
    jge    Branch286
    cmp    esi,DWORD PTR [ebp+0x0]
    je     Branch283
    test   edi,edi
    jne    Branch283
    lea    eax,[esi+0x10]
    push   eax
    push   ebx
    call   R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test   al,al
    jne    Branch283
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CreateByteDescriptorTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch285
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch285
  Branch283:
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CreateByteDescriptorTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch284
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch285
  Branch284:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch285
    mov    DWORD PTR [eax+0x8],edi
  Branch285:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push   edx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch286:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    mov    BYTE PTR [eax+0x4],0x0
    pop    ebx
    ret    0x8
  }
}

// Compare unsigned byte prefixes then signed lengths; reuse incoming arguments for lengths and return full EAX0/1.
// R6GameService.dll @ 10028350 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) uint __cdecl ByteDescriptorLess(const void *left,const void *right)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esp+0x8]
    push   ebx
    push   esi
    mov    esi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    push   edi
    mov    edi,DWORD PTR [ecx]
    sub    eax,esi
    sub    edx,edi
    mov    DWORD PTR [esp+0x10],eax
    cmp    edx,eax
    mov    DWORD PTR [esp+0x14],edx
    lea    ecx,[esp+0x14]
    jl     Branch287
    lea    ecx,[esp+0x10]
  Branch287:
    mov    ecx,DWORD PTR [ecx]
    xor    ebx,ebx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch288
    sbb    ebx,ebx
    sbb    ebx,0xffffffff
  Branch288:
    test   ebx,ebx
    jne    Branch290
    cmp    eax,edx
    jge    Branch289
    or     ebx,0xffffffff
    xor    eax,eax
    test   ebx,ebx
    pop    edi
    pop    esi
    setl   al
    pop    ebx
    ret
  Branch289:
    xor    ebx,ebx
    cmp    eax,edx
    setg   bl
  Branch290:
    xor    eax,eax
    pop    edi
    test   ebx,ebx
    pop    esi
    pop    ebx
    setl   al
    ret
  }
}

// Compare unsigned bytes then signed wrapped lengths; overwrite the first two argument words and return -1/0/1.
// R6GameService.dll @ 100283e0 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) uint __cdecl CompareByteRanges(const byte *leftBegin,uint leftEnd,const byte *rightBegin,uint rightEnd)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x8]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    sub    edx,esi
    sub    ebx,edi
    mov    DWORD PTR [esp+0x10],edx
    cmp    ebx,edx
    mov    DWORD PTR [esp+0x14],ebx
    lea    eax,[esp+0x14]
    jl     Branch291
    lea    eax,[esp+0x10]
  Branch291:
    mov    ecx,DWORD PTR [eax]
    xor    eax,eax
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch292
    sbb    eax,eax
    sbb    eax,0xffffffff
  Branch292:
    test   eax,eax
    jne    Branch294
    cmp    edx,ebx
    jge    Branch293
    pop    edi
    pop    esi
    or     eax,0xffffffff
    pop    ebx
    ret
  Branch293:
    xor    eax,eax
    cmp    edx,ebx
    setg   al
  Branch294:
    pop    edi
    pop    esi
    pop    ebx
    ret
  }
}

// Allocate a32-byte node, clone begin/end at+10 and reload source before low16 port; preserve raw allocation result.
// R6GameService.dll @ 10028550 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CreateByteDescriptorTreeNode(const void *source)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ByteDescriptorNodeConstructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    push   0x20
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    xor    ecx,ecx
    lea    esi,[eax+0x10]
    mov    DWORD PTR [ebp-0x14],eax
    mov    DWORD PTR [ebp-0x4],ecx
    mov    DWORD PTR [ebp-0x18],esi
    mov    DWORD PTR [ebp-0x1c],esi
    cmp    esi,ecx
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch295
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x2
    mov    edi,DWORD PTR [eax+0x4]
    mov    ebx,DWORD PTR [eax]
    mov    eax,edi
    sub    eax,ebx
    inc    eax
    push   eax
    call   R6GameServiceAddresses::InitializeHeapByteString
    mov    eax,DWORD PTR [esi]
    push   eax
    push   edi
    push   ebx
    call   R6GameServiceAddresses::MoveByteRange
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,DWORD PTR [ebp-0x14]
    mov    dx,WORD PTR [ecx+0xc]
    mov    WORD PTR [esi+0xc],dx
  Branch295:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Free the staged node at parent EBP-14 and rethrow the active construction exception.
// R6GameService.dll @ 100285e3 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowByteDescriptorNodeConstruction(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Pass both saved payload-context words to empty cleanup; retain the loaded EAX.
// R6GameService.dll @ 10065740 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) void __cdecl CleanupByteDescriptorNodeContext(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Release the current first-word allocation through the saved payload address at parent EBP-1c.
// R6GameService.dll @ 10065751 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) uint __cdecl ReleaseByteDescriptorNodePayload(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the four-state node construction record and catch-all ownership handler.
// R6GameService.dll @ 10065759 : complete native control/access/raw ABI; descriptive shared helper name.
__declspec(naked) void __cdecl ByteDescriptorNodeConstructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CreateByteDescriptorTreeNodeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Four-state unwind map: raw allocation state0, saved context1, constructed payload2, catch state3.
// R6GameService.dll data @ 1007f8f4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CreateByteDescriptorTreeNodeUnwindMap[4] = {
  {-1, 0x00000000},
  {0x00000000, R6GameServiceAddresses::CleanupByteDescriptorNodeContext},
  {0x00000001, R6GameServiceAddresses::ReleaseByteDescriptorNodePayload},
  {-1, 0x00000000},
};

// Catch-all HandlerType for the staged node release/rethrow.
// R6GameService.dll data @ 1007f914 : native storage identity retained.
const R6GameServiceNative::CatchHandler ordered_tree_supportGByteDescriptorNodeLifetimeData[1] = {
  {0x00000000, 0x00000000, 0x00000000, R6GameServiceAddresses::RethrowByteDescriptorNodeConstruction},
};

// Try states0..2 with catch state3 and one catch-all handler.
// R6GameService.dll data @ 1007f924 : native storage identity retained.
const R6GameServiceNative::TryBlock CreateByteDescriptorTreeNodeTryMap[1] = {
  {0x00000000, 0x00000002, 0x00000003, 0x00000001,
  R6GameServiceAddresses::ordered_tree_supportGByteDescriptorNodeLifetimeData},
};

// Node constructor FuncInfo with four-state map and one catch-all try record.
// R6GameService.dll data @ 1007f938 : native storage identity retained.
const R6GameServiceNative::FuncInfo CreateByteDescriptorTreeNodeExceptionInfo = {
  0x19930520,
  0x00000004,
  R6GameServiceAddresses::CreateByteDescriptorTreeNodeUnwindMap,
  0x00000001,
  R6GameServiceAddresses::CreateByteDescriptorTreeNodeTryMap,
  0x00000000,
  0x00000000,
};

// Clear right/current/left timestamped nodes and their +20 triplets, retain header, then reset live header links/count.
// R6GameService.dll @ 100271e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall ClearBufferedRecordTree(void *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch298
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch297
    push   ebx
  Branch296:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReturnEmbeddedBuffer
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch296
    pop    ebx
  Branch297:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch298:
    pop    edi
    ret
  }
}

// Clear plain nodes using27770, retaining the header and reloading it for each final link store.
// R6GameService.dll @ 10027240 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall ClearRecordTreeVariantOne(void *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch301
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch300
    push   ebx
  Branch299:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleasePlainTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch299
    pop    ebx
  Branch300:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch301:
    pop    edi
    ret
  }
}

// Clear plain nodes using277a0, retaining the header and reloading it for each final link store.
// R6GameService.dll @ 10027290 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall ClearRecordTreeVariantTwo(void *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch304
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch303
    push   ebx
  Branch302:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch302
    pop    ebx
  Branch303:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch304:
    pop    edi
    ret
  }
}

// Clear plain nodes using277d0, retaining the header and reloading it for each final link store.
// R6GameService.dll @ 100272e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall ClearRecordTreeVariantThree(void *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch307
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch306
    push   ebx
  Branch305:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes2
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch305
    pop    ebx
  Branch306:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch307:
    pop    edi
    ret
  }
}

// Allocate32-byte tree header; copy the saved ECX high byte after allocation, then restore current saved ECX.
// R6GameService.dll @ 10027330 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall InitializeCircularListStorage(void *tree)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    push   0x20
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x7]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],0x0
    mov    BYTE PTR [esi+0x8],cl
    mov    BYTE PTR [eax],0x0
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret
  }
}

// Clear pointer-bearing nodes using27800/current first-word release, retain header, reset current links/count.
// R6GameService.dll @ 10027370 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __fastcall ClearFirstWordBufferedTree(void *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch310
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch309
    push   ebx
  Branch308:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseFirstWordPayloadTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch308
    pop    ebx
  Branch309:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch310:
    pop    edi
    ret
  }
}

// Allocate48-byte tree header, publish it/reset count, then copy the late byte and initialize current header links.
// R6GameService.dll @ 100273e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall InitializeThirtyByteListStorage(
    void *tree,const byte *initialByte,void *unusedTag)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   0x30
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],0x0
    mov    dl,BYTE PTR [ecx]
    mov    BYTE PTR [esi+0x8],dl
    mov    BYTE PTR [eax],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,esi
    pop    esi
    ret    0x8
  }
}

// Allocate24-byte tree header, publish it/reset count, then copy the late byte and initialize current header links.
// R6GameService.dll @ 10027420 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall InitializeTreeSentinel(void *tree,const byte *initialByte,void *unusedTag)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   0x18
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],0x0
    mov    dl,BYTE PTR [ecx]
    mov    BYTE PTR [esi+0x8],dl
    mov    BYTE PTR [eax],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,esi
    pop    esi
    ret    0x8
  }
}

// Tail-forward tree destruction without changing receiver, stack or raw target return.
// R6GameService.dll @ 10023c10 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall TailForwardTreeCleanup(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyTreeWithNodePayload
  }
}

// Tail-forward tree destruction without changing receiver, stack or raw target return.
// R6GameService.dll @ 10023c20 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_TailForwardTreeCleanup(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyTreeNodes
  }
}

// Tail-forward tree destruction without changing receiver, stack or raw target return.
// R6GameService.dll @ 10023c30 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_TailForwardTreeCleanup2(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::ordered_tree_support_DestroyTreeNodes
  }
}

// Tail-forward tree destruction without changing receiver, stack or raw target return.
// R6GameService.dll @ 10023c40 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_TailForwardTreeCleanup3(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::ordered_tree_support_DestroyTreeNodes2
  }
}

// Tail-forward tree destruction without changing receiver, stack or raw target return.
// R6GameService.dll @ 10023c50 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_TailForwardTreeCleanup4(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::ordered_tree_support_DestroyTreeWithNodePayload
  }
}

// Destroy nodes/payload triplets, reset current header links/count, then free current header; keep cleanup armed.
// R6GameService.dll @ 10023c60 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall DestroyTreeWithNodePayload(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TreeDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch313
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch312
    push   ebx
  Branch311:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   0x0
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::DeleteEmbeddedBufferDescriptor
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch311
    pop    ebx
  Branch312:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch313:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy plain nodes through27770, reset current header/count, then free header even when count0.
// R6GameService.dll @ 10023cf0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall DestroyTreeNodes(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TreeDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch316
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch315
    push   ebx
  Branch314:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleasePlainTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch314
    pop    ebx
  Branch315:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch316:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy plain nodes through277a0, reset current header/count, then free header even when count0.
// R6GameService.dll @ 10023d80 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_DestroyTreeNodes(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TreeDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch319
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch318
    push   ebx
  Branch317:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch317
    pop    ebx
  Branch318:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch319:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy plain nodes through277d0, reset current header/count, then free header even when count0.
// R6GameService.dll @ 10023e10 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_DestroyTreeNodes2(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TreeDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch322
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch321
    push   ebx
  Branch320:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes2
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch320
    pop    ebx
  Branch321:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch322:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy pointer-bearing nodes, reset current header/count and free header; retain raw free return and armed cleanup.
// R6GameService.dll @ 10023ea0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall ordered_tree_support_DestroyTreeWithNodePayload(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TreeDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch325
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch324
    push   ebx
  Branch323:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseFirstWordPayloadTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   0x0
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleaseHeapByteStringAndMaybeOwner
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch323
    pop    ebx
  Branch324:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch325:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Load current saved receiver at parent EBP-0x10 and free its current first-word header, including NULL.
// R6GameService.dll @ 10064d60 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __cdecl ReleaseSavedTreeHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the shared one-state lifetime record for five tree destructors.
// R6GameService.dll @ 10064d68 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __cdecl TreeDestructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// State 0 unwinds to -1 by releasing the current header through the saved receiver.
// R6GameService.dll data @ 1007f040 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ordered_tree_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseSavedTreeHeaderOnUnwind},
};

// Shared one-state FuncInfo for five generic tree destructors.
// R6GameService.dll data @ 1007f048 : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x00000001,
  R6GameServiceAddresses::ordered_tree_supportSharedLifetimeUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Retain tree ECX for recursion; release subtree+c, then cache next8 BEFORE freeing current node.
// RET4; NULL input retains incoming EAX, nonempty returns last free EAX; no own guard/cycle repair.
// R6GameService.dll @ 10041710 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseLinkedNodes(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch327
    push   edi
  Branch326:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch326
    pop    edi
  Branch327:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Recurse subtree+c with retained ECX receiver, cache next8, free current node, then continue cached chain.
// NULL input retains EAX; otherwise raw last free result, RET4. Separate physical specialization; no own guard.
// R6GameService.dll @ 10042d20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ordered_tree_support_ReleaseTreeNodes(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch329
    push   edi
  Branch328:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch328
    pop    edi
  Branch329:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Recurse subtree+c with retained ECX receiver, cache next8, free current node, then continue cached chain.
// NULL input retains EAX; otherwise raw last free result, RET4. Separate physical specialization; no own guard.
// R6GameService.dll @ 10042d50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ordered_tree_support_ReleaseTreeNodes2(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch331
    push   edi
  Branch330:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes2
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch330
    pop    edi
  Branch331:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Recurse subtree+c with retained ECX receiver, cache next8, free current node, then continue cached chain.
// NULL input retains EAX; otherwise raw last free result, RET4. Separate physical specialization; no own guard.
// R6GameService.dll @ 10042d80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ordered_tree_support_ReleaseTreeNodes3(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch333
    push   edi
  Branch332:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes3
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch332
    pop    edi
  Branch333:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Recurse+c, cache next8, release reference at node+10 (target at node+20), then free node.
// Preserve receiver for recursion and cached successor across release/free; RET4/raw last free EAX, no own guard.
// R6GameService.dll @ 10042de0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseTreePayloadNodes(void *tree,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch335
    push   edi
  Branch334:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseTreePayloadNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleasePayloadReferenceAt16
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch334
    pop    edi
  Branch335:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Nonzero count4 drains right subtrees then cached next8/current nodes; reload header for each reset/count0.
// Keep sentinel/slot, no own EH. Count0 returns0; reset path raw EAX is last reloaded header.
// R6GameService.dll @ 100416c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseNestedServiceLinkedEntries(int *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch338
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch337
    push   ebx
  Branch336:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch336
    pop    ebx
  Branch337:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch338:
    pop    edi
    ret
  }
}

// Install77d88 at owner4, use tree slot+c/count10, recurse entire root then reset live header/count.
// Arm state1 BEFORE final sized-free; its unwind only tails empty base. State0 releases current header on failure.
// Normal empty cleanup runs after state-1; RET0/raw free EAX. Overall declaring class remains unassigned.
// R6GameService.dll @ 10055a50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyOwnedList(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ordered_tree_support_SelectCollectionEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    lea    esi,[ecx+0xc]
    mov    DWORD PTR [ecx+0x4],R6GameServiceAddresses::clPlayerResultsVTable
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch339
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch339:
    mov    eax,DWORD PTR [esi]
    push   0x1
    push   eax
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0x1
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Drain nonzero-count tree with late next8/cache across free; reset CURRENT header links/count, free header.
// Head slot stays dangling; state0 through final free can repeat current-header release. RET0/raw allocator EAX.
// R6GameService.dll @ 10056380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyIndexedTree(int *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ordered_tree_support_SelectCollectionEH2
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch342
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch341
    push   ebx
  Branch340:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch340
    pop    ebx
  Branch341:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch342:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail release CURRENT first word of saved tree slot[parent ENTRY ESP-10], without clearing slot.
// R6GameService.dll @ 10069150 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ordered_tree_support_UnwindCollection(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Tail genuine empty cleanup on CURRENT saved tree-slot pointer; state1->-1 skips header release.
// R6GameService.dll @ 10069158 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ordered_tree_support_UnwindCollection2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail release CURRENT first word of saved tree slot[parent ENTRY ESP-10], without clearing slot.
// R6GameService.dll @ 10069260 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ordered_tree_support_UnwindCollection3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select collection lifetime map and tail-enter current CRT frame dispatch.
// R6GameService.dll @ 10069160 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_support_SelectCollectionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyOwnedListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select collection lifetime map and tail-enter current CRT frame dispatch.
// R6GameService.dll @ 10069268 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_support_SelectCollectionEH2(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083bc0 : exact collection lifetime map/FuncInfo words.
const R6GameServiceNative::UnwindEntry DestroyOwnedListUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ordered_tree_support_UnwindCollection},
  {-1, R6GameServiceAddresses::ordered_tree_support_UnwindCollection2},
};

// R6GameService.dll data @ 10083bd0 : exact collection lifetime map/FuncInfo words.
// R6GameService.dll data @ 10083bc0 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyOwnedListExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyOwnedListUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 10083d64 : exact collection lifetime map/FuncInfo words.
const R6GameServiceNative::UnwindEntry ordered_tree_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::ordered_tree_support_UnwindCollection3},
};

// R6GameService.dll data @ 10083d6c : exact collection lifetime map/FuncInfo words.
// R6GameService.dll data @ 10083d64 : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ordered_tree_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Allocate pair nodes through18050, copy color/parent, recurse+c then iterate+8; root replaces original source arg.
// Arm catch state0 only after first root fields/right read; no NULL-source/allocation repair or local pre-arm release.
// Physical epilogue56281 is canonical here; catch56254 normally rethrows, or falls through here if throw helper returns.
// R6GameService.dll @ 100561c0 : complete native operations/raw ABI; physical catch islands separate.
__declspec(naked) void * __thiscall ordered_tree_support_CloneOrderedTreeSubtree(void *tree,void *sourceNode,uint parentNode)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectIndexedCloneEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ebp-0x10],esp
    mov    ebx,ecx
    lea    eax,[edi+0x10]
    mov    DWORD PTR [ebp-0x14],ebx
    push   eax
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    cl,BYTE PTR [edi]
    mov    edx,DWORD PTR [ebp+0xc]
    mov    esi,eax
    mov    DWORD PTR [ebp+0x8],esi
    mov    BYTE PTR [esi],cl
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi+0xc]
    cmp    eax,ecx
    mov    DWORD PTR [ebp-0x4],ecx
    je     Branch344
    mov    ecx,ebx
  Branch343:
    push   esi
    push   eax
    call   R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtree
    mov    DWORD PTR [esi+0xc],eax
  Branch344:
    mov    edi,DWORD PTR [edi+0x8]
    mov    ebx,esi
    test   edi,edi
    je     Branch345
    mov    ecx,DWORD PTR [ebp-0x14]
    lea    eax,[edi+0x10]
    push   eax
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    cl,BYTE PTR [edi]
    mov    esi,eax
    mov    BYTE PTR [esi],cl
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [ebx+0x8],esi
    mov    DWORD PTR [esi+0x4],ebx
    mov    eax,DWORD PTR [edi+0xc]
    cmp    eax,ecx
    je     Branch344
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    Branch343
  Branch345:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp+0x8]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Inherited real parent EBP: release CURRENT root arg+8 using retained tree-14 and actual41710/current allocator.
// Recurse+c, capture next8 before free, then rethrow(NULL,NULL); normally nonreturning.
// If throw helper returns physically, continue parent epilogue56281; no invented separate RET or duplicated epilogue.
// R6GameService.dll @ 10056254 : complete native operations/raw ABI; physical catch islands separate.
__declspec(naked) void __cdecl ordered_tree_support_ordered_tree_supportCatch3(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp+0x8]
    test   esi,esi
    je     Branch347
    mov    ebx,DWORD PTR [ebp-0x14]
  Branch346:
    mov    edx,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   edx
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    edi,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch346
  Branch347:
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Incoming ECX unused. Allocate50 then save raw block-14; state0, compute block+10/save twice-18/-1c, state1.
// Skip children only when block+10 wraps0; NULL block still writes10/14. Forward argument-slot+3, zero string,
// state2 string-range init, state3 nested indexed construction; real EBP frame, RET4/raw block, exact catch/unwind map.
// R6GameService.dll @ 100562a0 : complete native operations/raw ABI; physical catch islands separate.
__declspec(naked) void * __thiscall AllocateIndexedTreeNode(void *unusedTree,uint *descriptor)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ordered_tree_support_SelectIndexedCloneEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    push   0x50
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x14],ebx
    lea    esi,[ebx+0x10]
    mov    DWORD PTR [ebp-0x18],esi
    mov    DWORD PTR [ebp-0x1c],esi
    test   esi,esi
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch348
    mov    edi,DWORD PTR [ebp+0x8]
    lea    eax,[ebp+0xb]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::ForwardStackWord
    push   0x0
    push   eax
    lea    ecx,[esi+0x8]
    mov    DWORD PTR [esi],0x0
    mov    DWORD PTR [esi+0x4],0x0
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    ecx,DWORD PTR [edi+0x4]
    mov    edx,DWORD PTR [edi]
    push   ecx
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x2
    call   R6GameServiceAddresses::InitializeStringRange
    add    edi,0xc
    push   0x1
    push   edi
    lea    ecx,[esi+0xc]
    mov    BYTE PTR [ebp-0x4],0x3
    call   R6GameServiceAddresses::AssignIndexedRecord
  Branch348:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,ebx
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Inherited real parent EBP: free CURRENT raw block-14 then rethrow(NULL,NULL), normally nonreturning.
// Returning throw helper would physically reach56356 alignment then neighboring56360; no invented return/rollback.
// R6GameService.dll @ 10056344 : complete native operations/raw ABI; physical catch islands separate.
__declspec(naked) void __cdecl ordered_tree_support_ordered_tree_supportCatch4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Read both saved subobject words-18/-1c as two unused cdecl stack words to genuine empty59130; caller pops8.
// R6GameService.dll @ 10069230 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl UnwindIndexedNode(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Tail free CURRENT first word of saved string subobject[parent real EBP-1c]; no pointer or count clear.
// R6GameService.dll @ 10069241 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ordered_tree_support_UnwindIndexedNode(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Tail free CURRENT first word of saved string subobject[parent real EBP-1c]; no pointer or count clear.
// R6GameService.dll @ 10069249 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ordered_tree_support_UnwindIndexedNode2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact clone/node catch and unwind metadata, then tail current CRT frame dispatch.
// R6GameService.dll @ 10069220 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedCloneEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact clone/node catch and unwind metadata, then tail current CRT frame dispatch.
// R6GameService.dll @ 10069251 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_support_SelectIndexedCloneEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateIndexedTreeNodeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083cac : exact clone/node unwind, catch handler, try or FuncInfo words.
const R6GameServiceNative::UnwindEntry ordered_tree_support_CloneOrderedTreeSubtreeUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// R6GameService.dll data @ 10083cbc : exact clone/node unwind, catch handler, try or FuncInfo words.
const R6GameServiceNative::CatchHandler ordered_tree_supportGIndexedCloneEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ordered_tree_support_ordered_tree_supportCatch3},
};

// R6GameService.dll data @ 10083ccc : exact clone/node unwind, catch handler, try or FuncInfo words.
// R6GameService.dll data @ 10083cbc : native storage identity retained.
const R6GameServiceNative::TryBlock ordered_tree_support_CloneOrderedTreeSubtreeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::ordered_tree_supportGIndexedCloneEH},
};

// R6GameService.dll data @ 10083ce0 : exact clone/node unwind, catch handler, try or FuncInfo words.
// R6GameService.dll data @ 10083cac : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_support_CloneOrderedTreeSubtreeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtreeUnwindMap,
  0x1,
  R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtreeTryMap,
  0x0,
  0x0,
};

// R6GameService.dll data @ 10083cfc : exact clone/node unwind, catch handler, try or FuncInfo words.
const R6GameServiceNative::UnwindEntry AllocateIndexedTreeNodeUnwindMap[5] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UnwindIndexedNode},
  {0x1, R6GameServiceAddresses::ordered_tree_support_UnwindIndexedNode},
  {0x1, R6GameServiceAddresses::ordered_tree_support_UnwindIndexedNode2},
  {-1, 0x0},
};

// R6GameService.dll data @ 10083d24 : exact clone/node unwind, catch handler, try or FuncInfo words.
const R6GameServiceNative::CatchHandler ordered_tree_supportGIndexedCloneEH5[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ordered_tree_support_ordered_tree_supportCatch4},
};

// R6GameService.dll data @ 10083d34 : exact clone/node unwind, catch handler, try or FuncInfo words.
// R6GameService.dll data @ 10083d24 : native storage identity retained.
const R6GameServiceNative::TryBlock AllocateIndexedTreeNodeTryMap[1] = {
  {0x0, 0x3, 0x4, 0x1, R6GameServiceAddresses::ordered_tree_supportGIndexedCloneEH5},
};

// R6GameService.dll data @ 10083d48 : exact clone/node unwind, catch handler, try or FuncInfo words.
// R6GameService.dll data @ 10083cfc : native storage identity retained.
const R6GameServiceNative::FuncInfo AllocateIndexedTreeNodeExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::AllocateIndexedTreeNodeUnwindMap,
  0x1,
  R6GameServiceAddresses::AllocateIndexedTreeNodeTryMap,
  0x0,
  0x0,
};

// Tail current receiver unchanged to existing collection destructor; preserve raw return/stack/register behavior.
// R6GameService.dll @ 10056360 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardIndexedCollectionDestroy(void *receiver)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyIndexedTree
  }
}

// Tail current receiver unchanged to existing collection destructor; preserve raw return/stack/register behavior.
// R6GameService.dll @ 10056370 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardDestroyServiceLinkedRecordContainer(void *receiver)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServiceLinkedRecordContainer
  }
}

// Capture head/root, read requested key ONCE only if root nonNULL, descend unsigned lower bound.
// Empty avoids key dereference; late output store/RET8/output EAX preserve head/key/output aliases.
// R6GameService.dll @ 10056790 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __thiscall FindUnsignedTreeLowerBound(void *tree,int *output,const uint *key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [ecx+0x4]
    test   eax,eax
    je     Branch352
    mov    edx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [edx]
  Branch349:
    cmp    DWORD PTR [eax+0x10],edx
    jb     Branch350
    mov    ecx,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch351
  Branch350:
    mov    eax,DWORD PTR [eax+0xc]
  Branch351:
    test   eax,eax
    jne    Branch349
  Branch352:
    mov    eax,DWORD PTR [esp+0x4]
    mov    DWORD PTR [eax],ecx
    ret    0x8
  }
}

// Use leftmost/end/interior hint, unsigned adjacent-key gates or fallback full lookup; duplicates retain payload.
// Some routes allocate/link then call RB fixup; others call56e30. Current head/payload/count/output reads retained.
// Write ONLY output node word, RET12/output EAX; no validation/own EH/rollback or invented inserted-byte output.
// R6GameService.dll @ 100567c0 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __thiscall FindOrInsertUnsignedTreeNodeNearHint(
    void *tree,int *output,void *hint,uint *payload)
{
  __asm {
    sub    esp,0x1c
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    mov    ebp,DWORD PTR [esi]
    cmp    edi,DWORD PTR [ebp+0x8]
    jne    Branch384
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    ja     Branch361
    mov    edi,DWORD PTR [ebp+0x4]
    mov    ebx,DWORD PTR [esp+0x38]
    test   edi,edi
    mov    cl,0x1
    je     Branch356
    mov    eax,DWORD PTR [ebx]
  Branch353:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebp,edi
    cmp    eax,ecx
    setb   cl
    test   cl,cl
    je     Branch354
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch355
  Branch354:
    mov    edi,DWORD PTR [edi+0xc]
  Branch355:
    test   edi,edi
    jne    Branch353
  Branch356:
    mov    eax,ebp
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch358
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch357
    lea    ecx,[esp+0x38]
    lea    edx,[esp+0x1c]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    push   eax
    jmp    Branch360
  Branch357:
    push   ecx
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch358:
    mov    eax,DWORD PTR [eax+0x10]
    mov    ecx,DWORD PTR [ebx]
    cmp    eax,ecx
    jae    Branch359
    lea    ecx,[esp+0x34]
    lea    edx,[esp+0x20]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    push   eax
    jmp    Branch360
  Branch359:
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x14]
    push   eax
    mov    BYTE PTR [esp+0x17],0x0
    push   ecx
  Branch360:
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],edx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch361:
    mov    ebp,DWORD PTR [esp+0x38]
    mov    ecx,DWORD PTR [edi+0x10]
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    ecx,eax
    jbe    Branch364
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch362
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch363
  Branch362:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch363
    mov    DWORD PTR [eax+0x8],ebp
  Branch363:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch364:
    jb     Branch365
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch365:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    cmp    ebx,eax
    jne    Branch369
    cmp    edi,eax
    mov    ecx,esi
    push   ebp
    je     Branch366
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch368
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch368
  Branch366:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch367
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch368
  Branch367:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch368
    mov    DWORD PTR [eax+0x8],ebp
  Branch368:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    eax,DWORD PTR [esi]
    add    eax,0x4
    push   eax
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch369:
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [ebx+0x10]
    cmp    edx,ecx
    jae    Branch376
    mov    ecx,DWORD PTR [edi+0xc]
    push   ebp
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch373
    cmp    edi,eax
    je     Branch370
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch372
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch372
  Branch370:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch371
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch372
  Branch371:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch372
    mov    DWORD PTR [eax+0x8],ebp
  Branch372:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [esi]
    add    edx,0x4
    push   edx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch373:
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    edi,eax
    mov    DWORD PTR [ebx+0x8],edi
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne    Branch374
    mov    DWORD PTR [eax+0x4],edi
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch375
  Branch374:
    cmp    ebx,DWORD PTR [eax+0x8]
    jne    Branch375
    mov    DWORD PTR [eax+0x8],edi
  Branch375:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch376:
    mov    edi,DWORD PTR [eax+0x4]
    mov    ebx,eax
    test   edi,edi
    mov    cl,0x1
    je     Branch380
  Branch377:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebx,edi
    cmp    edx,ecx
    setb   cl
    test   cl,cl
    je     Branch378
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch379
  Branch378:
    mov    edi,DWORD PTR [edi+0xc]
  Branch379:
    test   edi,edi
    jne    Branch377
  Branch380:
    mov    eax,ebx
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch382
    lea    edx,[esp+0x20]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch381
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x1c]
    push   eax
    push   0x0
    push   ebp
    push   ebx
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch381:
    push   ecx
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch382:
    mov    edx,DWORD PTR [eax+0x10]
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    edx,eax
    jae    Branch383
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x18]
    push   eax
    push   0x0
    push   ebp
    push   ebx
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch383:
    lea    edx,[esp+0x13]
    lea    eax,[esp+0x14]
    push   edx
    lea    ecx,[esp+0x28]
    push   eax
    mov    BYTE PTR [esp+0x1b],0x0
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch384:
    cmp    edi,ebp
    jne    Branch386
    mov    ebp,DWORD PTR [ebp+0xc]
    mov    eax,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [ebp+0x10]
    mov    ecx,DWORD PTR [eax]
    cmp    edx,ecx
    mov    ecx,esi
    jae    Branch385
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    push   eax
    push   ebp
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch385:
    push   eax
    lea    eax,[esp+0x28]
    push   eax
    jmp    Branch394
  Branch386:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    mov    ebp,DWORD PTR [esp+0x3c]
    mov    ebx,DWORD PTR [edi+0x10]
    add    esp,0x4
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    ecx,ebx
    setb   bl
    test   bl,bl
    je     Branch388
    cmp    DWORD PTR [eax+0x10],ecx
    jae    Branch388
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch387
    mov    edi,DWORD PTR [esp+0x30]
    push   eax
    push   ebp
    push   eax
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch387:
    push   0x0
    push   ebp
    push   edi
    push   edi
    mov    edi,DWORD PTR [esp+0x40]
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch388:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    add    esp,0x4
    test   bl,bl
    sete   cl
    test   bl,bl
    jne    Branch391
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [edi+0x10]
    cmp    ecx,edx
    setb   cl
    test   cl,cl
    je     Branch392
    cmp    eax,DWORD PTR [esi]
    je     Branch389
    cmp    edx,DWORD PTR [eax+0x10]
    jae    Branch391
  Branch389:
    mov    ecx,DWORD PTR [edi+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch390
    push   edi
    push   ebp
    push   edi
    mov    edi,DWORD PTR [esp+0x3c]
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch390:
    mov    edi,DWORD PTR [esp+0x30]
    push   0x0
    push   ebp
    push   eax
    push   eax
    push   edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch391:
    cmp    bl,cl
    jne    Branch393
  Branch392:
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch393:
    lea    edx,[esp+0x24]
    push   ebp
    push   edx
    mov    ecx,esi
  Branch394:
    call   R6GameServiceAddresses::FindOrInsertOrderedTreeNodeByU32Key
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  }
}

// Find a byte-string node using signed range lengths and unsigned byte comparisons; return the cached head on failure.
// Tree/node types are inferred. Traversal caches the query begin/length; the final comparison reloads its descriptor.
// Final query >= candidate accepts the saved candidate; ordinary stable trees make this an exact-match lookup.
// Empty trees never read the query. The original query argument slot becomes final candidate-length scratch; RET4.
// R6GameService.dll @ 1004b760 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall FindServiceTreeNodeByByteString(void *tree,undefined4 *keyDescriptor)
{
  __asm {
    sub    esp,0x14
    mov    eax,DWORD PTR [ecx]
    push   ebx
    push   ebp
    mov    ebp,eax
    mov    ebx,DWORD PTR [eax+0x4]
    push   esi
    test   ebx,ebx
    push   edi
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x10],ebp
    je     Branch402
    mov    eax,DWORD PTR [esp+0x28]
    mov    edi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    sub    eax,edi
    mov    DWORD PTR [esp+0x18],edi
    mov    DWORD PTR [esp+0x1c],eax
    jmp    Branch396
  Branch395:
    mov    edi,DWORD PTR [esp+0x18]
  Branch396:
    mov    esi,DWORD PTR [ebx+0x10]
    mov    edx,DWORD PTR [ebx+0x14]
    sub    edx,esi
    lea    ecx,[esp+0x1c]
    cmp    eax,edx
    mov    DWORD PTR [esp+0x20],edx
    jl     Branch397
    lea    ecx,[esp+0x20]
  Branch397:
    mov    ecx,DWORD PTR [ecx]
    xor    ebp,ebp
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch398
    sbb    ebp,ebp
    sbb    ebp,0xffffffff
  Branch398:
    test   ebp,ebp
    jne    Branch399
    cmp    edx,eax
    jl     Branch400
    xor    ecx,ecx
    cmp    edx,eax
    setg   cl
    mov    ebp,ecx
    test   ebp,ebp
  Branch399:
    jl     Branch400
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebx,DWORD PTR [ebx+0x8]
    jmp    Branch401
  Branch400:
    mov    ebx,DWORD PTR [ebx+0xc]
  Branch401:
    test   ebx,ebx
    jne    Branch395
    mov    eax,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [esp+0x10]
  Branch402:
    cmp    ebp,eax
    je     Branch408
    mov    eax,DWORD PTR [esp+0x28]
    mov    edi,DWORD PTR [ebp+0x10]
    mov    ebx,DWORD PTR [ebp+0x14]
    mov    esi,DWORD PTR [eax]
    mov    edx,DWORD PTR [eax+0x4]
    sub    edx,esi
    sub    ebx,edi
    cmp    ebx,edx
    mov    DWORD PTR [esp+0x20],edx
    mov    DWORD PTR [esp+0x28],ebx
    lea    eax,[esp+0x28]
    jl     Branch403
    lea    eax,[esp+0x20]
  Branch403:
    mov    ecx,DWORD PTR [eax]
    xor    ebp,ebp
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch404
    sbb    ebp,ebp
    sbb    ebp,0xffffffff
  Branch404:
    test   ebp,ebp
    jne    Branch405
    cmp    edx,ebx
    jl     Branch406
    xor    eax,eax
    cmp    edx,ebx
    setg   al
    mov    ebp,eax
    test   ebp,ebp
  Branch405:
    jge    Branch407
  Branch406:
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x14
    ret    0x4
  Branch407:
    mov    eax,DWORD PTR [esp+0x10]
  Branch408:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x14
    ret    0x4
  }
}

// Find an existing byte-keyed record or allocate/deep-copy an80-byte node and link/rebalance it.
// Descriptor/source pointer is cached; comparisons and allocation read its current fields. Generic class unassigned.
// Both native insertion branches retain head/extrema reloads and the exhausted-cursor test before choosing a side.
// Publish count only after rebalance; output DWORD node plus BYTE inserted flag, other output bytes untouched.
// No own exception registration/rollback; child constructor handles its own partial construction. RET8/output EAX.
// R6GameService.dll @ 10055d80 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 *__thiscall InsertOrFindByteDescriptorNode(
    void *tree,undefined4 *output,const void *source)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,ecx
    mov    ebx,DWORD PTR [esp+0x10]
    push   esi
    push   edi
    mov    esi,DWORD PTR [ebp+0x0]
    mov    al,0x1
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    je     Branch412
  Branch409:
    mov    eax,DWORD PTR [edi+0x14]
    mov    ecx,DWORD PTR [edi+0x10]
    mov    edx,DWORD PTR [ebx]
    push   eax
    mov    eax,DWORD PTR [ebx+0x4]
    push   ecx
    push   eax
    push   edx
    mov    esi,edi
    call   R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test   eax,eax
    setl   al
    test   al,al
    je     Branch410
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch411
  Branch410:
    mov    edi,DWORD PTR [edi+0xc]
  Branch411:
    test   edi,edi
    jne    Branch409
  Branch412:
    mov    ecx,esi
    test   al,al
    mov    DWORD PTR [esp+0x18],ecx
    je     Branch417
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch416
    cmp    esi,eax
    je     Branch413
    test   edi,edi
    jne    Branch413
    lea    eax,[esi+0x10]
    push   eax
    push   ebx
    call   R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test   al,al
    jne    Branch413
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AllocateIndexedTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch415
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch415
  Branch413:
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AllocateIndexedTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch414
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch415
  Branch414:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch415
    mov    DWORD PTR [eax+0x8],edi
  Branch415:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push   edx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch416:
    push   esi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x18],eax
    mov    ecx,eax
  Branch417:
    mov    eax,DWORD PTR [ebx+0x4]
    mov    edx,DWORD PTR [ecx+0x14]
    mov    ecx,DWORD PTR [ecx+0x10]
    push   eax
    mov    eax,DWORD PTR [ebx]
    push   eax
    push   edx
    push   ecx
    call   R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test   eax,eax
    jge    Branch421
    cmp    esi,DWORD PTR [ebp+0x0]
    je     Branch418
    test   edi,edi
    jne    Branch418
    lea    eax,[esi+0x10]
    push   eax
    push   ebx
    call   R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test   al,al
    jne    Branch418
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AllocateIndexedTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch420
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch420
  Branch418:
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AllocateIndexedTreeNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch419
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch420
  Branch419:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch420
    mov    DWORD PTR [eax+0x8],edi
  Branch420:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push   edx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch421:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    mov    BYTE PTR [eax+0x4],0x0
    pop    ebx
    ret    0x8
  }
}

// Shared collection destruction metadata used by clMatchResults and clPlayerResults.
// Tail release CURRENT first word of saved tree slot[parent ENTRY ESP-10], without clearing slot.
// R6GameService.dll @ 10066e30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl UnwindCollection(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select collection lifetime map and tail-enter current CRT frame dispatch.
// R6GameService.dll @ 10066e38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectCollectionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_supportSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10081528 : exact collection lifetime map/FuncInfo words.
const R6GameServiceNative::UnwindEntry ordered_tree_supportSharedLifetimeUnwindMap3[1] = {
  {-1, R6GameServiceAddresses::UnwindCollection},
};

// R6GameService.dll data @ 10081530 : exact collection lifetime map/FuncInfo words.
// R6GameService.dll data @ 10081528 : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_supportSharedLifetimeExceptionInfo3 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ordered_tree_supportSharedLifetimeUnwindMap3,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Release right subtree, cache current left, destroy owning pair at node10, free node, then continue left.
// Context only forwards recursively; no field interpretation, own EH, deduplication or link/count reset.
// Null node preserves incoming EAX; otherwise raw final free result, RET4.
// R6GameService.dll @ 10041540 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseServiceTreeSubtree(void *context,int nodeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch423
    push   edi
  Branch422:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseServiceTreeSubtree
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::DestroyServiceTreeRecord
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch422
    pop    edi
  Branch423:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Find a signed key for stable inputs and write node/head to current output pointer; historical lower-bound name retained.
// Cache head/query pointer and first traversal key; reload CURRENT query for final query>=candidate acceptance.
// Empty tree never dereferences the query. Raw output pointer EAX/RET8; only output DWORD written.
// R6GameService.dll @ 100552b0 : complete native control/access order and raw ABI retained.
__declspec(naked) int *__thiscall FindIndexedTreeLowerBound(void *tree,int *output,int *requestedKey)
{
  __asm {
    mov    ecx,DWORD PTR [ecx]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx+0x4]
    mov    edx,ecx
    test   eax,eax
    je     Branch427
    mov    esi,DWORD PTR [edi]
  Branch424:
    cmp    DWORD PTR [eax+0x10],esi
    jl     Branch425
    mov    edx,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch426
  Branch425:
    mov    eax,DWORD PTR [eax+0xc]
  Branch426:
    test   eax,eax
    jne    Branch424
  Branch427:
    cmp    edx,ecx
    je     Branch428
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [edx+0x10]
    cmp    eax,esi
    jge    Branch429
  Branch428:
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ecx
    ret    0x8
  Branch429:
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],edx
    ret    0x8
  }
}

// Allocate/copy a record node and place it left for head, or for zero hint with nonzero leftChild/smaller key.
// Nonzero hint selects right for a non-head parent. Preserve cached source/parent and current head/extrema stores.
// Native inline red-black repair retains its exact current accesses, cached root-slot address and shared rotations.
// Increment current count after repair, write only node DWORD to CURRENT output, RET20/output EAX; no own guard.
// R6GameService.dll @ 10055320 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 *__thiscall InsertIndexedTreeNodeAndRebalance(
    void *tree,undefined4 *output,int leftChild,int parent,int *sourceRecord,int hint)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push   edi
    je     Branch431
    mov    ecx,DWORD PTR [esp+0x24]
    test   ecx,ecx
    jne    Branch430
    mov    ecx,DWORD PTR [esp+0x18]
    test   ecx,ecx
    jne    Branch431
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esi+0x10]
    cmp    ecx,edx
    jl     Branch431
  Branch430:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch433
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch433
  Branch431:
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    jne    Branch432
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [ebx]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch433
  Branch432:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch433
    mov    DWORD PTR [eax+0x8],ebp
  Branch433:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [ebp+0x0],al
    add    edi,0x4
    mov    esi,ebp
    cmp    ebp,DWORD PTR [edi]
    je     Branch449
  Branch434:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch449
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch445
    mov    ecx,DWORD PTR [edx+0xc]
    test   ecx,ecx
    je     Branch436
    cmp    BYTE PTR [ecx],0x0
    jne    Branch436
  Branch435:
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch448
  Branch436:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch441
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch437
    mov    DWORD PTR [ecx+0x4],esi
  Branch437:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch438
    mov    DWORD PTR [edi],eax
    jmp    Branch440
  Branch438:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch439
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch440
  Branch439:
    mov    DWORD PTR [ecx+0xc],eax
  Branch440:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch441:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test   edx,edx
    je     Branch442
    mov    DWORD PTR [edx+0x4],eax
  Branch442:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch443
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch448
  Branch443:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch444
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch448
  Branch444:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch448
  Branch445:
    test   ecx,ecx
    je     Branch446
    cmp    BYTE PTR [ecx],0x0
    je     Branch435
  Branch446:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch447
    mov    esi,eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch447:
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    call   R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch448:
    cmp    esi,DWORD PTR [edi]
    jne    Branch434
  Branch449:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    eax,DWORD PTR [ebx+0x4]
    inc    eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Find or insert a signed-key record; search caches its first key value, while final duplicate/side tests reload it.
// Existing record payload is retained. Both insertion copies keep exhausted-cursor/head alternatives and live stores.
// New nodes use actual record construction and shared red-black repair; count publishes after repair.
// Write node DWORD plus inserted BYTE only, RET8/output EAX; no own exception registration or rollback.
// R6GameService.dll @ 100554f0 : complete native control/access order and raw ABI retained.
__declspec(naked) int *__thiscall ordered_tree_support_FindOrInsertIndexedTreeNode(void *tree,int *output,int *sourceRecord)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,0x1
    mov    edx,DWORD PTR [edi]
    mov    esi,edx
    mov    ebp,DWORD PTR [edx+0x4]
    test   ebp,ebp
    je     Branch453
    mov    eax,DWORD PTR [ebx]
  Branch450:
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    esi,ebp
    cmp    eax,ecx
    setl   cl
    test   cl,cl
    je     Branch451
    mov    ebp,DWORD PTR [ebp+0x8]
    jmp    Branch452
  Branch451:
    mov    ebp,DWORD PTR [ebp+0xc]
  Branch452:
    test   ebp,ebp
    jne    Branch450
  Branch453:
    test   cl,cl
    mov    eax,esi
    je     Branch458
    cmp    esi,DWORD PTR [edx+0x8]
    jne    Branch457
    cmp    esi,edx
    je     Branch454
    test   ebp,ebp
    jne    Branch454
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jl     Branch454
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch456
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch456
  Branch454:
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch455
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch456
  Branch455:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch456
    mov    DWORD PTR [eax+0x8],ebp
  Branch456:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [edi]
    add    edx,0x4
    push   edx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch457:
    push   esi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
  Branch458:
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [eax+0x10]
    cmp    edx,ecx
    jge    Branch462
    cmp    esi,DWORD PTR [edi]
    je     Branch459
    test   ebp,ebp
    jne    Branch459
    cmp    ecx,DWORD PTR [esi+0x10]
    jl     Branch459
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch461
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch461
  Branch459:
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch460
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch461
  Branch460:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch461
    mov    DWORD PTR [eax+0x8],ebp
  Branch461:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [edi]
    add    ecx,0x4
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch462:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ecx],eax
    mov    BYTE PTR [ecx+0x4],0x0
    mov    eax,ecx
    pop    ebx
    ret    0x8
  }
}

// Return exact signed-key node for stable inputs, otherwise cached head; final current query>=candidate test is literal.
// Cache head/query pointer/traversal key, then reload current query for final acceptance; empty tree avoids query read.
// Raw node word EAX/RET4, no writes or local guard.
// R6GameService.dll @ 10055660 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FindIndexedTreeKey(void *tree,int *requestedKey)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,eax
    test   ecx,ecx
    je     Branch466
    mov    esi,DWORD PTR [edi]
  Branch463:
    cmp    DWORD PTR [ecx+0x10],esi
    jl     Branch464
    mov    edx,ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    jmp    Branch465
  Branch464:
    mov    ecx,DWORD PTR [ecx+0xc]
  Branch465:
    test   ecx,ecx
    jne    Branch463
  Branch466:
    cmp    edx,eax
    je     Branch467
    mov    ecx,DWORD PTR [edi]
    mov    esi,DWORD PTR [edx+0x10]
    cmp    ecx,esi
    jl     Branch467
    mov    eax,edx
  Branch467:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Insert or find signed-key record using leftmost/end/neighbor hint paths or native full-search fallback.
// Keep each duplicated link branch, cached/current key/head/source distinction and exact builder/RB choices.
// Temporary node/flag construction can overwrite lowBYTE of original hint/source argument slots; cached pointers survive.
// Write only node DWORD through path-cached/current output; duplicate payload retained, RET12/output EAX, no own guard.
// R6GameService.dll @ 10054dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) int *__thiscall FindOrInsertIndexedTreeNode(
    void *tree,int *output,char *hintNode,int *sourceRecord)
{
  __asm {
    sub    esp,0x1c
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    mov    ebp,DWORD PTR [esi]
    cmp    edi,DWORD PTR [ebp+0x8]
    jne    Branch499
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    ja     Branch476
    mov    edi,DWORD PTR [ebp+0x4]
    mov    ebx,DWORD PTR [esp+0x38]
    test   edi,edi
    mov    cl,0x1
    je     Branch471
    mov    eax,DWORD PTR [ebx]
  Branch468:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebp,edi
    cmp    eax,ecx
    setl   cl
    test   cl,cl
    je     Branch469
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch470
  Branch469:
    mov    edi,DWORD PTR [edi+0xc]
  Branch470:
    test   edi,edi
    jne    Branch468
  Branch471:
    mov    eax,ebp
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch473
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch472
    lea    ecx,[esp+0x38]
    lea    edx,[esp+0x1c]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    push   eax
    jmp    Branch475
  Branch472:
    push   ecx
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch473:
    mov    eax,DWORD PTR [eax+0x10]
    mov    ecx,DWORD PTR [ebx]
    cmp    eax,ecx
    jge    Branch474
    lea    ecx,[esp+0x34]
    lea    edx,[esp+0x20]
    push   ecx
    push   0x0
    push   ebx
    push   ebp
    push   edi
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    push   eax
    jmp    Branch475
  Branch474:
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x14]
    push   eax
    mov    BYTE PTR [esp+0x17],0x0
    push   ecx
  Branch475:
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],edx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch476:
    mov    ebp,DWORD PTR [esp+0x38]
    mov    ecx,DWORD PTR [edi+0x10]
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    ecx,eax
    jle    Branch479
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch477
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch478
  Branch477:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch478
    mov    DWORD PTR [eax+0x8],ebp
  Branch478:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch479:
    jl     Branch480
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch480:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    cmp    ebx,eax
    jne    Branch484
    cmp    edi,eax
    mov    ecx,esi
    push   ebp
    je     Branch481
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch483
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch483
  Branch481:
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch482
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch483
  Branch482:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch483
    mov    DWORD PTR [eax+0x8],ebp
  Branch483:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    eax,DWORD PTR [esi]
    add    eax,0x4
    push   eax
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch484:
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [ebx+0x10]
    cmp    edx,ecx
    jge    Branch491
    mov    ecx,DWORD PTR [edi+0xc]
    push   ebp
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch488
    cmp    edi,eax
    je     Branch485
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch487
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch487
  Branch485:
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch486
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch487
  Branch486:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch487
    mov    DWORD PTR [eax+0x8],ebp
  Branch487:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [esi]
    add    edx,0x4
    push   edx
    push   ebp
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch488:
    call   R6GameServiceAddresses::AllocateIndexedRecordAndCopyList
    mov    edi,eax
    mov    DWORD PTR [ebx+0x8],edi
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne    Branch489
    mov    DWORD PTR [eax+0x4],edi
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch490
  Branch489:
    cmp    ebx,DWORD PTR [eax+0x8]
    jne    Branch490
    mov    DWORD PTR [eax+0x8],edi
  Branch490:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push   ecx
    push   edi
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch491:
    mov    edi,DWORD PTR [eax+0x4]
    mov    ebx,eax
    test   edi,edi
    mov    cl,0x1
    je     Branch495
  Branch492:
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebx,edi
    cmp    edx,ecx
    setl   cl
    test   cl,cl
    je     Branch493
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch494
  Branch493:
    mov    edi,DWORD PTR [edi+0xc]
  Branch494:
    test   edi,edi
    jne    Branch492
  Branch495:
    mov    eax,ebx
    test   cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch497
    lea    edx,[esp+0x20]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch496
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x1c]
    push   eax
    push   0x0
    push   ebp
    push   ebx
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch496:
    push   ecx
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch497:
    mov    edx,DWORD PTR [eax+0x10]
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    edx,eax
    jge    Branch498
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x18]
    push   eax
    push   0x0
    push   ebp
    push   ebx
    push   edi
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    lea    ecx,[esp+0x28]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch498:
    lea    edx,[esp+0x13]
    lea    eax,[esp+0x14]
    push   edx
    lea    ecx,[esp+0x28]
    push   eax
    mov    BYTE PTR [esp+0x1b],0x0
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch499:
    cmp    edi,ebp
    jne    Branch501
    mov    ebp,DWORD PTR [ebp+0xc]
    mov    eax,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [ebp+0x10]
    mov    ecx,DWORD PTR [eax]
    cmp    edx,ecx
    mov    ecx,esi
    jge    Branch500
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    push   eax
    push   ebp
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch500:
    push   eax
    lea    eax,[esp+0x28]
    push   eax
    jmp    Branch509
  Branch501:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    mov    ebp,DWORD PTR [esp+0x3c]
    mov    ebx,DWORD PTR [edi+0x10]
    add    esp,0x4
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    ecx,ebx
    setl   bl
    test   bl,bl
    je     Branch503
    cmp    DWORD PTR [eax+0x10],ecx
    jge    Branch503
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch502
    mov    edi,DWORD PTR [esp+0x30]
    push   eax
    push   ebp
    push   eax
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch502:
    push   0x0
    push   ebp
    push   edi
    push   edi
    mov    edi,DWORD PTR [esp+0x40]
    push   edi
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch503:
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    add    esp,0x4
    test   bl,bl
    sete   cl
    test   bl,bl
    jne    Branch506
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [edi+0x10]
    cmp    ecx,edx
    setl   cl
    test   cl,cl
    je     Branch507
    cmp    eax,DWORD PTR [esi]
    je     Branch504
    cmp    edx,DWORD PTR [eax+0x10]
    jge    Branch506
  Branch504:
    mov    ecx,DWORD PTR [edi+0xc]
    test   ecx,ecx
    mov    ecx,esi
    jne    Branch505
    push   edi
    push   ebp
    push   edi
    mov    edi,DWORD PTR [esp+0x3c]
    push   0x0
    push   edi
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch505:
    mov    edi,DWORD PTR [esp+0x30]
    push   0x0
    push   ebp
    push   eax
    push   eax
    push   edi
    call   R6GameServiceAddresses::InsertIndexedTreeNodeAndRebalance
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch506:
    cmp    bl,cl
    jne    Branch508
  Branch507:
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch508:
    lea    edx,[esp+0x24]
    push   ebp
    push   edx
    mov    ecx,esi
  Branch509:
    call   R6GameServiceAddresses::ordered_tree_support_FindOrInsertIndexedTreeNode
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  }
}

// Reload the current header before each byte/parent/left/right initialization; leave padding untouched.
// Raw EAX/EDX/ECX retain the third/second/fourth loaded header pointers; no cached-header substitution.
// R6GameService.dll @ 1004b490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall InitializeServiceTreeHeader(void *headerSlot)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    mov    BYTE PTR [eax],0x0
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [ecx]
    mov    DWORD PTR [ecx+0xc],ecx
    ret
  }
}

// Recurse right, then capture current left link, release current node string and node, and continue on cached left.
// No local guard or link repair; null input retains entry EAX and nonempty completion retains final free EAX.
// R6GameService.dll @ 1004b4b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FreeNestedListNodes(void *context,int node)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test    esi,esi
    je    Branch511
    push    edi
  Branch510:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push    eax
    call    R6GameServiceAddresses::FreeNestedListNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    edi,edi
    mov    esi,edi
    jne    Branch510
    pop    edi
  Branch511:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Allocate raw1c node, guard string at+10, allocate length+1 and move captured key range; publish returned end/NUL.
// Preserve raw adjusted-pointer guard, captured descriptor, current raw-node return slot and catch/unwind stages.
// R6GameService.dll @ 1004b6b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CreateServiceTreeByteStringNode(void *treeContext,void *keyDescriptor)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectServiceStringNodeEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    mov    DWORD PTR [ebp-0x10],esp
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    xor    edi,edi
    lea    esi,[eax+0x10]
    mov    DWORD PTR [ebp-0x14],eax
    mov    DWORD PTR [ebp-0x4],edi
    mov    DWORD PTR [ebp-0x18],esi
    mov    DWORD PTR [ebp-0x1c],esi
    cmp    esi,edi
    mov    BYTE PTR [ebp-0x4],0x1
    je    Branch512
    mov    ebx,DWORD PTR [ebp+0x8]
    lea    eax,[ebp+0xb]
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::ForwardStackWord
    mov    DWORD PTR [esi],edi
    mov    DWORD PTR [esi+0x4],edi
    mov    DWORD PTR [esi+0x8],edi
    mov    edi,DWORD PTR [ebx+0x4]
    mov    ebx,DWORD PTR [ebx]
    mov    eax,edi
    mov    ecx,esi
    sub    eax,ebx
    mov    BYTE PTR [ebp-0x4],0x2
    inc    eax
    push    eax
    call    R6GameServiceAddresses::InitializeHeapByteString
    mov    eax,DWORD PTR [esi]
    lea    ecx,[ebp+0xb]
    push    ecx
    push    eax
    push    edi
    push    ebx
    call    R6GameServiceAddresses::CopyByteRange
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,DWORD PTR [ebp-0x14]
  Branch512:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Free CURRENT inherited raw node EBP-14, then rethrow with the native two zero arguments; no local frame.
// R6GameService.dll @ 1004b747 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_supportCatch(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x14]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    0x0
    push    0x0
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// Forward both inherited string-guard words through the genuine empty helper; retain their load/stack effects.
// R6GameService.dll @ 100680c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CreateServiceTreeByteStringNodeUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push    eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push    ecx
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Release the CURRENT inherited string descriptor EBP-1c through its first-word free; do not free the raw node here.
// R6GameService.dll @ 100680d1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CreateServiceTreeByteStringNodeUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the four-state raw-node/string lifetime map and catch-all try record; tail the existing runtime dispatcher.
// R6GameService.dll @ 100680d9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceStringNodeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CreateServiceTreeByteStringNodeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal string-node unwind/catch/try/FuncInfo words.
// R6GameService.dll data @ 10082aa4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CreateServiceTreeByteStringNodeUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::CreateServiceTreeByteStringNodeUnwind2},
  {0x1, R6GameServiceAddresses::CreateServiceTreeByteStringNodeUnwind3},
  {-1, 0x0},
};

// Literal string-node unwind/catch/try/FuncInfo words.
// R6GameService.dll data @ 10082ac4 : native storage identity retained.
const R6GameServiceNative::CatchHandler ordered_tree_supportGServiceStringNodeEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ordered_tree_supportCatch},
};

// Literal string-node unwind/catch/try/FuncInfo words.
// R6GameService.dll data @ 10082ad4 : native storage identity retained.
const R6GameServiceNative::TryBlock CreateServiceTreeByteStringNodeTryMap[1] = {
  {0x0, 0x2, 0x3, 0x1, R6GameServiceAddresses::ordered_tree_supportGServiceStringNodeEH},
};

// Literal string-node unwind/catch/try/FuncInfo words.
// R6GameService.dll data @ 10082ae8 : native storage identity retained.
const R6GameServiceNative::FuncInfo CreateServiceTreeByteStringNodeExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::CreateServiceTreeByteStringNodeUnwindMap,
  0x1,
  R6GameServiceAddresses::CreateServiceTreeByteStringNodeTryMap,
  0x0,
  0x0,
};

// Find equal byte key or copy/link/rebalance a new node, increment count and publish node plus BYTE insertion flag.
// Preserve predecessor candidate argument rewrite, late output/current header reads, native count wrap and raw EAX.
// R6GameService.dll @ 1004b4f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall FindOrInsertServiceTreeByteString(
    void *tree,void *result,void *keyDescriptor)
{
  __asm {
    push    ebx
    push    ebp
    mov    ebp,ecx
    mov    ebx,DWORD PTR [esp+0x10]
    push    esi
    push    edi
    mov    esi,DWORD PTR [ebp+0x0]
    mov    al,0x1
    mov    edi,DWORD PTR [esi+0x4]
    test    edi,edi
    je    Branch516
  Branch513:
    mov    eax,DWORD PTR [edi+0x14]
    mov    ecx,DWORD PTR [edi+0x10]
    mov    edx,DWORD PTR [ebx]
    push    eax
    mov    eax,DWORD PTR [ebx+0x4]
    push    ecx
    push    eax
    push    edx
    mov    esi,edi
    call    R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test    eax,eax
    setl    al
    test    al,al
    je    Branch514
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch515
  Branch514:
    mov    edi,DWORD PTR [edi+0xc]
  Branch515:
    test    edi,edi
    jne    Branch513
  Branch516:
    mov    ecx,esi
    test    al,al
    mov    DWORD PTR [esp+0x18],ecx
    je    Branch521
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch520
    cmp    esi,eax
    je    Branch517
    test    edi,edi
    jne    Branch517
    lea    eax,[esi+0x10]
    push    eax
    push    ebx
    call    R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test    al,al
    jne    Branch517
    push    ebx
    mov    ecx,ebp
    call    R6GameServiceAddresses::CreateServiceTreeByteStringNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch519
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch519
  Branch517:
    push    ebx
    mov    ecx,ebp
    call    R6GameServiceAddresses::CreateServiceTreeByteStringNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch518
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch519
  Branch518:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch519
    mov    DWORD PTR [eax+0x8],edi
  Branch519:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push    edx
    push    edi
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch520:
    push    esi
    call    R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x18],eax
    mov    ecx,eax
  Branch521:
    mov    eax,DWORD PTR [ebx+0x4]
    mov    edx,DWORD PTR [ecx+0x14]
    mov    ecx,DWORD PTR [ecx+0x10]
    push    eax
    mov    eax,DWORD PTR [ebx]
    push    eax
    push    edx
    push    ecx
    call    R6GameServiceAddresses::CompareByteRanges
    add    esp,0x10
    test    eax,eax
    jge    Branch525
    cmp    esi,DWORD PTR [ebp+0x0]
    je    Branch522
    test    edi,edi
    jne    Branch522
    lea    eax,[esi+0x10]
    push    eax
    push    ebx
    call    R6GameServiceAddresses::ByteDescriptorLess
    add    esp,0x8
    test    al,al
    jne    Branch522
    push    ebx
    mov    ecx,ebp
    call    R6GameServiceAddresses::CreateServiceTreeByteStringNode
    mov    edi,eax
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch524
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch524
  Branch522:
    push    ebx
    mov    ecx,ebp
    call    R6GameServiceAddresses::CreateServiceTreeByteStringNode
    mov    edi,eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch523
    mov    DWORD PTR [eax+0x4],edi
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0xc],edi
    jmp    Branch524
  Branch523:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch524
    mov    DWORD PTR [eax+0x8],edi
  Branch524:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],esi
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    add    edx,0x4
    push    edx
    push    edi
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch525:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    mov    BYTE PTR [eax+0x4],0x0
    pop    ebx
    ret    0x8
  }
}

// Copy1023 bytes, release old name tree, then tokenize/copy/insert each distinct name with per-token string guards.
// Keep the untouched last buffer byte, partial replacement, current normal free slot and raw final helper return.
// R6GameService.dll @ 1004b350 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceServiceTreeNamesFromDelimitedText(void *owner,char *inputText)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectServiceNameTokenEH
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x418
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    0x3ff
    lea    ecx,[esp+0x28]
    push    eax
    push    ecx
    call    R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esi+0x28]
    lea    ebp,[esi+0x24]
    xor    ebx,ebx
    add    esp,0xc
    cmp    eax,ebx
    je    Branch526
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,ebp
    mov    eax,DWORD PTR [edx+0x4]
    push    eax
    call    R6GameServiceAddresses::FreeNestedListNodes
    mov    eax,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [ecx+0x4],ebx
    mov    eax,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [ebp+0x4],ebx
  Branch526:
    lea    edx,[esp+0x24]
    push    R6GameServiceAddresses::TextPunctuation3
    push    edx
    call    R6GameServiceAddresses::strtok
    mov    esi,eax
    add    esp,0x8
    cmp    esi,ebx
    je    Branch528
    push    edi
  Branch527:
    lea    eax,[esp+0x13]
    push    ebx
    push    eax
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x438],ebx
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x20],ebx
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    edi,esi
    or    ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x430],0x1
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    edi,ecx
    lea    ecx,[esp+0x14]
    add    edi,esi
    mov    eax,edi
    sub    eax,esi
    inc    eax
    push    eax
    call    R6GameServiceAddresses::InitializeHeapByteString
    mov    ecx,DWORD PTR [esp+0x14]
    push    ecx
    push    edi
    push    esi
    call    R6GameServiceAddresses::MoveByteRange
    mov    DWORD PTR [esp+0x18],eax
    mov    BYTE PTR [eax],bl
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x20]
    push    edx
    push    eax
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x438],0x3
    call    R6GameServiceAddresses::FindOrInsertServiceTreeByteString
    push    R6GameServiceAddresses::TextPunctuation3
    push    ebx
    call    R6GameServiceAddresses::strtok
    mov    ecx,DWORD PTR [esp+0x1c]
    add    esp,0x8
    mov    esi,eax
    mov    DWORD PTR [esp+0x430],0xffffffff
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,ebx
    jne    Branch527
    pop    edi
  Branch528:
    mov    ecx,DWORD PTR [esp+0x424]
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x424
    ret    0x4
  }
}

// Forward inherited EBP-421 cookie address to the genuine empty guard; do not invent descriptor cleanup.
// R6GameService.dll @ 10068090 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReplaceServiceTreeNamesFromDelimitedTextUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x421]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Free current temporary descriptor first word at inherited EBP-420 during state1; then trivial guard state0.
// R6GameService.dll @ 1006809b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReplaceServiceTreeNamesFromDelimitedTextUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x420]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Free current temporary EBP-420 descriptor for states2/3; predecessor is respectively0 or-1, without retry.
// R6GameService.dll @ 100680a6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReplaceServiceTreeNamesFromDelimitedTextUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x420]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the exact four-state per-token string lifetime map; tail the existing Windows frame dispatcher.
// R6GameService.dll @ 100680b1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceNameTokenEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal per-token string unwind and FuncInfo words.
// R6GameService.dll data @ 10082a68 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReplaceServiceTreeNamesFromDelimitedTextUnwindMap[4] = {
  {-1, R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextUnwind1},
  {0x0, R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextUnwind2},
  {0x0, R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextUnwind3},
  {-1, R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextUnwind3},
};

// Literal per-token string unwind and FuncInfo words.
// R6GameService.dll data @ 10082a88 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReplaceServiceTreeNamesFromDelimitedTextExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedTextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Return full1 when name filtering is disabled; otherwise construct/query/free a temporary byte string.
// Compare lookup result with CURRENT header, retain free upper EAX plus AL membership and armed state3 on free.
// R6GameService.dll @ 1004b270 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PassesOptionalServiceTreeNameFilter(void *owner,char *name)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectServiceNameFilterEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    xor    eax,eax
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    ecx,eax
    jne    Branch529
    mov    al,0x1
    pop    esi
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  Branch529:
    push    edi
    mov    DWORD PTR [esp+0x20],eax
    mov    DWORD PTR [esp+0xc],eax
    mov    DWORD PTR [esp+0x10],eax
    push    eax
    lea    eax,[esp+0xf]
    lea    ecx,[esp+0x18]
    push    eax
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    edx,DWORD PTR [esp+0x28]
    or    ecx,0xffffffff
    mov    edi,edx
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x28]
    mov    BYTE PTR [esp+0x20],0x1
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x28],al
    lea    eax,[esp+0x28]
    add    ecx,edx
    push    eax
    push    ecx
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ConstructHeapByteStringRange
    lea    ecx,[esp+0xc]
    add    esi,0x24
    push    ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x24],0x3
    call    R6GameServiceAddresses::FindServiceTreeNodeByByteString
    mov    ecx,DWORD PTR [esi]
    pop    edi
    cmp    eax,ecx
    je    Branch530
    mov    edx,DWORD PTR [esp+0x8]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    al,0x1
    pop    esi
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  Branch530:
    mov    eax,DWORD PTR [esp+0x8]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    xor    al,al
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  }
}

// Forward inherited EBP-19 cookie address through the genuine empty guard.
// R6GameService.dll @ 10068060 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PassesOptionalServiceTreeNameFilterUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x19]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release current EBP-18 descriptor first word for state1, then run the trivial cookie guard.
// R6GameService.dll @ 10068068 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PassesOptionalServiceTreeNameFilterUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Release current EBP-18 descriptor for states2/3; an interrupted normal free remains armed in state3.
// R6GameService.dll @ 10068070 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PassesOptionalServiceTreeNameFilterUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the exact four-state temporary-name lifetime map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10068078 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceNameFilterEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal optional-name filter unwind and FuncInfo words.
// R6GameService.dll data @ 10082a2c : native storage identity retained.
const R6GameServiceNative::UnwindEntry PassesOptionalServiceTreeNameFilterUnwindMap[4] = {
  {-1, R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterUnwind1},
  {0x0, R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterUnwind2},
  {0x0, R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterUnwind3},
  {-1, R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterUnwind3},
};

// Literal optional-name filter unwind and FuncInfo words.
// R6GameService.dll data @ 10082a4c : native storage identity retained.
const R6GameServiceNative::FuncInfo PassesOptionalServiceTreeNameFilterExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::PassesOptionalServiceTreeNameFilterUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Publish allocated24-byte header, zero count/root and self-link extrema; no NULL guard.
// Preserve byte at tree+8 from CURRENT high byte of saved entry ECX, EAX receiver and raw call effects.
// R6GameService.dll @ 10042c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall InitializeTreeSentinel24(void *tree)
{
  __asm {
    push    ecx
    push    esi
    mov    esi,ecx
    push    0x18
    mov    DWORD PTR [esi],0x0
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x7]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],0x0
    mov    BYTE PTR [esi+0x8],cl
    mov    BYTE PTR [eax],0x0
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret
  }
}

// If count is nonzero, free right-recursive/left-iterative nodes, reset CURRENT header/count, then free head.
// Never delete values; shared one-state guard releases CURRENT head slot after interruption. Raw EAX retained.
// R6GameService.dll @ 100428e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearOrderedTreeStorage(void *tree)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedTreeStorageDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch533
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch532
    push    ebx
  Branch531:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch531
    pop    ebx
  Branch532:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch533:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// If count is nonzero, free right-recursive/left-iterative nodes, reset CURRENT header/count, then free head.
// Never delete values; shared one-state guard releases CURRENT head slot after interruption. Raw EAX retained.
// R6GameService.dll @ 10041ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceSubtreeContainer(void *tree)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedTreeStorageDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch536
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch535
    push    ebx
  Branch534:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes2
    mov    ebx,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch534
    pop    ebx
  Branch535:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch536:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Release CURRENT saved tree first word; entered node destruction is not retried.
// R6GameService.dll @ 100671a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_supportSharedLifetimeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact inherited destruction FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 100671a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSharedTreeStorageDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ordered_tree_supportSharedLifetimeExceptionInfo4
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 10081898 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ordered_tree_supportSharedLifetimeUnwindMap4[1] = {
  {-1, R6GameServiceAddresses::ordered_tree_supportSharedLifetimeUnwind1},
};

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 100818a0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ordered_tree_supportSharedLifetimeExceptionInfo4 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ordered_tree_supportSharedLifetimeUnwindMap4,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Drain plain tree nodes when count is nonzero, reset CURRENT header/count and free head; raw final free EAX.
// Shared671a8 guard releases only CURRENT head after interruption; no value destruction or rollback.
// R6GameService.dll @ 100419a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceTreeContainer(void *tree)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedTreeStorageDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch539
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch538
    push    ebx
  Branch537:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes3
    mov    ebx,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch537
    pop    ebx
  Branch538:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch539:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Drain tree nodes and actual embedded two-word reference lifetimes, then reset CURRENT header/count and free head.
// Shared671a8 guard releases only CURRENT head after interruption; retain partial decrements and no retry.
// R6GameService.dll @ 10041aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServicePayloadTreeContainer(void *tree)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedTreeStorageDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch542
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch541
    push    ebx
  Branch540:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseTreePayloadNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x0
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::DeletePayloadReferenceAt16
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch540
    pop    ebx
  Branch541:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch542:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Recurse right+c, cache left8 and free each node; forward inherited ECX without object accesses. RET4.
// Original member/free-helper spelling remains unresolved; raw ECX/last result retained.
// R6GameService.dll @ 10051a70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ordered_tree_support_ReleaseLinkedNodes(int nodeAddress)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test    esi,esi
    je    Branch544
    push    edi
  Branch543:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push    eax
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    edi,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    edi,edi
    mov    esi,edi
    jne    Branch543
    pop    edi
  Branch544:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Clear head, allocate60-byte sentinel, clear count and set cookie from CURRENT saved entry ECX high byte.
// Initialize only color/root/min/max; keep allocator padding and raw receiver result. No own guard/NULL check.
// R6GameService.dll @ 10051900 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __fastcall InitializeTreeOwnerStorage(int *ownerWords)
{
  __asm {
    push    ecx
    push    esi
    mov    esi,ecx
    push    0x3c
    mov    DWORD PTR [esi],0x0
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x7]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],0x0
    mov    BYTE PTR [esi+0x8],cl
    mov    BYTE PTR [eax],0x0
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret
  }
}

// Nonzero count drains right/current/left through cached left links, then resets CURRENT head/count; keep head.
// Count0 preserves live nodes and returns0; otherwise return final head pointer, without normalization or own guard.
// R6GameService.dll @ 10051940 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearTreeOwnerStorage(int *ownerWords)
{
  __asm {
    push    edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test    eax,eax
    je    Branch547
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch546
    push    ebx
  Branch545:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch545
    pop    ebx
  Branch546:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch547:
    pop    edi
    ret
  }
}

// Allocate/copy payload before color/links; recurse right, iterate left, retaining exact source reload order. RET8.
// EBP+8 becomes copied root; state0 catch51a24 owns linked partial copy. Continuation51a51 stays in this body.
// R6GameService.dll @ 10051990 : complete split native body; catch51a24 defined separately.
__declspec(naked) undefined1 * __thiscall CloneOrderedTreeSubtree(
    void *tree,undefined1 *sourceRoot,uint parentNode)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTreeCloneCatchEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    mov    edi,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ebp-0x10],esp
    mov    ebx,ecx
    lea    eax,[edi+0x10]
    mov    DWORD PTR [ebp-0x14],ebx
    push    eax
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    cl,BYTE PTR [edi]
    mov    edx,DWORD PTR [ebp+0xc]
    mov    esi,eax
    mov    DWORD PTR [ebp+0x8],esi
    mov    BYTE PTR [esi],cl
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi+0xc]
    cmp    eax,ecx
    mov    DWORD PTR [ebp-0x4],ecx
    je    Branch549
    mov    ecx,ebx
  Branch548:
    push    esi
    push    eax
    call    R6GameServiceAddresses::CloneOrderedTreeSubtree
    mov    DWORD PTR [esi+0xc],eax
  Branch549:
    mov    edi,DWORD PTR [edi+0x8]
    mov    ebx,esi
    test    edi,edi
    je    Branch550
    mov    ecx,DWORD PTR [ebp-0x14]
    lea    eax,[edi+0x10]
    push    eax
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    cl,BYTE PTR [edi]
    mov    esi,eax
    mov    BYTE PTR [esi],cl
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [ebx+0x8],esi
    mov    DWORD PTR [esi+0x4],ebx
    mov    eax,DWORD PTR [edi+0xc]
    cmp    eax,ecx
    je    Branch549
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    Branch548
  Branch550:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp+0x8]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Release CURRENT caught root at inherited EBP+8 using tree contextEBP-14, then rethrow(0,0); no normal return.
// Right recursion/cached-left iteration touches only the linked partial copy; initial state-1 is outside this catch.
// R6GameService.dll @ 10051a24 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_support_ordered_tree_supportCatch(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp+0x8]
    test    esi,esi
    je    Branch552
    mov    ebx,DWORD PTR [ebp-0x14]
  Branch551:
    mov    edx,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push    edx
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    edi,DWORD PTR [esi+0x8]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    edi,edi
    mov    esi,edi
    jne    Branch551
  Branch552:
    push    0x0
    push    0x0
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// Insert/find unsigned key using minimum/end/interior hint, inline search or actual unique-insert fallback.
// Write caller nodeDWORD only and return its output pointer; local pair flags reuse hint/payload argument lowBYTE.
// Preserve captured versus late output/header/key/count loads and child construction before publication. RETc.
// No own EH, rollback or query/hint repair; pointer/iterator source types remain inferred.
// R6GameService.dll @ 10051ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __thiscall InsertOrFindOrderedTreeNodeByU16Key(
    void *tree,int *outputNode,char *hintNode,ushort *payload)
{
  __asm {
    sub    esp,0x1c
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    edi,DWORD PTR [esp+0x34]
    mov    ebp,DWORD PTR [esi]
    cmp    edi,DWORD PTR [ebp+0x8]
    jne    Branch584
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    ja    Branch561
    mov    edi,DWORD PTR [ebp+0x4]
    mov    ebx,DWORD PTR [esp+0x38]
    test    edi,edi
    mov    cl,0x1
    je    Branch556
    mov    ax,WORD PTR [ebx]
  Branch553:
    cmp    ax,WORD PTR [edi+0x10]
    mov    ebp,edi
    setb    cl
    test    cl,cl
    je    Branch554
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch555
  Branch554:
    mov    edi,DWORD PTR [edi+0xc]
  Branch555:
    test    edi,edi
    jne    Branch553
  Branch556:
    mov    eax,ebp
    test    cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je    Branch558
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch557
    lea    ecx,[esp+0x38]
    lea    edx,[esp+0x1c]
    push    ecx
    push    0x0
    push    ebx
    push    ebp
    push    edi
    push    edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    push    eax
    jmp    Branch560
  Branch557:
    push    ecx
    call    R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch558:
    mov    ax,WORD PTR [eax+0x10]
    cmp    ax,WORD PTR [ebx]
    jae    Branch559
    lea    ecx,[esp+0x34]
    lea    edx,[esp+0x20]
    push    ecx
    push    0x0
    push    ebx
    push    ebp
    push    edi
    push    edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    push    eax
    jmp    Branch560
  Branch559:
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x14]
    push    eax
    mov    BYTE PTR [esp+0x17],0x0
    push    ecx
  Branch560:
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],edx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch561:
    mov    ebp,DWORD PTR [esp+0x38]
    mov    cx,WORD PTR [edi+0x10]
    mov    ax,WORD PTR [ebp+0x0]
    cmp    cx,ax
    jbe    Branch564
    push    ebp
    mov    ecx,esi
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch562
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch563
  Branch562:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch563
    mov    DWORD PTR [eax+0x8],ebp
  Branch563:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch564:
    jb    Branch565
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch565:
    push    edi
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    cmp    ebx,eax
    jne    Branch569
    cmp    edi,eax
    mov    ecx,esi
    push    ebp
    je    Branch566
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch568
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch568
  Branch566:
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch567
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch568
  Branch567:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch568
    mov    DWORD PTR [eax+0x8],ebp
  Branch568:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    eax,DWORD PTR [esi]
    add    eax,0x4
    push    eax
    push    ebp
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch569:
    mov    dx,WORD PTR [ebp+0x0]
    cmp    dx,WORD PTR [ebx+0x10]
    jae    Branch576
    mov    ecx,DWORD PTR [edi+0xc]
    push    ebp
    test    ecx,ecx
    mov    ecx,esi
    jne    Branch573
    cmp    edi,eax
    je    Branch570
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [edi+0xc],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,DWORD PTR [eax+0xc]
    jne    Branch572
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch572
  Branch570:
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [edi+0x8],ebp
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch571
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch572
  Branch571:
    cmp    edi,DWORD PTR [eax+0x8]
    jne    Branch572
    mov    DWORD PTR [eax+0x8],ebp
  Branch572:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [esi]
    add    edx,0x4
    push    edx
    push    ebp
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch573:
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    edi,eax
    mov    DWORD PTR [ebx+0x8],edi
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne    Branch574
    mov    DWORD PTR [eax+0x4],edi
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch575
  Branch574:
    cmp    ebx,DWORD PTR [eax+0x8]
    jne    Branch575
    mov    DWORD PTR [eax+0x8],edi
  Branch575:
    xor    eax,eax
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [esi]
    add    ecx,0x4
    push    ecx
    push    edi
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch576:
    mov    edi,DWORD PTR [eax+0x4]
    mov    ebx,eax
    test    edi,edi
    mov    cl,0x1
    je    Branch580
  Branch577:
    cmp    dx,WORD PTR [edi+0x10]
    mov    ebx,edi
    setb    cl
    test    cl,cl
    je    Branch578
    mov    edi,DWORD PTR [edi+0x8]
    jmp    Branch579
  Branch578:
    mov    edi,DWORD PTR [edi+0xc]
  Branch579:
    test    edi,edi
    jne    Branch577
  Branch580:
    mov    eax,ebx
    test    cl,cl
    mov    DWORD PTR [esp+0x14],eax
    je    Branch582
    lea    edx,[esp+0x20]
    mov    ecx,esi
    push    edx
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax]
    cmp    ecx,edx
    jne    Branch581
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x1c]
    push    eax
    push    0x0
    push    ebp
    push    ebx
    push    edi
    push    ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x1
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push    eax
    call    R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch581:
    push    ecx
    call    R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch582:
    mov    dx,WORD PTR [eax+0x10]
    cmp    dx,WORD PTR [ebp+0x0]
    jae    Branch583
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x18]
    push    eax
    push    0x0
    push    ebp
    push    ebx
    push    edi
    push    ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    lea    ecx,[esp+0x28]
    push    eax
    call    R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch583:
    lea    edx,[esp+0x13]
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x28]
    push    eax
    mov    BYTE PTR [esp+0x1b],0x0
    call    R6GameServiceAddresses::ConstructWordBytePair
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch584:
    cmp    edi,ebp
    jne    Branch586
    mov    ebp,DWORD PTR [ebp+0xc]
    mov    eax,DWORD PTR [esp+0x38]
    mov    ecx,esi
    mov    dx,WORD PTR [ebp+0x10]
    cmp    dx,WORD PTR [eax]
    jae    Branch585
    push    edi
    mov    edi,DWORD PTR [esp+0x34]
    push    eax
    push    ebp
    push    0x0
    push    edi
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch585:
    push    eax
    lea    eax,[esp+0x28]
    push    eax
    jmp    Branch594
  Branch586:
    push    edi
    call    R6GameServiceAddresses::OrderedTreePredecessor
    mov    ebp,DWORD PTR [esp+0x3c]
    add    esp,0x4
    mov    cx,WORD PTR [ebp+0x0]
    cmp    cx,WORD PTR [edi+0x10]
    setb    bl
    test    bl,bl
    je    Branch588
    cmp    WORD PTR [eax+0x10],cx
    jae    Branch588
    mov    ecx,DWORD PTR [eax+0xc]
    test    ecx,ecx
    mov    ecx,esi
    jne    Branch587
    mov    edi,DWORD PTR [esp+0x30]
    push    eax
    push    ebp
    push    eax
    push    0x0
    push    edi
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch587:
    push    0x0
    push    ebp
    push    edi
    push    edi
    mov    edi,DWORD PTR [esp+0x40]
    push    edi
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch588:
    push    edi
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    add    esp,0x4
    test    bl,bl
    sete    cl
    test    bl,bl
    jne    Branch591
    mov    dx,WORD PTR [ebp+0x0]
    cmp    WORD PTR [edi+0x10],dx
    setb    cl
    test    cl,cl
    je    Branch592
    cmp    eax,DWORD PTR [esi]
    je    Branch589
    cmp    dx,WORD PTR [eax+0x10]
    jae    Branch591
  Branch589:
    mov    ecx,DWORD PTR [edi+0xc]
    test    ecx,ecx
    mov    ecx,esi
    jne    Branch590
    push    edi
    push    ebp
    push    edi
    mov    edi,DWORD PTR [esp+0x3c]
    push    0x0
    push    edi
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch590:
    mov    edi,DWORD PTR [esp+0x30]
    push    0x0
    push    ebp
    push    eax
    push    eax
    push    edi
    call    R6GameServiceAddresses::InsertOrderedTreeNodeAtHint
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch591:
    cmp    bl,cl
    jne    Branch593
  Branch592:
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret    0xc
  Branch593:
    lea    edx,[esp+0x24]
    push    ebp
    push    edx
    mov    ecx,esi
  Branch594:
    call    R6GameServiceAddresses::FindOrInsertOrderedTreeNodeByU16Key
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    pop    ebx
    add    esp,0x1c
    ret    0xc
  }
}

// Capture head and descent key, walk unsigned lower bound, then reload final key and output argument.
// Store accepted node or original head and return output pointer; empty tree never reads key. RET8/no own guard.
// R6GameService.dll @ 10051fd0 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __thiscall FindOrderedTreeNodeByU16Key(void *tree,int *outputNode,ushort *key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx]
    push    edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    edx,ecx
    mov    eax,DWORD PTR [ecx+0x4]
    test    eax,eax
    je    Branch598
    push    esi
    mov    si,WORD PTR [edi]
  Branch595:
    cmp    WORD PTR [eax+0x10],si
    jb    Branch596
    mov    edx,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch597
  Branch596:
    mov    eax,DWORD PTR [eax+0xc]
  Branch597:
    test    eax,eax
    jne    Branch595
    pop    esi
  Branch598:
    cmp    edx,ecx
    je    Branch599
    mov    ax,WORD PTR [edi]
    cmp    ax,WORD PTR [edx+0x10]
    jae    Branch600
  Branch599:
    mov    eax,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR [eax],ecx
    ret    0x8
  Branch600:
    mov    eax,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR [eax],edx
    ret    0x8
  }
}

// Allocate60 bytes; unless allocation+10 wraps toNULL, reload source and copy44 payload bytes to+10. RET4.
// Preserve key WORD/ten forward DWORD/final WORD order, overlap effects and untouched links/color/padding. No guard.
// R6GameService.dll @ 10052040 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall AllocateTreeNodeWithCopiedPayload(const undefined2 *sourceKeyAndPayload)
{
  __asm {
    push    0x3c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x10]
    test    ecx,ecx
    je    Branch601
    mov    edx,DWORD PTR [esp+0x4]
    push    esi
    push    edi
    lea    edi,[ecx+0x2]
    mov    si,WORD PTR [edx]
    mov    WORD PTR [ecx],si
    lea    esi,[edx+0x2]
    mov    ecx,0xa
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    movs    WORD PTR es:[edi],WORD PTR ds:[esi]
    pop    edi
    pop    esi
  Branch601:
    ret    0x4
  }
}

// Link plain60-byte node at captured parent: head selects left/root; nonzero right mode overrides left mode.
// Otherwise use unsigned key comparison before allocation, then rebalance captured CURRENT root slot.
// Increment CURRENT count and store through late output argument; no own guard or hint validation. RET14/output.
// R6GameService.dll @ 10052070 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 * __thiscall InsertTreeNodeAndRebalance(
    void *tree,undefined4 *outputNode,int leftModeWord,int parentNode,ushort *payload,int rightModeWord)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    edi
    je    Branch603
    mov    ecx,DWORD PTR [esp+0x24]
    test    ecx,ecx
    jne    Branch602
    mov    ecx,DWORD PTR [esp+0x18]
    test    ecx,ecx
    jne    Branch603
    mov    cx,WORD PTR [eax]
    cmp    cx,WORD PTR [esi+0x10]
    jb    Branch603
  Branch602:
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch605
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch605
  Branch603:
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    jne    Branch604
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [ebx]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch605
  Branch604:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch605
    mov    DWORD PTR [eax+0x8],ebp
  Branch605:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [ebp+0x0],al
    add    edi,0x4
    mov    esi,ebp
    cmp    ebp,DWORD PTR [edi]
    je    Branch621
  Branch606:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch621
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch617
    mov    ecx,DWORD PTR [edx+0xc]
    test    ecx,ecx
    je    Branch608
    cmp    BYTE PTR [ecx],0x0
    jne    Branch608
  Branch607:
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch620
  Branch608:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch613
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch609
    mov    DWORD PTR [ecx+0x4],esi
  Branch609:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch610
    mov    DWORD PTR [edi],eax
    jmp    Branch612
  Branch610:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch611
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch612
  Branch611:
    mov    DWORD PTR [ecx+0xc],eax
  Branch612:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch613:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test    edx,edx
    je    Branch614
    mov    DWORD PTR [edx+0x4],eax
  Branch614:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch615
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch620
  Branch615:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch616
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch620
  Branch616:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch620
  Branch617:
    test    ecx,ecx
    je    Branch618
    cmp    BYTE PTR [ecx],0x0
    je    Branch607
  Branch618:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch619
    mov    esi,eax
    push    edi
    push    esi
    call    R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch619:
    mov    eax,DWORD PTR [esi+0x4]
    push    edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push    ecx
    call    R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch620:
    cmp    esi,DWORD PTR [edi]
    jne    Branch606
  Branch621:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    eax,DWORD PTR [ebx+0x4]
    inc    eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Construct extendedb4-byte node, then link/rebalance as the plain variant with the same full-word mode order.
// Retain captured parent, CURRENT header/root/count, late output and native inline rotation reloads. RET14/output.
// Child catches own construction failures before link publication; this method has no own guard.
// R6GameService.dll @ 10052240 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 * __thiscall InsertOrderedTreeNodeAtHint(
    void *tree,undefined4 *outputNode,int leftModeWord,int parentNode,ushort *payload,int rightModeWord)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    edi
    je    Branch623
    mov    ecx,DWORD PTR [esp+0x24]
    test    ecx,ecx
    jne    Branch622
    mov    ecx,DWORD PTR [esp+0x18]
    test    ecx,ecx
    jne    Branch623
    mov    cx,WORD PTR [eax]
    cmp    cx,WORD PTR [esi+0x10]
    jb    Branch623
  Branch622:
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch625
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch625
  Branch623:
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [ebx]
    cmp    esi,eax
    jne    Branch624
    mov    DWORD PTR [eax+0x4],ebp
    mov    edx,DWORD PTR [ebx]
    mov    DWORD PTR [edx+0xc],ebp
    jmp    Branch625
  Branch624:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch625
    mov    DWORD PTR [eax+0x8],ebp
  Branch625:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [ebp+0x0],al
    add    edi,0x4
    mov    esi,ebp
    cmp    ebp,DWORD PTR [edi]
    je    Branch641
  Branch626:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    BYTE PTR [eax],0x0
    jne    Branch641
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [edx+0x8]
    cmp    eax,ecx
    jne    Branch637
    mov    ecx,DWORD PTR [edx+0xc]
    test    ecx,ecx
    je    Branch628
    cmp    BYTE PTR [ecx],0x0
    jne    Branch628
  Branch627:
    mov    BYTE PTR [eax],0x1
    mov    BYTE PTR [ecx],0x1
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    BYTE PTR [ecx],0x0
    mov    edx,DWORD PTR [esi+0x4]
    mov    esi,DWORD PTR [edx+0x4]
    jmp    Branch640
  Branch628:
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch633
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch629
    mov    DWORD PTR [ecx+0x4],esi
  Branch629:
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    ecx,DWORD PTR [edi]
    cmp    esi,ecx
    jne    Branch630
    mov    DWORD PTR [edi],eax
    jmp    Branch632
  Branch630:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0x8]
    jne    Branch631
    mov    DWORD PTR [ecx+0x8],eax
    jmp    Branch632
  Branch631:
    mov    DWORD PTR [ecx+0xc],eax
  Branch632:
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [esi+0x4],eax
  Branch633:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0x8],edx
    mov    edx,DWORD PTR [ecx+0xc]
    test    edx,edx
    je    Branch634
    mov    DWORD PTR [edx+0x4],eax
  Branch634:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [edi]
    cmp    eax,edx
    jne    Branch635
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch640
  Branch635:
    mov    edx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [edx+0xc]
    jne    Branch636
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch640
  Branch636:
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch640
  Branch637:
    test    ecx,ecx
    je    Branch638
    cmp    BYTE PTR [ecx],0x0
    je    Branch627
  Branch638:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch639
    mov    esi,eax
    push    edi
    push    esi
    call    R6GameServiceAddresses::RotateOrderedTreeRight
    add    esp,0x8
  Branch639:
    mov    eax,DWORD PTR [esi+0x4]
    push    edi
    mov    BYTE PTR [eax],0x1
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax+0x4]
    push    ecx
    call    R6GameServiceAddresses::RotateOrderedTreeLeft
    add    esp,0x8
  Branch640:
    cmp    esi,DWORD PTR [edi]
    jne    Branch626
  Branch641:
    mov    edx,DWORD PTR [edi]
    pop    edi
    pop    esi
    mov    BYTE PTR [edx],0x1
    mov    eax,DWORD PTR [ebx+0x4]
    inc    eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],ebp
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Find unsigned U16 key or construct/link extended node and call actual generic RB repair; no own guard.
// Keep cached search key versus reloaded validation/payload key; write nodeDWORD/flagBYTE only, return output. RET8.
// R6GameService.dll @ 10052410 : complete native control/access order and raw ABI retained.
__declspec(naked) int * __thiscall FindOrInsertOrderedTreeNodeByU16Key(
    void *tree,int *outputPair,ushort *payload)
{
  __asm {
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,0x1
    mov    edx,DWORD PTR [edi]
    mov    esi,edx
    mov    ebp,DWORD PTR [edx+0x4]
    test    ebp,ebp
    je    Branch645
    mov    ax,WORD PTR [ebx]
  Branch642:
    cmp    ax,WORD PTR [ebp+0x10]
    mov    esi,ebp
    setb    cl
    test    cl,cl
    je    Branch643
    mov    ebp,DWORD PTR [ebp+0x8]
    jmp    Branch644
  Branch643:
    mov    ebp,DWORD PTR [ebp+0xc]
  Branch644:
    test    ebp,ebp
    jne    Branch642
  Branch645:
    test    cl,cl
    mov    eax,esi
    je    Branch650
    cmp    esi,DWORD PTR [edx+0x8]
    jne    Branch649
    cmp    esi,edx
    je    Branch646
    test    ebp,ebp
    jne    Branch646
    mov    ax,WORD PTR [ebx]
    cmp    ax,WORD PTR [esi+0x10]
    jb    Branch646
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch648
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch648
  Branch646:
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch647
    mov    DWORD PTR [eax+0x4],ebp
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [ecx+0xc],ebp
    jmp    Branch648
  Branch647:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch648
    mov    DWORD PTR [eax+0x8],ebp
  Branch648:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    edx,DWORD PTR [edi]
    add    edx,0x4
    push    edx
    push    ebp
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch649:
    push    esi
    call    R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
  Branch650:
    mov    cx,WORD PTR [ebx]
    cmp    WORD PTR [eax+0x10],cx
    jae    Branch654
    cmp    esi,DWORD PTR [edi]
    je    Branch651
    test    ebp,ebp
    jne    Branch651
    cmp    cx,WORD PTR [esi+0x10]
    jb    Branch651
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0xc],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch653
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch653
  Branch651:
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayload
    mov    ebp,eax
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    jne    Branch652
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],ebp
    jmp    Branch653
  Branch652:
    cmp    esi,DWORD PTR [eax+0x8]
    jne    Branch653
    mov    DWORD PTR [eax+0x8],ebp
  Branch653:
    xor    eax,eax
    mov    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [edi]
    add    ecx,0x4
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],ebp
    pop    ebp
    mov    BYTE PTR [eax+0x4],0x1
    pop    ebx
    ret    0x8
  Branch654:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ecx],eax
    mov    BYTE PTR [ecx+0x4],0x0
    mov    eax,ecx
    pop    ebx
    ret    0x8
  }
}

// Find unsigned U16 lower bound, then reload key for final validation; return accepted node or captured head.
// Cache the initial query only during descent; no header reload, normalization or own guard. RET4.
// R6GameService.dll @ 10052580 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ordered_tree_support_FindOrderedTreeNodeByU16Key(void *tree,const ushort *key)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push    edi
    mov    edi,DWORD PTR [esp+0x8]
    mov    edx,eax
    mov    ecx,DWORD PTR [eax+0x4]
    test    ecx,ecx
    je    Branch658
    push    esi
    mov    si,WORD PTR [edi]
  Branch655:
    cmp    WORD PTR [ecx+0x10],si
    jb    Branch656
    mov    edx,ecx
    mov    ecx,DWORD PTR [ecx+0x8]
    jmp    Branch657
  Branch656:
    mov    ecx,DWORD PTR [ecx+0xc]
  Branch657:
    test    ecx,ecx
    jne    Branch655
    pop    esi
  Branch658:
    cmp    edx,eax
    je    Branch659
    mov    cx,WORD PTR [edi]
    cmp    cx,WORD PTR [edx+0x10]
    jb    Branch659
    mov    eax,edx
  Branch659:
    pop    edi
    ret    0x4
  }
}

// Allocateb4 bytes, copy key and record fields with native gaps, construct treea0, then copy trailing WORDb0.
// EBP+8 becomes record destination+14; return CURRENT allocationEBP-14. Keep no-op guard/catch boundary. RET4.
// R6GameService.dll @ 100525c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall AllocateTreeNodeWithCopiedExtendedPayload(const void *sourceKeyAndRecord)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectExtendedNodeCopyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    mov    DWORD PTR [ebp-0x14],0x0
    mov    DWORD PTR [ebp-0x10],esp
    push    0xb4
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x10]
    mov    DWORD PTR [ebp-0x14],eax
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x18],ecx
    mov    DWORD PTR [ebp-0x1c],ecx
    test    ecx,ecx
    mov    BYTE PTR [ebp-0x4],0x1
    je    Branch660
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    ax,WORD PTR [ebx]
    add    ebx,0x4
    mov    WORD PTR [ecx],ax
    lea    eax,[ecx+0x4]
    mov    ecx,0x20
    mov    esi,ebx
    mov    edi,eax
    mov    DWORD PTR [ebp+0x8],eax
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    movs    BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    cx,WORD PTR [ebx+0x82]
    mov    WORD PTR [eax+0x82],cx
    mov    dl,BYTE PTR [ebx+0x84]
    mov    BYTE PTR [eax+0x84],dl
    mov    ecx,DWORD PTR [ebx+0x88]
    mov    DWORD PTR [eax+0x88],ecx
    lea    ecx,[eax+0x8c]
    lea    edx,[ebx+0x8c]
    push    edx
    mov    DWORD PTR [ecx+0xc],0x10077f84
    call    R6GameServiceAddresses::InitializeAndCloneEmbeddedTree
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    ax,WORD PTR [ebx+0x9c]
    mov    WORD PTR [ecx+0x9c],ax
    mov    eax,DWORD PTR [ebp-0x14]
  Branch660:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Free CURRENT saved allocationEBP-14, then rethrow(0,0); no embedded-tree destruction or normal return.
// R6GameService.dll @ 10052691 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ordered_tree_support_ordered_tree_supportCatch2(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x14]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    0x0
    push    0x0
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// Allocate head before loading source argument; copy cookie, clone colors/payload/links, then copy CURRENT count.
// Shared state0 guard frees CURRENT head only after child catch; no rollback of published owner fields. RET4/receiver.
// R6GameService.dll @ 100526b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeAndCloneEmbeddedTree(void *destination,int *source)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTreeDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebp
    push    esi
    mov    esi,ecx
    push    0x3c
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esi],0x0
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esp+0x14],0x0
    mov    cl,BYTE PTR [ebp+0x8]
    mov    BYTE PTR [esi+0x8],cl
    mov    edx,DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    BYTE PTR [eax],0x0
    test    ecx,ecx
    jne    Branch661
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    jmp    Branch666
  Branch661:
    mov    ecx,DWORD PTR [ebp+0x0]
    push    edi
    mov    edi,DWORD PTR [esi]
    mov    edx,DWORD PTR [ecx+0x4]
    push    edi
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CloneOrderedTreeSubtree
    mov    DWORD PTR [edi+0x4],eax
    mov    edx,DWORD PTR [esi]
    pop    edi
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch663
  Branch662:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch662
  Branch663:
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    je    Branch665
  Branch664:
    mov    ecx,eax
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    jne    Branch664
  Branch665:
    mov    DWORD PTR [edx+0xc],ecx
  Branch666:
    mov    eax,DWORD PTR [ebp+0x4]
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Load/push both CURRENT inherited wordsEBP-18/-1c, call genuine no-op, discard8 stack bytes; free nothing.
// R6GameService.dll @ 10068c10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AllocateTreeNodeWithCopiedExtendedPayloadUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push    eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push    ecx
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Select two NULL unwind actions and state0 catch-all record for partial subtree release/rethrow.
// R6GameService.dll @ 10068c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTreeCloneCatchEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CloneOrderedTreeSubtreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 1008363c : native storage identity retained.
const R6GameServiceNative::UnwindEntry CloneOrderedTreeSubtreeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 1008364c : native storage identity retained.
const R6GameServiceNative::CatchHandler ordered_tree_supportGRecordTreeCopyEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ordered_tree_support_ordered_tree_supportCatch},
};

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 1008364c : native storage identity retained.
const R6GameServiceNative::TryBlock CloneOrderedTreeSubtreeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::ordered_tree_supportGRecordTreeCopyEH},
};

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 1008363c : native storage identity retained.
const R6GameServiceNative::FuncInfo CloneOrderedTreeSubtreeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::CloneOrderedTreeSubtreeUnwindMap,
  0x1,
  R6GameServiceAddresses::CloneOrderedTreeSubtreeTryMap,
  0x0,
  0x0,
};

// Select exact three-state no-op/catch-all construction FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10068c21 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectExtendedNodeCopyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayloadExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native extended-node cleanup/catch metadata.
// R6GameService.dll data @ 1008368c : native storage identity retained.
const R6GameServiceNative::UnwindEntry AllocateTreeNodeWithCopiedExtendedPayloadUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayloadUnwind2},
  {-1, 0x0},
};

// Literal native extended-node cleanup/catch metadata.
// R6GameService.dll data @ 100836a4 : native storage identity retained.
const R6GameServiceNative::CatchHandler ordered_tree_supportGExtendedNodeCopyEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ordered_tree_support_ordered_tree_supportCatch2},
};

// Literal native extended-node cleanup/catch metadata.
// R6GameService.dll data @ 100836a4 : native storage identity retained.
const R6GameServiceNative::TryBlock AllocateTreeNodeWithCopiedExtendedPayloadTryMap[1] = {
  {0x0, 0x1, 0x2, 0x1, R6GameServiceAddresses::ordered_tree_supportGExtendedNodeCopyEH},
};

// Literal native extended-node cleanup/catch metadata.
// R6GameService.dll data @ 1008368c : native storage identity retained.
const R6GameServiceNative::FuncInfo AllocateTreeNodeWithCopiedExtendedPayloadExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayloadUnwindMap,
  0x1,
  R6GameServiceAddresses::AllocateTreeNodeWithCopiedExtendedPayloadTryMap,
  0x0,
  0x0,
};
