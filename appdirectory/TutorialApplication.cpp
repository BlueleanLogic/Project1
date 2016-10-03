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
#include "MyMotionState.h"


//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
    :physicsEngine(0),
    bulletEntities(0)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
int cubeRoomDimention = 5000;
int sphereRadius = 100;
Ogre::Entity* sphereEntity;
Ogre::SceneNode* sphereNode;
Ogre::Vector3 dir;
Ogre::Plane wallPlane4(Ogre::Vector3::UNIT_Z, 0); //negative z
Ogre::Plane wallPlane3(Ogre::Vector3::NEGATIVE_UNIT_Z, 0); //positive z
Ogre::Plane floorPlane(Ogre::Vector3::UNIT_Y, 0); // "negative" y
Ogre::Plane ceilingPlane(Ogre::Vector3::NEGATIVE_UNIT_Y, 0);// positive y
Ogre::Plane wallPlane(Ogre::Vector3::NEGATIVE_UNIT_X, 0); //positive x
Ogre::Plane wallPlane2(Ogre::Vector3::UNIT_X, 0); //negative x
int speed;
btRigidBody *sphereBody;
btRigidBody *groundBody;

void TutorialApplication::createScene(void)
{
    // Setting Up Physics
    physicsEngine = new Physics();
    bulletEntities = new BulletEntities();

    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.3, 0.3, 0.5));


    ////////////////FLOOR///////////////

    Ogre::SceneNode *groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();

    Ogre::MeshManager::getSingleton().createPlane(
      "ground",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      floorPlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    groundEntity->setCastShadows(false);
    groundEntity->setMaterialName("Examples/Rockwall");
    groundNode->attachObject(groundEntity);


    // ***Set up bullet Transform necessary for rigidbody.***
    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(btVector3(0, -50, 0));

    // ***Set up CollisionShape necessary for rigidbody.***
    btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);
    btScalar groundMass(0.);
    btVector3 localGroundInertia(0, 0, 0);
    groundShape->calculateLocalInertia(groundMass, localGroundInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *groundMotionState = new MyMotionState(groundTransform, groundNode);

    // ***Create and track the ground's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo groundRBInfo(groundMass, groundMotionState, groundShape, localGroundInertia);
    groundBody = new btRigidBody(groundRBInfo);
    groundBody->setRestitution(1);
    physicsEngine->getDynamicsWorld()->addRigidBody(groundBody);

    ////////////////SPHERE///////////////

    // **Initial Position for Sphere. (Used to sync initial Ogre and Bullet sphere positions.)**
    int ipfsX = 30;
    int ipfsY = 500;
    int ipfsZ = 30;

    // ***Create node for sphere.***
    Ogre::Vector3 ogreSpherePosition = Ogre::Vector3(ipfsX,ipfsY,ipfsZ);
    Ogre::SceneNode *sphereNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(ogreSpherePosition);

    // ***Add sphere entity to its node.***
    sphereEntity = mSceneMgr->createEntity("sphere.mesh");
    sphereEntity->setCastShadows(true);
    // sphereEntity->setMaterialName("Examples/EnvMappedRustySteel");        /* TODO: Reapply a texture to the sphere. */
    sphereNode->attachObject(sphereEntity);

    // ***Set up bullet Transform necessary for rigidbody.***
    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0));
    btVector3 btSpherePosition = btVector3(ipfsX,ipfsY,ipfsZ);
    startTransform.setOrigin(btSpherePosition);

    // ***Set up bullet Collider necessary for rigidbody.***
    btSphereShape* btSphereCollider = bulletEntities->makePingPongBall(sphereRadius); //change this value!
    btScalar mass(0.1f);                 /* "0" -> an immovable object */
    btVector3 localInertia(0,0,0); 
    btSphereCollider->calculateLocalInertia(mass, localInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *myMotionState = new MyMotionState(startTransform, sphereNode);

    // ***Create and track the sphere's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, btSphereCollider, localInertia);
    sphereBody = new btRigidBody(rbInfo);
    sphereBody->setRestitution(2);
    sphereBody->setUserPointer(sphereNode);
    physicsEngine->getDynamicsWorld()->addRigidBody(sphereBody);

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

    ////////////////////////////////////////////////
    // ***Used for manually setting velocity in Project 1.***
    // srand(time(NULL)); //for random number
    // speed = speedOfBall();
    // dir = directionVector()*speed;
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
  // Ogre::Vector3 a = sphereNode->getPosition();

  // Ogre::Vector3 R;

 
  // bool xOutOfRangeNeg = (a.x <= (0-cubeRoomDimention/2 + sphereRadius));
  // physicsEngine->getDynamicsWorld()->stepSimulation(1.0f/60.0f);
  // bool xOutOfRangePos = (a.x >= (cubeRoomDimention/2 - sphereRadius));
  // bool yOutOfRangeNeg = (a.y <= (0 + sphereRadius));
  // bool yOutOfRangePos = (a.y >= (cubeRoomDimention - sphereRadius));
  // bool zOutOfRangeNeg = (a.z <= (0-cubeRoomDimention/2 + sphereRadius));
  // bool zOutOfRangePos = (a.z >= (cubeRoomDimention/2 - sphereRadius));
 
 
 
  // if (ret && (!xOutOfRangePos && !yOutOfRangePos && !zOutOfRangePos && !xOutOfRangeNeg && !yOutOfRangeNeg && !zOutOfRangeNeg))
  // {
  //   sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  // }else{
  //   if(zOutOfRangeNeg){
  //     R = dir - 2*(wallPlane4.normal * dir)*wallPlane4.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   } else if(zOutOfRangePos){
  //     R = dir -2*(wallPlane3.normal * dir)*wallPlane3.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   } else if(yOutOfRangeNeg){
  //     R = dir -2*(floorPlane.normal * dir)*floorPlane.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   } else if(yOutOfRangePos){
  //     R = dir -2*(ceilingPlane.normal * dir)*ceilingPlane.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   } else if(xOutOfRangeNeg){
  //     R = dir -2*(wallPlane2.normal * dir)*wallPlane2.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   } else if(xOutOfRangePos){
  //     R = dir -2*(wallPlane.normal * dir)*wallPlane.normal;
  //     R.normalise();
  //     dir = R*speed;
  //     sphereNode->translate(dir, Ogre::Node::TS_LOCAL);
  //   }
  // }
  printf("4\n");


  physicsEngine->stepSimulation();

  btTransform trans;
  sphereBody->getMotionState()->getWorldTransform(trans);
  printf("\nposition of Y: ");
  printf("%f", (float)(trans.getOrigin().getY()));

  printf("7\n");

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
  int s = RandomNum(2, 3); 
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
