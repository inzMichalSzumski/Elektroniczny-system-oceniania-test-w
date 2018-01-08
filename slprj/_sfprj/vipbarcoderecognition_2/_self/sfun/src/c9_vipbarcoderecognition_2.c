/* Include files */

#include <stddef.h>
#include "blas.h"
#include "vipbarcoderecognition_2_sfun.h"
#include "c9_vipbarcoderecognition_2.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void initialize_params_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void enable_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void disable_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void set_sim_state_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void sf_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void initSimStructsc9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void registerMessagesc9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static void c9_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_Center, const char_T *c9_identifier,
  real32_T c9_y[600]);
static void c9_b_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real32_T c9_y[600]);
static void c9_c_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_Num, const char_T *c9_identifier, int32_T
  c9_y[3]);
static void c9_d_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  int32_T c9_y[3]);
static uint8_T c9_e_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct *
  chartInstance, const mxArray *c9_b_is_active_c9_vipbarcoderecognition_2, const
  char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_vipbarcoderecognition_2 = 0U;
}

static void initialize_params_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void enable_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real32_T c9_u[600];
  const mxArray *c9_b_y = NULL;
  int32_T c9_b_u[3];
  const mxArray *c9_c_y = NULL;
  real32_T c9_c_u[600];
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real32_T (*c9_Width)[600];
  int32_T (*c9_Num)[3];
  real32_T (*c9_Center)[600];
  c9_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Width = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Center = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(4), FALSE);
  for (c9_i0 = 0; c9_i0 < 600; c9_i0++) {
    c9_u[c9_i0] = (*c9_Center)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 1, 0U, 1U, 0U, 2, 200, 3),
                FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0++) {
    c9_b_u[c9_i0] = (*c9_Num)[c9_i0];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 6, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i0 = 0; c9_i0 < 600; c9_i0++) {
    c9_c_u[c9_i0] = (*c9_Width)[c9_i0];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 1, 0U, 1U, 0U, 2, 200, 3),
                FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_u = chartInstance->c9_is_active_c9_vipbarcoderecognition_2;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real32_T (*c9_Center)[600];
  int32_T (*c9_Num)[3];
  real32_T (*c9_Width)[600];
  c9_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Width = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Center = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                      "Center", *c9_Center);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                        "Num", *c9_Num);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
                      "Width", *c9_Width);
  chartInstance->c9_is_active_c9_vipbarcoderecognition_2 = c9_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
     "is_active_c9_vipbarcoderecognition_2");
  sf_mex_destroy(&c9_u);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void sf_c9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
  int32_T c9_iFeature;
  real32_T c9_F[960];
  real32_T c9_Center[600];
  real32_T c9_Width[600];
  uint8_T c9_Num[3];
  int32_T c9_iBar;
  int32_T c9_iPix;
  real32_T c9_curWidth;
  real32_T c9_curCenter;
  real32_T (*c9_b_Center)[600];
  real32_T (*c9_b_Width)[600];
  int32_T (*c9_b_Num)[3];
  real32_T (*c9_b_F)[960];
  c9_b_Num = (int32_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_Width = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_Center = (real32_T (*)[600])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_F = (real32_T (*)[960])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  for (c9_iFeature = 0; c9_iFeature < 960; c9_iFeature++) {
    c9_F[c9_iFeature] = (*c9_b_F)[c9_iFeature];
  }

  for (c9_iFeature = 0; c9_iFeature < 600; c9_iFeature++) {
    c9_Center[c9_iFeature] = 0.0F;
    c9_Width[c9_iFeature] = 0.0F;
  }

  for (c9_iFeature = 0; c9_iFeature < 3; c9_iFeature++) {
    c9_Num[c9_iFeature] = 0U;
  }

  for (c9_iFeature = 0; c9_iFeature < 3; c9_iFeature++) {
    c9_iBar = -1;
    c9_iPix = 0;
    while ((c9_iPix + 1 <= 320) && (c9_iBar + 1 < 200)) {
      c9_curWidth = 0.0F;
      c9_curCenter = 0.0F;
      while ((c9_iPix + 1 <= 320) && (c9_F[c9_iFeature + 3 * c9_iPix] >= 0.0F))
      {
        c9_curWidth += c9_F[c9_iFeature + 3 * c9_iPix];
        c9_curCenter += c9_F[c9_iFeature + 3 * c9_iPix] * (real32_T)(c9_iPix + 1);
        c9_iPix++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c9_iBar++;
      if (c9_curWidth > 0.0F) {
        c9_Center[c9_iBar + 200 * c9_iFeature] = c9_curCenter / c9_curWidth;
        c9_Width[c9_iBar + 200 * c9_iFeature] = c9_curWidth;
      }

      c9_curWidth = 0.0F;
      c9_curCenter = 0.0F;
      while ((c9_iPix + 1 <= 320) && (c9_F[c9_iFeature + 3 * c9_iPix] < 0.0F)) {
        c9_curWidth += c9_F[c9_iFeature + 3 * c9_iPix];
        c9_curCenter += c9_F[c9_iFeature + 3 * c9_iPix] * (real32_T)(c9_iPix + 1);
        c9_iPix++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      if ((c9_curWidth < 0.0F) && (c9_iBar + 1 < 200)) {
        c9_iBar++;
        c9_Center[c9_iBar + 200 * c9_iFeature] = c9_curCenter / c9_curWidth;
        c9_Width[c9_iBar + 200 * c9_iFeature] = -c9_curWidth;
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c9_Num[c9_iFeature] = (uint8_T)(c9_iBar + 1);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c9_iFeature = 0; c9_iFeature < 600; c9_iFeature++) {
    (*c9_b_Center)[c9_iFeature] = c9_Center[c9_iFeature];
    (*c9_b_Width)[c9_iFeature] = c9_Width[c9_iFeature];
  }

  for (c9_iFeature = 0; c9_iFeature < 3; c9_iFeature++) {
    (*c9_b_Num)[c9_iFeature] = c9_Num[c9_iFeature];
  }
}

static void initSimStructsc9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void registerMessagesc9_vipbarcoderecognition_2
  (SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

const mxArray *sf_c9_vipbarcoderecognition_2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[5];
  c9_ResolvedFunctionInfo (*c9_b_info)[5];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i1;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[5])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "mtimes";
  (*c9_b_info)[0].dominantType = "single";
  (*c9_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c9_b_info)[0].fileTimeLo = 1289519692U;
  (*c9_b_info)[0].fileTimeHi = 0U;
  (*c9_b_info)[0].mFileTimeLo = 0U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  (*c9_b_info)[1].context = "";
  (*c9_b_info)[1].name = "mrdivide";
  (*c9_b_info)[1].dominantType = "single";
  (*c9_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[1].fileTimeLo = 1357951548U;
  (*c9_b_info)[1].fileTimeHi = 0U;
  (*c9_b_info)[1].mFileTimeLo = 1319729966U;
  (*c9_b_info)[1].mFileTimeHi = 0U;
  (*c9_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[2].name = "rdivide";
  (*c9_b_info)[2].dominantType = "single";
  (*c9_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[2].fileTimeLo = 1346510388U;
  (*c9_b_info)[2].fileTimeHi = 0U;
  (*c9_b_info)[2].mFileTimeLo = 0U;
  (*c9_b_info)[2].mFileTimeHi = 0U;
  (*c9_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[3].name = "eml_scalexp_compatible";
  (*c9_b_info)[3].dominantType = "single";
  (*c9_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c9_b_info)[3].fileTimeLo = 1286818796U;
  (*c9_b_info)[3].fileTimeHi = 0U;
  (*c9_b_info)[3].mFileTimeLo = 0U;
  (*c9_b_info)[3].mFileTimeHi = 0U;
  (*c9_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[4].name = "eml_div";
  (*c9_b_info)[4].dominantType = "single";
  (*c9_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c9_b_info)[4].fileTimeLo = 1313347810U;
  (*c9_b_info)[4].fileTimeHi = 0U;
  (*c9_b_info)[4].mFileTimeLo = 0U;
  (*c9_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c9_i1 = 0; c9_i1 < 5; c9_i1++) {
    c9_r0 = &c9_info[c9_i1];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i1);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i1);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_Center, const char_T *c9_identifier,
  real32_T c9_y[600])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Center), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Center);
}

static void c9_b_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real32_T c9_y[600])
{
  real32_T c9_fv0[600];
  int32_T c9_i2;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_fv0, 1, 1, 0U, 1, 0U, 2, 200,
                3);
  for (c9_i2 = 0; c9_i2 < 600; c9_i2++) {
    c9_y[c9_i2] = c9_fv0[c9_i2];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_Num, const char_T *c9_identifier, int32_T
  c9_y[3])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Num), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Num);
}

