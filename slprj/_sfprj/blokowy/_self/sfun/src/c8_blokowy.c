/* Include files */

#include <stddef.h>
#include "blas.h"
#include "blokowy_sfun.h"
#include "c8_blokowy.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void initialize_params_c8_blokowy(SFc8_blokowyInstanceStruct
  *chartInstance);
static void enable_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void disable_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_blokowy(SFc8_blokowyInstanceStruct
  *chartInstance);
static void set_sim_state_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_st);
static void finalize_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void sf_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void c8_chartstep_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void initSimStructsc8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void registerMessagesc8_blokowy(SFc8_blokowyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[83]);
static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[83]);
static void c8_check_forloop_overflow_error(SFc8_blokowyInstanceStruct
  *chartInstance, boolean_T c8_overflow);
static void c8_inv(SFc8_blokowyInstanceStruct *chartInstance, real32_T c8_x[9],
                   real32_T c8_y[9]);
static real32_T c8_norm(SFc8_blokowyInstanceStruct *chartInstance, real32_T
  c8_x[9]);
static void c8_eml_warning(SFc8_blokowyInstanceStruct *chartInstance);
static void c8_b_eml_warning(SFc8_blokowyInstanceStruct *chartInstance, char_T
  c8_varargin_2[14]);
static void c8_RecognizeHalfCode(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_codebook[1120], int32_T c8_barBin[1472], int32_T c8_firstBin,
  int32_T c8_numBinInSym, boolean_T c8_isReverse, int32_T c8_code[6], int32_T
  c8_conf[6]);
static real_T c8_sum(SFc8_blokowyInstanceStruct *chartInstance, int32_T c8_x[6]);
static void c8_RecognizeFirstHalfCode(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_LGCode[60], int32_T c8_lcode[6], int32_T c8_lconf[6], int32_T
  c8_gcode[6], int32_T c8_gconf[6], int32_T c8_code[7], int32_T c8_conf[7]);
static void c8_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance, const
  mxArray *c8_sprintf, const char_T *c8_identifier, char_T c8_y[14]);
static void c8_b_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, char_T c8_y[14]);
static void c8_c_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_Code, const char_T *c8_identifier, int32_T c8_y[13]);
static void c8_d_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, int32_T c8_y[13]);
static real32_T c8_e_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_Conf, const char_T *c8_identifier);
static real32_T c8_f_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static uint8_T c8_g_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_blokowy, const char_T *c8_identifier);
static uint8_T c8_h_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_mul_wide_s32(SFc8_blokowyInstanceStruct *chartInstance, int32_T
  c8_in0, int32_T c8_in1, uint32_T *c8_ptrOutBitsHi, uint32_T *c8_ptrOutBitsLo);
static int32_T c8_mul_s32_s32_s32_sat(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_a, int32_T c8_b);
static void init_dsm_address_info(SFc8_blokowyInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_blokowy = 0U;
}

static void initialize_params_c8_blokowy(SFc8_blokowyInstanceStruct
  *chartInstance)
{
}

static void enable_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c8_blokowy(SFc8_blokowyInstanceStruct
  *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  int32_T c8_u[13];
  const mxArray *c8_b_y = NULL;
  real32_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real32_T *c8_Conf;
  int32_T (*c8_Code)[13];
  c8_Conf = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Code = (int32_T (*)[13])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(3), FALSE);
  for (c8_i0 = 0; c8_i0 < 13; c8_i0++) {
    c8_u[c8_i0] = (*c8_Code)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 6, 0U, 1U, 0U, 1, 13), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_u = *c8_Conf;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_u = chartInstance->c8_is_active_c8_blokowy;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_st)
{
  const mxArray *c8_u;
  real32_T *c8_Conf;
  int32_T (*c8_Code)[13];
  c8_Conf = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Code = (int32_T (*)[13])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                        "Code", *c8_Code);
  *c8_Conf = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    1)), "Conf");
  chartInstance->c8_is_active_c8_blokowy = c8_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 2)), "is_active_c8_blokowy");
  sf_mex_destroy(&c8_u);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
}

static void sf_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c8_chartstep_c8_blokowy(chartInstance);
}

