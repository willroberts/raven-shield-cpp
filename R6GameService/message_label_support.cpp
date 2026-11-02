#include "native_addresses.h"

// Shared message-label helpers; original free/member ownership is unresolved. Incoming ECX is unused.

// Literal native read-only dispatch table at 1005ac90.
static const uint GMessageLabelTargets[129] = {
    R6GameServiceAddresses::GMessageLabelTargetsCase1,R6GameServiceAddresses::GMessageLabelTargetsCase2,R6GameServiceAddresses::GMessageLabelTargetsCase3,R6GameServiceAddresses::GMessageLabelTargetsCase4,R6GameServiceAddresses::GMessageLabelTargetsCase5,R6GameServiceAddresses::GMessageLabelTargetsCase6,R6GameServiceAddresses::GMessageLabelTargetsCase7,R6GameServiceAddresses::GMessageLabelTargetsCase8,
    R6GameServiceAddresses::GMessageLabelTargetsCase9,R6GameServiceAddresses::GMessageLabelTargetsCase10,R6GameServiceAddresses::GMessageLabelTargetsCase11,R6GameServiceAddresses::GMessageLabelTargetsCase12,R6GameServiceAddresses::GMessageLabelTargetsCase13,R6GameServiceAddresses::GMessageLabelTargetsCase14,R6GameServiceAddresses::GMessageLabelTargetsCase15,R6GameServiceAddresses::GMessageLabelTargetsCase16,
    R6GameServiceAddresses::GMessageLabelTargetsCase17,R6GameServiceAddresses::GMessageLabelTargetsCase18,R6GameServiceAddresses::GMessageLabelTargetsCase19,R6GameServiceAddresses::GMessageLabelTargetsCase20,R6GameServiceAddresses::GMessageLabelTargetsCase21,R6GameServiceAddresses::GMessageLabelTargetsCase22,R6GameServiceAddresses::GMessageLabelTargetsCase23,R6GameServiceAddresses::GMessageLabelTargetsCase24,
    R6GameServiceAddresses::GMessageLabelTargetsCase25,R6GameServiceAddresses::GMessageLabelTargetsCase26,R6GameServiceAddresses::GMessageLabelTargetsCase27,R6GameServiceAddresses::GMessageLabelTargetsCase28,R6GameServiceAddresses::GMessageLabelTargetsCase29,R6GameServiceAddresses::GMessageLabelTargetsCase30,R6GameServiceAddresses::GMessageLabelTargetsCase31,R6GameServiceAddresses::GMessageLabelTargetsCase32,
    R6GameServiceAddresses::GMessageLabelTargetsCase33,R6GameServiceAddresses::GMessageLabelTargetsCase34,R6GameServiceAddresses::GMessageLabelTargetsCase35,R6GameServiceAddresses::GMessageLabelTargetsCase36,R6GameServiceAddresses::GMessageLabelTargetsCase37,R6GameServiceAddresses::GMessageLabelTargetsCase38,R6GameServiceAddresses::GMessageLabelTargetsCase39,R6GameServiceAddresses::GMessageLabelTargetsCase40,
    R6GameServiceAddresses::GMessageLabelTargetsCase41,R6GameServiceAddresses::GMessageLabelTargetsCase42,R6GameServiceAddresses::GMessageLabelTargetsCase43,R6GameServiceAddresses::GMessageLabelTargetsCase44,R6GameServiceAddresses::GMessageLabelTargetsCase45,R6GameServiceAddresses::GMessageLabelTargetsCase46,R6GameServiceAddresses::GMessageLabelTargetsCase47,R6GameServiceAddresses::GMessageLabelTargetsCase48,
    R6GameServiceAddresses::GMessageLabelTargetsCase49,R6GameServiceAddresses::GMessageLabelTargetsCase50,R6GameServiceAddresses::GMessageLabelTargetsCase51,R6GameServiceAddresses::GMessageLabelTargetsCase52,R6GameServiceAddresses::GMessageLabelTargetsCase53,R6GameServiceAddresses::GMessageLabelTargetsCase54,R6GameServiceAddresses::GMessageLabelTargetsCase55,R6GameServiceAddresses::GMessageLabelTargetsCase56,
    R6GameServiceAddresses::GMessageLabelTargetsCase57,R6GameServiceAddresses::GMessageLabelTargetsCase58,R6GameServiceAddresses::GMessageLabelTargetsCase59,R6GameServiceAddresses::GMessageLabelTargetsCase60,R6GameServiceAddresses::GMessageLabelTargetsCase61,R6GameServiceAddresses::GMessageLabelTargetsCase62,R6GameServiceAddresses::GMessageLabelTargetsCase63,R6GameServiceAddresses::GMessageLabelTargetsCase64,
    R6GameServiceAddresses::GMessageLabelTargetsCase65,R6GameServiceAddresses::GMessageLabelTargetsCase66,R6GameServiceAddresses::GMessageLabelTargetsCase67,R6GameServiceAddresses::GMessageLabelTargetsCase68,R6GameServiceAddresses::GMessageLabelTargetsCase69,R6GameServiceAddresses::GMessageLabelTargetsCase70,R6GameServiceAddresses::GMessageLabelTargetsCase71,R6GameServiceAddresses::GMessageLabelTargetsCase72,
    R6GameServiceAddresses::GMessageLabelTargetsCase73,R6GameServiceAddresses::GMessageLabelTargetsCase74,R6GameServiceAddresses::GMessageLabelTargetsCase75,R6GameServiceAddresses::GMessageLabelTargetsCase76,R6GameServiceAddresses::GMessageLabelTargetsCase77,R6GameServiceAddresses::GMessageLabelTargetsCase78,R6GameServiceAddresses::GMessageLabelTargetsCase79,R6GameServiceAddresses::GMessageLabelTargetsCase80,
    R6GameServiceAddresses::GMessageLabelTargetsCase81,R6GameServiceAddresses::GMessageLabelTargetsCase82,R6GameServiceAddresses::GMessageLabelTargetsCase83,R6GameServiceAddresses::GMessageLabelTargetsCase84,R6GameServiceAddresses::GMessageLabelTargetsCase85,R6GameServiceAddresses::GMessageLabelTargetsCase86,R6GameServiceAddresses::GMessageLabelTargetsCase87,R6GameServiceAddresses::GMessageLabelTargetsCase88,
    R6GameServiceAddresses::GMessageLabelTargetsCase89,R6GameServiceAddresses::GMessageLabelTargetsCase90,R6GameServiceAddresses::GMessageLabelTargetsCase91,R6GameServiceAddresses::GMessageLabelTargetsCase92,R6GameServiceAddresses::GMessageLabelTargetsCase93,R6GameServiceAddresses::GMessageLabelTargetsCase94,R6GameServiceAddresses::GMessageLabelTargetsCase95,R6GameServiceAddresses::GMessageLabelTargetsCase96,
    R6GameServiceAddresses::GMessageLabelTargetsCase97,R6GameServiceAddresses::GMessageLabelTargetsCase98,R6GameServiceAddresses::GMessageLabelTargetsCase99,R6GameServiceAddresses::GMessageLabelTargetsCase100,R6GameServiceAddresses::GMessageLabelTargetsCase101,R6GameServiceAddresses::GMessageLabelTargetsCase102,R6GameServiceAddresses::GMessageLabelTargetsCase103,R6GameServiceAddresses::GMessageLabelTargetsCase104,
    R6GameServiceAddresses::GMessageLabelTargetsCase105,R6GameServiceAddresses::GMessageLabelTargetsCase106,R6GameServiceAddresses::GMessageLabelTargetsCase107,R6GameServiceAddresses::GMessageLabelTargetsCase108,R6GameServiceAddresses::GMessageLabelTargetsCase109,R6GameServiceAddresses::GMessageLabelTargetsCase110,R6GameServiceAddresses::GMessageLabelTargetsCase111,R6GameServiceAddresses::GMessageLabelTargetsCase112,
    R6GameServiceAddresses::GMessageLabelTargetsCase113,R6GameServiceAddresses::GMessageLabelTargetsCase114,R6GameServiceAddresses::GMessageLabelTargetsCase115,R6GameServiceAddresses::GMessageLabelTargetsCase116,R6GameServiceAddresses::GMessageLabelTargetsCase117,R6GameServiceAddresses::GMessageLabelTargetsCase118,R6GameServiceAddresses::GMessageLabelTargetsCase119,R6GameServiceAddresses::GMessageLabelTargetsCase120,
    R6GameServiceAddresses::GMessageLabelTargetsCase121,R6GameServiceAddresses::GMessageLabelTargetsCase122,R6GameServiceAddresses::GMessageLabelTargetsCase123,R6GameServiceAddresses::GMessageLabelTargetsCase124,R6GameServiceAddresses::GMessageLabelTargetsCase125,R6GameServiceAddresses::GMessageLabelTargetsCase126,R6GameServiceAddresses::GMessageLabelTargetsCase127,R6GameServiceAddresses::GMessageLabelTargetsCase128,
    R6GameServiceAddresses::GMessageLabelTargetsCase129
};

