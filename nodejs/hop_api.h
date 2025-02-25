/*=====================================================================*/
/*    serrano/prgm/project/hop/hop/nodejs/hop_api.h                    */
/*    -------------------------------------------------------------    */
/*    Author      :  Manuel Serrano                                    */
/*    Creation    :  Fri Feb 24 15:38:53 2023                          */
/*    Last change :  Fri Jun  9 08:54:50 2023 (serrano)                */
/*    Copyright   :  2023 Manuel Serrano                               */
/*    -------------------------------------------------------------    */
/*    Hop Specific macro redefinitions                                 */
/*=====================================================================*/
#ifndef HOP_NODE_API_H_
#define HOP_NODE_API_H_

#include <stdarg.h>

/*---------------------------------------------------------------------*/
/*    Imports                                                          */
/*---------------------------------------------------------------------*/
extern int64_t bgl_bignum_to_int64(obj_t x);
extern uint64_t bgl_bignum_to_uint64(obj_t x);
extern obj_t bgl_int64_to_bignum(int64_t);
extern obj_t bgl_uint64_to_bignum(uint64_t);

static obj_t _reso;
static bool _resb;

extern int bgl_napi_is_array(obj_t);
extern int bgl_napi_is_date(obj_t);
extern int bgl_napi_is_error(obj_t);
extern int bgl_napi_is_promise(obj_t);
extern int bgl_napi_strict_equals(obj_t, obj_t);

extern int bgl_napi_typeof(obj_t, obj_t);
extern obj_t bgl_napi_throw(obj_t, obj_t);
extern obj_t bgl_napi_throw_error(obj_t, char *, char *);
extern obj_t bgl_napi_throw_type_error(obj_t, char *, char *);
extern obj_t bgl_napi_throw_range_error(obj_t, char *, char *);
extern obj_t bgl_napi_throw_syntax_error(obj_t, char *, char *);

