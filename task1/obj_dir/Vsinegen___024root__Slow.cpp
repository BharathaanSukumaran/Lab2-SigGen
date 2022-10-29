// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "verilated.h"

#include "Vsinegen__Syms.h"
#include "Vsinegen___024root.h"

void Vsinegen___024root___ctor_var_reset(Vsinegen___024root* vlSelf);

Vsinegen___024root::Vsinegen___024root(Vsinegen__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsinegen___024root___ctor_var_reset(this);
}

void Vsinegen___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsinegen___024root::~Vsinegen___024root() {
}
