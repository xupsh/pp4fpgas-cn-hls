// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __cordiccart2pol_ancud_H__
#define __cordiccart2pol_ancud_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct cordiccart2pol_ancud_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 16;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(cordiccart2pol_ancud_ram) {
        ram[0] = "0b00111111010010010000111111011011";
        ram[1] = "0b00111110111011010110001100111000";
        ram[2] = "0b00111110011110101101101110110000";
        ram[3] = "0b00111101111111101010110111010101";
        ram[4] = "0b00111101011111111010101011011110";
        ram[5] = "0b00111100111111111110101010101110";
        ram[6] = "0b00111100011111111111101010101011";
        ram[7] = "0b00111011111111111111111010101011";
        ram[8] = "0b00111011011111111111111110101011";
        ram[9] = "0b00111010111111111111111111101011";
        ram[10] = "0b00111010011111111111111111111011";
        ram[11] = "0b00111001111111111111111111111111";
        ram[12] = "0b00111001100000000000000000000000";
        ram[13] = "0b00111001000000000000000000000000";
        ram[14] = "0b00111000100000000000000000000000";
        ram[15] = "0b00111000000000000000000000000000";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(cordiccart2pol_ancud) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


cordiccart2pol_ancud_ram* meminst;


SC_CTOR(cordiccart2pol_ancud) {
meminst = new cordiccart2pol_ancud_ram("cordiccart2pol_ancud_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~cordiccart2pol_ancud() {
    delete meminst;
}


};//endmodule
#endif