static void c8_chartstep_c8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
  int32_T c8_i1;
  int32_T c8_Sequence[270];
  int32_T c8_NumSeq[3];
  int32_T c8_LGCode[60];
  int32_T c8_LCode[1120];
  int32_T c8_GCode[1120];
  int32_T c8_RCode[1120];
  int32_T c8_LCodeRev[1120];
  int32_T c8_GCodeRev[1120];
  int32_T c8_RCodeRev[1120];
  real32_T c8_mapCenter[200];
  real32_T c8_mapWidth[200];
  int32_T c8_barBin[1472];
  int32_T c8_bestConf;
  int32_T c8_bestCode[13];
  int32_T c8_codeAll[13];
  real32_T c8_Center[600];
  real32_T c8_Width[600];
  int32_T c8_iScanline;
  int32_T c8_q0;
  int32_T c8_qY;
  int32_T c8_iSequence;
  real32_T c8_dataMx[9];
  int32_T c8_iSep;
  int32_T c8_q1;
  uint32_T c8_u0;
  int32_T c8_val;
  int32_T c8_b_qY;
  real32_T c8_left;
  real32_T c8_b_dataMx[9];
  real32_T c8_coeff[3];
  real32_T c8_b[3];
  real32_T c8_b_b[2];
  real32_T c8_right;
  real32_T c8_f0;
  int32_T c8_rconfFwd[6];
  int32_T c8_rcodeFwd[6];
  int32_T c8_rconfRev[6];
  int32_T c8_rcodeRev[6];
  int32_T c8_lconfRec[6];
  int32_T c8_lcodeRec[6];
  int32_T c8_gconfRec[6];
  int32_T c8_gcodeRec[6];
  real_T c8_d0;
  int32_T c8_confLeft[7];
  int32_T c8_codeLeft[7];
  int32_T (*c8_Code)[13];
  real32_T *c8_Conf;
  real32_T (*c8_b_Center)[600];
  real32_T (*c8_b_Width)[600];
  int32_T (*c8_b_LCode)[1120];
  int32_T (*c8_b_GCode)[1120];
  int32_T (*c8_b_RCode)[1120];
  int32_T (*c8_b_LCodeRev)[1120];
  int32_T (*c8_b_GCodeRev)[1120];
  int32_T (*c8_b_RCodeRev)[1120];
  int32_T (*c8_b_LGCode)[60];
  int32_T (*c8_b_NumSeq)[3];
  int32_T (*c8_b_Sequence)[270];
  c8_Conf = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Code = (int32_T (*)[13])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_RCodeRev = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 10);
  c8_b_GCodeRev = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 9);
  c8_b_LCodeRev = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 8);
  c8_b_RCode = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 7);
  c8_b_GCode = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 6);
  c8_b_LCode = (int32_T (*)[1120])ssGetInputPortSignal(chartInstance->S, 5);
  c8_b_LGCode = (int32_T (*)[60])ssGetInputPortSignal(chartInstance->S, 4);
  c8_b_NumSeq = (int32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c8_b_Sequence = (int32_T (*)[270])ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_Width = (real32_T (*)[600])ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_Center = (real32_T (*)[600])ssGetInputPortSignal(chartInstance->S, 0);
  for (c8_i1 = 0; c8_i1 < 270; c8_i1++) {
    c8_Sequence[c8_i1] = (*c8_b_Sequence)[c8_i1];
  }

  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    c8_NumSeq[c8_i1] = (*c8_b_NumSeq)[c8_i1];
  }

  for (c8_i1 = 0; c8_i1 < 60; c8_i1++) {
    c8_LGCode[c8_i1] = (*c8_b_LGCode)[c8_i1];
  }

  for (c8_i1 = 0; c8_i1 < 1120; c8_i1++) {
    c8_LCode[c8_i1] = (*c8_b_LCode)[c8_i1];
    c8_GCode[c8_i1] = (*c8_b_GCode)[c8_i1];
    c8_RCode[c8_i1] = (*c8_b_RCode)[c8_i1];
    c8_LCodeRev[c8_i1] = (*c8_b_LCodeRev)[c8_i1];
    c8_GCodeRev[c8_i1] = (*c8_b_GCodeRev)[c8_i1];
    c8_RCodeRev[c8_i1] = (*c8_b_RCodeRev)[c8_i1];
  }

  for (c8_i1 = 0; c8_i1 < 200; c8_i1++) {
    c8_mapCenter[c8_i1] = 0.0F;
    c8_mapWidth[c8_i1] = 0.0F;
  }

  for (c8_i1 = 0; c8_i1 < 1472; c8_i1++) {
    c8_barBin[c8_i1] = 0;
  }

  c8_bestConf = 0;
  for (c8_i1 = 0; c8_i1 < 13; c8_i1++) {
    c8_bestCode[c8_i1] = 0;
    c8_codeAll[c8_i1] = 0;
  }

  for (c8_i1 = 0; c8_i1 < 600; c8_i1++) {
    c8_Center[c8_i1] = (*c8_b_Center)[c8_i1] / 92.0F;
    c8_Width[c8_i1] = (*c8_b_Width)[c8_i1] / 92.0F;
  }

  for (c8_iScanline = 0; c8_iScanline < 3; c8_iScanline++) {
    c8_q0 = c8_NumSeq[c8_iScanline];
    c8_qY = c8_q0 - 1;
    if ((c8_q0 < 0) && (c8_qY >= 0)) {
      c8_qY = MIN_int32_T;
    }

    c8_iSequence = 0;
    while (c8_iSequence <= c8_qY) {
      for (c8_i1 = 0; c8_i1 < 9; c8_i1++) {
        c8_dataMx[c8_i1] = 0.0F;
      }

      for (c8_iSep = 0; c8_iSep < 3; c8_iSep++) {
        c8_q1 = c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence);
        c8_u0 = (uint32_T)muDoubleScalarRound((real_T)((uint32_T)
          c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence) + (uint32_T)(1
          + c8_iSep)));
        if (c8_u0 < 2147483648U) {
          c8_i1 = (int32_T)c8_u0;
        } else {
          c8_i1 = MAX_int32_T;
        }

        sf_mex_lw_bounds_check(c8_i1, 1, 90);
        c8_u0 = (uint32_T)muDoubleScalarRound((real_T)((uint32_T)c8_q1 +
          (uint32_T)(1 + c8_iSep)));
        if (c8_u0 < 2147483648U) {
          c8_i1 = (int32_T)c8_u0;
        } else {
          c8_i1 = MAX_int32_T;
        }

        c8_u0 = (uint32_T)muDoubleScalarRound((real_T)((uint32_T)c8_q1 +
          (uint32_T)(1 + c8_iSep)));
        if (c8_u0 < 2147483648U) {
          c8_val = (int32_T)c8_u0;
        } else {
          c8_val = MAX_int32_T;
        }

        c8_q0 = c8_Sequence[(c8_val + 90 * c8_iScanline) - 1];
        c8_b_qY = c8_q0 + 1;
        if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
          c8_b_qY = MAX_int32_T;
        }

        c8_u0 = (uint32_T)muDoubleScalarRound((real_T)((uint32_T)c8_q1 +
          (uint32_T)(1 + c8_iSep)));
        if (c8_u0 < 2147483648U) {
          c8_val = (int32_T)c8_u0;
        } else {
          c8_val = MAX_int32_T;
        }

        c8_q0 = c8_Sequence[(c8_val + 90 * c8_iScanline) - 1];
        c8_q1 = c8_q0 + 2;
        if ((c8_q0 > 0) && (c8_q1 <= 0)) {
          c8_q1 = MAX_int32_T;
        }

        c8_left = (c8_Center[(sf_mex_lw_bounds_check(c8_Sequence[(c8_i1 + 90 *
          c8_iScanline) - 1], 1, 200) + 200 * c8_iScanline) - 1] + c8_Center
                   [(sf_mex_lw_bounds_check(c8_b_qY, 1, 200) + 200 *
                     c8_iScanline) - 1]) + c8_Center[(sf_mex_lw_bounds_check
          (c8_q1, 1, 200) + 200 * c8_iScanline) - 1];
        c8_left /= 3.0F;
        c8_dataMx[c8_iSep] = c8_left * c8_left;
        c8_dataMx[3 + c8_iSep] = c8_left;
        c8_dataMx[6 + c8_iSep] = 1.0F;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      for (c8_i1 = 0; c8_i1 < 9; c8_i1++) {
        c8_b_dataMx[c8_i1] = c8_dataMx[c8_i1];
      }

      c8_inv(chartInstance, c8_b_dataMx, c8_dataMx);
      for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
        c8_coeff[c8_i1] = 0.0F;
        c8_val = 0;
        for (c8_q1 = 0; c8_q1 < 3; c8_q1++) {
          c8_coeff[c8_i1] += c8_dataMx[c8_val + c8_i1] * (46.0F * (real32_T)
            c8_q1);
          c8_val += 3;
        }
      }

      c8_q0 = c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence);
      c8_b_qY = c8_q0 + 1;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_q0 = c8_Sequence[(sf_mex_lw_bounds_check(c8_b_qY, 1, 90) + 90 *
                           c8_iScanline) - 1];
      c8_b_qY = c8_q0 + 3;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_iSep = c8_b_qY - 1;
      c8_q0 = c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence);
      c8_b_qY = c8_q0 + 3;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_q0 = c8_Sequence[(sf_mex_lw_bounds_check(c8_b_qY, 1, 90) + 90 *
                           c8_iScanline) - 1];
      c8_b_qY = c8_q0 - 1;
      if ((c8_q0 < 0) && (c8_b_qY >= 0)) {
        c8_b_qY = MIN_int32_T;
      }

      while (c8_iSep + 1 <= c8_b_qY) {
        sf_mex_lw_bounds_check(c8_iSep + 1, 1, 200);
        c8_b[0] = c8_Center[c8_iSep + 200 * c8_iScanline] * c8_Center[c8_iSep +
          200 * c8_iScanline];
        c8_b[1] = c8_Center[c8_iSep + 200 * c8_iScanline];
        c8_b[2] = 1.0F;
        c8_left = 0.0F;
        for (c8_q1 = 0; c8_q1 < 3; c8_q1++) {
          c8_left += c8_coeff[c8_q1] * c8_b[c8_q1];
        }

        c8_mapCenter[c8_iSep] = c8_left;
        c8_b_b[0] = 2.0F * c8_Width[c8_iSep + 200 * c8_iScanline];
        c8_b_b[1] = 1.0F;
        c8_left = 0.0F;
        for (c8_q1 = 0; c8_q1 < 2; c8_q1++) {
          c8_left += c8_coeff[c8_q1] * c8_b_b[c8_q1];
        }

        c8_mapWidth[c8_iSep] = c8_left * c8_Width[c8_iSep + 200 * c8_iScanline];
        c8_iSep++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c8_val = -1;
      c8_q0 = c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence);
      c8_b_qY = c8_q0 + 1;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_q0 = c8_Sequence[(sf_mex_lw_bounds_check(c8_b_qY, 1, 90) + 90 *
                           c8_iScanline) - 1];
      c8_b_qY = c8_q0 + 3;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_iSep = c8_b_qY - 1;
      c8_q0 = c8_mul_s32_s32_s32_sat(chartInstance, 3, c8_iSequence);
      c8_b_qY = c8_q0 + 3;
      if ((c8_q0 > 0) && (c8_b_qY <= 0)) {
        c8_b_qY = MAX_int32_T;
      }

      c8_q0 = c8_Sequence[(sf_mex_lw_bounds_check(c8_b_qY, 1, 90) + 90 *
                           c8_iScanline) - 1];
      c8_b_qY = c8_q0 - 1;
      if ((c8_q0 < 0) && (c8_b_qY >= 0)) {
        c8_b_qY = MIN_int32_T;
      }

      while (c8_iSep + 1 <= c8_b_qY) {
        sf_mex_lw_bounds_check(c8_iSep + 1, 1, 200);
        c8_left = (c8_mapCenter[c8_iSep] - c8_mapWidth[c8_iSep] / 2.0F) * 16.0F;
        c8_right = c8_left + c8_mapWidth[c8_iSep] * 16.0F;
        if ((c8_left < 1.0F) || muSingleScalarIsNaN(c8_left)) {
          c8_left = 1.0F;
        }

        c8_right = muSingleScalarMin(c8_right, 1472.0F);
        c8_f0 = muSingleScalarRound(c8_left);
        c8_left = muSingleScalarRound(c8_right);
        c8_i1 = (int32_T)(c8_left + (1.0F - c8_f0));
        sf_mex_lw_for_loop_vector_check((real_T)c8_f0, 1.0, (real_T)c8_left,
          mxSINGLE_CLASS, c8_i1);
        c8_q1 = 0;
        while (c8_q1 <= c8_i1 - 1) {
          c8_barBin[sf_mex_lw_bounds_check((int32_T)(c8_f0 + (real32_T)c8_q1), 1,
            1472) - 1] = c8_val;
          c8_q1++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        c8_val = -c8_val;
        c8_iSep++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c8_RecognizeHalfCode(chartInstance, c8_RCode, c8_barBin, 776, 112, FALSE,
                           c8_rcodeFwd, c8_rconfFwd);
      c8_RecognizeHalfCode(chartInstance, c8_RCodeRev, c8_barBin, 24, 112, TRUE,
                           c8_rcodeRev, c8_rconfRev);
      if (c8_sum(chartInstance, c8_rconfFwd) > c8_sum(chartInstance, c8_rconfRev))
      {
        c8_RecognizeHalfCode(chartInstance, c8_LCode, c8_barBin, 24, 112, FALSE,
                             c8_lcodeRec, c8_lconfRec);
        c8_RecognizeHalfCode(chartInstance, c8_GCode, c8_barBin, 24, 112, FALSE,
                             c8_gcodeRec, c8_gconfRec);
        for (c8_i1 = 0; c8_i1 < 6; c8_i1++) {
          c8_codeAll[c8_i1 + 7] = c8_rcodeFwd[c8_i1];
        }

        c8_d0 = muDoubleScalarRound(c8_sum(chartInstance, c8_rconfFwd));
        if (c8_d0 < 2.147483648E+9) {
          if (c8_d0 >= -2.147483648E+9) {
            c8_val = (int32_T)c8_d0;
          } else {
            c8_val = MIN_int32_T;
          }
        } else if (c8_d0 >= 2.147483648E+9) {
          c8_val = MAX_int32_T;
        } else {
          c8_val = 0;
        }
      } else {
        c8_RecognizeHalfCode(chartInstance, c8_LCodeRev, c8_barBin, 776, 112,
                             TRUE, c8_lcodeRec, c8_lconfRec);
        c8_RecognizeHalfCode(chartInstance, c8_GCodeRev, c8_barBin, 776, 112,
                             TRUE, c8_gcodeRec, c8_gconfRec);
        for (c8_i1 = 0; c8_i1 < 6; c8_i1++) {
          c8_codeAll[c8_i1 + 7] = c8_rcodeRev[c8_i1];
        }

        c8_d0 = muDoubleScalarRound(c8_sum(chartInstance, c8_rconfRev));
        if (c8_d0 < 2.147483648E+9) {
          if (c8_d0 >= -2.147483648E+9) {
            c8_val = (int32_T)c8_d0;
          } else {
            c8_val = MIN_int32_T;
          }
        } else if (c8_d0 >= 2.147483648E+9) {
          c8_val = MAX_int32_T;
        } else {
          c8_val = 0;
        }
      }

      c8_RecognizeFirstHalfCode(chartInstance, c8_LGCode, c8_lcodeRec,
        c8_lconfRec, c8_gcodeRec, c8_gconfRec, c8_codeLeft, c8_confLeft);
      for (c8_i1 = 0; c8_i1 < 7; c8_i1++) {
        c8_codeAll[c8_i1] = c8_codeLeft[c8_i1];
      }

      c8_q1 = c8_confLeft[0];
      c8_b_qY = c8_val + c8_q1;
      if ((c8_val < 0) && ((c8_q1 < 0) && (c8_b_qY >= 0))) {
        c8_b_qY = MIN_int32_T;
      } else {
        if ((c8_val > 0) && ((c8_q1 > 0) && (c8_b_qY <= 0))) {
          c8_b_qY = MAX_int32_T;
        }
      }

      c8_val = c8_b_qY;
      if (c8_bestConf < c8_val) {
        for (c8_i1 = 0; c8_i1 < 13; c8_i1++) {
          c8_bestCode[c8_i1] = c8_codeAll[c8_i1];
        }

        c8_bestConf = c8_val;
      }

      c8_iSequence++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c8_i1 = 0; c8_i1 < 13; c8_i1++) {
    (*c8_Code)[c8_i1] = c8_bestCode[c8_i1];
  }

  *c8_Conf = (real32_T)c8_bestConf / 1344.0F;
}

