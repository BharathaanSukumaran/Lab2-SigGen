// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsigdelay.h"
#include "Vsigdelay__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsigdelay::Vsigdelay(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsigdelay__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , wr{vlSymsp->TOP.wr}
    , rd{vlSymsp->TOP.rd}
    , offset{vlSymsp->TOP.offset}
    , en{vlSymsp->TOP.en}
    , mic_signal{vlSymsp->TOP.mic_signal}
    , delayed_signal{vlSymsp->TOP.delayed_signal}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsigdelay::Vsigdelay(const char* _vcname__)
    : Vsigdelay(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsigdelay::~Vsigdelay() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsigdelay___024root___eval_initial(Vsigdelay___024root* vlSelf);
void Vsigdelay___024root___eval_settle(Vsigdelay___024root* vlSelf);
void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf);
#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG
void Vsigdelay___024root___final(Vsigdelay___024root* vlSelf);

static void _eval_initial_loop(Vsigdelay__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsigdelay___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsigdelay___024root___eval_settle(&(vlSymsp->TOP));
        Vsigdelay___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsigdelay::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsigdelay::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsigdelay___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsigdelay___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vsigdelay::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsigdelay::final() {
    Vsigdelay___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsigdelay::hierName() const { return vlSymsp->name(); }
const char* Vsigdelay::modelName() const { return "Vsigdelay"; }
unsigned Vsigdelay::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vsigdelay::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsigdelay___024root__trace_init_top(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsigdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsigdelay___024root*>(voidSelf);
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsigdelay___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsigdelay___024root__trace_register(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsigdelay::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsigdelay___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
