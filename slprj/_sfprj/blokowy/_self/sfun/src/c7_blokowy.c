/* Include files */

#include <stddef.h>
#include "blas.h"
#include "blokowy_sfun.h"
#include "c7_blokowy.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void initialize_params_c7_blokowy(SFc7_blokowyInstanceStruct
  *chartInstance);
static void enable_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void disable_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_blokowy(SFc7_blokowyInstanceStruct
  *chartInstance);
static void set_sim_state_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_st);
static void finalize_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void sf_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void c7_chartstep_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void initSimStructsc7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void registerMessagesc7_blokowy(SFc7_blokowyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[58]);
static void c7_abs(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x[958],
                   real32_T c7_y[958]);
static void c7_conv2(SFc7_blokowyInstanceStruct *chartInstance, real32_T
                     c7_arg1[960], real32_T c7_arg2[11], real32_T c7_c[960]);
static void c7_mean(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x[960],
                    real32_T c7_y[320]);
static real32_T c7_b_mean(SFc7_blokowyInstanceStruct *chartInstance, real32_T
  c7_x[320]);
static void c7_sum(SFc7_blokowyInstanceStruct *chartInstance, boolean_T c7_x[960],
                   real_T c7_y[320]);
static real_T c7_b_sum(SFc7_blokowyInstanceStruct *chartInstance, real_T c7_x
  [320]);
static void c7_c_sum(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x
                     [960], real32_T c7_y[320]);
static real32_T c7_d_sum(SFc7_blokowyInstanceStruct *chartInstance, real32_T
  c7_x[320]);
static void c7_eml_error(SFc7_blokowyInstanceStruct *chartInstance);
static void c7_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance, const
  mxArray *c7_F, const char_T *c7_identifier, real32_T c7_y[960]);
static void c7_b_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real32_T c7_y[960]);
static void c7_c_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_R, const char_T *c7_identifier, real_T c7_y[3]);
static void c7_d_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static uint8_T c7_e_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_blokowy, const char_T *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sqrt(SFc7_blokowyInstanceStruct *chartInstance, real32_T *c7_x);
static int32_T c7_div_nzp_s32_floor(SFc7_blokowyInstanceStruct *chartInstance,
  int32_T c7_numerator, int32_T c7_denominator);
static void init_dsm_address_info(SFc7_blokowyInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_blokowy = 0U;
}

static void initialize_params_c7_blokowy(SFc7_blokowyInstanceStruct
  *chartInstance)
{
}

static void enable_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c7_blokowy(SFc7_blokowyInstanceStruct
  *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real32_T c7_u[960];
  const mxArray *c7_b_y = NULL;
  real_T c7_b_u[3];
  const mxArray *c7_c_y = NULL;
  uint8_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T (*c7_R)[3];
  real32_T (*c7_F)[960];
  c7_F = (real32_T (*)[960])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_R = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(3), FALSE);
  for (c7_i0 = 0; c7_i0 < 960; c7_i0++) {
    c7_u[c7_i0] = (*c7_F)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 1, 0U, 1U, 0U, 2, 3, 320),
                FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_b_u[c7_i0] = (*c7_R)[c7_i0];
  }

  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_u = chartInstance->c7_is_active_c7_blokowy;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_st)
{
  const mxArray *c7_u;
  real32_T (*c7_F)[960];
  real_T (*c7_R)[3];
  c7_F = (real32_T (*)[960])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_R = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "F",
                      *c7_F);
  c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)), "R",
                        *c7_R);
  chartInstance->c7_is_active_c7_blokowy = c7_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 2)), "is_active_c7_blokowy");
  sf_mex_destroy(&c7_u);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
}

static void sf_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c7_chartstep_c7_blokowy(chartInstance);
}

