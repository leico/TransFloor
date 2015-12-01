//
//  kinectCV.hpp
//  emptyExample
//
//  Created by leico_system on 2015/11/26.
//
//

#ifndef kinectCV_hpp
#define kinectCV_hpp

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"

class KinectCV{

  ofxKinect kinect;

  ofxCvGrayscaleImage grayImage;
  ofxCvGrayscaleImage binaryImage;
  ofxCvContourFinder contourfinder;

  std :: vector<ofxOscMessage> humans;

  std :: string prefix;

  unsigned char min_depth;
  unsigned char max_depth;

  int angle;

  int blur;

  int min_area;
  int max_area;

  ofRectangle cliparea;

  public:
   KinectCV(void);
  ~KinectCV(void);

  const unsigned char MinDepth(void);
                 void MinDepth(const unsigned char min);

  const unsigned char MaxDepth(void);
                 void MaxDepth(const unsigned char max);
  
  const int  Angle(void);
        void Angle(const int _angle);

  const int  Blur(void);
        void Blur(const int _blur);

  const int  MinArea(void);
        void MinArea(const int min);

  const int  MaxArea(void);
        void MaxArea(const int max);

  const ofRectangle& ClipArea(void);
        void         ClipArea(const ofRectangle& area);
  

  void setup (const std :: string &serial, const std :: string &_prefix);
  void exit  (void);
  bool update(void);
  void draw  (void);

  ofxOscMessage& osc(ofxOscMessage &m);

  const std :: vector<ofxOscMessage>& Humans(void);
};

/* ========================================================= *
 * constructor / destructor                                  *
 * ========================================================= */
inline KinectCV ::  KinectCV(void){}
inline KinectCV :: ~KinectCV(void){}

/* ========================================================= *
 * const unsigned char MinDepth(void)                        *
 *                void MinDepth(const unsigned char min)     *
 * ========================================================= */
inline const unsigned char KinectCV :: MinDepth(void)                   { return min_depth; }
inline                void KinectCV :: MinDepth(const unsigned char min){ min_depth = min;  }


/* ========================================================= *
 * const unsigned char MaxDepth(void)                        *
 *                void MaxDepth(const unsigned char max)     *
 * ========================================================= */
inline const unsigned char KinectCV :: MaxDepth(void)                   { return max_depth; }
inline                void KinectCV :: MaxDepth(const unsigned char max){ max_depth = max; }


/* ========================================================= *
 * const int  Angle(void)                                    *
 *       void Angle(const int _angle)                        *
 * ========================================================= */
inline const int  KinectCV :: Angle(void)            { return angle;   }
inline       void KinectCV :: Angle(const int _angle){
  angle = ofClamp(_angle, -30, 30); 
  kinect.setCameraTiltAngle(angle);
}


/* ========================================================= *
 * const int  Blur(void);                                    *
 *       void Blur(const int _blur);                         *
 * ========================================================= */
inline const int  KinectCV :: Blur(void)           { return blur;   }
inline       void KinectCV :: Blur(const int _blur){ blur = _blur;  } 


/* ========================================================= *
 * const int  MinArea(void);                                 *
 *       void MinArea(const int min);                        *
 * ========================================================= */
inline const int  KinectCV :: MinArea(void)         { return min_area; }
inline       void KinectCV :: MinArea(const int min){ min_area = min;  } 


/* ========================================================= *
 * const int  MaxArea(void);                                 *
 *       void MaxArea(const int max);                        *
 * ========================================================= */
inline const int  KinectCV :: MaxArea(void)         { return max_area; }
inline       void KinectCV :: MaxArea(const int max){ max_area = max;  }

/* ========================================================= *
 * const ofRectangle& ClipArea(void);                        *
 *       void         ClipArea(const ofRectangle& area);     *
 * ========================================================= */
inline const ofRectangle& KinectCV :: ClipArea(void)                   { return cliparea; }
inline void               KinectCV :: ClipArea(const ofRectangle& area){ cliparea = area; }







/* ========================================================= *
 * void setup(const std :: string &serial)                   *
 * ========================================================= */
inline void KinectCV :: setup (const std :: string &serial, const std :: string &_prefix){

  prefix = _prefix;


  kinect.init();
  kinect.open(serial);

  grayImage  .allocate( kinect.getWidth(), kinect.getHeight() );
  binaryImage.allocate( kinect.getWidth(), kinect.getHeight() );

  humans.resize(1024);
  humans.clear();

  MinDepth(70);
  MaxDepth(200);

  Angle(0);
  Blur (0);

  ClipArea( ofRectangle(0, 0, kinect.getWidth(), kinect.getHeight() ) );
  
  MinArea(0);
  MaxArea(100);

}

