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
#include "OperandDataRequest.h"

#include <sstream>

#include "Data.h"
#include "Log.h"

using namespace std;

namespace Force {
  OperandDataRequest::OperandDataRequest(const string& name, const string& valueStr)
    : Object(), mName(name), mstrData(), mApplied(false)
  {
    SetDataRequest(valueStr);
  }

  OperandDataRequest::OperandDataRequest(const OperandDataRequest& rOther)
    : Object(rOther), mName(rOther.mName), mstrData(), mApplied(false)
  {
  }

  OperandDataRequest::~OperandDataRequest()
  {
  }

  Object* OperandDataRequest::Clone() const
  {
    return new OperandDataRequest(*this);
  }

  const std::string OperandDataRequest::ToString() const
  {
    stringstream out_stream;

    out_stream << Type() << ": " << Name();
    out_stream << "<=" << mstrData ;

    return out_stream.str();
  }

  void OperandDataRequest::SetDataRequest(const string& valueStr)
  {
    mstrData = valueStr;
  }

}
