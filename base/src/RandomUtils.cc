//
// Copyright (C) [2020] Futurewei Technologies, Inc.
//
// FORCE-RISCV is licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
// FIT FOR A PARTICULAR PURPOSE.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "RandomUtils.h"

#include "Log.h"
#include "Random.h"

using namespace std;

namespace Force {

  uint32 random_value32(uint32 min, uint32 max)
  {
    return Random::Instance()->Random32(min, max);
  }

  uint64 random_value64(uint64 min, uint64 max)
  {
    return Random::Instance()->Random64(min, max);
  }

  double random_real(double min, double max)
  {
    return Random::Instance()->RandomReal(min, max);
  }

  void report_error(const char* pErrMsg)
  {
    LOG(fail) << "[report_error] " << pErrMsg << endl;
    FAIL("error-in-random-utils");
  }

}
