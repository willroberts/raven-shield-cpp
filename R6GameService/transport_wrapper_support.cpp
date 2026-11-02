#include "native_addresses.h"
#include "native_records.h"

// Unassigned transport-wrapper entries; offset table76d6c=[0,98] does not establish class identity.
// Nonvirtual names and parameter roles are descriptive; raw entry views retain complete native operations.

// Optionally install offset table, clear provider4, copy live default text to10 through NUL, then clear94/8/c.
// No length guard; gaps remain. RET4/owner EAX/current zero-initialized scratch ECX; no own EH.
// R6GameService.dll @ 10032030 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeTransportState(void *transport,uint initializeBase)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je     Branch1
    mov    DWORD PTR [eax],0x10076d6c
  Branch1:
    push   ebx
    push   esi
    mov    edx,R6GameServiceAddresses::GRegistrationEmptyText
    lea    esi,[eax+0x10]
    mov    DWORD PTR [eax+0x4],ecx
    sub    esi,edx
  Branch2:
    mov    bl,BYTE PTR [edx]
    mov    BYTE PTR [esi+edx*1],bl
    inc    edx
    cmp    bl,cl
    jne    Branch2
    pop    esi
    mov    DWORD PTR [eax+0x94],ecx
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Close old provider before clearing4; allocate68, construct571c0(22,word4,4,word3,b4,0,0,1), publish4.
// Open slot4(late address/port,0), strict AL1 success; forward unbounded address copy, late8/c and masked port94.
// RET24/stateWord0 upper|Boolean AL. Shared state0 frees current staged block at entryESP-10; no rollback.
// R6GameService.dll @ 10032080 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectAddressTransport(
    void *transport,const char *address,uint port,uint optionWord0,uint optionWord1,uint stateWord0,uint stateWord1)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTransportAllocationEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    xor    esi,esi
    mov    ecx,DWORD PTR [edi+0x4]
    cmp    ecx,esi
    je     Branch3
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [edi+0x4],esi
  Branch3:
    push   0x68
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,esi
    mov    DWORD PTR [esp+0x1c],esi
    je     Branch4
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esp+0x30]
    push   0x1
    push   esi
    push   esi
    push   0xb4
    push   ecx
    push   0x4
    push   edx
    push   0x22
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeTransportRecord
    jmp    Branch5
  Branch4:
    xor    eax,eax
  Branch5:
    mov    ebp,DWORD PTR [esp+0x28]
    push   esi
    mov    esi,DWORD PTR [esp+0x28]
    mov    DWORD PTR [edi+0x4],eax
    mov    edx,DWORD PTR [eax]
    push   ebp
    push   esi
    mov    ecx,eax
    mov    DWORD PTR [esp+0x28],0xffffffff
    call   DWORD PTR [edx+0x4]
    cmp    al,0x1
    lea    edx,[edi+0x10]
    sete   bl
    mov    ecx,esi
    sub    edx,esi
  Branch6:
    mov    al,BYTE PTR [ecx]
    mov    BYTE PTR [edx+ecx*1],al
    inc    ecx
    test   al,al
    jne    Branch6
    mov    eax,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [esp+0x38]
    and    ebp,0xffff
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0x94],ebp
    mov    DWORD PTR [edi+0xc],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    al,bl
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x18
  }
}

// If provider exists, update57980 and replace only AL with strict status==1; absent provider only clears AL.
// R6GameService.dll @ 10032150 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall IsTransportConnected(void *transport)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x4]
    test   ecx,ecx
    je     Branch7
    call   R6GameServiceAddresses::UpdateTransportProvider
    cmp    al,0x1
    sete   al
    ret
  Branch7:
    xor    al,al
    ret
  }
}

// Existing provider/nonNULL payload forwards full words(opcode,4,mode,payload), raw helper EAX/RET12.
// Missing provider clears incoming AL; NULL payload returns full0. No own guard or payload release.
// R6GameService.dll @ 10032170 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendTransportPayload(
    void *transport,uint opcodeWord,uint modeWord,const void *payload)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x4]
    test   ecx,ecx
    je     Branch8
    mov    eax,DWORD PTR [esp+0xc]
    test   eax,eax
    je     Branch8
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   eax
    push   0x4
    push   edx
    call   R6GameServiceAddresses::QueueCopiedTransportRecord
    ret    0xc
  Branch8:
    xor    al,al
    ret    0xc
  }
}

