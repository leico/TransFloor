//
//  SecondScreen.cpp
//  emptyExample
//
//  Created by iamas_retina02 on 2015/11/30.
//
//

#include "SecondScreen.h"

void SecondScreen :: setup (void){};
void SecondScreen :: exit  (void){};
void SecondScreen :: update(void){};
void SecondScreen :: draw  (void){};

void SecondScreen :: keyPressed   (int key){

  if(key == 'f') ofToggleFullscreen();
  
};
void SecondScreen :: keyReleased  (int key){};
void SecondScreen :: mouseMoved   (int x, int y){};
void SecondScreen :: mouseDragged (int x, int y, int button){};
void SecondScreen :: mousePressed (int x, int y, int button){};
void SecondScreen :: mouseReleased(int x, int y, int button){};

void SecondScreen :: windowResized(int w, int h){};

void SecondScreen :: dragEvent (ofDragInfo dragInfo){};
void SecondScreen :: gotMessage(ofMessage msg){};

