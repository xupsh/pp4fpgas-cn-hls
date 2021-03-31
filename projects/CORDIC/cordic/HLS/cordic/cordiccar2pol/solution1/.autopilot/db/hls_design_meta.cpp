#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("x", 32, hls_in, 0, "ap_none", "in_data", 1),
	Port_Property("y", 32, hls_in, 1, "ap_none", "in_data", 1),
	Port_Property("r", 32, hls_out, 2, "ap_vld", "out_data", 1),
	Port_Property("r_ap_vld", 1, hls_out, 2, "ap_vld", "out_vld", 1),
	Port_Property("theta", 32, hls_out, 3, "ap_vld", "out_data", 1),
	Port_Property("theta_ap_vld", 1, hls_out, 3, "ap_vld", "out_vld", 1),
};
const char* HLS_Design_Meta::dut_name = "cordiccart2pol";