static void initSimStructsc8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
}

static void registerMessagesc8_blokowy(SFc8_blokowyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

const mxArray *sf_c8_blokowy_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[83];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i2;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 83), FALSE);
  for (c8_i2 = 0; c8_i2 < 83; c8_i2++) {
    c8_r0 = &c8_info[c8_i2];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i2);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i2);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[83])
{
  c8_info[0].context = "";
  c8_info[0].name = "mtimes";
  c8_info[0].dominantType = "int32";
  c8_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[0].fileTimeLo = 1289519692U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "";
  c8_info[1].name = "mrdivide";
  c8_info[1].dominantType = "single";
  c8_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[1].fileTimeLo = 1357951548U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 1319729966U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[2].name = "rdivide";
  c8_info[2].dominantType = "single";
  c8_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[2].fileTimeLo = 1346510388U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[3].name = "eml_scalexp_compatible";
  c8_info[3].dominantType = "single";
  c8_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c8_info[3].fileTimeLo = 1286818796U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[4].name = "eml_div";
  c8_info[4].dominantType = "single";
  c8_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[4].fileTimeLo = 1313347810U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "";
  c8_info[5].name = "eml_int_forloop_overflow_check";
  c8_info[5].dominantType = "";
  c8_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[5].fileTimeLo = 1346510340U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[6].name = "intmax";
  c8_info[6].dominantType = "char";
  c8_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[6].fileTimeLo = 1311255316U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context = "";
  c8_info[7].name = "mpower";
  c8_info[7].dominantType = "single";
  c8_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[7].fileTimeLo = 1286818842U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[8].name = "power";
  c8_info[8].dominantType = "single";
  c8_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[8].fileTimeLo = 1348191930U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[9].name = "eml_scalar_eg";
  c8_info[9].dominantType = "single";
  c8_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[9].fileTimeLo = 1286818796U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[10].name = "eml_scalexp_alloc";
  c8_info[10].dominantType = "single";
  c8_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[10].fileTimeLo = 1352424860U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[11].name = "floor";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[11].fileTimeLo = 1343830380U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[12].name = "eml_scalar_floor";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[12].fileTimeLo = 1286818726U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[13].name = "eml_scalar_eg";
  c8_info[13].dominantType = "single";
  c8_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[13].fileTimeLo = 1286818796U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[14].name = "mtimes";
  c8_info[14].dominantType = "single";
  c8_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[14].fileTimeLo = 1289519692U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context = "";
  c8_info[15].name = "inv";
  c8_info[15].dominantType = "single";
  c8_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c8_info[15].fileTimeLo = 1305318000U;
  c8_info[15].fileTimeHi = 0U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
  c8_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c8_info[16].name = "eml_index_class";
  c8_info[16].dominantType = "";
  c8_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[16].fileTimeLo = 1323170578U;
  c8_info[16].fileTimeHi = 0U;
  c8_info[16].mFileTimeLo = 0U;
  c8_info[16].mFileTimeHi = 0U;
  c8_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c8_info[17].name = "abs";
  c8_info[17].dominantType = "single";
  c8_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[17].fileTimeLo = 1343830366U;
  c8_info[17].fileTimeHi = 0U;
  c8_info[17].mFileTimeLo = 0U;
  c8_info[17].mFileTimeHi = 0U;
  c8_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[18].name = "eml_scalar_abs";
  c8_info[18].dominantType = "single";
  c8_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[18].fileTimeLo = 1286818712U;
  c8_info[18].fileTimeHi = 0U;
  c8_info[18].mFileTimeLo = 0U;
  c8_info[18].mFileTimeHi = 0U;
  c8_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c8_info[19].name = "eml_div";
  c8_info[19].dominantType = "single";
  c8_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[19].fileTimeLo = 1313347810U;
  c8_info[19].fileTimeHi = 0U;
  c8_info[19].mFileTimeLo = 0U;
  c8_info[19].mFileTimeHi = 0U;
  c8_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c8_info[20].name = "mtimes";
  c8_info[20].dominantType = "single";
  c8_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[20].fileTimeLo = 1289519692U;
  c8_info[20].fileTimeHi = 0U;
  c8_info[20].mFileTimeLo = 0U;
  c8_info[20].mFileTimeHi = 0U;
  c8_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c8_info[21].name = "eml_index_plus";
  c8_info[21].dominantType = "double";
  c8_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[21].fileTimeLo = 1286818778U;
  c8_info[21].fileTimeHi = 0U;
  c8_info[21].mFileTimeLo = 0U;
  c8_info[21].mFileTimeHi = 0U;
  c8_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[22].name = "eml_index_class";
  c8_info[22].dominantType = "";
  c8_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[22].fileTimeLo = 1323170578U;
  c8_info[22].fileTimeHi = 0U;
  c8_info[22].mFileTimeLo = 0U;
  c8_info[22].mFileTimeHi = 0U;
  c8_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[23].name = "norm";
  c8_info[23].dominantType = "single";
  c8_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[23].fileTimeLo = 1336522094U;
  c8_info[23].fileTimeHi = 0U;
  c8_info[23].mFileTimeLo = 0U;
  c8_info[23].mFileTimeHi = 0U;
  c8_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[24].name = "abs";
  c8_info[24].dominantType = "single";
  c8_info[24].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[24].fileTimeLo = 1343830366U;
  c8_info[24].fileTimeHi = 0U;
  c8_info[24].mFileTimeLo = 0U;
  c8_info[24].mFileTimeHi = 0U;
  c8_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[25].name = "isnan";
  c8_info[25].dominantType = "single";
  c8_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[25].fileTimeLo = 1286818760U;
  c8_info[25].fileTimeHi = 0U;
  c8_info[25].mFileTimeLo = 0U;
  c8_info[25].mFileTimeHi = 0U;
  c8_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[26].name = "eml_guarded_nan";
  c8_info[26].dominantType = "char";
  c8_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[26].fileTimeLo = 1286818776U;
  c8_info[26].fileTimeHi = 0U;
  c8_info[26].mFileTimeLo = 0U;
  c8_info[26].mFileTimeHi = 0U;
  c8_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[27].name = "eml_is_float_class";
  c8_info[27].dominantType = "char";
  c8_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[27].fileTimeLo = 1286818782U;
  c8_info[27].fileTimeHi = 0U;
  c8_info[27].mFileTimeLo = 0U;
  c8_info[27].mFileTimeHi = 0U;
  c8_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[28].name = "mtimes";
  c8_info[28].dominantType = "single";
  c8_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[28].fileTimeLo = 1289519692U;
  c8_info[28].fileTimeHi = 0U;
  c8_info[28].mFileTimeLo = 0U;
  c8_info[28].mFileTimeHi = 0U;
  c8_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[29].name = "eml_warning";
  c8_info[29].dominantType = "char";
  c8_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c8_info[29].fileTimeLo = 1286818802U;
  c8_info[29].fileTimeHi = 0U;
  c8_info[29].mFileTimeLo = 0U;
  c8_info[29].mFileTimeHi = 0U;
  c8_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[30].name = "isnan";
  c8_info[30].dominantType = "single";
  c8_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[30].fileTimeLo = 1286818760U;
  c8_info[30].fileTimeHi = 0U;
  c8_info[30].mFileTimeLo = 0U;
  c8_info[30].mFileTimeHi = 0U;
  c8_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[31].name = "eps";
  c8_info[31].dominantType = "char";
  c8_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[31].fileTimeLo = 1326727996U;
  c8_info[31].fileTimeHi = 0U;
  c8_info[31].mFileTimeLo = 0U;
  c8_info[31].mFileTimeHi = 0U;
  c8_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[32].name = "eml_is_float_class";
  c8_info[32].dominantType = "char";
  c8_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[32].fileTimeLo = 1286818782U;
  c8_info[32].fileTimeHi = 0U;
  c8_info[32].mFileTimeLo = 0U;
  c8_info[32].mFileTimeHi = 0U;
  c8_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[33].name = "eml_eps";
  c8_info[33].dominantType = "char";
  c8_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[33].fileTimeLo = 1326727996U;
  c8_info[33].fileTimeHi = 0U;
  c8_info[33].mFileTimeLo = 0U;
  c8_info[33].mFileTimeHi = 0U;
  c8_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[34].name = "eml_float_model";
  c8_info[34].dominantType = "char";
  c8_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[34].fileTimeLo = 1326727996U;
  c8_info[34].fileTimeHi = 0U;
  c8_info[34].mFileTimeLo = 0U;
  c8_info[34].mFileTimeHi = 0U;
  c8_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[35].name = "eml_flt2str";
  c8_info[35].dominantType = "single";
  c8_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c8_info[35].fileTimeLo = 1309451196U;
  c8_info[35].fileTimeHi = 0U;
  c8_info[35].mFileTimeLo = 0U;
  c8_info[35].mFileTimeHi = 0U;
  c8_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c8_info[36].name = "char";
  c8_info[36].dominantType = "double";
  c8_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c8_info[36].fileTimeLo = 1319729968U;
  c8_info[36].fileTimeHi = 0U;
  c8_info[36].mFileTimeLo = 0U;
  c8_info[36].mFileTimeHi = 0U;
  c8_info[37].context = "";
  c8_info[37].name = "mtimes";
  c8_info[37].dominantType = "single";
  c8_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[37].fileTimeLo = 1289519692U;
  c8_info[37].fileTimeHi = 0U;
  c8_info[37].mFileTimeLo = 0U;
  c8_info[37].mFileTimeHi = 0U;
  c8_info[38].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[38].name = "eml_index_class";
  c8_info[38].dominantType = "";
  c8_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[38].fileTimeLo = 1323170578U;
  c8_info[38].fileTimeHi = 0U;
  c8_info[38].mFileTimeLo = 0U;
  c8_info[38].mFileTimeHi = 0U;
  c8_info[39].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[39].name = "eml_scalar_eg";
  c8_info[39].dominantType = "single";
  c8_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[39].fileTimeLo = 1286818796U;
  c8_info[39].fileTimeHi = 0U;
  c8_info[39].mFileTimeLo = 0U;
  c8_info[39].mFileTimeHi = 0U;
  c8_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[40].name = "eml_xgemm";
  c8_info[40].dominantType = "single";
  c8_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[40].fileTimeLo = 1299076772U;
  c8_info[40].fileTimeHi = 0U;
  c8_info[40].mFileTimeLo = 0U;
  c8_info[40].mFileTimeHi = 0U;
  c8_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[41].name = "eml_blas_inline";
  c8_info[41].dominantType = "";
  c8_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[41].fileTimeLo = 1299076768U;
  c8_info[41].fileTimeHi = 0U;
  c8_info[41].mFileTimeLo = 0U;
  c8_info[41].mFileTimeHi = 0U;
  c8_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c8_info[42].name = "mtimes";
  c8_info[42].dominantType = "double";
  c8_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[42].fileTimeLo = 1289519692U;
  c8_info[42].fileTimeHi = 0U;
  c8_info[42].mFileTimeLo = 0U;
  c8_info[42].mFileTimeHi = 0U;
  c8_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[43].name = "eml_index_class";
  c8_info[43].dominantType = "";
  c8_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[43].fileTimeLo = 1323170578U;
  c8_info[43].fileTimeHi = 0U;
  c8_info[43].mFileTimeLo = 0U;
  c8_info[43].mFileTimeHi = 0U;
  c8_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[44].name = "eml_scalar_eg";
  c8_info[44].dominantType = "single";
  c8_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[44].fileTimeLo = 1286818796U;
  c8_info[44].fileTimeHi = 0U;
  c8_info[44].mFileTimeLo = 0U;
  c8_info[44].mFileTimeHi = 0U;
  c8_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[45].name = "eml_refblas_xgemm";
  c8_info[45].dominantType = "single";
  c8_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[45].fileTimeLo = 1299076774U;
  c8_info[45].fileTimeHi = 0U;
  c8_info[45].mFileTimeLo = 0U;
  c8_info[45].mFileTimeHi = 0U;
  c8_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[46].name = "eml_xdotu";
  c8_info[46].dominantType = "single";
  c8_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[46].fileTimeLo = 1299076772U;
  c8_info[46].fileTimeHi = 0U;
  c8_info[46].mFileTimeLo = 0U;
  c8_info[46].mFileTimeHi = 0U;
  c8_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[47].name = "eml_blas_inline";
  c8_info[47].dominantType = "";
  c8_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[47].fileTimeLo = 1299076768U;
  c8_info[47].fileTimeHi = 0U;
  c8_info[47].mFileTimeLo = 0U;
  c8_info[47].mFileTimeHi = 0U;
  c8_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[48].name = "eml_xdot";
  c8_info[48].dominantType = "single";
  c8_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[48].fileTimeLo = 1299076772U;
  c8_info[48].fileTimeHi = 0U;
  c8_info[48].mFileTimeLo = 0U;
  c8_info[48].mFileTimeHi = 0U;
  c8_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[49].name = "eml_blas_inline";
  c8_info[49].dominantType = "";
  c8_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[49].fileTimeLo = 1299076768U;
  c8_info[49].fileTimeHi = 0U;
  c8_info[49].mFileTimeLo = 0U;
  c8_info[49].mFileTimeHi = 0U;
  c8_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[50].name = "eml_index_class";
  c8_info[50].dominantType = "";
  c8_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[50].fileTimeLo = 1323170578U;
  c8_info[50].fileTimeHi = 0U;
  c8_info[50].mFileTimeLo = 0U;
  c8_info[50].mFileTimeHi = 0U;
  c8_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[51].name = "eml_refblas_xdot";
  c8_info[51].dominantType = "single";
  c8_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[51].fileTimeLo = 1299076772U;
  c8_info[51].fileTimeHi = 0U;
  c8_info[51].mFileTimeLo = 0U;
  c8_info[51].mFileTimeHi = 0U;
  c8_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[52].name = "eml_refblas_xdotx";
  c8_info[52].dominantType = "single";
  c8_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[52].fileTimeLo = 1299076774U;
  c8_info[52].fileTimeHi = 0U;
  c8_info[52].mFileTimeLo = 0U;
  c8_info[52].mFileTimeHi = 0U;
  c8_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[53].name = "eml_scalar_eg";
  c8_info[53].dominantType = "single";
  c8_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[53].fileTimeLo = 1286818796U;
  c8_info[53].fileTimeHi = 0U;
  c8_info[53].mFileTimeLo = 0U;
  c8_info[53].mFileTimeHi = 0U;
  c8_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[54].name = "eml_index_class";
  c8_info[54].dominantType = "";
  c8_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[54].fileTimeLo = 1323170578U;
  c8_info[54].fileTimeHi = 0U;
  c8_info[54].mFileTimeLo = 0U;
  c8_info[54].mFileTimeHi = 0U;
  c8_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[55].name = "eml_index_minus";
  c8_info[55].dominantType = "double";
  c8_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[55].fileTimeLo = 1286818778U;
  c8_info[55].fileTimeHi = 0U;
  c8_info[55].mFileTimeLo = 0U;
  c8_info[55].mFileTimeHi = 0U;
  c8_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[56].name = "eml_index_class";
  c8_info[56].dominantType = "";
  c8_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[56].fileTimeLo = 1323170578U;
  c8_info[56].fileTimeHi = 0U;
  c8_info[56].mFileTimeLo = 0U;
  c8_info[56].mFileTimeHi = 0U;
  c8_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[57].name = "eml_index_times";
  c8_info[57].dominantType = "coder.internal.indexInt";
  c8_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[57].fileTimeLo = 1286818780U;
  c8_info[57].fileTimeHi = 0U;
  c8_info[57].mFileTimeLo = 0U;
  c8_info[57].mFileTimeHi = 0U;
  c8_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[58].name = "eml_index_class";
  c8_info[58].dominantType = "";
  c8_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[58].fileTimeLo = 1323170578U;
  c8_info[58].fileTimeHi = 0U;
  c8_info[58].mFileTimeLo = 0U;
  c8_info[58].mFileTimeHi = 0U;
  c8_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[59].name = "eml_index_plus";
  c8_info[59].dominantType = "coder.internal.indexInt";
  c8_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[59].fileTimeLo = 1286818778U;
  c8_info[59].fileTimeHi = 0U;
  c8_info[59].mFileTimeLo = 0U;
  c8_info[59].mFileTimeHi = 0U;
  c8_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[60].name = "eml_int_forloop_overflow_check";
  c8_info[60].dominantType = "";
  c8_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[60].fileTimeLo = 1346510340U;
  c8_info[60].fileTimeHi = 0U;
  c8_info[60].mFileTimeLo = 0U;
  c8_info[60].mFileTimeHi = 0U;
  c8_info[61].context = "";
  c8_info[61].name = "max";
  c8_info[61].dominantType = "single";
  c8_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c8_info[61].fileTimeLo = 1311255316U;
  c8_info[61].fileTimeHi = 0U;
  c8_info[61].mFileTimeLo = 0U;
  c8_info[61].mFileTimeHi = 0U;
  c8_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c8_info[62].name = "eml_min_or_max";
  c8_info[62].dominantType = "single";
  c8_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[62].fileTimeLo = 1334071490U;
  c8_info[62].fileTimeHi = 0U;
  c8_info[62].mFileTimeLo = 0U;
  c8_info[62].mFileTimeHi = 0U;
  c8_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[63].name = "eml_scalar_eg";
  c8_info[63].dominantType = "single";
  c8_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[63].fileTimeLo = 1286818796U;
  c8_info[63].fileTimeHi = 0U;
  c8_info[63].mFileTimeLo = 0U;
  c8_info[63].mFileTimeHi = 0U;
}

