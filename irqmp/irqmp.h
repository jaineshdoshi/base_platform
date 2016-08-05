/**
 * \file     irqmp.h
 * \author   Jainesh Doshi
 *
 *           The ArchC Team
 *           http://www.archc.org/
 *
 *           Computer Systems Laboratory (LSC)
 *           IC-UNICAMP
 *           http://www.lsc.ic.unicamp.br/
 *
 *
 * \brief     Implements the Grlib IRQMP Multiprocessor Interrupt Controller
 *
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
**/

#ifndef irqmp_H
#define irqmp_H

#include <systemc.h>
#include <stdio.h>
#include <assert.h>
#include "ac_tlm_protocol.H"
#include "ac_tlm_port.H"

#define IRQMP_LEVEL_OFFSET      0x0
#define IRQMP_PENDING_OFFSET    0x4
#define IRQMP_FORCE0_OFFSET     0x8
#define IRQMP_CLEAR_OFFSET      0xC
#define IRQMP_MPSTATUS_OFFSET   0x10
#define IRQMP_BROADCAST_OFFSET  0x14
#define IRQMP_MASK_OFFSET       0x40
#define IRQMP_FORCE_OFFSET      0x80
#define IRQMP_EXTENDED_OFFSET   0xC0


