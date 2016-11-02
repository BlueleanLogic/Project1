#include "Paddle.h"

Ogre::Entity* paddleEntity;
Ogre::SceneNode* paddleNode;
btRigidBody *paddleBody;
btTransform paddleTransformation;


//---------------------------------------------------------------------------
Paddle::Paddle(Ogre::SceneManager *mSceneMgr, Physics *physicsEngine, bool client)
{
    int paddleX = 0;
    int paddleY = 100;
    int paddleZ = 0;

    Ogre::Vector3 ogrePaddlePosition = Ogre::Vector3(paddleX,paddleY,paddleZ);
    paddleEntity = mSceneMgr->createEntity("cube.mesh");

    if(client) {
        paddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Paddle2", ogrePaddlePosition);
        paddleEntity->setMaterialName("MyMaterials/HexagonsAndStars");
    } else {
        paddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Paddle", ogrePaddlePosition);
        paddleEntity->setMaterialName("Examples/Rockwall");
    }

    paddleEntity->setCastShadows(true);
    paddleNode->setScale(7, 1, 7); 
    paddleNode->attachObject(paddleEntity);

    // ***Set up bullet Transform necessary for rigidbody.***
    //btTransform paddleTransformation;
    paddleTransformation.setIdentity();
    //paddleTransformation.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0)); UNCOMMENT if we want paddle to rotate
    btVector3 btPaddlePosition = btVector3(paddleX,paddleY,paddleZ);
    paddleTransformation.setOrigin(btPaddlePosition);

    // ***Set up bullet Collider necessary for rigidbody.***
    btVector3 btPaddleScale(7, 1, 7);
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
    paddleBody->setRestitution(1.0f);
    //paddleBody->setUserPointer(paddleNode);
    physicsEngine->getDynamicsWorld()->addRigidBody(paddleBody);
}
//---------------------------------------------------------------------------
Paddle::~Paddle(void)
{
}