//
// Created by Cass May on 07/05/2018.
//

#ifndef OPENFRAMEWORKS_LEDMAPPER_HPP
#define OPENFRAMEWORKS_LEDMAPPER_HPP

#include <vector>
#include "ofMain.h"
#include "PaletteMapper.hpp"

class LedMapper {
public:
    LedMapper(int strand_id_, ofPoint origin_, float led_size_) : strand_id(strand_id_), origin(origin_), led_size(led_size_) {}
    void setPixels(ofPixels &p);
    ofPixels getPixels();
    virtual void render(float brightness);
    void blend(float last_led_factor);
    virtual ofPoint getExtent();
    void setFromPalette(PaletteMapper *mapper);
    void sparkle(PaletteMapper *mapper, float chance);

//protected:
    const int strand_id;
    std::vector<struct ledInfo> leds;
    float led_size;
    ofPoint origin;
};


#endif //OPENFRAMEWORKS_LEDMAPPER_HPP
