/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include <OgreVector3.h>
#include "Physics.h"
#include "Sound.h"
#include "MyMotionState.h"
#include "BulletEntities.h"
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>
#include <string>
#include <iostream>



//---------------------------------------------------------------------------

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);
    Physics* physicsEngine;
    BulletEntities* bulletEntities;
    CEGUI::Window *scoreBox;
    CEGUI::Window *sheet;
    Sound *sound;

    Ogre::MovablePlane* mPlane;
    Ogre::Entity* mPlaneEntity;
    Ogre::SceneNode* mPlaneNode;


protected:
    virtual void createScene(void);
    virtual void createCamera();
    virtual void createViewports();
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
    virtual Ogre::Vector3 directionVector();
    virtual int RandomNum (int min, int max);
    virtual int speedOfBall();
    CEGUI::OgreRenderer* mRenderer;

    

private:
	bool processUnbufferedInput(const Ogre::FrameEvent& fe);
};

//---------------------------------------------------------------------------

#endif // #ifndef __TutorialApplication_h_

//---------------------------------------------------------------------------
