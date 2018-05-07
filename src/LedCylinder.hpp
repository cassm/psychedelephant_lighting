//
//  LedCylinder.hpp
//  LedCylinder
//
//  Created by Cass May on 21/04/2018.
//

#ifndef LedCylinder_hpp
#define LedCylinder_hpp

#include "ofMain.h"
#include "LedMapper.hpp"
#include <vector>
#include <cstdio>
#include <fstream>

//#include "ofxSerial.h"

class LedCylinder : public LedMapper {
public:
    LedCylinder() = default;
    ~LedCylinder() = default;
    
    void init(float radius, float length, float rotation, float n_turns, int n_leds);

    void render(ofPoint origin, float led_size, float scale) override;

private:
    float radius_;
    float length_;
};

#endif /* LedCylinder_hpp */
