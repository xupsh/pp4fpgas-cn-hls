// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xfir.h"

extern XFir_Config XFir_ConfigTable[];

XFir_Config *XFir_LookupConfig(u16 DeviceId) {
	XFir_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XFIR_NUM_INSTANCES; Index++) {
		if (XFir_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XFir_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XFir_Initialize(XFir *InstancePtr, u16 DeviceId) {
	XFir_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XFir_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XFir_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

