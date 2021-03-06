/*******************************************************************************

 File:    TransmitterQ.h
 Project: OpenSonATA
 Authors: The OpenSonATA code is the result of many programmers
          over many years

 Copyright 2011 The SETI Institute

 OpenSonATA is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 OpenSonATA is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with OpenSonATA.  If not, see<http://www.gnu.org/licenses/>.
 
 Implementers of this code are requested to include the caption
 "Licensed through SETI" with a link to setiQuest.org.
 
 For alternate licensing arrangements, please contact
 The SETI Institute at www.seti.org or setiquest.org. 

*******************************************************************************/

//
// Transmitter queue
//
// Packets for output are passed to the transmitter task via this
// queue.
//
// $Heaer: $
//
#ifndef _TransmitterQH
#define _TransmitterQH

#include "Queue.h"

using namespace sonata_lib;

namespace chan {

/**
* Singleton Worker input queue.
*
* Description:\n
*	A singleton queue is used by all Worker tasks to receive
*	input.
*/
class TransmitterQ {
public:
	static Queue *getInstance() {
		static Lock l;
		l.lock();
		if (!instance)
			instance = new Queue("TransmitterQ", DEFAULT_TRANSMITQ_SLOTS);
		l.unlock();
		return (instance);
	}

	~TransmitterQ() {}

private:
	static Queue *instance;
	TransmitterQ() {}

};

}
#endif