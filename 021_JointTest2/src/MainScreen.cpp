#include "MainScreen.h"

const std :: string MainScreen :: prefix("/first");


//--------------------------------------------------------------
void MainScreen::setup(){
    
  ofSetLogLevel(OF_LOG_WARNING);

  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  ofBackground(0);

  ofxKinect :: listDevices();
  kinectcv.setup("A00363A02931053A");

  receiver.setup(12345);

  Debug(false);

  basedraw = new tkm001();

  basedraw -> setup();
}
//--------------------------------------------------------------
void MainScreen :: exit(){

  kinectcv.exit();

  delete basedraw;
}

//--------------------------------------------------------------
void MainScreen::update(){

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
void MainScreen::draw(){

  if( Debug() ){
    kinectcv.draw();
    return;
  }

  basedraw -> draw();

}

//--------------------------------------------------------------
void MainScreen::keyPressed(int key){

  if(key == 'f') ofToggleFullscreen();

}

//--------------------------------------------------------------
void MainScreen::keyReleased(int key){

}

//--------------------------------------------------------------
void MainScreen::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void MainScreen::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MainScreen::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void MainScreen::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MainScreen::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MainScreen::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MainScreen::dragEvent(ofDragInfo dragInfo){ 

}
