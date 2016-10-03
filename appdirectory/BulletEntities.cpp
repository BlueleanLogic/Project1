#include "BulletEntities.h"


#include "LinearMath/btScalar.h"


//---------------------------------------------------------------------------
BulletEntities::BulletEntities(void)
{
}
//---------------------------------------------------------------------------
BulletEntities::~BulletEntities(void)
{
}

btSphereShape* BulletEntities::makePingPongBall(int radius)	{
	btScalar rad(radius);
	return new btSphereShape(rad);
}

btStaticPlaneShape BulletEntities::makePlane(Ogre::Vector3 normal, int planeConstant){
	btVector3 v(normal.x, normal.y, normal.z);
	btScalar c(planeConstant);
	return btStaticPlaneShape(v, c);
}