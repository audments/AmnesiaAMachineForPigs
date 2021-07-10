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

#ifndef EDIT_MODE_H
#define EDIT_MODE_H

//----------------------------------------------

#include "../common/EdModule.h"

//----------------------------------------------

class iEditor;
class iEdViewport;
class iEdWindow;

//----------------------------------------------

class iEditMode : public iEdModule {
  public:
    iEditMode(iEditor *, const tWString &asName);

    iEdWindow *GetWindow() { return mpWindow; }

    void SetCurrent(bool);

    virtual void OnViewportMouseDown(iEdViewport *, bool, bool, bool) = 0;
    virtual void OnViewportMouseUp(iEdViewport *, bool, bool, bool) = 0;

    virtual void OnDraw(iEdViewport *, cRendererCallbackFunctions *);

  protected:
    virtual void OnInit();

    virtual void OnSetActive(bool) = 0;

    virtual iEdWindow *CreateWindow() = 0;

    iEdWindow *mpWindow;
};

//----------------------------------------------

#endif // EDIT_MODE_H
