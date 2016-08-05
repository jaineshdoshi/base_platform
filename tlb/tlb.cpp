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
 * @brief     Implements a ac_tlm TLB.
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

#include "tlb.h"

//////////////////////////////////////////////////////////////////////////////

// Uncomment this for the debug model
#define TLB_DEBUG


/// Constructor
ac_tlm_tlb::ac_tlm_tlb(sc_module_name module_name):
  sc_module(module_name),
  target_export("iport"),
  BUS_port("BUS_port",0U) // This is the port that connects to the actual bus
{
  /// Binds target_export to the bus
  target_export(*this);

}

/// Destructor
ac_tlm_tlb::~ac_tlm_tlb()
{
}


/// This routine is for the translation of virtual addresses to real memory addresses
ac_tlm_rsp ac_tlm_tlb::transport(const ac_tlm_req &request)
{
  ac_tlm_rsp response;

// Check the address requested
  if(request.addr >= 0x80000000){
    // Virtual memory is being accessed in this request
    ac_tlm_req req = request;
    req.addr = request.addr - 0x80000000;
#ifndef TLB_DEBUG
    cout << "Actual Address to Bus (Memory): "<< std::hex req.addr << endl;
#endif
    response = BUS_port->transport(req);
    return response;
  } else {
    // Actual memory accessed
#ifndef TLB_DEBUG
    cout <<"Address requested"<< std::hex request.addr << endl;
#endif
    response = BUS_port->transport(request);
    return response;
  }
}