/*
-----------------------------------------------------------------------------
Filename:    GameManager.cpp
-----------------------------------------------------------------------------

This source file is part of the
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/

and edited by Brittany Madrigal for her own project 1 in Game Tech

Description: Makes a ball and a room, and alows the user to watch the ball bounce around the room unbound by gravity.
-----------------------------------------------------------------------------
*/
#include "BaseApplication.h"

#include "GameManager.h"
#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include <OgreNode.h>
#include <ctime>
#include "MyMotionState.h"
#include <OgreRectangle2D.h>
#include "scoreBoard.h"
#include <string>
#include <iostream>
#include <sstream>


//---------------------------------------------------------------------------
GameManager::GameManager(void)
    :physicsEngine(0),
    gui(0),
    mMode(MENU)
    // mShutDown(false)
{
}
//---------------------------------------------------------------------------
GameManager::~GameManager(void)
{
}

//---------------------------------------------------------------------------
int cubeRoomDimention = 5000;
int sphereRadius = 100;
std::string mMode = "PAUSE";
Ogre::Entity* sphereEntity;
Ogre::Entity* paddleEntity;
Ogre::SceneNode* paddleNode;
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
btRigidBody *paddleBody;
btRigidBody *groundBody;
btRigidBody *ceilingBody;
btRigidBody *wall1Body;
btRigidBody *wall2Body;
btRigidBody *wall3Body;
btRigidBody *wall4Body;
btTransform paddleTransformation;
bool roomInitiated = false;
// CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID);
CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID) {
  switch (buttonID)
  {
    case OIS::MB_Left:
      return CEGUI::LeftButton;

    case OIS::MB_Right:
      return CEGUI::RightButton;

    case OIS::MB_Middle:
      return CEGUI::MiddleButton;

    default:
      return CEGUI::LeftButton;
  }
}

// bool GameManager::keyPressed( const OIS::KeyEvent &arg )
// {
//   CEGUI::GUIContext &context = CEGUI::System::getSingleton().getDefaultGUIContext();
//   context.injectKeyDown((CEGUI::Key::Scan)arg.key);
//   context.injectChar((CEGUI::Key::Scan)arg.text);

//   if (arg.key == OIS::KC_ESCAPE)
//   {
//       mShutDown = true;
//   }

//   mCameraMan->injectKeyDown(arg);


//   return true;
// }

// bool GameManager::keyReleased( const OIS::KeyEvent &arg )
// {
//   CEGUI::System::getSingleton().getDefaultGUIContext().injectKeyUp((CEGUI::Key::Scan)arg.key);
  
// }

// bool GameManager::mouseMoved( const OIS::MouseEvent &arg )
// {
//   CEGUI::GUIContext &context = CEGUI::System::getSingleton().getDefaultGUIContext();
//   context.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
  
//   // Scroll wheel.
//   if (arg.state.Z.rel)
//     context.injectMouseWheelChange(arg.state.Z.rel / 120.0f);
//   return true;
// }

bool GameManager::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(convertButton(id));
  return true;  
}

bool GameManager::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(convertButton(id));
  return true;
}

