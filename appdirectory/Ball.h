#ifndef __Ball_h_
#define __Ball_h_

#include "Physics.h"
#include "MyMotionState.h"
#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreMeshManager.h>
#include <Ogre.h>

//---------------------------------------------------------------------------
class Ball{

	public:
		Ball(Ogre::SceneManager *mSceneMgr, Physics *physicsEngine);
		~Ball(void);
		btRigidBody *GetBody(void);
};

#endif // #ifndef __Ball_h_