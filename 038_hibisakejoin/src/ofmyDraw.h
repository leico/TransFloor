//
//  ofmyDraw.h
//  emptyExample
//
//  Created by iamas_retina02 on 2015/12/01.
//
//

#ifndef ofmyDraw_h
#define ofmyDraw_h

#include "Base.h"


class ofmyDraw : public Base{
  
  vector< ofPoint > humans;
    int ctr;
    double pre_x,pre_y;
  
public:
  void setup (void){
      //ofSetWindowShape(1280, 720);
      ofBackground(192);
      pre_x = 0.0;
      pre_y = 0.0;
    
  }
  void update(void){
  }
  void osc   (vector< ofxOscMessage > &m){
    humans.resize( m.size() );
    
    // "/human_x_y_z"
    for(int i = 0, j = 0 ; i < m.size() ; ++ i){
      
      if(m[i].getAddress() == "/human"){
        humans[j].x = m[i].getArgAsInt32(0);
        humans[j].y = m[i].getArgAsInt32(1);
        humans[j].z = m[i].getArgAsInt32(2);
        
        ++ j;
      }
    }
    
  }
  void draw  (void){
      ofSetCircleResolution(64);
      
      float rCentor_x =ofGetWindowWidth()*5/7;
      float lCentor_x =ofGetWindowWidth()*2/7;
      float rCentor_y =ofGetWindowHeight()/2;
      float lCentor_y =ofGetWindowHeight()/2;
      float eyeSize = ofGetWindowWidth()/6;
      float eyeSize2 = ofGetWindowWidth()/10;
      float lineWidth = ofGetWindowWidth()/40;
      float eyePosLen =eyeSize-eyeSize2-lineWidth/2;
      
      
      double drection_rx , drection_ry , drection_lx , drection_ly;
      double angle_r , angle_l;
      
    

      
      bool flug = false;
      double tgt_x,tgt_y;
      tgt_x = pre_x;
      tgt_y = pre_y;
      for(int i = 0 ; i < humans.size() ; ++ i){
          flug = true;
          if(i==0){
              tgt_x = humans[i].x;
              tgt_y = humans[i].y;
          }else{
              double length_c,length_p;
              length_p = pow((pre_x - tgt_x),2.0) + pow((pre_y - tgt_y),2.0);
              length_c = pow((pre_x - humans[i].x),2.0) + pow((pre_y - humans[i].y),2.0);
              if(length_p>length_c){
                  tgt_x = humans[i].x;
                  tgt_y = humans[i].y;
              }
          }
      }
      
      pre_x = tgt_x;
      pre_y = tgt_y;
      
      if(flug){
          bool near_r = false;
          bool near_l = false;
          bool center = false;
          //////////////////////////////////////////////////////////////////          
          for(int i = 0  ;i <humans.size(); ++ i){
              double length_e;
              length_e = sqrt(pow((humans[i].x - rCentor_x),2.0) + pow((humans[i].y - rCentor_y),2.0));
              if(length_e < eyeSize){
                  near_r = true;
              }
              length_e = sqrt(pow((humans[i].x - lCentor_x),2.0) + pow((humans[i].y - lCentor_y),2.0));
              if(length_e < eyeSize){
                  near_l = true;
              }
          }
          
          if(   lCentor_x + eyeSize < tgt_x
             && tgt_x < rCentor_x - eyeSize
             && rCentor_y - eyeSize < tgt_y
             && tgt_y < rCentor_y + eyeSize
             ){
              center=true;
          }
          //////////////////////////////////////////////////////////////////
//          int mx = ofGetMouseX();
//          int my = ofGetMouseY();
//          
//          double length_e;
//          length_e = sqrt(pow((mx - rCentor_x),2.0) + pow((my - rCentor_y),2.0));
//          if(length_e < eyeSize){
//              near_r = true;
//          }
//          length_e = sqrt(pow((mx - lCentor_x),2.0) + pow((my - lCentor_y),2.0));
//          if(length_e < eyeSize){
//              near_l = true;
//          }
//          if(  (lCentor_x + eyeSize < mx)
//             && (mx < rCentor_x - eyeSize)
//             && (rCentor_y - eyeSize < my)
//             && (my < rCentor_y + eyeSize)
//             ){
//              center=true;
//          }
//          
          //////////////////////////////////////////////////////////////////
          drection_rx = tgt_x - rCentor_x;
          drection_ry = tgt_y - rCentor_y;
          drection_lx = tgt_x - lCentor_x;
          drection_ly = tgt_y - lCentor_y;
          //////////////////////////////////////////////////////////////////
//          drection_rx = mx - rCentor_x;
//          drection_ry = my - rCentor_y;
//          drection_lx = mx - lCentor_x;
//          drection_ly = my - lCentor_y;
          //////////////////////////////////////////////////////////////////
          if(near_r){
              ofSetColor(0,0,0);
              //ofDrawRectangle(rCentor_x-eyeSize, rCentor_y-lineWidth/2, eyeSize*2, lineWidth);
              ofSetLineWidth(lineWidth);
              ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y);
              ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y - eyeSize/3);
              ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y + eyeSize/3);
              
          }else{
              ofSetColor(0,0,0);
              ofFill();
              ofDrawCircle(rCentor_x, rCentor_y, eyeSize);
              ofSetColor(255,255,255);
              ofFill();
              ofDrawCircle(rCentor_x, rCentor_y, eyeSize - lineWidth);
              
              angle_r = -(atan2(drection_rx,drection_ry)-pi/2);
              ofSetColor(0,0,0);
              ofFill();
              ofDrawCircle(rCentor_x + cos(angle_r)*eyePosLen , rCentor_y + sin(angle_r)*eyePosLen, eyeSize2);

          }
          if(near_l){
              ofSetColor(0,0,0);
              ofSetLineWidth(lineWidth);
              ofDrawLine(lCentor_x-eyeSize, lCentor_y, lCentor_x + eyeSize, lCentor_y);
              ofDrawLine(lCentor_x-eyeSize, lCentor_y - eyeSize/3, lCentor_x + eyeSize, lCentor_y);
              ofDrawLine(lCentor_x-eyeSize, lCentor_y + eyeSize/3, lCentor_x + eyeSize, lCentor_y);
              
              
          }else{
              ofSetColor(0,0,0);
              ofFill();
              ofDrawCircle(lCentor_x, lCentor_y, eyeSize);
              ofSetColor(255,255,255);
              ofFill();
              ofDrawCircle(lCentor_x, lCentor_y, eyeSize - lineWidth);
              
              angle_l = -(atan2(drection_lx,drection_ly)-pi/2);
              ofSetColor(0,0,0);
              ofFill();
              ofDrawCircle(lCentor_x + cos(angle_l)*eyePosLen , lCentor_y + sin(angle_l)*eyePosLen, eyeSize2);
              
          }
          if(center){
              ofSetColor(0,0,0);
              ofSetLineWidth(lineWidth);
              ofDrawLine(ofGetWindowWidth()/2, (ofGetWindowHeight()/2)-ofGetWindowHeight()/20, ofGetWindowWidth()/2, (ofGetWindowHeight()/2)+ofGetWindowHeight()/20);
              
              ofDrawLine((ofGetWindowWidth()/2)- ofGetWindowWidth()/30, (ofGetWindowHeight()/2)-ofGetWindowHeight()/20, (ofGetWindowWidth()/2)- ofGetWindowWidth()/30, (ofGetWindowHeight()/2)+ ofGetWindowHeight()/20);
              
              ofDrawLine((ofGetWindowWidth()/2)+ ofGetWindowWidth()/30, (ofGetWindowHeight()/2)-ofGetWindowHeight()/20, (ofGetWindowWidth()/2)+ ofGetWindowWidth()/30, (ofGetWindowHeight()/2)+ofGetWindowHeight()/20);
              
          }
          
      }else{
        ofSetColor(0,0,0);
        //ofDrawRectangle(rCentor_x-eyeSize, rCentor_y-lineWidth/2, eyeSize*2, lineWidth);
        ofSetLineWidth(lineWidth);
        ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y);
        ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y - eyeSize/3);
        ofDrawLine(rCentor_x-eyeSize, rCentor_y, rCentor_x + eyeSize, rCentor_y + eyeSize/3);

        ofDrawLine(lCentor_x-eyeSize, lCentor_y, lCentor_x + eyeSize, lCentor_y);
        ofDrawLine(lCentor_x-eyeSize, lCentor_y - eyeSize/3, lCentor_x + eyeSize, lCentor_y);
        ofDrawLine(lCentor_x-eyeSize, lCentor_y + eyeSize/3, lCentor_x + eyeSize, lCentor_y);
        

      }
  }
};

#endif /* ofmyDraw_h */
