#include "native_addresses.h"

// Shared deflate Huffman construction. Helper/field/type spellings are descriptive inferences.
// Preserve native frequency/depth widths, heap ordering, length redistribution, frame operands and raw stdcall ABI.

// Extra bit widths indexed by the corresponding symbol range.
// R6GameService.dll data @ 10075d50 : selected 29 uint32 entries.
static const uint DeflateLengthExtraBits[29] = {
  0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
  5, 5, 5, 5, 0,
};

// Extra bit widths indexed by the corresponding symbol range.
// R6GameService.dll data @ 10075dc8 : selected 30 uint32 entries.
static const uint DeflateDistanceExtraBits[30] = {
  0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
  5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10,
  11, 11, 12, 12, 13, 13,
};

// Extra bit widths indexed by the corresponding symbol range.
// R6GameService.dll data @ 10075e40 : selected 19 uint32 entries.
static const uint DeflateBitLengthExtraBits[19] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 2, 3, 7,
};

// Bit-length symbols in native header order.
// R6GameService.dll data @ 10075e8c : selected 19-byte order.
static const byte DeflateBitLengthOrder[19] = {
  16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15
};

// Static tree, extra-bit table, base symbol, element count and maximum bit length; source type is inferred.
struct DeflateStaticTreeDescriptorRecord { uint tree, extraBits, extraBase, elements, maxLength; };

// Shared native tree descriptor.
// R6GameService.dll data @ 1008c8cc : five uint32 fields.
static const DeflateStaticTreeDescriptorRecord DeflateLiteralTreeDescriptor = {
  R6GameServiceAddresses::DeflateFixedLiteralCodes, R6GameServiceAddresses::DeflateLengthExtraBits, 257, 286, 15
};

// Shared native tree descriptor.
// R6GameService.dll data @ 1008c8e0 : five uint32 fields.
static const DeflateStaticTreeDescriptorRecord DeflateDistanceTreeDescriptor = {
  R6GameServiceAddresses::DeflateFixedDistanceCodes, R6GameServiceAddresses::DeflateDistanceExtraBits, 0, 30, 15
};

// Shared native tree descriptor.
// R6GameService.dll data @ 1008c8f4 : five uint32 fields.
// R6GameService.dll data @ 10075e40 : native storage identity retained.
static const DeflateStaticTreeDescriptorRecord DeflateBitLengthTreeDescriptor = { 0, R6GameServiceAddresses::DeflateBitLengthExtraBits, 0, 19, 7 };

// Code/frequency and length share native four-byte nodes; field names describe these static records.
struct DeflateStaticCodeRecord { ushort code, length; };

