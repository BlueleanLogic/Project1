#include "Physics.h"


//---------------------------------------------------------------------------
Physics::Physics(void)
{
	initObjects();
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
	dynamicsWorld->setGravity(btVector3 (0,-10,0));
	// list<CollisionShape> objects;
}

btDiscreteDynamicsWorld* Physics::getDynamicsWorld() {
	return dynamicsWorld;
}

void Physics::stepSimulation(){
	printf("5\n");
	dynamicsWorld->stepSimulation(1.0f/60.0f);
	printf("6\n");
}

void getCollisionShapes() { //change from void

}

void trackRigidBodyWithName() {

}