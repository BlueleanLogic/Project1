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
#include <OgreQuaternion.h>
#include <OgreNode.h>
#include <ctime>
#include "MyMotionState.h"
#include <OgreRectangle2D.h>
#include "scoreBoard.h"
#include <string>
#include <iostream>
#include <sstream>

template <typename T>
  std::string NumberToString ( T Number )
  {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
  }

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
btRigidBody *groundBody;
btRigidBody *ceilingBody;
btRigidBody *wall1Body;
btRigidBody *wall2Body;
btRigidBody *wall3Body;
btRigidBody *wall4Body;
int a = 0;

void TutorialApplication::createScene(void)
{
    // Setting Up Physics
    physicsEngine = new Physics();
    bulletEntities = new BulletEntities();
    // sound = new Sound();

    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.7, 0.7, 0.7));
    {
      mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();

      CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
      CEGUI::Font::setDefaultResourceGroup("Fonts");
      CEGUI::Scheme::setDefaultResourceGroup("Schemes");
      CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
      CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

      CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme"); 

      CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
      CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
      sheet = wmgr.createWindow("DefaultWindow", "Raquetball/Sheet");

      scoreBox = wmgr.createWindow("TaharezLook/StaticText", "Raquetball/Pause/PauseMenu/Sound");
      scoreBox->setText("Score: 0");
      scoreBox->setSize(CEGUI::USize(CEGUI::UDim(0.1, 0), CEGUI::UDim(0.05, 0)));
      scoreBox->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.9,0), CEGUI::UDim(0,0)));
      sheet->addChild(scoreBox);
      scoreBox->setText("Score: 0");           
      CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
    }


    ////////////////PADDLE//////////////
    
    Ogre::Vector3 ogrePaddlePosition = Ogre::Vector3(100,500,0);
    paddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(ogrePaddlePosition);
    paddleEntity = mSceneMgr->createEntity("cube.mesh");
    paddleEntity->setCastShadows(true);
    paddleEntity->setMaterialName("MyMaterials/HexagonalMesh");
    paddleNode->setScale(.7, .7, .1); 
    paddleNode->attachObject(paddleEntity);

    //void TutorialApplication::makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
    //                                    const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant)

    makePlane(Ogre::Vector3(0, 0, 0),                                      "ground", floorPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/WoodenFloor",      btVector3(0, -50, 0),   btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(0, cubeRoomDimention, 0),                     "ceiling",  ceilingPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/White",            btVector3(0, 50, 0),                        btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(cubeRoomDimention/2, cubeRoomDimention/2, 0),    "wall", wallPlane, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, -50, 0),    btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(-(cubeRoomDimention/2), cubeRoomDimention/2, 0), "wall2", wallPlane2, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, -50, 0), btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(0, cubeRoomDimention/2, cubeRoomDimention/2),    "wall3", wallPlane3, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, -50, 0),    btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(0, cubeRoomDimention/2, -(cubeRoomDimention/2)), "wall4", wallPlane4, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, -50, 0),  btVector3(0, 1, 0), 0);

    ////////////////SPHERE///////////////

    // **Initial Position for Sphere. (Used to sync initial Ogre and Bullet sphere positions.)**
    int ipfsX = 30;
    int ipfsY = 500;
    int ipfsZ = 30;

    // ***Create node for sphere.***
    Ogre::Vector3 ogreSpherePosition = Ogre::Vector3(ipfsX,ipfsY,ipfsZ);
    Ogre::SceneNode *sphereNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(ogreSpherePosition);
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
    btSphereShape* btSphereCollider = bulletEntities->makePingPongBall(sphereRadius); //change this value!
    btScalar mass(0.1f);                 /* "0" -> an immovable object */
    btVector3 localInertia(0,0,0); 
    btSphereCollider->calculateLocalInertia(mass, localInertia);

    // ***Set up MotionState necessary for rigidbody.***
    MyMotionState *myMotionState = new MyMotionState(startTransform, sphereNode);

    // ***Create and track the sphere's rigidbody.***
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, btSphereCollider, localInertia);
    sphereBody = new btRigidBody(rbInfo);
    sphereBody->setRestitution(3);
    sphereBody->setUserPointer(sphereNode);
    physicsEngine->getDynamicsWorld()->addRigidBody(sphereBody);

    ////////////////////////////////////////////////
    // ***Used for manually setting velocity in Project 1.***
    // srand(time(NULL)); //for random number
    // speed = speedOfBall();
    // dir = directionVector()*speed;
}
//---------------------------------------------------------------------------

void TutorialApplication::makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
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
    groundBody->setRestitution(1);
    physicsEngine->getDynamicsWorld()->addRigidBody(groundBody);

}

void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    //position the camera
    mCamera->setPosition(Ogre::Vector3(0, 300, 500)); //0 300 500
    //sets direction of camera
    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
    //the distance at which the Camera will no longer render any mesh
    mCamera->setNearClipDistance(1);
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
  //printf("4\n");

  //////////////////PADDLE MOVEMENT//////////////////
  float followDist = 300.0;
  Ogre::Vector3 campos = mCamera->getPosition();
  Ogre::Vector3 camdir = mCamera->getDirection();
  camdir.normalise();
  camdir *= followDist;

  //printf("[ %f, %f, %f ] + ", campos.x, campos.y, campos.z);
  //printf("[ %f, %f, %f ] = ", camdir.x, camdir.y, camdir.z);
  //printf("[ %f, %f, %f ]", (float)(paddleNode->getPosition().x), (float)(paddleNode->getPosition().y), (float)(paddleNode->getPosition().z));

  //Ogre::Quaternion* camquat = new Ogre::Quaternion(Ogre::Radian(0), camdir);

  paddleNode->setPosition(camdir + campos);
  //paddleNode->roll();
  //paddleNode->yaw();
  //paddleNode->pitch();
  paddleNode->setOrientation(mCamera->getOrientation());

  ////////////////////////////////////


  physicsEngine->stepSimulation();

  btTransform trans;
  sphereBody->getMotionState()->getWorldTransform(trans);
  //printf("\nposition of Y: ");
  //printf("%f", (float)(trans.getOrigin().getY()));
  a++;
  std::string s = NumberToString(a);
  scoreBox->setText("Score: "+s);
  //printf("7\n");

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
