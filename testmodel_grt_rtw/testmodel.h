/*
 * testmodel.h
 *
 * Code generation for model "testmodel".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C++ source code generated on : Tue Apr 07 19:34:28 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_testmodel_h_
#define RTW_HEADER_testmodel_h_
#include <stddef.h>
#include <string.h>
#ifndef testmodel_COMMON_INCLUDES_
# define testmodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* testmodel_COMMON_INCLUDES_ */

#include "testmodel_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T avg;                          /* '<Root>/Chart' */
  uint8_T is_active_c3_testmodel;      /* '<Root>/Chart' */
  uint8_T is_c3_testmodel;             /* '<Root>/Chart' */
} DW_testmodel_T;

/* Parameters (auto storage) */
struct P_testmodel_T_ {
  real_T ts_Value[6];                  /* Expression: [12 232 2336 54 653 35]
                                        * Referenced by: '<Root>/ts'
                                        */
  real_T per_Value;                    /* Expression: 3
                                        * Referenced by: '<Root>/per  '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testmodel_T {
  const char_T *errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

/* Class declaration for model testmodel */
class testmodelModelClass {
  /* public data and function members */
 public:
  /* Model entry point functions */

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  testmodelModelClass();

  /* Destructor */
  ~testmodelModelClass();

  /* Real-Time Model get method */
  RT_MODEL_testmodel_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  P_testmodel_T testmodel_P;

  /* Block states */
  DW_testmodel_T testmodel_DW;

  /* Real-Time Model */
  RT_MODEL_testmodel_T testmodel_M;

  /* private member function(s) for subsystem '<Root>' */
  real_T testmodel_testMovAvg(const real_T x[6], real_T ped);
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'testmodel'
 * '<S1>'   : 'testmodel/Chart'
 */
#endif                                 /* RTW_HEADER_testmodel_h_ */
