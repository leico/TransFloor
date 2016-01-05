//
//  ossya.h
//  emptyExample
//
//  Created by LIFE_MAC25  on 2015/12/01.
//
//　　ランダムドット

#ifndef ossya_h
#define ossya_h

#define HOST "localhost"
#define PORT 12346

#include "Base.h"

class ossya : public Base{
    
    vector <ofPoint> humans; //めっちゃ便利配列
    float * fftSmoothed;
    int nBandsToGet;
    
    
    ofSoundPlayer dragon;
    ofSoundPlayer dragon2;
    

    
public:
    
    void setup (void){
        ofBackground(0);
        
        fftSmoothed = new float[8190];
        for(int i = 0; i < 8190; i++){ //8190
            fftSmoothed[i]=0;
        }
        nBandsToGet = 1;
        
        //Audioをロード
        
        dragon.load("sound/dragon.wav");
        dragon.setLoop(true);
        dragon.play();
        dragon2.load("sound/dragon2.wav");
        dragon2.setLoop(true);
        dragon2.play();
        

    }
//-----------------------------------------------------
    void update (void){
        
        ofBackground(0,0,0);
        
        // update the sound playing system:
        ofSoundUpdate();
        
        
        float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
        for (int i = 0; i < nBandsToGet; i++){
            
            // take the max, either the smoothed or the incoming:
            if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
            
            // let the smoothed calue sink to zero:
            fftSmoothed[i] *= 0.5f;
            
        }
     dragon.setVolume(0.0f);
     dragon2.setVolume(0.0f);
        
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
        
        float vv = fftSmoothed[0];
        //cout << vv << endl;
        
        
        for(int i = 0 ; i < humans.size(); ++ i ){
            ofSetColor(155+ofRandom(100),155+ofRandom(100),155+ofRandom(100));
            
            if(humans.size() > 1) dragon.setVolume(0.8f);
            if(humans.size() > 2) dragon2.setVolume(0.8f);
            
            dragon.setSpeed  (0.5 * (humans[i].  x/ofGetWidth())   );
            dragon2.setSpeed (0.5 * (humans[i+2].x/ofGetWidth())   );
            
            
            glLineWidth(vv*800);
            ofDrawLine(0,             humans[i].y+ofRandom(30),
                       ofGetWidth(),  humans[i].y+ofRandom(30));
        
        
            glLineWidth(vv*700);
            ofDrawLine(0,                 humans[i].y+ofRandom(50),
                        ofGetWidth(),     humans[i].y+ofRandom(50));
           
        }
}
};

#endif /* ossya_h */