static void c7_chartstep_c7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
  int32_T c7_idx;
  static real32_T c7_I[76800];
  real_T c7_R[3];
  real_T c7_b_R;
  int32_T c7_i1;
  real32_T c7_F[960];
  real32_T c7_gradient[960];
  real32_T c7_b_I[960];
  real32_T c7_c_I[960];
  real32_T c7_d_I[958];
  static real32_T c7_fv0[11] = { 0.022191F, 0.045589F, 0.079811F, 0.119065F,
    0.151361F, 0.163967F, 0.151361F, 0.119065F, 0.079811F, 0.045589F, 0.022191F
  };

  real32_T c7_fv1[320];
  real32_T c7_numPix;
  boolean_T c7_mask[960];
  real_T c7_dv0[320];
  real32_T c7_fv2[320];
  real32_T c7_f_mean;
  real32_T c7_f_std;
  real32_T c7_scale;
  real32_T c7_f_high;
  real32_T (*c7_b_F)[960];
  real_T (*c7_c_R)[3];
  real_T (*c7_Row)[3];
  real32_T (*c7_e_I)[76800];
  c7_Row = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_F = (real32_T (*)[960])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_e_I = (real32_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
  c7_c_R = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c7_idx = 0; c7_idx < 76800; c7_idx++) {
    c7_I[c7_idx] = (*c7_e_I)[c7_idx];
  }

  for (c7_idx = 0; c7_idx < 3; c7_idx++) {
    c7_R[c7_idx] = (*c7_Row)[c7_idx];
  }

  for (c7_idx = 0; c7_idx < 3; c7_idx++) {
    c7_b_R = c7_R[c7_idx];
    if (c7_R[c7_idx] < 1.0) {
      c7_b_R = 1.0;
    } else {
      if (c7_R[c7_idx] >= 240.0) {
        c7_b_R = 240.0;
      }
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    c7_R[c7_idx] = c7_b_R;
  }

  for (c7_idx = 0; c7_idx < 320; c7_idx++) {
    for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
      c7_F[c7_i1 + 3 * c7_idx] = c7_I[(sf_mex_lw_bounds_check((int32_T)
        c7_R[c7_i1], 1, 240) + 240 * c7_idx) - 1];
    }
  }

  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    c7_gradient[c7_idx] = 0.0F;
  }

  for (c7_idx = 0; c7_idx < 320; c7_idx++) {
    for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
      c7_b_I[c7_i1 + 3 * c7_idx] = c7_I[((int32_T)c7_R[c7_i1] + 240 * c7_idx) -
        1];
      c7_c_I[c7_i1 + 3 * c7_idx] = c7_I[((int32_T)c7_R[c7_i1] + 240 * c7_idx) -
        1];
    }
  }

  for (c7_idx = 0; c7_idx < 958; c7_idx++) {
    c7_d_I[c7_idx] = c7_b_I[c7_idx + 2] - c7_c_I[c7_idx];
  }

  c7_abs(chartInstance, c7_d_I, *(real32_T (*)[958])&c7_gradient[1]);
  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    c7_b_I[c7_idx] = c7_gradient[c7_idx];
  }

  c7_conv2(chartInstance, c7_b_I, c7_fv0, c7_gradient);
  c7_mean(chartInstance, c7_gradient, c7_fv1);
  c7_numPix = c7_b_mean(chartInstance, c7_fv1);
  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    c7_mask[c7_idx] = (c7_gradient[c7_idx] > c7_numPix);
  }

  c7_sum(chartInstance, c7_mask, c7_dv0);
  c7_numPix = (real32_T)c7_b_sum(chartInstance, c7_dv0);
  for (c7_idx = 0; c7_idx < 320; c7_idx++) {
    for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
      c7_b_I[c7_i1 + 3 * c7_idx] = c7_I[((int32_T)c7_R[c7_i1] + 240 * c7_idx) -
        1] * (real32_T)c7_mask[c7_i1 + 3 * c7_idx];
    }
  }

  c7_c_sum(chartInstance, c7_b_I, c7_fv2);
  c7_f_mean = c7_d_sum(chartInstance, c7_fv2) / c7_numPix;
  c7_f_std = 0.0F;
  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    if (c7_mask[c7_idx]) {
      c7_scale = c7_I[((int32_T)c7_R[c7_idx % 3] + 240 * c7_div_nzp_s32_floor
                       (chartInstance, c7_idx, 3)) - 1] - c7_f_mean;
      c7_f_std += c7_scale * c7_scale;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c7_f_std /= c7_numPix;
  c7_sqrt(chartInstance, &c7_f_std);
  c7_f_high = c7_f_mean + c7_f_std * 0.4F;
  c7_numPix = c7_f_mean - c7_f_std * 0.4F;
  c7_scale = 2.0F / (c7_f_high - c7_numPix);
  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    if ((c7_F[c7_idx] > c7_numPix) && (c7_F[c7_idx] < c7_f_high)) {
      c7_f_mean = (c7_f_high - c7_F[c7_idx]) * c7_scale - 1.0F;
    } else if (c7_F[c7_idx] <= c7_numPix) {
      c7_f_mean = 1.0F;
    } else {
      c7_f_mean = -1.0F;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    c7_F[c7_idx] = c7_f_mean;
  }

  for (c7_idx = 0; c7_idx < 3; c7_idx++) {
    (*c7_c_R)[c7_idx] = c7_R[c7_idx] - 1.0;
  }

  for (c7_idx = 0; c7_idx < 960; c7_idx++) {
    (*c7_b_F)[c7_idx] = c7_F[c7_idx];
  }
}

