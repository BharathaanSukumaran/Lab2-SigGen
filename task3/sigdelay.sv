module sigdelay #(
    parameter D_WIDTH = 8,
    parameter A_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic wr,
    input logic rd,
    input logic [D_WIDTH-1:0] offset,
    input logic en,
    output logic [D_WIDTH-1:0] mic_signal,
    output logic [D_WIDTH-1:0] delayed_signal
);

// connecting variables
logic [D_WIDTH-1:0] addr1;
logic [D_WIDTH-1:0] addr2;


counter addrCounter (
    .clk (clk),
    .rst(rst),
    .en(en),
    .offset(offset),
    .count1(addr1),
    .count2(addr2)
);

ram sigram(
    .clk(clk),
    .r_en(rd),
    .w_en(wr),
    .r_addr(addr1),
    .w_addr(addr2),
    .din(mic_signal),
    .dout(delayed_signal)
);
endmodule
