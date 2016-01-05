#include "SecondScreen.h"

const std :: string SecondScreen :: prefix("/second");


//--------------------------------------------------------------
void SecondScreen::setup(){
  
  ofSetLogLevel(OF_LOG_WARNING);
  
  ofxKinect :: listDevices();
  kinectcv.setup("A00363907873053A");
  
  Debug(false);
  
  DisplaySetup();
  
  basedraw = new Blank();
  basedraw -> setup();
  
  style = ofGetStyle();
}
//--------------------------------------------------------------
void SecondScreen :: exit(){
  
  kinectcv.exit();
  
  delete basedraw;
}

//--------------------------------------------------------------
void SecondScreen::update(){
  
  kinectcv.update();
  
  
  vector <ofxOscMessage> humans = kinectcv.Humans();
  
  basedraw -> osc( humans );
  basedraw -> update();
}

void SecondScreen :: osc(ofxOscMessage &m){
  
    //if start is 'not' "/second", exit
  if( m.getAddress().find(prefix) != 0 ){
    m.clear();
    return;
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
      return;
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
        case 8  : delete basedraw; basedraw = new Font();        break; //Font
        case 9  : delete basedraw; basedraw = new buuun();       break; //buuun
        case 10 : delete basedraw; basedraw = new lines();       break;  //lines
        case 11 : delete basedraw; basedraw = new ossya();       break; //ossya
        case 13 : delete basedraw; basedraw = new vection();     break; //vection
        case 12 : delete basedraw; basedraw = new ofmyDraw();     break; //vection
        case 14 : delete basedraw; basedraw = new baribari();    break; //baribari
        default : m.clear();       return;                       break; //nomatch
      }
      
      DisplaySetup();
      basedraw -> setup();
      
      style = ofGetStyle();
      
      m.clear();
    }
    
    kinectcv.osc(m);
  
}

//--------------------------------------------------------------
void SecondScreen::draw(){
  
  ofSetStyle(style);
  
  if( Debug() ){
    kinectcv.draw();
    return;
  }
  
  basedraw -> draw();
  
}

//--------------------------------------------------------------
void SecondScreen::keyPressed(int key){
  
  if(key == 'f') ofToggleFullscreen();
  
}

//--------------------------------------------------------------
void SecondScreen::keyReleased(int key){
  
}

//--------------------------------------------------------------
void SecondScreen::mouseMoved(int x, int y){
  
}

//--------------------------------------------------------------
void SecondScreen::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void SecondScreen::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void SecondScreen::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void SecondScreen::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void SecondScreen::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void SecondScreen::dragEvent(ofDragInfo dragInfo){ 
  
}
