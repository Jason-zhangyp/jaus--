////////////////////////////////////////////////////////////////////////////////////
///
///  \file queryauthority.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 16 November 2009
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
#ifndef __JAUS_CORE_ACCESS_CONTROL_QUERY_AUTHORITY__H
#define __JAUS_CORE_ACCESS_CONTROL_QUERY_AUTHORITY__H

#include "jaus/core/corecodes.h"
#include "jaus/core/message.h"

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class QueryAuthority
    ///   \brief This message is used by clients to query the current value of the
    ///             authority code of this service.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_CORE_DLL QueryAuthority : public Message
    {
    public:
        QueryAuthority(const Address& dest = Address(), const Address& src = Address());
        QueryAuthority(const QueryAuthority& message);
        ~QueryAuthority();
        virtual bool IsCommand() const { return false; }
        virtual int WriteMessageBody(Packet& packet) const;
        virtual int ReadMessageBody(const Packet& packet);
        virtual Message* Clone() const { return new QueryAuthority(*this); }
        virtual UInt GetPresenceVector() const { return 0; }
        virtual UInt GetPresenceVectorSize() const { return 0; }
        virtual UInt GetPresenceVectorMask() const { return 0; }
        virtual UShort GetMessageCodeOfResponse() const { return REPORT_AUTHORITY; }
        virtual std::string GetMessageName() const { return "Query Authority"; }        
        virtual void ClearMessageBody();
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize = 1437) const { return false; }
        virtual int RunTestCase() const;
        QueryAuthority& operator=(const QueryAuthority& message);
    };
}

#endif
/*  End of File */
