#include "MyFrameListener.h"
#include "Ogre/Ogre.h"

using namespace std;

//IOS will be initialized using a list of parameters, we also need a window handle 
//in string form for the parameter list; create the three needed variables to store the data.
MyFrameListener::MyFrameListener(Ogre::RenderWindow* win, Ogre::Camera* cam, Ogre::Viewport* viewPort, 
								Ogre::SceneNode* node, Ogre::Entity* ent, CylindricalEffect* effect)
{
	_Cam = cam;
	_movementSpeed = 25.0f;
	_walkingSpeed = 25.0f;
	_node = node;
	_effect = effect;

	_aniState = ent->getAnimationState("RunBase");
	_aniState->setLoop(false);

	_aniStateTop = ent->getAnimationState("RunTop");
	_aniState->setLoop(false);
	_dance = ent->getAnimationState("Dance");
	
	OIS::ParamList parameters;
	unsigned int windowHandle = 0;
	ostringstream windowHandleStream;

	//Get the handle of the Renderwindow and convert it into a string
	win->getCustomAttribute("WINDOW", &windowHandle);
	windowHandleStream << windowHandle;

	//Add the string containing the window handle to the parameter list using the key WINDOW.
	parameters.insert(make_pair("WINDOW", windowHandleStream.str()));

	//using the parameter list to create input manager
	_InputManager = OIS::InputManager::createInputSystem(parameters);

	//with the manager, create the keyboard
	_Keyboard = static_cast<OIS::Keyboard*>(_InputManager->createInputObject(OIS::OISKeyboard, false));

	_Mouse = static_cast<OIS::Mouse*>(_InputManager->createInputObject(OIS::OISMouse, false));

}

bool MyFrameListener::frameStarted(const Ogre::FrameEvent& evt)
{

	Ogre::Vector3 translate(0, 0, 0);
	Ogre::Vector3 SinbadTranslate(0, 0, 0);

	_effect->update(evt.timeSinceLastFrame);

	float _rotation = 0.0f;
	bool walked = false;

	//Keyboard input
	_Keyboard->capture();
	if (_Keyboard->isKeyDown(OIS::KC_ESCAPE)){
		return false;
	}
	if (_Keyboard->isKeyDown(OIS::KC_W)){
		translate += Ogre::Vector3(0, 0, -1);
	}
	if (_Keyboard->isKeyDown(OIS::KC_S)){
		translate += Ogre::Vector3(0, 0, 1);
	}
	if (_Keyboard->isKeyDown(OIS::KC_A)){
		translate += Ogre::Vector3(-1, 0, 0);
	}
	if (_Keyboard->isKeyDown(OIS::KC_D)){
		translate += Ogre::Vector3(1, 0, 0);
	}

	bool dance = false;
	if (_Keyboard->isKeyDown(OIS::KC_M)){
		dance = true;
	}

	//Sinbad movement
	if (_Keyboard->isKeyDown(OIS::KC_UP)){
		SinbadTranslate += Ogre::Vector3(0,0,-1);
		_rotation = 3.14f;
		walked = true;
	}
	if (_Keyboard->isKeyDown(OIS::KC_DOWN)){
		SinbadTranslate += Ogre::Vector3(0, 0, 1);
		_rotation = 0.0f;
		walked = true;
	}
	if (_Keyboard->isKeyDown(OIS::KC_LEFT)){
		SinbadTranslate += Ogre::Vector3(-1, 0, 0);
		_rotation = -1.57f;
		walked = true;
	}
	if (_Keyboard->isKeyDown(OIS::KC_RIGHT)){
		SinbadTranslate += Ogre::Vector3(1, 0, 0);
		_rotation = -1.57f;
		walked = true;
	}

	_Cam->moveRelative(translate * evt.timeSinceLastFrame * _movementSpeed);

	//Mouse input
	_Mouse->capture();

	float rotX = _Mouse->getMouseState().X.rel * evt.timeSinceLastFrame * -1;
	float rotY = _Mouse->getMouseState().Y.rel * evt.timeSinceLastFrame * -1;
	_Cam->yaw(Ogre::Radian(rotX));
	_Cam->pitch(Ogre::Radian(rotY));

	_node->translate(SinbadTranslate * evt.timeSinceLastFrame * _walkingSpeed);
	_node->resetOrientation();
	_node->yaw(Ogre::Radian(_rotation));
	
	
	if (walked){
		_aniState->setEnabled(true);
		_aniStateTop->setEnabled(true);

		if (_aniState->hasEnded()){
			_aniState->setTimePosition(0.0f);
		}
		if (_aniStateTop->hasEnded()){
			_aniStateTop->setTimePosition(0.0f);
		}

	}
	else{
		_aniState->setTimePosition(0.0f);
		_aniState->setEnabled(false);
		_aniStateTop->setTimePosition(0.0f);
		_aniStateTop->setEnabled(false);
	}
	if (dance){
		_dance->setEnabled(true);
		if (_dance->hasEnded()){
			_dance->setTimePosition(0.0f);
		}
	}
	else{
		_dance->setTimePosition(0.0f);
		_dance->setEnabled(false);
	}

	_aniState->addTime(evt.timeSinceLastFrame);
	_aniStateTop->addTime(evt.timeSinceLastFrame);
	_dance->addTime(evt.timeSinceLastFrame);

	return true;
}
/*
bool MyFrameListener::frameEnded(const Ogre::FrameEvent& evt)
{
	cout << "Frame ended" << endl;
	return true;
}
bool MyFrameListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	cout << "Frame queued" << endl;
	return true;
}
*/
MyFrameListener::~MyFrameListener()
{
	_InputManager->destroyInputObject(_Keyboard);
	_InputManager->destroyInputObject(_Mouse);
	OIS::InputManager::destroyInputSystem(_InputManager);
	delete _effect;


}