// Literal native read-only dispatch table at 1005ae94.
static const byte GMessageLabelSelectors[212] = {
    0x0,0x1,0x2,0x3,0x4,0x80,0x5,0x6,0x7,0x80,0x8,0x80,0x9,0x80,0xa,0xb,0xc,0xd,0xe,0xf,
    0x10,0x11,0x80,0x12,0x80,0x13,0x14,0x15,0x80,0x80,0x16,0x17,0x18,0x19,0x80,0x80,0x80,0x1a,0x1b,0x1c,
    0x80,0x80,0x80,0x80,0x1d,0x80,0x80,0x1e,0x80,0x80,0x1f,0x20,0x80,0x21,0x22,0x80,0x80,0x23,0x24,0x25,
    0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x80,0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
    0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,
    0x4d,0x4e,0x4f,0x50,0x80,0x51,0x52,0x53,0x54,0x55,0x56,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
    0x80,0x80,0x80,0x80,0x80,0x80,0x57,0x80,0x80,0x80,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,0x60,0x61,
    0x62,0x80,0x63,0x64,0x65,0x66,0x80,0x67,0x80,0x80,0x68,0x80,0x80,0x80,0x80,0x80,0x69,0x6a,0x6b,0x80,
    0x80,0x80,0x80,0x80,0x80,0x6c,0x80,0x80,0x6d,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x6e,0x6f,
    0x70,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x71,0x72,0x80,0x73,0x74,0x75,0x76,0x77,0x80,0x80,0x78,0x80,
    0x80,0x79,0x7a,0x80,0x7b,0x80,0x80,0x80,0x7c,0x7d,0x7e,0x7f
};