void GameManager::createScene(void)
{
    // Setting Up Physics
    physicsEngine = new Physics();
    gui = new GUI();
    sound = new Sound();


    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.7, 0.7, 0.7));


    ////////////////PADDLE////////////// //MEOW
    int paddleX = 0;
    int paddleY = 100;
    int paddleZ = 0;

    Ogre::Vector3 ogrePaddlePosition = Ogre::Vector3(paddleX,paddleY,paddleZ);
    paddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(ogrePaddlePosition);
    paddleEntity = mSceneMgr->createEntity("cube.mesh");
    paddleEntity->setCastShadows(true);
    paddleEntity->setMaterialName("MyMaterials/HexagonalMesh");
    paddleNode->setScale(.7, .7, .1); 
    paddleNode->attachObject(paddleEntity);

    // ***Set up bullet Transform necessary for rigidbody.***
    //btTransform paddleTransformation;
    paddleTransformation.setIdentity();
    //paddleTransformation.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0)); UNCOMMENT if we want paddle to rotate
    btVector3 btPaddlePosition = btVector3(paddleX,paddleY,paddleZ);
    paddleTransformation.setOrigin(btPaddlePosition);

    // ***Set up bullet Collider necessary for rigidbody.***
    btVector3 btPaddleScale(.7, .7, .1);
    btBoxShape* btPaddleCollider = physicsEngine->makePaddle(btPaddlePosition);
    btPaddleCollider->setLocalScaling(btPaddleScale);
    btScalar paddleMass(6000);                 /* "0" -> an immovable object */
    btVector3 localPaddleInertia(70,70,70); 
    btPaddleCollider->calculateLocalInertia(paddleMass, localPaddleInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *paddleMotionState = new MyMotionState(paddleTransformation, paddleNode);

    // ***Create and track the paddle's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo rbPInfo(paddleMass, paddleMotionState, btPaddleCollider, localPaddleInertia);
    paddleBody = new btRigidBody(rbPInfo);
    paddleBody->setRestitution(2);
    //paddleBody->setUserPointer(paddleNode);
    physicsEngine->getDynamicsWorld()->addRigidBody(paddleBody);


    //void GameManager::makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
    //                                    const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant)

    makePlane(Ogre::Vector3(0, 0, 0),                                      "ground", floorPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/WoodenFloor",      btVector3(0, -50, 0),     btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(0, cubeRoomDimention, 0),                     "ceiling",  ceilingPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/White",            btVector3(0, 4950, 0),      -1.0f*btVector3(0, 1, 0), 0);

    makePlane(Ogre::Vector3(cubeRoomDimention/2, cubeRoomDimention/2, 0),    "wall", wallPlane, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, 0, 4950/2),     -1.0f*btVector3(0, 0, 1), 0);

    makePlane(Ogre::Vector3(-(cubeRoomDimention/2), cubeRoomDimention/2, 0), "wall2", wallPlane2, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, 0, -4950/2),     1.0f*btVector3(0, 0, 1), 0);

    makePlane(Ogre::Vector3(0, cubeRoomDimention/2, cubeRoomDimention/2),    "wall3", wallPlane3, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(4950/2, 0, 0),     -1.0f*btVector3(1, 0, 0), 0);

    makePlane(Ogre::Vector3(0, cubeRoomDimention/2, -(cubeRoomDimention/2)), "wall4", wallPlane4, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(-4950/2, 0, 0),     1.0f*btVector3(1, 0, 0), 0);

    ////////////////SPHERE///////////////

    // **Initial Position for Sphere. (Used to sync initial Ogre and Bullet sphere positions.)**
    int ipfsX = 30;
    int ipfsY = 4500;
    int ipfsZ = 30;

    // ***Create node for sphere.***
    Ogre::Vector3 ogreSpherePosition = Ogre::Vector3(ipfsX,ipfsY,ipfsZ);
    Ogre::SceneNode *sphereNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("sphereNode",ogreSpherePosition);
    // sphereNode->setScale(sphereRadius/20,sphereRadius/20,sphereRadius/20);

    // ***Add sphere entity to its node.***
    sphereEntity = mSceneMgr->createEntity("sphere.mesh");
    sphereEntity->setCastShadows(true);
    sphereEntity->setMaterialName("MyMaterials/GreenRubberBall");
    sphereNode->attachObject(sphereEntity);

    // ***Set up bullet Transform necessary for rigidbody.***
    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0));
    btVector3 btSpherePosition = btVector3(ipfsX,ipfsY,ipfsZ);
    startTransform.setOrigin(btSpherePosition);

    // ***Set up bullet Collider necessary for rigidbody.***
    btSphereShape* btSphereCollider = physicsEngine->makeBall(sphereRadius); //change this value!
    btScalar mass(0.1f);                 /* "0" -> an immovable object */
    btVector3 localInertia(0,0,0); 
    btSphereCollider->calculateLocalInertia(mass, localInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *myMotionState = new MyMotionState(startTransform, sphereNode);

    // ***Create and track the sphere's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, btSphereCollider, localInertia);
    sphereBody = new btRigidBody(rbInfo);
    sphereBody->setRestitution(1.0f);
    sphereBody->setUserPointer(sphereNode);
    physicsEngine->getDynamicsWorld()->addRigidBody(sphereBody);


    srand(time(NULL));
    btVector3 direction(100.0f * (rand() * 1.0f / RAND_MAX),
                        100.0f * (rand() * 1.0f / RAND_MAX),
                        100.0f * (rand() * 1.0f / RAND_MAX));

    sphereBody->setLinearVelocity(direction);
    physicsEngine->getDynamicsWorld()->addRigidBody(sphereBody);

    ////////////////////////////////////////////////
    // ***Used for manually setting velocity in Project 1.***
    // srand(time(NULL)); //for random number
    // speed = speedOfBall();
    // dir = directionVector()*speed;
}
//---------------------------------------------------------------------------

