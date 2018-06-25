//
// Created by Cass May on 23/06/2018.
//

#include "BrightnessBox.hpp"

bool BrightnessBox::check_for_connect() {
    if (previously_connected) {
        if (port.isOpen()) {
            return true;
        }
        else {
            ofLogNotice("BrightnessBox::init") << "Serial port connection lost on " << port_str;
            previously_connected = false;
            return false;
        }
    }
    else {
        if (port.isOpen()) {
            return true; //weird case. Prob not possible
        }
        else {
            try {
                port.open(port_str, 115200);
                port.setTimeout(0.05);

                if (port.isOpen()) {
                    ofLogNotice("BrightnessBox::init") << "Serial port opened on " << port_str;
                    previously_connected = true;
                    return true;
                } else {
                    return false;
                }
            }
            catch(const std::exception& e) {
//                ofLogNotice("BrightnessBox::init") << "Error opening serial port: " << e.what();
                return false;
            }
        }
    }
}

void BrightnessBox::update_vals() {
    try {
        if (check_for_connect()) port.write("~");
        else return;
        if (check_for_connect()) port.read(global_brightness, 1);
        else return;
        if (check_for_connect()) port.read(screen_brightness, 1);
        else return;
        if (check_for_connect()) port.read(bunting_brightness, 1);
        else return;
        if (check_for_connect()) port.read(lantern_brightness, 1);
        else return;
    }
    catch(const std::exception& e) {
        port.close();
    }
}

