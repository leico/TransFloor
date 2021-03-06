//
//  buuun.h
//  emptyExample
//
//  Created by LIFE_MAC25  on 2015/12/01.
//
//　　ランダムドット

#ifndef buuun_h
#define buuun_h

#define HOST "localhost"
#define PORT 12346

#include "Base.h"

class buuun : public Base{
    
    vector <ofPoint> humans; //めっちゃ便利配列
    float * fftSmoothed;
    int nBandsToGet;
    
    //ofxOscSender sender;
    
    ofSoundPlayer buun; //トラック

    
public:
    
    void setup (void){
        ofBackground(0);
        
        //sender.setup(HOST,PORT);
        
        fftSmoothed = new float[8190];
        for(int i = 0; i < 8190; i++){ //8190
            fftSmoothed[i]=0;
        }
        nBandsToGet = 1;
        
        //Audioをロード
        buun.load("sound/buun.wav");
        buun.setMultiPlay(true);
        

        
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
            fftSmoothed[i] *= 0.8f;
            
        }
        buun.setVolume (0.8f);

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
        static long c = 0;
        const int cmax = 2;
        const int th = 20;
        
        //cout << fftSmoothed[0] << endl;
        float vv = fftSmoothed[0];
            
        
        for(int i = 0 ; i < humans.size(); ++ i ){
          
            ofSetColor(255,80);
            glLineWidth(5);
            ofDrawLine(0,ofGetHeight()/2 + vv*300 ,ofGetWidth(),ofGetHeight()/2 + vv*300);
            
            if((ofGetHeight()/2 - th < humans[i].y)&&(humans[i].y < ofGetHeight()/2 + th)) {
                if( c <= 0 ) {
                buun.setSpeed(1.0 +3.0 * (   humans[i].x/ofGetWidth()  )   );
               buun.play();
                    c++;
                } else if( ++c > cmax )
                    c = 0;
            }
            
        }
}
};

#endif /* buuun_h */