static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[83])
{
  c8_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[64].name = "eml_scalexp_alloc";
  c8_info[64].dominantType = "single";
  c8_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[64].fileTimeLo = 1352424860U;
  c8_info[64].fileTimeHi = 0U;
  c8_info[64].mFileTimeLo = 0U;
  c8_info[64].mFileTimeHi = 0U;
  c8_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[65].name = "eml_index_class";
  c8_info[65].dominantType = "";
  c8_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[65].fileTimeLo = 1323170578U;
  c8_info[65].fileTimeHi = 0U;
  c8_info[65].mFileTimeLo = 0U;
  c8_info[65].mFileTimeHi = 0U;
  c8_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[66].name = "eml_scalar_eg";
  c8_info[66].dominantType = "single";
  c8_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[66].fileTimeLo = 1286818796U;
  c8_info[66].fileTimeHi = 0U;
  c8_info[66].mFileTimeLo = 0U;
  c8_info[66].mFileTimeHi = 0U;
  c8_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[67].name = "eml_relop";
  c8_info[67].dominantType = "function_handle";
  c8_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c8_info[67].fileTimeLo = 1342451182U;
  c8_info[67].fileTimeHi = 0U;
  c8_info[67].mFileTimeLo = 0U;
  c8_info[67].mFileTimeHi = 0U;
  c8_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[68].name = "isnan";
  c8_info[68].dominantType = "single";
  c8_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[68].fileTimeLo = 1286818760U;
  c8_info[68].fileTimeHi = 0U;
  c8_info[68].mFileTimeLo = 0U;
  c8_info[68].mFileTimeHi = 0U;
  c8_info[69].context = "";
  c8_info[69].name = "min";
  c8_info[69].dominantType = "single";
  c8_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[69].fileTimeLo = 1311255318U;
  c8_info[69].fileTimeHi = 0U;
  c8_info[69].mFileTimeLo = 0U;
  c8_info[69].mFileTimeHi = 0U;
  c8_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[70].name = "eml_min_or_max";
  c8_info[70].dominantType = "single";
  c8_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[70].fileTimeLo = 1334071490U;
  c8_info[70].fileTimeHi = 0U;
  c8_info[70].mFileTimeLo = 0U;
  c8_info[70].mFileTimeHi = 0U;
  c8_info[71].context = "";
  c8_info[71].name = "round";
  c8_info[71].dominantType = "single";
  c8_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c8_info[71].fileTimeLo = 1343830384U;
  c8_info[71].fileTimeHi = 0U;
  c8_info[71].mFileTimeLo = 0U;
  c8_info[71].mFileTimeHi = 0U;
  c8_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c8_info[72].name = "eml_scalar_round";
  c8_info[72].dominantType = "single";
  c8_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c8_info[72].fileTimeLo = 1307651238U;
  c8_info[72].fileTimeHi = 0U;
  c8_info[72].mFileTimeLo = 0U;
  c8_info[72].mFileTimeHi = 0U;
  c8_info[73].context = "";
  c8_info[73].name = "round";
  c8_info[73].dominantType = "int32";
  c8_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c8_info[73].fileTimeLo = 1343830384U;
  c8_info[73].fileTimeHi = 0U;
  c8_info[73].mFileTimeLo = 0U;
  c8_info[73].mFileTimeHi = 0U;
  c8_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c8_info[74].name = "eml_scalar_round";
  c8_info[74].dominantType = "int32";
  c8_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c8_info[74].fileTimeLo = 1307651238U;
  c8_info[74].fileTimeHi = 0U;
  c8_info[74].mFileTimeLo = 0U;
  c8_info[74].mFileTimeHi = 0U;
  c8_info[75].context = "";
  c8_info[75].name = "sum";
  c8_info[75].dominantType = "int32";
  c8_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[75].fileTimeLo = 1314736612U;
  c8_info[75].fileTimeHi = 0U;
  c8_info[75].mFileTimeLo = 0U;
  c8_info[75].mFileTimeHi = 0U;
  c8_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[76].name = "isequal";
  c8_info[76].dominantType = "int32";
  c8_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[76].fileTimeLo = 1286818758U;
  c8_info[76].fileTimeHi = 0U;
  c8_info[76].mFileTimeLo = 0U;
  c8_info[76].mFileTimeHi = 0U;
  c8_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[77].name = "eml_isequal_core";
  c8_info[77].dominantType = "int32";
  c8_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[77].fileTimeLo = 1286818786U;
  c8_info[77].fileTimeHi = 0U;
  c8_info[77].mFileTimeLo = 0U;
  c8_info[77].mFileTimeHi = 0U;
  c8_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[78].name = "eml_const_nonsingleton_dim";
  c8_info[78].dominantType = "int32";
  c8_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c8_info[78].fileTimeLo = 1286818696U;
  c8_info[78].fileTimeHi = 0U;
  c8_info[78].mFileTimeLo = 0U;
  c8_info[78].mFileTimeHi = 0U;
  c8_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[79].name = "eml_scalar_eg";
  c8_info[79].dominantType = "double";
  c8_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[79].fileTimeLo = 1286818796U;
  c8_info[79].fileTimeHi = 0U;
  c8_info[79].mFileTimeLo = 0U;
  c8_info[79].mFileTimeHi = 0U;
  c8_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[80].name = "eml_index_class";
  c8_info[80].dominantType = "";
  c8_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[80].fileTimeLo = 1323170578U;
  c8_info[80].fileTimeHi = 0U;
  c8_info[80].mFileTimeLo = 0U;
  c8_info[80].mFileTimeHi = 0U;
  c8_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c8_info[81].name = "eml_int_forloop_overflow_check";
  c8_info[81].dominantType = "";
  c8_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[81].fileTimeLo = 1346510340U;
  c8_info[81].fileTimeHi = 0U;
  c8_info[81].mFileTimeLo = 0U;
  c8_info[81].mFileTimeHi = 0U;
  c8_info[82].context = "";
  c8_info[82].name = "mtimes";
  c8_info[82].dominantType = "double";
  c8_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[82].fileTimeLo = 1289519692U;
  c8_info[82].fileTimeHi = 0U;
  c8_info[82].mFileTimeLo = 0U;
  c8_info[82].mFileTimeHi = 0U;
}

