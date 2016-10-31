#ifndef __Room_h_
#define __Room_h_

#include "BaseApplication.h"


#include "Physics.h"
#include "MyMotionState.h"
#include <OgreEntity.h>
#include <OgreSceneManager.h>

#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include <OgreNode.h>
#include <OgreRectangle2D.h>


//---------------------------------------------------------------------------
class Room{

	public:
		Room(Ogre::SceneManager *mSceneMgr, Physics *physicsEngine);
		~Room(void);
		void makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
                        const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant);
		int cubeRoomDimension;
		int getDimension(void);
};

#endif // #ifndef __Room_h_