// Fixed canonical codes already reversed for low-bit-first emission.
// R6GameService.dll data @ 10075ea0 : 288 selected four-byte nodes.
static const DeflateStaticCodeRecord DeflateFixedLiteralCodes[288] = {
  {12, 8}, {140, 8}, {76, 8}, {204, 8}, {44, 8}, {172, 8},
  {108, 8}, {236, 8}, {28, 8}, {156, 8}, {92, 8}, {220, 8},
  {60, 8}, {188, 8}, {124, 8}, {252, 8}, {2, 8}, {130, 8},
  {66, 8}, {194, 8}, {34, 8}, {162, 8}, {98, 8}, {226, 8},
  {18, 8}, {146, 8}, {82, 8}, {210, 8}, {50, 8}, {178, 8},
  {114, 8}, {242, 8}, {10, 8}, {138, 8}, {74, 8}, {202, 8},
  {42, 8}, {170, 8}, {106, 8}, {234, 8}, {26, 8}, {154, 8},
  {90, 8}, {218, 8}, {58, 8}, {186, 8}, {122, 8}, {250, 8},
  {6, 8}, {134, 8}, {70, 8}, {198, 8}, {38, 8}, {166, 8},
  {102, 8}, {230, 8}, {22, 8}, {150, 8}, {86, 8}, {214, 8},
  {54, 8}, {182, 8}, {118, 8}, {246, 8}, {14, 8}, {142, 8},
  {78, 8}, {206, 8}, {46, 8}, {174, 8}, {110, 8}, {238, 8},
  {30, 8}, {158, 8}, {94, 8}, {222, 8}, {62, 8}, {190, 8},
  {126, 8}, {254, 8}, {1, 8}, {129, 8}, {65, 8}, {193, 8},
  {33, 8}, {161, 8}, {97, 8}, {225, 8}, {17, 8}, {145, 8},
  {81, 8}, {209, 8}, {49, 8}, {177, 8}, {113, 8}, {241, 8},
  {9, 8}, {137, 8}, {73, 8}, {201, 8}, {41, 8}, {169, 8},
  {105, 8}, {233, 8}, {25, 8}, {153, 8}, {89, 8}, {217, 8},
  {57, 8}, {185, 8}, {121, 8}, {249, 8}, {5, 8}, {133, 8},
  {69, 8}, {197, 8}, {37, 8}, {165, 8}, {101, 8}, {229, 8},
  {21, 8}, {149, 8}, {85, 8}, {213, 8}, {53, 8}, {181, 8},
  {117, 8}, {245, 8}, {13, 8}, {141, 8}, {77, 8}, {205, 8},
  {45, 8}, {173, 8}, {109, 8}, {237, 8}, {29, 8}, {157, 8},
  {93, 8}, {221, 8}, {61, 8}, {189, 8}, {125, 8}, {253, 8},
  {19, 9}, {275, 9}, {147, 9}, {403, 9}, {83, 9}, {339, 9},
  {211, 9}, {467, 9}, {51, 9}, {307, 9}, {179, 9}, {435, 9},
  {115, 9}, {371, 9}, {243, 9}, {499, 9}, {11, 9}, {267, 9},
  {139, 9}, {395, 9}, {75, 9}, {331, 9}, {203, 9}, {459, 9},
  {43, 9}, {299, 9}, {171, 9}, {427, 9}, {107, 9}, {363, 9},
  {235, 9}, {491, 9}, {27, 9}, {283, 9}, {155, 9}, {411, 9},
  {91, 9}, {347, 9}, {219, 9}, {475, 9}, {59, 9}, {315, 9},
  {187, 9}, {443, 9}, {123, 9}, {379, 9}, {251, 9}, {507, 9},
  {7, 9}, {263, 9}, {135, 9}, {391, 9}, {71, 9}, {327, 9},
  {199, 9}, {455, 9}, {39, 9}, {295, 9}, {167, 9}, {423, 9},
  {103, 9}, {359, 9}, {231, 9}, {487, 9}, {23, 9}, {279, 9},
  {151, 9}, {407, 9}, {87, 9}, {343, 9}, {215, 9}, {471, 9},
  {55, 9}, {311, 9}, {183, 9}, {439, 9}, {119, 9}, {375, 9},
  {247, 9}, {503, 9}, {15, 9}, {271, 9}, {143, 9}, {399, 9},
  {79, 9}, {335, 9}, {207, 9}, {463, 9}, {47, 9}, {303, 9},
  {175, 9}, {431, 9}, {111, 9}, {367, 9}, {239, 9}, {495, 9},
  {31, 9}, {287, 9}, {159, 9}, {415, 9}, {95, 9}, {351, 9},
  {223, 9}, {479, 9}, {63, 9}, {319, 9}, {191, 9}, {447, 9},
  {127, 9}, {383, 9}, {255, 9}, {511, 9}, {0, 7}, {64, 7},
  {32, 7}, {96, 7}, {16, 7}, {80, 7}, {48, 7}, {112, 7},
  {8, 7}, {72, 7}, {40, 7}, {104, 7}, {24, 7}, {88, 7},
  {56, 7}, {120, 7}, {4, 7}, {68, 7}, {36, 7}, {100, 7},
  {20, 7}, {84, 7}, {52, 7}, {116, 7}, {3, 8}, {131, 8},
  {67, 8}, {195, 8}, {35, 8}, {163, 8}, {99, 8}, {227, 8},
};