static void c8_check_forloop_overflow_error(SFc8_blokowyInstanceStruct
  *chartInstance, boolean_T c8_overflow)
{
  int32_T c8_i3;
  static char_T c8_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c8_u[34];
  const mxArray *c8_y = NULL;
  static char_T c8_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c8_b_u[5];
  const mxArray *c8_b_y = NULL;
  if (c8_overflow) {
    for (c8_i3 = 0; c8_i3 < 34; c8_i3++) {
      c8_u[c8_i3] = c8_cv0[c8_i3];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c8_i3 = 0; c8_i3 < 5; c8_i3++) {
      c8_b_u[c8_i3] = c8_cv1[c8_i3];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call("error", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c8_y, 14,
      c8_b_y));
  }
}

static void c8_inv(SFc8_blokowyInstanceStruct *chartInstance, real32_T c8_x[9],
                   real32_T c8_y[9])
{
  int32_T c8_p1;
  real32_T c8_b_x[9];
  int32_T c8_p2;
  int32_T c8_p3;
  real32_T c8_absx11;
  real32_T c8_absx21;
  real32_T c8_absx31;
  int32_T c8_itmp;
  static char_T c8_cv2[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c8_u[8];
  const mxArray *c8_b_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real32_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  char_T c8_str[14];
  for (c8_p1 = 0; c8_p1 < 9; c8_p1++) {
    c8_b_x[c8_p1] = c8_x[c8_p1];
  }

  c8_p1 = 0;
  c8_p2 = 3;
  c8_p3 = 6;
  c8_absx11 = muSingleScalarAbs(c8_x[0]);
  c8_absx21 = muSingleScalarAbs(c8_x[1]);
  c8_absx31 = muSingleScalarAbs(c8_x[2]);
  if ((c8_absx21 > c8_absx11) && (c8_absx21 > c8_absx31)) {
    c8_p1 = 3;
    c8_p2 = 0;
    c8_b_x[0] = c8_x[1];
    c8_b_x[1] = c8_x[0];
    c8_b_x[3] = c8_x[4];
    c8_b_x[4] = c8_x[3];
    c8_b_x[6] = c8_x[7];
    c8_b_x[7] = c8_x[6];
  } else {
    if (c8_absx31 > c8_absx11) {
      c8_p1 = 6;
      c8_p3 = 0;
      c8_b_x[0] = c8_x[2];
      c8_b_x[2] = c8_x[0];
      c8_b_x[3] = c8_x[5];
      c8_b_x[5] = c8_x[3];
      c8_b_x[6] = c8_x[8];
      c8_b_x[8] = c8_x[6];
    }
  }

  c8_absx11 = c8_b_x[1] / c8_b_x[0];
  c8_b_x[1] /= c8_b_x[0];
  c8_absx21 = c8_b_x[2] / c8_b_x[0];
  c8_b_x[2] /= c8_b_x[0];
  c8_b_x[4] -= c8_absx11 * c8_b_x[3];
  c8_b_x[5] -= c8_absx21 * c8_b_x[3];
  c8_b_x[7] -= c8_absx11 * c8_b_x[6];
  c8_b_x[8] -= c8_absx21 * c8_b_x[6];
  if (muSingleScalarAbs(c8_b_x[5]) > muSingleScalarAbs(c8_b_x[4])) {
    c8_itmp = c8_p2;
    c8_p2 = c8_p3;
    c8_p3 = c8_itmp;
    c8_b_x[1] = c8_absx21;
    c8_b_x[2] = c8_absx11;
    c8_absx11 = c8_b_x[4];
    c8_b_x[4] = c8_b_x[5];
    c8_b_x[5] = c8_absx11;
    c8_absx11 = c8_b_x[7];
    c8_b_x[7] = c8_b_x[8];
    c8_b_x[8] = c8_absx11;
  }

  c8_absx11 = c8_b_x[5] / c8_b_x[4];
  c8_b_x[5] /= c8_b_x[4];
  c8_b_x[8] -= c8_absx11 * c8_b_x[7];
  c8_absx11 = (c8_b_x[5] * c8_b_x[1] - c8_b_x[2]) / c8_b_x[8];
  c8_absx21 = -(c8_b_x[1] + c8_b_x[7] * c8_absx11) / c8_b_x[4];
  c8_y[c8_p1] = ((1.0F - c8_b_x[3] * c8_absx21) - c8_b_x[6] * c8_absx11) /
    c8_b_x[0];
  c8_y[c8_p1 + 1] = c8_absx21;
  c8_y[c8_p1 + 2] = c8_absx11;
  c8_absx11 = -c8_b_x[5] / c8_b_x[8];
  c8_absx21 = (1.0F - c8_b_x[7] * c8_absx11) / c8_b_x[4];
  c8_y[c8_p2] = -(c8_b_x[3] * c8_absx21 + c8_b_x[6] * c8_absx11) / c8_b_x[0];
  c8_y[c8_p2 + 1] = c8_absx21;
  c8_y[c8_p2 + 2] = c8_absx11;
  c8_absx11 = 1.0F / c8_b_x[8];
  c8_absx21 = -c8_b_x[7] * c8_absx11 / c8_b_x[4];
  c8_y[c8_p3] = -(c8_b_x[3] * c8_absx21 + c8_b_x[6] * c8_absx11) / c8_b_x[0];
  c8_y[c8_p3 + 1] = c8_absx21;
  c8_y[c8_p3 + 2] = c8_absx11;
  c8_absx11 = c8_norm(chartInstance, c8_x);
  c8_absx21 = c8_norm(chartInstance, c8_y);
  c8_absx31 = 1.0F / (c8_absx11 * c8_absx21);
  if ((c8_absx11 == 0.0F) || (c8_absx21 == 0.0F) || (c8_absx31 == 0.0F)) {
    c8_eml_warning(chartInstance);
  } else {
    if (muSingleScalarIsNaN(c8_absx31) || (c8_absx31 < 1.1920929E-7F)) {
      for (c8_p1 = 0; c8_p1 < 8; c8_p1++) {
        c8_u[c8_p1] = c8_cv2[c8_p1];
      }

      c8_b_y = NULL;
      sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c8_b_u = 14.0;
      c8_c_y = NULL;
      sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c8_c_u = 6.0;
      c8_d_y = NULL;
      sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c8_d_u = c8_absx31;
      c8_e_y = NULL;
      sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 1, 0U, 0U, 0U, 0),
                    FALSE);
      c8_emlrt_marshallIn(chartInstance, sf_mex_call("sprintf", 1U, 2U, 14,
        sf_mex_call("sprintf", 1U, 3U, 14, c8_b_y, 14, c8_c_y, 14, c8_d_y), 14,
        c8_e_y), "sprintf", c8_str);
      c8_b_eml_warning(chartInstance, c8_str);
    }
  }
}

