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
// R6GameService.dll @ 10005fc0 : RET4; node and flag slot retain their native lifetimes.
__declspec(naked) NativeModuleVersionNode * __thiscall DeleteModuleVersionChain
    (NativeModuleVersionNode *node,uint flags)
{
  NativeModuleVersionNode *receiver,*next;
  byte *nativeStack;
  __asm {
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    mov    receiver,esi
    mov    next,ecx
    mov    nativeStack,esp
  }
  using DeleteABI = NativeModuleVersionNode * (__thiscall *)(NativeModuleVersionNode *,uint);
  if (next != nullptr) ((DeleteABI)R6GameServiceAddresses::DeleteModuleVersionChain)(next,1);
  bool release = (*(byte *)(nativeStack + 8) & 1) != 0;
  receiver->next = nullptr;
  if (release) {
    void *allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
    byte *table = *(byte **)allocator;
    (*(uint (__thiscall **)(void *,void *))(table + 8))(allocator,receiver);
  }
  __asm {
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Recursively frees the cached head chain and clears head/tail; preserves the byte count.
// R6GameService.dll @ 10005ff0 : RET0; normal return keeps the last free result or incoming EAX for an empty list.
__declspec(naked) void __thiscall ClearModuleVersionList(NativeModuleVersionList *list)
{
  NativeModuleVersionList *receiver;
  NativeModuleVersionNode *head;
  uint rawEax;
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi]
    mov    receiver,edi
    mov    head,esi
    mov    rawEax,eax
  }
  if (head != nullptr) {
    NativeModuleVersionNode *next = head->next;
    using DeleteABI = NativeModuleVersionNode * (__thiscall *)(NativeModuleVersionNode *,uint);
    if (next != nullptr) ((DeleteABI)R6GameServiceAddresses::DeleteModuleVersionChain)(next,1);
    head->next = nullptr;
    void *allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
    byte *table = *(byte **)allocator;
    rawEax = (*(uint (__thiscall **)(void *,void *))(table + 8))(allocator,head);
  }
  receiver->tail = nullptr;
  receiver->head = nullptr;
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    ret
  }
}

