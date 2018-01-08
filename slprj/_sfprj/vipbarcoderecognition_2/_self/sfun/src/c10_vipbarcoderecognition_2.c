/* Include files */

#include <stddef.h>
#include "blas.h"
#include "vipbarcoderecognition_2_sfun.h"
#include "c10_vipbarcoderecognition_2.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void initialize_params_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void enable_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void disable_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void set_sim_state_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_st);
static void finalize_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void sf_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void c10_chartstep_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void initSimStructsc10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void registerMessagesc10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static void c10_check_forloop_overflow_error
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, boolean_T
   c10_overflow);
static void c10_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_Num, const char_T *c10_identifier, int32_T
  c10_y[3]);
static void c10_b_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  int32_T c10_y[3]);
static void c10_c_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_Sequence, const char_T *c10_identifier,
  int32_T c10_y[270]);
static void c10_d_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  int32_T c10_y[270]);
static uint8_T c10_e_emlrt_marshallIn
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_vipbarcoderecognition_2, const char_T *c10_identifier);
static uint8_T c10_f_emlrt_marshallIn
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_vipbarcoderecognition_2 = 0U;
}

static void initialize_params_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void enable_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  int32_T c10_u[3];
  const mxArray *c10_b_y = NULL;
  int32_T c10_b_u[270];
  const mxArray *c10_c_y = NULL;
  uint8_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  int32_T (*c10_Sequence)[270];
  int32_T (*c10_Num)[3];
  c10_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_Sequence = (int32_T (*)[270])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(3), FALSE);
  for (c10_i0 = 0; c10_i0 < 3; c10_i0++) {
    c10_u[c10_i0] = (*c10_Num)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 6, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  for (c10_i0 = 0; c10_i0 < 270; c10_i0++) {
    c10_b_u[c10_i0] = (*c10_Sequence)[c10_i0];
  }

  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_b_u, 6, 0U, 1U, 0U, 2, 90, 3),
                FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_u = chartInstance->c10_is_active_c10_vipbarcoderecognition_2;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  int32_T (*c10_Num)[3];
  int32_T (*c10_Sequence)[270];
  c10_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_Sequence = (int32_T (*)[270])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "Num", *c10_Num);
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "Sequence", *c10_Sequence);
  chartInstance->c10_is_active_c10_vipbarcoderecognition_2 =
    c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
    "is_active_c10_vipbarcoderecognition_2");
  sf_mex_destroy(&c10_u);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void sf_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c10_chartstep_c10_vipbarcoderecognition_2(chartInstance);
}

