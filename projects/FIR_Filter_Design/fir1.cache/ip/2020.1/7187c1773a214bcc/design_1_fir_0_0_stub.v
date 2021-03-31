// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Sat Jan 16 21:15:11 2021
// Host        : DESKTOP-BMH7MVV running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_fir_0_0_stub.v
// Design      : design_1_fir_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "fir,Vivado 2020.1" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(s_axi_ap_start_AWADDR, 
  s_axi_ap_start_AWVALID, s_axi_ap_start_AWREADY, s_axi_ap_start_WDATA, 
  s_axi_ap_start_WSTRB, s_axi_ap_start_WVALID, s_axi_ap_start_WREADY, 
  s_axi_ap_start_BRESP, s_axi_ap_start_BVALID, s_axi_ap_start_BREADY, 
  s_axi_ap_start_ARADDR, s_axi_ap_start_ARVALID, s_axi_ap_start_ARREADY, 
  s_axi_ap_start_RDATA, s_axi_ap_start_RRESP, s_axi_ap_start_RVALID, 
  s_axi_ap_start_RREADY, ap_clk, ap_rst_n, interrupt)
/* synthesis syn_black_box black_box_pad_pin="s_axi_ap_start_AWADDR[4:0],s_axi_ap_start_AWVALID,s_axi_ap_start_AWREADY,s_axi_ap_start_WDATA[31:0],s_axi_ap_start_WSTRB[3:0],s_axi_ap_start_WVALID,s_axi_ap_start_WREADY,s_axi_ap_start_BRESP[1:0],s_axi_ap_start_BVALID,s_axi_ap_start_BREADY,s_axi_ap_start_ARADDR[4:0],s_axi_ap_start_ARVALID,s_axi_ap_start_ARREADY,s_axi_ap_start_RDATA[31:0],s_axi_ap_start_RRESP[1:0],s_axi_ap_start_RVALID,s_axi_ap_start_RREADY,ap_clk,ap_rst_n,interrupt" */;
  input [4:0]s_axi_ap_start_AWADDR;
  input s_axi_ap_start_AWVALID;
  output s_axi_ap_start_AWREADY;
  input [31:0]s_axi_ap_start_WDATA;
  input [3:0]s_axi_ap_start_WSTRB;
  input s_axi_ap_start_WVALID;
  output s_axi_ap_start_WREADY;
  output [1:0]s_axi_ap_start_BRESP;
  output s_axi_ap_start_BVALID;
  input s_axi_ap_start_BREADY;
  input [4:0]s_axi_ap_start_ARADDR;
  input s_axi_ap_start_ARVALID;
  output s_axi_ap_start_ARREADY;
  output [31:0]s_axi_ap_start_RDATA;
  output [1:0]s_axi_ap_start_RRESP;
  output s_axi_ap_start_RVALID;
  input s_axi_ap_start_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
endmodule
