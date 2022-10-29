// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsinegen.h"
#include "Vsinegen__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsinegen::Vsinegen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsinegen__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , incr{vlSymsp->TOP.incr}
    , dout{vlSymsp->TOP.dout}
    , __pinNumber6{vlSymsp->TOP.__pinNumber6}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsinegen::Vsinegen(const char* _vcname__)
    : Vsinegen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsinegen::~Vsinegen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsinegen___024root___eval_initial(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval_settle(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval(Vsinegen___024root* vlSelf);
#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG
void Vsinegen___024root___final(Vsinegen___024root* vlSelf);

static void _eval_initial_loop(Vsinegen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsinegen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsinegen___024root___eval_settle(&(vlSymsp->TOP));
        Vsinegen___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsinegen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsinegen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsinegen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsinegen___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vsinegen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsinegen::final() {
    Vsinegen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsinegen::hierName() const { return vlSymsp->name(); }
const char* Vsinegen::modelName() const { return "Vsinegen"; }
unsigned Vsinegen::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vsinegen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsinegen___024root__trace_init_top(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen___024root*>(voidSelf);
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsinegen___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsinegen___024root__trace_register(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsinegen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsinegen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
