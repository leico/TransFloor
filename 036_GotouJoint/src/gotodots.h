//
//  goto.h
//  emptyExample
//
//  Created by GotoRyota on 2015/12/01.
//
//

#ifndef gotodots_h
#define gotodots_h

#include "Base.h"

//Baseのクラスを受け継ぐ
class gotodots : public Base{
    
    vector < ofPoint > humans;

    ofSoundPlayer mm;
    
    //配列
    //int a[128];
    //可変長配列
    //vector < int > a(128);
    ofVec2f pos[200][200];
    //ofVec2f tec[1000];
    ofVec2f dig[200][200];
    int rag;
    int hueNum;
    int frameNum;

    
public:
    
    
    
    void setup(void){
        
        ofSetBackgroundAuto(true);
        ofSetBackgroundColor(0);
        ofSetWindowShape(1280, 720);
        
        /*
        mm.load("sei.mp3");
        mm.setVolume(1.0f);
        mm.setLoop(true);
        mm.play();
        */
         
        for(int y = 0 ; y < 200 ; ++ y){
            for(int x = 0 ; x < 200 ; ++ x){
                pos[x][y].x = x * 10;
                pos[x][y].y = y * 8;
            }
        }

        
    }
    void update(void){
    
        ofSoundUpdate();
        
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
        
        
       
        for (int j=0; j<humans.size(); ++j) {
         
            for (int x = 0; x < 200; ++ x) {
                
                for (int y =  0; y < 200; ++ y){
                    
                    dig[x][y].x = humans[j].x - pos[x][y].x;
                    dig[x][y].y = humans[j].y - pos[x][y].y;
                    
                    if(dig[x][y].x > 150 || dig[x][y].y >150){
                        dig[x][y].x = 0;
                        dig[x][y].y = 0;
                    }
                    if(dig[x][y].x < -150 || dig[x][y].y < -150){
                        dig[x][y].x = 0;
                        dig[x][y].y = 0;
                    }
                    dig[x][y].x = dig[x][y].x /8;
                    dig[x][y].y = dig[x][y].y /8;
                    
                }
            }

        
        }
        
        ofColor c;
        c.setHsb(hueNum, 255, 255,255);
        // 色を設定して正方形を描く
        ofSetColor( c );
        
        for (int x = 0; x < 200; ++x) {
            
                       for (int y =  0; y < 200; ++y){
                
            ofDrawCircle(pos[x][y].x+dig[x][y].x+ofNoise(x), pos[x][y].y+dig[x][y].y+ofNoise(y),3);
            
            }
            
            }
        
        
        int waru = frameNum%30;
        
        if(waru == 0){
            hueNum++;
        }
        if(hueNum >= 255){
            hueNum=0 ;
        }
        frameNum ++;
    
    }

};

#endif /* goto_h */
