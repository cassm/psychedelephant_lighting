//
//  LedCylinder.cpp
//  LedCylinder
//
//  Created by Cass May on 21/04/2018.
//

#include "LedCylinder.hpp"

LedCylinder::LedCylinder(int strand_id_, float radius, float length, float rotation, float n_turns, int n_leds, float led_size_, ofPoint origin_)
        : LedMapper(strand_id_, origin_, led_size_) {
    ofSetBackgroundAuto(true);

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

        led.output_mapping += origin;

        led.theta = atan2(led.output_mapping.x, led.output_mapping.y) * 180 / 3.14;
        led.delta = sqrt(led.output_mapping.x*led.output_mapping.x + led.output_mapping.y*led.output_mapping.y + led.output_mapping.z*led.output_mapping.z);

        leds.push_back(led);
    }
}

//FIXME move lantern origin and rotation into constructor, just use origin

void LedCylinder::render(float led_size) {
    ofSetColor(ofColor(0,0,0));
    ofFill();

    ofPushMatrix();
    ofTranslate(origin);
    ofRotateX(90);
    ofDrawCylinder(radius_, length_);
    ofPopMatrix();

    LedMapper::render(led_size);
}

ofPoint LedCylinder::getExtent() {
    ofPoint max;
    for (int i = 0; i < leds.size(); i++) {
        ofPoint point = leds[i].output_mapping + origin;
        if (abs(point.x) > max.x) {
            max.x = abs(point.x);
        }
        if (abs(point.y) > max.y) {
            max.y = abs(point.y);
        }
        if (abs(point.z) > max.z) {
            max.z = abs(point.z);
        }
    }

    return max;
}

