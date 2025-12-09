/*
 * Copyright (c) 2023, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#if PL_CONFIG_USE_UNIT_TESTS
#include "tests.h"

#include "unity.h"
#include "McuUnity.h"
#include "McuRTOS.h"
#include "McuShell.h"
#include "McuRTT.h"
#include "McuUtility.h"
#include "McuLog.h"
#include "test_leds.h"
#include "test_gcov_test.h"

void Tests_Run(void) {
    unsigned char buf[32];
    int nofBytes = McuUnity_RTT_GetArgs(buf, sizeof(buf));
    if (nofBytes <= 0) {
        TEST_ASSERT_MESSAGE(false, "No test argument provided");
    }

    UNITY_BEGIN();

    if (McuUtility_strcmp((char*)buf, "led_1") == 0) {
        RUN_TEST(TestLeds_OnOff);
    } else if (McuUtility_strcmp((char*)buf, "led_2") == 0) {
        RUN_TEST(TestLeds_Toggle);
    } else if (McuUtility_strcmp((char*)buf, "gcov") == 0) {
        RUN_TEST(TestGcov_Calc);
        RUN_TEST(TestGcov_Value);
        RUN_TEST(TestGcov_Test2);
    } else {
        TEST_ASSERT_MESSAGE(false, "Unknown test argument");
    }

    int nofFailures = UNITY_END();

#if PL_CONFIG_USE_RTT
    McuUnity_Exit_JRun_RTT(nofFailures == 0);
#else
    McuUnity_Exit_LinkServer_Log(nofFailures == 0);
#endif
}

static void TestTask(void *pv) {
    McuLog_info("starting test task");
    Tests_Run();
    vTaskDelete(NULL); /* terminate task */
}

void Tests_Init(void) {
  if (xTaskCreate(
      TestTask,  /* pointer to the task */
      "Test", /* task name for kernel awareness debugging */
      1500/sizeof(StackType_t), /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY,  /* initial priority */
      (TaskHandle_t*)NULL /* optional task handle to create */
    ) != pdPASS)
  {
    McuLog_fatal("Failed creating task");
    for(;;){} /* error! probably out of memory */
  }
}
#endif /* PL_CONFIG_USE_UNIT_TESTS */