#ifndef __c10_vipbarcoderecognition_2_h__
#define __c10_vipbarcoderecognition_2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c10_ResolvedFunctionInfo
#define typedef_c10_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c10_ResolvedFunctionInfo;

#endif                                 /*typedef_c10_ResolvedFunctionInfo*/

#ifndef typedef_SFc10_vipbarcoderecognition_2InstanceStruct
#define typedef_SFc10_vipbarcoderecognition_2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c10_is_active_c10_vipbarcoderecognition_2;
} SFc10_vipbarcoderecognition_2InstanceStruct;

#endif                                 /*typedef_SFc10_vipbarcoderecognition_2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c10_vipbarcoderecognition_2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_vipbarcoderecognition_2_get_check_sum(mxArray *plhs[]);
extern void c10_vipbarcoderecognition_2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
