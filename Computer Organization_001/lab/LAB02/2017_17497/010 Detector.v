`timescale 100ps / 100ps

module detector(
    input clk,
    input in,
    output reg out
    );
    
    parameter firstZero = 0,
              firstOne = 1,
              ones = 2,
              endZero = 3;
              
    reg[1:0] state;
    reg[1:0] nextState;
    
    initial begin
        state <= ones;
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
    
    always @(posedge clk) begin
        state <= nextState;
    end
    
    always @(state) begin
        out <= (state == endZero) ? 1 : 0;
    end
    
endmodule
