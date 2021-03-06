#include "MainScreen.h"

const std :: string MainScreen :: prefix("/first");


//--------------------------------------------------------------
void MainScreen::setup(){
    
  ofSetLogLevel(OF_LOG_VERBOSE);

  ofxKinect :: listDevices();
  kinectcv.setup("A00363902566052A");

  receiver.setup(12345);

  Debug(false);

  DisplaySetup();

  basedraw = new Blank();
  basedraw -> setup();
  
  style = ofGetStyle();
  
  
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

   
    //message is Debug
    if(m.getAddress() == "/debug"){

      Debug(m.getArgAsInt32(0) == 1);

      //Display Setting initialize
      DisplaySetup();
      if( ! Debug() ) basedraw -> setup();
      
      style = ofGetStyle();

      m.clear();
      continue;
    }

    //message is DisplayChagne
    if(m.getAddress() == "/scene"){
      switch( m.getArgAsInt32(0) ){

        case 0  : delete basedraw; basedraw = new Blank ();      break; //Blank
        case 1  : delete basedraw; basedraw = new tkm001();      break; //track circles
        case 2  : delete basedraw; basedraw = new RippleScene(); break; //Ripples
        case 3  : delete basedraw; basedraw = new Relation();    break; //Relation
        case 4  : delete basedraw; basedraw = new Gravity();     break; //Gravity
        case 5  : delete basedraw; basedraw = new takami();      break; //escape
        case 6  : delete basedraw; basedraw = new Gushi01();     break; //Pirrrrrrrrro
        case 7  : delete basedraw; basedraw = new tkmOTO();      break; //tkmOTO
        case 8  : delete basedraw; basedraw = new Font();        break; //LightBox
        case 9  : delete basedraw; basedraw = new buuun();       break; //buuun
        case 10 : delete basedraw; basedraw = new lines();       break; //lines
        case 11 : delete basedraw; basedraw = new ossya();       break; //ossya
        case 13 : delete basedraw; basedraw = new vection();     break; //vection
        case 12 : delete basedraw; basedraw = new ofmyDraw();       break; //vection
        case 14 : delete basedraw; basedraw = new baribari();    break; //baribari
        default : m.clear();       continue;                     break; //nomatch
      }

      DisplaySetup();
      basedraw -> setup();
      
      style = ofGetStyle();
    }
    
    kinectcv.osc(m);
  }

  
  vector <ofxOscMessage> humans = kinectcv.Humans();

  basedraw -> osc( humans );
  basedraw -> update();
}

//--------------------------------------------------------------
void MainScreen::draw(){
  
  ofSetStyle(style);

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
