#include "Ogre/Ogre.h"

class CylindricalEffect
{
public:
	CylindricalEffect(Ogre::Entity* entity, Ogre::Vector3 position, Ogre::Vector3 velocity);
	Ogre::Vector3 getCartesian();
	void update(float dt);
	~CylindricalEffect();

private:
	float radius;
	float height;
	Ogre::Radian angle;

	Ogre::Entity* _ent;
	Ogre::Vector3 _position;
	Ogre::Vector3 _velocity;
};
