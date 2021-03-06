/**
 * @file      memory.cpp
 * @author    Bruno de Carvalho Albertini
 *
 * @author    The ArchC Team
 *            http://www.archc.org/
 *
 *            Computer Systems Laboratory (LSC)
 *            IC-UNICAMP
 *            http://www.lsc.ic.unicamp.br/
 *
 * @version   0.1
 * @date      Sun, 02 Apr 2006 08:07:46 -0200
 *
 * @brief     Implements a ac_tlm bus.
 *
 * @attention Copyright (C) 2002-2005 --- The ArchC Team
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *
 */

//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "bus.h"

//////////////////////////////////////////////////////////////////////////////


/// Constructor
ac_tlm_bus::ac_tlm_bus(sc_module_name module_name):
  sc_module(module_name),
  target_export("iport"),
  MEM_port("MEM_port", 536870912U), // This is the memory port, assigned for 512MB
  GPTIMER_port("GPTIMER_port", 0U),  // Port that connects to the timer unit
  IRQ_port("IRQ_port", 0U),
  UART_port("UART_port", 0U)
{
    /// Binds target_export to the memory
    target_export(*this);

}

/// Destructor
ac_tlm_bus::~ac_tlm_bus()
{
}

/// This is the transport method. Everything should go through this file.
/// To connect more components, you will need to have an if/then/else or a switch
/// statement inside this method. Notice that ac_tlm_req has an address field.
ac_tlm_rsp ac_tlm_bus::transport(const ac_tlm_req &request)
{
  ac_tlm_rsp response;
  /// MEMORY REQUEST
  if(request.addr >= 0x00000000 && request.addr < 0x80000000){
    response = MEM_port->transport(request);
    return response;
  }
  else if(request.addr >= 0xBF000900 && request.addr < 0xBF000952){
    //! Atlas Serial UART unit accessed
//    cerr << "\n Accessing UART Serial : " << hex << request.addr << endl;
    response = UART_port->transport(request);
    return response;
  }
    else {
    cerr<<"Error:trying to access address outside of allowed memory : " << request.addr << endl;
  }
}