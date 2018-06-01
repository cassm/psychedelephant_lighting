//
// Created by Cass May on 07/05/2018.
//

#include "LedMapper.hpp"
#include <chrono>

using namespace std::chrono;

void LedMapper::setPixels(ofPixels &p) {
    for (auto &led : leds) {
        auto x = static_cast<size_t>((p.getWidth() - 1) * led.input_mapping.x);
        auto y = static_cast<size_t>((p.getHeight()-1) * led.input_mapping.y);
        led.last_color = led.color;
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

void LedMapper::blend(float last_led_factor) {
//    float last_led_factor = 0.85;

    for (auto &led : leds) {
        led.color *= (1-last_led_factor);
        led.color += (led.last_color * last_led_factor);
    }

}

void LedMapper::render(float brightness) {
    for (auto &led : leds) {
        ofSetColor(led.color * brightness);
        ofFill();
        ofDrawSphere(led.output_mapping, led_size);
    }

    ofSetColor(255,255,255); // reset draw color after use
}

ofPoint LedMapper::getExtent() {
    ofPoint max;
    for (int i = 0; i < leds.size(); i++) {
        ofPoint point = leds[i].output_mapping;
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

void LedMapper::setFromPalette(PaletteMapper *mapper) {
    for (auto &led : leds) {
        led.last_color = led.color;
        led.color = mapper->getColor(&led);
    }
}

//FIXME soft transition
void LedMapper::sparkle(PaletteMapper *mapper, float chance) {
    for (auto &led : leds) {
        if ((double) rand() / (RAND_MAX) < chance) {
            led.sparkle_color = mapper->getColor(&led);
            led.sparkle_time = high_resolution_clock::now();
        }

        float t_delta = (duration_cast<milliseconds>(high_resolution_clock::now() - led.sparkle_time).count());
        int min_delta = 100;
        if (t_delta < min_delta) t_delta = min_delta;
        led.last_color = led.color;
        led.color = led.sparkle_color / (t_delta/200);
    }
}