static void initSimStructsc7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
}

static void registerMessagesc7_blokowy(SFc7_blokowyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

const mxArray *sf_c7_blokowy_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[58];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i2;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58), FALSE);
  for (c7_i2 = 0; c7_i2 < 58; c7_i2++) {
    c7_r0 = &c7_info[c7_i2];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i2);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i2);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[58])
{
  c7_info[0].context = "";
  c7_info[0].name = "abs";
  c7_info[0].dominantType = "single";
  c7_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[0].fileTimeLo = 1343830366U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[1].name = "eml_scalar_abs";
  c7_info[1].dominantType = "single";
  c7_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[1].fileTimeLo = 1286818712U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context = "";
  c7_info[2].name = "conv2";
  c7_info[2].dominantType = "single";
  c7_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/conv2.m";
  c7_info[2].fileTimeLo = 1286818682U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/conv2.m!eml_conv2";
  c7_info[3].name = "round";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c7_info[3].fileTimeLo = 1343830384U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c7_info[4].name = "eml_scalar_round";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c7_info[4].fileTimeLo = 1307651238U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/conv2.m!conv2nonsep";
  c7_info[5].name = "eml_scalar_eg";
  c7_info[5].dominantType = "single";
  c7_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[5].fileTimeLo = 1286818796U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/conv2.m!conv2nonsep";
  c7_info[6].name = "mtimes";
  c7_info[6].dominantType = "single";
  c7_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[6].fileTimeLo = 1289519692U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context = "";
  c7_info[7].name = "mean";
  c7_info[7].dominantType = "single";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c7_info[7].fileTimeLo = 1286818694U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c7_info[8].name = "isequal";
  c7_info[8].dominantType = "single";
  c7_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[8].fileTimeLo = 1286818758U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[9].name = "eml_isequal_core";
  c7_info[9].dominantType = "single";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[9].fileTimeLo = 1286818786U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c7_info[10].name = "eml_const_nonsingleton_dim";
  c7_info[10].dominantType = "single";
  c7_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[10].fileTimeLo = 1286818696U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c7_info[11].name = "sum";
  c7_info[11].dominantType = "single";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[11].fileTimeLo = 1314736612U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[12].name = "eml_assert_valid_dim";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c7_info[12].fileTimeLo = 1286818694U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c7_info[13].name = "eml_scalar_floor";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c7_info[13].fileTimeLo = 1286818726U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
  c7_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c7_info[14].name = "eml_index_class";
  c7_info[14].dominantType = "";
  c7_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[14].fileTimeLo = 1323170578U;
  c7_info[14].fileTimeHi = 0U;
  c7_info[14].mFileTimeLo = 0U;
  c7_info[14].mFileTimeHi = 0U;
  c7_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c7_info[15].name = "intmax";
  c7_info[15].dominantType = "char";
  c7_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[15].fileTimeLo = 1311255316U;
  c7_info[15].fileTimeHi = 0U;
  c7_info[15].mFileTimeLo = 0U;
  c7_info[15].mFileTimeHi = 0U;
  c7_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[16].name = "eml_index_class";
  c7_info[16].dominantType = "";
  c7_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[16].fileTimeLo = 1323170578U;
  c7_info[16].fileTimeHi = 0U;
  c7_info[16].mFileTimeLo = 0U;
  c7_info[16].mFileTimeHi = 0U;
  c7_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[17].name = "eml_scalar_eg";
  c7_info[17].dominantType = "single";
  c7_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[17].fileTimeLo = 1286818796U;
  c7_info[17].fileTimeHi = 0U;
  c7_info[17].mFileTimeLo = 0U;
  c7_info[17].mFileTimeHi = 0U;
  c7_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[18].name = "eml_matrix_vstride";
  c7_info[18].dominantType = "single";
  c7_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[18].fileTimeLo = 1286818788U;
  c7_info[18].fileTimeHi = 0U;
  c7_info[18].mFileTimeLo = 0U;
  c7_info[18].mFileTimeHi = 0U;
  c7_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[19].name = "eml_index_minus";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[19].fileTimeLo = 1286818778U;
  c7_info[19].fileTimeHi = 0U;
  c7_info[19].mFileTimeLo = 0U;
  c7_info[19].mFileTimeHi = 0U;
  c7_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[20].name = "eml_index_class";
  c7_info[20].dominantType = "";
  c7_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[20].fileTimeLo = 1323170578U;
  c7_info[20].fileTimeHi = 0U;
  c7_info[20].mFileTimeLo = 0U;
  c7_info[20].mFileTimeHi = 0U;
  c7_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[21].name = "eml_index_class";
  c7_info[21].dominantType = "";
  c7_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[21].fileTimeLo = 1323170578U;
  c7_info[21].fileTimeHi = 0U;
  c7_info[21].mFileTimeLo = 0U;
  c7_info[21].mFileTimeHi = 0U;
  c7_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[22].name = "eml_size_prod";
  c7_info[22].dominantType = "single";
  c7_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[22].fileTimeLo = 1286818798U;
  c7_info[22].fileTimeHi = 0U;
  c7_info[22].mFileTimeLo = 0U;
  c7_info[22].mFileTimeHi = 0U;
  c7_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[23].name = "eml_index_class";
  c7_info[23].dominantType = "";
  c7_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[23].fileTimeLo = 1323170578U;
  c7_info[23].fileTimeHi = 0U;
  c7_info[23].mFileTimeLo = 0U;
  c7_info[23].mFileTimeHi = 0U;
  c7_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[24].name = "eml_matrix_npages";
  c7_info[24].dominantType = "single";
  c7_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[24].fileTimeLo = 1286818786U;
  c7_info[24].fileTimeHi = 0U;
  c7_info[24].mFileTimeLo = 0U;
  c7_info[24].mFileTimeHi = 0U;
  c7_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[25].name = "eml_index_plus";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[25].fileTimeLo = 1286818778U;
  c7_info[25].fileTimeHi = 0U;
  c7_info[25].mFileTimeLo = 0U;
  c7_info[25].mFileTimeHi = 0U;
  c7_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[26].name = "eml_index_class";
  c7_info[26].dominantType = "";
  c7_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[26].fileTimeLo = 1323170578U;
  c7_info[26].fileTimeHi = 0U;
  c7_info[26].mFileTimeLo = 0U;
  c7_info[26].mFileTimeHi = 0U;
  c7_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[27].name = "eml_index_class";
  c7_info[27].dominantType = "";
  c7_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[27].fileTimeLo = 1323170578U;
  c7_info[27].fileTimeHi = 0U;
  c7_info[27].mFileTimeLo = 0U;
  c7_info[27].mFileTimeHi = 0U;
  c7_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[28].name = "eml_size_prod";
  c7_info[28].dominantType = "single";
  c7_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[28].fileTimeLo = 1286818798U;
  c7_info[28].fileTimeHi = 0U;
  c7_info[28].mFileTimeLo = 0U;
  c7_info[28].mFileTimeHi = 0U;
  c7_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[29].name = "eml_index_times";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[29].fileTimeLo = 1286818780U;
  c7_info[29].fileTimeHi = 0U;
  c7_info[29].mFileTimeLo = 0U;
  c7_info[29].mFileTimeHi = 0U;
  c7_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[30].name = "eml_index_class";
  c7_info[30].dominantType = "";
  c7_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[30].fileTimeLo = 1323170578U;
  c7_info[30].fileTimeHi = 0U;
  c7_info[30].mFileTimeLo = 0U;
  c7_info[30].mFileTimeHi = 0U;
  c7_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[31].name = "eml_int_forloop_overflow_check";
  c7_info[31].dominantType = "";
  c7_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[31].fileTimeLo = 1346510340U;
  c7_info[31].fileTimeHi = 0U;
  c7_info[31].mFileTimeLo = 0U;
  c7_info[31].mFileTimeHi = 0U;
  c7_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c7_info[32].name = "intmax";
  c7_info[32].dominantType = "char";
  c7_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[32].fileTimeLo = 1311255316U;
  c7_info[32].fileTimeHi = 0U;
  c7_info[32].mFileTimeLo = 0U;
  c7_info[32].mFileTimeHi = 0U;
  c7_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[33].name = "eml_index_plus";
  c7_info[33].dominantType = "double";
  c7_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[33].fileTimeLo = 1286818778U;
  c7_info[33].fileTimeHi = 0U;
  c7_info[33].mFileTimeLo = 0U;
  c7_info[33].mFileTimeHi = 0U;
  c7_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[34].name = "eml_index_plus";
  c7_info[34].dominantType = "coder.internal.indexInt";
  c7_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[34].fileTimeLo = 1286818778U;
  c7_info[34].fileTimeHi = 0U;
  c7_info[34].mFileTimeLo = 0U;
  c7_info[34].mFileTimeHi = 0U;
  c7_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c7_info[35].name = "rdivide";
  c7_info[35].dominantType = "single";
  c7_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[35].fileTimeLo = 1346510388U;
  c7_info[35].fileTimeHi = 0U;
  c7_info[35].mFileTimeLo = 0U;
  c7_info[35].mFileTimeHi = 0U;
  c7_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[36].name = "eml_scalexp_compatible";
  c7_info[36].dominantType = "single";
  c7_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c7_info[36].fileTimeLo = 1286818796U;
  c7_info[36].fileTimeHi = 0U;
  c7_info[36].mFileTimeLo = 0U;
  c7_info[36].mFileTimeHi = 0U;
  c7_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[37].name = "eml_div";
  c7_info[37].dominantType = "single";
  c7_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[37].fileTimeLo = 1313347810U;
  c7_info[37].fileTimeHi = 0U;
  c7_info[37].mFileTimeLo = 0U;
  c7_info[37].mFileTimeHi = 0U;
  c7_info[38].context = "";
  c7_info[38].name = "sum";
  c7_info[38].dominantType = "logical";
  c7_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[38].fileTimeLo = 1314736612U;
  c7_info[38].fileTimeHi = 0U;
  c7_info[38].mFileTimeLo = 0U;
  c7_info[38].mFileTimeHi = 0U;
  c7_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[39].name = "isequal";
  c7_info[39].dominantType = "double";
  c7_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[39].fileTimeLo = 1286818758U;
  c7_info[39].fileTimeHi = 0U;
  c7_info[39].mFileTimeLo = 0U;
  c7_info[39].mFileTimeHi = 0U;
  c7_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[40].name = "eml_isequal_core";
  c7_info[40].dominantType = "double";
  c7_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[40].fileTimeLo = 1286818786U;
  c7_info[40].fileTimeHi = 0U;
  c7_info[40].mFileTimeLo = 0U;
  c7_info[40].mFileTimeHi = 0U;
  c7_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[41].name = "eml_const_nonsingleton_dim";
  c7_info[41].dominantType = "logical";
  c7_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[41].fileTimeLo = 1286818696U;
  c7_info[41].fileTimeHi = 0U;
  c7_info[41].mFileTimeLo = 0U;
  c7_info[41].mFileTimeHi = 0U;
  c7_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[42].name = "eml_scalar_eg";
  c7_info[42].dominantType = "double";
  c7_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[42].fileTimeLo = 1286818796U;
  c7_info[42].fileTimeHi = 0U;
  c7_info[42].mFileTimeLo = 0U;
  c7_info[42].mFileTimeHi = 0U;
  c7_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[43].name = "eml_matrix_vstride";
  c7_info[43].dominantType = "double";
  c7_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[43].fileTimeLo = 1286818788U;
  c7_info[43].fileTimeHi = 0U;
  c7_info[43].mFileTimeLo = 0U;
  c7_info[43].mFileTimeHi = 0U;
  c7_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c7_info[44].name = "eml_size_prod";
  c7_info[44].dominantType = "logical";
  c7_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[44].fileTimeLo = 1286818798U;
  c7_info[44].fileTimeHi = 0U;
  c7_info[44].mFileTimeLo = 0U;
  c7_info[44].mFileTimeHi = 0U;
  c7_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[45].name = "eml_matrix_npages";
  c7_info[45].dominantType = "double";
  c7_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[45].fileTimeLo = 1286818786U;
  c7_info[45].fileTimeHi = 0U;
  c7_info[45].mFileTimeLo = 0U;
  c7_info[45].mFileTimeHi = 0U;
  c7_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c7_info[46].name = "eml_size_prod";
  c7_info[46].dominantType = "logical";
  c7_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c7_info[46].fileTimeLo = 1286818798U;
  c7_info[46].fileTimeHi = 0U;
  c7_info[46].mFileTimeLo = 0U;
  c7_info[46].mFileTimeHi = 0U;
  c7_info[47].context = "";
  c7_info[47].name = "sum";
  c7_info[47].dominantType = "double";
  c7_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[47].fileTimeLo = 1314736612U;
  c7_info[47].fileTimeHi = 0U;
  c7_info[47].mFileTimeLo = 0U;
  c7_info[47].mFileTimeHi = 0U;
  c7_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[48].name = "eml_const_nonsingleton_dim";
  c7_info[48].dominantType = "double";
  c7_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[48].fileTimeLo = 1286818696U;
  c7_info[48].fileTimeHi = 0U;
  c7_info[48].mFileTimeLo = 0U;
  c7_info[48].mFileTimeHi = 0U;
  c7_info[49].context = "";
  c7_info[49].name = "sum";
  c7_info[49].dominantType = "single";
  c7_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[49].fileTimeLo = 1314736612U;
  c7_info[49].fileTimeHi = 0U;
  c7_info[49].mFileTimeLo = 0U;
  c7_info[49].mFileTimeHi = 0U;
  c7_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[50].name = "isequal";
  c7_info[50].dominantType = "single";
  c7_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[50].fileTimeLo = 1286818758U;
  c7_info[50].fileTimeHi = 0U;
  c7_info[50].mFileTimeLo = 0U;
  c7_info[50].mFileTimeHi = 0U;
  c7_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[51].name = "eml_const_nonsingleton_dim";
  c7_info[51].dominantType = "single";
  c7_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[51].fileTimeLo = 1286818696U;
  c7_info[51].fileTimeHi = 0U;
  c7_info[51].mFileTimeLo = 0U;
  c7_info[51].mFileTimeHi = 0U;
  c7_info[52].context = "";
  c7_info[52].name = "mrdivide";
  c7_info[52].dominantType = "single";
  c7_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[52].fileTimeLo = 1357951548U;
  c7_info[52].fileTimeHi = 0U;
  c7_info[52].mFileTimeLo = 1319729966U;
  c7_info[52].mFileTimeHi = 0U;
  c7_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[53].name = "rdivide";
  c7_info[53].dominantType = "single";
  c7_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[53].fileTimeLo = 1346510388U;
  c7_info[53].fileTimeHi = 0U;
  c7_info[53].mFileTimeLo = 0U;
  c7_info[53].mFileTimeHi = 0U;
  c7_info[54].context = "";
  c7_info[54].name = "mtimes";
  c7_info[54].dominantType = "single";
  c7_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[54].fileTimeLo = 1289519692U;
  c7_info[54].fileTimeHi = 0U;
  c7_info[54].mFileTimeLo = 0U;
  c7_info[54].mFileTimeHi = 0U;
  c7_info[55].context = "";
  c7_info[55].name = "sqrt";
  c7_info[55].dominantType = "single";
  c7_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[55].fileTimeLo = 1343830386U;
  c7_info[55].fileTimeHi = 0U;
  c7_info[55].mFileTimeLo = 0U;
  c7_info[55].mFileTimeHi = 0U;
  c7_info[56].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[56].name = "eml_error";
  c7_info[56].dominantType = "char";
  c7_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[56].fileTimeLo = 1343830358U;
  c7_info[56].fileTimeHi = 0U;
  c7_info[56].mFileTimeLo = 0U;
  c7_info[56].mFileTimeHi = 0U;
  c7_info[57].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[57].name = "eml_scalar_sqrt";
  c7_info[57].dominantType = "single";
  c7_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[57].fileTimeLo = 1286818738U;
  c7_info[57].fileTimeHi = 0U;
  c7_info[57].mFileTimeLo = 0U;
  c7_info[57].mFileTimeHi = 0U;
}

