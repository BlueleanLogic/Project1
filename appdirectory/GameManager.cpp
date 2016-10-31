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
#include "GameManager.h"
#include <OgreQuaternion.h>
#include <OgreNode.h>
#include <ctime>
#include <OgreRectangle2D.h>
#include "scoreBoard.h"
#include <sstream>


//---------------------------------------------------------------------------
GameManager::GameManager(void)
    :physicsEngine(0),
    gui(0),
    nm(NULL)
    // mShutDown(false)
{
}
//---------------------------------------------------------------------------
GameManager::~GameManager(void)
{
}

//---------------------------------------------------------------------------
int cubeRoomDimension;
Ogre::Vector3 dir;
int speed;
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

bool GameManager::keyPressed( const OIS::KeyEvent &arg )
{
  CEGUI::GUIContext &context = CEGUI::System::getSingleton().getDefaultGUIContext();
  context.injectKeyDown((CEGUI::Key::Scan)arg.key);
  context.injectChar((CEGUI::Key::Scan)arg.text);

  if (arg.key == OIS::KC_ESCAPE)
  {
      mShutDown = true;
  }

  mCameraMan->injectKeyDown(arg);


  return true;
}

// bool GameManager::keyReleased( const OIS::KeyEvent &arg )
// {
//   CEGUI::System::getSingleton().getDefaultGUIContext().injectKeyUp((CEGUI::Key::Scan)arg.key);
  
// }

bool GameManager::mouseMoved( const OIS::MouseEvent &arg )
{
  CEGUI::GUIContext &context = CEGUI::System::getSingleton().getDefaultGUIContext();
  if (gui->isGui())
    context.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);

  if (gui->isPlay())
    mCameraMan->injectMouseMove(arg);

  return true;
}

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
    // sound->loadSounds();
    // nm = new NetManager();

    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.7, 0.7, 0.7));

    Paddle *paddle = new Paddle(mSceneMgr, physicsEngine);
    ball = new Ball(mSceneMgr, physicsEngine);
    Room *room = new Room(mSceneMgr, physicsEngine);
    cubeRoomDimension = room->getDimension();
}


void GameManager::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    //position the camera
    mCamera->setPosition(Ogre::Vector3(5000/4, 5000*1.3, 5000/1.2)); //0 300 500
    //sets direction of camera
    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
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

  if (gui->isServer) {
    startMulti();
    gui->isServer=false;
  }

  if (gui->isClient) {
    searchGame();
    gui->isClient=false;
  }

  // Ogre::Vector3 b = sphereNode->getPosition();

  // Ogre::Vector3 R;

 
  // bool xOutOfRangeNeg = (a.x <= (0-cubeRoomDimension/2 + sphereRadius));
  // physicsEngine->getDynamicsWorld()->stepSimulation(1.0f/60.0f);
  // bool xOutOfRangePos = (a.x >= (cubeRoomDimension/2 - sphereRadius));
  // bool yOutOfRangeNeg = (a.y <= (0 + sphereRadius));
  // bool yOutOfRangePos = (a.y >= (cubeRoomDimension - sphereRadius));
  // bool zOutOfRangeNeg = (a.z <= (0-cubeRoomDimension/2 + sphereRadius));
  // bool zOutOfRangePos = (a.z >= (cubeRoomDimension/2 - sphereRadius));
 
 
 
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
  
  static Ogre::Real move = 2000;

  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  if (mKeyboard->isKeyDown(OIS::KC_I))
      dirVec.z -= move;
  if (mKeyboard->isKeyDown(OIS::KC_K))
      dirVec.z += move;

  if (mKeyboard->isKeyDown(OIS::KC_J))
      dirVec.x -= move;
  if (mKeyboard->isKeyDown(OIS::KC_L))
      dirVec.x += move;

  mSceneMgr->getSceneNode("Paddle")->translate(
      dirVec * fe.timeSinceLastFrame,
      Ogre::Node::TS_LOCAL);


  physicsEngine->stepSimulation();

  btTransform trans;
  ball->GetBody()->getMotionState()->getWorldTransform(trans);
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

bool GameManager::startServer() {
  if (nm) {
    endNetwork();
  }
  nm = new NetManager();
  nm->initNetManager();
  nm->addNetworkInfo();
  if ( nm->startServer() ) {
    nm->acceptConnections();
    return true;
  }
  return false;
}

bool GameManager::startClient(const char* IP) {
  if (nm) {
    endNetwork();
  }
  nm = new NetManager();
  nm->initNetManager();
  nm->addNetworkInfo(PROTOCOL_ALL,IP);
  if ( nm->startClient() ) {
    return true;
  }
  return false;
}

void GameManager::searchGame() {
  if (startClient(gui->address.c_str())){
    if (gui->address.compare(nm->getIPstring()))
      gui->setPlay();
  }
}


void GameManager::endNetwork() {
  if (nm) {
    nm->close();
    delete nm;
    nm = NULL;
  }
}

void GameManager::startMulti() {
  if (startServer()){
    if (nm->pollForActivity(5000)) {
      if (nm->getClients()){
        gui->setPlay();
      }
    }
  }
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
