/*
*   Copyright (C) 2017 by Jonathan Naylor G4KLX
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "PassAllTG.h"

#include "DMRDefines.h"

#include <cstdio>
#include <cassert>

CPassAllTG::CPassAllTG(const char* name, unsigned int slot) :
m_name(name),
m_slot(slot)
{
	assert(slot == 1U || slot == 2U);
}

CPassAllTG::~CPassAllTG()
{
}

bool CPassAllTG::processRF(CDMRData& data)
{
	return process(data);
}

bool CPassAllTG::processNet(CDMRData& data)
{
	return process(data);
}

bool CPassAllTG::process(CDMRData& data)
{
	FLCO flco = data.getFLCO();
	unsigned int slotNo = data.getSlotNo();

	return flco == FLCO_GROUP || slotNo == m_slot;
}