static void c7_abs(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x[958],
                   real32_T c7_y[958])
{
  int32_T c7_k;
  for (c7_k = 0; c7_k < 958; c7_k++) {
    c7_y[c7_k] = muSingleScalarAbs(c7_x[c7_k]);
  }
}

static void c7_conv2(SFc7_blokowyInstanceStruct *chartInstance, real32_T
                     c7_arg1[960], real32_T c7_arg2[11], real32_T c7_c[960])
{
  int32_T c7_jc;
  int32_T c7_ja1;
  int32_T c7_ja2;
  int32_T c7_ic;
  real32_T c7_s;
  int32_T c7_i3;
  int32_T c7_ja;
  int32_T c7_b_ja;
  int32_T c7_jb;
  int32_T c7_ia;
  for (c7_jc = 0; c7_jc < 320; c7_jc++) {
    if (11 < 7 + c7_jc) {
      c7_ja1 = c7_jc - 4;
    } else {
      c7_ja1 = 1;
    }

    if (320 < 6 + c7_jc) {
      c7_ja2 = 314;
    } else {
      c7_ja2 = c7_jc;
    }

    for (c7_ic = 0; c7_ic < 3; c7_ic++) {
      c7_s = 0.0F;
      c7_i3 = (c7_ja2 - c7_ja1) + 6;
      for (c7_ja = 0; c7_ja <= c7_i3; c7_ja++) {
        c7_b_ja = c7_ja1 + c7_ja;
        c7_jb = (c7_jc - c7_b_ja) + 6;
        c7_ia = 0;
        while (c7_ia <= 0) {
          c7_ia = c7_ic;
          c7_s += c7_arg1[c7_ia + 3 * (c7_b_ja - 1)] * c7_arg2[(c7_ic - c7_ia) +
            c7_jb];
          c7_ia = 1;
        }
      }

      c7_c[c7_ic + 3 * c7_jc] = c7_s;
    }
  }
}

