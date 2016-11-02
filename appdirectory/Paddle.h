#ifndef __Paddle_h_
#define __Paddle_h_

#include "Physics.h"
#include "MyMotionState.h"
#include <OgreEntity.h>
#include <OgreSceneManager.h>

//---------------------------------------------------------------------------
class Paddle{

	public:
		Paddle(Ogre::SceneManager *mSceneMgr, Physics *physicsEngine, bool client);
		~Paddle(void);
		int move[2];
};

#endif // #ifndef __Paddle_h_