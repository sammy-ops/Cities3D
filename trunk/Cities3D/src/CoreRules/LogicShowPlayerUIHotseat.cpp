/*
 *  Cities3D - Copyright (C) 2001-2009 Jason Fugate (saladyears@gmail.com)
 * 
 *  This program is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU General Public License as published by the Free 
 *  Software Foundation; either version 2 of the License, or (at your option) 
 *  any later version.
 * 
 *  This program is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 *  for more details.
 */
#include "stdwx.h"
#include "style.h"	//READ THIS BEFORE MAKING ANY CHANGES TO THIS FILE!!!

//---------------------------- SYSTEM INCLUDES  -----------------------------//

//---------------------------- USER INCLUDES    -----------------------------//
#include "Logic.h"
#include "RuleSetDatabase.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- LOGIC            -----------------------------//

//---------------------------------------------------------------------------//
// Class: LogicShowPlayerUIHotseat
// 
// Mixin logic that determines if the given PlayerUI should be fully
// visible or have its data hidden in a hotseat game.
//
// Derived From:
//     <Logic>
//
// Project:
//     <CoreRules>
//
// RuleSet:
//     <Core>
//
// Mixin To:
//     <LogicShowPlayerUI>
//
class LogicShowPlayerUIHotseat : public Logic
{
public:
	virtual void Decide(const DataObject &input, DataObject &output)
	{
		wxInt32 index = input.read<wxInt32>();

		// Show the player if it's their turn, or the game has ended.
		bool show = false;

		if( (index == gameData<wxInt32>(shCurrentPlayer)) ||
			(shComplete == gameData<HashString>(shState)))
		{
			show = true;
		}

		output = DataObject(show);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicShowPlayerUIHotseat, Hotseat,
							LogicShowPlayerUI, HOTSEAT)
