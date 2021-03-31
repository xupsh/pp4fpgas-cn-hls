#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_AWADDR", 5, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_ARADDR", 5, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_ap_start_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_ap_start_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "fir";
