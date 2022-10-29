module counter #(
    // bits in counter set to 8 bits
    parameter WIDTH = 8
)(
    // interface signals
    input logic clk, //clk
    input logic rst, //reset
    input logic en, // enable
    input logic [WIDTH-1:0] offset,//offset
    output logic [WIDTH-1:0] count1, //count output
    output logic [WIDTH-1:0] count2 //count output

);
// indicates that this is a clocked circuit

always_ff @(posedge clk) 
if(rst) begin
    count1 <= 0;
    count2 <= 0;
end
else begin
    count1 <= count1+ 1'b1;
    count2 <= count1 - offset;
end


endmodule 