static void c7_mean(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x[960],
                    real32_T c7_y[320])
{
  int32_T c7_ix;
  int32_T c7_iy;
  int32_T c7_i;
  int32_T c7_ixstart;
  real32_T c7_s;
  c7_ix = -1;
  c7_iy = -1;
  for (c7_i = 0; c7_i < 320; c7_i++) {
    c7_ixstart = c7_ix + 1;
    c7_ix++;
    c7_s = c7_x[c7_ixstart];
    for (c7_ixstart = 0; c7_ixstart < 2; c7_ixstart++) {
      c7_ix++;
      c7_s += c7_x[c7_ix];
    }

    c7_iy++;
    c7_y[c7_iy] = c7_s;
  }

  for (c7_ixstart = 0; c7_ixstart < 320; c7_ixstart++) {
    c7_y[c7_ixstart] /= 3.0F;
  }
}

static real32_T c7_b_mean(SFc7_blokowyInstanceStruct *chartInstance, real32_T
  c7_x[320])
{
  real32_T c7_y;
  int32_T c7_k;
  c7_y = c7_x[0];
  for (c7_k = 0; c7_k < 319; c7_k++) {
    c7_y += c7_x[c7_k + 1];
  }

  c7_y /= 320.0F;
  return c7_y;
}

static void c7_sum(SFc7_blokowyInstanceStruct *chartInstance, boolean_T c7_x[960],
                   real_T c7_y[320])
{
  int32_T c7_ix;
  int32_T c7_iy;
  int32_T c7_i;
  int32_T c7_ixstart;
  real_T c7_s;
  c7_ix = -1;
  c7_iy = -1;
  for (c7_i = 0; c7_i < 320; c7_i++) {
    c7_ixstart = c7_ix + 1;
    c7_ix++;
    c7_s = (real_T)c7_x[c7_ixstart];
    for (c7_ixstart = 0; c7_ixstart < 2; c7_ixstart++) {
      c7_ix++;
      c7_s += (real_T)c7_x[c7_ix];
    }

    c7_iy++;
    c7_y[c7_iy] = c7_s;
  }
}

