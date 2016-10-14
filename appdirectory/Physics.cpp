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
	//printf("5\n");
	dynamicsWorld->stepSimulation(1.0f/60.0f);

	//printf("6\n");
}

btSphereShape* Physics::makeBall(int radius)	{
	btScalar rad(radius);
	return new btSphereShape(rad);
}

btStaticPlaneShape Physics::makePlane(Ogre::Vector3 normal, int planeConstant){
	btVector3 v(normal.x, normal.y, normal.z);
	btScalar c(planeConstant);
	return btStaticPlaneShape(v, c);
}

btBoxShape* Physics::makePaddle(btVector3 position){
	//btVector3 v(position.x, position.y, position.z);
	//btVector3 s(scale.x, scale.y, scale.z);
	//btBoxShape box = btBoxShape(position);
	//box->setLocalScaling(s);
	return new btBoxShape(position);
}