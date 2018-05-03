//
//  LedCylinder.hpp
//  LedCylinder
//
//  Created by Cass May on 21/04/2018.
//

#ifndef LedCylinder_hpp
#define LedCylinder_hpp

#include "ofMain.h"
#include <vector>
#include <cstdio>
#include <fstream>

//#include "ofxSerial.h"

class LedCylinder {
public:
    LedCylinder() = default;
    ~LedCylinder() = default;
    
    void init(float radius, float length, float n_turns, int n_leds);
    void setPixels(ofPixels &p);
    ofPixels getPixels();
    void render(ofPoint origin, float led_size);

private:
    struct ledInfo {
        ofPoint input_mapping; // indexed 0 -> 1, xy only
        ofPoint output_mapping; // xyz
        ofColor color;
    };
    
    std::vector<struct ledInfo> leds;
    float radius_;
    float length_;
};

#endif /* LedCylinder_hpp */
