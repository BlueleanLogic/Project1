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

btSphereShape* BulletEntities::makeBall(int radius)	{
	btScalar rad(radius);
	return new btSphereShape(rad);
}

btStaticPlaneShape BulletEntities::makePlane(Ogre::Vector3 normal, int planeConstant){
	btVector3 v(normal.x, normal.y, normal.z);
	btScalar c(planeConstant);
	return btStaticPlaneShape(v, c);
}

btBoxShape* BulletEntities::makePaddle(btVector3 position){
	//btVector3 v(position.x, position.y, position.z);
	//btVector3 s(scale.x, scale.y, scale.z);
	//btBoxShape box = btBoxShape(position);
	//box->setLocalScaling(s);
	return new btBoxShape(position);
}