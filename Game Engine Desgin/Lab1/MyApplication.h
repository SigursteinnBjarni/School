#include "OGRE/OgreRoot.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreSceneNode.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreConfigFile.h"
#include "OGRE/OgreEntity.h"
#include "MyFrameListener.h"

class MyApplication{
	private:
		Ogre::SceneManager* _sceneManager;
		Ogre::Root* _root;
		Ogre::SceneNode* _SinbadNode;
		Ogre::Entity* _SinbadEnt;



		Ogre::Entity* _myOgre;
		Ogre::Entity* _myCube;

		MyFrameListener* _listener;
		CylindricalEffect* _effect;

		bool _keepRunning;
	public:
		MyApplication();
		void loadResources();
		void renderOneFrame();
		int startUp();
		bool keepRunning();
		void createScene();
		~MyApplication();

};