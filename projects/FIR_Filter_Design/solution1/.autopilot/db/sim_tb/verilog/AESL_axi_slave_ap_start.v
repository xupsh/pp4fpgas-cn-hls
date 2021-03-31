// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps

module AESL_axi_slave_ap_start (
    clk,
    reset,
    TRAN_s_axi_ap_start_AWADDR,
    TRAN_s_axi_ap_start_AWVALID,
    TRAN_s_axi_ap_start_AWREADY,
    TRAN_s_axi_ap_start_WVALID,
    TRAN_s_axi_ap_start_WREADY,
    TRAN_s_axi_ap_start_WDATA,
    TRAN_s_axi_ap_start_WSTRB,
    TRAN_s_axi_ap_start_ARADDR,
    TRAN_s_axi_ap_start_ARVALID,
    TRAN_s_axi_ap_start_ARREADY,
    TRAN_s_axi_ap_start_RVALID,
    TRAN_s_axi_ap_start_RREADY,
    TRAN_s_axi_ap_start_RDATA,
    TRAN_s_axi_ap_start_RRESP,
    TRAN_s_axi_ap_start_BVALID,
    TRAN_s_axi_ap_start_BREADY,
    TRAN_s_axi_ap_start_BRESP,
    TRAN_ap_start_write_data_finish,
    TRAN_ap_start_read_data_finish,
    TRAN_ap_start_start_in,
    TRAN_ap_start_idle_out,
    TRAN_ap_start_ready_out,
    TRAN_ap_start_ready_in,
    TRAN_ap_start_done_out,
    TRAN_ap_start_write_start_in   ,
    TRAN_ap_start_write_start_finish,
    TRAN_ap_start_interrupt,
    TRAN_ap_start_transaction_done_in
    );

//------------------------Parameter----------------------
`define TV_OUT_y_V "./rtl.fir.autotvout_y_V.dat"
`define TV_IN_x_V "./c.fir.autotvin_x_V.dat"
parameter ADDR_WIDTH = 5;
parameter DATA_WIDTH = 32;
parameter y_V_DEPTH = 1;
reg [31 : 0] y_V_OPERATE_DEPTH = 0;
parameter y_V_c_bitwidth = 32;
parameter x_V_DEPTH = 1;
reg [31 : 0] x_V_OPERATE_DEPTH = 0;
parameter x_V_c_bitwidth = 32;
parameter START_ADDR = 0;
parameter fir_continue_addr = 0;
parameter fir_auto_start_addr = 0;
parameter x_V_data_in_addr = 24;
parameter y_V_data_out_addr = 16;
parameter y_V_valid_out_addr = 20;
parameter STATUS_ADDR = 0;

output [ADDR_WIDTH - 1 : 0] TRAN_s_axi_ap_start_AWADDR;
output  TRAN_s_axi_ap_start_AWVALID;
input  TRAN_s_axi_ap_start_AWREADY;
output  TRAN_s_axi_ap_start_WVALID;
input  TRAN_s_axi_ap_start_WREADY;
output [DATA_WIDTH - 1 : 0] TRAN_s_axi_ap_start_WDATA;
output [DATA_WIDTH/8 - 1 : 0] TRAN_s_axi_ap_start_WSTRB;
output [ADDR_WIDTH - 1 : 0] TRAN_s_axi_ap_start_ARADDR;
output  TRAN_s_axi_ap_start_ARVALID;
input  TRAN_s_axi_ap_start_ARREADY;
input  TRAN_s_axi_ap_start_RVALID;
output  TRAN_s_axi_ap_start_RREADY;
input [DATA_WIDTH - 1 : 0] TRAN_s_axi_ap_start_RDATA;
input [2 - 1 : 0] TRAN_s_axi_ap_start_RRESP;
input  TRAN_s_axi_ap_start_BVALID;
output  TRAN_s_axi_ap_start_BREADY;
input [2 - 1 : 0] TRAN_s_axi_ap_start_BRESP;
output TRAN_ap_start_write_data_finish;
output TRAN_ap_start_read_data_finish;
input     clk;
input     reset;
input     TRAN_ap_start_start_in;
output    TRAN_ap_start_done_out;
output    TRAN_ap_start_ready_out;
input     TRAN_ap_start_ready_in;
output    TRAN_ap_start_idle_out;
input  TRAN_ap_start_write_start_in   ;
output TRAN_ap_start_write_start_finish;
input     TRAN_ap_start_interrupt;
input     TRAN_ap_start_transaction_done_in;