// Zero-extend the supplied lowWORD, format with native "%d", and return the imported formatter result/RET8.
// R6GameService.dll @ 1005a030 : two full stack words; incoming ECX ignored.
int __stdcall FormatWordAsDecimal(uint codeWord,char *output)
{
  return sprintf(output,(const char *)R6GameServiceAddresses::TextSignedDecimalFormat,codeWord & 0xffff);
}

// Select the lowBYTE label through native tables, copy bytes forward including NUL and return source-past-NUL.
// Numeric fallback returns the imported formatter result. One loop represents 128 identical inline native branches.
// R6GameService.dll @ 1005a050 : two full stack words; incoming ECX ignored, raw uint/RET8.
uint __stdcall FormatByteLabel(uint codeWord,char *output)
{
  uint codeByte = codeWord & 0xff;
  uint index = codeByte - 1;
  if (index > 0xd3) return (uint)sprintf(output,(const char *)R6GameServiceAddresses::TextSignedDecimalFormat,codeByte);
  uint selector = GMessageLabelSelectors[index];
  uint target = GMessageLabelTargets[selector];
  uint sourceAddress;
  // The fixed native tables select exactly these 129 targets.
  switch (target) {
  case R6GameServiceAddresses::GMessageLabelTargetsCase1: sourceAddress = R6GameServiceAddresses::TextNEWUSERREQUEST; break; // NEWUSERREQUEST
  case R6GameServiceAddresses::GMessageLabelTargetsCase2: sourceAddress = R6GameServiceAddresses::TextCONNECTIONREQUEST; break; // CONNECTIONREQUEST
  case R6GameServiceAddresses::GMessageLabelTargetsCase3: sourceAddress = R6GameServiceAddresses::TextPLAYERNEW; break; // PLAYERNEW
  case R6GameServiceAddresses::GMessageLabelTargetsCase4: sourceAddress = R6GameServiceAddresses::TextDISCONNECTION; break; // DISCONNECTION
  case R6GameServiceAddresses::GMessageLabelTargetsCase5: sourceAddress = R6GameServiceAddresses::TextPLAYERREMOVED; break; // PLAYERREMOVED
  case R6GameServiceAddresses::GMessageLabelTargetsCase6: sourceAddress = R6GameServiceAddresses::TextNEWS; break; // NEWS
  case R6GameServiceAddresses::GMessageLabelTargetsCase7: sourceAddress = R6GameServiceAddresses::TextSEARCHPLAYER; break; // SEARCHPLAYER
  case R6GameServiceAddresses::GMessageLabelTargetsCase8: sourceAddress = R6GameServiceAddresses::TextREMOVEACCOUNT; break; // REMOVEACCOUNT
  case R6GameServiceAddresses::GMessageLabelTargetsCase9: sourceAddress = R6GameServiceAddresses::TextSERVERSLIST; break; // SERVERSLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase10: sourceAddress = R6GameServiceAddresses::TextSESSIONLIST; break; // SESSIONLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase11: sourceAddress = R6GameServiceAddresses::TextPLAYERLIST; break; // PLAYERLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase12: sourceAddress = R6GameServiceAddresses::TextGETGROUPINFO; break; // GETGROUPINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase13: sourceAddress = R6GameServiceAddresses::TextGROUPINFO; break; // GROUPINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase14: sourceAddress = R6GameServiceAddresses::TextGETPLAYERINFO; break; // GETPLAYERINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase15: sourceAddress = R6GameServiceAddresses::TextPLAYERINFO; break; // PLAYERINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase16: sourceAddress = R6GameServiceAddresses::TextCHATALL; break; // CHATALL
  case R6GameServiceAddresses::GMessageLabelTargetsCase17: sourceAddress = R6GameServiceAddresses::TextCHATLIST; break; // CHATLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase18: sourceAddress = R6GameServiceAddresses::TextCHATSESSION; break; // CHATSESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase19: sourceAddress = R6GameServiceAddresses::TextCHAT; break; // CHAT
  case R6GameServiceAddresses::GMessageLabelTargetsCase20: sourceAddress = R6GameServiceAddresses::TextCREATESESSION; break; // CREATESESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase21: sourceAddress = R6GameServiceAddresses::TextSESSIONNEW; break; // SESSIONNEW
  case R6GameServiceAddresses::GMessageLabelTargetsCase22: sourceAddress = R6GameServiceAddresses::TextJOINSESSION; break; // JOINSESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase23: sourceAddress = R6GameServiceAddresses::TextJOINNEW; break; // JOINNEW
  case R6GameServiceAddresses::GMessageLabelTargetsCase24: sourceAddress = R6GameServiceAddresses::TextLEAVESESSION; break; // LEAVESESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase25: sourceAddress = R6GameServiceAddresses::TextJOINLEAVE; break; // JOINLEAVE
  case R6GameServiceAddresses::GMessageLabelTargetsCase26: sourceAddress = R6GameServiceAddresses::TextSESSIONREMOVE; break; // SESSIONREMOVE
  case R6GameServiceAddresses::GMessageLabelTargetsCase27: sourceAddress = R6GameServiceAddresses::TextGSSUCCESS; break; // GSSUCCESS
  case R6GameServiceAddresses::GMessageLabelTargetsCase28: sourceAddress = R6GameServiceAddresses::TextGSFAIL; break; // GSFAIL
  case R6GameServiceAddresses::GMessageLabelTargetsCase29: sourceAddress = R6GameServiceAddresses::TextBEGINGAME; break; // BEGINGAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase30: sourceAddress = R6GameServiceAddresses::TextUPDATEPLAYERINFO; break; // UPDATEPLAYERINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase31: sourceAddress = R6GameServiceAddresses::TextMASTERCHANGED; break; // MASTERCHANGED
  case R6GameServiceAddresses::GMessageLabelTargetsCase32: sourceAddress = R6GameServiceAddresses::TextUPDATESESSIONSTATE; break; // UPDATESESSIONSTATE
  case R6GameServiceAddresses::GMessageLabelTargetsCase33: sourceAddress = R6GameServiceAddresses::TextURGENTMESSAGE; break; // URGENTMESSAGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase34: sourceAddress = R6GameServiceAddresses::TextNEWWAITMODULE; break; // NEWWAITMODULE
  case R6GameServiceAddresses::GMessageLabelTargetsCase35: sourceAddress = R6GameServiceAddresses::TextKILLMODULE; break; // KILLMODULE
  case R6GameServiceAddresses::GMessageLabelTargetsCase36: sourceAddress = R6GameServiceAddresses::TextSTILLALIVE; break; // STILLALIVE
  case R6GameServiceAddresses::GMessageLabelTargetsCase37: sourceAddress = R6GameServiceAddresses::TextPING; break; // PING
  case R6GameServiceAddresses::GMessageLabelTargetsCase38: sourceAddress = R6GameServiceAddresses::TextPLAYERKICK; break; // PLAYERKICK
  case R6GameServiceAddresses::GMessageLabelTargetsCase39: sourceAddress = R6GameServiceAddresses::TextPLAYERMUTE; break; // PLAYERMUTE
  case R6GameServiceAddresses::GMessageLabelTargetsCase40: sourceAddress = R6GameServiceAddresses::TextALLOWGAME; break; // ALLOWGAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase41: sourceAddress = R6GameServiceAddresses::TextFORBIDGAME; break; // FORBIDGAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase42: sourceAddress = R6GameServiceAddresses::TextGAMELIST; break; // GAMELIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase43: sourceAddress = R6GameServiceAddresses::TextUPDATEADVERTISMEMENTS; break; // UPDATEADVERTISMEMENTS
  case R6GameServiceAddresses::GMessageLabelTargetsCase44: sourceAddress = R6GameServiceAddresses::TextUPDATENEWS; break; // UPDATENEWS
  case R6GameServiceAddresses::GMessageLabelTargetsCase45: sourceAddress = R6GameServiceAddresses::TextVERSIONLIST; break; // VERSIONLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase46: sourceAddress = R6GameServiceAddresses::TextUPDATEVERSIONS; break; // UPDATEVERSIONS
  case R6GameServiceAddresses::GMessageLabelTargetsCase47: sourceAddress = R6GameServiceAddresses::TextUPDATEDISTANTROUTERS; break; // UPDATEDISTANTROUTERS
  case R6GameServiceAddresses::GMessageLabelTargetsCase48: sourceAddress = R6GameServiceAddresses::TextADMINLOGIN; break; // ADMINLOGIN
  case R6GameServiceAddresses::GMessageLabelTargetsCase49: sourceAddress = R6GameServiceAddresses::TextSTATPLAYER; break; // STAT_PLAYER
  case R6GameServiceAddresses::GMessageLabelTargetsCase50: sourceAddress = R6GameServiceAddresses::TextSTATGAME; break; // STAT_GAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase51: sourceAddress = R6GameServiceAddresses::TextUPDATEFRIEND; break; // UPDATEFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase52: sourceAddress = R6GameServiceAddresses::TextADDFRIEND; break; // ADDFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase53: sourceAddress = R6GameServiceAddresses::TextDELFRIEND; break; // DELFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase54: sourceAddress = R6GameServiceAddresses::TextLOGINWAITMODULE; break; // LOGINWAITMODULE
  case R6GameServiceAddresses::GMessageLabelTargetsCase55: sourceAddress = R6GameServiceAddresses::TextLOGINFRIENDS; break; // LOGINFRIENDS
  case R6GameServiceAddresses::GMessageLabelTargetsCase56: sourceAddress = R6GameServiceAddresses::TextADDIGNOREFRIEND; break; // ADDIGNOREFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase57: sourceAddress = R6GameServiceAddresses::TextDELIGNOREFRIEND; break; // DELIGNOREFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase58: sourceAddress = R6GameServiceAddresses::TextSTATUSCHANGE; break; // STATUSCHANGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase59: sourceAddress = R6GameServiceAddresses::TextJOINARENA; break; // JOINARENA
  case R6GameServiceAddresses::GMessageLabelTargetsCase60: sourceAddress = R6GameServiceAddresses::TextLEAVEARENA; break; // LEAVEARENA
  case R6GameServiceAddresses::GMessageLabelTargetsCase61: sourceAddress = R6GameServiceAddresses::TextIGNORELIST; break; // IGNORELIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase62: sourceAddress = R6GameServiceAddresses::TextIGNOREFRIEND; break; // IGNOREFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase63: sourceAddress = R6GameServiceAddresses::TextGETARENA; break; // GETARENA
  case R6GameServiceAddresses::GMessageLabelTargetsCase64: sourceAddress = R6GameServiceAddresses::TextGETSESSION; break; // GETSESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase65: sourceAddress = R6GameServiceAddresses::TextPAGEPLAYER; break; // PAGEPLAYER
  case R6GameServiceAddresses::GMessageLabelTargetsCase66: sourceAddress = R6GameServiceAddresses::TextFRIENDLIST; break; // FRIENDLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase67: sourceAddress = R6GameServiceAddresses::TextPEERMSG; break; // PEERMSG
  case R6GameServiceAddresses::GMessageLabelTargetsCase68: sourceAddress = R6GameServiceAddresses::TextPEERPLAYER; break; // PEERPLAYER
  case R6GameServiceAddresses::GMessageLabelTargetsCase69: sourceAddress = R6GameServiceAddresses::TextDISCONNECTFRIENDS; break; // DISCONNECTFRIENDS
  case R6GameServiceAddresses::GMessageLabelTargetsCase70: sourceAddress = R6GameServiceAddresses::TextJOINWAITMODULE; break; // JOINWAITMODULE
  case R6GameServiceAddresses::GMessageLabelTargetsCase71: sourceAddress = R6GameServiceAddresses::TextLOGINSESSION; break; // LOGINSESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase72: sourceAddress = R6GameServiceAddresses::TextDISCONNECTSESSION; break; // DISCONNECTSESSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase73: sourceAddress = R6GameServiceAddresses::TextPLAYERDISCONNECT; break; // PLAYERDISCONNECT
  case R6GameServiceAddresses::GMessageLabelTargetsCase74: sourceAddress = R6GameServiceAddresses::TextADVERTISEMENT; break; // ADVERTISEMENT
  case R6GameServiceAddresses::GMessageLabelTargetsCase75: sourceAddress = R6GameServiceAddresses::TextMODIFYUSER; break; // MODIFYUSER
  case R6GameServiceAddresses::GMessageLabelTargetsCase76: sourceAddress = R6GameServiceAddresses::TextSTARTGAME; break; // STARTGAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase77: sourceAddress = R6GameServiceAddresses::TextCHANGEVERSION; break; // CHANGEVERSION
  case R6GameServiceAddresses::GMessageLabelTargetsCase78: sourceAddress = R6GameServiceAddresses::TextPAGER; break; // PAGER
  case R6GameServiceAddresses::GMessageLabelTargetsCase79: sourceAddress = R6GameServiceAddresses::TextLOGIN; break; // LOGIN
  case R6GameServiceAddresses::GMessageLabelTargetsCase80: sourceAddress = R6GameServiceAddresses::TextPHOTO; break; // PHOTO
  case R6GameServiceAddresses::GMessageLabelTargetsCase81: sourceAddress = R6GameServiceAddresses::TextLOGINARENA; break; // LOGINARENA
  case R6GameServiceAddresses::GMessageLabelTargetsCase82: sourceAddress = R6GameServiceAddresses::TextSQLCREATE; break; // SQLCREATE
  case R6GameServiceAddresses::GMessageLabelTargetsCase83: sourceAddress = R6GameServiceAddresses::TextSQLSELECT; break; // SQLSELECT
  case R6GameServiceAddresses::GMessageLabelTargetsCase84: sourceAddress = R6GameServiceAddresses::TextSQLDELETE; break; // SQLDELETE
  case R6GameServiceAddresses::GMessageLabelTargetsCase85: sourceAddress = R6GameServiceAddresses::TextSQLSET; break; // SQLSET
  case R6GameServiceAddresses::GMessageLabelTargetsCase86: sourceAddress = R6GameServiceAddresses::TextSQLSTAT; break; // SQLSTAT
  case R6GameServiceAddresses::GMessageLabelTargetsCase87: sourceAddress = R6GameServiceAddresses::TextSQLQUERY; break; // SQLQUERY
  case R6GameServiceAddresses::GMessageLabelTargetsCase88: sourceAddress = R6GameServiceAddresses::TextROUTEURLIST; break; // ROUTEURLIST
  case R6GameServiceAddresses::GMessageLabelTargetsCase89: sourceAddress = R6GameServiceAddresses::TextDISTANCEVECTOR; break; // DISTANCEVECTOR
  case R6GameServiceAddresses::GMessageLabelTargetsCase90: sourceAddress = R6GameServiceAddresses::TextWRAPPEDMESSAGE; break; // WRAPPEDMESSAGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase91: sourceAddress = R6GameServiceAddresses::TextCHANGEFRIEND; break; // CHANGEFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase92: sourceAddress = R6GameServiceAddresses::TextNEWRELFRIEND; break; // NEWRELFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase93: sourceAddress = R6GameServiceAddresses::TextDELRELFRIEND; break; // DELRELFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase94: sourceAddress = R6GameServiceAddresses::TextNEWIGNOREFRIEND; break; // NEWIGNOREFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase95: sourceAddress = R6GameServiceAddresses::TextDELETEIGNOREFRIEND; break; // DELETEIGNOREFRIEND
  case R6GameServiceAddresses::GMessageLabelTargetsCase96: sourceAddress = R6GameServiceAddresses::TextARENACONNECTION; break; // ARENACONNECTION
  case R6GameServiceAddresses::GMessageLabelTargetsCase97: sourceAddress = R6GameServiceAddresses::TextARENADISCONNECTION; break; // ARENADISCONNECTION
  case R6GameServiceAddresses::GMessageLabelTargetsCase98: sourceAddress = R6GameServiceAddresses::TextARENAWAITMODULE; break; // ARENAWAITMODULE
  case R6GameServiceAddresses::GMessageLabelTargetsCase99: sourceAddress = R6GameServiceAddresses::TextARENANEW; break; // ARENANEW
  case R6GameServiceAddresses::GMessageLabelTargetsCase100: sourceAddress = R6GameServiceAddresses::TextNEWBASICGROUP; break; // NEWBASICGROUP
  case R6GameServiceAddresses::GMessageLabelTargetsCase101: sourceAddress = R6GameServiceAddresses::TextARENAREMOVED; break; // ARENAREMOVED
  case R6GameServiceAddresses::GMessageLabelTargetsCase102: sourceAddress = R6GameServiceAddresses::TextDELETEBASICGROUP; break; // DELETEBASICGROUP
  case R6GameServiceAddresses::GMessageLabelTargetsCase103: sourceAddress = R6GameServiceAddresses::TextSESSIONSBEGIN; break; // SESSIONSBEGIN
  case R6GameServiceAddresses::GMessageLabelTargetsCase104: sourceAddress = R6GameServiceAddresses::TextGROUPDATA; break; // GROUPDATA
  case R6GameServiceAddresses::GMessageLabelTargetsCase105: sourceAddress = R6GameServiceAddresses::TextARENAMESSAGE; break; // ARENA_MESSAGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase106: sourceAddress = R6GameServiceAddresses::TextARENALISTREQUEST; break; // ARENALISTREQUEST
  case R6GameServiceAddresses::GMessageLabelTargetsCase107: sourceAddress = R6GameServiceAddresses::TextROUTERPLAYERNEW; break; // ROUTERPLAYERNEW
  case R6GameServiceAddresses::GMessageLabelTargetsCase108: sourceAddress = R6GameServiceAddresses::TextBASEGROUPREQUEST; break; // BASEGROUPREQUEST
  case R6GameServiceAddresses::GMessageLabelTargetsCase109: sourceAddress = R6GameServiceAddresses::TextUPDATEPLAYERPING; break; // UPDATEPLAYERPING
  case R6GameServiceAddresses::GMessageLabelTargetsCase110: sourceAddress = R6GameServiceAddresses::TextUPDATEGROUPSIZE; break; // UPDATEGROUPSIZE
  case R6GameServiceAddresses::GMessageLabelTargetsCase111: sourceAddress = R6GameServiceAddresses::TextSLEEP; break; // SLEEP
  case R6GameServiceAddresses::GMessageLabelTargetsCase112: sourceAddress = R6GameServiceAddresses::TextWAKEUP; break; // WAKEUP
  case R6GameServiceAddresses::GMessageLabelTargetsCase113: sourceAddress = R6GameServiceAddresses::TextSYSTEMPAGE; break; // SYSTEMPAGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase114: sourceAddress = R6GameServiceAddresses::TextSESSIONOPEN; break; // SESSIONOPEN
  case R6GameServiceAddresses::GMessageLabelTargetsCase115: sourceAddress = R6GameServiceAddresses::TextSESSIONCLOSE; break; // SESSIONCLOSE
  case R6GameServiceAddresses::GMessageLabelTargetsCase116: sourceAddress = R6GameServiceAddresses::TextLOGINCLANMANAGER; break; // LOGINCLANMANAGER
  case R6GameServiceAddresses::GMessageLabelTargetsCase117: sourceAddress = R6GameServiceAddresses::TextDISCONNECTCLANMANAGER; break; // DISCONNECTCLANMANAGER
  case R6GameServiceAddresses::GMessageLabelTargetsCase118: sourceAddress = R6GameServiceAddresses::TextCLANMANAGERPAGE; break; // CLANMANAGERPAGE
  case R6GameServiceAddresses::GMessageLabelTargetsCase119: sourceAddress = R6GameServiceAddresses::TextUPDATECLANPLAYER; break; // UPDATECLANPLAYER
  case R6GameServiceAddresses::GMessageLabelTargetsCase120: sourceAddress = R6GameServiceAddresses::TextPLAYERCLANS; break; // PLAYERCLANS
  case R6GameServiceAddresses::GMessageLabelTargetsCase121: sourceAddress = R6GameServiceAddresses::TextGETPERSISTANTGROUPINFO; break; // GETPERSISTANTGROUPINFO
  case R6GameServiceAddresses::GMessageLabelTargetsCase122: sourceAddress = R6GameServiceAddresses::TextUPDATEGROUPPING; break; // UPDATEGROUPPING
  case R6GameServiceAddresses::GMessageLabelTargetsCase123: sourceAddress = R6GameServiceAddresses::TextDEFERREDGAMESTARTED; break; // DEFERREDGAMESTARTED
  case R6GameServiceAddresses::GMessageLabelTargetsCase124: sourceAddress = R6GameServiceAddresses::TextBEGINCLIENTHOSTGAME; break; // BEGINCLIENTHOSTGAME
  case R6GameServiceAddresses::GMessageLabelTargetsCase125: sourceAddress = R6GameServiceAddresses::TextLOBBYMSG; break; // LOBBY_MSG
  case R6GameServiceAddresses::GMessageLabelTargetsCase126: sourceAddress = R6GameServiceAddresses::TextLOBBYSERVERLOGIN; break; // LOBBYSERVERLOGIN
  case R6GameServiceAddresses::GMessageLabelTargetsCase127: sourceAddress = R6GameServiceAddresses::TextSETGROUPSZDATA; break; // SETGROUPSZDATA
  case R6GameServiceAddresses::GMessageLabelTargetsCase128: sourceAddress = R6GameServiceAddresses::TextGROUPSZDATA; break; // GROUPSZDATA
  case R6GameServiceAddresses::GMessageLabelTargetsCase129: return (uint)sprintf(output,(const char *)R6GameServiceAddresses::TextSignedDecimalFormat,codeByte);
  }
  uint delta = (uint)output - sourceAddress;
  byte current;
  do {
    current = *(const byte *)sourceAddress;
    *(byte *)(sourceAddress + delta) = current;
    ++sourceAddress;
  } while (current != 0);
  return sourceAddress;
}

