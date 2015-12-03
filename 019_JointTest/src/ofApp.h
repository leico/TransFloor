#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "KinectCV.hpp"
#include "SecondScreen.hpp"
#include "Base.h"
#include "tkm001.h"
#include "ofmyDraw.h"

class ofApp : public ofBaseApp{

  ofxOscReceiver receiver;
  KinectCV       kinectcv;

  bool b_debug;

  const static std :: string prefix;

  const bool Debug(void);
        void Debug(const bool debug);

  Base *basedraw;

  public:
  void setup();
  void exit();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  shared_ptr<SecondScreen> secondscreen;
};


inline const bool ofApp :: Debug(void)            { return b_debug;  }
inline       void ofApp :: Debug(const bool debug){ b_debug = debug; }


