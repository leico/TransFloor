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
class gotou : public Base{
    
    vector < ofPoint > humans;
    ofImage aaa01;
    ofImage aaa02;
    ofImage aaa03;
    ofImage aaa04;
    ofImage bbb01;
    ofImage bbb02;
    ofImage bbb03;
    ofImage bbb04;
    ofImage ccc01;
    ofImage ccc02;
    ofImage ccc03;
    ofImage ccc04;
    ofImage ddd01;
    ofImage ddd02;
    ofImage ddd03;
    ofImage ddd04;
    ofImage eee01;
    ofImage eee02;
    ofImage eee03;
    ofImage eee04;
    
    int hueNum;
    int i;
    int mode;
    int mun = 0;
    
    
    
    const static int SIZE_H = 780;
    const static int SIZE_W = 320;
    
public:
    
    
    
    void setup(void){
        
        
        aaa01.loadImage("aaa01.png");
        aaa02.loadImage("aaa02.png");
        aaa03.loadImage("aaa03.png");
        aaa04.loadImage("aaa04.png");
        bbb01.loadImage("bbb04.png");
        bbb03.loadImage("bbb03.png");
        bbb02.loadImage("bbb02.png");
        bbb04.loadImage("bbb04.png");
        
        ccc01.loadImage("ccc_01.png");
        ccc02.loadImage("ccc_02.png");
        ccc03.loadImage("ccc_03.png");
        ccc04.loadImage("ccc_04.png");
        ddd01.loadImage("ddd_01.png");
        ddd02.loadImage("ddd_02.png");
        ddd03.loadImage("ddd_03.png");
        ddd04.loadImage("ddd_04.png");
        eee01.loadImage("eee_01.png");
        eee02.loadImage("eee_02.png");
        eee03.loadImage("eee_03.png");
        eee04.loadImage("eee_04.png");
        
    }
    void update(void){
        //hueNum = ((ofGetFrameNum() % 6 == 0) ? hueNum + 1 : hueNum) % 256;
        
        i = ofGetFrameNum() % 1280;
        
        if(i <251){
            mode = 1;
        }else if(i < 501){
            mode = 2;
        }else if(i < 751){
            mode = 3;
        }else if(i < 1001){
            mode = 4;
        }else{
            mode = 5;
        }
        
        
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
        
      ofSetColor(225);
      
        ofPushMatrix();
        
        ofTranslate(0, 0, 0);
        
        mun = ofRandom(1,6);
        
        switch (mun) {
                
            case 1:
                aaa01.draw( 0 , 0 , SIZE_W , SIZE_H );
                break;
            case 2:
                bbb01.draw( 0 , 0 , SIZE_W , SIZE_H );
                break;
            case 3:
                ccc01.draw( 0 , 0 , SIZE_W , SIZE_H );
                break;
            case 4:
                ddd01.draw( 0 , 0 , SIZE_W , SIZE_H );
                break;
            case 5:
                eee01.draw( 0 , 0 , SIZE_W , SIZE_H );
                break;
                
            default:
                break;
        }
        
        
        //////////////////////////
        
        
        mun = ofRandom(1,6);
        
        switch (mun) {
                
            case 1:
                aaa02.draw( SIZE_W * 1 , 0 , SIZE_W , SIZE_H );
                break;
            case 2:
                bbb02.draw( SIZE_W * 1 , 0 , SIZE_W , SIZE_H );
                break;
            case 3:
                ccc02.draw( SIZE_W * 1 , 0 , SIZE_W , SIZE_H );
                break;
            case 4:
                ddd02.draw( SIZE_W * 1 , 0 , SIZE_W , SIZE_H );
                break;
            case 5:
                eee02.draw( SIZE_W * 1 , 0 , SIZE_W , SIZE_H );
                break;
                
            default:
                break;
        }

        //////////////////////////
        
        
        mun = ofRandom(1,6);
        
        switch (mun) {
                
            case 1:
                aaa03.draw( SIZE_W * 2 , 0 , SIZE_W , SIZE_H );
                break;
            case 2:
                bbb03.draw( SIZE_W * 2 , 0 , SIZE_W , SIZE_H );
                break;
            case 3:
                ccc03.draw( SIZE_W * 2 , 0 , SIZE_W , SIZE_H );
                break;
            case 4:
                ddd03.draw( SIZE_W * 2 , 0 , SIZE_W , SIZE_H );
                break;
            case 5:
                eee03.draw( SIZE_W * 2 , 0 , SIZE_W , SIZE_H );
                break;
                
            default:
                break;
        }
        
        
        //////////////////////////
        
        
        mun = ofRandom(1,6);
        
        switch (mun) {
                
            case 1:
                aaa04.draw( SIZE_W * 3 , 0 , SIZE_W , SIZE_H );
                break;
            case 2:
                bbb04.draw( SIZE_W * 3 , 0 , SIZE_W , SIZE_H );
                break;
            case 3:
                ccc04.draw( SIZE_W * 3 , 0 , SIZE_W , SIZE_H );
                break;
            case 4:
                ddd04.draw( SIZE_W * 3 , 0 , SIZE_W , SIZE_H );
                break;
            case 5:
                eee04.draw( SIZE_W * 3 , 0 , SIZE_W , SIZE_H );
                break;
                
            default:
                break;
        }
        
       
        ofPopMatrix();
        
        
        switch (mode) {
        
                case 1:
                
        for(int i = 0;i < humans.size();i++){

            if(humans[i].x >= SIZE_W * 0 && humans[i].x <= SIZE_W * 1){
        
                ofPushMatrix();
            
                ofTranslate(0, 0, 0);
        
                aaa01.draw( 0 , 0 , SIZE_W , SIZE_H );
                
                ofPopMatrix();
            }
            
            if(humans[i].x >= SIZE_W * 1 && humans[i].x <= SIZE_W * 2){
                
                ofPushMatrix();
                
                ofTranslate(SIZE_W * 1, 0, 0);
                
                aaa02.draw( 0 , 0 , SIZE_W , SIZE_H );
                
                ofPopMatrix();
            }
            
            if(humans[i].x >= SIZE_W * 2 && humans[i].x <= SIZE_W * 3){
                
                ofPushMatrix();
                
                ofTranslate(SIZE_W * 2, 0, 0);
                
                aaa03.draw( 0 , 0 , SIZE_W , SIZE_H );
                
                ofPopMatrix();
            }
            
            if(humans[i].x >= SIZE_W * 3 && humans[i].x <= SIZE_W * 4){
                
                ofPushMatrix();
                
                ofTranslate(SIZE_W * 3, 0, 0);
                
                aaa04.draw( 0 , 0 , SIZE_W , SIZE_H );
                
                ofPopMatrix();
            }
        }
            break;
         
        case 2:
            
            for(int i = 0;i < humans.size();i++){
                
                if(humans[i].x >= SIZE_W * 0 && humans[i].x <= SIZE_W * 1){
                    
                    ofPushMatrix();
                    
                    ofTranslate(0, 0, 0);
                    
                    bbb01.draw( 0 , 0 , SIZE_W , SIZE_H );
                    
                    ofPopMatrix();
                }
                
                if(humans[i].x >= SIZE_W * 1 && humans[i].x <= SIZE_W * 2){
                    
                    ofPushMatrix();
                    
                    ofTranslate(SIZE_W * 1, 0, 0);
                    
                    bbb02.draw( 0 , 0 , SIZE_W , SIZE_H );
                    
                    ofPopMatrix();
                }
                
                if(humans[i].x >= SIZE_W * 2 && humans[i].x <= SIZE_W * 3){
                    
                    ofPushMatrix();
                    
                    ofTranslate(SIZE_W * 2, 0, 0);
                    
                    bbb03.draw( 0 , 0 , SIZE_W , SIZE_H );
                    
                    ofPopMatrix();
                }
                
                if(humans[i].x >= SIZE_W * 3 && humans[i].x <= SIZE_W * 4){
                    
                    ofPushMatrix();
                    
                    ofTranslate(SIZE_W * 3, 0, 0);
                    
                    bbb04.draw( 0 , 0 , SIZE_W , SIZE_H );
                    
                    ofPopMatrix();
                }
            
            }
                break;

            case 3:
                
                for(int i = 0;i < humans.size();i++){
                    
                    if(humans[i].x >= SIZE_W * 0 && humans[i].x <= SIZE_W * 1){
                        
                        ofPushMatrix();
                        
                        ofTranslate(0, 0, 0);
                        
                        ccc01.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 1 && humans[i].x <= SIZE_W * 2){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 1, 0, 0);
                        
                        ccc02.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 2 && humans[i].x <= SIZE_W * 3){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 2, 0, 0);
                        
                        ccc03.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 3 && humans[i].x <= SIZE_W * 4){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 3, 0, 0);
                        
                        ccc04.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                }
                break;
                