static real32_T c8_norm(SFc8_blokowyInstanceStruct *chartInstance, real32_T
  c8_x[9])
{
  real32_T c8_y;
  int32_T c8_j;
  boolean_T c8_exitg1;
  real32_T c8_s;
  int32_T c8_i;
  c8_y = 0.0F;
  c8_j = 0;
  c8_exitg1 = FALSE;
  while ((c8_exitg1 == FALSE) && (c8_j < 3)) {
    c8_s = 0.0F;
    for (c8_i = 0; c8_i < 3; c8_i++) {
      c8_s += muSingleScalarAbs(c8_x[c8_i + 3 * c8_j]);
    }

    if (muSingleScalarIsNaN(c8_s)) {
      c8_y = ((real32_T)rtNaN);
      c8_exitg1 = TRUE;
    } else {
      if (c8_s > c8_y) {
        c8_y = c8_s;
      }

      c8_j++;
    }
  }

  return c8_y;
}

static void c8_eml_warning(SFc8_blokowyInstanceStruct *chartInstance)
{
  int32_T c8_i4;
  static char_T c8_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c8_u[27];
  const mxArray *c8_y = NULL;
  for (c8_i4 = 0; c8_i4 < 27; c8_i4++) {
    c8_u[c8_i4] = c8_varargin_1[c8_i4];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call("warning", 0U, 1U, 14, sf_mex_call("message", 1U, 1U, 14, c8_y));
}

static void c8_b_eml_warning(SFc8_blokowyInstanceStruct *chartInstance, char_T
  c8_varargin_2[14])
{
  int32_T c8_i5;
  static char_T c8_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c8_u[33];
  const mxArray *c8_y = NULL;
  char_T c8_b_u[14];
  const mxArray *c8_b_y = NULL;
  for (c8_i5 = 0; c8_i5 < 33; c8_i5++) {
    c8_u[c8_i5] = c8_varargin_1[c8_i5];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c8_i5 = 0; c8_i5 < 14; c8_i5++) {
    c8_b_u[c8_i5] = c8_varargin_2[c8_i5];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call("warning", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c8_y, 14,
    c8_b_y));
}

static void c8_RecognizeHalfCode(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_codebook[1120], int32_T c8_barBin[1472], int32_T c8_firstBin,
  int32_T c8_numBinInSym, boolean_T c8_isReverse, int32_T c8_code[6], int32_T
  c8_conf[6])
{
  int32_T c8_iSym;
  int32_T c8_step;
  int32_T c8_startBin;
  int32_T c8_idx;
  int32_T c8_bestCode;
  int32_T c8_bestSum;
  int32_T c8_iCode;
  int32_T c8_b_sum;
  boolean_T c8_b0;
  int32_T c8_jdx;
  int32_T c8_qY;
  int32_T c8_q1;
  for (c8_iSym = 0; c8_iSym < 6; c8_iSym++) {
    c8_code[c8_iSym] = 0;
    c8_conf[c8_iSym] = 0;
  }

  c8_iSym = 1;
  c8_step = 1;
  if (c8_isReverse) {
    c8_iSym = 6;
    c8_step = -1;
  }

  c8_startBin = c8_firstBin;
  for (c8_idx = 0; c8_idx < 6; c8_idx++) {
    c8_bestCode = -1;
    c8_bestSum = c8_mul_s32_s32_s32_sat(chartInstance, -2, c8_numBinInSym);
    for (c8_iCode = 0; c8_iCode < 10; c8_iCode++) {
      c8_b_sum = 0;
      if (1 > c8_numBinInSym) {
        c8_b0 = FALSE;
      } else {
        c8_b0 = (c8_numBinInSym > 2147483646);
      }

      if (c8_b0) {
        c8_check_forloop_overflow_error(chartInstance, TRUE);
      }

      c8_jdx = 1;
      while (c8_jdx <= c8_numBinInSym) {
        c8_qY = c8_startBin + c8_jdx;
        if ((c8_startBin < 0) && ((c8_jdx < 0) && (c8_qY >= 0))) {
          c8_qY = MIN_int32_T;
        } else {
          if ((c8_startBin > 0) && ((c8_jdx > 0) && (c8_qY <= 0))) {
            c8_qY = MAX_int32_T;
          }
        }

        sf_mex_lw_bounds_check(c8_qY - 1, 1, 1472);
        sf_mex_lw_bounds_check(c8_jdx, 1, 112);
        c8_qY = c8_startBin + c8_jdx;
        if ((c8_startBin < 0) && ((c8_jdx < 0) && (c8_qY >= 0))) {
          c8_qY = MIN_int32_T;
        } else {
          if ((c8_startBin > 0) && ((c8_jdx > 0) && (c8_qY <= 0))) {
            c8_qY = MAX_int32_T;
          }
        }

        c8_q1 = c8_mul_s32_s32_s32_sat(chartInstance, c8_barBin[c8_qY - 2],
          c8_codebook[c8_iCode + 10 * (c8_jdx - 1)]);
        c8_qY = c8_b_sum + c8_q1;
        if ((c8_b_sum < 0) && ((c8_q1 < 0) && (c8_qY >= 0))) {
          c8_qY = MIN_int32_T;
        } else {
          if ((c8_b_sum > 0) && ((c8_q1 > 0) && (c8_qY <= 0))) {
            c8_qY = MAX_int32_T;
          }
        }

        c8_b_sum = c8_qY;
        c8_jdx++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      if (c8_bestSum < c8_b_sum) {
        c8_bestSum = c8_b_sum;
        c8_bestCode = c8_iCode;
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c8_code[sf_mex_lw_bounds_check(c8_iSym, 1, 6) - 1] = c8_bestCode;
    c8_conf[c8_iSym - 1] = c8_bestSum;
    c8_iSym += c8_step;
    c8_qY = c8_startBin + c8_numBinInSym;
    if ((c8_startBin < 0) && ((c8_numBinInSym < 0) && (c8_qY >= 0))) {
      c8_qY = MIN_int32_T;
    } else {
      if ((c8_startBin > 0) && ((c8_numBinInSym > 0) && (c8_qY <= 0))) {
        c8_qY = MAX_int32_T;
      }
    }

    c8_startBin = c8_qY;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }
}

static real_T c8_sum(SFc8_blokowyInstanceStruct *chartInstance, int32_T c8_x[6])
{
  real_T c8_y;
  int32_T c8_k;
  c8_y = (real_T)c8_x[0];
  for (c8_k = 0; c8_k < 5; c8_k++) {
    c8_y += (real_T)c8_x[c8_k + 1];
  }

  return c8_y;
}

static void c8_RecognizeFirstHalfCode(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_LGCode[60], int32_T c8_lcode[6], int32_T c8_lconf[6], int32_T
  c8_gcode[6], int32_T c8_gconf[6], int32_T c8_code[7], int32_T c8_conf[7])
{
  int32_T c8_i6;
  int32_T c8_confComb[12];
  int32_T c8_bestCode;
  int32_T c8_k;
  real_T c8_bestSum;
  int32_T c8_idx;
  real_T c8_curSum;
  int32_T c8_b_lcode[12];
  for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
    c8_confComb[c8_i6] = c8_lconf[c8_i6];
    c8_confComb[c8_i6 + 6] = c8_gconf[c8_i6];
  }

  for (c8_i6 = 0; c8_i6 < 7; c8_i6++) {
    c8_code[c8_i6] = 0;
    c8_conf[c8_i6] = 0;
  }

  c8_bestCode = 0;
  c8_i6 = 0;
  for (c8_k = 0; c8_k < 6; c8_k++) {
    sf_mex_lw_bounds_check(c8_LGCode[c8_i6], 1, 12);
    c8_i6 += 10;
  }

  c8_bestSum = (real_T)c8_confComb[c8_LGCode[0] - 1];
  for (c8_k = 0; c8_k < 5; c8_k++) {
    c8_bestSum += (real_T)c8_confComb[c8_LGCode[10 * (c8_k + 1)] - 1];
  }

  for (c8_idx = 0; c8_idx < 9; c8_idx++) {
    for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
      sf_mex_lw_bounds_check(c8_LGCode[(c8_idx + 10 * c8_i6) + 1], 1, 12);
    }

    c8_curSum = (real_T)c8_confComb[c8_LGCode[c8_idx + 1] - 1];
    for (c8_k = 0; c8_k < 5; c8_k++) {
      c8_curSum += (real_T)c8_confComb[c8_LGCode[(c8_idx + 10 * (c8_k + 1)) + 1]
        - 1];
    }

    if (c8_bestSum < c8_curSum) {
      c8_bestCode = 1 + c8_idx;
      c8_bestSum = c8_curSum;
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c8_code[0] = c8_bestCode;
  c8_bestSum = muDoubleScalarRound(c8_bestSum);
  if (c8_bestSum < 2.147483648E+9) {
    if (c8_bestSum >= -2.147483648E+9) {
      c8_i6 = (int32_T)c8_bestSum;
    } else {
      c8_i6 = MIN_int32_T;
    }
  } else {
    c8_i6 = MAX_int32_T;
  }

  c8_conf[0] = c8_i6;
  for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
    c8_b_lcode[c8_i6] = c8_lcode[c8_i6];
    c8_b_lcode[c8_i6 + 6] = c8_gcode[c8_i6];
  }

  for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
    c8_code[1 + c8_i6] = c8_b_lcode[sf_mex_lw_bounds_check(c8_LGCode[c8_bestCode
      + 10 * c8_i6], 1, 12) - 1];
  }

  for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
    c8_conf[1 + c8_i6] = c8_confComb[sf_mex_lw_bounds_check
      (c8_LGCode[c8_bestCode + 10 * c8_i6], 1, 12) - 1];
  }
}

static void c8_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance, const
  mxArray *c8_sprintf, const char_T *c8_identifier, char_T c8_y[14])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_sprintf), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_sprintf);
}

