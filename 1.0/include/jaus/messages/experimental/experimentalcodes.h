////////////////////////////////////////////////////////////////////////////////////
///
///  \file experimentalcodes.h
///  \brief This file lists all command code definitions for experimental 
///         messeages.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 23 September 2007
///  <br>Last Modified: 26 February 2008
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
#ifndef _JAUS_EXPERIMENTAL_CLASS_CODES_H
#define _JAUS_EXPERIMENTAL_CLASS_CODES_H

#include "jaus/messages/types.h"

namespace Jaus 
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \brief Checks if the message code is for an experimental message.
    ///
    ///   \param code The message code to check.
    ///
    ///   \return True if experimental message, otherwise false.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    inline bool IsExperimentalMessage(const UShort code)
    {
        if(code >= 0xD000)
        {
            return true;
        }
        return false;
    }

    // Query Messages
    const UShort JAUS_QUERY_SICK_LIDAR                                  =   0xD300;
    const UShort JAUS_QUERY_PIXEL_ON_SCREEN                             =   0xD301;


    // Report Messages
    const UShort JAUS_REPORT_SICK_LIDAR                                 =   0xD900;    
    const UShort JAUS_REPORT_PIXEL_ON_SCREEN                            =   0xD901;
}

#endif
/*  End of File */
