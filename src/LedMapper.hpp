//
// Created by Cass May on 07/05/2018.
//

#ifndef OPENFRAMEWORKS_LEDMAPPER_HPP
#define OPENFRAMEWORKS_LEDMAPPER_HPP

#include <vector>
#include "ofMain.h"

class LedMapper {
public:
    void setPixels(ofPixels &p);
    ofPixels getPixels();
    virtual void render(ofPoint origin, float led_size, float scale) = 0;

protected:
    struct ledInfo {
        ofPoint input_mapping; // indexed 0 -> 1
        ofPoint output_mapping; // indexed 0 -> 1

        ofColor color;
    };

    std::vector<struct ledInfo> leds;
};


#endif //OPENFRAMEWORKS_LEDMAPPER_HPP
