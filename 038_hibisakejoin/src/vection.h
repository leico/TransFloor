//
//  vection.h
//  emptyExample
//
//  Created by GotoRyota on 2015/12/01.
//
//

#ifndef vection_h
#define vection_h

#include "Base.h"

//Baseのクラスを受け継ぐ
class vection : public Base{
    
    vector < ofPoint > bottom;
    vector < ofPoint > top;
    const static int NUM   = 40;
    const static int WIDTH = 10;
    
    const static float DIFF;
  
public:
    
    
    void setup(void){
    
        ofSetLineWidth( WIDTH );
        bottom.resize(NUM);
        top   .resize(NUM);
        
        for(int i = 0 ; i < NUM ; ++ i){
            bottom[i].x = ofGetWidth() / NUM * i + WIDTH;
            bottom[i].y = ofGetHeight();
            top   [i].x = ofGetWidth() / NUM * i + WIDTH;
            top   [i].y = 0;
        }
        
        
        
    }

    void osc (vector <ofxOscMessage> &m){

    }
    
    void update(void){
        
//        if(ofGetFrameNum() % 10 != 0) return;
        
        for(int i = 0 ; i < NUM ; ++ i){
            int basepos = ofGetWidth() / NUM * i + WIDTH;
            bottom[i].x = ofClamp(bottom[i].x + ofRandom(-DIFF, DIFF), basepos - WIDTH, basepos + WIDTH);
            top   [i].x = ofClamp(top   [i].x + ofRandom(-DIFF, DIFF), basepos - WIDTH, basepos + WIDTH);
        }
 
    }
    
    
    
    void draw  (void){
        for(int i = 0 ; i < NUM ; ++ i){
            ofDrawLine(top[i], bottom[i]);
        }
    }
    
};

const float vection :: DIFF = 0.2;

#endif /* vection_h */
