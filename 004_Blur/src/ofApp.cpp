#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLogLevel(OF_LOG_VERBOSE);

  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  ofBackground(0);

  ofxKinect :: listDevices();

  kinect.init();
  kinect.open("A00363A02391053A");

  grayImage.allocate( kinect.getWidth(), kinect.getHeight() );



}
//--------------------------------------------------------------
void ofApp :: exit(){

  kinect.close();
  kinect.clear();
}

//--------------------------------------------------------------
void ofApp::update(){

  kinect.update();

  if(kinect.isFrameNew()){

    grayImage.setFromPixels( kinect.getDepthPixels(), kinect.getWidth(), kinect.getHeight() );
    grayImage.blur(10);
    
  }


}

//--------------------------------------------------------------
void ofApp::draw(){

  int width  = kinect.getWidth();
  int height = kinect.getHeight();

  grayImage.draw(0, 0, 320, 240);
  kinect.drawDepth(320, 0, 320, 240);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
