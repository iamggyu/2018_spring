`timescale 100ps / 100ps


module RF(
    input write,
    input clk,
    input reset_n,
    input [1:0] addr1,
    input [1:0] addr2,
    input [1:0] addr3,
    output reg [15:0] data1,
    output reg [15:0] data2,
    input [15:0] data3);
    
    reg [15:0] reg0, reg1, reg2, reg3;
    
    always @(*) begin
        if(reset_n == 0) begin
            reg0 = 0;
            reg1 = 0;
            reg2 = 0;
            reg3 = 0;
        end
        else begin
            case (addr1)
            0: data1 = reg0;
            1: data1 = reg1;
            2: data1 = reg2;
            3: data1 = reg3;
            endcase
            
            case (addr2)
            0: data2 = reg0;
            1: data2 = reg1;
            2: data2 = reg2;
            3: data2 = reg3;
            endcase
        end
    end
    
    always @(posedge clk) begin
        if (write) begin 
            case (addr3) 
            0: reg0 = data3;
            1: reg1 = data3;
            2: reg2 = data3;
            3: reg3 = data3;
            endcase
        end
    end

endmodule