void GameManager::makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
                                    const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant)
{
    Ogre::SceneNode *groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(nodeLocation);

    Ogre::MeshManager::getSingleton().createPlane(
      planeName,
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      planePlane, 
      cubeRoomDimention, cubeRoomDimention, 20, 20, 
      true, 
      1, 5, 5, 
      upVector);

    Ogre::Entity* groundEntity = mSceneMgr->createEntity(planeName);
    groundEntity->setCastShadows(false);
    groundEntity->setMaterialName(materialName);
    groundNode->attachObject(groundEntity);


    // ***Set up bullet Transform necessary for rigidbody.***
    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(btOriginVector);

    // ***Set up CollisionShape necessary for rigidbody.***
    btCollisionShape *groundShape = new btStaticPlaneShape(planeNormal, planeConstant);
    btScalar groundMass(0.);
    btVector3 localGroundInertia(0, 0, 0);
    groundShape->calculateLocalInertia(groundMass, localGroundInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *groundMotionState = new MyMotionState(groundTransform, groundNode);

    // ***Create and track the ground's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo groundRBInfo(groundMass, groundMotionState, groundShape, localGroundInertia);
    groundBody = new btRigidBody(groundRBInfo);
    groundBody->setRestitution(1.0f);
    physicsEngine->getDynamicsWorld()->addRigidBody(groundBody);

}

void GameManager::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    //position the camera
    mCamera->setPosition(Ogre::Vector3(0, 300, 500)); //0 300 500
    //sets direction of camera
    mCamera->lookAt(Ogre::Vector3(0, 3000, 0));
    //the distance at which the Camera will no longer render any mesh
    mCamera->setNearClipDistance(1);
    //camera controller, can control camera passed to it
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
    mCameraMan->setTopSpeed(2000.0f);
}
 
void GameManager::createViewports()
{
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    //set the background color of the Viewport
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    //not using this now, but getting in the habit
    mCamera->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) /
    Ogre::Real(vp->getActualHeight()));
}

bool GameManager::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);
  if(gui->mShutDown)
    return false;
  // Ogre::Vector3 b = sphereNode->getPosition();

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
  //printf("4\n");

  //////////////////PADDLE MOVEMENT////////////////// //MEOW
  float followDist = 300.0;
  Ogre::Vector3 campos = mCamera->getPosition();
  Ogre::Vector3 camdir = mCamera->getDirection();
  camdir.normalise();
  camdir *= followDist;

  Ogre::Vector3 pos = camdir + campos;

  //printf("[ %f, %f, %f ] + ", campos.x, campos.y, campos.z);
  //printf("[ %f, %f, %f ] = ", camdir.x, camdir.y, camdir.z);
  //printf("[ %f, %f, %f ]", (float)(paddleNode->getPosition().x), (float)(paddleNode->getPosition().y), (float)(paddleNode->getPosition().z));

  //paddleNode->setPosition(pos);
  //paddleNode->setOrientation(mCamera->getOrientation()); 

  btQuaternion newPaddleQuaternion(mCamera->getOrientation().x, mCamera->getOrientation().y, mCamera->getOrientation().z, 0);
  btVector3 newPaddlePos(pos.x, pos.y, pos.z);
  btMotionState* paddleMSToUpdate = paddleBody->getMotionState();
  paddleMSToUpdate->setWorldTransform(btTransform(newPaddleQuaternion, newPaddlePos));
  //////////////////////////////////// 


  physicsEngine->stepSimulation();

  btTransform trans;
  sphereBody->getMotionState()->getWorldTransform(trans);
  //printf("\nposition of Y: ");
  //printf("%f", (float)(trans.getOrigin().getY()));
  // mSceneMgr->getSceneNode("sphereNode")->getPosition().y;
  // Ogre::Vector3 bPosition = sphereNode->getPosition();
  if (mSceneMgr->getSceneNode("sphereNode")->getPosition().y <= 51){
    gui->incrementScore();
  }

  //printf("7\n");

  return ret;
}
 
bool GameManager::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  return true;
}

//borrowed idea from http://stackoverflow.com/questions/11758809/what-is-the-optimal-
//algorithm-for-generating-an-unbiased-random-integer-within-a?answertab=votes#tab-top
int GameManager::RandomNum (int min, int max)
{
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);

    return min + x % n;
}

Ogre::Vector3 GameManager::directionVector()
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

int GameManager::speedOfBall()
{
  int s = RandomNum(2, 3); 
  return s;
}

// bool GameManager::quit(const CEGUI::EventArgs &e)
// {
//   mShutDown = true;
//   return true;
// }

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
        GameManager app;

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
