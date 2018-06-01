#include "ofMain.h"
#include "ofApp.h"
#include "ProjectorView.hpp"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
//	ofVideoPlayer screen_player;
	float brightness;
	std::string title = "";
//	ofRunApp(new ofApp(&screen_player, &brightness));
//	ofRunApp(new ProjectorView(&screen_player, &brightness));

	ofGLWindowSettings settings;
	settings.width = 1920;
	settings.height = 1080;
	settings.setPosition(ofVec2f(0,0));
	auto projectionWindow = ofCreateWindow(settings);

	settings.width = 1920;
	settings.height = 1080;
	settings.setPosition(ofVec2f(300,0));
	auto mainWindow = ofCreateWindow(settings);

	auto projectionApp = make_shared<ProjectorView>(&title, &brightness);
	auto mainApp = make_shared<ofApp>(&title, &brightness);

	ofRunApp(mainWindow, mainApp);
	ofRunApp(projectionWindow, projectionApp);
	ofRunMainLoop();
}
