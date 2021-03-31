# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_OPENCV__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector_test.cpp E:/pp4fpgas/phase_detector/HLS/phasedetector/cordiccart2pol.cpp E:/pp4fpgas/phase_detector/HLS/phasedetector/fir.cpp E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector.cpp

TARGET := csim.exe

AUTOPILOT_ROOT := D:/Xilinx/Vivado/2019.2
AUTOPILOT_MACH := win64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
ifndef AP_GCC_PATH
  AP_GCC_PATH := D:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_ROOT}/tps/win64/msys64/mingw64/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/opencv"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_OPENCV__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -g
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += 
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



$(ObjDir)/phasedetector_test.o: E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector_test.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector_test.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/phasedetector_test.d

$(ObjDir)/cordiccart2pol.o: E:/pp4fpgas/phase_detector/HLS/phasedetector/cordiccart2pol.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling E:/pp4fpgas/phase_detector/HLS/phasedetector/cordiccart2pol.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/cordiccart2pol.d

$(ObjDir)/fir.o: E:/pp4fpgas/phase_detector/HLS/phasedetector/fir.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling E:/pp4fpgas/phase_detector/HLS/phasedetector/fir.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fir.d

$(ObjDir)/phasedetector.o: E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling E:/pp4fpgas/phase_detector/HLS/phasedetector/phasedetector.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/phasedetector.d
