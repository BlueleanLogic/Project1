#include "Room.h"



btRigidBody *groundBody;
btRigidBody *ceilingBody;
btRigidBody *wall1Body;
btRigidBody *wall2Body;
btRigidBody *wall3Body;
btRigidBody *wall4Body;

Ogre::Plane wallPlane4(Ogre::Vector3::UNIT_Z, 0); //negative z
Ogre::Plane wallPlane3(Ogre::Vector3::NEGATIVE_UNIT_Z, 0); //positive z
Ogre::Plane floorPlane(Ogre::Vector3::UNIT_Y, 0); // "negative" y
Ogre::Plane ceilingPlane(Ogre::Vector3::NEGATIVE_UNIT_Y, 0);// positive y
Ogre::Plane wallPlane(Ogre::Vector3::NEGATIVE_UNIT_X, 0); //positive x
Ogre::Plane wallPlane2(Ogre::Vector3::UNIT_X, 0); //negative x

Ogre::SceneManager *mSceneMgr;
Physics *physicsEngine;

//---------------------------------------------------------------------------
Room::Room(Ogre::SceneManager *_mSceneMgr, Physics *_physicsEngine)
{
    cubeRoomDimension = 5000;

    mSceneMgr = _mSceneMgr;
    physicsEngine = _physicsEngine;

    makePlane(Ogre::Vector3(0, 0, 0),                                      "ground", floorPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/WoodenFloor",      btVector3(0, -50, 0),     btVector3(0, 1, 0), 0);
    makePlane(Ogre::Vector3(0, cubeRoomDimension, 0),                     "ceiling",  ceilingPlane, Ogre::Vector3::UNIT_Z,
              "MyMaterials/White",            btVector3(0, 4950, 0),      -1.0f*btVector3(0, 1, 0), 0);

    makePlane(Ogre::Vector3(cubeRoomDimension/2, cubeRoomDimension/2, 0),    "wall", wallPlane, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, 0, 4950/2),     -1.0f*btVector3(0, 0, 1), 0);

    makePlane(Ogre::Vector3(-(cubeRoomDimension/2), cubeRoomDimension/2, 0), "wall2", wallPlane2, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(0, 0, -4950/2),     1.0f*btVector3(0, 0, 1), 0);

    makePlane(Ogre::Vector3(0, cubeRoomDimension/2, cubeRoomDimension/2),    "wall3", wallPlane3, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(4950/2, 0, 0),     -1.0f*btVector3(1, 0, 0), 0);

    makePlane(Ogre::Vector3(0, cubeRoomDimension/2, -(cubeRoomDimension/2)), "wall4", wallPlane4, Ogre::Vector3::UNIT_Y,
              "MyMaterials/HexagonsAndStars", btVector3(-4950/2, 0, 0),     1.0f*btVector3(1, 0, 0), 0);
}
//---------------------------------------------------------------------------
Room::~Room(void)
{
}

void Room::makePlane(Ogre::Vector3 nodeLocation, const char *planeName, Ogre::Plane planePlane, Ogre::Vector3 upVector,
                                    const char *materialName, btVector3 btOriginVector, btVector3 planeNormal, int planeConstant)
{
    Ogre::SceneNode *groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(nodeLocation);

    Ogre::MeshManager::getSingleton().createPlane(
      planeName,
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      planePlane, 
      cubeRoomDimension, cubeRoomDimension, 20, 20, 
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

int Room::getDimension()
{
    return cubeRoomDimension;
}