//
//  LedCylinder.cpp
//  LedCylinder
//
//  Created by Cass May on 21/04/2018.
//

#include "LedCylinder.hpp"

void LedCylinder::init(float radius, float length, float rotation, float n_turns, int n_leds) {
    glEnable (GL_DEPTH_TEST);   // Enables Depth Testing
    ofSetBackgroundAuto(true);

    radius_ = radius;
    length_ = length;
    float leds_per_turn = n_leds / n_turns;

    leds.clear();

    for (int i = 0; i < n_leds; i++) {
        struct ledInfo led;
        
        led.input_mapping.y = (float)(n_leds - 1 - i) / n_leds;
        led.input_mapping.x = fmod(i, leds_per_turn) / leds_per_turn;
        
        float num_turns_so_far = n_turns * led.input_mapping.y;
        float angle_on_cylinder = fmod(2*3.14 * num_turns_so_far + 3.14*1.5, 2*3.14);
        
        led.output_mapping.x = cos(angle_on_cylinder + rotation) * radius;
        led.output_mapping.z = sin(angle_on_cylinder + rotation) * radius;
        led.output_mapping.y = (led.input_mapping.y * length) - length/2; // origin is in centre
        
        leds.push_back(led);
    }
}

void LedCylinder::render(ofPoint origin, float led_size, float scale) {
    ofSetColor(ofColor(0,0,0));
    ofFill();
    ofDrawCylinder(origin, radius_*scale, length_*scale);
    for (auto &led : leds) {
        ofSetColor(led.color);
        ofFill();
        ofDrawSphere(led.output_mapping*scale + origin, led_size);
    }
}
