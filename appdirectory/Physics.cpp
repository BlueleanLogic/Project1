#include "Physics.h"


//---------------------------------------------------------------------------
Physics::Physics(void)
{
}
//---------------------------------------------------------------------------
Physics::~Physics(void)
{
}

void Physics::initObjects() {
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	// list<CollisionShape> objects;
}

btDiscreteDynamicsWorld* Physics::getDynamicsWorld() {
	return dynamicsWorld;
}

void getCollisionShapes() { //change from void

}

void trackRigidBodyWithName() {

}