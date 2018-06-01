//
// Created by Cass May on 28/05/2018.
//

#ifndef OPENFRAMEWORKS_PALETTEMAPPER_HPP
#define OPENFRAMEWORKS_PALETTEMAPPER_HPP

#include "ofMain.h"
#include "SharedTypes.hpp"
#include <string>
#include <chrono>

class PaletteMapper {
public:
    PaletteMapper() = default;
    PaletteMapper(ofPoint extent_, float palette_period_, std::string palettePath_, float palettes_per_extent_);

    ofColor getColor(ledInfo *led);

    void setMode(paletteMode mode);

//    float skew;

private:
    ofImage palette;
    ofPoint extent;
    float max_delta;
    paletteMode mode;
    float palette_period;
    float palettes_per_extent;
    std::chrono::high_resolution_clock::time_point init_time;
    //FIXME corner_offset for concentric, swirl for radial
};


#endif //OPENFRAMEWORKS_PALETTEMAPPER_HPP
