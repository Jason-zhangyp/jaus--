////////////////////////////////////////////////////////////////////////////////////
///
///  \file informmessages.h
///  \brief Main include file for all inform messages.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 27 January 2007
///  <br>Last Modified: 10 June 2008
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
#ifndef __JAUS_INFORM_MESSAGES_INCLUDE__H
#define __JAUS_INFORM_MESSAGES_INCLUDE__H

#include "jaus/messages/inform/acknackmessage.h"

#include "jaus/messages/inform/core/reportcomponentauthority.h"
#include "jaus/messages/inform/core/reportcomponentcontrol.h"
#include "jaus/messages/inform/core/reportcomponentstatus.h"
#include "jaus/messages/inform/core/reporttime.h"

#include "jaus/messages/inform/communications/reportheartbeatpulse.h"
#include "jaus/messages/inform/communications/reportdatalinkstatus.h"
#include "jaus/messages/inform/communications/reportselecteddatalinkstatus.h"

#include "jaus/messages/inform/configuration/reportconfiguration.h"
#include "jaus/messages/inform/configuration/reportservices.h"
#include "jaus/messages/inform/configuration/reportidentification.h"
#include "jaus/messages/inform/configuration/reportsubsystemlist.h"

#include "jaus/messages/inform/events/eventmessage.h"
#include "jaus/messages/inform/events/reportevents.h"

#include "jaus/messages/inform/platform/reportglobalpose.h"
#include "jaus/messages/inform/platform/reportlocalpose.h"
#include "jaus/messages/inform/platform/reportglobalvector.h"
#include "jaus/messages/inform/platform/reportwrencheffort.h"
#include "jaus/messages/inform/platform/reportplatformspecifications.h"
#include "jaus/messages/inform/platform/reportvelocitystate.h"
#include "jaus/messages/inform/platform/reporttravelspeed.h"
#include "jaus/messages/inform/platform/reportplatformoperationaldata.h"
#include "jaus/messages/inform/platform/reportdiscretedevices.h"
#include "jaus/messages/inform/platform/reportlocalvector.h"
#include "jaus/messages/inform/platform/reportwaypointcount.h"
#include "jaus/messages/inform/platform/reportglobalwaypoint.h"
#include "jaus/messages/inform/platform/reportlocalwaypoint.h"
#include "jaus/messages/inform/platform/reportpathsegmentcount.h"
#include "jaus/messages/inform/platform/reportglobalpathsegment.h"
#include "jaus/messages/inform/platform/reportlocalpathsegment.h"
#include "jaus/messages/inform/platform/reportdevicepowerstatus.h"

#include "jaus/messages/inform/environment/reportimage.h"
#include "jaus/messages/inform/environment/reportcameraformatoptions.h"
#include "jaus/messages/inform/environment/reportcamerapose.h"                //Added 8/15/2008
#include "jaus/messages/inform/environment/reportcameracount.h"                //Added 8/15/2008
#include "jaus/messages/inform/environment/reportselectedcamera.h"            //Added 8/15/2008
#include "jaus/messages/inform/environment/reportrelativeobjectposition.h"    //Added 8/20/2008
#include "jaus/messages/inform/environment/reportcameracapabilities.h"        //Added 8/20/2008
#include "jaus/messages/inform/environment/reportwaterdepth.h"                //Added 4/03/2009

#endif
/*  End of File */
