#ifndef __c6_blokowy_h__
#define __c6_blokowy_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c6_ResolvedFunctionInfo
#define typedef_c6_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c6_ResolvedFunctionInfo;

#endif                                 /*typedef_c6_ResolvedFunctionInfo*/

#ifndef typedef_SFc6_blokowyInstanceStruct
#define typedef_SFc6_blokowyInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c6_is_active_c6_blokowy;
} SFc6_blokowyInstanceStruct;

#endif                                 /*typedef_SFc6_blokowyInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_blokowy_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_blokowy_get_check_sum(mxArray *plhs[]);
extern void c6_blokowy_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