reg [ADDR_WIDTH - 1 : 0] AWADDR_reg = 0;
reg  AWVALID_reg = 0;
reg  WVALID_reg = 0;
reg [DATA_WIDTH - 1 : 0] WDATA_reg = 0;
reg [DATA_WIDTH/8 - 1 : 0] WSTRB_reg = 0;
reg [ADDR_WIDTH - 1 : 0] ARADDR_reg = 0;
reg  ARVALID_reg = 0;
reg  RREADY_reg = 0;
reg [DATA_WIDTH - 1 : 0] RDATA_reg = 0;
reg  BREADY_reg = 0;
reg [DATA_WIDTH - 1 : 0] mem_y_V [y_V_DEPTH - 1 : 0];
reg y_V_read_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_x_V [x_V_DEPTH - 1 : 0];
reg x_V_write_data_finish;
reg AESL_ready_out_index_reg = 0;
reg AESL_write_start_finish = 0;
reg AESL_ready_reg;
reg ready_initial;
reg AESL_done_index_reg = 0;
reg AESL_idle_index_reg = 0;
reg AESL_auto_restart_index_reg;
reg process_0_finish = 0;
reg process_1_finish = 0;
reg process_2_finish = 0;
reg process_3_finish = 0;
//write x_V reg
reg [31 : 0] write_x_V_count = 0;
reg write_x_V_run_flag = 0;
reg write_one_x_V_data_done = 0;
//read y_V reg
reg [31 : 0] read_y_V_count = 0;
reg read_y_V_run_flag = 0;
reg read_one_y_V_data_done = 0;
reg [31 : 0] write_start_count = 0;
reg write_start_run_flag = 0;

//===================process control=================
reg [31 : 0] ongoing_process_number = 0;
//process number depends on how much processes needed.
reg process_busy = 0;

//=================== signal connection ==============
assign TRAN_s_axi_ap_start_AWADDR = AWADDR_reg;
assign TRAN_s_axi_ap_start_AWVALID = AWVALID_reg;
assign TRAN_s_axi_ap_start_WVALID = WVALID_reg;
assign TRAN_s_axi_ap_start_WDATA = WDATA_reg;
assign TRAN_s_axi_ap_start_WSTRB = WSTRB_reg;
assign TRAN_s_axi_ap_start_ARADDR = ARADDR_reg;
assign TRAN_s_axi_ap_start_ARVALID = ARVALID_reg;
assign TRAN_s_axi_ap_start_RREADY = RREADY_reg;
assign TRAN_s_axi_ap_start_BREADY = BREADY_reg;
assign TRAN_ap_start_write_start_finish = AESL_write_start_finish;
assign TRAN_ap_start_done_out = AESL_done_index_reg;
assign TRAN_ap_start_ready_out = AESL_ready_out_index_reg;
assign TRAN_ap_start_idle_out = AESL_idle_index_reg;
assign TRAN_ap_start_read_data_finish = 1 & y_V_read_data_finish;
assign TRAN_ap_start_write_data_finish = 1 & x_V_write_data_finish;
always @(TRAN_ap_start_ready_in or ready_initial) 
begin
    AESL_ready_reg <= TRAN_ap_start_ready_in | ready_initial;
end

always @(reset or process_0_finish or process_1_finish or process_2_finish or process_3_finish ) begin
    if (reset == 0) begin
        ongoing_process_number <= 0;
    end
    else if (ongoing_process_number == 0 && process_0_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 1 && process_1_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 2 && process_2_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 3 && process_3_finish == 1) begin
            ongoing_process_number <= 0;
    end
end

task count_c_data_four_byte_num_by_bitwidth;
input  integer bitwidth;
output integer num;
integer factor;
integer i;
begin
    factor = 32;
    for (i = 1; i <= 32; i = i + 1) begin
        if (bitwidth <= factor && bitwidth > factor - 32) begin
            num = i;
        end
        factor = factor + 32;
    end
end    
endtask

