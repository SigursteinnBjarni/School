#include "CylindricalEffect.h"
#include "Ogre/Ogre.h"
#include "OgreMath.h"


CylindricalEffect::CylindricalEffect(Ogre::Entity* ent, Ogre::Vector3 position, Ogre::Vector3 velocity)
{
	_ent = ent;
	_position = position;
	_velocity = velocity;



}

Ogre::Vector3 CylindricalEffect::getCartesian()
{
	height = _position.x;
	radius = _position.y;
	angle = _position.z;

	Ogre::Vector3 result;

	result.x = Ogre::Math::Cos(angle) * radius;
	result.y = Ogre::Math::Cos(angle) * height+1;
	result.z = Ogre::Math::Sin(angle) * radius;
	return result;
}

void CylindricalEffect::update(float dt)
{
	_position = _position + dt * _velocity;
	_ent->getParentSceneNode()->setPosition(getCartesian());
}

CylindricalEffect::~CylindricalEffect()
{
}