static real_T c7_b_sum(SFc7_blokowyInstanceStruct *chartInstance, real_T c7_x
  [320])
{
  real_T c7_y;
  int32_T c7_k;
  c7_y = c7_x[0];
  for (c7_k = 0; c7_k < 319; c7_k++) {
    c7_y += c7_x[c7_k + 1];
  }

  return c7_y;
}

static void c7_c_sum(SFc7_blokowyInstanceStruct *chartInstance, real32_T c7_x
                     [960], real32_T c7_y[320])
{
  int32_T c7_ix;
  int32_T c7_iy;
  int32_T c7_i;
  int32_T c7_ixstart;
  real32_T c7_s;
  c7_ix = -1;
  c7_iy = -1;
  for (c7_i = 0; c7_i < 320; c7_i++) {
    c7_ixstart = c7_ix + 1;
    c7_ix++;
    c7_s = c7_x[c7_ixstart];
    for (c7_ixstart = 0; c7_ixstart < 2; c7_ixstart++) {
      c7_ix++;
      c7_s += c7_x[c7_ix];
    }

    c7_iy++;
    c7_y[c7_iy] = c7_s;
  }
}

static real32_T c7_d_sum(SFc7_blokowyInstanceStruct *chartInstance, real32_T
  c7_x[320])
{
  real32_T c7_y;
  int32_T c7_k;
  c7_y = c7_x[0];
  for (c7_k = 0; c7_k < 319; c7_k++) {
    c7_y += c7_x[c7_k + 1];
  }

  return c7_y;
}

