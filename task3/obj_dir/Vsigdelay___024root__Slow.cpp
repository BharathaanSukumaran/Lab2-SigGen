// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay__Syms.h"
#include "Vsigdelay___024root.h"

void Vsigdelay___024root___ctor_var_reset(Vsigdelay___024root* vlSelf);

Vsigdelay___024root::Vsigdelay___024root(Vsigdelay__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsigdelay___024root___ctor_var_reset(this);
}

void Vsigdelay___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsigdelay___024root::~Vsigdelay___024root() {
}
