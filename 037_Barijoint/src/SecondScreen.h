#pragma once

#include "TransFloor.h"

class SecondScreen : public ofBaseApp{
  
  KinectCV       kinectcv;
  
  bool b_debug;
  
  const static std :: string prefix;
  
  const bool Debug(void);
  void Debug(const bool debug);
  
  void DisplaySetup(void);
  
  Base *basedraw;
  
  ofStyle style;
public:
  void setup();
  void exit();
  void update();
  void draw();
  
  void osc(ofxOscMessage &m);
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
};


inline const bool SecondScreen :: Debug(void)            { return b_debug;  }
inline       void SecondScreen :: Debug(const bool debug){ b_debug = debug; }

inline void SecondScreen :: DisplaySetup(void){
  
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  
  ofBackground(0);
  
  ofSetBackgroundAuto(true);
  
  ofFill();
  ofSetLineWidth(1);
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  
  ofSetCircleResolution(32);
  
}

