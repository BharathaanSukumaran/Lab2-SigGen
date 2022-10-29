// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsinegen.h for the primary calling header

#ifndef VERILATED_VSINEGEN___024ROOT_H_
#define VERILATED_VSINEGEN___024ROOT_H_  // guard

#include "verilated.h"

class Vsinegen__Syms;

class Vsinegen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_IN8(incr,7,0);
    VL_OUT8(dout,7,0);
    VL_IN8(__pinNumber6,0,0);
    CData/*7:0*/ sinegen__DOT__address;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*7:0*/, 256> sinegen__DOT__sinerom__DOT__rom_array;

    // INTERNAL VARIABLES
    Vsinegen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsinegen___024root(Vsinegen__Syms* symsp, const char* name);
    ~Vsinegen___024root();
    VL_UNCOPYABLE(Vsinegen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
