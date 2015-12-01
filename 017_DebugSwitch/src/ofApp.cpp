#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
  ofSetLogLevel(OF_LOG_WARNING);

  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  ofBackground(0);

  ofxKinect :: listDevices();
  kinectcv.setup("A00364800479053A", "/first");

  receiver.setup(12345);

  Debug(false);
}
//--------------------------------------------------------------
void ofApp :: exit(){

  kinectcv.exit();
}

//--------------------------------------------------------------
void ofApp::update(){

  kinectcv.update();
  
  while(receiver.hasWaitingMessages()){
    ofxOscMessage m;
    receiver.getNextMessage(m);

    if(m.getAddress() == "/first/debug"){
      Debug(m.getArgAsInt32(0) == 1);
      
      m.clear();
      continue;
    }
    
    kinectcv.osc(m);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  if( Debug() ){
    kinectcv.draw();
    return;
  }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  if(key == 'f') ofToggleFullscreen();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
