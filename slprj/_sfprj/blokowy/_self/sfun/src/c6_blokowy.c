/* Include files */

#include <stddef.h>
#include "blas.h"
#include "blokowy_sfun.h"
#include "c6_blokowy.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void initialize_params_c6_blokowy(SFc6_blokowyInstanceStruct
  *chartInstance);
static void enable_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void disable_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_blokowy(SFc6_blokowyInstanceStruct
  *chartInstance);
static void set_sim_state_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void sf_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void initSimStructsc6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void registerMessagesc6_blokowy(SFc6_blokowyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static void c6_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance, const
  mxArray *c6_GCode, const char_T *c6_identifier, int32_T c6_y[1120]);
static void c6_b_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, int32_T c6_y[1120]);
static void c6_c_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_LGCode, const char_T *c6_identifier, int32_T c6_y[60]);
static void c6_d_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, int32_T c6_y[60]);
static uint8_T c6_e_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_blokowy, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_blokowyInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_blokowy = 0U;
}

static void initialize_params_c6_blokowy(SFc6_blokowyInstanceStruct
  *chartInstance)
{
}

static void enable_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c6_blokowy(SFc6_blokowyInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  int32_T c6_u[1120];
  const mxArray *c6_b_y = NULL;
  int32_T c6_b_u[1120];
  const mxArray *c6_c_y = NULL;
  int32_T c6_c_u[1120];
  const mxArray *c6_d_y = NULL;
  int32_T c6_d_u[1120];
  const mxArray *c6_e_y = NULL;
  int32_T c6_e_u[60];
  const mxArray *c6_f_y = NULL;
  int32_T c6_f_u[1120];
  const mxArray *c6_g_y = NULL;
  int32_T c6_g_u[1120];
  const mxArray *c6_h_y = NULL;
  uint8_T c6_h_u;
  const mxArray *c6_i_y = NULL;
  int32_T (*c6_RCodeRev)[1120];
  int32_T (*c6_RCode)[1120];
  int32_T (*c6_LGCode)[60];
  int32_T (*c6_LCodeRev)[1120];
  int32_T (*c6_LCode)[1120];
  int32_T (*c6_GCodeRev)[1120];
  int32_T (*c6_GCode)[1120];
  c6_RCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 7);
  c6_GCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 6);
  c6_LCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 5);
  c6_RCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_GCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_LCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_LGCode = (int32_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(8), FALSE);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_u[c6_i0] = (*c6_GCode)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_b_u[c6_i0] = (*c6_GCodeRev)[c6_i0];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_b_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_c_u[c6_i0] = (*c6_LCode)[c6_i0];
  }

  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_c_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_d_u[c6_i0] = (*c6_LCodeRev)[c6_i0];
  }

  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_d_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  for (c6_i0 = 0; c6_i0 < 60; c6_i0++) {
    c6_e_u[c6_i0] = (*c6_LGCode)[c6_i0];
  }

  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_e_u, 6, 0U, 1U, 0U, 2, 10, 6),
                FALSE);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_f_u[c6_i0] = (*c6_RCode)[c6_i0];
  }

  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_f_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  for (c6_i0 = 0; c6_i0 < 1120; c6_i0++) {
    c6_g_u[c6_i0] = (*c6_RCodeRev)[c6_i0];
  }

  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_g_u, 6, 0U, 1U, 0U, 2, 10, 112),
                FALSE);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_h_u = chartInstance->c6_is_active_c6_blokowy;
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &c6_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 7, c6_i_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  int32_T (*c6_GCode)[1120];
  int32_T (*c6_GCodeRev)[1120];
  int32_T (*c6_LCode)[1120];
  int32_T (*c6_LCodeRev)[1120];
  int32_T (*c6_LGCode)[60];
  int32_T (*c6_RCode)[1120];
  int32_T (*c6_RCodeRev)[1120];
  c6_RCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 7);
  c6_GCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 6);
  c6_LCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 5);
  c6_RCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_GCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_LCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_LGCode = (int32_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "GCode", *c6_GCode);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                      "GCodeRev", *c6_GCodeRev);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
                      "LCode", *c6_LCode);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
                      "LCodeRev", *c6_LCodeRev);
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
                        "LGCode", *c6_LGCode);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 5)),
                      "RCode", *c6_RCode);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 6)),
                      "RCodeRev", *c6_RCodeRev);
  chartInstance->c6_is_active_c6_blokowy = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 7)), "is_active_c6_blokowy");
  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
}