static void c7_eml_error(SFc7_blokowyInstanceStruct *chartInstance)
{
  int32_T c7_i4;
  static char_T c7_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  static char_T c7_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  for (c7_i4 = 0; c7_i4 < 30; c7_i4++) {
    c7_u[c7_i4] = c7_cv0[c7_i4];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c7_i4 = 0; c7_i4 < 4; c7_i4++) {
    c7_b_u[c7_i4] = c7_cv1[c7_i4];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call("error", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c7_y, 14,
    c7_b_y));
}

static void c7_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance, const
  mxArray *c7_F, const char_T *c7_identifier, real32_T c7_y[960])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_F), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_F);
}

static void c7_b_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real32_T c7_y[960])
{
  real32_T c7_fv3[960];
  int32_T c7_i5;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_fv3, 1, 1, 0U, 1, 0U, 2, 3,
                320);
  for (c7_i5 = 0; c7_i5 < 960; c7_i5++) {
    c7_y[c7_i5] = c7_fv3[c7_i5];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_c_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_R, const char_T *c7_identifier, real_T c7_y[3])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_R), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_R);
}

static void c7_d_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv1[3];
  int32_T c7_i6;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c7_i6 = 0; c7_i6 < 3; c7_i6++) {
    c7_y[c7_i6] = c7_dv1[c7_i6];
  }

  sf_mex_destroy(&c7_u);
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_blokowy, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_blokowy), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_blokowy);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_blokowyInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sqrt(SFc7_blokowyInstanceStruct *chartInstance, real32_T *c7_x)
{
  if (*c7_x < 0.0F) {
    c7_eml_error(chartInstance);
  }

  *c7_x = muSingleScalarSqrt(*c7_x);
}

