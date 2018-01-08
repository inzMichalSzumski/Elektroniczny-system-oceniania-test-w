/* Include files */

#include "blokowy_sfun.h"
#include "blokowy_sfun_debug_macros.h"
#include "c6_blokowy.h"
#include "c7_blokowy.h"
#include "c8_blokowy.h"
#include "c9_blokowy.h"
#include "c10_blokowy.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _blokowyMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void blokowy_initializer(void)
{
}

void blokowy_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_blokowy_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==6) {
    c6_blokowy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_blokowy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_blokowy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_blokowy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_blokowy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_blokowy_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1698701839U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3140256454U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1063146038U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2339096189U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(137768651U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4126228036U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1608878547U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1626229520U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 6:
        {
          extern void sf_c6_blokowy_get_check_sum(mxArray *plhs[]);
          sf_c6_blokowy_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_blokowy_get_check_sum(mxArray *plhs[]);
          sf_c7_blokowy_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_blokowy_get_check_sum(mxArray *plhs[]);
          sf_c8_blokowy_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_blokowy_get_check_sum(mxArray *plhs[]);
          sf_c9_blokowy_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_blokowy_get_check_sum(mxArray *plhs[]);
          sf_c10_blokowy_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(369497552U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(617855313U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2619553484U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3642398450U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_blokowy_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 6:
      {
        if (strcmp(aiChksum, "mcN20Wlerk7zkmiEv128aH") == 0) {
          extern mxArray *sf_c6_blokowy_get_autoinheritance_info(void);
          plhs[0] = sf_c6_blokowy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "eXuRFB128jCPKd4N68UPNE") == 0) {
          extern mxArray *sf_c7_blokowy_get_autoinheritance_info(void);
          plhs[0] = sf_c7_blokowy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "Vi3xD7xCRAiRzTI5nsbBcB") == 0) {
          extern mxArray *sf_c8_blokowy_get_autoinheritance_info(void);
          plhs[0] = sf_c8_blokowy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "OXXOpSi3cI6aJuxA9LuhcC") == 0) {
          extern mxArray *sf_c9_blokowy_get_autoinheritance_info(void);
          plhs[0] = sf_c9_blokowy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "QENw0uLwWORvmhdUDNM7C") == 0) {
          extern mxArray *sf_c10_blokowy_get_autoinheritance_info(void);
          plhs[0] = sf_c10_blokowy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_blokowy_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 6:
      {
        extern const mxArray *sf_c6_blokowy_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_blokowy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_blokowy_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_blokowy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_blokowy_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_blokowy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_blokowy_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_blokowy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_blokowy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_blokowy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_blokowy_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 6:
      {
        if (strcmp(tpChksum, "WNx6KD6oi6Jvz0bsMIWeNC") == 0) {
          extern mxArray *sf_c6_blokowy_third_party_uses_info(void);
          plhs[0] = sf_c6_blokowy_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "jov3DNqqdHejHqigu4RHZD") == 0) {
          extern mxArray *sf_c7_blokowy_third_party_uses_info(void);
          plhs[0] = sf_c7_blokowy_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "JvNanUkosqMbWN809moo3C") == 0) {
          extern mxArray *sf_c8_blokowy_third_party_uses_info(void);
          plhs[0] = sf_c8_blokowy_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "YCJmKQhRYNBnCPJxxGDdQ") == 0) {
          extern mxArray *sf_c9_blokowy_third_party_uses_info(void);
          plhs[0] = sf_c9_blokowy_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "B3wPEW6BpGCfpL7ofLY3LC") == 0) {
          extern mxArray *sf_c10_blokowy_third_party_uses_info(void);
          plhs[0] = sf_c10_blokowy_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void blokowy_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _blokowyMachineNumber_ = sf_debug_initialize_machine(debugInstance,"blokowy",
    "sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_blokowyMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_blokowyMachineNumber_,0);
}

void blokowy_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_blokowy_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("blokowy",
      "blokowy");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_blokowy_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
