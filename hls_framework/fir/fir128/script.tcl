############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project baseline
set_top fir
add_files fir.cpp
add_files fir.h
add_files -tb fir_test.cpp
add_files -tb out.gold.dat
add_files -tb input.dat
open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10
