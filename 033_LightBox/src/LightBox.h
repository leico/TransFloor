//
//  goto.h
//  emptyExample
//
//  Created by GotoRyota on 2015/12/01.
//
//

#ifndef goto_h
#define goto_h

#include "Base.h"


//Baseのクラスを受け継ぐ
class LightBox : public Base{
    
    vector < ofPoint > humans;
    vector < ofLight > lights;
    //配列
    //int a[128];
    //可変長配列
    //vector < int > a(128);
    
    int x,y;
    int hueNum;
    int frameNum;
    
    ofLight light;
    ofBoxPrimitive Box;
    
    
    
public:
  
  virtual ~LightBox(){
    for(int i = 0 ; i < lights.size() ; ++ i)
      lights[i].disable();
    
    ofDisableDepthTest();
  }
    
    
    
    void setup(void){
        
        ofEnableDepthTest();
        
        ofEnableSmoothing();
        
        
        ofSetFrameRate(60);
        ofBackground(0);
/*
        light.enable();
        light.setSpotlight();
        light.setPosition(100, 100, 100);
        light.setAmbientColor(ofFloatColor(0.5,0.2,0.2,1.0));
        light.setDiffuseColor(ofFloatColor(0.5,0.5,1.0));
        light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
*/
        lights.resize(1024);
        lights.clear();
        
        /*
        for(int y = 0 ; y < 200 ; ++ y){
            for(int x = 0 ; x < 200 ; ++ x){
                pos[x][y].x = x * 10;
                pos[x][y].y = y * 8;
            }
        }

        */
        
    }
    void update(void){
        
        
    }
    void osc (vector <ofxOscMessage> &m){
        humans.resize(m.size()/*vectorの中の大きさの確認*/);
        lights.clear();
        
        int j = 0;
        
        // "/human_x_y_z"
        for (int i=0; i<m.size(); ++i) {
            
            if(m[i].getAddress() == "/human"){
                humans[j].x = m[i].getArgAsInt32(0);
                humans[j].y = m[i].getArgAsInt32(1);
                humans[j].z = m[i].getArgAsInt32(2);
                
                ++j;
                
                lights.push_back( ofLight() );
                
                vector <ofLight> :: iterator it = (lights.end() - 1);
                
                it -> enable();
                it -> setSpotlight();
                it -> setPosition(humans[j].x, humans[j].y, humans[j].z * 10);
                it -> setAmbientColor(ofFloatColor(0.5,0.2,0.2,1.0));
                it -> setDiffuseColor(ofFloatColor(0.5,0.5,1.0));
                it -> setSpecularColor(ofFloatColor(1.0,1.0,1.0));

            }
        }
    }
    void draw  (void){
/*
        for(int i =0;i<humans.size();i++){
            
            light.enable();
            light.setSpotlight();
            light.setPosition(humans[i].x, humans[i].y, 300);
            light.setAmbientColor(ofFloatColor(0.5,0.2,0.2,1.0));
            light.setDiffuseColor(ofFloatColor(0.5,0.5,1.0));
            light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
            
        }
*/
        
        
        for(int x = 0 ; x < 10 ; ++ x){
        for(int y = 0 ; y < 10 ; ++ y){
            
            Box.set(100);
            Box.setPosition(x*200,y*200,0);
            Box.rotate(sin(x), 1.0, 0.0, 0.0);
            Box.rotate(cos(y), 0, 1.0, 0.0);
            
            ofSetColor(200);
            
            Box.draw();
        }
        }

        //Box.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
        
       // Box.rotate(ofNoise(10), 1.0, 0.0, 0.0);
        //Box.rotate(ofNoise(10), 0, 1.0, 0.0);
        
        
       // Box.draw();
        
        
    }
};

#endif /* goto_h */
