`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/25/2018 06:56:18 PM
// Design Name: 
// Module Name: Detector_010
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Detector_010(
    input CLK,
    input in,
    output reg out);
    
    parameter firstZero = 0,
              firstOne = 1,
              ones = 2,
              endZero = 3;
              
    reg[1:0] state;
    reg[1:0] nextState;
    
    initial begin
        state <= ones;
    end
    
    always @(posedge CLK) begin
        state <= nextState;
    end
    
    always @(in or state) begin
        case(state)
            firstZero: begin
                if(in == 0) nextState <= firstZero;
                else nextState <= firstOne;
            end
            firstOne: begin
                if(in == 0) nextState <= endZero;
                else nextState <= ones;
            end
            ones: begin
                if(in == 0) nextState <= firstZero;
                else nextState <= ones;
            end
            endZero: begin
                if(in == 0) nextState <= firstZero;
                else nextState <= firstOne;
            end
        endcase
    end
    
    always @(state) begin
        out <= (state == endZero) ? 1 : 0;
    end
    
endmodule
