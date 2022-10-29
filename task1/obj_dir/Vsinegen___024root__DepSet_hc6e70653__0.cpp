// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "verilated.h"

#include "Vsinegen___024root.h"

VL_INLINE_OPT void Vsinegen___024root___sequent__TOP__0(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__sinegen__DOT__address;
    // Body
    __Vdly__sinegen__DOT__address = vlSelf->sinegen__DOT__address;
    vlSelf->dout = vlSelf->sinegen__DOT__sinerom__DOT__rom_array
        [vlSelf->sinegen__DOT__address];
    if (vlSelf->rst) {
        __Vdly__sinegen__DOT__address = 0U;
    } else if (vlSelf->en) {
        __Vdly__sinegen__DOT__address = (0xffU & ((0xffU 
                                                   == (IData)(vlSelf->sinegen__DOT__address))
                                                   ? (IData)(vlSelf->incr)
                                                   : 
                                                  ((IData)(vlSelf->sinegen__DOT__address) 
                                                   + (IData)(vlSelf->incr))));
    }
    vlSelf->sinegen__DOT__address = __Vdly__sinegen__DOT__address;
}

void Vsinegen___024root___eval(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsinegen___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->__pinNumber6 & 0xfeU))) {
        Verilated::overWidthError("__pinNumber6");}
}
#endif  // VL_DEBUG
