/*
 * Copyright (c) 2023-2024, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "gcov_test.h"
#include <stdio.h>
#include <unity/unity.h>
#pragma GCC optimize("O3,inline")

int Calc(int i, int j) {
  int res;
  if (i==0) {
    res = i+1;
  } else if (i>0 && j<10) {
    res = i+j;
  }
  return res;
}

int Value(int i) {
  if (i==3) {
    return 5;
  }
  return 1;
}

void Test2(int *p) {
  if (*p!=0) {
    if (Value(*p)==5) {
      printf("value is 5\n");
      *p = 0;
    }
  }
}
