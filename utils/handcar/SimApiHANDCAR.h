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
#ifndef Force_SimApiHANDCAR_H
#define Force_SimApiHANDCAR_H

#include "SimAPI.h"

class SimDllApi;
class SimException;

namespace Force {

  /*!
    \class SimApiHANDCAR
    \brief C++ wrapper class for HANDCAR RISC-V simulator.
  */

  class SimApiHANDCAR : public SimAPI {
  public:
    SimApiHANDCAR(); //!< Constructor
    ~SimApiHANDCAR(); //!< Destructor.

    //!< Initialize simulator shared object using standard Force parameters...
    void InitializeIss(const ApiSimConfig& rConfig, const std::string &rSimSoFile, const std::string& rApiTraceFile) override;

    //!< write out simulation trace file (if any), send 'terminate' directive to simulator...
    void Terminate() override;

    //!< obtain the opcode and dissassembly that corresponds to a given PC address
    void GetDisassembly(uint32 CpuID, const uint64_t* pPc, std::string& rOpcode, std::string& rDisassembly);

    //!< write simulator physical memory. Return 0 if no errors...
    void WritePhysicalMemory(uint32 memBank, uint64 address, uint32  size, const unsigned char *pBytes) override;

    //!< read register value...
    void ReadRegister(uint32 CpuID, const char *regname, uint64 *rval, uint64 *pRegMask) override;

    //!< read the bytes corresponding a physical register from a large logical register without forcing the simulator to used Force's naming convention.
    void PartialReadLargeRegister(uint32 CpuID, const char* pRegname, uint8_t* pBytes, uint32 length, uint32 offset) override;

    //!< write simulator register. mask indicates which bits to write...
    void WriteRegister(uint32 CpuID,const char *regname,uint64 rval,uint64 rmask) override;

    //!< step instruction for specified cpu; returns after simulator step complete, with all updates.
    void Step(uint32 cpuid,std::vector<RegUpdate> &rRegUpdates,std::vector<MemUpdate> &rMemUpdates,
	      std::vector<MmuEvent> &rMmuEvents, std::vector<ExceptionUpdate> &rExceptUpdates) override;

    void WakeUp(uint32 cpuId) override; //!< Wake up from lower power state.
    void TurnOn(uint32 cpuId) override; //!< Turn the Iss thread on.
    void EnterSpeculativeMode(uint32 cpuId) override; //!< The CPU thread enters speculative mode.
    void LeaveSpeculativeMode(uint32 cpuId) override; //!< The CPU thread leaves speculative mode.
    void RecordExceptionUpdate(const SimException *pException) override; //!< Record exception update.

    ASSIGNMENT_OPERATOR_ABSENT(SimApiHANDCAR);
    COPY_CONSTRUCTOR_ABSENT(SimApiHANDCAR);
  private:
    std::string BuildHandcarConfigurationString(const ApiSimConfig& rConfig);
  private:
    SimDllApi * mpSimDllAPI;       //!< Simulator shared object APIs.
  };
}

#endif
