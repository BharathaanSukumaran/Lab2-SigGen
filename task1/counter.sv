module counter #(
    // bits in counter set to 8 bits
    parameter WIDTH = 8
)(
    // interface signals
    input logic clk, //clk
    input logic rst, //reset
    input logic en, // enable
    input logic [WIDTH-1:0] incr,//increment
    output logic [WIDTH-1:0] count //count output
);
// indicates that this is a clocked circuit

always_ff @(posedge clk) 
if(rst) begin
    count <= 0;
end
else begin

    if(en)begin
    if(count == 8'b1111_1111) begin
        count <= incr ;
    end
    else begin
        count <= count+ incr;
    end   
    end
end


endmodule 









