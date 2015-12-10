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
  
    int hueNum;
//    vector < ofPoint > humans; //vector 可変長配列　超便利配列！
  
  list <ofPoint> humans;
  list <ofColor> colors;
  
  const static int LOG = 2048;
  
    
    
public:
    
    
    
    
    
    void setup(void){
      
        hueNum=0;
        //ofSetBackgroundAuto(false);
        
        
    }
    
    
    
    
    
    
    
    
    void osc(vector<ofxOscMessage> &m){
        
        /*
         
         int size = (m.size() > 5) ? 5 : m.size();
         
         for(int i = 0 ; i < size ; i++){
         if(m[i].getAddress()=="/human"){
         m[i].getArgAsInt32(0);//X
         m[i].getArgAsInt32(1);//Y
         m[i].getArgAsInt32(2);//Z
         
         pos[i].set(m[i].getArgAsInt32(0),m[i].getArgAsInt32(1),m[i].getArgAsInt32(2));
         
         }*/
        
        
        //humans.resize(m.size());// m.size()でvectorの大きさ、resizeでサイズ変更
        int j = 0;
        for(int i = 0 ; i < m.size() ; ++i ){
            if(m[i].getAddress()== "/human"){
              
              humans.push_back(
                ofPoint(
                    m[i].getArgAsInt32(0)
                  , m[i].getArgAsInt32(1)
                  , m[i].getArgAsInt32(2)
                )
              );
              
              ofColor c;
              c.setHsb(hueNum, 255, 255, 200);
              colors.push_back(c);
 
            }
        }
    }

    
  
    
    
    void update(void){
        
      
      hueNum = ((ofGetFrameNum() % 6 == 0) ? hueNum + 1 : hueNum) % 256;
      
      while(humans.size() > LOG){
        humans.pop_front();
        colors.pop_front();
      }
      
    }
    

    
    
    
    
    void draw(void){
      
      list<ofPoint> :: iterator it;
      list<ofColor> :: iterator cit;
        
        
      for(it  = humans.begin(), cit = colors.begin() ; it != humans.end() ; ++ it, ++ cit){
        ofSetColor(*cit);
        ofPushMatrix();
        
           ofTranslate( it -> x, it -> y, it -> z);
           int z = it -> z;
           
           ofFill();
        
           ofDrawCircle(0, 0, z/6);
           ofPopMatrix();

           
      }
        
    }
   
    









};


#endif /* defined(__mySketch__tkm001__) */
