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
#include "NetManager.h"
#include "Paddle.h"
#include "Ball.h"
#include "Room.h"

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
    NetManager *nm;
    Sound *sound;
    Ogre::MovablePlane* mPlane;
    Ogre::Entity* mPlaneEntity;
    Ogre::SceneNode* mPlaneNode;
    Ball *ball;
    Paddle *paddle;
    Paddle *paddle2;


protected:
    virtual void createScene(void);
    virtual void createCamera();
    virtual void createViewports();
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
    // virtual bool keyReleased( const OIS::KeyEvent &arg );
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    // bool quit(const CEGUI::EventArgs &e);

private:
    bool processUnbufferedInput(const Ogre::FrameEvent& fe);
    // virtual bool quit(const CEGUI::EventArgs &e);
    bool startServer();
    bool startClient(const char* IP);
    void endNetwork();
    void startMulti();
    void searchGame();
    void multiPlayerGame();

    // void startMulti();
    void singlePlayerGame();
};

//---------------------------------------------------------------------------

#endif // #ifndef __GameManager_h_

//---------------------------------------------------------------------------
