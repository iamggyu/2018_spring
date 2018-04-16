// Title         : vending_machine.v
// Author      : Hunjun Lee (hunjunlee7515@snu.ac.kr), Suheon Bae (suheon.bae@snu.ac.kr)

`include "vending_machine_def.v"

module vending_machine (

	clk,							// Clock signal
	reset_n,	 					// Reset signal (active-low)

	i_input_coin,				// coin is inserted.
	i_select_item,				// item is selected.
	i_trigger_return,			// change-return is triggered

	o_available_item,			// Sign of the item availability
	o_output_item,			   // Sign of the item withdrawal
	o_return_coin,			   // Sign of the coin return
	o_current_total
);

	// Ports Declaration
	input clk;
	input reset_n;

	input [`kNumCoins-1:0] i_input_coin;
	input [`kNumItems-1:0] i_select_item;
	input i_trigger_return;

	output [`kNumItems-1:0] o_available_item;
	output [`kNumItems-1:0] o_output_item;
	output [`kReturnCoins-1:0] o_return_coin;
	output [`kTotalBits-1:0] o_current_total;

	// Net constant values (prefix kk & CamelCase)
	wire [31:0] kkItemPrice [`kNumItems-1:0];	// Price of each item
	wire [31:0] kkCoinValue [`kNumCoins-1:0];	// Value of each coin
	assign kkItemPrice[0] = 400;
	assign kkItemPrice[1] = 500;
	assign kkItemPrice[2] = 1000;
	assign kkItemPrice[3] = 2000;
	assign kkCoinValue[0] = 100;
	assign kkCoinValue[1] = 500;
	assign kkCoinValue[2] = 1000;

	// Internal states. You may add your own reg variables.
	reg [`kTotalBits-1:0] current_total;
	reg [`kItemBits-1:0] num_items [`kNumItems-1:0]; //use if needed
	reg [`kCoinBits-1:0] num_coins [`kNumCoins-1:0]; //use if needed
	reg [`kTotalBits-1:0] next_total;
	
	//reg for output
	reg [`kNumItems-1:0] available_item = 0;
	reg [`kNumItems-1:0] output_item = 0;
    reg [`kReturnCoins-1:0] return_coin = 0;
	
	assign o_available_item = available_item;
	assign o_output_item = output_item;
	assign o_return_coin = return_coin;
	assign o_current_total = current_total;
	
	//index
	integer i;

	// Combinational circuit for the next states
	always @(i_input_coin, i_select_item, i_trigger_return) begin
        //initialize outputs
        next_total = current_total;
        output_item = 0;
        return_coin = 0;
        available_item = 0;
        
        //insearting coin
        for(i=0;i<`kNumCoins;i=i+1)
            if(i_input_coin[i] == 1)
                next_total = next_total + kkCoinValue[i];
         
        //purchasing item
        for(i=0; i < `kNumItems; i=i+1) begin
            if(i_select_item[i] == 1)
                //check is there enough money
                if(next_total >= kkItemPrice[i]) begin
                    next_total = next_total - kkItemPrice[i];
                    output_item[i] = 1;
                end
        end
                   	   
	    //find o_return_coin
	    if(i_trigger_return == 1) begin
	       for(i = `kNumCoins; i >= 0; i = i - 1) begin
	           while(next_total >= kkCoinValue[i]) begin
	               next_total = next_total - kkCoinValue[i];
	               return_coin = return_coin + 1;
	           end
	       end
	    end
        
        //find o_available_item
        for(i=0; i < `kNumItems; i=i+1)
            if(next_total >= kkItemPrice[i])
                available_item[i] = 1;
	end

	// Sequential circuit to reset or update the states
	//current_total is only state. 
	always @(posedge clk) begin
		if (!reset_n) begin
			// TODO: reset all states.
			current_total = 0;
		end
		else begin
			// TODO: update all states.
			current_total = next_total;
		end
	end

endmodule
