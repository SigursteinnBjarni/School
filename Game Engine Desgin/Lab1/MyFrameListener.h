#include "OGRE/OgreRoot.h"
#include "OGRE/OgreConfigFile.h"
#include "OGRE/OgreEntity.h"
#include "Ogre/Ogre.h"
#include "CylindricalEffect.h"
#include "OIS\OIS.h"


class MyFrameListener : public Ogre::FrameListener
{
public:
	
	bool frameStarted(const Ogre::FrameEvent& evt);
	/*
	bool frameEnded(const Ogre::FrameEvent& evt);
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	*/
	MyFrameListener(Ogre::RenderWindow* win, Ogre::Camera* cam, Ogre::Viewport* viewPort, 
					Ogre::SceneNode* node, Ogre::Entity* ent, CylindricalEffect* effect);
	~MyFrameListener();
private:
	float _movementSpeed;
	float _walkingSpeed;

	OIS::InputManager* _InputManager;
	OIS::Keyboard* _Keyboard;
	OIS::Mouse* _Mouse;

	Ogre::Camera* _Cam;
	Ogre::SceneNode* _node;
	Ogre::AnimationState* _aniState;
	Ogre::AnimationState* _aniStateTop;
	Ogre::AnimationState* _dance;

	CylindricalEffect* _effect;

};

