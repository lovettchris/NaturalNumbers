// Lean compiler output
// Module: InequalityWorld.Level16
// Imports: Init MyNat.Definition MyNat.Addition MyNat.Inequality Mathlib.Tactic.Use AdditionWorld.Level2 AdditionWorld.Level3 InequalityWorld.Level5 InequalityWorld.Level6 InequalityWorld.Level10 AdvancedAdditionWorld.Level13
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_MyNat_Definition(uint8_t builtin, lean_object*);
lean_object* initialize_MyNat_Addition(uint8_t builtin, lean_object*);
lean_object* initialize_MyNat_Inequality(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_Use(uint8_t builtin, lean_object*);
lean_object* initialize_AdditionWorld_Level2(uint8_t builtin, lean_object*);
lean_object* initialize_AdditionWorld_Level3(uint8_t builtin, lean_object*);
lean_object* initialize_InequalityWorld_Level5(uint8_t builtin, lean_object*);
lean_object* initialize_InequalityWorld_Level6(uint8_t builtin, lean_object*);
lean_object* initialize_InequalityWorld_Level10(uint8_t builtin, lean_object*);
lean_object* initialize_AdvancedAdditionWorld_Level13(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_InequalityWorld_Level16(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MyNat_Definition(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MyNat_Addition(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MyNat_Inequality(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_Use(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_AdditionWorld_Level2(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_AdditionWorld_Level3(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_InequalityWorld_Level5(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_InequalityWorld_Level6(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_InequalityWorld_Level10(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_AdvancedAdditionWorld_Level13(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
