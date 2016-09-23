/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/

and edited by Brittany Madrigal for her own project 1 in Game Tech

Description: Makes a ball and a room, and alows the user to watch the ball bounce around the room unbound by gravity.
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"
#include <OgreVector3.h>
#include <OgreNode.h>
#include <ctime>

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
int cubeRoomDimention = 5000;
int sphereRadius = 95;
Ogre::Entity* sphereEntity;
Ogre::SceneNode* ogreNode2;
Ogre::Vector3 dir;
Ogre::Plane wallPlane4(Ogre::Vector3::UNIT_Z, 0); //negative z
Ogre::Plane wallPlane3(Ogre::Vector3::NEGATIVE_UNIT_Z, 0); //positive z
Ogre::Plane floorPlane(Ogre::Vector3::UNIT_Y, 0); // "negative" y
Ogre::Plane ceilingPlane(Ogre::Vector3::NEGATIVE_UNIT_Y, 0);// positive y
Ogre::Plane wallPlane(Ogre::Vector3::NEGATIVE_UNIT_X, 0); //positive x
Ogre::Plane wallPlane2(Ogre::Vector3::UNIT_X, 0); //negative x
int speed;

void TutorialApplication::createScene(void)
{
    Physics* physicsEngine = new Physics();

    srand(time(NULL)); //for random number
    speed = speedOfBall();
    dir = directionVector()*speed;
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.3, 0.3, 0.5));

    //purple light
    Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
    spotLight->setDiffuseColour(1.0, 0, 1.0);
    spotLight->setSpecularColour(1.0, 0, 1.0);
    spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
    spotLight->setDirection(-1, -1, -1);
    spotLight->setPosition(Ogre::Vector3(cubeRoomDimention/2-30, cubeRoomDimention-1, cubeRoomDimention/4));

    //green light
    Ogre::Light* spotLight2 = mSceneMgr->createLight("SpotLight2");
    spotLight2->setDiffuseColour(0, 1.0, .5);
    spotLight2->setSpecularColour(0, 1.0, .5);
    spotLight2->setType(Ogre::Light::LT_SPOTLIGHT);
    spotLight2->setDirection(1, -1, 1);
    spotLight2->setPosition(Ogre::Vector3(0-cubeRoomDimention/2+30, cubeRoomDimention-1, 0 - cubeRoomDimention/4));

    //create sphere
    sphereEntity = mSceneMgr->createEntity("sphere.mesh");
    sphereEntity->setCastShadows(true);
    sphereEntity->setMaterialName("Examples/EnvMappedRustySteel");
    //place initial sphere
    ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, 200, 0));
    ogreNode2->attachObject(sphereEntity);

    ////////////////FLOOR///////////////
    Ogre::MeshManager::getSingleton().createPlane(
      "ground",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      floorPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

    groundEntity->setCastShadows(false);

    groundEntity->setMaterialName("Examples/Rockwall");

    /////////////CEILING////////////////////////

    Ogre::MeshManager::getSingleton().createPlane(
      "ceiling",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      ceilingPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* ceilingEntity = mSceneMgr->createEntity("ceiling");

    Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, cubeRoomDimention, 0));
    ogreNode3->attachObject(ceilingEntity);

    ceilingEntity->setCastShadows(false);

    ceilingEntity->setMaterialName("Examples/CloudySky");

    ////////////WALL 1 ALONG POS X/////////////////////////////

    Ogre::MeshManager::getSingleton().createPlane(
      "wall",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Y);

    Ogre::Entity* wallEntity = mSceneMgr->createEntity("wall");

    Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(cubeRoomDimention/2, cubeRoomDimention/2, 0));
    ogreNode4->attachObject(wallEntity);

    wallEntity->setCastShadows(false);

    wallEntity->setMaterialName("Examples/Rockwall");

    ////////////WALL 2 ALONG NEG X/////////////////////////////

    Ogre::MeshManager::getSingleton().createPlane(
      "wall2",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane2, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Y);

    Ogre::Entity* wallEntity2 = mSceneMgr->createEntity("wall2");

    Ogre::SceneNode* ogreNode5 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(-(cubeRoomDimention/2), cubeRoomDimention/2, 0));
    ogreNode5->attachObject(wallEntity2);

    wallEntity2->setCastShadows(false);

    wallEntity2->setMaterialName("Examples/Rockwall");

    ////////////WALL 3 ALONG POS Z/////////////////////////////

    Ogre::MeshManager::getSingleton().createPlane(
      "wall3",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane3, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Y);

    Ogre::Entity* wallEntity3 = mSceneMgr->createEntity("wall3");

    Ogre::SceneNode* ogreNode6 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, cubeRoomDimention/2, cubeRoomDimention/2));
    ogreNode6->attachObject(wallEntity3);

    wallEntity3->setCastShadows(false);

    wallEntity3->setMaterialName("Examples/Rockwall"); 

    ////////////WALL 4 ALONG NEG Z/////////////////////////////

    Ogre::MeshManager::getSingleton().createPlane(
      "wall4",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane4, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Y);

    Ogre::Entity* wallEntity4 = mSceneMgr->createEntity("wall4");

    Ogre::SceneNode* ogreNode7 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, cubeRoomDimention/2, -(cubeRoomDimention/2)));
    ogreNode7->attachObject(wallEntity4);

    wallEntity4->setCastShadows(false);

    wallEntity4->setMaterialName("Examples/Rockwall"); 

}
//---------------------------------------------------------------------------

