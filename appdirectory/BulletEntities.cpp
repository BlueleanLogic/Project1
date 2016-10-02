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

btSphereShape makePingPongBall(float radius)	{
	btScalar rad(radius);
	return btSphereShape(rad);
}

btStaticPlaneShape makePlane(Ogre::Vector3 normal, float planeConstant){
	btVector3 v(normal.x, normal.y, normal.z);
	btScalar c(planeConstant);
	return btStaticPlaneShape(v, c);
}