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

#ifndef LUX_PROP_ITEM_H
#define LUX_PROP_ITEM_H

//----------------------------------------------

#include "LuxProp.h"

//----------------------------------------------

class cLuxProp_Item_SaveData : public iLuxProp_SaveData {
    kSerializableClassInit(cLuxProp_Item_SaveData) public : tString msVal;
    tString msExtraVal;
    int mlSpawnContainerID;
    float mfAmount;
    tString msSubItemTypeName;
};

//----------------------------------------------

class cLuxProp_Item : public iLuxProp {
    typedef iLuxProp super_class;
    friend class cLuxPropLoader_Item;

  public:
    cLuxProp_Item(const tString &asName, int alID, cLuxMap *apMap);
    virtual ~cLuxProp_Item();

    //////////////////////
    // General
    bool CanInteract(iPhysicsBody *apBody);
    bool OnInteract(iPhysicsBody *apBody, const cVector3f &avPos);

    void OnSetupAfterLoad(cWorld *apWorld);

    void OnResetProperties();

    void UpdatePropSpecific(float afTimeStep);

    void BeforePropDestruction();

    eLuxFocusCrosshair GetFocusCrosshair(iPhysicsBody *apBody, const cVector3f &avPos);

    //////////////////////
    // Properties
    const tString &GetStringVal() { return msVal; }

    eLuxItemType GetItemType() { return mItemType; }

    const tString &GetImageFile() { return msImageFile; }
    const tString &GetPickSound() { return msPickSound; }
    const tString &GetSubItemTypeName() { return msSubItemTypeName; }

    float GetAmount() { return mfAmount; }

    int GetSpawnContainerID() { return mlSpawnContainerID; }
    void SetSpawnContainerID(int alX) { mlSpawnContainerID = alX; }

    //////////////////////
    // Connection callbacks
    void OnConnectionStateChange(iLuxEntity *apEntity, int alState);

    //////////////////////
    // Save data stuff
    iLuxEntity_SaveData *CreateSaveData();
    void SaveToSaveData(iLuxEntity_SaveData *apSaveData);
    void LoadFromSaveData(iLuxEntity_SaveData *apSaveData);
    void SetupSaveData(iLuxEntity_SaveData *apSaveData);

  private:
    ////////////////
    // Variables
    tString msVal;
    tString msExtraVal;

    int mlSpawnContainerID;

    ////////////////
    // Data
    eLuxItemType mItemType;

    tString msImageFile;
    tString msPickSound;
    tString msSubItemTypeName;

    float mfAmount;
};

//----------------------------------------------

class cLuxPropLoader_Item : public iLuxPropLoader {
  public:
    cLuxPropLoader_Item(const tString &asName);
    virtual ~cLuxPropLoader_Item() {}

    iLuxProp *CreateProp(const tString &asName, int alID, cLuxMap *apMap);
    void LoadVariables(iLuxProp *apProp, cXmlElement *apRootElem);
    void LoadInstanceVariables(iLuxProp *apProp, cResourceVarsObject *apInstanceVars);

  private:
};

//----------------------------------------------

#endif // LUX_PROP_ITEM_H
