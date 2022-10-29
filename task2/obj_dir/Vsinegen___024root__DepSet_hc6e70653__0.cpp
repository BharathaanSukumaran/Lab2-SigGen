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
    CData/*7:0*/ __Vdly__sinegen__DOT__addr1;
    // Body
    __Vdly__sinegen__DOT__addr1 = vlSelf->sinegen__DOT__addr1;
    vlSelf->dout1 = vlSelf->sinegen__DOT__sinerom__DOT__rom_array
        [vlSelf->sinegen__DOT__addr1];
    vlSelf->dout2 = vlSelf->sinegen__DOT__sinerom__DOT__rom_array
        [vlSelf->sinegen__DOT__addr2];
    if (vlSelf->rst) {
        __Vdly__sinegen__DOT__addr1 = 0U;
        vlSelf->sinegen__DOT__addr2 = 0U;
    } else {
        __Vdly__sinegen__DOT__addr1 = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->sinegen__DOT__addr1)));
        vlSelf->sinegen__DOT__addr2 = (0xffU & ((IData)(vlSelf->sinegen__DOT__addr1) 
                                                + (IData)(vlSelf->incr)));
    }
    vlSelf->sinegen__DOT__addr1 = __Vdly__sinegen__DOT__addr1;
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
    if (VL_UNLIKELY((vlSelf->__pinNumber7 & 0xfeU))) {
        Verilated::overWidthError("__pinNumber7");}
}
#endif  // VL_DEBUG
