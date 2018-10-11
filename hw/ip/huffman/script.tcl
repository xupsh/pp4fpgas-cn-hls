open_project huffman
set_top huffman
add_files huffman/huffman.cpp
add_files huffman/huffman.h
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 7 -name default
create_clock -period 10 -name control
csynth_design
export_design -format ip_catalog -description "PP4FPGA-HLS-HUFFMAN" -display_name "Huffman"
exit
