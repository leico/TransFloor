//
//  SecondScreen.hpp
//  emptyExample
//
//  Created by iamas_retina02 on 2015/11/30.
//
//

#ifndef SecondScreen_hpp
#define SecondScreen_hpp

#include "ofMain.h"

class SecondScreen : public ofBaseApp{
  
  public:
  void setup (void);
  void exit  (void);
  void update(void);
  void draw  (void);

  void keyPressed   (int key);
  void keyReleased  (int key);
  void mouseMoved   (int x, int y);
  void mouseDragged (int x, int y, int button);
  void mousePressed (int x, int y, int button);
  void mouseReleased(int x, int y, int button);

  void windowResized(int w, int h);

  void dragEvent (ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
};


#endif /* SecondScreen_hpp */
