// RPC functions
// created: 02.01.2014 11:20:38
// This is an auto generated file
// *** DO NOT EDIT THIS FILE ***

#include "pxar_rpc.h"

const char CTestboard::rpc_timestamp[] = "02.01.2014 11:20:38";

const unsigned int CTestboard::rpc_cmdListSize = 93;

const char *CTestboard::rpc_cmdName[] =
{
	/*     0 */ "GetRpcVersion$S",
	/*     1 */ "GetRpcCallId$i3c",
	/*     2 */ "GetRpcTimestamp$v4c",
	/*     3 */ "GetRpcCallCount$i",
	/*     4 */ "GetRpcCallName$bi4c",
	/*     5 */ "GetInfo$v4c",
	/*     6 */ "GetBoardId$S",
	/*     7 */ "GetHWVersion$v4c",
	/*     8 */ "GetFWVersion$S",
	/*     9 */ "GetSWVersion$S",
	/*    10 */ "UpgradeGetVersion$S",
	/*    11 */ "UpgradeStart$CS",
	/*    12 */ "UpgradeData$C3c",
	/*    13 */ "UpgradeError$C",
	/*    14 */ "UpgradeErrorMsg$v4c",
	/*    15 */ "UpgradeExec$vS",
	/*    16 */ "Init$v",
	/*    17 */ "Welcome$v",
	/*    18 */ "SetLed$vC",
	/*    19 */ "cDelay$vS",
	/*    20 */ "uDelay$vS",
	/*    21 */ "Sig_SetMode$vCC",
	/*    22 */ "Sig_SetPRBS$vCC",
	/*    23 */ "Sig_SetDelay$vCSc",
	/*    24 */ "Sig_SetLevel$vCC",
	/*    25 */ "Sig_SetOffset$vC",
	/*    26 */ "Sig_SetLVDS$v",
	/*    27 */ "Sig_SetLCDS$v",
	/*    28 */ "SignalProbeD1$vC",
	/*    29 */ "SignalProbeD2$vC",
	/*    30 */ "SignalProbeA1$vC",
	/*    31 */ "SignalProbeA2$vC",
	/*    32 */ "SignalProbeADC$vCC",
	/*    33 */ "Pon$v",
	/*    34 */ "Poff$v",
	/*    35 */ "_SetVD$vS",
	/*    36 */ "_SetVA$vS",
	/*    37 */ "_SetID$vS",
	/*    38 */ "_SetIA$vS",
	/*    39 */ "_GetVD$S",
	/*    40 */ "_GetVA$S",
	/*    41 */ "_GetID$S",
	/*    42 */ "_GetIA$S",
	/*    43 */ "HVon$v",
	/*    44 */ "HVoff$v",
	/*    45 */ "ResetOn$v",
	/*    46 */ "ResetOff$v",
	/*    47 */ "GetStatus$C",
	/*    48 */ "SetRocAddress$vC",
	/*    49 */ "GetPixelAddressInverted$b",
	/*    50 */ "SetPixelAddressInverted$vb",
	/*    51 */ "Pg_SetCmd$vSS",
	/*    52 */ "Pg_Stop$v",
	/*    53 */ "Pg_Single$v",
	/*    54 */ "Pg_Trigger$v",
	/*    55 */ "Pg_Loop$vS",
	/*    56 */ "GetUser1Version$S",
	/*    57 */ "Daq_Open$II",
	/*    58 */ "Daq_Close$v",
	/*    59 */ "Daq_Start$v",
	/*    60 */ "Daq_Stop$v",
	/*    61 */ "Daq_GetSize$I",
	/*    62 */ "Daq_Read$C2SS",
	/*    63 */ "Daq_Read$C2SS0I",
	/*    64 */ "Daq_Select_ADC$vSCCC",
	/*    65 */ "Daq_Select_Deser160$vC",
	/*    66 */ "roc_I2cAddr$vC",
	/*    67 */ "roc_ClrCal$v",
	/*    68 */ "roc_SetDAC$vCC",
	/*    69 */ "roc_Pix$vCCC",
	/*    70 */ "roc_Pix_Trim$vCCC",
	/*    71 */ "roc_Pix_Mask$vCC",
	/*    72 */ "roc_Pix_Cal$vCCb",
	/*    73 */ "roc_Col_Enable$vCb",
	/*    74 */ "roc_Col_Mask$vC",
	/*    75 */ "roc_Chip_Mask$v",
	/*    76 */ "TBM_Present$b",
	/*    77 */ "tbm_Enable$vb",
	/*    78 */ "tbm_Addr$vCC",
	/*    79 */ "mod_Addr$vC",
	/*    80 */ "tbm_Set$vCC",
	/*    81 */ "tbm_Get$bC0C",
	/*    82 */ "tbm_GetRaw$bC0I",
	/*    83 */ "testColPixel$bCC2C",
	/*    84 */ "Ethernet_Send$v3c",
	/*    85 */ "Ethernet_RecvPackets$I",
	/*    86 */ "CountReadouts$ii",
	/*    87 */ "CountReadouts$iii",
	/*    88 */ "CountReadouts$iiii",
	/*    89 */ "PixelThreshold$iiiiiiiiiii",
	/*    90 */ "ChipThresholdConvert$iiiiiiii2i2i",
	/*    91 */ "PH$iiiis",
	/*    92 */ "test_pixel_address$bii"
};

