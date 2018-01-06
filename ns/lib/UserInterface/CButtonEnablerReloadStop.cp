/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- * * The contents of this file are subject to the Netscape Public License * Version 1.0 (the "NPL"); you may not use this file except in * compliance with the NPL.  You may obtain a copy of the NPL at * http://www.mozilla.org/NPL/ * * Software distributed under the NPL is distributed on an "AS IS" basis, * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL * for the specific language governing rights and limitations under the * NPL. * * The Initial Developer of this code under the NPL is Netscape * Communications Corporation.  Portions created by Netscape are * Copyright (C) 1998 Netscape Communications Corporation.  All Rights * Reserved. */#ifdef PowerPlant_PCH#include PowerPlant_PCH#endif#include "CButtonEnablerReloadStop.h"CButtonEnablerReloadStop::CButtonEnablerReloadStop(LStream* inStream)	: CPaneEnabler(inStream){	// ta da!}void CButtonEnablerReloadStop::ExecuteSelf(MessageT inMessage, void *ioParam){	LControl*	theControl		= dynamic_cast<LControl*>(mPane);	LCommander* theTarget		= LCommander::GetTarget();	Boolean 	enabled			= false;	Boolean		usesMark		= false;	MessageT	command;	Str255		outName;	Char16		outMark;	if (!theControl || !theTarget)		return;			command = theControl->GetValueMessage();		theTarget->ProcessCommandStatus(command, enabled, usesMark, outMark, outName);		if (enabled)	{		mPane->Enable();		mPane->Show();	}	else	{		mPane->Hide();		mPane->Disable();	}}