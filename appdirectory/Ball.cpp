#include "Ball.h"

int sphereRadius = 100;
Ogre::Entity* sphereEntity;
Ogre::SceneNode* sphereNode;
btRigidBody *sphereBody;


//---------------------------------------------------------------------------
Ball::Ball(Ogre::SceneManager *mSceneMgr, Physics *physicsEngine)
{
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
}
//---------------------------------------------------------------------------
Ball::~Ball(void)
{
}

btRigidBody *Ball::GetBody(){
    return sphereBody;
}