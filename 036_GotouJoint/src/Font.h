//
//  Font.h
//  emptyExample
//
//  Created by GotoRyota on 2015/12/01.
//
//

#ifndef Font_h
#define Font_h

#include "Base.h"

//Baseのクラスを受け継ぐ
class Font : public Base{
    
    vector < ofPoint > humans;
    ofImage trans;
    
    int hueNum;
    
    const static int SIZE = 300;

    
public:
    
    
    
    void setup(void){
        
        trans.load("トランス.png");
        
    }
    void update(void){
        hueNum = ((ofGetFrameNum() % 6 == 0) ? hueNum + 1 : hueNum) % 256;
        
    }
    void osc (vector <ofxOscMessage> &m){
        humans.resize(m.size());   //vectorの中の大きさの確認
        
        int j = 0;
        
        // "/human_x_y_z"
        for (int i=0; i<m.size(); ++i) {
            
            if(m[i].getAddress() == "/human"){
                humans[j].x = m[i].getArgAsInt32(0);
                humans[j].y = m[i].getArgAsInt32(1);
                humans[j].z = m[i].getArgAsInt32(2);
                
                ++j;
            }
        }
    }
    
    void draw  (void){
        
        
        for(int i = 0; i < humans.size(); i++){

            ofPushMatrix();
            
                ofTranslate(humans[i].x, humans[i].y, 0);
                ofRotate(ofGetFrameNum() % 360);
            
                ofSetColor( ofColor :: fromHsb(hueNum, 255, 255) );
                trans.draw( 0 - SIZE / 2 , 0 - SIZE / 2 , SIZE , SIZE );
            
            ofPopMatrix();

            
        }
    }
};

#endif /* Font_h */