static void sf_c6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
  int32_T c6_iNum;
  int32_T c6_iSym;
  int32_T c6_b_iSym;
  static char_T c6_ean_code_sym[60] = { 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L',
    'L', 'L', 'L', 'L', 'L', 'L', 'G', 'G', 'G', 'G', 'G', 'G', 'L', 'G', 'G',
    'G', 'L', 'G', 'G', 'L', 'L', 'G', 'L', 'L', 'G', 'G', 'L', 'L', 'G', 'G',
    'G', 'L', 'L', 'G', 'L', 'G', 'G', 'L', 'L', 'L', 'G', 'G', 'L', 'G', 'G',
    'L', 'G', 'G', 'L', 'G', 'L', 'L' };

  int8_T c6_LGCode[60];
  static int8_T c6_LCode[1120] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1,
    1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1,
    -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1,
    1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1,
    1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1,
    -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1,
    1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1,
    -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1,
    -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1,
    -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1,
    1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1,
    -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1,
    -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1,
    -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1,
    -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1,
    1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1,
    1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1,
    -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1,
    -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1,
    1, 1, -1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1,
    1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1,
    -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1,
    1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1,
    -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1,
    -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1,
    1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1,
    -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 1,
    -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1,
    1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1,
    -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1,
    -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1,
    -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1,
    1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1,
    -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  };

  int8_T c6_LCodeRev[1120];
  static int8_T c6_GCode[1120] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1,
    -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1,
    1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1,
    -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1,
    -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1,
    -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1,
    -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1,
    1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1,
    -1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1,
    1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1,
    1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1,
    -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1,
    -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1,
    -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1,
    1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1,
    -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1,
    1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1,
    -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1,
    -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1,
    1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1,
    -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1,
    1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1,
    -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1,
    -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1,
    -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1,
    1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1,
    -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1,
    -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1,
    -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1,
    -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1,
    -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1 };

  int8_T c6_GCodeRev[1120];
  static int8_T c6_RCode[1120] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1,
    -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1,
    -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1,
    -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1,
    1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1,
    -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1,
    -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1,
    -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1,
    1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1,
    -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1,
    -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1,
    1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1,
    -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1,
    -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1,
    -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1,
    1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1,
    -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1,
    1, 1, -1, -1, 1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1,
    -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1,
    -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1,
    -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1,
    -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1,
    -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1,
    -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1,
    1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1,
    -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1,
    1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1,
    -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1,
    -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1,
    -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1 };

  int8_T c6_RCodeRev[1120];
  int32_T (*c6_b_LGCode)[60];
  int32_T (*c6_b_LCode)[1120];
  int32_T (*c6_b_GCode)[1120];
  int32_T (*c6_b_RCode)[1120];
  int32_T (*c6_b_LCodeRev)[1120];
  int32_T (*c6_b_GCodeRev)[1120];
  int32_T (*c6_b_RCodeRev)[1120];
  c6_b_RCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 7);
  c6_b_GCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 6);
  c6_b_LCodeRev = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 5);
  c6_b_RCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_b_GCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_b_LCode = (int32_T (*)[1120])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_LGCode = (int32_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  for (c6_iNum = 0; c6_iNum < 10; c6_iNum++) {
    c6_iSym = 0;
    for (c6_b_iSym = 0; c6_b_iSym < 6; c6_b_iSym++) {
      if (c6_ean_code_sym[c6_iSym + c6_iNum] == 'L') {
        c6_LGCode[c6_iSym + c6_iNum] = (int8_T)(1 + c6_b_iSym);
      } else {
        c6_LGCode[c6_iSym + c6_iNum] = (int8_T)(7 + c6_b_iSym);
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      c6_iSym += 10;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c6_iNum = 0; c6_iNum < 112; c6_iNum++) {
    c6_iSym = 111 - c6_iNum;
    for (c6_b_iSym = 0; c6_b_iSym < 10; c6_b_iSym++) {
      c6_LCodeRev[c6_b_iSym + 10 * c6_iNum] = c6_LCode[c6_b_iSym + 10 * c6_iSym];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c6_iNum = 0; c6_iNum < 112; c6_iNum++) {
    c6_iSym = 111 - c6_iNum;
    for (c6_b_iSym = 0; c6_b_iSym < 10; c6_b_iSym++) {
      c6_GCodeRev[c6_b_iSym + 10 * c6_iNum] = c6_GCode[c6_b_iSym + 10 * c6_iSym];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c6_iNum = 0; c6_iNum < 112; c6_iNum++) {
    c6_iSym = 111 - c6_iNum;
    for (c6_b_iSym = 0; c6_b_iSym < 10; c6_b_iSym++) {
      c6_RCodeRev[c6_b_iSym + 10 * c6_iNum] = c6_RCode[c6_b_iSym + 10 * c6_iSym];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c6_iSym = 0; c6_iSym < 60; c6_iSym++) {
    (*c6_b_LGCode)[c6_iSym] = c6_LGCode[c6_iSym];
  }

  for (c6_iSym = 0; c6_iSym < 1120; c6_iSym++) {
    (*c6_b_LCode)[c6_iSym] = c6_LCode[c6_iSym];
    (*c6_b_GCode)[c6_iSym] = c6_GCode[c6_iSym];
    (*c6_b_RCode)[c6_iSym] = c6_RCode[c6_iSym];
    (*c6_b_LCodeRev)[c6_iSym] = c6_LCodeRev[c6_iSym];
    (*c6_b_GCodeRev)[c6_iSym] = c6_GCodeRev[c6_iSym];
    (*c6_b_RCodeRev)[c6_iSym] = c6_RCodeRev[c6_iSym];
  }
}

static void initSimStructsc6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
}

static void registerMessagesc6_blokowy(SFc6_blokowyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

const mxArray *sf_c6_blokowy_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[3];
  c6_ResolvedFunctionInfo (*c6_b_info)[3];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i1;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[3])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mtimes";
  (*c6_b_info)[0].dominantType = "int32";
  (*c6_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c6_b_info)[0].fileTimeLo = 1289519692U;
  (*c6_b_info)[0].fileTimeHi = 0U;
  (*c6_b_info)[0].mFileTimeLo = 0U;
  (*c6_b_info)[0].mFileTimeHi = 0U;
  (*c6_b_info)[1].context = "";
  (*c6_b_info)[1].name = "eml_int_forloop_overflow_check";
  (*c6_b_info)[1].dominantType = "";
  (*c6_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c6_b_info)[1].fileTimeLo = 1346510340U;
  (*c6_b_info)[1].fileTimeHi = 0U;
  (*c6_b_info)[1].mFileTimeLo = 0U;
  (*c6_b_info)[1].mFileTimeHi = 0U;
  (*c6_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c6_b_info)[2].name = "intmax";
  (*c6_b_info)[2].dominantType = "char";
  (*c6_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c6_b_info)[2].fileTimeLo = 1311255316U;
  (*c6_b_info)[2].fileTimeHi = 0U;
  (*c6_b_info)[2].mFileTimeLo = 0U;
  (*c6_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    c6_r0 = &c6_info[c6_i1];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i1);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i1);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance, const
  mxArray *c6_GCode, const char_T *c6_identifier, int32_T c6_y[1120])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_GCode), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_GCode);
}

