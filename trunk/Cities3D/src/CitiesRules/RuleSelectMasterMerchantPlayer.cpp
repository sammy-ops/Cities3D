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
#include "Rule.h"
#include "RuleSetDatabase.h"
#include "IRuleEngine.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- RULES            -----------------------------//

//---------------------------------------------------------------------------//
// Class: RuleSelectMasterMerchantPlayer
// 
// Handles the player selecting who to use the master merchant on.
//
// Derived From:
//     <Rule>
//
// Project:
//     <CitiesRules>
//
// RuleSet:
//     <Cities>
//
class RuleSelectMasterMerchantPlayer : public Rule
{
public:
	virtual void Execute(const DataObject &object)
	{
		wxInt32 index = object.read<wxInt32>();

		gameData<wxInt32>(shMasterMerchantVictim) = index;

		gameData<HashString>(shState) = shTurnMasterMerchantSteal;
		RULE.Execute(shRuleRestartTurnMasterMerchantSteal, DataObject());
	}
};

IMPLEMENT_RULE(RuleSelectMasterMerchantPlayer, CITIES)