// Fixed canonical codes already reversed for low-bit-first emission.
// R6GameService.dll data @ 10076320 : 30 selected four-byte nodes.
static const DeflateStaticCodeRecord DeflateFixedDistanceCodes[30] = {
  {0, 5}, {16, 5}, {8, 5}, {24, 5}, {4, 5}, {20, 5},
  {12, 5}, {28, 5}, {2, 5}, {18, 5}, {10, 5}, {26, 5},
  {6, 5}, {22, 5}, {14, 5}, {30, 5}, {1, 5}, {17, 5},
  {9, 5}, {25, 5}, {5, 5}, {21, 5}, {13, 5}, {29, 5},
  {3, 5}, {19, 5}, {11, 5}, {27, 5}, {7, 5}, {23, 5},
};

// Build a frequency/depth heap, add missing leaves, merge nodes, assign bounded lengths and canonical codes.
// R6GameService.dll @ 100209e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall BuildDeflateHuffmanTree(void *state,void *descriptor)
{
  __asm {
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    push   edi
    mov    edi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x8]
    xor    ebx,ebx
    or     ebp,0xffffffff
    mov    edx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [eax+0xc]
    xor    eax,eax
    cmp    ecx,ebx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esi+0x1448],ebx
    mov    DWORD PTR [esi+0x144c],0x23d
    jle    Branch4
  Branch1:
    cmp    WORD PTR [edi+eax*4],bx
    je     Branch2
    mov    ecx,DWORD PTR [esi+0x1448]
    mov    DWORD PTR [esp+0x10],eax
    inc    ecx
    mov    ebp,eax
    mov    DWORD PTR [esi+0x1448],ecx
    mov    DWORD PTR [esi+ecx*4+0xb54],eax
    mov    ecx,DWORD PTR [esp+0x14]
    mov    BYTE PTR [eax+esi*1+0x1450],bl
    jmp    Branch3
  Branch2:
    mov    WORD PTR [edi+eax*4+0x2],bx
  Branch3:
    inc    eax
    cmp    eax,ecx
    jl     Branch1
  Branch4:
    mov    ecx,DWORD PTR [esi+0x1448]
    cmp    ecx,0x2
    jge    Branch9
  Branch5:
    cmp    ebp,0x2
    jge    Branch6
    inc    ebp
    mov    eax,ebp
    jmp    Branch7
  Branch6:
    xor    eax,eax
  Branch7:
    inc    ecx
    mov    DWORD PTR [esi+0x1448],ecx
    mov    DWORD PTR [esi+ecx*4+0xb54],eax
    mov    WORD PTR [edi+eax*4],0x1
    mov    BYTE PTR [esi+eax*1+0x1450],bl
    mov    ecx,DWORD PTR [esi+0x16a0]
    dec    ecx
    cmp    edx,ebx
    mov    DWORD PTR [esi+0x16a0],ecx
    je     Branch8
    xor    ecx,ecx
    mov    cx,WORD PTR [edx+eax*4+0x2]
    mov    eax,DWORD PTR [esi+0x16a4]
    sub    eax,ecx
    mov    DWORD PTR [esi+0x16a4],eax
  Branch8:
    mov    ecx,DWORD PTR [esi+0x1448]
    cmp    ecx,0x2
    jl     Branch5
    mov    DWORD PTR [esp+0x10],ebp
  Branch9:
    mov    edx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [edx+0x4],ebp
    mov    eax,DWORD PTR [esi+0x1448]
    cdq
    sub    eax,edx
    mov    ebx,eax
    sar    ebx,1
    cmp    ebx,0x1
    jl     Branch11
  Branch10:
    push   ebx
    push   edi
    push   esi
    call   R6GameServiceAddresses::RestoreDeflateHeap
    dec    ebx
    cmp    ebx,0x1
    jge    Branch10
  Branch11:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x1c],eax
  Branch12:
    mov    eax,DWORD PTR [esi+0x1448]
    mov    ebx,DWORD PTR [esi+0xb58]
    push   0x1
    push   edi
    mov    ecx,DWORD PTR [esi+eax*4+0xb54]
    dec    eax
    push   esi
    mov    DWORD PTR [esi+0xb58],ecx
    mov    DWORD PTR [esi+0x1448],eax
    call   R6GameServiceAddresses::RestoreDeflateHeap
    mov    edx,DWORD PTR [esi+0x144c]
    mov    ebp,DWORD PTR [esi+0xb58]
    dec    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0x144c],edx
    mov    DWORD PTR [esi+eax*4+0xb54],ebx
    mov    ecx,DWORD PTR [esi+0x144c]
    dec    ecx
    mov    eax,ecx
    mov    DWORD PTR [esi+0x144c],ecx
    mov    DWORD PTR [esi+eax*4+0xb54],ebp
    mov    dx,WORD PTR [edi+ebp*4]
    add    dx,WORD PTR [edi+ebx*4]
    mov    eax,DWORD PTR [esp+0x1c]
    mov    WORD PTR [edi+eax*4],dx
    mov    cl,BYTE PTR [esi+ebx*1+0x1450]
    mov    dl,BYTE PTR [esi+ebp*1+0x1450]
    cmp    cl,dl
    jb     Branch13
    and    ecx,0xff
    jmp    Branch14
  Branch13:
    and    edx,0xff
    mov    ecx,edx
  Branch14:
    inc    cl
    push   0x1
    mov    BYTE PTR [esi+eax*1+0x1450],cl
    mov    WORD PTR [edi+ebp*4+0x2],ax
    mov    WORD PTR [edi+ebx*4+0x2],ax
    mov    DWORD PTR [esi+0xb58],eax
    inc    eax
    push   edi
    push   esi
    mov    DWORD PTR [esp+0x28],eax
    call   R6GameServiceAddresses::RestoreDeflateHeap
    cmp    DWORD PTR [esi+0x1448],0x2
    jge    Branch12
    mov    eax,DWORD PTR [esi+0x144c]
    mov    edx,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esi+0xb58]
    dec    eax
    push   edx
    mov    DWORD PTR [esi+0x144c],eax
    push   esi
    mov    DWORD PTR [esi+eax*4+0xb54],ecx
    call   R6GameServiceAddresses::AssignDeflateCodeLengths
    add    esi,0xb34
    mov    eax,DWORD PTR [esp+0x10]
    push   esi
    push   eax
    push   edi
    call   R6GameServiceAddresses::GenerateDeflateCanonicalCodes
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Sift one heap element down by frequency/depth, choosing the right child on equal depth/frequency.
// R6GameService.dll @ 10020bf0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall RestoreDeflateHeap(void *state,void *tree,int index)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [eax+0x1448]
    push   edi
    mov    ebp,DWORD PTR [eax+esi*4+0xb54]
    lea    ecx,[esi+esi*1]
    cmp    ecx,edx
    mov    DWORD PTR [esp+0x14],ebp
    jg     Branch22
    mov    edi,DWORD PTR [esp+0x18]
  Branch15:
    jge    Branch18
    mov    esi,DWORD PTR [eax+ecx*4+0xb58]
    mov    ebp,DWORD PTR [eax+ecx*4+0xb54]
    mov    dx,WORD PTR [edi+esi*4]
    mov    bx,WORD PTR [edi+ebp*4]
    cmp    dx,bx
    jb     Branch16
    jne    Branch17
    mov    dl,BYTE PTR [esi+eax*1+0x1450]
    mov    bl,BYTE PTR [eax+ebp*1+0x1450]
    cmp    dl,bl
    ja     Branch17
  Branch16:
    inc    ecx
  Branch17:
    mov    ebp,DWORD PTR [esp+0x14]
  Branch18:
    mov    esi,DWORD PTR [eax+ecx*4+0xb54]
    mov    dx,WORD PTR [edi+ebp*4]
    mov    bx,WORD PTR [edi+esi*4]
    cmp    dx,bx
    jb     Branch20
    jne    Branch19
    mov    dl,BYTE PTR [eax+ebp*1+0x1450]
    mov    bl,BYTE PTR [esi+eax*1+0x1450]
    cmp    dl,bl
    jbe    Branch21
  Branch19:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x1c],ecx
    add    ecx,ecx
    mov    DWORD PTR [eax+edx*4+0xb54],esi
    mov    edx,DWORD PTR [eax+0x1448]
    cmp    ecx,edx
    jle    Branch15
  Branch20:
    mov    ecx,DWORD PTR [esp+0x1c]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax+ecx*4+0xb54],ebp
    pop    ebp
    pop    ebx
    ret    0xc
  Branch21:
    mov    edx,DWORD PTR [esp+0x1c]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax+edx*4+0xb54],ebp
    pop    ebp
    pop    ebx
    ret    0xc
  Branch22:
    mov    DWORD PTR [eax+esi*4+0xb54],ebp
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Walk sorted nodes, accumulate length costs, redistribute length overflow and update affected leaf lengths.
// R6GameService.dll @ 10020cd0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall AssignDeflateCodeLengths(void *state,void *descriptor)
{
  __asm {
    sub    esp,0x18
    mov    eax,DWORD PTR [esp+0x20]
    push   ebx
    push   ebp
    push   esi
    mov    ebp,DWORD PTR [eax]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esp+0x18],ecx
    push   edi
    xor    ebx,ebx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    esi,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,DWORD PTR [eax+0x10]
    mov    DWORD PTR [esp+0x20],ecx
    mov    DWORD PTR [esp+0x10],edx
    mov    edx,DWORD PTR [esp+0x2c]
    mov    ecx,0x8
    xor    eax,eax
    lea    edi,[edx+0xb34]
    mov    DWORD PTR [esp+0x30],ebx
    rep    stos DWORD PTR es:[edi],eax
    mov    eax,DWORD PTR [edx+0x144c]
    mov    ecx,DWORD PTR [edx+eax*4+0xb54]
    mov    WORD PTR [ebp+ecx*4+0x2],bx
    mov    eax,DWORD PTR [edx+0x144c]
    inc    eax
    cmp    eax,0x23d
    jge    Branch36
    lea    ecx,[edx+eax*4+0xb54]
    mov    DWORD PTR [esp+0x2c],ecx
    mov    ecx,0x23d
    sub    ecx,eax
    add    eax,ecx
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0x14],eax
  Branch23:
    mov    eax,DWORD PTR [esp+0x2c]
    xor    edi,edi
    mov    ecx,DWORD PTR [eax]
    xor    eax,eax
    mov    ax,WORD PTR [ebp+ecx*4+0x2]
    mov    di,WORD PTR [ebp+eax*4+0x2]
    mov    eax,edi
    mov    edi,DWORD PTR [esp+0x10]
    inc    eax
    cmp    eax,edi
    jle    Branch24
    inc    ebx
    mov    eax,edi
    mov    DWORD PTR [esp+0x30],ebx
  Branch24:
    mov    edi,DWORD PTR [esp+0x1c]
    mov    WORD PTR [ebp+ecx*4+0x2],ax
    cmp    ecx,edi
    jg     Branch27
    mov    edi,DWORD PTR [esp+0x20]
    inc    WORD PTR [edx+eax*2+0xb34]
    xor    ebx,ebx
    cmp    ecx,edi
    jl     Branch25
    mov    ebx,ecx
    sub    ebx,edi
    mov    edi,DWORD PTR [esp+0x24]
    mov    ebx,DWORD PTR [edi+ebx*4]
  Branch25:
    mov    di,WORD PTR [ebp+ecx*4+0x0]
    add    eax,ebx
    and    edi,0xffff
    imul   eax,edi
    add    DWORD PTR [edx+0x16a0],eax
    test   esi,esi
    je     Branch26
    xor    eax,eax
    mov    ax,WORD PTR [esi+ecx*4+0x2]
    mov    ecx,DWORD PTR [edx+0x16a4]
    add    eax,ebx
    imul   eax,edi
    add    ecx,eax
    mov    DWORD PTR [edx+0x16a4],ecx
  Branch26:
    mov    ebx,DWORD PTR [esp+0x30]
  Branch27:
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    eax,DWORD PTR [esp+0x18]
    add    ecx,0x4
    dec    eax
    mov    DWORD PTR [esp+0x2c],ecx
    mov    DWORD PTR [esp+0x18],eax
    jne    Branch23
    test   ebx,ebx
    je     Branch36
    mov    eax,DWORD PTR [esp+0x10]
    lea    esi,[eax-0x1]
    lea    edi,[edx+eax*2+0xb34]
  Branch28:
    mov    eax,esi
    cmp    WORD PTR [edx+eax*2+0xb34],0x0
    lea    ecx,[edx+eax*2+0xb34]
    jne    Branch30
  Branch29:
    sub    ecx,0x2
    dec    eax
    cmp    WORD PTR [ecx],0x0
    je     Branch29
  Branch30:
    dec    WORD PTR [edx+eax*2+0xb34]
    add    WORD PTR [edx+eax*2+0xb36],0x2
    dec    WORD PTR [edi]
    sub    ebx,0x2
    test   ebx,ebx
    jg     Branch28
    mov    esi,DWORD PTR [esp+0x10]
    test   esi,esi
    je     Branch36
    mov    DWORD PTR [esp+0x2c],edi
  Branch31:
    xor    eax,eax
    mov    ax,WORD PTR [edi]
    test   eax,eax
    mov    DWORD PTR [esp+0x30],eax
    je     Branch35
    mov    ecx,DWORD PTR [esp+0x14]
    lea    ebx,[edx+ecx*4+0xb54]
  Branch32:
    mov    edi,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [ebx-0x4]
    dec    edi
    sub    ebx,0x4
    mov    DWORD PTR [esp+0x14],edi
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    ecx,edi
    mov    DWORD PTR [esp+0x24],ebx
    jg     Branch34
    lea    edi,[ebp+ecx*4+0x2]
    xor    eax,eax
    mov    ax,WORD PTR [edi]
    cmp    eax,esi
    je     Branch33
    mov    ebx,esi
    sub    ebx,eax
    xor    eax,eax
    mov    ax,WORD PTR [ebp+ecx*4+0x0]
    imul   ebx,eax
    mov    eax,DWORD PTR [edx+0x16a0]
    add    eax,ebx
    mov    ebx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [edx+0x16a0],eax
    mov    WORD PTR [edi],si
  Branch33:
    mov    eax,DWORD PTR [esp+0x30]
    dec    eax
    mov    DWORD PTR [esp+0x30],eax
  Branch34:
    test   eax,eax
    jne    Branch32
  Branch35:
    mov    edi,DWORD PTR [esp+0x2c]
    dec    esi
    sub    edi,0x2
    test   esi,esi
    mov    DWORD PTR [esp+0x2c],edi
    jne    Branch31
  Branch36:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x18
    ret    0x8
  }
}