static void c10_chartstep_c10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  int32_T c10_q0;
  real32_T c10_Width[600];
  int32_T c10_NumBar[3];
  real32_T c10_WidthVar;
  int32_T c10_separator[50];
  int32_T c10_Sequence[270];
  int8_T c10_Num[3];
  int32_T c10_iScanline;
  int32_T c10_firstBar;
  int32_T c10_numSep;
  int32_T c10_exitg4;
  int32_T c10_qY;
  real32_T c10_avgWidth;
  real32_T c10_devWidth;
  real32_T c10_difWidth;
  int32_T c10_iSequence;
  int32_T c10_iStart;
  boolean_T c10_exitg1;
  int32_T c10_firstMidSep;
  int32_T c10_firstEndSep;
  int32_T c10_iMid;
  boolean_T c10_exitg2;
  int32_T c10_iEnd;
  boolean_T c10_exitg3;
  boolean_T c10_b_separator;
  boolean_T c10_c_separator;
  boolean_T c10_b_firstBar;
  int32_T (*c10_b_Num)[3];
  int32_T (*c10_b_Sequence)[270];
  real32_T *c10_b_WidthVar;
  int32_T (*c10_b_NumBar)[3];
  real32_T (*c10_b_Width)[600];
  c10_b_WidthVar = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_Sequence = (int32_T (*)[270])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_NumBar = (int32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_Width = (real32_T (*)[600])ssGetInputPortSignal(chartInstance->S, 0);
  for (c10_q0 = 0; c10_q0 < 600; c10_q0++) {
    c10_Width[c10_q0] = (*c10_b_Width)[c10_q0];
  }

  for (c10_q0 = 0; c10_q0 < 3; c10_q0++) {
    c10_NumBar[c10_q0] = (*c10_b_NumBar)[c10_q0];
  }

  c10_WidthVar = *c10_b_WidthVar;
  for (c10_q0 = 0; c10_q0 < 50; c10_q0++) {
    c10_separator[c10_q0] = 0;
  }

  for (c10_q0 = 0; c10_q0 < 270; c10_q0++) {
    c10_Sequence[c10_q0] = 0;
  }

  for (c10_q0 = 0; c10_q0 < 3; c10_q0++) {
    c10_Num[c10_q0] = 0;
  }

  for (c10_iScanline = 0; c10_iScanline < 3; c10_iScanline++) {
    c10_firstBar = 1;
    if (c10_Width[0] == 0.0F) {
      c10_firstBar = 3;
    }

    c10_numSep = 0;
    do {
      c10_exitg4 = 0;
      c10_q0 = c10_NumBar[c10_iScanline];
      c10_qY = c10_q0 - 2;
      if ((c10_q0 < 0) && (c10_qY >= 0)) {
        c10_qY = MIN_int32_T;
      }

      if (c10_firstBar <= c10_qY) {
        c10_avgWidth = 0.0F;
        c10_q0 = ((int32_T)(uint32_T)c10_firstBar - c10_firstBar) + 2;
        c10_qY = 0;
        while (c10_qY <= c10_q0) {
          c10_avgWidth += c10_Width[(sf_mex_lw_bounds_check((int32_T)((uint32_T)
            c10_firstBar + (uint32_T)c10_qY), 1, 200) + 200 * c10_iScanline) - 1];
          c10_qY++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        c10_avgWidth /= 3.0F;
        c10_devWidth = 0.0F;
        c10_q0 = ((int32_T)(uint32_T)c10_firstBar - c10_firstBar) + 2;
        c10_qY = 0;
        while (c10_qY <= c10_q0) {
          c10_difWidth = c10_Width[(sf_mex_lw_bounds_check((int32_T)((uint32_T)
            c10_firstBar + (uint32_T)c10_qY), 1, 200) + 200 * c10_iScanline) - 1]
            - c10_avgWidth;
          c10_difWidth = muSingleScalarAbs(c10_difWidth);
          if (c10_devWidth < c10_difWidth) {
            c10_devWidth = c10_difWidth;
          }

          c10_qY++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        if ((c10_numSep < 50) && (c10_devWidth < c10_WidthVar)) {
          c10_numSep++;
          c10_separator[c10_numSep - 1] = c10_firstBar;
        }

        c10_firstBar += 2;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        c10_exitg4 = 1;
      }
    } while (c10_exitg4 == 0);

    c10_iSequence = 0;
    c10_iStart = 0;
    c10_exitg1 = FALSE;
    while ((c10_exitg1 == FALSE) && ((c10_iSequence < 30) && (c10_iStart + 1 <=
             c10_numSep - 2))) {
      c10_q0 = c10_NumBar[c10_iScanline];
      c10_qY = c10_q0 - 56;
      if ((c10_q0 < 0) && (c10_qY >= 0)) {
        c10_qY = MIN_int32_T;
      }

      if (c10_separator[c10_iStart] <= c10_qY + 2) {
        c10_q0 = c10_separator[c10_iStart];
        c10_qY = c10_q0 + 28;
        if ((c10_q0 > 0) && (c10_qY <= 0)) {
          c10_qY = MAX_int32_T;
        }

        c10_firstMidSep = c10_qY - 2;
        c10_q0 = c10_separator[c10_iStart];
        c10_qY = c10_q0 + 56;
        if ((c10_q0 > 0) && (c10_qY <= 0)) {
          c10_qY = MAX_int32_T;
        }

        c10_firstEndSep = c10_qY - 2;
        c10_iMid = c10_iStart + 1;
        while ((c10_iMid + 1 <= c10_numSep - 1) && (c10_separator[c10_iMid] <
                c10_firstMidSep)) {
          c10_iMid++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        c10_exitg2 = FALSE;
        while ((c10_exitg2 == FALSE) && ((c10_iSequence < 30) && (c10_iMid + 1 <=
                 c10_numSep - 1))) {
          c10_qY = c10_firstMidSep + 4;
          if ((c10_firstMidSep > 0) && (c10_qY <= 0)) {
            c10_qY = MAX_int32_T;
          }

          if (c10_separator[c10_iMid] <= c10_qY) {
            c10_iEnd = c10_iMid + 1;
            while ((c10_iEnd + 1 <= c10_numSep) && (c10_separator[c10_iEnd] <
                    c10_firstEndSep)) {
              c10_iEnd++;
              _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
            }

            c10_exitg3 = FALSE;
            while ((c10_exitg3 == FALSE) && ((c10_iSequence < 30) && (c10_iEnd +
                     1 <= c10_numSep))) {
              c10_qY = c10_firstEndSep + 4;
              if ((c10_firstEndSep > 0) && (c10_qY <= 0)) {
                c10_qY = MAX_int32_T;
              }

              if (c10_separator[c10_iEnd] <= c10_qY) {
                c10_avgWidth = 0.0F;
                c10_q0 = c10_separator[c10_iStart] + 2;
                if (c10_separator[c10_iStart] > c10_q0) {
                  c10_b_separator = FALSE;
                } else {
                  c10_b_separator = (c10_q0 > 2147483646);
                }

                if (c10_b_separator) {
                  c10_check_forloop_overflow_error(chartInstance, TRUE);
                }

                c10_qY = c10_separator[c10_iStart];
                while (c10_qY <= c10_q0) {
                  c10_avgWidth += c10_Width[(sf_mex_lw_bounds_check(c10_qY, 1,
                    200) + 200 * c10_iScanline) - 1];
                  c10_qY++;
                  _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
                }

                c10_q0 = c10_separator[c10_iEnd] + 2;
                if (c10_separator[c10_iEnd] > c10_q0) {
                  c10_c_separator = FALSE;
                } else {
                  c10_c_separator = (c10_q0 > 2147483646);
                }

                if (c10_c_separator) {
                  c10_check_forloop_overflow_error(chartInstance, TRUE);
                }

                c10_qY = c10_separator[c10_iEnd];
                while (c10_qY <= c10_q0) {
                  c10_avgWidth += c10_Width[(sf_mex_lw_bounds_check(c10_qY, 1,
                    200) + 200 * c10_iScanline) - 1];
                  c10_qY++;
                  _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
                }

                c10_avgWidth /= 6.0F;
                c10_devWidth = 0.0F;
                c10_firstBar = c10_separator[c10_iMid] - 1;
                c10_q0 = c10_separator[c10_iMid];
                c10_qY = c10_q0 + 3;
                if ((c10_q0 > 0) && (c10_qY <= 0)) {
                  c10_qY = MAX_int32_T;
                }

                if (c10_firstBar > c10_qY) {
                  c10_b_firstBar = FALSE;
                } else {
                  c10_b_firstBar = (c10_qY > 2147483646);
                }

                if (c10_b_firstBar) {
                  c10_check_forloop_overflow_error(chartInstance, TRUE);
                }

                while (c10_firstBar <= c10_qY) {
                  c10_difWidth = c10_Width[(sf_mex_lw_bounds_check(c10_firstBar,
                    1, 200) + 200 * c10_iScanline) - 1] - c10_avgWidth;
                  c10_difWidth = muSingleScalarAbs(c10_difWidth);
                  if (c10_devWidth < c10_difWidth) {
                    c10_devWidth = c10_difWidth;
                  }

                  c10_firstBar++;
                  _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
                }

                if (c10_devWidth < c10_WidthVar) {
                  c10_Sequence[3 * c10_iSequence + 90 * c10_iScanline] =
                    c10_separator[c10_iStart];
                  c10_Sequence[(3 * c10_iSequence + 90 * c10_iScanline) + 1] =
                    c10_separator[c10_iMid];
                  c10_Sequence[(3 * c10_iSequence + 90 * c10_iScanline) + 2] =
                    c10_separator[c10_iEnd];
                  c10_iSequence++;
                }

                c10_iEnd++;
                _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
              } else {
                c10_exitg3 = TRUE;
              }
            }

            c10_iMid++;
            _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
          } else {
            c10_exitg2 = TRUE;
          }
        }

        c10_iStart++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        c10_exitg1 = TRUE;
      }
    }

    c10_Num[c10_iScanline] = (int8_T)c10_iSequence;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c10_q0 = 0; c10_q0 < 270; c10_q0++) {
    (*c10_b_Sequence)[c10_q0] = c10_Sequence[c10_q0];
  }

  for (c10_q0 = 0; c10_q0 < 3; c10_q0++) {
    (*c10_b_Num)[c10_q0] = c10_Num[c10_q0];
  }
}

static void initSimStructsc10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void registerMessagesc10_vipbarcoderecognition_2
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

const mxArray *sf_c10_vipbarcoderecognition_2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[9];
  c10_ResolvedFunctionInfo (*c10_b_info)[9];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i1;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_b_info = (c10_ResolvedFunctionInfo (*)[9])c10_info;
  (*c10_b_info)[0].context = "";
  (*c10_b_info)[0].name = "mtimes";
  (*c10_b_info)[0].dominantType = "double";
  (*c10_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[0].fileTimeLo = 1289519692U;
  (*c10_b_info)[0].fileTimeHi = 0U;
  (*c10_b_info)[0].mFileTimeLo = 0U;
  (*c10_b_info)[0].mFileTimeHi = 0U;
  (*c10_b_info)[1].context = "";
  (*c10_b_info)[1].name = "mrdivide";
  (*c10_b_info)[1].dominantType = "single";
  (*c10_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[1].fileTimeLo = 1357951548U;
  (*c10_b_info)[1].fileTimeHi = 0U;
  (*c10_b_info)[1].mFileTimeLo = 1319729966U;
  (*c10_b_info)[1].mFileTimeHi = 0U;
  (*c10_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[2].name = "rdivide";
  (*c10_b_info)[2].dominantType = "single";
  (*c10_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[2].fileTimeLo = 1346510388U;
  (*c10_b_info)[2].fileTimeHi = 0U;
  (*c10_b_info)[2].mFileTimeLo = 0U;
  (*c10_b_info)[2].mFileTimeHi = 0U;
  (*c10_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[3].name = "eml_scalexp_compatible";
  (*c10_b_info)[3].dominantType = "single";
  (*c10_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c10_b_info)[3].fileTimeLo = 1286818796U;
  (*c10_b_info)[3].fileTimeHi = 0U;
  (*c10_b_info)[3].mFileTimeLo = 0U;
  (*c10_b_info)[3].mFileTimeHi = 0U;
  (*c10_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[4].name = "eml_div";
  (*c10_b_info)[4].dominantType = "single";
  (*c10_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c10_b_info)[4].fileTimeLo = 1313347810U;
  (*c10_b_info)[4].fileTimeHi = 0U;
  (*c10_b_info)[4].mFileTimeLo = 0U;
  (*c10_b_info)[4].mFileTimeHi = 0U;
  (*c10_b_info)[5].context = "";
  (*c10_b_info)[5].name = "abs";
  (*c10_b_info)[5].dominantType = "single";
  (*c10_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c10_b_info)[5].fileTimeLo = 1343830366U;
  (*c10_b_info)[5].fileTimeHi = 0U;
  (*c10_b_info)[5].mFileTimeLo = 0U;
  (*c10_b_info)[5].mFileTimeHi = 0U;
  (*c10_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c10_b_info)[6].name = "eml_scalar_abs";
  (*c10_b_info)[6].dominantType = "single";
  (*c10_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c10_b_info)[6].fileTimeLo = 1286818712U;
  (*c10_b_info)[6].fileTimeHi = 0U;
  (*c10_b_info)[6].mFileTimeLo = 0U;
  (*c10_b_info)[6].mFileTimeHi = 0U;
  (*c10_b_info)[7].context = "";
  (*c10_b_info)[7].name = "eml_int_forloop_overflow_check";
  (*c10_b_info)[7].dominantType = "";
  (*c10_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c10_b_info)[7].fileTimeLo = 1346510340U;
  (*c10_b_info)[7].fileTimeHi = 0U;
  (*c10_b_info)[7].mFileTimeLo = 0U;
  (*c10_b_info)[7].mFileTimeHi = 0U;
  (*c10_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c10_b_info)[8].name = "intmax";
  (*c10_b_info)[8].dominantType = "char";
  (*c10_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c10_b_info)[8].fileTimeLo = 1311255316U;
  (*c10_b_info)[8].fileTimeHi = 0U;
  (*c10_b_info)[8].mFileTimeLo = 0U;
  (*c10_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c10_i1 = 0; c10_i1 < 9; c10_i1++) {
    c10_r0 = &c10_info[c10_i1];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo", c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i1);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i1);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_check_forloop_overflow_error
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, boolean_T
   c10_overflow)
{
  int32_T c10_i2;
  static char_T c10_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c10_u[34];
  const mxArray *c10_y = NULL;
  static char_T c10_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c10_b_u[5];
  const mxArray *c10_b_y = NULL;
  if (c10_overflow) {
    for (c10_i2 = 0; c10_i2 < 34; c10_i2++) {
      c10_u[c10_i2] = c10_cv0[c10_i2];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c10_i2 = 0; c10_i2 < 5; c10_i2++) {
      c10_b_u[c10_i2] = c10_cv1[c10_i2];
    }

    c10_b_y = NULL;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call("error", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c10_y,
      14, c10_b_y));
  }
}

static void c10_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_Num, const char_T *c10_identifier, int32_T
  c10_y[3])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_Num), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_Num);
}

static void c10_b_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  int32_T c10_y[3])
{
  int32_T c10_iv0[3];
  int32_T c10_i3;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_iv0, 1, 6, 0U, 1, 0U, 2, 1,
                3);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    c10_y[c10_i3] = c10_iv0[c10_i3];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_Sequence, const char_T *c10_identifier,
  int32_T c10_y[270])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_Sequence), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_Sequence);
}

