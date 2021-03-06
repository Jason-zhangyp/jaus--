////////////////////////////////////////////////////////////////////////////////////
///
///  \file reportaccelerationlimit.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 2 December 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: bsun@ist.ucf.edu
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
#ifndef __JAUS_MOBILITY_QUERY_ACCELERATION_LIMIT__H
#define __JAUS_MOBILITY_QUERY_ACCELERATION_LIMIT__H

#include "jaus/core/message.h"
#include "jaus/mobility/mobilitycodes.h"

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class QueryAccelerationLimit
    ///   \brief This message is shall cause the receiving component to reply to the
    ///          requestor with a ID 4416h: ReportAccelerationLimit message.
    ///          Field #2 specifies the fields to be returned in the
    ///          ReportAccelerationLimit message.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_MOBILITY_DLL QueryAccelerationLimit : public Message
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class PresenceVector
        ///   \brief This class contains bit masks for bitwise operations on the
        ///          presence vector for this message.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_MOBILITY_DLL PresenceVector : public JAUS::PresenceVector
        {
        public:
            const static Byte AccelerationX = 0x01;
            const static Byte AccelerationY = 0x02;
            const static Byte AccelerationZ = 0x04;
            const static Byte RollAcceleration = 0x08;
            const static Byte PitchAcceleration = 0x10;
            const static Byte YawAcceleration = 0x20;
        };
        // Command types when issuing commands.
        enum Command
        {
            SetMaximumAllowedValues = 0,
            SetMinimumAllowedValues
        };
        QueryAccelerationLimit(const Address& dest = Address(), const Address& src = Address());
        QueryAccelerationLimit(const QueryAccelerationLimit& message);
        ~QueryAccelerationLimit();
        void SetPresenceVector(const Byte presenceVector) { mPresenceVector = presenceVector; }
        inline Byte SetCommandType(const Byte type)  { return mCommandType = type; } 
        inline Byte GetCommandType() const { return mCommandType; }   
        virtual bool IsCommand() const { return false; }
        virtual int WriteMessageBody(Packet& packet) const;
        virtual int ReadMessageBody(const Packet& packet);
        virtual Message* Clone() const { return new QueryAccelerationLimit(*this); }
        virtual UInt GetPresenceVector() const { return mPresenceVector; }
        virtual UInt GetPresenceVectorSize() const { return BYTE_SIZE; }
        virtual UInt GetPresenceVectorMask() const { return 0x3F; }
        virtual UShort GetMessageCodeOfResponse() const { return REPORT_ACCELERATION_LIMIT; }
        virtual std::string GetMessageName() const { return "Query Acceleration Limit"; }
        virtual void ClearMessageBody();
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize = 1437) const { return false; }
        virtual int RunTestCase() const;
        QueryAccelerationLimit& operator=(const QueryAccelerationLimit& message);
    protected:
        Byte mPresenceVector;                   ///<  Bit vector for fields present.
        Byte mCommandType;                   ///<  CommandType
    };
}

#endif
/*  End of File */
