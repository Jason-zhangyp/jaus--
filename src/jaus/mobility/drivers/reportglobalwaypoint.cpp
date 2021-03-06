////////////////////////////////////////////////////////////////////////////////////
///
///  \file reportglobalwaypoint.cpp
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 25 November 2009
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
#include "jaus/mobility/drivers/reportglobalwaypoint.h"
#include "jaus/mobility/drivers/globalwaypoint.h"
#include "jaus/core/scaledinteger.h"

using namespace JAUS;


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor, initializes default values.
///
///   \param[in] src Source ID of message sender.
///   \param[in] dest Destination ID of message.
///
////////////////////////////////////////////////////////////////////////////////////
ReportGlobalWaypoint::ReportGlobalWaypoint(const Address& dest, const Address& src) : Message(REPORT_GLOBAL_WAYPOINT, dest, src)
{
    mPresenceVector = 0;
    mLatitude = 0;
    mLongitude = 0;
    mAltitude = 0;
    mRoll = 0;
    mPitch = 0;
    mYaw = 0;
    mWaypointTolerance = 0;
    mPathTolerance = 0;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Copy constructor.
///
////////////////////////////////////////////////////////////////////////////////////
ReportGlobalWaypoint::ReportGlobalWaypoint(const ReportGlobalWaypoint& message) : Message(REPORT_GLOBAL_WAYPOINT)
{
    *this = message;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Destructor.
///
////////////////////////////////////////////////////////////////////////////////////
ReportGlobalWaypoint::~ReportGlobalWaypoint()
{
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Writes message payload to the packet.
///
///   Message contents are written to the packet following the JAUS standard.
///
///   \param[out] packet Packet to write payload to.
///
///   \return -1 on error, otherwise number of bytes written.
///
////////////////////////////////////////////////////////////////////////////////////
int ReportGlobalWaypoint::WriteMessageBody(Packet& packet) const
{
    int expected = BYTE_SIZE;
    int written = 0;

    written += packet.Write(mPresenceVector);

    expected += UINT_SIZE;
    written += ScaledInteger::Write(packet, mLatitude, Limits::MaxLatitude, Limits::MinLatitude, ScaledInteger::UInt);

    expected += UINT_SIZE;
    written += ScaledInteger::Write(packet, mLongitude, Limits::MaxLongitude, Limits::MinLongitude, ScaledInteger::UInt);

    if((mPresenceVector & PresenceVector::Altitude) > 0)
    {
        expected += UINT_SIZE;
        written += ScaledInteger::Write(packet, mAltitude, Limits::MaxElevation, Limits::MinElevation, ScaledInteger::UInt);
    }
    if((mPresenceVector & PresenceVector::Roll) > 0)
    {
        expected += USHORT_SIZE;
        written += ScaledInteger::Write(packet, mRoll, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::Pitch) > 0)
    {
        expected += USHORT_SIZE;
        written += ScaledInteger::Write(packet, mPitch, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::Yaw) > 0)
    {
        expected += USHORT_SIZE;
        written += ScaledInteger::Write(packet, mYaw, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::WaypointTolerance) > 0)
    {
        expected += USHORT_SIZE;
        written += ScaledInteger::Write(packet, mWaypointTolerance, Limits::MaxWaypointTolerance, Limits::MinWaypointTolerance, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::PathTolerance) > 0)
    {
        expected += UINT_SIZE;
        written += ScaledInteger::Write(packet, mPathTolerance, Limits::MaxPathTolerance, Limits::MinPathTolerance, ScaledInteger::UInt);
    }

    return expected == written ? written : -1;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Reads message payload from the packet.
///
///   Message contents are read from the packet following the JAUS standard.
///
///   \param[in] packet Packet containing message payload data to read.
///
///   \return -1 on error, otherwise number of bytes written.
///
////////////////////////////////////////////////////////////////////////////////////
int ReportGlobalWaypoint::ReadMessageBody(const Packet& packet)
{
    int expected = BYTE_SIZE;
    int read = 0;

    read += packet.Read(mPresenceVector);

    expected += UINT_SIZE;
    read += ScaledInteger::Read(packet, mLatitude, Limits::MaxLatitude, Limits::MinLatitude, ScaledInteger::UInt);

    expected += UINT_SIZE;
    read += ScaledInteger::Read(packet, mLongitude, Limits::MaxLongitude, Limits::MinLongitude, ScaledInteger::UInt);

    if((mPresenceVector & PresenceVector::Altitude) > 0)
    {
        expected += UINT_SIZE;
        read += ScaledInteger::Read(packet, mAltitude, Limits::MaxElevation, Limits::MinElevation, ScaledInteger::UInt);
    }
    if((mPresenceVector & PresenceVector::Roll) > 0)
    {
        expected += USHORT_SIZE;
        read += ScaledInteger::Read(packet, mRoll, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::Pitch) > 0)
    {
        expected += USHORT_SIZE;
        read += ScaledInteger::Read(packet, mPitch, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::Yaw) > 0)
    {
        expected += USHORT_SIZE;
        read += ScaledInteger::Read(packet, mYaw, Limits::MaxAngle, Limits::MinAngle, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::WaypointTolerance) > 0)
    {
        expected += USHORT_SIZE;
        read += ScaledInteger::Read(packet, mWaypointTolerance, Limits::MaxWaypointTolerance, Limits::MinWaypointTolerance, ScaledInteger::UShort);
    }
    if((mPresenceVector & PresenceVector::PathTolerance) > 0)
    {
        expected += UINT_SIZE;
        read += ScaledInteger::Read(packet, mPathTolerance, Limits::MaxPathTolerance, Limits::MinPathTolerance, ScaledInteger::UInt);
    }

    return expected == read ? read : -1;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Clears message payload data.
///
////////////////////////////////////////////////////////////////////////////////////
void ReportGlobalWaypoint::ClearMessageBody()
{
    mPresenceVector = 0;
    mLatitude = 0;
    mLongitude = 0;
    mAltitude = 0;
    mRoll = 0;
    mPitch = 0;
    mYaw = 0;
    mWaypointTolerance = 0;
    mPathTolerance = 0;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Runs a test case to validate the message class.
///
///   \return 1 on success, otherwise 0.
///
////////////////////////////////////////////////////////////////////////////////////
int ReportGlobalWaypoint::RunTestCase() const
{
    int result = 0;

    Packet packet;

    ReportGlobalWaypoint msg1, msg2;

    msg1.SetRoll(-1.25);
    msg1.SetPathTolerance(50000);

    if((msg1.WriteMessageBody(packet) != -1) &&
        (msg2.ReadMessageBody(packet) != -1))
    {
        if(msg2.AreFieldsPresent(PresenceVector::Roll | PresenceVector::PathTolerance) )
         {
                result = 1;
         }
    }

    return result;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Sets equal to.
///
////////////////////////////////////////////////////////////////////////////////////
ReportGlobalWaypoint& ReportGlobalWaypoint::operator=(const ReportGlobalWaypoint& message)
{
    if(this != &message)
    {
        CopyHeaderData(&message);
        mPresenceVector = message.mPresenceVector;
        mLatitude = message.mLatitude;
        mLongitude = message.mLongitude;
        mAltitude = message.mAltitude;
        mRoll = message.mRoll;
        mPitch = message.mPitch;
        mYaw = message.mYaw;
        mWaypointTolerance = message.mWaypointTolerance;
        mPathTolerance = message.mPathTolerance;
        
    }
    return *this;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Sets equal to.
///
////////////////////////////////////////////////////////////////////////////////////
ReportGlobalWaypoint& ReportGlobalWaypoint::operator=(const GlobalWaypoint& waypoint)
{
    mPresenceVector = (Byte)waypoint.GetPresenceVector();
    mLatitude = waypoint.GetLatitude();
    mLongitude = waypoint.GetLongitude();
    mAltitude = waypoint.GetAltitude();
    mRoll = waypoint.GetRoll();
    mPitch = waypoint.GetPitch();
    mYaw = waypoint.GetYaw();
    mWaypointTolerance = waypoint.GetWaypointTolerance();
    mPathTolerance = waypoint.GetPathTolerance();
    return *this;
}


/*  End of File */
