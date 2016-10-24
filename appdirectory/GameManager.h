/*
-----------------------------------------------------------------------------
Filename:    GameManager.h
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

#ifndef __GameManager_h_
#define __GameManager_h_

#include "BaseApplication.h"
#include <OgreVector3.h>
#include "Physics.h"
#include "GUI.h"
#include "Sound.h"
#include "MyMotionState.h"

#include <string>
#include <iostream>



//---------------------------------------------------------------------------

class GameManager : public BaseApplication
{
public:
    GameManager(void);
    virtual ~GameManager(void);
    Physics* physicsEngine;
    GUI *gui;
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
    // virtual bool keyReleased( const OIS::KeyEvent &arg );
    // virtual bool keyPressed( const OIS::KeyEvent &arg );
    // virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );


    // bool quit(const CEGUI::EventArgs &e);
    void makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
                   const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant);

    

private:
    enum GameState {PLAY,PAUSE,MENU,OVER};
    GameState mMode;
    bool processUnbufferedInput(const Ogre::FrameEvent& fe);
    // virtual bool quit(const CEGUI::EventArgs &e);
};

//---------------------------------------------------------------------------

#endif // #ifndef __GameManager_h_

//---------------------------------------------------------------------------