static void c10_d_emlrt_marshallIn(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  int32_T c10_y[270])
{
  int32_T c10_iv1[270];
  int32_T c10_i4;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_iv1, 1, 6, 0U, 1, 0U, 2, 90,
                3);
  for (c10_i4 = 0; c10_i4 < 270; c10_i4++) {
    c10_y[c10_i4] = c10_iv1[c10_i4];
  }

  sf_mex_destroy(&c10_u);
}

static uint8_T c10_e_emlrt_marshallIn
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_b_is_active_c10_vipbarcoderecognition_2, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_vipbarcoderecognition_2), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_vipbarcoderecognition_2);
  return c10_y;
}

static uint8_T c10_f_emlrt_marshallIn
  (SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_vipbarcoderecognition_2InstanceStruct
  *chartInstance)
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

void sf_c10_vipbarcoderecognition_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2997796986U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1850758621U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(450468474U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1875851290U);
}

mxArray *sf_c10_vipbarcoderecognition_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5uqIiJcMfHpitvZcXu8Yy");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(90);
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_vipbarcoderecognition_2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c10_vipbarcoderecognition_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[14],T\"Num\",},{M[1],M[13],T\"Sequence\",},{M[8],M[0],T\"is_active_c10_vipbarcoderecognition_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_vipbarcoderecognition_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "iEwnIpcykaKB5XfCS2FktG";
}

