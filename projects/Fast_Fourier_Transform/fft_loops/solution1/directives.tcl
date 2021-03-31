############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_loop_tripcount -min 9 -max 9 "fft_streaming/stage_loop"
set_directive_loop_tripcount -min 1 -max 256 "fft_stage/butterfly_loop"
set_directive_loop_tripcount -min 2 -max 512 "fft_stage/dft_loop"
