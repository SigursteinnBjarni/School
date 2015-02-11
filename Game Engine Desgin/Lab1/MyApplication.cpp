#include "OGRE/OgreRoot.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreSceneNode.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreConfigFile.h"
#include "OGRE/OgreEntity.h"
#include "Ogre/Ogre.h"
#include "OgreMath.h"

#include "MyApplication.h"

MyApplication::MyApplication()
{
	_sceneManager = NULL;
	_root = NULL;
	_listener = NULL;
	_effect = NULL;
}

void MyApplication::loadResources()
{
	//Load the config file
	Ogre::ConfigFile cf;
	cf.load("../LabFiles/OgreConfig/resources_d.cfg");
	//First get the iteratot which goes over each section of the confi8 file
	Ogre::ConfigFile::SectionIterator sectionIter = cf.getSectionIterator();


	//Define three strings to save the data we are going to extract from the config file
	//and iterate over each section
	Ogre::String sectionName, typeName, dataName;
	while (sectionIter.hasMoreElements()) {
		//Get the name of the section
		sectionName = sectionIter.peekNextKey();

		//Get the settings contained in the section and, at the same time, advance the section
		//iterator, also create an iterator for the settings itself
		Ogre::ConfigFile::SettingsMultiMap *settings = sectionIter.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		//Iterate over each setting in the section

		for (i = settings->begin(); i != settings->end(); ++i) {
			//Use the iterator to get the name and the type of the resources:
			typeName = i->first;
			dataName = i->second;

			//Use the resource name, type, and section name to add it to the resource index
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(dataName, typeName, sectionName);
		}
	}

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

}

bool MyApplication::keepRunning()
{
	return _keepRunning;
}

void MyApplication::renderOneFrame()
{
	Ogre::WindowEventUtilities::messagePump();
	_keepRunning = _root->renderOneFrame();
}


int MyApplication::startUp()
{
	//Create an instance of the Ogre 3D Rooc class
	_root = new Ogre::Root("../LabFiles/OgreConfig/plugins_d.cfg", "../LabFiles/OgreConfig/ogre.cfg");

	//lf the config dialog can't be shown or the user cancels it, close the application
	if (!_root->showConfigDialog()) {
		return -1;
	}

	//Create a scene manager
	_sceneManager = _root->createSceneManager(Ogre::ST_GENERIC);

	//Create a renderer window
	Ogre::RenderWindow* window = _root->initialise(true, "Ogre3D Beginners Guide");

	
	//Create a camera
	Ogre::Camera* camera = _sceneManager->createCamera("Camera");
	camera->setPosition(Ogre::Vector3(0, 0, 30));
	camera->lookAt(Ogre::Vector3(0, 0, 0));
	camera->setNearClipDistance(5);

	//With the camera, create viewport
	Ogre::Viewport* viewport = window->addViewport(camera);
	viewport->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));

	//Use the window to set the aspect ratio of the camera
	camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));


	loadResources();
	createScene();

	_listener = new MyFrameListener(window, camera, viewport, _SinbadNode, _SinbadEnt,_effect);	
	_root->addFrameListener(_listener);

	return 0;

}
void MyApplication::createScene()
{
	
	Ogre::Entity* myModel = _sceneManager->createEntity("MyModel", "MyModel.mesh");
	Ogre::SceneNode* modelNode = _sceneManager->getRootSceneNode()->createChildSceneNode();
	modelNode->attachObject(myModel);
	modelNode->setScale(5, 5, 5);
	modelNode->setPosition(15, 0, 2);
	
	//create sinbad
 	_SinbadEnt = _sceneManager->createEntity("Sinbad.mesh");
	_SinbadNode = _sceneManager->getRootSceneNode()->createChildSceneNode();
	_SinbadNode->attachObject(_SinbadEnt);

	_myOgre = _SinbadEnt;

	_myCube = _sceneManager->createEntity("Cube.mesh");
	Ogre::SceneNode* cubeNode = _myOgre->getParentSceneNode()->createChildSceneNode();

	//attach the cube and set it's position
	cubeNode->attachObject(_myCube);
	cubeNode->scale(0.01, 0.01, 0.01);
	cubeNode->setPosition(2.0, 0.0, 0.0);

	//create a light and attach it to the cube
	Ogre::Light* plight = _sceneManager->createLight("Light2");
	plight->setType(Ogre::Light::LT_POINT);
	cubeNode->attachObject(plight);

	//Creating a new instace of the cylindrical effect
	_effect = new CylindricalEffect(_myCube, Ogre::Vector3(5.0, 5.0 ,3.0), Ogre::Vector3(0.0, 0.0, 1.0));

	Ogre::AnimationStateIterator iter = _SinbadEnt->getAllAnimationStates()->getAnimationStateIterator();
	while (iter.hasMoreElements()) {
		Ogre::AnimationState *a = iter.getNext();
		std::cout << a->getAnimationName() << std::endl;
	}

	_sceneManager->setAmbientLight(Ogre::ColourValue(.3f, .3f, .3f));

	// Plane defenititon
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -5);
	Ogre::MeshManager::getSingleton().createPlane("plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
		1500, 1500, 200, 200, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	// Create a instance of this plane and add it to the scene
	Ogre::Entity* ground = _sceneManager->createEntity("LightPlaneEntity", "plane");
	_sceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(ground);
	ground->setMaterialName("Examples/BeachStones");

	// Add lights
	Ogre::Light* light = _sceneManager->createLight("light1");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(Ogre::Vector3(1, -1, 0));

	// Add shadow
	_sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

}
MyApplication::~MyApplication()
{
	delete _root;
	delete _listener;
	delete _effect;
}