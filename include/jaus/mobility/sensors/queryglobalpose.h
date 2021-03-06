////////////////////////////////////////////////////////////////////////////////////
///
///  \file queryglobalpose.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 3 December 2009
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
#ifndef __JAUS_MOBILITY_QUERY_GLOBAL_POSE__H
#define __JAUS_MOBILITY_QUERY_GLOBAL_POSE__H

#include "jaus/core/message.h"
#include "jaus/mobility/mobilitycodes.h"

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class QueryGlobalPose
    ///   \brief This message shall cause the receiving component to reply to the
    ///          requestor with a ID 4402h: ReportGlobalPose message.  A logical AND
    ///          shall be performed on the requested presence vector and that
    ///          representating the available fields from the responder.  The resulting
    ///          message shall contain the fields indicated by the result of this
    ///          lobical AND operation.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_MOBILITY_DLL QueryGlobalPose : public Message
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
            const static UShort Latitude = 0x0001;      ///< Presence of the Lattitude field
            const static UShort Longitude = 0x0002;     ///< Presence of the Longitude field
            const static UShort Altitude = 0x0004;      ///< Presence of the Altitude field
            const static UShort PositionRMS = 0x0008;   ///< Presence of the PositionRMS field
            const static UShort Roll = 0x0010;          ///< Presence of the Roll field
            const static UShort Pitch = 0x0020;         ///< Presence of the Pitch field
            const static UShort Yaw = 0x0040;           ///< Presence of the Yaw field
            const static UShort AttitudeRMS = 0x0080;   ///< Presence of the AttitudeRMS field
            const static UShort TimeStamp = 0x0100;     ///< Presence of the Timestamp field
        };
        QueryGlobalPose(const Address& dest = Address(), const Address& src = Address());
        QueryGlobalPose(const QueryGlobalPose& message);
        ~QueryGlobalPose();
        void SetPresenceVector(const UShort presenceVector) { mPresenceVector = presenceVector; }
        virtual bool IsCommand() const { return false; }
        virtual int WriteMessageBody(Packet& packet) const;
        virtual int ReadMessageBody(const Packet& packet);
        virtual Message* Clone() const { return new QueryGlobalPose(*this); }
        virtual UInt GetPresenceVector() const { return mPresenceVector; }
        virtual UInt GetPresenceVectorSize() const { return USHORT_SIZE; }
        virtual UInt GetPresenceVectorMask() const { return 0x01FF; }
        virtual UShort GetMessageCodeOfResponse() const { return REPORT_GLOBAL_POSE; }
        virtual std::string GetMessageName() const { return "Query Global Pose"; }        
        virtual void ClearMessageBody();
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize = 1437) const { return false; }
        virtual int RunTestCase() const;
        QueryGlobalPose& operator=(const QueryGlobalPose& message);
    protected:
        UShort mPresenceVector;                   ///<  Bit vector for fields present.
    };
}

#endif
/*  End of File */
