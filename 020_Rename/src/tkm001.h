//
//  tkm001.h
//  mySketch
//
//  Created by asamiTakami on 2015/11/26.
//
//

#ifndef __mySketch__tkm001__
#define __mySketch__tkm001__

#include "Base.h"




class tkm001 :public Base{

  private:
    ofPoint pos[5];
    int rag;
    int hueNum;
    int frameNum;
  
  vector<ofPoint> humans;


  public:


    /* =============================================== *
     * setup(void)                                     *
     * =============================================== */
    void setup(void){

      rag   =0;
      hueNum=0;

      ofSetBackgroundAuto(false);

    }

    /* =============================================== *
     * update(void)                                    *
     * =============================================== */
    void update(void){

    }

    /* =============================================== *
     * osc(vector<ofxOscMessage> &m)                   *
     * =============================================== */
    void osc(vector<ofxOscMessage> &m){
      
      
      humans.resize( m.size() );
      
      for(int i = 0 ; i < m.size() ; ++ i){
        humans[i].x = m[i].getArgAsInt32(0);
        humans[i].y = m[i].getArgAsInt32(1);
        humans[i].z = m[i].getArgAsInt32(2);
      }
/*
      int size = (m.size() > 5) ? 5 : m.size();

      for(int i = 0 ; i < size ; i++){
        if(m[i].getAddress()=="/human"){
          m[i].getArgAsInt32(0);//X
          m[i].getArgAsInt32(1);//Y
          m[i].getArgAsInt32(2);//Z

          pos[i].set(m[i].getArgAsInt32(0),m[i].getArgAsInt32(1),m[i].getArgAsInt32(2));

        }
      }
*/
    }

    /* =============================================== *
     * draw(void)                                      *
     * =============================================== */
    void draw(void){



      ofColor c;
      // iとjの値を、０〜２５５間にマッピング
      //ofMaps(x.a.b.c.d): a~b間でのxの値を、c~d間に写像する。　a:b:x=c:d:f(x)
      c.setHsb(hueNum, 255, 255,255);

      // 色を設定して正方形を描く
      ofSetColor( c );

      for(int i = 0 ;i < humans.size() ;i ++){

        ofPushMatrix();



        ofTranslate(humans[i].x, humans[i].y);
        int z = pos[i].z;



        ofFill();
        ofDrawTriangle(ofRandom(-50,0), ofRandom(-50,0), ofRandom(-25,25), ofRandom(0,50), ofRandom(0,50), ofRandom(-50,0));



        ofPopMatrix();





      }

      int waru = frameNum%6;

      if(waru == 0){
        hueNum++;
      }
      if(hueNum >= 255){
        hueNum=0 ;
      }
      frameNum ++;
    }




};


#endif /* defined(__mySketch__tkm001__) */
