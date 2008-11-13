////////////////////////////////////////////////////////////////////////////////////
///
///  \file activateserviceconnection.cpp
///  \brief This file contains data structures for the JAUS_ACTIVATE_SERVICE_CONNECTION
///  message belonging to the CORE set of JAUS messages.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 20 February 2007
///  <br>Last Modified: 11 October 2007
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
#include "jaus/messages/command/core/activateserviceconnection.h"
#include "jaus/messages/command/commandcodes.h"
#include <iostream>

using namespace std;
using namespace Jaus;

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor. Sets the class code.
///
////////////////////////////////////////////////////////////////////////////////////
ActivateServiceConnection::ActivateServiceConnection() : Message(JAUS_ACTIVATE_SERVICE_CONNECTION)
{
    mScCommandCode = 0;
    mInstanceID = 0;
    this->mServiceConnectionFlag = 0;
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor. Sets the class code.
///
////////////////////////////////////////////////////////////////////////////////////
ActivateServiceConnection::ActivateServiceConnection(const ActivateServiceConnection &msg) : Message(JAUS_ACTIVATE_SERVICE_CONNECTION)
{
    *this = msg;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Destructor.
///
////////////////////////////////////////////////////////////////////////////////////
ActivateServiceConnection::~ActivateServiceConnection()
{
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Set the message code for the desired service connection type.
///
///   \param code Message code for service connection.  SC type.
///
///   \return JAUS_OK if the value was set, otherwise JAUS_FAILURE and the 
///   setting of an error code.
///
////////////////////////////////////////////////////////////////////////////////////
int ActivateServiceConnection::SetMessageCode(const UShort code)
{
    mScCommandCode = code;
    return JAUS_OK;
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Set the instance ID of the requester.
///
///   \param id of the Requesters SC.
///
///   \return 1 if the value was set, otherwise 0 and the setting of an
///   error code.
///
////////////////////////////////////////////////////////////////////////////////////
int ActivateServiceConnection::SetInstanceID(const Byte id)
{
    mInstanceID = id;
    return JAUS_OK;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Writes the message body data to the stream.
///
///   \param msg The stream to write to.
///   \param version The desired version of the message to write.
///
///   \return Number of bytes written on success.  A return of 0 is not
///           an error (some messages have no message body), only a 
///           return of -1 and setting of an error code is
///           is a failure state.
///
////////////////////////////////////////////////////////////////////////////////////
int ActivateServiceConnection::WriteMessageBody(Stream& msg, 
                                                const UShort version) const
{
    if(version <= JAUS_VERSION_3_4) 
    {
        if( msg.Write(mScCommandCode) &&
            msg.Write(mInstanceID))
        {
            return JAUS_USHORT_SIZE + JAUS_BYTE_SIZE;
        }
        else
        {
            SetJausError(ErrorCodes::WriteFailure); return -1;
        }
    }
    else 
    {
        SetJausError(ErrorCodes::UnsupportedVersion); return -1;
    }
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Reads the message body data from the stream.
///
///   \param msg The stream to read from.
///   \param version The desired version of the message to read.
///
///   \return Number of bytes read on success.  A return of 0 is not
///           an error (some messages have no message body), only a 
///           return of -1 and setting of an error code is
///           is a failure state.
///
////////////////////////////////////////////////////////////////////////////////////
int ActivateServiceConnection::ReadMessageBody(const Stream& msg, 
                                               const UShort version)
{
    UShort code;
    Byte id;

    if( version <= JAUS_VERSION_3_4 )
    {           
        if( msg.Read(code) &&
            msg.Read(id))
        {
            mScCommandCode = code;
            mInstanceID = id;
            return JAUS_USHORT_SIZE + JAUS_BYTE_SIZE;
        }
        else
        {
            SetJausError(ErrorCodes::ReadFailure); return -1;
        }
    }
    else 
    {
        SetJausError(ErrorCodes::UnsupportedVersion); return -1;
    }
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Clears all data for the message.
///
////////////////////////////////////////////////////////////////////////////////////
void ActivateServiceConnection::ClearMessageBody()
{
    mScCommandCode = 0;
    mInstanceID = 0; 
}

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Assignment operator.
///
////////////////////////////////////////////////////////////////////////////////////
ActivateServiceConnection &ActivateServiceConnection::operator =(const ActivateServiceConnection &msg)
{
    CopyHeaderData(&msg);
    mScCommandCode = msg.mScCommandCode;
    mInstanceID = msg.mInstanceID;
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
UShort ActivateServiceConnection::GetPresenceVectorSize(const UShort version) const { return 0; }
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
UInt ActivateServiceConnection::GetPresenceVectorMask(const UShort version) const { return 0; }
/*  End of File */
