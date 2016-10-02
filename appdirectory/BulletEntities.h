
#ifndef __BulletEntities_h_
#define __BulletEntites_h_

#include "BulletCollision/CollisionShapes/btStaticPlaneShape.h"
#include "BulletCollision/CollisionShapes/btSphereShape.h"
#include <OgreVector3.h>

class BulletEntities{

	public:
		BulletEntities(void);
		~BulletEntities(void);
		btSphereShape makePingPongBall(int radius);
		btStaticPlaneShape makePlane(Ogre::Vector3 normal, float planeConstant);

	protected:


	private:

};

#endif // #ifndef __BulletEntities_h_