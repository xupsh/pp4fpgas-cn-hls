############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project phase322
set_top phasedetector
add_files E:/pp4fpgas/phase_detector/HLS/phasedetector/cordiccart2pol.cpp
add_files E:/pp4fpgas/phase_detector/HLS/phasedetector/fir.cpp
add_files E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector.cpp
add_files -tb E:/pp4fpgas/phase_detector/HLS/phasedetector/input_i.dat
add_files -tb E:/pp4fpgas/phase_detector/HLS/phasedetector/input_q.dat
add_files -tb E:/pp4fpgas/phase_detector/HLS/phasedetector/out.gold.dat
add_files -tb E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector_test.cpp
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
#source "./phase322/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
