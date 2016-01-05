//
//  mydraw.h
//  emptyExample
//
//  Created by LIFE_MAC25  on 2015/12/01.
//
//　　baribari

#ifndef mydraw_h
#define mydraw_h

#define HOST "localhost"
#define PORT 12346

#include "Base.h"

class baribari : public Base{
    
    vector <ofPoint> humans; //めっちゃ便利配列
    float * fftSmoothed;
    int nBandsToGet;
    
    
    ofSoundPlayer bari;
    
        float  angle;
    
public:
    
    void setup (void){
        ofBackground(0);
        ofSetBackgroundAuto(false);
        
        fftSmoothed = new float[8190];
        for(int i = 0; i < 8190; i++){ //8190
            fftSmoothed[i]=0;
        }
        nBandsToGet = 1;
        
        //Audioをロード
        
        bari.load("sound/baribari.wav");
        bari.setLoop(true);
        bari.play();
        
        

    }
//-----------------------------------------------------
    void update (void){
        
        
        // update the sound playing system:
        ofSoundUpdate();
        
        
        float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
        for (int i = 0; i < nBandsToGet; i++){
            
            // take the max, either the smoothed or the incoming:
            if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
            
            // let the smoothed calue sink to zero:
            fftSmoothed[i] *= 0.5f;
            
        }
     bari.setVolume(0.0f);
        
        angle += ofRandom(360) ;
        
    }
//-----------------------------------------------------
    void osc (vector <ofxOscMessage> &m){
        humans.resize( m.size());
        // /human x y z
        
        int j = 0;
        for(int i = 0; i < m.size() ; ++ i){
        
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
        
        int XX = 500;
        int R1 = ofRandom(10);
        int R2 = ofRandom(30);
        int R3 = ofRandom(100);
        int R4 = ofRandom(100);
        int R5 = ofRandom(100);
        int R6 = ofRandom(100);
        
        int pX ;
        int pY ;
        int pX2 ;
        int pY2 ;
        int pX3 ;
        int pY3 ;
        int pX4 ;
        int pY4 ;
        int pX5 ;
        int pY5 ;
        int pX6 ;
        int pY6 ;
        
        
        ofSetColor(0,1);
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

        
        for(int i = 0 ; i < humans.size(); ++ i ){
            
            ofSetColor(155+ofRandom(100),155+ofRandom(100),155+ofRandom(100));
            
            
    
            cout << humans[i].x/ofGetWidth() << endl;
            cout << humans[i].y/ofGetWidth() << endl;
            ofPushMatrix();
            
            ofTranslate(humans[i].x,humans[i].y);
            ofRotateZ(angle);
            
            ofSetColor(255);
            glLineWidth(2);
            
            
            
            pX = ofRandom(200);
            pY = ofRandom(100);
            glLineWidth(ofRandom(2,7));
            ofDrawLine(0,0,pX,pY);
            
            glLineWidth(2);
            pX2 = pX + ofRandom(200);
            pY2 = pY + ofRandom(100);
            ofDrawLine(pX,pY,pX2,pY2);
            
            pX3 = pX2 + ofRandom(200);
            pY3 = pY2 + ofRandom(200);
            ofDrawLine(pX2,pY2,pX3,pY3);
            
            pX4 = pX3 + ofRandom(200);
            pY4 = pY3 + ofRandom(200);
            ofDrawLine(pX3,pY3,pX4,pY4);
            
            pX5 = pX4 + ofRandom(200);
            pY5 = pY4 + ofRandom(200);
            ofDrawLine(pX4,pY4,pX5,pY5);
            
            pX6 = pX5 + ofRandom(300);
            pY6 = pY5 + ofRandom(300);
            ofDrawLine(pX5,pY5,pX6,pY6);
            
            ofDrawTriangle(0,0,pX,pY,10,0);
            ofDrawTriangle(pX,pY,pX2,pY2,pX+10,pY);
            
            glLineWidth(1);
            ofDrawLine(pX,pY,pX,pY+R3);
            
            ofDrawLine(0,0,pX,pY+R3);
            ofDrawLine(pX,pY+R3,pX2,pY2+R3);
            ofDrawLine(pX2,pY2+R3,pX3,pY3+R4);
            
            ofPopMatrix();
            
            if(humans.size() > 1) bari.setVolume(1.0f);
            bari.setSpeed  (0.2 * ofRandom(100) );
        }
}
};

#endif /* mydraw_h */
