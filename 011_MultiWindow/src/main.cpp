#include "ofMain.h"
#include "ofApp.h"
#include "Second.hpp"

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
  
  shared_ptr<ofApp> mainApp(new ofApp);
  shared_ptr<Second> secondApp(new Second);
  
  ofRunApp(mainwindow, mainApp);
  ofRunApp(secondwindow, secondApp);

  ofRunMainLoop();


}
