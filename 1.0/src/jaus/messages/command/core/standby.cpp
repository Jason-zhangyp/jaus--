////////////////////////////////////////////////////////////////////////////////////
///
///  \file standby.cpp
///  \brief This file contains data structures for the JAUS_STANDBY
///  message belonging to the CORE set of JAUS messages.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 20 February 2007
///  <br>Last Modified: 17 July 2007
///  <br>Copyright (c) 2007
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
/// 
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#include "jaus/messages/command/core/standby.h"
#include "jaus/messages/command/commandcodes.h"
#include <iostream>

using namespace std;
using namespace Jaus;

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor. Sets the class code.
///
////////////////////////////////////////////////////////////////////////////////////
Standby::Standby() : Message(JAUS_STANDBY)
{
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor. Sets the class code.
///
////////////////////////////////////////////////////////////////////////////////////
Standby::Standby(const Standby &msg) : Message(JAUS_STANDBY)
{
    *this = msg;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Destructor.
///
////////////////////////////////////////////////////////////////////////////////////
Standby::~Standby()
{
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Assignment operator.
///
////////////////////////////////////////////////////////////////////////////////////
Standby &Standby::operator=(const Standby &msg)
{
    CopyHeaderData(&msg);
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Gets the size in bytes of the presence vector used by
///          the message.
///
///   \param version Version of JAUS to use for acquiring presence vector
///                  size.  Defaults is current version of library.
///
///   \return Size in bytes of presence vector associated with message.
///
////////////////////////////////////////////////////////////////////////////////////
UShort Standby::GetPresenceVectorSize(const UShort version) const { return 0; }
////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Gets the bit mask associated with the message indicating the
///          bits used in the presence vector of this message (if it has one).
///
///   \param version Version of JAUS to use for acquiring presence vector
///                  mask.  Defaults is current version of library.
///
///   \return Presence vector mask associated with message.  This value
///           is used to determine what bits are used in the presence vector.
///
////////////////////////////////////////////////////////////////////////////////////
UInt Standby::GetPresenceVectorMask(const UShort version) const { return 0; }

/*  End of File */
