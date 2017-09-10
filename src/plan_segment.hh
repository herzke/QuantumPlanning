/*
 * plan_segment.hh
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

#ifndef PLAN_SEGMENT_HH_
#define PLAN_SEGMENT_HH_

#include <cstdint>
#include <string>

/// A plan segment consists of an initial value, a start time, and a
/// growth rate. From there, it prescribes linear growth of a value.
class plan_segment_t {

  /// The start day of this plan segment.
  uint64_t start_time;

  /// The value of this plan segment on the day it starts
  double start_value;

  /// The rate of value change per time unit
  double growth_rate;

public:

  /// The constructor initializes the data members.
  /// @param start_time The point in time when this plan segment begins to
  ///                   prescribe values.  Unit of time is unspecified and
  ///                   has to be agreed on by the users of the class.
  /// @param start_value The initial value of this plan, i.e. valid at
  ///                   @c start_time
  /// @param growth_rate The rate of value change per time unit.
  plan_segment_t(uint64_t start_time, double start_value, double growth_rate);

  /// Ask the plan_segment for a prescribed value.
  /// @param time  The time for which the plan value is asked.
  /// @return the prescribed value for the time parameter.
  double operator()(uint64_t time) const;

  std::string to_string() const;
};

#endif /* PLAN_SEGMENT_HH_ */
