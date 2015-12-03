//
//  ofmyDraw.h
//  emptyExample
//
//  Created by iamas_retina02 on 2015/12/01.
//
//

#ifndef ofmyDraw_h
#define ofmyDraw_h

#include "Base.h"

class ofmyDraw : public Base{
  
  vector< ofPoint > humans;
  
public:
  void setup (void){
    ofBackground(0);
  }
  void update(void){
  }
  void osc   (vector< ofxOscMessage > &m){
    humans.resize( m.size() );
    
    // "/human_x_y_z"
    for(int i = 0, j = 0 ; i < m.size() ; ++ i){
      
      if(m[i].getAddress() == "/human"){
        humans[j].x = m[i].getArgAsInt32(0);
        humans[j].y = m[i].getArgAsInt32(1);
        humans[j].z = m[i].getArgAsInt32(2);
        
        ++ j;
      }
    }
    
  }
  void draw  (void){
    
    ofSetColor(255);
    
    for(int i = 0 ; i < humans.size() ; ++ i){
      
      ofDrawCircle(humans[i].x, humans[i].y, 20);
    }
  }
};

#endif /* ofmyDraw_h */
