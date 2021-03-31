# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XFir" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_AP_START_BASEADDR" \
        "C_S_AXI_AP_START_HIGHADDR"

    xdefine_config_file $drv_handle "xfir_g.c" "XFir" \
        "DEVICE_ID" \
        "C_S_AXI_AP_START_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XFir" \
        "DEVICE_ID" \
        "C_S_AXI_AP_START_BASEADDR" \
        "C_S_AXI_AP_START_HIGHADDR"
}