// Compute low-word canonical start codes, reverse each nonzero-length code and replace leaf frequencies.
// R6GameService.dll @ 10020ef0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall GenerateDeflateCanonicalCodes(void *tree,int maxCode,const void *lengthCounts)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0x20
    xor    ecx,ecx
    mov    eax,0x1
    push   ebx
    push   esi
    lea    esi,[esp+0xa]
    sub    edx,esi
  Branch37:
    lea    esi,[edx+eax*2]
    mov    si,WORD PTR [esp+esi*1+0x8]
    add    si,cx
    add    esi,esi
    inc    eax
    mov    ecx,esi
    cmp    eax,0xf
    mov    WORD PTR [esp+eax*2+0x6],cx
    jle    Branch37
    mov    ebx,DWORD PTR [esp+0x30]
    xor    esi,esi
    test   ebx,ebx
    jl     Branch40
    push   edi
    mov    edi,DWORD PTR [esp+0x30]
  Branch38:
    xor    eax,eax
    mov    ax,WORD PTR [edi+esi*4+0x2]
    test   eax,eax
    je     Branch39
    mov    dx,WORD PTR [esp+eax*2+0xc]
    push   eax
    mov    ecx,edx
    and    ecx,0xffff
    inc    edx
    push   ecx
    mov    WORD PTR [esp+eax*2+0x14],dx
    call   R6GameServiceAddresses::ReverseDeflateCodeBits
    mov    WORD PTR [edi+esi*4],ax
  Branch39:
    inc    esi
    cmp    esi,ebx
    jle    Branch38
    pop    edi
  Branch40:
    pop    esi
    pop    ebx
    add    esp,0x20
    ret    0xc
  }
}

