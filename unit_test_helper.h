/**
 * @file   unit_test_helper.h
 * @brief  SCUTH (Simple C Unit Test Helper) header file
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
 * SCUTH provides C MACROs to assist writing unit tests for you C source code.
 */
#ifndef __UNIT_TEST_HELPER_H__
#define __UNIT_TEST_HELPER_H__

#ifdef  __cplusplus
extern "C" {
#endif  /* __cplusplus */

#include <stdio.h>
#include <stdlib.h>

#define TEST_RESULT_PASS   0
#define TEST_RESULT_FAIL  -1

#define TEST_CASE(whatever...) \
    { \
        printf("Test Case -- "); \
        printf(whatever); \
        printf("\n"); \
    }

#define TEST_PASS() \
    { \
        printf("-----> PASS\n"); \
    }

#define TEST_FAIL(whatever...) \
    { \
        printf("-----> FAIL : "); \
        printf("(%s:%d)", __FILE__, __LINE__); \
        printf(whatever); \
        printf("\n"); \
        exit(TEST_RESULT_FAIL); \
    }

#define TEST_ASSERT(statement) \
    { \
        if (!(statement)) { \
            TEST_FAIL("Not TRUE: %s", #statement); \
        } \
    }

#define TEST_BEGIN() \
    { \
    }

#define TEST_END() \
    { \
        exit(TEST_RESULT_PASS); \
    }

#define TEST_MOCK(func) __wrap_##func 


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __UNIT_TEST_HELPER_H__ */

