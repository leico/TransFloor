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
    
    kinectcv.osc(m);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  kinectcv.draw();

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
