#include "native_addresses.h"

// Inferred native storage views; original list/node class names and padding are unavailable.
struct NativeModuleVersionNode {
  NativeModuleVersionNode *next; // +0
  char moduleName[32]; // +4; append writes 31 bytes, leaving the final byte untouched.
  uint version; // +0x24
};
struct NativeModuleVersionList {
  NativeModuleVersionNode *head; // +0
  NativeModuleVersionNode *tail; // +4
  byte count; // +8, wraps; trailing padding is untouched.
};

// Recursively deletes successors, clears the cached receiver link and optionally frees it using late flag bit0.
// R6GameService.dll @ 10005fc0 : complete native control/access order and raw ABI retained.
__declspec(naked) NativeModuleVersionNode * __thiscall DeleteModuleVersionChain
    (NativeModuleVersionNode *node,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    test   ecx,ecx
    je     Branch1
    push   0x1
    call   R6GameServiceAddresses::DeleteModuleVersionChain
  Branch1:
    test   BYTE PTR [esp+0x8],0x1
    mov    DWORD PTR [esi],0x0
    je     Branch2
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Recursively frees the cached head chain and clears head/tail; preserves the byte count.
// R6GameService.dll @ 10005ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ClearModuleVersionList(NativeModuleVersionList *list)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi]
    test   esi,esi
    je     Branch4
    mov    ecx,DWORD PTR [esi]
    test   ecx,ecx
    je     Branch3
    push   0x1
    call   R6GameServiceAddresses::DeleteModuleVersionChain
  Branch3:
    mov    DWORD PTR [esi],0x0
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch4:
    mov    DWORD PTR [edi+0x4],0x0
    mov    DWORD PTR [edi],0x0
    pop    edi
    pop    esi
    ret
  }
}

