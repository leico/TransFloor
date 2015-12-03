#include "ofMain.h"
#include "MainScreen.h"
#include "SecondScreen.hpp"

//========================================================================
int main( ){

  ofGLFWWindowSettings settings;
  
  settings.width  = 300;
  settings.height = 300;
  settings.setPosition( ofVec2f(20, 20) );
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> mainwindow = ofCreateWindow(settings);

  settings.width  = 300;
  settings.height = 300;
  settings.setPosition( ofVec2f(400, 20) );
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> secondwindow = ofCreateWindow(settings);
  
  shared_ptr<MainScreen> mainApp(new MainScreen);
  shared_ptr<SecondScreen> secondApp(new SecondScreen);
  
  ofRunApp(mainwindow, mainApp);
  ofRunApp(secondwindow, secondApp);
  mainApp -> secondscreen = secondApp;

  ofRunMainLoop();


}
