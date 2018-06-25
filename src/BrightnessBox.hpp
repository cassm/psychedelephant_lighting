//
// Created by Cass May on 23/06/2018.
//

#ifndef OPENFRAMEWORKS_BRIGHTNESSBOX_HPP
#define OPENFRAMEWORKS_BRIGHTNESSBOX_HPP

#include "ofMain.h"
#include <string>
#include <vector>
#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>

#include <iostream>
#include "TimeoutSerial.h"


class BrightnessBox {
public:
    BrightnessBox() = default;

    BrightnessBox(std::string port_str_, float *global_brightness_, float *screen_brightess_, float *bunting_brightess_, float *lantern_brightess_)
            : global_brightness(global_brightness_),
              screen_brightness(screen_brightness_),
              bunting_brightness(bunting_brightness_),
              lantern_brightness(lantern_brightness_),
              port(io),
              port_str(port_str_),
              previously_connected(false) {}

    bool check_for_connect();
    void update_vals();

private:
    float *global_brightness;
    float *screen_brightness;
    float *bunting_brightness;
    float *lantern_brightness;

//    boost::asio::io_service io;
//    boost::asio::serial_port port;

    TimeoutSerial port;

    std::string port_str;
    bool previously_connected;
};


#endif //OPENFRAMEWORKS_BRIGHTNESSBOX_HPP