// Mask lowBYTE send target, use native table for1..5 or decimal fallback; return raw sprintf result/RET8. ECX unused.
// R6GameService.dll @ 1005bb60 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall FormatSendTarget(uint targetWord,char *output)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    and    eax,0xff
    lea    ecx,[eax-0x1]
    cmp    ecx,0x4
    ja    Branch1
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::message_label_supportGGameDiagnosticTargets]
    mov    eax,DWORD PTR [esp+0x8]
    push    R6GameServiceAddresses::TextSENDTOALLPLAYERS
    push    eax
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x8
    mov    ecx,DWORD PTR [esp+0x8]
    push    R6GameServiceAddresses::TextSENDTOOTHERPLAYERS
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x8
    mov    edx,DWORD PTR [esp+0x8]
    push    R6GameServiceAddresses::TextSENDTOPLAYERGROUP
    push    edx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x8
    mov    eax,DWORD PTR [esp+0x8]
    push    R6GameServiceAddresses::TextSENDTOPLAYER
    push    eax
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x8
    mov    ecx,DWORD PTR [esp+0x8]
    push    R6GameServiceAddresses::TextSENDTOSERVER
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x8
  Branch1:
    mov    edx,DWORD PTR [esp+0x8]
    push    eax
    push    R6GameServiceAddresses::TextSignedDecimalFormat
    push    edx
    call    R6GameServiceAddresses::sprintf
    add    esp,0xc
    ret    0x8
  }
}

// Literal native diagnostic formatter dispatch table.
// R6GameService.dll data @ 1005bbf8 : native storage identity retained.
const uint message_label_supportGGameDiagnosticTargets[5] = {
    R6GameServiceAddresses::message_label_supportGGameDiagnosticTargetsCase1,R6GameServiceAddresses::message_label_supportGGameDiagnosticTargetsCase2,R6GameServiceAddresses::message_label_supportGGameDiagnosticTargetsCase3,R6GameServiceAddresses::message_label_supportGGameDiagnosticTargetsCase4,R6GameServiceAddresses::message_label_supportGGameDiagnosticTargetsCase5
};