static void c8_b_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, char_T c8_y[14])
{
  char_T c8_cv3[14];
  int32_T c8_i7;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c8_i7 = 0; c8_i7 < 14; c8_i7++) {
    c8_y[c8_i7] = c8_cv3[c8_i7];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_Code, const char_T *c8_identifier, int32_T c8_y[13])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Code), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_Code);
}

static void c8_d_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, int32_T c8_y[13])
{
  int32_T c8_iv0[13];
  int32_T c8_i8;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_iv0, 1, 6, 0U, 1, 0U, 1, 13);
  for (c8_i8 = 0; c8_i8 < 13; c8_i8++) {
    c8_y[c8_i8] = c8_iv0[c8_i8];
  }

  sf_mex_destroy(&c8_u);
}

static real32_T c8_e_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_Conf, const char_T *c8_identifier)
{
  real32_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Conf), &c8_thisId);
  sf_mex_destroy(&c8_Conf);
  return c8_y;
}

static real32_T c8_f_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real32_T c8_y;
  real32_T c8_f1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_f1, 1, 1, 0U, 0, 0U, 0);
  c8_y = c8_f1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_blokowy, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_blokowy), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_blokowy);
  return c8_y;
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_blokowyInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u1, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_mul_wide_s32(SFc8_blokowyInstanceStruct *chartInstance, int32_T
  c8_in0, int32_T c8_in1, uint32_T *c8_ptrOutBitsHi, uint32_T *c8_ptrOutBitsLo)
{
  uint32_T c8_absIn0;
  uint32_T c8_absIn1;
  int32_T c8_negativeProduct;
  int32_T c8_in0Hi;
  int32_T c8_in0Lo;
  int32_T c8_in1Hi;
  int32_T c8_in1Lo;
  uint32_T c8_productLoHi;
  uint32_T c8_productLoLo;
  uint32_T c8_outBitsLo;
  if (c8_in0 < 0) {
    c8_absIn0 = (uint32_T)-c8_in0;
  } else {
    c8_absIn0 = (uint32_T)c8_in0;
  }

  if (c8_in1 < 0) {
    c8_absIn1 = (uint32_T)-c8_in1;
  } else {
    c8_absIn1 = (uint32_T)c8_in1;
  }

  c8_negativeProduct = !((c8_in0 == 0) || ((c8_in1 == 0) || (c8_in0 > 0 ==
    c8_in1 > 0)));
  c8_in0Hi = (int32_T)(c8_absIn0 >> 16U);
  c8_in0Lo = (int32_T)(c8_absIn0 & 65535U);
  c8_in1Hi = (int32_T)(c8_absIn1 >> 16U);
  c8_in1Lo = (int32_T)(c8_absIn1 & 65535U);
  c8_absIn0 = (uint32_T)c8_in0Hi * (uint32_T)c8_in1Hi;
  c8_absIn1 = (uint32_T)c8_in0Hi * (uint32_T)c8_in1Lo;
  c8_productLoHi = (uint32_T)c8_in0Lo * (uint32_T)c8_in1Hi;
  c8_productLoLo = (uint32_T)c8_in0Lo * (uint32_T)c8_in1Lo;
  c8_in0Hi = 0;
  c8_outBitsLo = c8_productLoLo + (c8_productLoHi << 16U);
  if (c8_outBitsLo < c8_productLoLo) {
    c8_in0Hi = 1;
  }

  c8_productLoLo = c8_outBitsLo;
  c8_outBitsLo += c8_absIn1 << 16U;
  if (c8_outBitsLo < c8_productLoLo) {
    c8_in0Hi = (int32_T)((uint32_T)c8_in0Hi + 1U);
  }

  c8_absIn0 = (((uint32_T)c8_in0Hi + c8_absIn0) + (c8_productLoHi >> 16U)) +
    (c8_absIn1 >> 16U);
  if (c8_negativeProduct) {
    c8_absIn0 = ~c8_absIn0;
    c8_outBitsLo = ~c8_outBitsLo;
    c8_outBitsLo++;
    if (c8_outBitsLo == 0U) {
      c8_absIn0++;
    }
  }

  *c8_ptrOutBitsHi = c8_absIn0;
  *c8_ptrOutBitsLo = c8_outBitsLo;
}