// Appends a 40-byte node with 31 name bytes; even null allocation increments count and publishes the null node.
// R6GameService.dll @ 10006030 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall AppendModuleVersion
    (NativeModuleVersionList *list,const char *name,uint version)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x28
    call   DWORD PTR [edx]
    mov    esi,eax
    test   esi,esi
    je     Branch5
    mov    eax,DWORD PTR [esp+0xc]
    push   0x1f
    push   eax
    lea    ecx,[esi+0x4]
    push   ecx
    mov    DWORD PTR [esi],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strncpySlot
    mov    edx,DWORD PTR [esp+0x1c]
    add    esp,0xc
    mov    DWORD PTR [esi+0x24],edx
    jmp    Branch6
  Branch5:
    xor    esi,esi
  Branch6:
    mov    cl,BYTE PTR [edi+0x8]
    mov    eax,DWORD PTR [edi]
    inc    cl
    test   eax,eax
    mov    BYTE PTR [edi+0x8],cl
    jne    Branch7
    mov    DWORD PTR [edi],esi
    mov    DWORD PTR [edi+0x4],esi
    pop    edi
    pop    esi
    ret    0x8
  Branch7:
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [edi+0x4],esi
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Prints, writes an unchecked report, or reports 70*byteCount+150 bytes; sets only AL to 1 on normal return.
// R6GameService.dll @ 100060a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FormatModuleVersionList
    (NativeModuleVersionList *list,char *output,uint *size)
{
  __asm {
    sub    esp,0x48
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x58]
    test   edi,edi
    mov    esi,ecx
    mov    ebp,DWORD PTR [esi]
    jne    Branch11
    mov    eax,DWORD PTR [esp+0x5c]
    test   eax,eax
    jne    Branch21
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCR71_printfSlot
    push   R6GameServiceAddresses::TextBeginModuleVersionOutput2
    call   edi
    mov    al,BYTE PTR [esi+0x8]
    add    esp,0x4
    test   al,al
    jne    Branch8
    push   R6GameServiceAddresses::TextNoLinkedGsLibrary
    call   edi
    add    esp,0x4
    push   R6GameServiceAddresses::TextEndModuleVersionOutput2
    call   edi
    add    esp,0x4
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x48
    ret    0x8
  Branch8:
    test   ebp,ebp
    je     Branch10
  Branch9:
    mov    eax,DWORD PTR [ebp+0x24]
    push   eax
    lea    ecx,[ebp+0x4]
    push   ecx
    push   R6GameServiceAddresses::TextLibrarySVersionD
    call   edi
    mov    ebp,DWORD PTR [ebp+0x0]
    add    esp,0xc
    test   ebp,ebp
    jne    Branch9
  Branch10:
    push   R6GameServiceAddresses::TextEndModuleVersionOutput2
    call   edi
    add    esp,0x4
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x48
    ret    0x8
  Branch11:
    mov    eax,DWORD PTR [esp+0x5c]
    test   eax,eax
    je     Branch22
    push   R6GameServiceAddresses::TextBeginModuleVersionOutput
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_sprintfSlot
    mov    al,BYTE PTR [esi+0x8]
    add    esp,0x8
    test   al,al
    jne    Branch13
    dec    edi
    lea    esp,[esp+0x0]
  Branch12:
    mov    al,BYTE PTR [edi+0x1]
    inc    edi
    test   al,al
    jne    Branch12
    mov    ecx,0x7
    mov    esi,R6GameServiceAddresses::TextNoLinkedGsLibrary
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    jmp    Branch18
  Branch13:
    test   ebp,ebp
    je     Branch19
    jmp    Branch15
  Branch14:
    mov    edi,DWORD PTR [esp+0x58]
  Branch15:
    mov    edx,DWORD PTR [ebp+0x24]
    push   edx
    lea    eax,[ebp+0x4]
    push   eax
    push   R6GameServiceAddresses::TextLibrarySVersionD
    lea    ecx,[esp+0x18]
    push   0x46
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__snprintfSlot
    lea    eax,[esp+0x20]
    add    esp,0x14
    mov    BYTE PTR [esp+0x51],0x0
    mov    ecx,eax
  Branch16:
    mov    dl,BYTE PTR [eax]
    inc    eax
    test   dl,dl
    jne    Branch16
    sub    eax,ecx
    mov    esi,ecx
    dec    edi
  Branch17:
    mov    cl,BYTE PTR [edi+0x1]
    inc    edi
    test   cl,cl
    jne    Branch17
    mov    ecx,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ebp,DWORD PTR [ebp+0x0]
    test   ebp,ebp
    jne    Branch14
  Branch18:
    mov    edi,DWORD PTR [esp+0x58]
  Branch19:
    dec    edi
  Branch20:
    mov    al,BYTE PTR [edi+0x1]
    inc    edi
    test   al,al
    jne    Branch20
    mov    ecx,0x9
    mov    esi,R6GameServiceAddresses::TextEndModuleVersionOutput
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    movs   WORD PTR es:[edi],WORD PTR ds:[esi]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x48
    ret    0x8
  Branch21:
    movzx  edx,BYTE PTR [esi+0x8]
    imul   edx,edx,0x46
    add    edx,0x96
    mov    DWORD PTR [eax],edx
  Branch22:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x48
    ret    0x8
  }
}

// Clears list head/tail/count and appends twelve fixed UBI.com GS module/version records in native order.
// R6GameService.dll @ 10009320 : complete native control/access order and raw ABI retained.
__declspec(naked) NativeModuleVersionList * __thiscall InitializeGSModuleVersions
    (NativeModuleVersionList *list)
{
  __asm {
    push   esi
    mov    esi,ecx
    xor    eax,eax
    push   0x5b0
    push   R6GameServiceAddresses::TextLibgsclient // libgsclient
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    BYTE PTR [esi+0x8],al
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x597
    push   R6GameServiceAddresses::TextLibgsmsclient // libgsmsclient
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x587
    push   R6GameServiceAddresses::TextLibgsregserver // libgsregserver
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5ad
    push   R6GameServiceAddresses::TextLibgsconnect // libgsconnect
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5ad
    push   R6GameServiceAddresses::TextLibgsproxyclient // libgsproxyclient
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5ac
    push   R6GameServiceAddresses::TextLibgsresult // libgsresult
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5b0
    push   R6GameServiceAddresses::TextLibgssocket // libgssocket
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x567
    push   R6GameServiceAddresses::TextLibgsutility // libgsutility
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5b2
    push   R6GameServiceAddresses::TextLibgscsp // libgscsp
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x5b8
    push   R6GameServiceAddresses::TextLibgsdatacontainer // libgsdatacontainer
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x58f
    push   R6GameServiceAddresses::TextLibgscrypto // libgscrypto
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    push   0x575
    push   R6GameServiceAddresses::TextLibgscdkey // libgscdkey
    mov    ecx,esi
    call   R6GameServiceAddresses::AppendModuleVersion
    mov    eax,esi
    pop    esi
    ret
  }
}
