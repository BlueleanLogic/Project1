#ifndef __MyMotionState_h_
#define __MyMotionState_h_
#include "LinearMath/btMotionState.h"
#include <OgreNode.h>


//---------
// includes
//---------

class MyMotionState : public btMotionState {
	Ogre::SceneNode* mSceneNode;
	btTransform mInitialPosition;

	public:
		MyMotionState(const btTransform &initialPosition, Ogre::SceneNode *node);
		~MyMotionState();
		void setNode(Ogre::SceneNode *node);
		void getWorldTransform(btTransform &worldTrans) const;
		void setWorldTransform(const btTransform &worldTrans);

	protected:
};

#endif // #ifndef __MyMotionState_h_