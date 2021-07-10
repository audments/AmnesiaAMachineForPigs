/*
 * Copyright © 2011-2020 Frictional Games
 *
 * This file is part of Amnesia: A Machine For Pigs.
 *
 * Amnesia: A Machine For Pigs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Amnesia: A Machine For Pigs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Amnesia: A Machine For Pigs.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LUX_AREA_FLASHBACK_H
#define LUX_AREA_FLASHBACK_H

//----------------------------------------------

#include "LuxArea.h"

//----------------------------------------------

class cLuxArea_Flashback_SaveData : public iLuxArea_SaveData {
    kSerializableClassInit(cLuxArea_Flashback_SaveData) public : iLuxArea *CreateArea(cLuxMap *apMap);

    tString msFlashbackFile;
    tString msCallback;
};

//----------------------------------------------

class cLuxArea_Flashback : public iLuxArea {
    typedef iLuxArea super_class;
    friend class cLuxAreaLoader_Flashback;

  public:
    cLuxArea_Flashback(const tString &asName, int alID, cLuxMap *apMap);
    virtual ~cLuxArea_Flashback();

    //////////////////////
    // General
    void OnUpdate(float afTimeStep);

    //////////////////////
    // Connection callbacks
    void OnConnectionStateChange(iLuxEntity *apEntity, int alState) {}

    //////////////////////
    // Save data stuff
    iLuxEntity_SaveData *CreateSaveData();
    virtual void SaveToSaveData(iLuxEntity_SaveData *apSaveData);
    virtual void LoadFromSaveData(iLuxEntity_SaveData *apSaveData);
    virtual void SetupSaveData(iLuxEntity_SaveData *apSaveData);

  protected:
  private:
    /////////////////////////
    // Data
    tString msFlashbackFile;
    tString msCallback;

    /////////////////////////
    // Variables
    float mfCheckCollisionCount;
};

//----------------------------------------------

class cLuxAreaLoader_Flashback : public iLuxAreaLoader {
  public:
    cLuxAreaLoader_Flashback(const tString &asName);
    ~cLuxAreaLoader_Flashback();

    iLuxArea *CreateArea(const tString &asName, int alID, cLuxMap *apMap);

    void LoadVariables(iLuxArea *apArea, cWorld *apWorld);
    void SetupArea(iLuxArea *apArea, cWorld *apWorld);
};

//----------------------------------------------

#endif // LUX_AREA_Flashback_H
