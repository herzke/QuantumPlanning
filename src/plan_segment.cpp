/*
 * plan_segment.cpp
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

#include <plan_segment.hh>
#include <stdexcept>

plan_segment_t::plan_segment_t(
    uint64_t start_time,
    double start_value,
    double growth_rate)
: start_time(start_time)
, start_value(start_value)
, growth_rate(growth_rate)
{}

double plan_segment_t::operator()(uint64_t time) const {
  if (time < start_time) {
    std::string error_message =
        to_string() + "operator() called with too early time="
        + std::to_string(time);
    throw std::underflow_error(error_message);
    }
  uint64_t time_into_the_plan = time - start_time;
  double value_difference = time_into_the_plan * growth_rate;
  return start_value + value_difference;
}

std::string plan_segment_t::to_string() const {
  return "";
}
