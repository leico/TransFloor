#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
  ofSetLogLevel(OF_LOG_WARNING);

  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  ofBackground(0);

  ofxKinect :: listDevices();

  kinect.init();
  kinect.open("A00364800479053A");

  grayImage  .allocate( kinect.getWidth(), kinect.getHeight() );
  binaryImage.allocate( kinect.getWidth(), kinect.getHeight() );

  humans.resize(1024);
  humans.clear();
}
//--------------------------------------------------------------
void ofApp :: exit(){

  grayImage  .clear();
  binaryImage.clear();

  kinect.close();
  kinect.clear();
}

//--------------------------------------------------------------
void ofApp::update(){

  kinect.update();

  if(kinect.isFrameNew()){

    int width  = kinect.getWidth();
    int height = kinect.getHeight();

    //get kinect depth data and noise reduction
    grayImage.setFromPixels( kinect.getDepthPixels(), width, height );
    binaryImage = grayImage;
    binaryImage.blur(30);

    //binarization
    {
      unsigned char *pixels = binaryImage.getPixels();
      for(int i = 0, numpix = width * height ; i < numpix ; ++ i)
        pixels [i] = (pixels[i] <  50 || pixels[i] > 200 ) ? 0 : 255;
    }

    //contourfinder
    contourfinder.findContours(binaryImage, 0, 300, 200, false);

    humans.clear();

    for(int i = 0, size = contourfinder.blobs.size() ; i < size ; ++ i){

      ofPoint pos = contourfinder.blobs.at(i).centroid;
      
      unsigned char* pixels = grayImage.getPixels();

      ofxOscMessage m;
      m.setAddress("/human");
      m.addIntArg(pos.x);
      m.addIntArg(pos.y);
      m.addIntArg( pixels[int(width * pos.y + pos.x)] );

      humans.push_back(m);

      ofLogWarning() << "nBlobs:" << humans.size();


      //各々のOSC関数を呼び出す
      
    }

  }


}

//--------------------------------------------------------------
void ofApp::draw(){

  int width  = kinect.getWidth();
  int height = kinect.getHeight();

  binaryImage.draw(  0, 0, 320, 240);
  grayImage  .draw(320, 0, 320, 240);

 // for(int i = 0 ; i < contourfinder.nBlobs ; ++ i){
    contourfinder.draw(0, 0, 320, 240);


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
