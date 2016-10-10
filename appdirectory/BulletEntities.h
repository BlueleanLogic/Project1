#ifndef __BulletEntities_h_
#define __BulletEntities_h_

#include "BulletCollision/CollisionShapes/btStaticPlaneShape.h"
#include "BulletCollision/CollisionShapes/btSphereShape.h"
#include "BulletCollision/CollisionShapes/btBoxShape.h"
#include <OgreVector3.h>
#include "BulletEntities.h"

class BulletEntities{

	public:
		BulletEntities(void);
		~BulletEntities(void);
		btSphereShape* makeBall(int radius);
		btStaticPlaneShape makePlane(Ogre::Vector3 normal, int planeConstant);
		btBoxShape* makePaddle(btVector3 position);

	protected:


	private:

};

#endif // #ifndef __BulletEntities_h_