uint16_t CTestboard::GetRpcVersion()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(0);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(0); throw; };
	return rpc_par0;
}

int32_t CTestboard::GetRpcCallId(string &rpc_par1)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(1);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_Send(*rpc_io, rpc_par1);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(1); throw; };
	return rpc_par0;
}

void CTestboard::GetRpcTimestamp(stringR &rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(2);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,0);
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(2); throw; };
}

int32_t CTestboard::GetRpcCallCount()
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(3);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(3); throw; };
	return rpc_par0;
}

bool CTestboard::GetRpcCallName(int32_t rpc_par1, stringR &rpc_par2)
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(4);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_BOOL();
	rpc_Receive(*rpc_io, rpc_par2);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(4); throw; };
	return rpc_par0;
}

void CTestboard::GetInfo(stringR &rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(5);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,0);
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(5); throw; };
}

uint16_t CTestboard::GetBoardId()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(6);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(6); throw; };
	return rpc_par0;
}

void CTestboard::GetHWVersion(stringR &rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(7);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,0);
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(7); throw; };
}

uint16_t CTestboard::GetFWVersion()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(8);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(8); throw; };
	return rpc_par0;
}

uint16_t CTestboard::GetSWVersion()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(9);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(9); throw; };
	return rpc_par0;
}

uint16_t CTestboard::UpgradeGetVersion()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(10);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(10); throw; };
	return rpc_par0;
}

uint8_t CTestboard::UpgradeStart(uint16_t rpc_par1)
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(11);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_UINT8();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(11); throw; };
	return rpc_par0;
}

uint8_t CTestboard::UpgradeData(string &rpc_par1)
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(12);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_Send(*rpc_io, rpc_par1);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_UINT8();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(12); throw; };
	return rpc_par0;
}

uint8_t CTestboard::UpgradeError()
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(13);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_UINT8();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(13); throw; };
	return rpc_par0;
}

void CTestboard::UpgradeErrorMsg(stringR &rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(14);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,0);
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(14); throw; };
}

void CTestboard::UpgradeExec(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(15);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(15); throw; };
}

void CTestboard::Init()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(16);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(16); throw; };
}

void CTestboard::Welcome()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(17);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(17); throw; };
}

void CTestboard::SetLed(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(18);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(18); throw; };
}

void CTestboard::cDelay(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(19);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(19); throw; };
}

void CTestboard::uDelay(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(20);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(20); throw; };
}

void CTestboard::Sig_SetMode(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(21);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(21); throw; };
}

void CTestboard::Sig_SetPRBS(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(22);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(22); throw; };
}

void CTestboard::Sig_SetDelay(uint8_t rpc_par1, uint16_t rpc_par2, int8_t rpc_par3)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(23);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT16(rpc_par2);
	msg.Put_INT8(rpc_par3);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(23); throw; };
}

void CTestboard::Sig_SetLevel(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(24);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(24); throw; };
}

void CTestboard::Sig_SetOffset(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(25);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(25); throw; };
}

void CTestboard::Sig_SetLVDS()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(26);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(26); throw; };
}

void CTestboard::Sig_SetLCDS()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(27);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(27); throw; };
}

void CTestboard::SignalProbeD1(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(28);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(28); throw; };
}

void CTestboard::SignalProbeD2(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(29);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(29); throw; };
}

void CTestboard::SignalProbeA1(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(30);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(30); throw; };
}

void CTestboard::SignalProbeA2(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(31);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(31); throw; };
}

void CTestboard::SignalProbeADC(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(32);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(32); throw; };
}

void CTestboard::Pon()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(33);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(33); throw; };
}

void CTestboard::Poff()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(34);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(34); throw; };
}

void CTestboard::_SetVD(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(35);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(35); throw; };
}

void CTestboard::_SetVA(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(36);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(36); throw; };
}

void CTestboard::_SetID(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(37);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(37); throw; };
}

void CTestboard::_SetIA(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(38);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(38); throw; };
}

uint16_t CTestboard::_GetVD()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(39);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(39); throw; };
	return rpc_par0;
}

