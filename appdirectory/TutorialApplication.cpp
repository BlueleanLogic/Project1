/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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

#include "TutorialApplication.h"
//#include <random>
#include <OgreVector3.h>
#include <OgreNode.h>

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
Ogre::Entity* sphereEntity;
Ogre::SceneNode* ogreNode2;
Ogre::Vector3 dir;



void TutorialApplication::createScene(void)
{
    dir = directionVector();
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.8, 0.8, 0.8));
    //create sphere
    sphereEntity = mSceneMgr->createEntity("uv_sphere.mesh");
    
    //place initial sphere
    ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, 200, 0));
    ogreNode2->attachObject(sphereEntity);
    //put sphere in scene
    //mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(sphereEntity);
    sphereEntity->setCastShadows(true);
    sphereEntity->setMaterialName("Examples/SphereMappedRustySteel");


    ////////////////FLOOR///////////////
    //a blueprint for a plane that is perpendicular to the y-axis and zero units from the origin
    Ogre::Plane floorPlane(Ogre::Vector3::UNIT_Y, 0);

    //creating actual plane on blueprint
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

    groundEntity->setMaterialName("Examples/BeachStones");

    /////////////CEILING////////////////////////
    Ogre::Plane ceilingPlane(Ogre::Vector3::NEGATIVE_UNIT_Y, 0);

    Ogre::MeshManager::getSingleton().createPlane(
      "ceiling",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      ceilingPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* ceilingEntity = mSceneMgr->createEntity("ceiling");
    //mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ceilingEntity);

    Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(0, cubeRoomDimention, 0));
    ogreNode3->attachObject(ceilingEntity);

    ceilingEntity->setCastShadows(false);

    ceilingEntity->setMaterialName("Examples/CloudySky");

    ////////////WALL 1 ALONG X/////////////////////////////
    Ogre::Plane wallPlane(Ogre::Vector3::NEGATIVE_UNIT_X, 0);

    Ogre::MeshManager::getSingleton().createPlane(
      "wall",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* wallEntity = mSceneMgr->createEntity("wall");

    Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(cubeRoomDimention/2, cubeRoomDimention/2, 0));
    ogreNode4->attachObject(wallEntity);

    wallEntity->setCastShadows(false);

    wallEntity->setMaterialName("Examples/BeachStones");

    ////////////WALL 2 ALONG X/////////////////////////////
    Ogre::Plane wallPlane2(Ogre::Vector3::UNIT_X, 0);

    Ogre::MeshManager::getSingleton().createPlane(
      "wall2",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      wallPlane2, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* wallEntity2 = mSceneMgr->createEntity("wall2");

    Ogre::SceneNode* ogreNode5 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    Ogre::Vector3(-(cubeRoomDimention/2), cubeRoomDimention/2, 0));
    ogreNode5->attachObject(wallEntity2);

    wallEntity2->setCastShadows(false);

    wallEntity2->setMaterialName("Examples/BeachStones");

    ////////////WALL 3 ALONG POS Z/////////////////////////////
    Ogre::Plane wallPlane3(Ogre::Vector3::NEGATIVE_UNIT_Z, 0);

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

    wallEntity3->setMaterialName("Examples/BeachStones"); 

    ////////////WALL 4 ALONG NEG Z/////////////////////////////
    Ogre::Plane wallPlane4(Ogre::Vector3::UNIT_Z, 0);

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

    wallEntity4->setMaterialName("Examples/BeachStones"); 

}
//---------------------------------------------------------------------------

void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    //position the camera
    mCamera->setPosition(Ogre::Vector3(0, 300, 500));
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
  Ogre::Vector3 a = ogreNode2->getPosition;

 
  if (ret)
  {
    //ogreNode7 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    //Ogre::Vector3(0, 200, 0)+directionVector());
    //ogreNode7->attachObject(sphereEntity);
    ogreNode2->translate(dir, Ogre::Node::TS_LOCAL);
  
  }
  return ret;
}
 
bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  return true;
}

//borrowed from http://stackoverflow.com/questions/11758809/what-is-the-optimal-algorithm-for-generating-an-unbiased-random-integer-within-a?answertab=votes#tab-top
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
  double randX = RandomNum(-1, 1);
  double randY = RandomNum(-1, 1);
  double randZ = RandomNum(-1, 1);
  Ogre::Vector3 v = Ogre::Vector3(randX, randY, randZ);
  v.normalise();

  return v;
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