static int32_T c7_div_nzp_s32_floor(SFc7_blokowyInstanceStruct *chartInstance,
  int32_T c7_numerator, int32_T c7_denominator)
{
  int32_T c7_quotient;
  uint32_T c7_absNumerator;
  uint32_T c7_absDenominator;
  int32_T c7_quotientNeedsNegation;
  uint32_T c7_tempAbsQuotient;
  if (c7_numerator >= 0) {
    c7_absNumerator = (uint32_T)c7_numerator;
  } else {
    c7_absNumerator = (uint32_T)-c7_numerator;
  }

  if (c7_denominator >= 0) {
    c7_absDenominator = (uint32_T)c7_denominator;
  } else {
    c7_absDenominator = (uint32_T)-c7_denominator;
  }

  c7_quotientNeedsNegation = (c7_numerator < 0 != c7_denominator < 0);
  c7_tempAbsQuotient = c7_absNumerator / c7_absDenominator;
  if ((uint32_T)c7_quotientNeedsNegation) {
    c7_absNumerator %= c7_absDenominator;
    if (c7_absNumerator > (uint32_T)0) {
      c7_tempAbsQuotient += (uint32_T)1;
    }
  }

  if ((uint32_T)c7_quotientNeedsNegation) {
    c7_quotient = -(int32_T)c7_tempAbsQuotient;
  } else {
    c7_quotient = (int32_T)c7_tempAbsQuotient;
  }

  return c7_quotient;
}

static void init_dsm_address_info(SFc7_blokowyInstanceStruct *chartInstance)
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

void sf_c7_blokowy_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1368957460U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2496458515U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3962457408U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3562357506U);
}

mxArray *sf_c7_blokowy_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eXuRFB128jCPKd4N68UPNE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(240);
      pr[1] = (double)(320);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(320);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_blokowy_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_blokowy(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"F\",},{M[1],M[13],T\"R\",},{M[8],M[0],T\"is_active_c7_blokowy\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_blokowy_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "jov3DNqqdHejHqigu4RHZD";
}

static void sf_opaque_initialize_c7_blokowy(void *chartInstanceVar)
{
  initialize_params_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
  initialize_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_blokowy(void *chartInstanceVar)
{
  enable_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_blokowy(void *chartInstanceVar)
{
  disable_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_blokowy(void *chartInstanceVar)
{
  sf_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_blokowy(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_blokowy((SFc7_blokowyInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_blokowy();/* state var info */
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

extern void sf_internal_set_sim_state_c7_blokowy(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_blokowy();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_blokowy((SFc7_blokowyInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_blokowy(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_blokowy(S);
}

static void sf_opaque_set_sim_state_c7_blokowy(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_blokowy(S, st);
}

static void sf_opaque_terminate_c7_blokowy(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_blokowyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_blokowy_optimization_info();
    }

    finalize_c7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_blokowy((SFc7_blokowyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_blokowy(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_blokowy((SFc7_blokowyInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_blokowy_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4071391767U));
  ssSetChecksum1(S,(1758596491U));
  ssSetChecksum2(S,(2596185966U));
  ssSetChecksum3(S,(24483750U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_blokowy(SimStruct *S)
{
  SFc7_blokowyInstanceStruct *chartInstance;
  chartInstance = (SFc7_blokowyInstanceStruct *)utMalloc(sizeof
    (SFc7_blokowyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_blokowyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_blokowy;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_blokowy;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_blokowy;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_blokowy;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_blokowy;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_blokowy;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_blokowy;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_blokowy;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_blokowy;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_blokowy;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_blokowy;
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

void c7_blokowy_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_blokowy(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_blokowy(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_blokowy(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_blokowy_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
