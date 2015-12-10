//
//  tkmOTO.h
//  mySketch
//
//  Created by asamiTakami on 2015/11/26.
//
//

#ifndef __mySketch__tkmOTO__
#define __mySketch__tkmOTO__

#include "Base.h"
#include "particle.h"




class tkmOTO :public Base{
    
private:
    ofPoint pos[5];
    int rag;
    int hueNum;
    int frameNum;
    int frameNumA;
    vector < ofPoint > humans; //vector 可変長配列　超便利配列！
    
    vector < ofPoint > humansB;
    
    
    vector< Particle > particles ;
    
    
    vector< ofColor > col;
    vector< float > kaiten ;
    // メッシュ
    //ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    // パーティクルの数
    static const int NUM = 30;
    ofSoundPlayer ppi,ppi2,ppi3,ppi4;
    
    
public:
    
    
    
    
    
    void setup(void){
        
        rag=0;
        hueNum=0;
        ofSetBackgroundAuto(true);
        
        
        ppi.load("sounds/b_068.aiff");
        ppi.setVolume(0.75f);
        ppi.setMultiPlay(true);
        ppi2.load("sounds/b_068.aiff");
        ppi2.setVolume(0.75f);
        ppi2.setMultiPlay(true);
        ppi2.setSpeed(0.8);
        ppi3.load("sounds/b_068.aiff");
        ppi3.setVolume(0.75f);
        ppi3.setMultiPlay(true);
        ppi3.setSpeed(0.5);
        ppi4.load("sounds/b_068.aiff");
        ppi4.setVolume(0.75f);
        ppi4.setMultiPlay(true);
        ppi4.setSpeed(1.2);
        
        
        //ppi.play();
        
        
        
        // メッシュを点で描画
        //mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
        //glPointSize(2.0);
        
        for (int i = 0; i < NUM; i++) {
            ofColor c;
             c.setHsb(ofRandom(150), 180, 255,255);
             
             col.push_back(c);
            
            
            float k = ofRandom(360);
            kaiten.push_back(k);
            
            
            
            
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    void osc(vector<ofxOscMessage> &m){
        

        
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
    }

    
    
    
    void update(void){
        
        ofSoundUpdate();
        
        if (humans.size() >= 1)
        {
            humansB.resize(humans.size());
            for (int j = 0; j < humans.size(); j++){
                
                humansB[j]=humans[j];
            }
           
            
    for (int i = 0; i < particles.size(); i++){
           // パーティクルの数だけ計算
       for (int j = 0; j < humans.size(); j++){
       
       
            // 力をリセット
            particles[i].resetForce();
            //反発
                particles[i].addRepulsionForce(humansB[j].x, humansB[j].y, 300, 0.3);
          
               particles[i].addAttractionForce(particles[j], 120.0, 0.01);
           
            // パーティクル更新
            particles[i].update();
            // 画面の端にきたら跳ね返る
            particles[i].bounceOffWalls();
           //画面の端に来たら音がなる
           particles[i].soundOfWalls(ppi,ppi2,ppi3,ppi4);
            
            
        }
           
         
       }
        
        
        
        
        int waru = frameNum % 6;
        
        if(waru == 0){
            hueNum++;
        }
        if(hueNum >= 255){
            hueNum=0 ;
        }
        frameNum ++;
        frameNumA ++;
        
    }
    

    }
    
    
    
    void draw(void){
        
        ofFill();
        if(humans.size() == 0)ofNoFill();
        //mesh.clear();
        for (int i = 0; i < particles.size(); i++) {
            
            ofSetColor(col[i]);
            ofPushMatrix();
            
            ofTranslate(particles[i].position.x, particles[i].position.y);
            //ofSetColor(col[i]);
            ofRotateZ(ofGetFrameNum()+kaiten[i]);
            
            if(i <= particles.size()/3){
            ofDrawRectangle(0, 0, 40, 40);
              
            }
            
            if(i > particles.size()/3 && i < particles.size()*2/3){
                ofSetCircleResolution(64);
                ofDrawCircle(0,0,20);
            }
            
            if(i >= particles.size()*2/3){
             ofSetCircleResolution(3);
                ofDrawCircle(0, 0, 32);
            }
            
            
            //mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
            
            ofPopMatrix();
        }
       // mesh.draw();
    
   
    for(int j = 0 ; j < humansB.size() ; j++){
        ofSetColor(255);
        ofNoFill();
    ofSetCircleResolution(ofRandom(3,10));
    ofDrawCircle(humansB[j].x, humansB[j].y, 30);
        
    }
    
    
    
    

    }


    



};


#endif /* defined(__mySketch__tkmOTO__) */
