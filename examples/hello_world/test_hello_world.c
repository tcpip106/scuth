/**
 * @file   test_hello_world.c
 * @brief  SCUTH usage example
 *
 * Copyright (c) 2014, tcpip106
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * This example shows the usage of the SCUTH MACROs. It verifies the 
 * hello_world function works as expected when fputs returns ok and fail.
 */

#include <string.h>
#include "unit_test_helper.h"

#include "hello_world.h"

int g_fputs_success = 1;

int TEST_MOCK(fputs)(const char *s, FILE *stream)
{
  TEST_ASSERT(0 != s);
  TEST_ASSERT(0 == strncmp("hello world", s, strlen(s)));

  if (1 == g_fputs_success) {
    return 1;
  } else {
    return -1;
  }
}

void test_hello_world_success()
{
  TEST_CASE("hello world - success");

  g_fputs_success = 1;
  TEST_ASSERT(1 == hello_world());

  TEST_PASS();
}

void test_hello_world_fail()
{
  TEST_CASE("hello world - fail");

  g_fputs_success = 0;
  TEST_ASSERT(-1 == hello_world());

  TEST_PASS();
}

int main() 
{
  test_hello_world_success();
  test_hello_world_fail();

  return TEST_RESULT_PASS;
}

