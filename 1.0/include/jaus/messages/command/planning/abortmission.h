////////////////////////////////////////////////////////////////////////////////////
///
///  \file abortmission.h
///  \brief This file contains data structure for the JAUS_ABORT_MISSION message.
///
///  <br>Author(s): Cathy Yen
///  <br>Created: 13 April 2009
///  <br>Last Modified: 13 April 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
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
#ifndef __JAUS_ABORT_MISSION_H
#define __JAUS_ABORT_MISSION_H

#include "jaus/messages/message.h"

namespace Jaus
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class AbortMission
    ///   \brief Implements Abort Mission (0E02h), one of the Command set of messages 
    ///   under the Planning Subgroup in JAUS.   
    ///
    ///   Receipt of the Abort Mission message tells the component to abort, or delete,
    ///   the mission with Mission ID.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_MSG_DLL AbortMission : public Message
    {
    public:
        AbortMission();
        AbortMission(const AbortMission &msg);
        ~AbortMission();
        void SetMissionID(const UShort missionID);
        inline UShort GetMissionID() const { return mMissionID; } ///<   Gets the mission id.
        void SetTaskID(const UShort taskID);
        inline UShort GetTaskID() const { return mTaskID; } ///<   Gets the mission id.
        virtual int WriteMessageBody(Stream &msg, const UShort version) const;
        virtual int ReadMessageBody(const Stream &msg, const UShort version);
        virtual void ClearMessageBody();
        virtual void Print() const;
        virtual UShort GetPresenceVectorSize(const UShort version = JAUS_DEFAULT_VERSION) const;
        virtual UInt GetPresenceVectorMask(const UShort version = JAUS_DEFAULT_VERSION) const;
        virtual Message* Clone() const;
        AbortMission& operator=(const AbortMission &msg);
        virtual int RunTestCase() const;
    protected:
        UShort mMissionID;    ///< mission id of the mission to abort.
        UShort mTaskID;       ///< task id of the task to abort.
    };
}

#endif

