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
// Class: LogicCardNameDevCards
// 
// Provides translated names of development cards
//
// Derived From:
//     <Logic>
//
// Project:
//     <StandardRules>
//
// RuleSet:
//     <DevCards>
//
// Mixin To:
//     <LogicCardName>
//
class LogicCardNameVictoryPoint : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		output = DataObject(stVictoryPoint);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicCardNameVictoryPoint, VictoryPoint, 
							LogicCardName, DEVCARDS);


// Road Building.

class LogicCardNameRoadBuilding : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		output = DataObject(stRoadBuilding);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicCardNameRoadBuilding, RoadBuilding, 
							LogicCardName, DEVCARDS);


// YearOfPlenty.

class LogicCardNameYearOfPlenty : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		output = DataObject(stYearOfPlenty);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicCardNameYearOfPlenty, YearOfPlenty, 
							LogicCardName, DEVCARDS);

// Monopoly.

class LogicCardNameMonopoly : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		output = DataObject(stMonopoly);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicCardNameMonopoly, Monopoly, 
							LogicCardName, DEVCARDS);

// Soldier.

class LogicCardNameSoldier : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		output = DataObject(stSoldier);
	}
};

IMPLEMENT_LOGIC_KEYED_MIXIN(LogicCardNameSoldier, Soldier, 
							LogicCardName, DEVCARDS);