static void sf_opaque_initialize_c10_vipbarcoderecognition_2(void
  *chartInstanceVar)
{
  initialize_params_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
  initialize_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_vipbarcoderecognition_2(void *chartInstanceVar)
{
  enable_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_vipbarcoderecognition_2(void *chartInstanceVar)
{
  disable_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_vipbarcoderecognition_2(void *chartInstanceVar)
{
  sf_c10_vipbarcoderecognition_2((SFc10_vipbarcoderecognition_2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_vipbarcoderecognition_2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_vipbarcoderecognition_2();/* state var info */
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

extern void sf_internal_set_sim_state_c10_vipbarcoderecognition_2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_vipbarcoderecognition_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_vipbarcoderecognition_2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c10_vipbarcoderecognition_2(S);
}

static void sf_opaque_set_sim_state_c10_vipbarcoderecognition_2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c10_vipbarcoderecognition_2(S, st);
}

static void sf_opaque_terminate_c10_vipbarcoderecognition_2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_vipbarcoderecognition_2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vipbarcoderecognition_2_optimization_info();
    }

    finalize_c10_vipbarcoderecognition_2
      ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_vipbarcoderecognition_2
    ((SFc10_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_vipbarcoderecognition_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_vipbarcoderecognition_2
      ((SFc10_vipbarcoderecognition_2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_vipbarcoderecognition_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vipbarcoderecognition_2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(286973981U));
  ssSetChecksum1(S,(997194892U));
  ssSetChecksum2(S,(3395171096U));
  ssSetChecksum3(S,(3890158110U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_vipbarcoderecognition_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_vipbarcoderecognition_2(SimStruct *S)
{
  SFc10_vipbarcoderecognition_2InstanceStruct *chartInstance;
  chartInstance = (SFc10_vipbarcoderecognition_2InstanceStruct *)utMalloc(sizeof
    (SFc10_vipbarcoderecognition_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_vipbarcoderecognition_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_vipbarcoderecognition_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_vipbarcoderecognition_2;
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

void c10_vipbarcoderecognition_2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_vipbarcoderecognition_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_vipbarcoderecognition_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_vipbarcoderecognition_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_vipbarcoderecognition_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
