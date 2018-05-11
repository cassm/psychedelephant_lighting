//
//  LedCylinder.cpp
//  LedCylinder
//
//  Created by Cass May on 21/04/2018.
//

#include "LedCylinder.hpp"

LedCylinder::LedCylinder(int strand_id, ofPoint xy_location, float radius, float length, float rotation, float n_turns, int n_leds)
        : strand_id_(strand_id) {
    ofSetBackgroundAuto(true);

    xy_location_ = xy_location;
    radius_ = radius;
    length_ = length;
    float leds_per_turn = n_leds / n_turns;

    leds.clear();

    for (int i = 0; i < n_leds; i++) {
        struct ledInfo led;
        
        led.input_mapping.y = (float)i / n_leds;
        led.input_mapping.x = fmod(i, leds_per_turn) / leds_per_turn;
        
        float num_turns_so_far = n_turns * led.input_mapping.y;
        float angle_on_cylinder = fmod(2*3.14 * num_turns_so_far + 3.14*1.5, 2*3.14);
        
        led.output_mapping.x = cos(angle_on_cylinder + rotation) * radius;
        led.output_mapping.y = sin(angle_on_cylinder + rotation) * radius;
        led.output_mapping.z = (led.input_mapping.y * length) - length/2; // origin is in centre
        
        leds.push_back(led);
    }
}

void LedCylinder::render(ofPoint origin, float led_size, float scale) {
    ofSetColor(ofColor(0,0,0));
    ofFill();
    ofPushMatrix();
    ofTranslate(xy_location_);

    ofPushMatrix();
    ofTranslate(origin);
    ofRotateX(90);
    ofDrawCylinder(radius_*scale, length_*scale);
    ofPopMatrix();

    LedMapper::render(origin, led_size, scale);
    ofPopMatrix();
}
