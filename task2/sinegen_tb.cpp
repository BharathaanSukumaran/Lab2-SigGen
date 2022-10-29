#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include"vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int it;
    int tick;

    Verilated::commandArgs(argc,argv);
    // intialise sinegen module
    Vsinegen* top = new Vsinegen;
    // initialise trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("sinegen.vcd");

    // init Vbuddy
    if (vbdOpen()!=1) return (-1);
    vbdHeader("Sinewave Gen");

    // init simulation outputs
    top->clk = 1;
    top->rst =0;
    top->en = 1;
    top->incr = 1;

    for(int i=0;i<1000000; i++){
        

        // dump variables into VCD file and toggle clock
        for(tick=0;tick<2;tick++){
            // in ps
            tfp->dump (2*i+tick);
            // falling edge
            top->clk = !top->clk;
            top->eval();
        }
        // vbdHex(4, (int(top->dout) >> 16) & 0xF);
        // vbdHex(3, (int(top->dout) >> 8) & 0xF);
        // vbdHex(2, (int(top->dout) >> 4) & 0xF);
        // vbdHex(1, int(top->dout) & 0xF);
        // vbdCycle(i+1);

        top->en = 1;
        top->rst = 0;
        top->incr = vbdValue();
        

        vbdPlot(int(top->dout1),0,255);
        vbdPlot(int(top->dout2),0,255);
        vbdCycle(i+1);
        
        if((Verilated::gotFinish()) || (vbdGetkey()=='q')) exit(0); 
    
    }
    vbdClose();
    tfp->close();
    exit(0);



}
