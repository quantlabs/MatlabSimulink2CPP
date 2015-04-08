/*
 * testmodel.cpp
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
#include "testmodel.h"
#include "testmodel_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define testmodel_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define testmodel_IN_buy               ((uint8_T)1U)
#define testmodel_IN_sell              ((uint8_T)2U)

/*
 * Function for Chart: '<Root>/Chart'
 * function avgNum=testMovAvg(x,ped)
 */
real_T testmodelModelClass::testmodel_testMovAvg(const real_T x[6], real_T ped)
{
  real_T y;
  int32_T k;

  /* MATLAB Function 'testMovAvg': '<S1>:2' */
  /* ensure out variable does not cofnflict with other model objects  */
  /* this directive is need to add input and output on Stateflow chart block! */
  /* '<S1>:2:5' avgNum = 0; */
  /* must define for code generation */
  /* '<S1>:2:6' avgNum = sum(x)/ped; */
  y = x[0];
  for (k = 0; k < 5; k++) {
    y += x[k + 1];
  }

  return y / ped;
}

/* Model step function */
void testmodelModelClass::step()
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/per  '
   *  Constant: '<Root>/ts'
   */
  /* Gateway: Chart */
  /* During: Chart */
  if (testmodel_DW.is_active_c3_testmodel == 0U) {
    /* Entry: Chart */
    testmodel_DW.is_active_c3_testmodel = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:6' */
    /* '<S1>:6:1' avg=testMovAvg(ts,pd) */
    testmodel_DW.avg = testmodel_testMovAvg(testmodel_P.ts_Value,
      testmodel_P.per_Value);

    /* '<S1>:10:1' sf_internal_predicateOutput = ... */
    /* '<S1>:10:1' avg<50; */
    if (testmodel_DW.avg < 50.0) {
      /* Transition: '<S1>:10' */
      testmodel_DW.is_c3_testmodel = testmodel_IN_buy;

      /* Entry 'buy': '<S1>:8' */
      /* '<S1>:8:1' posFlag=1 */
    } else {
      /* '<S1>:12:1' sf_internal_predicateOutput = ... */
      /* '<S1>:12:1' avg>50; */
      if (testmodel_DW.avg > 50.0) {
        /* Transition: '<S1>:12' */
        testmodel_DW.is_c3_testmodel = testmodel_IN_sell;

        /* Entry 'sell': '<S1>:9' */
        /* '<S1>:9:1' posFlag=-1 */
      }
    }
  } else if (testmodel_DW.is_c3_testmodel == testmodel_IN_buy) {
    /* During 'buy': '<S1>:8' */
    /* Transition: '<S1>:11' */
    /* '<S1>:10:1' sf_internal_predicateOutput = ... */
    /* '<S1>:10:1' avg<50; */
    if (testmodel_DW.avg < 50.0) {
      /* Transition: '<S1>:10' */
      testmodel_DW.is_c3_testmodel = testmodel_IN_buy;

      /* Entry 'buy': '<S1>:8' */
      /* '<S1>:8:1' posFlag=1 */
    } else {
      /* '<S1>:12:1' sf_internal_predicateOutput = ... */
      /* '<S1>:12:1' avg>50; */
      if (testmodel_DW.avg > 50.0) {
        /* Transition: '<S1>:12' */
        testmodel_DW.is_c3_testmodel = testmodel_IN_sell;

        /* Entry 'sell': '<S1>:9' */
        /* '<S1>:9:1' posFlag=-1 */
      }
    }
  } else {
    /* During 'sell': '<S1>:9' */
    /* Transition: '<S1>:13' */
    /* '<S1>:10:1' sf_internal_predicateOutput = ... */
    /* '<S1>:10:1' avg<50; */
    if (testmodel_DW.avg < 50.0) {
      /* Transition: '<S1>:10' */
      testmodel_DW.is_c3_testmodel = testmodel_IN_buy;

      /* Entry 'buy': '<S1>:8' */
      /* '<S1>:8:1' posFlag=1 */
    } else {
      /* '<S1>:12:1' sf_internal_predicateOutput = ... */
      /* '<S1>:12:1' avg>50; */
      if (testmodel_DW.avg > 50.0) {
        /* Transition: '<S1>:12' */
        testmodel_DW.is_c3_testmodel = testmodel_IN_sell;

        /* Entry 'sell': '<S1>:9' */
        /* '<S1>:9:1' posFlag=-1 */
      }
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void testmodelModelClass::initialize()
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus((&testmodel_M), (NULL));

  /* states (dwork) */
  (void) memset((void *)&testmodel_DW, 0,
                sizeof(DW_testmodel_T));

  /* InitializeConditions for Chart: '<Root>/Chart' */
  testmodel_DW.is_active_c3_testmodel = 0U;
  testmodel_DW.is_c3_testmodel = testmodel_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void testmodelModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
testmodelModelClass::testmodelModelClass()
{
  static const P_testmodel_T testmodel_P_temp = {
    /*  Expression: [12 232 2336 54 653 35]
     * Referenced by: '<Root>/ts'
     */
    { 12.0, 232.0, 2336.0, 54.0, 653.0, 35.0 },
    3.0                                /* Expression: 3
                                        * Referenced by: '<Root>/per  '
                                        */
  };                                   /* Modifiable parameters */

  /* Initialize tunable parameters */
  testmodel_P = testmodel_P_temp;
}

/* Destructor */
testmodelModelClass::~testmodelModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_testmodel_T * testmodelModelClass::getRTM()
{
  return (&testmodel_M);
}
