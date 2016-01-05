//
//  tkm001.h
//  mySketch
//
//  Created by asamiTakami on 2015/11/26.
//
//

#include "Base.h"




class suuzi :public Base{
    
private:

    vector < ofPoint > humans;
    vector < ofPoint > humanA;
    vector < ofPoint > _humanA;
    vector < ofColor > col ;
    int framNUM;
    
    
    
public:
    
    
    
    
    
    void setup(void){
        
        for (int i = 0 ; i <= 50 ; i++){
        
        ofColor c;
        c.setHsb(ofRandom(150), 100, 255,200);
        col.push_back(c);
        framNUM=ofGetHeight()/5;
        
        
        
        }
        
        
    }
    
    
    
    
    
    
    
    
    void osc(vector<ofxOscMessage> &m){

        //if(m.size()>0){
        
        humans.resize(m.size());// m.size()でvectorの大きさ、resizeでサイズ変更
        int j = 0;
        
        for(int i = 0 ; i < m.size() ; ++i ){
            if(m[i].getAddress()== "/human"){
                
                humans[j].x = m[i].getArgAsInt32(0);
                humans[j].y = m[i].getArgAsInt32(1);
                humans[j].z = m[i].getArgAsInt32(2);
                
                ++j;
                
            }
            }
        //}
        
    
        
        
    }

    
  
    
    
    void update(void){
        
        if(framNUM == 0){
        framNUM=ofGetHeight();
      }
    framNUM--;
        
    }
    
    void draw(void){
        
        for (int i = 0 ; i < humans.size() ; i++){
            ofSetColor(col[i]);
            ofSetCircleResolution(i+3);
            ofDrawCircle(humans[i].x, humans[i].y, 30);
            
            }
        
      


    }




};