/* ========================================================= *
 * void exit(void)                                           *
 * ========================================================= */
inline void KinectCV :: exit(void){
  grayImage  .clear();
  binaryImage.clear();

  Angle(0);
  kinect.close();
  kinect.clear();
}

/* ========================================================= *
 * void update(void)                                         *
 * ========================================================= */
inline bool KinectCV :: update(void){
  kinect.update();

  if(kinect.isFrameNew()){

    int width  = kinect.getWidth();
    int height = kinect.getHeight();

    //get kinect depth data and noise reduction
    grayImage.setFromPixels( kinect.getDepthPixels(), width, height );
    grayImage.blur(blur);

    //set Rectangle of Interest and clip Rectangle of Interest
    grayImage.setROI(cliparea);
    grayImage.setFromPixels( grayImage.getRoiPixels() );

    //resize display size
    grayImage.resize(kinect.getWidth(), kinect.getHeight());

    binaryImage = grayImage;

    //binarization
    {
      unsigned char *pixels = binaryImage.getPixels();
      for(int i = 0, numpix = width * height ; i < numpix ; ++ i)
        pixels [i] = (pixels[i] <  min_depth || pixels[i] > max_depth ) ? 0 : 255;
    }

    //contourfinder
    contourfinder.findContours(binaryImage, min_area, max_area, 200, false);

    humans.clear();

    for(int i = 0, size = contourfinder.blobs.size() ; i < size ; ++ i){

      //get contour center position
      ofPoint pos = contourfinder.blobs.at(i).centroid;

      unsigned char* pixels = grayImage.getPixels();

      //create OSC Message
      ofxOscMessage m;
      m.setAddress("/human");
      m.addIntArg(pos.x);
      m.addIntArg(pos.y);
      m.addIntArg( pixels[int(width * pos.y + pos.x)] );

      //store for humans
      humans.push_back(m);

      //ofLogWarning() << "nBlobs:" << humans.size();

    }
    //各々のOSC関数を呼び出す
    return true;

  }

  return false;
}

/* ========================================================= *
 * void draw(void)                                           *
 * ========================================================= */
inline void KinectCV :: draw(void){

  int width  = kinect.getWidth();
  int height = kinect.getHeight();

  binaryImage.draw(  0, 0, 320, 240);
  grayImage  .draw(320, 0, 320, 240);

 // for(int i = 0 ; i < contourfinder.nBlobs ; ++ i){
    contourfinder.draw(0, 0, 320, 240);


}

/* ========================================================= *
 * ofxOscMessage& osc(ofxOscMessage &m)                      *
 * ========================================================= */
inline ofxOscMessage& KinectCV :: osc(ofxOscMessage &m){

  if(m.getAddress() == prefix + "/kinect/mindepth"){
    MinDepth( m.getArgAsInt32(0) );
    m.clear();
    return m;
  }

  if(m.getAddress() == prefix + "/kinect/maxdepth"){
    MaxDepth( m.getArgAsInt32(0) );
    m.clear();
    return m;
  }

  if(m.getAddress() == prefix + "/kinect/angle"){
    Angle( m.getArgAsInt32(0) );
    m.clear();
    return m;
  }

  if(m.getAddress() == prefix + "/kinect/blur"){
    Blur( m.getArgAsInt32(0) );
    m.clear();
    return m;
  }

  if(m.getAddress() == prefix + "/kinect/minarea"){
    MinArea( m.getArgAsInt32(0) );
    m.clear();
    return m;

  }

  if(m.getAddress() == prefix + "/kinect/maxarea"){
    MaxArea( m.getArgAsInt32(0) );
    m.clear();
    return m;
  }

  if(m.getAddress() == prefix + "/kinect/cliparea"){
    ClipArea(
      ofRectangle(
          m.getArgAsInt32(0)
        , m.getArgAsInt32(1)
        , m.getArgAsInt32(2)
        , m.getArgAsInt32(3)
      )
    );

    m.clear();
    return m;
  }

  return m;
}

/* ========================================================= *
 * const std :: vector<ofxOscMessage>& Humans()              *
 * ========================================================= */
inline const std :: vector<ofxOscMessage>& KinectCV :: Humans(void){
  return humans;
}


#endif /* kinectCV_hpp */