void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    //position the camera
    mCamera->setPosition(Ogre::Vector3(0, 300, 500)); //0 300 500
    //sets direction of camera
    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
    //the distance at which the Camera will no longer render any mesh
    mCamera->setNearClipDistance(5);
    //camera controller, can control camera passed to it
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}
 
void TutorialApplication::createViewports()
{
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    //set the background color of the Viewport
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    //not using this now, but getting in the habit
    mCamera->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) /
    Ogre::Real(vp->getActualHeight()));
}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);
  Ogre::Vector3 a = ogreNode2->getPosition();
  Ogre::Vector3 R;

  bool xOutOfRangeNeg = (a.x <= (0-cubeRoomDimention/2 + sphereRadius));
  bool xOutOfRangePos = (a.x >= (cubeRoomDimention/2 - sphereRadius));
  bool yOutOfRangeNeg = (a.y <= (0 + sphereRadius));
  bool yOutOfRangePos = (a.y >= (cubeRoomDimention - sphereRadius));
  bool zOutOfRangeNeg = (a.z <= (0-cubeRoomDimention/2 + sphereRadius));
  bool zOutOfRangePos = (a.z >= (cubeRoomDimention/2 - sphereRadius));

 
  if (ret && (!xOutOfRangePos && !yOutOfRangePos && !zOutOfRangePos && !xOutOfRangeNeg && !yOutOfRangeNeg && !zOutOfRangeNeg))
  {
    ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
  }else{
    if(zOutOfRangeNeg){
      R = dir - 2*(wallPlane4.normal * dir)*wallPlane4.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    } else if(zOutOfRangePos){
      R = dir -2*(wallPlane3.normal * dir)*wallPlane3.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    } else if(yOutOfRangeNeg){
      R = dir -2*(floorPlane.normal * dir)*floorPlane.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    } else if(yOutOfRangePos){
      R = dir -2*(ceilingPlane.normal * dir)*ceilingPlane.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    } else if(xOutOfRangeNeg){
      R = dir -2*(wallPlane2.normal * dir)*wallPlane2.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    } else if(xOutOfRangePos){
      R = dir -2*(wallPlane.normal * dir)*wallPlane.normal;
      R.normalise();
      dir = R*speed;
      ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
    }
  }
  return ret;
}
 
bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  return true;
}

//borrowed idea from http://stackoverflow.com/questions/11758809/what-is-the-optimal-
//algorithm-for-generating-an-unbiased-random-integer-within-a?answertab=votes#tab-top
int TutorialApplication::RandomNum (int min, int max)
{
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);

    return min + x % n;
}

Ogre::Vector3 TutorialApplication::directionVector()
{
  int randX = RandomNum(-1, 1);
  int randY = RandomNum(-1, 1);
  int randZ = RandomNum(-1, 1);

  if(randX && randY && randZ == 0){
    int randY = -1;
    int randZ = 1;
  }

  Ogre::Vector3 v = Ogre::Vector3(randX, randY, randZ);
  v.normalise();
  return v;
}

int TutorialApplication::speedOfBall()
{
  int s = RandomNum(2, 8); 
  return s;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
