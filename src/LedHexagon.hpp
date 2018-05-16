//
// Created by Cass May on 07/05/2018.
//

#ifndef OPENFRAMEWORKS_LEDHEXAGON_H
#define OPENFRAMEWORKS_LEDHEXAGON_H

#include "LedMapper.hpp"

//TODO add height

class LedHexagon : public LedMapper {
public:
    LedHexagon(int strand_id_, int num_strings_, int leds_per_strand_, float diameter_, float max_diameter_);
    int get_strand_id() { return strand_id; }
    void setFromColor(ofColor color);
private:
    int strand_id;
};


#endif //OPENFRAMEWORKS_LEDHEXAGON_H
