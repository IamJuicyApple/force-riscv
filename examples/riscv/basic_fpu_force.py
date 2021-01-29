#
# Copyright (C) [2020] Futurewei Technologies, Inc.
#
# FORCE-RISCV is licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
# FIT FOR A PARTICULAR PURPOSE.
# See the License for the specific language governing permissions and
# limitations under the License.
#
from riscv.EnvRISCV import EnvRISCV
from riscv.GenThreadRISCV import GenThreadRISCV
from base.Sequence import Sequence
from base.InstructionMap import InstructionMap
from DV.riscv.trees.instruction_tree import *

class MainSequence(Sequence):
    """Generate a sequence of instructions that are randomly selected from the specified subset 
       of RISC-V instructions.  
       1 specify the number of instructions to be generated by setting instruction_count
       2 specify a the desired subset by setting the instruction_group.  Some of the predefined
         instruction subsets are listed below with the statement for all but one commented out. Just
         uncomment the subset you wish to use, while commenting out the others.  For more details
         on the specific instructions in each subset and a list of the other available predefined
         subsets, see  force/py/DV/riscv/trees/instruction_tree.py.
       3 if you want to a specific instruction, set the_instruction2 to the appropriate string and
         use the_instruction2 in the genInstruction call.
    """

    def generate(self, **kargs):

        # 1 - set the number of instructions to generate, 
        # can configure via control file with generator option - 'instruction_count'
        (count_opt, count_opt_valid) = self.getOption("instruction_count")
        if count_opt_valid:
            instruction_count = count_opt
        else:
            instruction_count = 100

        # 2 - Choose the subset of RISCV instruction you wish to use
        # instruction_group = RV_G_instructions
        # instruction_group = RV64F_instructions
        # instruction_group = RV32F_instructions
        # instruction_group = BranchJump_instructions
        # instruction_group = LDST_All_instructions
        # instruction_group = ALU_Int_All_instructions
        # instruction_group = ALU_Float_All_instructions
        # instruction_group = RV32I_instructions
        # instruction_group = RV_A_instructions

        # or can merge instruction groups 
        #instruction_group = Merge(RV64F_instructions,RV32F_instructions)

        # 3 - If you want to specify a specific instruction, set the_instruction2 to the appropriate string here
        # and replace the argument in the genInstruction call to the_instruction2.  For the string values to 
        # use for a given instruction, search for that instruction in force/py/DV/riscv/trees/instruction_tree.py.
        # the_instruction2 = "ADD##RISCV"

        instruction_group = RV32F_instructions if self.getGlobalState('AppRegisterWidth') == 32 else RV64F_instructions

        for _ in range(instruction_count):
            # select a specific instruction from the instruction group
            the_instruction = self.pickWeighted(instruction_group)

            # create the instruction
            record_id = self.genInstruction(the_instruction)

## Points to the MainSequence defined in this file
MainSequenceClass = MainSequence

## Using GenThreadRISCV by default, can be overriden with extended classes
GenThreadClass = GenThreadRISCV

## Using EnvRISCV by default, can be overriden with extended classes
EnvClass = EnvRISCV

