############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fir1
set_top fir
add_files C:/Users/znxnt/Desktop/fir_1/fir11/fir.h
add_files C:/Users/znxnt/Desktop/fir_1/fir11/fir.cpp
add_files -tb C:/Users/znxnt/Desktop/project1/fir11/out.gold.dat -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb C:/Users/znxnt/Desktop/project1/fir11/input.dat -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb C:/Users/znxnt/Desktop/fir_1/fir11/fir_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./fir1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