task count_seperate_factor_by_bitwidth;
input  integer bitwidth;
output integer factor;
begin
    if (bitwidth <= 8 ) begin
        factor=4;
    end
    if (bitwidth <= 16 & bitwidth > 8 ) begin
        factor=2;
    end
    if (bitwidth <= 32 & bitwidth > 16 ) begin
        factor=1;
    end
    if (bitwidth <= 1024 & bitwidth > 32 ) begin
        factor=1;
    end
end    
endtask

task count_operate_depth_by_bitwidth_and_depth;
input  integer bitwidth;
input  integer depth;
output integer operate_depth;
integer factor;
integer remain;
begin
    count_seperate_factor_by_bitwidth (bitwidth , factor);
    operate_depth = depth / factor;
    remain = depth % factor;
    if (remain > 0) begin
        operate_depth = operate_depth + 1;
    end
end    
endtask

task write; /*{{{*/
    input  reg [ADDR_WIDTH - 1:0] waddr;   // write address
    input  reg [DATA_WIDTH - 1:0] wdata;   // write data
    output reg wresp;
    reg aw_flag;
    reg w_flag;
    reg [DATA_WIDTH/8 - 1:0] wstrb_reg;
    integer i;
begin 
    wresp = 0;
    aw_flag = 0;
    w_flag = 0;
