#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "KinectCV.hpp"


class ofApp : public ofBaseApp{

  ofxOscReceiver receiver;

  KinectCV kinectcv;

  bool b_debug;

  const bool Debug(void);
        void Debug(const bool debug);

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
};


inline const bool ofApp :: Debug(void)            { return b_debug;  }
inline       void ofApp :: Debug(const bool debug){ b_debug = debug; }