static void c9_d_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  int32_T c9_y[3])
{
  int32_T c9_iv0[3];
  int32_T c9_i3;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_iv0, 1, 6, 0U, 1, 0U, 2, 1, 3);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    c9_y[c9_i3] = c9_iv0[c9_i3];
  }

  sf_mex_destroy(&c9_u);
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct *
  chartInstance, const mxArray *c9_b_is_active_c9_vipbarcoderecognition_2, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_vipbarcoderecognition_2), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_vipbarcoderecognition_2);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_vipbarcoderecognition_2InstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_vipbarcoderecognition_2InstanceStruct
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

void sf_c9_vipbarcoderecognition_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(923877605U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2934976133U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3575249001U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(699114595U);
}

mxArray *sf_c9_vipbarcoderecognition_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MNZBuVRhuc3opfNNvDrMjC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_vipbarcoderecognition_2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c9_vipbarcoderecognition_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"Center\",},{M[1],M[13],T\"Num\",},{M[1],M[14],T\"Width\",},{M[8],M[0],T\"is_active_c9_vipbarcoderecognition_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_vipbarcoderecognition_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "5F7sn4PZaKyl94NmuMd08C";
}

static void sf_opaque_initialize_c9_vipbarcoderecognition_2(void
  *chartInstanceVar)
{
  initialize_params_c9_vipbarcoderecognition_2
    ((SFc9_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
  initialize_c9_vipbarcoderecognition_2
    ((SFc9_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_vipbarcoderecognition_2(void *chartInstanceVar)
{
  enable_c9_vipbarcoderecognition_2((SFc9_vipbarcoderecognition_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_vipbarcoderecognition_2(void *chartInstanceVar)
{
  disable_c9_vipbarcoderecognition_2((SFc9_vipbarcoderecognition_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_vipbarcoderecognition_2(void *chartInstanceVar)
{
  sf_c9_vipbarcoderecognition_2((SFc9_vipbarcoderecognition_2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_vipbarcoderecognition_2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_vipbarcoderecognition_2
    ((SFc9_vipbarcoderecognition_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_vipbarcoderecognition_2();/* state var info */
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

extern void sf_internal_set_sim_state_c9_vipbarcoderecognition_2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_vipbarcoderecognition_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_vipbarcoderecognition_2
    ((SFc9_vipbarcoderecognition_2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_vipbarcoderecognition_2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c9_vipbarcoderecognition_2(S);
}

static void sf_opaque_set_sim_state_c9_vipbarcoderecognition_2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_vipbarcoderecognition_2(S, st);
}

static void sf_opaque_terminate_c9_vipbarcoderecognition_2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_vipbarcoderecognition_2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_vipbarcoderecognition_2_optimization_info();
    }

    finalize_c9_vipbarcoderecognition_2
      ((SFc9_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_vipbarcoderecognition_2
    ((SFc9_vipbarcoderecognition_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_vipbarcoderecognition_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_vipbarcoderecognition_2
      ((SFc9_vipbarcoderecognition_2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_vipbarcoderecognition_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vipbarcoderecognition_2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2276093551U));
  ssSetChecksum1(S,(2944640181U));
  ssSetChecksum2(S,(1207435983U));
  ssSetChecksum3(S,(2319139048U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_vipbarcoderecognition_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_vipbarcoderecognition_2(SimStruct *S)
{
  SFc9_vipbarcoderecognition_2InstanceStruct *chartInstance;
  chartInstance = (SFc9_vipbarcoderecognition_2InstanceStruct *)utMalloc(sizeof
    (SFc9_vipbarcoderecognition_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_vipbarcoderecognition_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_vipbarcoderecognition_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_vipbarcoderecognition_2;
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

void c9_vipbarcoderecognition_2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_vipbarcoderecognition_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_vipbarcoderecognition_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_vipbarcoderecognition_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_vipbarcoderecognition_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