uint16_t CTestboard::_GetVA()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(40);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(40); throw; };
	return rpc_par0;
}

uint16_t CTestboard::_GetID()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(41);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(41); throw; };
	return rpc_par0;
}

uint16_t CTestboard::_GetIA()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(42);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(42); throw; };
	return rpc_par0;
}

void CTestboard::HVon()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(43);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(43); throw; };
}

void CTestboard::HVoff()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(44);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(44); throw; };
}

void CTestboard::ResetOn()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(45);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(45); throw; };
}

void CTestboard::ResetOff()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(46);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(46); throw; };
}

uint8_t CTestboard::GetStatus()
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(47);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_UINT8();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(47); throw; };
	return rpc_par0;
}

void CTestboard::SetRocAddress(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(48);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(48); throw; };
}

bool CTestboard::GetPixelAddressInverted()
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(49);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_BOOL();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(49); throw; };
	return rpc_par0;
}

void CTestboard::SetPixelAddressInverted(bool rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(50);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_BOOL(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(50); throw; };
}

void CTestboard::Pg_SetCmd(uint16_t rpc_par1, uint16_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(51);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Put_UINT16(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(51); throw; };
}

void CTestboard::Pg_Stop()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(52);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(52); throw; };
}

void CTestboard::Pg_Single()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(53);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(53); throw; };
}

void CTestboard::Pg_Trigger()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(54);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(54); throw; };
}

void CTestboard::Pg_Loop(uint16_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(55);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(55); throw; };
}

uint16_t CTestboard::GetUser1Version()
{ RPC_PROFILING
	uint16_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(56);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_UINT16();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(56); throw; };
	return rpc_par0;
}

uint32_t CTestboard::Daq_Open(uint32_t rpc_par1)
{ RPC_PROFILING
	uint32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(57);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT32(rpc_par1);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_UINT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(57); throw; };
	return rpc_par0;
}

void CTestboard::Daq_Close()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(58);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(58); throw; };
}

void CTestboard::Daq_Start()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(59);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(59); throw; };
}

void CTestboard::Daq_Stop()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(60);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(60); throw; };
}

uint32_t CTestboard::Daq_GetSize()
{ RPC_PROFILING
	uint32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(61);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_UINT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(61); throw; };
	return rpc_par0;
}

uint8_t CTestboard::Daq_Read(vectorR<uint16_t> &rpc_par1, uint16_t rpc_par2)
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(62);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_UINT8();
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(62); throw; };
	return rpc_par0;
}

uint8_t CTestboard::Daq_Read(vectorR<uint16_t> &rpc_par1, uint16_t rpc_par2, uint32_t &rpc_par3)
{ RPC_PROFILING
	uint8_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(63);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par2);
	msg.Put_UINT32(rpc_par3);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,5);
	rpc_par0 = msg.Get_UINT8();
	rpc_par3 = msg.Get_UINT32();
	rpc_Receive(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(63); throw; };
	return rpc_par0;
}

void CTestboard::Daq_Select_ADC(uint16_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3, uint8_t rpc_par4)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(64);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT16(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Put_UINT8(rpc_par3);
	msg.Put_UINT8(rpc_par4);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(64); throw; };
}

void CTestboard::Daq_Select_Deser160(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(65);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(65); throw; };
}

void CTestboard::roc_I2cAddr(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(66);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(66); throw; };
}

void CTestboard::roc_ClrCal()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(67);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(67); throw; };
}

void CTestboard::roc_SetDAC(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(68);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(68); throw; };
}

void CTestboard::roc_Pix(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(69);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Put_UINT8(rpc_par3);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(69); throw; };
}

void CTestboard::roc_Pix_Trim(uint8_t rpc_par1, uint8_t rpc_par2, uint8_t rpc_par3)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(70);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Put_UINT8(rpc_par3);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(70); throw; };
}

void CTestboard::roc_Pix_Mask(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(71);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(71); throw; };
}

void CTestboard::roc_Pix_Cal(uint8_t rpc_par1, uint8_t rpc_par2, bool rpc_par3)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(72);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Put_BOOL(rpc_par3);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(72); throw; };
}

void CTestboard::roc_Col_Enable(uint8_t rpc_par1, bool rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(73);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_BOOL(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(73); throw; };
}

void CTestboard::roc_Col_Mask(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(74);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(74); throw; };
}

void CTestboard::roc_Chip_Mask()
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(75);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(75); throw; };
}

bool CTestboard::TBM_Present()
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(76);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_BOOL();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(76); throw; };
	return rpc_par0;
}

void CTestboard::tbm_Enable(bool rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(77);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_BOOL(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(77); throw; };
}

void CTestboard::tbm_Addr(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(78);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(78); throw; };
}