            case 4:
                
                for(int i = 0;i < humans.size();i++){
                    
                    if(humans[i].x >= SIZE_W * 0 && humans[i].x <= SIZE_W * 1){
                        
                        ofPushMatrix();
                        
                        ofTranslate(0, 0, 0);
                        
                        ddd01.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 1 && humans[i].x <= SIZE_W * 2){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 1, 0, 0);
                        
                        ddd02.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 2 && humans[i].x <= SIZE_W * 3){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 2, 0, 0);
                        
                        ddd03.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 3 && humans[i].x <= SIZE_W * 4){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 3, 0, 0);
                        
                        ddd04.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                }
                break;
                
            case 5:
                
                for(int i = 0;i < humans.size();i++){
                    
                    if(humans[i].x >= SIZE_W * 0 && humans[i].x <= SIZE_W * 1){
                        
                        ofPushMatrix();
                        
                        ofTranslate(0, 0, 0);
                        
                        eee01.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 1 && humans[i].x <= SIZE_W * 2){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 1, 0, 0);
                        
                        eee02.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 2 && humans[i].x <= SIZE_W * 3){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 2, 0, 0);
                        
                        eee03.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                    if(humans[i].x >= SIZE_W * 3 && humans[i].x <= SIZE_W * 4){
                        
                        ofPushMatrix();
                        
                        ofTranslate(SIZE_W * 3, 0, 0);
                        
                        eee04.draw( 0 , 0 , SIZE_W , SIZE_H );
                        
                        ofPopMatrix();
                    }
                    
                }
                break;
                
            default:
                break;
            
        }
        }
};

#endif /* goto_h */
