set moduleName fir
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fir}
set C_modelType { void 0 }
set C_modelArgList {
	{ y_V int 32 regular {axi_slave 1}  }
	{ x_V int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "y_V", "interface" : "axi_slave", "bundle":"ap_start","type":"ap_vld","bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "y.V","cData": "int32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}], "offset" : {"out":16}, "offset_end" : {"out":23}} , 
 	{ "Name" : "x_V", "interface" : "axi_slave", "bundle":"ap_start","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "x.V","cData": "int32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_ap_start_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ap_start_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ap_start_AWADDR sc_in sc_lv 5 signal -1 } 
	{ s_axi_ap_start_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ap_start_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ap_start_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_ap_start_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_ap_start_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ap_start_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ap_start_ARADDR sc_in sc_lv 5 signal -1 } 
	{ s_axi_ap_start_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ap_start_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ap_start_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_ap_start_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_ap_start_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ap_start_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ap_start_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_ap_start_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "ap_start", "role": "AWADDR" },"address":[{"name":"fir","role":"start","value":"0","valid_bit":"0"},{"name":"fir","role":"continue","value":"0","valid_bit":"4"},{"name":"fir","role":"auto_start","value":"0","valid_bit":"7"},{"name":"x_V","role":"data","value":"24"}] },
	{ "name": "s_axi_ap_start_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "AWVALID" } },
	{ "name": "s_axi_ap_start_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "AWREADY" } },
	{ "name": "s_axi_ap_start_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "WVALID" } },
	{ "name": "s_axi_ap_start_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "WREADY" } },
	{ "name": "s_axi_ap_start_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ap_start", "role": "WDATA" } },
	{ "name": "s_axi_ap_start_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ap_start", "role": "WSTRB" } },
	{ "name": "s_axi_ap_start_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "ap_start", "role": "ARADDR" },"address":[{"name":"fir","role":"start","value":"0","valid_bit":"0"},{"name":"fir","role":"done","value":"0","valid_bit":"1"},{"name":"fir","role":"idle","value":"0","valid_bit":"2"},{"name":"fir","role":"ready","value":"0","valid_bit":"3"},{"name":"fir","role":"auto_start","value":"0","valid_bit":"7"},{"name":"y_V","role":"data","value":"16"}, {"name":"y_V","role":"valid","value":"20","valid_bit":"0"}] },
	{ "name": "s_axi_ap_start_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "ARVALID" } },
	{ "name": "s_axi_ap_start_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "ARREADY" } },
	{ "name": "s_axi_ap_start_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "RVALID" } },
	{ "name": "s_axi_ap_start_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "RREADY" } },
	{ "name": "s_axi_ap_start_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ap_start", "role": "RDATA" } },
	{ "name": "s_axi_ap_start_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ap_start", "role": "RRESP" } },
	{ "name": "s_axi_ap_start_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "BVALID" } },
	{ "name": "s_axi_ap_start_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "BREADY" } },
	{ "name": "s_axi_ap_start_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ap_start", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_start", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "fir",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "3", "EstimateLatencyMax" : "3",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "y_V", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "shift_reg_V_9", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_8", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_7", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_6", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_4", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "shift_reg_V_0", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fir_ap_start_s_axi_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fir {
		y_V {Type O LastRead -1 FirstWrite 3}
		x_V {Type I LastRead 0 FirstWrite -1}
		shift_reg_V_9 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_8 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_7 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_6 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_5 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_4 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_3 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_2 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_1 {Type IO LastRead -1 FirstWrite -1}
		shift_reg_V_0 {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "3", "Max" : "3"}
	, {"Name" : "Interval", "Min" : "4", "Max" : "4"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
