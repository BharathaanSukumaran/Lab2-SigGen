module sinegen #(
    parameter D_WIDTH = 8,
    parameter A_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [D_WIDTH-1:0] incr,
    output logic [D_WIDTH-1:0] dout1,
    output logic [D_WIDTH-1:0] dout2,
);

// connecting variable
logic [D_WIDTH-1:0] addr1;
logic [D_WIDTH-1:0] addr2;


counter addrCounter (
    .clk (clk),
    .rst(rst),
    .en(en),
    .incr(incr),
    .count1(addr1),
    .count2(addr2)
);

rom sinerom(
    .clk(clk),
    .addr1(addr1),
    .addr2(addr2),
    .dout1(dout1),
    .dout2(dout2)
);
endmodule