// Scan literal/distance code lengths, build their run-length tree and add header/order cost.
// R6GameService.dll @ 10020f70 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall BuildDeflateBitLengthTree(void *state)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esi+0xb14]
    lea    ecx,[esi+0x8c]
    push   eax
    push   ecx
    push   esi
    call   R6GameServiceAddresses::CountDeflateCodeLengthRuns
    mov    edx,DWORD PTR [esi+0xb20]
    lea    eax,[esi+0x980]
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::CountDeflateCodeLengthRuns
    lea    ecx,[esi+0xb28]
    push   ecx
    push   esi
    call   R6GameServiceAddresses::BuildDeflateHuffmanTree
    mov    eax,0x12
  Branch41:
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::DeflateBitLengthOrder]
    cmp    WORD PTR [esi+edx*4+0xa76],0x0
    jne    Branch42
    dec    eax
    cmp    eax,0x3
    jge    Branch41
  Branch42:
    mov    edx,DWORD PTR [esi+0x16a0]
    lea    ecx,[eax+eax*2+0x11]
    add    edx,ecx
    mov    DWORD PTR [esi+0x16a0],edx
    pop    esi
    ret    0x4
  }
}

// Publish a sentinel length and count literal/16/17/18 run tokens with native thresholds and word widths.
// R6GameService.dll @ 10020fe0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CountDeflateCodeLengthRuns(void *state,void *tree,int maxCode)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    push   ebx
    xor    ecx,ecx
    push   esi
    mov    cx,WORD PTR [eax+0x2]
    push   edi
    xor    edi,edi
    mov    DWORD PTR [esp+0xc],0xffffffff
    test   ecx,ecx
    mov    edx,0x7
    mov    esi,0x4
    jne    Branch43
    mov    edx,0x8a
    mov    esi,0x3
  Branch43:
    mov    ebx,DWORD PTR [esp+0x1c]
    test   ebx,ebx
    mov    WORD PTR [eax+ebx*4+0x6],0xffff
    jl     Branch54
    inc    ebx
    push   ebp
    mov    DWORD PTR [esp+0x1c],ebx
    mov    ebx,DWORD PTR [esp+0x18]
    lea    ebp,[eax+0x6]
  Branch44:
    mov    eax,ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [ebp+0x0]
    inc    edi
    cmp    edi,edx
    jge    Branch45
    cmp    eax,ecx
    je     Branch53
  Branch45:
    cmp    edi,esi
    jge    Branch46
    add    WORD PTR [ebx+eax*4+0xa74],di
    jmp    Branch50
  Branch46:
    test   eax,eax
    je     Branch48
    cmp    eax,DWORD PTR [esp+0x10]
    je     Branch47
    inc    WORD PTR [ebx+eax*4+0xa74]
  Branch47:
    inc    WORD PTR [ebx+0xab4]
    jmp    Branch50
  Branch48:
    cmp    edi,0xa
    jg     Branch49
    inc    WORD PTR [ebx+0xab8]
    jmp    Branch50
  Branch49:
    inc    WORD PTR [ebx+0xabc]
  Branch50:
    xor    edi,edi
    mov    DWORD PTR [esp+0x10],eax
    test   ecx,ecx
    jne    Branch51
    mov    edx,0x8a
    mov    esi,0x3
    jmp    Branch53
  Branch51:
    cmp    eax,ecx
    jne    Branch52
    mov    edx,0x6
    mov    esi,0x3
    jmp    Branch53
  Branch52:
    mov    edx,0x7
    mov    esi,0x4
  Branch53:
    mov    eax,DWORD PTR [esp+0x1c]
    add    ebp,0x4
    dec    eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch44
    pop    ebp
  Branch54:
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  }
}
