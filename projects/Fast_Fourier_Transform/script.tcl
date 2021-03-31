############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fft_loops
set_top fft
add_files fft_stages_loop.cpp
add_files -tb fft_stages_loop_top.cpp
add_files -tb fft_streaming.h
add_files -tb out.fft.gold.dat
add_files -tb tw_i.h
add_files -tb tw_r.h
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
source "./fft_loops/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