// Appends a 40-byte node with 31 name bytes; even null allocation increments count and publishes the null node.
// R6GameService.dll @ 10006030 : RET8; allocation failure still increments count and publishes null.
__declspec(naked) void __thiscall AppendModuleVersion
    (NativeModuleVersionList *list,const char *name,uint version)
{
  NativeModuleVersionList *receiver;
  NativeModuleVersionNode *node;
  byte *nativeStack;
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
    mov    receiver,edi
    mov    node,esi
    mov    nativeStack,esp
  }
  if (node != nullptr) {
    const char *currentName = *(const char **)(nativeStack + 0xc);
    node->next = nullptr;
    using CopyABI = char * (__cdecl *)(char *,const char *,uint);
    (*(CopyABI *)R6GameServiceAddresses::MSVCR71_strncpySlot)(node->moduleName,currentName,31);
    node->version = *(uint *)(nativeStack + 0x10);
  }
  byte count = receiver->count;
  NativeModuleVersionNode *head = receiver->head;
  receiver->count = (byte)(count + 1);
  uint rawEax = (uint)head;
  if (head == nullptr) {
    receiver->head = node;
    receiver->tail = node;
  } else {
    NativeModuleVersionNode *tail = receiver->tail;
    rawEax = (uint)tail;
    tail->next = node;
    receiver->tail = node;
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Prints, writes an unchecked report, or reports 70*byteCount+150 bytes; sets only AL to 1 on normal return.
// R6GameService.dll @ 100060a0 : RET8; inherited DF and overlapping DWORD/remainder copies stay explicit.
__declspec(naked) uint __thiscall FormatModuleVersionList
    (NativeModuleVersionList *list,char *output,uint *size)
{
  byte *nativeStack;
  NativeModuleVersionList *receiver;
  NativeModuleVersionNode *node;
  char *destination;
  __asm {
    sub    esp,0x48
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x58]
    test   edi,edi
    mov    esi,ecx
    mov    ebp,DWORD PTR [esi]
    mov    nativeStack,esp
    mov    receiver,esi
    mov    node,ebp
    mov    destination,edi
  }
  uint *currentSize = *(uint **)(nativeStack + 0x5c);
  uint rawEax = (uint)currentSize;
  if (destination == nullptr) {
    if (currentSize != nullptr) {
      uint count = receiver->count;
      *currentSize = count * 70 + 150;
    } else {
      using PrintABI = uint (__cdecl *)(const char *,...);
      PrintABI print = *(PrintABI *)R6GameServiceAddresses::MSVCR71_printfSlot;
      rawEax = print((const char *)R6GameServiceAddresses::TextBeginModuleVersionOutput2);
      byte count = receiver->count;
      rawEax = (rawEax & 0xffffff00) | count;
      if (count == 0) rawEax = print((const char *)R6GameServiceAddresses::TextNoLinkedGsLibrary);
      else {
        while (node != nullptr) {
          uint version = node->version;
          rawEax = print((const char *)R6GameServiceAddresses::TextLibrarySVersionD,node->moduleName,version);
          node = node->next;
        }
      }
      rawEax = print((const char *)R6GameServiceAddresses::TextEndModuleVersionOutput2);
    }
  } else if (currentSize != nullptr) {
    using FormatABI = uint (__cdecl *)(char *,const char *,...);
    rawEax = (*(FormatABI *)R6GameServiceAddresses::MSVCR71_sprintfSlot)
        (destination,(const char *)R6GameServiceAddresses::TextBeginModuleVersionOutput);
    byte count = receiver->count;
    rawEax = (rawEax & 0xffffff00) | count;
    if (count == 0) {
      byte value;
      do { value = *(byte *)destination++; } while (value != 0);
      --destination;
      rawEax &= 0xffffff00;
      __asm {
        mov    edi,destination
        mov    ecx,0x7
        mov    esi,R6GameServiceAddresses::TextNoLinkedGsLibrary
        rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
      }
      destination = *(char **)(nativeStack + 0x58);
    } else {
      char *row = (char *)(nativeStack + 0xc);
      while (node != nullptr) {
        uint version = node->version;
        using RowABI = int (__cdecl *)(char *,uint,const char *,...);
        (*(RowABI *)R6GameServiceAddresses::MSVCR71__snprintfSlot)
            (row,70,(const char *)R6GameServiceAddresses::TextLibrarySVersionD,node->moduleName,version);
        *(byte *)(nativeStack + 0x51) = 0;
        char *end = row;
        byte value;
        do { value = *(byte *)end++; } while (value != 0);
        rawEax = (uint)(end - row);
        do { value = *(byte *)destination++; } while (value != 0);
        --destination;
        // Copy includes the terminator, with the original DWORD-first overlap and inherited direction flag.
        __asm {
          mov    edi,destination
          mov    esi,row
          mov    eax,rawEax
          mov    ecx,eax
          shr    ecx,0x2
          rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
          mov    ecx,eax
          and    ecx,0x3
          rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
        }
        node = node->next;
        destination = *(char **)(nativeStack + 0x58);
      }
    }
    byte value;
    do { value = *(byte *)destination++; } while (value != 0);
    --destination;
    rawEax &= 0xffffff00;
    __asm {
      mov    edi,destination
      mov    ecx,0x9
      mov    esi,R6GameServiceAddresses::TextEndModuleVersionOutput
      rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
      movs   WORD PTR es:[edi],WORD PTR ds:[esi]
    }
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x48
    ret    0x8
  }
}

// Clears list head/tail/count and appends twelve fixed UBI.com GS module/version records in native order.
// R6GameService.dll @ 10009320 : RET0; initial stores preserve padding and do not destroy a previous chain.
__declspec(naked) NativeModuleVersionList * __thiscall InitializeGSModuleVersions
    (NativeModuleVersionList *list)
{
  NativeModuleVersionList *receiver;
  __asm {
    push   esi
    mov    esi,ecx
    xor    eax,eax
    mov    receiver,esi
  }
  receiver->tail = nullptr;
  receiver->head = nullptr;
  receiver->count = 0;
  using AppendABI = void (__thiscall *)(NativeModuleVersionList *,const char *,uint);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsclient,0x5b0);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsmsclient,0x597);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsregserver,0x587);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsconnect,0x5ad);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsproxyclient,0x5ad);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsresult,0x5ac);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgssocket,0x5b0);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsutility,0x567);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgscsp,0x5b2);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgsdatacontainer,0x5b8);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgscrypto,0x58f);
  ((AppendABI)R6GameServiceAddresses::AppendModuleVersion)(receiver,
      (const char *)R6GameServiceAddresses::TextLibgscdkey,0x575);
  __asm {
    mov    eax,esi
    pop    esi
    ret
  }
}
