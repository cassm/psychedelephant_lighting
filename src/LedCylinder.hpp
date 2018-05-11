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
    LedCylinder(int strand_id, ofPoint xy_location, float radius, float length, float rotation, float n_turns, int n_leds);
    ~LedCylinder() = default;
    

    void render(ofPoint origin, float led_size, float scale) override;
    const int strand_id_;

private:
    ofPoint xy_location_;
    float radius_;
    float length_;
};

#endif /* LedCylinder_hpp */
