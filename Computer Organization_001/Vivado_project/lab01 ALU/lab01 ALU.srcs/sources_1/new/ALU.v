`timescale 100ps / 100ps

// TODO : You should specify your ALU's OPCODE.	   
// Arithmetic
`define	OP_ADD	4'b0000
`define	OP_SUB	4'b0001
//  Bitwise Boolean operation
`define	OP_ID	4'b0010
`define	OP_NAND	4'b0011
`define	OP_NOR	4'b0100
`define	OP_XNOR	4'b0101
`define	OP_NOT	4'b0110
`define	OP_AND	4'b0111
`define	OP_OR	4'b1000
`define	OP_XOR	4'b1001
// Shifting
`define	OP_LRS	4'b1010
`define	OP_ARS	4'b1011
`define	OP_RR	4'b1100
`define	OP_LLS	4'b1101
`define	OP_ALS	4'b1110
`define	OP_RL	4'b1111


module ALU(
    input [15:0] A,
    input [15:0] B,
    input Cin,
    input [3:0] OP,
    output [15:0] C,
    output Cout
);

    reg Cout = 0;
    reg [16:0] temp;
    reg [15:0] alu_result;
    assign C = alu_result;

    always @(A, B, Cin, OP)
    begin
        Cout = 0;
        case(OP)
        `OP_ADD : begin
                    temp = (A + B + Cin);
                    Cout = (temp >= (1 << 16));
                    alu_result = (A + B + Cin);
                  end
        `OP_SUB : begin
                    temp = (B + Cin);
                    Cout = temp > A;
                    alu_result = (A - B - Cin);
                  end
        
        `OP_ID  : alu_result = A;
        `OP_NAND: alu_result = ~(A & B);
        `OP_NOR : alu_result = ~(A | B);
        `OP_XNOR: alu_result = ~(A ^ B);
        `OP_NOT : alu_result = ~A;
        `OP_AND : alu_result = (A & B);
        `OP_OR  : alu_result = (A | B);
        `OP_XOR : alu_result = A ^ B;
        
        `OP_LRS : alu_result = A >> 1;
        `OP_ARS : begin
                    alu_result = A >> 1;
                    alu_result = alu_result + (A[15] << 15);
                  end
        `OP_RR  :  begin
                    alu_result = A >> 1;
                    alu_result = alu_result + (A[0] << 15);
                   end 
        `OP_LLS : alu_result = A << 1;
        `OP_ALS : alu_result = A << 1;
        `OP_RL  : begin
                    alu_result = A << 1;
                    alu_result = alu_result + A[15];
                  end
        endcase
    end
endmodule