static int32_T c8_mul_s32_s32_s32_sat(SFc8_blokowyInstanceStruct *chartInstance,
  int32_T c8_a, int32_T c8_b)
{
  int32_T c8_result;
  uint32_T c8_u32_clo;
  uint32_T c8_u32_chi;
  c8_mul_wide_s32(chartInstance, c8_a, c8_b, &c8_u32_chi, &c8_u32_clo);
  if (((int32_T)c8_u32_chi > 0) || ((c8_u32_chi == 0U) && (c8_u32_clo >=
        2147483648U))) {
    c8_result = MAX_int32_T;
  } else if (((int32_T)c8_u32_chi < -1) || (((int32_T)c8_u32_chi == -1) &&
              (c8_u32_clo < 2147483648U))) {
    c8_result = MIN_int32_T;
  } else {
    c8_result = (int32_T)c8_u32_clo;
  }

  return c8_result;
}

static void init_dsm_address_info(SFc8_blokowyInstanceStruct *chartInstance)
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

void sf_c8_blokowy_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1311108307U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2560474265U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1206716400U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2939997389U);
}

mxArray *sf_c8_blokowy_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Vi3xD7xCRAiRzTI5nsbBcB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(200);
      pr[1] = (double)(3);
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
      pr[0] = (double)(200);
      pr[1] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(90);
      pr[1] = (double)(3);
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
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
      pr[1] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(112);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(13);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

mxArray *sf_c8_blokowy_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c8_blokowy(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[13],T\"Code\",},{M[1],M[14],T\"Conf\",},{M[8],M[0],T\"is_active_c8_blokowy\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_blokowy_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "JvNanUkosqMbWN809moo3C";
}

static void sf_opaque_initialize_c8_blokowy(void *chartInstanceVar)
{
  initialize_params_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
  initialize_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_blokowy(void *chartInstanceVar)
{
  enable_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_blokowy(void *chartInstanceVar)
{
  disable_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_blokowy(void *chartInstanceVar)
{
  sf_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_blokowy(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_blokowy((SFc8_blokowyInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_blokowy();/* state var info */
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

extern void sf_internal_set_sim_state_c8_blokowy(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_blokowy();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_blokowy((SFc8_blokowyInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_blokowy(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_blokowy(S);
}

static void sf_opaque_set_sim_state_c8_blokowy(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_blokowy(S, st);
}

static void sf_opaque_terminate_c8_blokowy(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_blokowyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_blokowy_optimization_info();
    }

    finalize_c8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_blokowy((SFc8_blokowyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_blokowy(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_blokowy((SFc8_blokowyInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_blokowy_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,11);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 11; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3669562140U));
  ssSetChecksum1(S,(940839874U));
  ssSetChecksum2(S,(3146567665U));
  ssSetChecksum3(S,(3507336655U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_blokowy(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_blokowy(SimStruct *S)
{
  SFc8_blokowyInstanceStruct *chartInstance;
  chartInstance = (SFc8_blokowyInstanceStruct *)utMalloc(sizeof
    (SFc8_blokowyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_blokowyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_blokowy;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_blokowy;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_blokowy;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_blokowy;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_blokowy;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_blokowy;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_blokowy;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_blokowy;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_blokowy;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_blokowy;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_blokowy;
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

void c8_blokowy_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_blokowy(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_blokowy(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_blokowy(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_blokowy_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
