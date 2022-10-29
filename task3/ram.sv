module ram #(
    parameter ADDRESS_WIDTH = 9,
    parameter DATA_WIDTH = 8
)(
    input logic clk,
    input logic [ADDRESS_WIDTH-1:0] r_addr,
    input logic [ADDRESS_WIDTH-1:0] w_addr,
    input logic r_en,
    input logic w_en,
    input logic [DATA_WIDTH-1:0] din,
    output logic [DATA_WIDTH-1:0] dout,

);
// 3-bit vector with a depth of 2^8 bits
logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

// Initialise memory

always_ff @(posedge clk) begin
    if(r_en == 1) begin
        dout <= ram_array [r_addr];
    end
    if(w_en == 1) begin
        ram_array[w_addr] <= din;
    end
end

endmodule
