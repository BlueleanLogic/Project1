#ifndef __Physics_h_
#define __Physics_h_

#include <btBulletDynamicsCommon.h>
#include "BulletCollision/CollisionShapes/btCollisionShape.h"

#include <vector>
#include <map>
#include <string>

//---------------------------------------------------------------------------
class Physics{
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
	std::vector<btCollisionShape *> collisionShapes;
	std::map<std::string, btRigidBody *> physicsAccessors;
	public:
		Physics(void);
		~Physics(void);
		void initObjects(void);
		btDiscreteDynamicsWorld* getDynamicsWorld();
		void getCollisionShapes();
		void trackRigidBodyWithName();
		void stepSimulation();
	protected:

	private:
};

#endif // #ifndef __Physics_h_