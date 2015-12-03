#include "ofApp.h"

const std :: string ofApp :: prefix("/first");


//--------------------------------------------------------------
void ofApp::setup(){
    
  ofSetLogLevel(OF_LOG_WARNING);

  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  ofBackground(0);

  ofxKinect :: listDevices();
  kinectcv.setup("A00364800479053A");

  receiver.setup(12345);

  Debug(false);

  basedraw = new ofmyDraw();

  basedraw -> setup();
}
//--------------------------------------------------------------
void ofApp :: exit(){

  kinectcv.exit();

  delete basedraw;
}

//--------------------------------------------------------------
void ofApp::update(){

  kinectcv.update();
  
  while(receiver.hasWaitingMessages()){
    ofxOscMessage m;
    receiver.getNextMessage(m);

    //if start is 'not' "/first", through to secondscreen
    if( m.getAddress().find(prefix) != 0 ){
      secondscreen -> osc(m);
      continue;
    }

    //------------------message to me
    m.setAddress( m.getAddress().substr( prefix.size() ) );

    
    if(m.getAddress() == "/debug"){
      Debug(m.getArgAsInt32(0) == 1);
      
      m.clear();
      continue;
    }
    
    kinectcv.osc(m);
  }

  
  vector <ofxOscMessage> humans = kinectcv.Humans();

  basedraw -> osc( humans );
  basedraw -> update();
}

//--------------------------------------------------------------
void ofApp::draw(){

  if( Debug() ){
    kinectcv.draw();
    return;
  }

  basedraw -> draw();

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
