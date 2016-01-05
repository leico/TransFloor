

#include "Base.h"
#include "Particle.h"




class flyaway:public Base{
private:

    vector < ofPoint > humans;
    vector < ofPoint > humanA;
    vector < ofPoint > _humanA;
    vector < ofColor > col ;
    int framNUM;
    ofImage gazou;
    
    //ofPoint yazirusi;
    vector <ofPoint> bekutoru;
    vector <Particle> yazirusi;
    static const int NUM = 100;
    int a;
    
public:
    
    
    
    
    
    void setup(void){
      
      //ofSetBackgroundAuto(true);
        for (int i = 0 ; i <= 50 ; i++){
        
        ofColor c;
        c.setHsb(ofRandom(150), 100, 255,200);
        col.push_back(c);
        }
        
    
        framNUM=ofGetHeight()/5;
        ofBackground(0);
      
        
        for (int i = 0; i < NUM; i++) {
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(ofRandom(-5,5),ofRandom(-5,5)));
            yazirusi.push_back(p);
            
            ofPoint b;
            b.set(ofRandom(-5,5),ofRandom(-5,5));
            bekutoru.push_back(b);
            
            
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
        
        if(framNUM == 0){
        framNUM=ofGetHeight();
      }
    framNUM--;
        for (int i = 0; i < yazirusi.size(); i++){
            // パーティクルの数だけ計算
          
                
                
                // 力をリセット
                yazirusi[i].resetForce();
            
                
            
                 if(humans.size() > 0){
                     // 画面の端にきたら反対側へ
                   yazirusi[i].setupV(0, ofRandom(20));
                     yazirusi[i].throughOfWalls();
                      a = 0;
                }
                 else{
                   if(a < 20){
                     yazirusi[i].setupV(bekutoru[i].x,bekutoru[i].y);
                   }
                    yazirusi[i].bounceOffWalls();
                 
                   a ++;
                 }
          // 力をリセット
          yazirusi[i].resetForce();
          
            
            // パーティクル更新
            yazirusi[i].update();
            
 
        }
        
        
        
        }
    
    
    
    void draw(void){
      
      ofSetColor(40,91,241);
        for (int i = 0; i < yazirusi.size(); i++) {
            ofPushMatrix();
            ofTranslate(yazirusi[i].position.x, yazirusi[i].position.y);
            ofDrawRectangle(0, 0, 10, 10);
            
            
            ofPopMatrix();
        }
      


    
    }


};

