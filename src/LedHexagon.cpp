//
// Created by Cass May on 07/05/2018.
//

#include "LedHexagon.hpp"
#include <cmath>

LedHexagon::LedHexagon(int strand_id_, int num_strings_, int leds_per_strand_, float diameter_, float max_diameter_) : strand_id(strand_id_) {
    int num_leds = num_strings_ * leds_per_strand_;
    float leds_per_side = static_cast<float>(num_leds) / 6;

    float relative_diameter = diameter_ / max_diameter_;
    float outer_radius = relative_diameter / 2;

    // TODO leds go clockwise from top right corner
    for (int i = 0; i < num_leds; i++) {
        struct ledInfo led;

        float position_on_side = static_cast<float>(fmod(i, leds_per_side) / leds_per_side);
        int side_index = i / leds_per_side;

        double rotation_per_side = 3.14/3;

        double side_origin_x = outer_radius * cos(side_index*rotation_per_side);
        double side_origin_y = outer_radius * sin(side_index*rotation_per_side);

        double side_endpoint_x = outer_radius * cos((side_index+1)*rotation_per_side);
        double side_endpoint_y = outer_radius * sin((side_index+1)*rotation_per_side);

        double side_diff_x = side_endpoint_x - side_origin_x;
        double side_diff_y = side_endpoint_y - side_origin_y;

        led.input_mapping.x = static_cast<float>(side_origin_x + position_on_side*side_diff_x + 0.5);
        led.input_mapping.y = static_cast<float>(side_origin_y + position_on_side*side_diff_y + 0.5);
        led.input_mapping.z = 0;

        led.output_mapping.x = led.input_mapping.x - 0.5;
        led.output_mapping.y = led.input_mapping.y - 0.5;
        led.output_mapping.z = sin(3.14 * position_on_side) * diameter_/2 * 0.0003;

        leds.emplace_back(led);
    }
}
void LedHexagon::setFromColor(ofColor color) {
    for (auto &led : leds) {
        led.color = color;
    }
}
