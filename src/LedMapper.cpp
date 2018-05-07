//
// Created by Cass May on 07/05/2018.
//

#include "LedMapper.hpp"

void LedMapper::setPixels(ofPixels &p) {
    for (auto &led : leds) {
        auto x = static_cast<size_t>((p.getWidth() - 1) * led.input_mapping.x);
        auto y = static_cast<size_t>((p.getHeight()-1) * led.input_mapping.y);
        led.color = p.getColor(x, y);
        //TODO: add sampling?
    }
}

ofPixels LedMapper::getPixels() {
    ofPixels p;
    p.allocate(leds.size(), 1, 3);

    for (int i = 0; i < leds.size(); i++) {
        p.setColor(i, 0, leds[i].color);
    }

    return p;
}

void LedMapper::render(ofPoint origin, float led_size, float scale) {
    for (auto &led : leds) {
        ofSetColor(led.color);
        ofFill();
        ofDrawSphere(led.output_mapping*scale + origin, led_size);
    }

    ofSetColor(255,255,255); // reset draw color after use
}
