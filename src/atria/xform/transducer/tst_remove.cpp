//
// Copyright (C) 2014, 2015 Ableton AG, Berlin. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#include <atria/xform/concepts.hpp>
#include <atria/xform/reducing/last_rf.hpp>
#include <atria/xform/transduce.hpp>
#include <atria/xform/transducer/remove.hpp>
#include <atria/xform/transducer/map.hpp>
#include <atria/prelude/comp.hpp>
#include <atria/testing/gtest.hpp>

namespace atria {
namespace xform {

TEST(remove, concept)
{
  meta::check<Transducer_spec(decltype(filter(std::less<int>{})),
                              meta::pack<int, int>)>();
}

TEST(remove, simple)
{
  auto v = std::vector<int> { 1, 2, 3, 6 };
  auto times2 = [] (int x) { return x * 2; };
  auto odd = [] (int x) { return x % 2 == 0; };

  auto res = transduce(
    comp(remove(odd), map(times2)), std::plus<int>{}, 1, v);
  EXPECT_EQ(res, 9);
}

} // namespace xform
} // namespace atria