extern obj_t bgl_napi_create_double(obj_t, obj_t, napi_value *result);
extern obj_t bgl_napi_create_string_latin1(obj_t, obj_t);
extern obj_t bgl_napi_create_string_utf8(obj_t, obj_t);
extern obj_t bgl_napi_create_string_utf16(obj_t, obj_t);
extern obj_t bgl_napi_create_function(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_create_object(obj_t);
extern obj_t bgl_napi_create_array(obj_t);
extern obj_t bgl_napi_create_array_with_length(obj_t, long);
extern obj_t bgl_napi_create_promise(obj_t, obj_t);
extern obj_t bgl_napi_create_date(obj_t, double);
extern obj_t bgl_napi_create_error(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_create_type_error(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_create_range_error(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_create_syntax_error(obj_t, obj_t, obj_t);

extern napi_status napi_define_class(napi_env _this, const char* utf8name, size_t length, napi_callback ctor, void *data, size_t property_count, const napi_property_descriptor *properties, napi_value *result);

extern bool_t bgl_napi_has_element(obj_t, obj_t, int);
extern obj_t bgl_napi_delete_element(obj_t, obj_t, int);
extern obj_t bgl_napi_get_element(obj_t, obj_t, int);
extern obj_t bgl_napi_set_element(obj_t, obj_t, int, obj_t);
extern obj_t bgl_napi_get_property(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_get_named_property(obj_t, obj_t, char *);
extern obj_t bgl_napi_put_property(obj_t, obj_t, obj_t, obj_t);
extern obj_t bgl_napi_put_named_property(obj_t, obj_t, obj_t, obj_t);
extern obj_t bgl_napi_put_named_string_property(obj_t, obj_t, char *, obj_t);
extern obj_t bgl_napi_define_named_property(obj_t, obj_t, obj_t, obj_t);
extern obj_t bgl_napi_make_property_descriptor(obj_t, obj_t, obj_t, obj_t,
					       bool_t, bool_t, bool_t,
					       obj_t, obj_t);
extern obj_t bgl_napi_delete_property(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_has_property(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_has_named_property(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_has_own_property(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_get_property_names(obj_t, obj_t);
extern obj_t bgl_napi_get_all_property_names(obj_t, obj_t, bool_t, int, bool_t);

extern obj_t bgl_napi_get_type_tag_object(obj_t, obj_t);
extern obj_t bgl_napi_set_type_tag_object(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_object_seal(obj_t, obj_t);
extern obj_t bgl_napi_object_freeze(obj_t, obj_t);

extern bool_t bgl_napi_jsstring_asciip(obj_t);
extern bool_t bgl_napi_jsstringp(obj_t);
extern obj_t bgl_napi_jsstring_to_string(obj_t);
extern obj_t bgl_napi_jsstring_to_string_latin1(obj_t);
extern obj_t bgl_napi_jsstring_to_string_utf16(obj_t);

extern uint32_t bgl_napi_get_array_length(obj_t, obj_t);
extern napi_status napi_define_properties(napi_env _this, napi_value this, size_t count, const napi_property_descriptor *properties);

extern napi_status napi_get_cb_info(napi_env _this, napi_callback_info info, size_t *argc, napi_value *argv, napi_value *this_arg, void **data);
extern obj_t bgl_napi_call_function(napi_env _this, obj_t this, obj_t fun, size_t argc, napi_value *argv);
extern obj_t bgl_napi_call_function_res(napi_env _this, obj_t this, obj_t fun, size_t argc, napi_value *argv, napi_value *res);

extern napi_status napi_get_value_bool(napi_env _this, napi_value value, bool *res);
extern napi_status napi_get_value_int32(napi_env _this, napi_value value, int32_t *res);
extern napi_status napi_get_value_double(napi_env _this, napi_value value, double *res);
extern napi_status napi_get_value_bigint_int64(napi_env _this, napi_value value, int64_t *res, bool *loosless);
extern napi_status napi_get_value_bigint_uint64(napi_env _this, napi_value value, uint64_t *res, bool *loosless);
extern napi_status napi_get_date_value(napi_env _this, napi_value value, double *res);
extern double bgl_napi_get_date_value(obj_t);

extern obj_t bgl_napi_wrap(obj_t, obj_t, obj_t);
extern obj_t bgl_napi_unwrap(obj_t, obj_t);
extern obj_t bgl_napi_remove_wrap(obj_t, obj_t);

/*---------------------------------------------------------------------*/
/*    bgl_napi_async_work                                              */
/*---------------------------------------------------------------------*/
struct napi_async_work__ {
   pthread_t pthread;
   obj_t env;
   napi_async_execute_callback execute;
   napi_async_complete_callback complete;
   void *data;
   char started;
};

/*---------------------------------------------------------------------*/
/*    napi_get_version                                                 */
/*---------------------------------------------------------------------*/
#define napi_get_version(env, result) \
   (*result = 8, napi_ok)

/*---------------------------------------------------------------------*/
/*    Module init                                                      */
/*---------------------------------------------------------------------*/
#undef NAPI_C_CTOR
#undef NAPI_MODULE_X
#undef NAPI_MODULE

#define NAPI_C_CTOR(modname)						\
   static obj_t BGl_z62hopscriptz62zz ## modname ## z00(obj_t env, obj_t _this, obj_t this, obj_t scope, obj_t module) { \
     napi_status status; \
     napi_value result; \
     obj_t nexports; \
     status = napi_get_named_property(_this, module, "exports", &result); \
     nexports = _module.nm_register_func(_this, result); \
     napi_put_named_property(_this, module, "exports", nexports, &result); \
     return nexports; \
   } \
   DEFINE_EXPORT_BGL_PROCEDURE(BGl_hopscriptzd2envzd2zz ## modname ## z00, __BGl_z62hopscriptz62zz ## modname ## z00, BGl_z62hopscriptz62zz ## modname ## z00, 0L, BUNSPEC, 4); \
   obj_t bigloo_dlopen_init() { \
     obj_t res = BTRUE; \
     BGL_MVALUES_NUMBER_SET(2); \
     BGL_MVALUES_VAL_SET(1,string_to_bstring(# modname)); \
     return res; \
  } \
  static void _register_ ## modname(void)

#define NAPI_MODULE_X(modname, regfunc, priv, flags)                  \
  EXTERN_C_START                                                      \
    static napi_module _module =                                      \
    {                                                                 \
      NAPI_MODULE_VERSION,                                            \
      flags,                                                          \
      __FILE__,                                                       \
      regfunc,                                                        \
      #modname,                                                       \
      priv,                                                           \
      {0},                                                            \
    };                                                                \
  NAPI_C_CTOR(modname) {				              \
      napi_module_register(&_module);                                 \
    }                                                                 \
  EXTERN_C_END

#define NAPI_MODULE(modname, regfunc)                                 \
  NAPI_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)

/*---------------------------------------------------------------------*/
/*    Wrappers                                                         */
/*---------------------------------------------------------------------*/
#define napi_throw(_this, obj) \
  bgl_napi_throw(_this, obj)

#define napi_throw_error(_this, code, msg) \
  bgl_napi_throw_error(_this, (char *)code, (char *)msg)

#define napi_throw_type_error(_this, code, msg) \
  bgl_napi_throw_type_error(_this, (char *)code, (char *)msg)

#define napi_throw_range_error(_this, code, msg) \
  bgl_napi_throw_range_error(_this, (char *)code, (char *)msg)

#define napi_throw_syntax_error(_this, code, msg) \
  bgl_napi_throw_syntax_error(_this, (char *)code, (char *)msg)

#define napi_create_int32(_this, val, res) \
   (*res = BINT(val), napi_ok)

#define napi_create_uint32(_this, val, res) \
   (*res = BINT(val), napi_ok)

#define napi_create_int64(_this, val, res) \
  (*res = DOUBLE_TO_REAL((double)val), napi_ok)

#define napi_create_uint64(_this, val, res) \
  (*res = DOUBLE_TO_REAL((double)val), napi_ok)

#define napi_create_object(_this, res) \
   (*res = bgl_napi_create_object(_this), napi_ok)

#define napi_create_array(_this, res) \
  (*res = bgl_napi_create_array(_this), napi_ok)

#define napi_create_array_with_length(_this, len, res)	\
   (*res = bgl_napi_create_array_with_length(_this, len), napi_ok)

#define napi_create_promise(_this, deferred, res) \
   (*res = bgl_napi_create_promise(_this, (obj_t)deferred), napi_ok)

#define napi_create_date(_this, time, res) \
  (*res = bgl_napi_create_date(_this, time), napi_ok)

#define napi_create_error(_this, code, msg, res) \
  (*res = bgl_napi_create_error(_this, code, msg), napi_ok)

#define napi_create_type_error(_this, code, msg, res) \
  (*res = bgl_napi_create_type_error(_this, code, msg), napi_ok)

#define napi_create_range_error(_this, code, msg, res) \
  (*res = bgl_napi_create_range_error(_this, code, msg), napi_ok)

#define napi_create_syntax_error(_this, code, msg, res) \
  (*res = bgl_napi_create_syntax_error(_this, code, msg), napi_ok)

#define napi_create_bigint_int64(_this, int64, res) \
   (*res = bgl_int64_to_bignum(int64), napi_ok)

#define napi_create_bigint_uint64(_this, uint64, res) \
   (*res = bgl_uint64_to_bignum(uint64), napi_ok)

#define napi_resolve_deferred(_this, deferred, value) \
  (bgl_napi_call_function(_this, BUNSPEC, CAR(deferred), 1, &value), napi_ok)
  
#define napi_reject_deferred(_this, deferred, value) \
  (bgl_napi_call_function(_this, BUNSPEC, CDR(deferred), 1, &value), napi_ok)
  
#define napi_get_property(_this, this, prop, res) \
   (_reso = bgl_napi_get_property(_this, this, prop), (res != NULL ? *((obj_t *)res) = _reso : 0L), napi_ok)

#define napi_get_named_property(_this, this, prop, res) \
   (_reso = bgl_napi_get_named_property(_this, this, prop), (res != NULL ? *((obj_t *)res) = _reso : 0L), napi_ok)

#define napi_put_property(_this, this, prop, val, res) \
  (*res = bgl_napi_put_property(_this, this, prop, val), napi_ok)

#define napi_put_named_property(_this, this, prop, val, res) \
  (*res = bgl_napi_put_named_string_property(_this, this, prop, val), napi_ok)

#define napi_set_property(_this, this, prop, val) \
  (bgl_napi_put_property(_this, this, prop, val), napi_ok)

#define napi_set_named_property(_this, this, prop, val) \
  (bgl_napi_put_named_string_property(_this, this, prop, val), napi_ok)

#define napi_delete_property(_this, this, key, res) \
   (_resb = CBOOL(bgl_napi_delete_property(_this, this, key)), (res != NULL ? *((bool *)res) = _resb : 0L), napi_ok)

#define napi_has_property(_this, this, key, res) \
   (_resb = CBOOL(bgl_napi_has_property(_this, this, key)), (res != NULL ? *((bool *)res) = _resb : 0L), napi_ok)

#define napi_has_named_property(_this, this, key, res) \
   (_resb = CBOOL(bgl_napi_has_named_property(_this, this, string_to_bstring(key))), (res != NULL ? *((bool *)res) = _resb : 0L), napi_ok)

#define napi_has_own_property(_this, this, key, res) \
   (_resb = CBOOL(bgl_napi_has_own_property(_this, this, key)), (res != NULL ? *((bool *)res) = _resb : 0L), napi_ok)

#define napi_type_tag_object(_this, this, tag) \
   (bgl_napi_set_type_tag_object(_this, this, (obj_t)tag), napi_ok)

#define napi_check_object_type_tag(_this, this, tag, res) \
   (*res = bgl_napi_get_type_tag_object(_this, this) == (obj_t)tag, napi_ok)

#define napi_object_seal(_this, this) \
   (bgl_napi_object_seal(_this, this), napi_ok)

#define napi_object_freeze(_this, this) \
   (bgl_napi_object_freeze(_this, this), napi_ok)

#define napi_get_undefined(env, res) \
  (*res = BUNSPEC, napi_ok)

#define napi_get_boolean(env, val, res) \
   (*res = BBOOL(val), napi_ok)

#define napi_has_element(_this, this, index, res) \
  (*res = bgl_napi_has_element(_this, this, index), napi_ok)

#define napi_delete_element(_this, this, index, res) \
   (_resb = CBOOL(bgl_napi_delete_element(_this, this, index)), (res != NULL ? *((bool *)res) = _resb : 0L), napi_ok)

#define napi_get_global(_this, res) \
  (*res = _this, napi_ok)

#define napi_call_function(_this, global, fun, argc, argv, res) \
  bgl_napi_call_function_res(_this, global, fun, argc, argv, res)

#define napi_is_array(_this, val, res) \
   (*res = bgl_napi_is_array(val), napi_ok)

#define napi_typeof(_this, val, res) \
  (*res = (napi_valuetype)bgl_napi_typeof(_this, val), napi_ok)

#define napi_get_array_length(_this, val, res) \
  (*res = bgl_napi_get_array_length(_this, val), napi_ok)

#define napi_delete_async_work(env, work) \
  (free(work), napi_ok)

#define napi_is_date(_this, val, res) \
   (*res = bgl_napi_is_date(val), napi_ok)

#define napi_is_error(_this, val, res) \
   (*res = bgl_napi_is_error(val), napi_ok)

#define napi_is_promise(_this, val, res) \
   (*res = bgl_napi_is_promise(val), napi_ok)

#define napi_strict_equals(_this, x, y, res) \
  (*res = bgl_napi_strict_equals(x, y), napi_ok)

#define napi_adjust_external_memory(env, change_in_bytes, result) \
  (*result = 1, napi_ok)

/*---------------------------------------------------------------------*/
/*    endif                                                            */
/*---------------------------------------------------------------------*/
#endif
