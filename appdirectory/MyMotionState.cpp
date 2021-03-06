#include "MyMotionState.h"

MyMotionState::MyMotionState(const btTransform &initialPosition, Ogre::SceneNode *node)
{
    mSceneNode = node;
    mInitialPosition = initialPosition;
}

MyMotionState::~MyMotionState()
{
}

void MyMotionState::setNode(Ogre::SceneNode *node)
{
    mSceneNode = node;
}

void MyMotionState::getWorldTransform(btTransform &worldTrans) const
{//from ogre to bullet
    worldTrans = mInitialPosition;
}

void MyMotionState::setWorldTransform(const btTransform &worldTrans)
{ //from bullet to ogre
    if(mSceneNode == 0)
        return; // silently return before we set a node

    btQuaternion rot = worldTrans.getRotation();
    mSceneNode->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
    btVector3 pos = worldTrans.getOrigin();
    mSceneNode->setPosition(pos.x(), pos.y(), pos.z());
}
