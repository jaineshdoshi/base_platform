/******************************************************
 * ArchC Resources implementation file.               *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

#include  "mips_arch.H"
#include  "mips_arch_ref.H"

//!/Default constructor.
mips_arch_ref::mips_arch_ref(mips_arch& arch) : ac_arch_ref<mips_parms::ac_word, mips_parms::ac_Hword>(arch),
                                                ac_pc(arch.ac_pc),
                                                DM(arch.DM_mport), RB(arch.RB),
                                                RBF(arch.RBF), C0_RB(arch.C0_RB),
                                                npc(arch.npc), hi(arch.hi), lo(arch.lo),
                                                id(arch.id), cc(arch.cc),
                                                intr_reg(arch.intr_reg),
                                                ack_intp(arch.ack_intp){}

