#include "MyApplication.h"
using namespace std;

int main()
{
	MyApplication myApp;
	myApp.startUp();
	while (myApp.keepRunning()){
		myApp.renderOneFrame();
	}
	return 0;
}