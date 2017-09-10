/*
 * plan_segment_test.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: herzke
 *
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <https://unlicense.org>
 * 
 */

#include <gtest/gtest.h>
#include <plan_segment.hh>

/// class can be instantiated.
TEST(plan_segment, plan_segment_constructor_takes_uint64_double_double) {
	EXPECT_NO_THROW(plan_segment_t plan_segment(0U, 0.0, 0.0));
}

/// Fixture with example data for tests
class plan_segment_fixture : public ::testing::Test {
protected:
	// Plan segment starts on day 0 with value 0.0 and is always 0.0
	plan_segment_t ps000 = {0U,0.0,0.0};

	// Plan segment starts on day 1 with value 1.0 and rises 0.5 per day
	plan_segment_t ps11half = {1U, 1.0, 0.5};

	// Plan segment starts on day 2 with value 0.5 and sinks 0.1 per day
	plan_segment_t ps2halfmtenth = {2U, 0.5, -0.1};
};

TEST_F(plan_segment_fixture, plan_segment_returns_start_value_on_first_day) {
	EXPECT_EQ(0.0, ps000(0U));
	EXPECT_EQ(1.0, ps11half(1U));
	EXPECT_EQ(0.5, ps2halfmtenth(2U));
}