// Additional provider byte50 gate before full-word dispatch; preserve raw helper EAX/RET12.
// Missing provider clears incoming AL; NULL payload full0; disabled byte50 returns payload upper with AL0.
// R6GameService.dll @ 100321a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendConnectedTransportPayload(
    void *transport,uint opcodeWord,uint modeWord,const void *payload)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x4]
    test   ecx,ecx
    je     Branch9
    mov    eax,DWORD PTR [esp+0xc]
    test   eax,eax
    je     Branch9
    mov    dl,BYTE PTR [ecx+0x50]
    test   dl,dl
    je     Branch9
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   eax
    push   0x4
    push   edx
    call   R6GameServiceAddresses::QueueKind2TransportRecordWhenEnabled
    ret    0xc
  Branch9:
    xor    al,al
    ret    0xc
  }
}

// Tail peer-endpoint query on current provider4; preserve caller output argument/raw return with no NULL repair.
// R6GameService.dll @ 100321d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueryProviderPeerEndpoint(void *transport,char *addressTextOut)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x4]
    jmp    R6GameServiceAddresses::QueryPeerEndpointAndPort
  }
}

// Pop one message, allocate1c, clone wrapper from late message14/byteD and current transport8/context.
// Physical kind word keeps context upper bytes. Release message even on NULL allocation; RET0/wrapper EAX.
// State0 arms after allocation, lowers before message release; failures free staged raw block only, no message retry.
// R6GameService.dll @ 100321e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall TakeNextTransportMessage(void *transport)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTransportAllocationEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x4]
    test   ecx,ecx
    je     Branch12
    call   R6GameServiceAddresses::PopAndDispatchControlRecord
    mov    esi,eax
    test   esi,esi
    je     Branch12
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x8],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je     Branch10
    mov    edx,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR [esi+0x14]
    push   0x1
    push   edx
    mov    dl,BYTE PTR [esi+0xd]
    push   ecx
    push   edx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructClonedPayloadWrapper
    mov    edi,eax
    jmp    Branch11
  Branch10:
    xor    edi,edi
  Branch11:
    mov    eax,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR [eax]
    mov    eax,edi
    pop    edi
    pop    esi
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  Branch12:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    xor    eax,eax
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Shared connect/message state0 action frees CURRENT raw block[parent entryESP-10] via current allocator.
// R6GameService.dll @ 10066350 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl UnwindTransportAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select shared one-state staged-allocation map and tail CRT dispatch; no object/message destruction.
// R6GameService.dll @ 1006635a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportAllocationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_wrapper_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Shared native staged-allocation unwind; state0->-1 calls66350.
// R6GameService.dll data @ 100806b4 : shared transport staged-allocation metadata.
const R6GameServiceNative::UnwindEntry transport_wrapper_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindTransportAllocation},
};

// Shared native staged-allocation info; state0->-1 calls66350.
// R6GameService.dll data @ 100806bc : shared transport staged-allocation metadata.
// R6GameService.dll data @ 100806b4 : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_wrapper_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::transport_wrapper_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Query through provider14, using original caller argument slot as WORD port output; socketNULL only clears AL.
// Actual clTCPProtocol2e950 forces AL1; preserve current raw upper result and RET4/output-slot alias.
// R6GameService.dll @ 100583b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueryPeerEndpointAndPort(void *provider,char *addressTextOut)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    test   ecx,ecx
    je     Branch13
    mov    edx,DWORD PTR [esp+0x4]
    lea    eax,[esp+0x4]
    push   eax
    push   edx
    call   R6GameServiceAddresses::QueryPeerEndpointAlwaysSuccess
    ret    0x4
  Branch13:
    xor    al,al
    ret    0x4
  }
}
