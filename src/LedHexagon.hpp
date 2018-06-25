//
// Created by Cass May on 07/05/2018.
//

#ifndef OPENFRAMEWORKS_LEDHEXAGON_H
#define OPENFRAMEWORKS_LEDHEXAGON_H

#include "LedMapper.hpp"

//TODO add height

class LedHexagon : public LedMapper {
public:
    LedHexagon(int strand_id_, int num_strings_, int leds_per_strand_, float diameter_, float max_diameter_, float scale_, float led_size_, ofPoint origin_);
    void setFromColor(ofColor color);
};


#endif //OPENFRAMEWORKS_LEDHEXAGON_H
