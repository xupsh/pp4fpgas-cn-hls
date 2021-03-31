-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
-- Date        : Sat Jan 16 21:15:12 2021
-- Host        : DESKTOP-BMH7MVV running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               e:/xilinx/framework/fir1/fir1.srcs/sources_1/bd/design_1/ip/design_1_fir_0_0/design_1_fir_0_0_stub.vhdl
-- Design      : design_1_fir_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_fir_0_0 is
  Port ( 
    s_axi_ap_start_AWADDR : in STD_LOGIC_VECTOR ( 4 downto 0 );
    s_axi_ap_start_AWVALID : in STD_LOGIC;
    s_axi_ap_start_AWREADY : out STD_LOGIC;
    s_axi_ap_start_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_ap_start_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_ap_start_WVALID : in STD_LOGIC;
    s_axi_ap_start_WREADY : out STD_LOGIC;
    s_axi_ap_start_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_ap_start_BVALID : out STD_LOGIC;
    s_axi_ap_start_BREADY : in STD_LOGIC;
    s_axi_ap_start_ARADDR : in STD_LOGIC_VECTOR ( 4 downto 0 );
    s_axi_ap_start_ARVALID : in STD_LOGIC;
    s_axi_ap_start_ARREADY : out STD_LOGIC;
    s_axi_ap_start_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_ap_start_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_ap_start_RVALID : out STD_LOGIC;
    s_axi_ap_start_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC
  );

end design_1_fir_0_0;

architecture stub of design_1_fir_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_ap_start_AWADDR[4:0],s_axi_ap_start_AWVALID,s_axi_ap_start_AWREADY,s_axi_ap_start_WDATA[31:0],s_axi_ap_start_WSTRB[3:0],s_axi_ap_start_WVALID,s_axi_ap_start_WREADY,s_axi_ap_start_BRESP[1:0],s_axi_ap_start_BVALID,s_axi_ap_start_BREADY,s_axi_ap_start_ARADDR[4:0],s_axi_ap_start_ARVALID,s_axi_ap_start_ARREADY,s_axi_ap_start_RDATA[31:0],s_axi_ap_start_RRESP[1:0],s_axi_ap_start_RVALID,s_axi_ap_start_RREADY,ap_clk,ap_rst_n,interrupt";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "fir,Vivado 2020.1";
begin
end;
