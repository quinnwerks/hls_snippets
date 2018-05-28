// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XTESTPR_H
#define XTESTPR_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xtestpr_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XTestpr_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XTestpr;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XTestpr_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XTestpr_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XTestpr_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XTestpr_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XTestpr_Initialize(XTestpr *InstancePtr, u16 DeviceId);
XTestpr_Config* XTestpr_LookupConfig(u16 DeviceId);
int XTestpr_CfgInitialize(XTestpr *InstancePtr, XTestpr_Config *ConfigPtr);
#else
int XTestpr_Initialize(XTestpr *InstancePtr, const char* InstanceName);
int XTestpr_Release(XTestpr *InstancePtr);
#endif

void XTestpr_Start(XTestpr *InstancePtr);
u32 XTestpr_IsDone(XTestpr *InstancePtr);
u32 XTestpr_IsIdle(XTestpr *InstancePtr);
u32 XTestpr_IsReady(XTestpr *InstancePtr);
void XTestpr_EnableAutoRestart(XTestpr *InstancePtr);
void XTestpr_DisableAutoRestart(XTestpr *InstancePtr);


void XTestpr_InterruptGlobalEnable(XTestpr *InstancePtr);
void XTestpr_InterruptGlobalDisable(XTestpr *InstancePtr);
void XTestpr_InterruptEnable(XTestpr *InstancePtr, u32 Mask);
void XTestpr_InterruptDisable(XTestpr *InstancePtr, u32 Mask);
void XTestpr_InterruptClear(XTestpr *InstancePtr, u32 Mask);
u32 XTestpr_InterruptGetEnabled(XTestpr *InstancePtr);
u32 XTestpr_InterruptGetStatus(XTestpr *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif