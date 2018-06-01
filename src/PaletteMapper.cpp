//
// Created by Cass May on 28/05/2018.
//

#include "PaletteMapper.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono;

PaletteMapper::PaletteMapper(ofPoint extent_, float palette_period_, std::string palettePath_, float palettes_per_extent_)
: extent(extent_), mode(mode_concentric), palette_period(palette_period_), palettes_per_extent(palettes_per_extent_) {
    max_delta = sqrt(extent.x*extent.x + extent.y*extent.y + extent.z*extent.z);
    palette.load(palettePath_);
    init_time = high_resolution_clock::now();
}

void PaletteMapper::setMode(paletteMode mode_) {
    mode = mode_;
}

ofColor PaletteMapper::getColor(ledInfo *led) {
    float time_offset = (duration_cast<milliseconds>(high_resolution_clock::now() - init_time).count()) / palette_period;
    time_offset /= 1000;
    time_offset = 1 - fmod(time_offset, 1);
    float space_offset = 0;

    if (mode == mode_concentric) {
        ofPoint pos = led->output_mapping / extent;

        float skewed_delta = sqrt(pos.x*pos.x + pos.y*pos.y + pos.z*pos.z);
//        float relative_delta = led->delta / max_delta;
//        float effective_delta = (1.0-skew)*relative_delta + skew*skewed_delta;
//        space_offset = effective_delta * palettes_per_extent;
        space_offset = skewed_delta * palettes_per_extent;
    }
    else if (mode == mode_radial) {
        float theta = led->theta;
        theta += led->delta/max_delta * 720;
        while (theta < 0) {
            theta += 360;
        }
        space_offset = theta / 360;
    }

    float total_offset = fmod(time_offset + space_offset, 1);

    int pixel_index = palette.getWidth() * total_offset;
    return palette.getColor(pixel_index, 0);
}
