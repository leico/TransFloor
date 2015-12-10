//
//  Gushi01.h
//  emptyExample
//
//  Created by LIFE_MAC25  on 2015/12/01.
//
//　　curve draw

#ifndef Gushi01_h
#define Gushi01_h

#define HOST "localhost"
#define PORT 12346

#include "Base.h"

class Gushi01 : public Base{
    
    vector <ofPoint> humans; //めっちゃ便利配列
    
    ofxOscSender sender;
  
    ofSoundPlayer curve;
  
  int num;
  
public:
    
    void setup (void){
        ofBackground(0);
        ofFill();
        
        //sender.setup(HOST,PORT);
        
        //audioをロード
        curve.load("sound/curve.wav");
        curve.setLoop(true);
        curve.play();
      
      humans.resize(1024);
      
        ofSetVerticalSync(true);
        ofSetCircleResolution(32);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
    }
//-----------------------------------------------------
    void update (void){
        ofBackground(0);
        // update the sound playing system:
      
        curve.setVolume(0.0f);
    }
//-----------------------------------------------------
    void osc (vector <ofxOscMessage> &m){
        // /human x y z
      
      num = m.size();
      
        int j = 0;
        for(int i = 0; i < num ; ++ i){
        
            if(m[i].getAddress() == "/human"){
                humans[j].x = m[i].getArgAsInt32(0);
                humans[j].y = m[i].getArgAsInt32(1);
                humans[j].z = m[i].getArgAsInt32(2);
              
                ++ j;
            }
        }

    }
//------------------------------------------------------
    void draw (void){
        
        
        ofSetColor(255);
      
        for(int i = 0 ; i < num ; ++ i ){
            ofSetColor(ofRandom(100,255),ofRandom(100,255),ofRandom(100,255));
            
            
            glLineWidth(ofRandom(6));
            ofDrawLine(humans[i].x+ofRandom(30),humans[i].y+ofRandom(30),
                       humans[i+1].x+ofRandom(30),humans[i+1].y+ofRandom(30));

            ofSetColor(ofRandom(100,255),ofRandom(100,255),ofRandom(100,255));
            ofDrawBezier(humans[i+2].x+ofRandom(30),humans[i+2].y+ofRandom(30),
                         humans[i+3].x+ofRandom(30),humans[i+3].y+ofRandom(30),
                         humans[i].x+ofRandom(30),humans[i].y+ofRandom(30),
                         humans[i+1].x+ofRandom(30),humans[i+1].y+ofRandom(30));
            
            ofSetColor(ofRandom(200,255),ofRandom(200,255),ofRandom(200,255));
            ofDrawBezier(humans[i].x+ofRandom(30),humans[i].y+ofRandom(30),
                         humans[i+1].x+ofRandom(30),humans[i+1].y+ofRandom(30),
                         humans[i+3].x+ofRandom(30),humans[i+3].y+ofRandom(30),
                         humans[i+2].x+ofRandom(30),humans[i+2].y+ofRandom(30));
            
            if(humans.size()>2)(curve.setVolume(0.5f),
                                curve.setSpeed(1.0f * (humans[i].x/humans[i+1].x)));
            
        }
    

            }
    
};

#endif /* Gushi01_h */