void CTestboard::mod_Addr(uint8_t rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(79);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(79); throw; };
}

void CTestboard::tbm_Set(uint8_t rpc_par1, uint8_t rpc_par2)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(80);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(80); throw; };
}

bool CTestboard::tbm_Get(uint8_t rpc_par1, uint8_t &rpc_par2)
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(81);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,2);
	rpc_par0 = msg.Get_BOOL();
	rpc_par2 = msg.Get_UINT8();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(81); throw; };
	return rpc_par0;
}

bool CTestboard::tbm_GetRaw(uint8_t rpc_par1, uint32_t &rpc_par2)
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(82);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT32(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,5);
	rpc_par0 = msg.Get_BOOL();
	rpc_par2 = msg.Get_UINT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(82); throw; };
	return rpc_par0;
}

bool CTestboard::testColPixel(uint8_t rpc_par1, uint8_t rpc_par2, vectorR<uint8_t> &rpc_par3)
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(83);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_UINT8(rpc_par1);
	msg.Put_UINT8(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_BOOL();
	rpc_Receive(*rpc_io, rpc_par3);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(83); throw; };
	return rpc_par0;
}

void CTestboard::Ethernet_Send(string &rpc_par1)
{ RPC_PROFILING
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(84);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_Send(*rpc_io, rpc_par1);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(84); throw; };
}

uint32_t CTestboard::Ethernet_RecvPackets()
{ RPC_PROFILING
	uint32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(85);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_UINT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(85); throw; };
	return rpc_par0;
}

int32_t CTestboard::CountReadouts(int32_t rpc_par1)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(86);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(86); throw; };
	return rpc_par0;
}

int32_t CTestboard::CountReadouts(int32_t rpc_par1, int32_t rpc_par2)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(87);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(87); throw; };
	return rpc_par0;
}

int32_t CTestboard::CountReadouts(int32_t rpc_par1, int32_t rpc_par2, int32_t rpc_par3)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(88);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Put_INT32(rpc_par3);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(88); throw; };
	return rpc_par0;
}

int32_t CTestboard::PixelThreshold(int32_t rpc_par1, int32_t rpc_par2, int32_t rpc_par3, int32_t rpc_par4, int32_t rpc_par5, int32_t rpc_par6, int32_t rpc_par7, int32_t rpc_par8, int32_t rpc_par9, int32_t rpc_par10)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(89);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Put_INT32(rpc_par3);
	msg.Put_INT32(rpc_par4);
	msg.Put_INT32(rpc_par5);
	msg.Put_INT32(rpc_par6);
	msg.Put_INT32(rpc_par7);
	msg.Put_INT32(rpc_par8);
	msg.Put_INT32(rpc_par9);
	msg.Put_INT32(rpc_par10);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(89); throw; };
	return rpc_par0;
}

int32_t CTestboard::ChipThresholdConvert(int32_t rpc_par1, int32_t rpc_par2, int32_t rpc_par3, int32_t rpc_par4, int32_t rpc_par5, int32_t rpc_par6, int32_t rpc_par7, vectorR<int32_t> &rpc_par8, vectorR<int32_t> &rpc_par9)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(90);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Put_INT32(rpc_par3);
	msg.Put_INT32(rpc_par4);
	msg.Put_INT32(rpc_par5);
	msg.Put_INT32(rpc_par6);
	msg.Put_INT32(rpc_par7);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	rpc_Receive(*rpc_io, rpc_par8);
	rpc_Receive(*rpc_io, rpc_par9);
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(90); throw; };
	return rpc_par0;
}

int32_t CTestboard::PH(int32_t rpc_par1, int32_t rpc_par2, int32_t rpc_par3, int16_t rpc_par4)
{ RPC_PROFILING
	int32_t rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(91);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Put_INT32(rpc_par3);
	msg.Put_INT16(rpc_par4);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,4);
	rpc_par0 = msg.Get_INT32();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(91); throw; };
	return rpc_par0;
}

bool CTestboard::test_pixel_address(int32_t rpc_par1, int32_t rpc_par2)
{ RPC_PROFILING
	bool rpc_par0;
	try {
	uint16_t rpc_clientCallId = rpc_GetCallId(92);
	RPC_THREAD_LOCK
	rpcMessage msg;
	msg.Create(rpc_clientCallId);
	msg.Put_INT32(rpc_par1);
	msg.Put_INT32(rpc_par2);
	msg.Send(*rpc_io);
	rpc_io->Flush();
	msg.Receive(*rpc_io);
	msg.Check(rpc_clientCallId,1);
	rpc_par0 = msg.Get_BOOL();
	RPC_THREAD_UNLOCK
	} catch (CRpcError &e) { e.SetFunction(92); throw; };
	return rpc_par0;
}

