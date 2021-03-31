// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// ap_start
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of y_V
//        bit 31~0 - y_V[31:0] (Read)
// 0x14 : Control signal of y_V
//        bit 0  - y_V_ap_vld (Read/COR)
//        others - reserved
// 0x18 : Data signal of x_V
//        bit 31~0 - x_V[31:0] (Read/Write)
// 0x1c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFIR_AP_START_ADDR_AP_CTRL  0x00
#define XFIR_AP_START_ADDR_GIE      0x04
#define XFIR_AP_START_ADDR_IER      0x08
#define XFIR_AP_START_ADDR_ISR      0x0c
#define XFIR_AP_START_ADDR_Y_V_DATA 0x10
#define XFIR_AP_START_BITS_Y_V_DATA 32
#define XFIR_AP_START_ADDR_Y_V_CTRL 0x14
#define XFIR_AP_START_ADDR_X_V_DATA 0x18
#define XFIR_AP_START_BITS_X_V_DATA 32