static void c6_b_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, int32_T c6_y[1120])
{
  int32_T c6_iv0[1120];
  int32_T c6_i2;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_iv0, 1, 6, 0U, 1, 0U, 2, 10,
                112);
  for (c6_i2 = 0; c6_i2 < 1120; c6_i2++) {
    c6_y[c6_i2] = c6_iv0[c6_i2];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_LGCode, const char_T *c6_identifier, int32_T c6_y[60])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_LGCode), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_LGCode);
}

static void c6_d_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, int32_T c6_y[60])
{
  int32_T c6_iv1[60];
  int32_T c6_i3;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_iv1, 1, 6, 0U, 1, 0U, 2, 10, 6);
  for (c6_i3 = 0; c6_i3 < 60; c6_i3++) {
    c6_y[c6_i3] = c6_iv1[c6_i3];
  }

  sf_mex_destroy(&c6_u);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_blokowy, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_blokowy), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_blokowy);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_blokowyInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_blokowyInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_blokowy_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3748485878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1755817444U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(225242504U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(480398041U);
}

mxArray *sf_c6_blokowy_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mcN20Wlerk7zkmiEv128aH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(6);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_blokowy_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_blokowy(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[14],T\"GCode\",},{M[1],M[20],T\"GCodeRev\",},{M[1],M[13],T\"LCode\",},{M[1],M[19],T\"LCodeRev\",},{M[1],M[16],T\"LGCode\",},{M[1],M[15],T\"RCode\",},{M[1],M[17],T\"RCodeRev\",},{M[8],M[0],T\"is_active_c6_blokowy\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_blokowy_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "WNx6KD6oi6Jvz0bsMIWeNC";
}

static void sf_opaque_initialize_c6_blokowy(void *chartInstanceVar)
{
  initialize_params_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
  initialize_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_blokowy(void *chartInstanceVar)
{
  enable_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_blokowy(void *chartInstanceVar)
{
  disable_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_blokowy(void *chartInstanceVar)
{
  sf_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_blokowy(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_blokowy((SFc6_blokowyInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_blokowy();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c6_blokowy(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_blokowy();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_blokowy((SFc6_blokowyInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_blokowy(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_blokowy(S);
}

static void sf_opaque_set_sim_state_c6_blokowy(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_blokowy(S, st);
}

static void sf_opaque_terminate_c6_blokowy(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_blokowyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_blokowy_optimization_info();
    }

    finalize_c6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_blokowy((SFc6_blokowyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_blokowy(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_blokowy((SFc6_blokowyInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_blokowy_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3747346564U));
  ssSetChecksum1(S,(2191128769U));
  ssSetChecksum2(S,(1088131691U));
  ssSetChecksum3(S,(1771341133U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_blokowy(SimStruct *S)
{
  SFc6_blokowyInstanceStruct *chartInstance;
  chartInstance = (SFc6_blokowyInstanceStruct *)utMalloc(sizeof
    (SFc6_blokowyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_blokowyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_blokowy;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_blokowy;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_blokowy;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_blokowy;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_blokowy;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_blokowy;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_blokowy;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_blokowy;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_blokowy;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_blokowy;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_blokowy;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c6_blokowy_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_blokowy(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_blokowy(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_blokowy(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_blokowy_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
