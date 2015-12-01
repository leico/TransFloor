#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

  ofGLFWWindowSettings settings;
  
  settings.width  = 300;
  settings.height = 300;
  settings.setPosition( ofVec2f(20, 20) );
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> mainwindow = ofCreateWindow(settings);

  shared_ptr<ofApp> mainApp(new ofApp);
  
  ofRunApp(mainwindow, mainApp);

  ofRunMainLoop();


}