//=======================one single write operate======================
    AWADDR_reg <= waddr;
    AWVALID_reg <= 1;
    WDATA_reg <= wdata;
    WVALID_reg <= 1;
    for (i = 0; i < DATA_WIDTH/8; i = i + 1) begin
        wstrb_reg [i] = 1;
    end    
    WSTRB_reg <= wstrb_reg;
    while (!(aw_flag && w_flag)) begin
        @(posedge clk);
        if (aw_flag != 1)
            aw_flag = TRAN_s_axi_ap_start_AWREADY & AWVALID_reg;
        if (w_flag != 1)
            w_flag = TRAN_s_axi_ap_start_WREADY & WVALID_reg;
        AWVALID_reg <= !aw_flag;
        WVALID_reg <= !w_flag;
    end

    BREADY_reg <= 1;
    while (TRAN_s_axi_ap_start_BVALID != 1) begin
        //wait for response 
        @(posedge clk);
    end
    @(posedge clk);
    BREADY_reg <= 0;
    if (TRAN_s_axi_ap_start_BRESP === 2'b00) begin
        wresp = 1;
        //input success. in fact BRESP is always 2'b00
    end   
//=======================one single write operate======================

end
endtask/*}}}*/

task read (/*{{{*/
    input  [ADDR_WIDTH - 1:0] raddr ,   // write address
    output [DATA_WIDTH - 1:0] RDATA_result ,
    output rresp
);
begin 
    rresp = 0;
//=======================one single read operate======================
    ARADDR_reg <= raddr;
    ARVALID_reg <= 1;
    while (TRAN_s_axi_ap_start_ARREADY !== 1) begin
        @(posedge clk);
    end
    @(posedge clk);
    ARVALID_reg <= 0;
    RREADY_reg <= 1;
    while (TRAN_s_axi_ap_start_RVALID !== 1) begin
        //wait for response 
        @(posedge clk);
    end
    @(posedge clk);
    RDATA_result  <= TRAN_s_axi_ap_start_RDATA;
    RREADY_reg <= 0;
    if (TRAN_s_axi_ap_start_RRESP === 2'b00 ) begin
        rresp <= 1;
        //output success. in fact RRESP is always 2'b00
    end  
    @(posedge clk);

//=======================one single read operate end======================

end
endtask/*}}}*/

initial begin : ready_initial_process
    ready_initial = 0;
    wait(reset === 1);
    @(posedge clk);
    ready_initial = 1;
    @(posedge clk);
    ready_initial = 0;
end

initial begin : update_status
    integer process_num ;
    integer read_status_resp;
    wait(reset === 1);
    @(posedge clk);
    process_num = 0;
    while (1) begin
        process_0_finish = 0;
        AESL_done_index_reg         <= 0;
        AESL_ready_out_index_reg        <= 0;
        if (ongoing_process_number === process_num && process_busy === 0) begin
            process_busy = 1;
            read (STATUS_ADDR, RDATA_reg, read_status_resp);
                AESL_done_index_reg         <= RDATA_reg[1 : 1];
                AESL_ready_out_index_reg    <= RDATA_reg[1 : 1];
                AESL_idle_index_reg         <= RDATA_reg[2 : 2];
            process_0_finish = 1;
            process_busy = 0;
        end 
        @(posedge clk);
    end
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        x_V_write_data_finish <= 0;
        write_x_V_run_flag <= 0; 
        write_x_V_count = 0;
        count_operate_depth_by_bitwidth_and_depth (x_V_c_bitwidth, x_V_DEPTH, x_V_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_ap_start_start_in === 1) begin
            x_V_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_x_V_run_flag <= 1; 
            write_x_V_count = 0;
        end
        if (write_one_x_V_data_done === 1) begin
            write_x_V_count = write_x_V_count + 1;
            if (write_x_V_count == x_V_OPERATE_DEPTH) begin
                write_x_V_run_flag <= 0; 
                x_V_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_x_V
    integer write_x_V_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] x_V_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = x_V_c_bitwidth;
    process_num = 1;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_1_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_x_V_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write x_V data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (x_V_c_bitwidth < 32) begin
                        x_V_data_tmp_reg = mem_x_V[write_x_V_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < x_V_c_bitwidth) begin
                                x_V_data_tmp_reg[j] = mem_x_V[write_x_V_count][i*32 + j];
                            end
                            else begin
                                x_V_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (x_V_data_in_addr + write_x_V_count * four_byte_num * 4 + i * 4, x_V_data_tmp_reg, write_x_V_resp);
                end
                process_busy = 0;
                write_one_x_V_data_done <= 1;
                @(posedge clk);
                write_one_x_V_data_done <= 0;
            end   
            process_1_finish <= 1;
        end
        @(posedge clk);
    end    
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        write_start_run_flag <= 0; 
        write_start_count <= 0;
    end
    else begin
        if (write_start_count >= 20) begin
            write_start_run_flag <= 0; 
        end
        else if (TRAN_ap_start_write_start_in === 1) begin
            write_start_run_flag <= 1; 
        end
        if (AESL_write_start_finish === 1) begin
            write_start_count <= write_start_count + 1;
            write_start_run_flag <= 0; 
        end
    end
end

initial begin : write_start
    reg [DATA_WIDTH - 1 : 0] write_start_tmp;
    integer process_num;
    integer write_start_resp;
    wait(reset === 1);
    @(posedge clk);
    process_num = 2;
    while (1) begin
        process_2_finish = 0;
        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            if (write_start_run_flag === 1) begin
                process_busy = 1;
                write_start_tmp=0;
                write_start_tmp[0 : 0] = 1;
                write (START_ADDR, write_start_tmp, write_start_resp);
                process_busy = 0;
                AESL_write_start_finish <= 1;
                @(posedge clk);
                AESL_write_start_finish <= 0;
            end
            process_2_finish <= 1;
        end 
        @(posedge clk);
    end
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        y_V_read_data_finish <= 0;
        read_y_V_run_flag <= 0; 
        read_y_V_count = 0;
        count_operate_depth_by_bitwidth_and_depth (y_V_c_bitwidth, y_V_DEPTH, y_V_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_ap_start_start_in === 1) begin
            read_y_V_run_flag = 1; 
        end
        if (TRAN_ap_start_transaction_done_in === 1) begin
            y_V_read_data_finish <= 0;
            read_y_V_count = 0; 
        end
        if (read_one_y_V_data_done === 1) begin
            read_y_V_count = read_y_V_count + 1;
            if (read_y_V_count == y_V_OPERATE_DEPTH) begin
                read_y_V_run_flag <= 0; 
                y_V_read_data_finish <= 1;
            end
        end
    end
end

initial begin : read_y_V
    integer read_y_V_resp;
    integer process_num;
    integer get_vld;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;

    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = y_V_c_bitwidth;
    process_num = 3;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_3_finish <= 0;
        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            if (read_y_V_run_flag === 1) begin
                process_busy = 1;
                get_vld = 0;
                //read y_V vld
                read (y_V_valid_out_addr, RDATA_reg, read_y_V_resp);
                if (RDATA_reg[0 : 0] == 1) begin
                    get_vld = 1;
                end
                if (get_vld == 1) begin
                    //read y_V data 
                    for (i = 0 ; i < four_byte_num ; i = i+1) begin
                        read (y_V_data_out_addr + read_y_V_count * four_byte_num * 4 + i * 4, RDATA_reg, read_y_V_resp);
                        if (y_V_c_bitwidth < 32) begin
                            mem_y_V[read_y_V_count] <= RDATA_reg;
                        end
                        else begin
                            for (j=0 ; j < 32 ; j = j + 1) begin
                                if (i*32 + j < y_V_c_bitwidth) begin
                                    mem_y_V[read_y_V_count][i*32 + j] <= RDATA_reg[j];
                                end
                            end
                        end
                    end
                    
                    read_one_y_V_data_done <= 1;
                    @(posedge clk);
                    read_one_y_V_data_done <= 0;
                end    
                process_busy = 0;
            end    
            process_3_finish <= 1;
        end
        @(posedge clk);
    end    
end
//------------------------Task and function-------------- 
task read_token; 
    input integer fp; 
    output reg [127 : 0] token;
    integer ret;
    begin
        token = "";
        ret = 0;
        ret = $fscanf(fp,"%s",token);
    end 
endtask 
 
//------------------------Write file----------------------- 
 
// Write data to file 
 
initial begin : write_y_V_file_proc 
  integer fp; 
  integer factor; 
  integer transaction_idx; 
  reg [y_V_c_bitwidth - 1 : 0] mem_tmp; 
  reg [ 100*8 : 1] str;
  integer i; 
  transaction_idx = 0; 
  count_seperate_factor_by_bitwidth (y_V_c_bitwidth , factor);
  while(1) begin 
      @(posedge clk);
      while (y_V_read_data_finish !== 1) begin
          @(posedge clk);
      end
      # 0.1;
      fp = $fopen(`TV_OUT_y_V, "a"); 
      if(fp == 0) begin       // Failed to open file 
          $display("Failed to open file \"%s\"!", `TV_OUT_y_V); 
          $finish; 
      end 
      $fdisplay(fp, "[[transaction]] %d", transaction_idx);
      for (i = 0; i < (y_V_DEPTH - y_V_DEPTH % factor); i = i + 1) begin
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp = mem_y_V[i/factor][7:0];
              end
              if (i%factor == 1) begin
                  mem_tmp = mem_y_V[i/factor][15:8];
              end
              if (i%factor == 2) begin
                  mem_tmp = mem_y_V[i/factor][23:16];
              end
              if (i%factor == 3) begin
                  mem_tmp = mem_y_V[i/factor][31:24];
              end
              $fdisplay(fp,"0x%x",mem_tmp);
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp = mem_y_V[i/factor][15:0];
              end
              if (i%factor == 1) begin
                  mem_tmp = mem_y_V[i/factor][31:16];
              end
              $fdisplay(fp,"0x%x",mem_tmp);
          end
          if (factor == 1) begin
              $fdisplay(fp,"0x%x",mem_y_V[i]);
          end
      end 
      if (factor == 4) begin
          if ((y_V_DEPTH - 1) % factor == 2) begin
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][7:0]);
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][15:8]);
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][23:16]);
          end
          if ((y_V_DEPTH - 1) % factor == 1) begin
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][7:0]);
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][15:8]);
          end
          if ((y_V_DEPTH - 1) % factor == 0) begin
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][7:0]);
          end
      end
      if (factor == 2) begin
          if ((y_V_DEPTH - 1) % factor == 0) begin
              $fdisplay(fp,"0x%x",mem_y_V[y_V_DEPTH / factor][15:0]);
          end
      end
      $fdisplay(fp, "[[/transaction]]");
      transaction_idx = transaction_idx + 1;
      $fclose(fp); 
      while (TRAN_ap_start_start_in !== 1) begin
          @(posedge clk);
      end
  end 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_x_V_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [x_V_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (x_V_c_bitwidth , factor);
  fp = $fopen(`TV_IN_x_V ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_x_V); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < x_V_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_x_V [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_x_V [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_x_V [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_x_V [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_x_V [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
endmodule
