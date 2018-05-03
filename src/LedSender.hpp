//
// Created by Cass May on 26/04/2018.
//

#ifndef OPENFRAMEWORKS_LEDSENDER_H
#define OPENFRAMEWORKS_LEDSENDER_H

#include "ofMain.h"
#include <string>
#include <vector>
#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>

class LedSender {
public:
    LedSender() : port(io) {};
    ~LedSender();
    void init(std::string port_str);
    void add_strand(uint8_t pin_, uint8_t channels_per_led_, uint16_t num_leds_);
    void setPixels(uint8_t pin_, const ofPixels &p_);
    void send(uint8_t pin_);

private:
    struct strand_info {
        bool operator==(const int& a) const
        {
            return (pin == a);
        }

        uint8_t pin;
        uint8_t channels_per_led;
        uint16_t num_leds;
        ofPixels p;
    };

    std::vector<strand_info> strands;
    boost::asio::io_service io;
    boost::asio::serial_port port;
};


#endif //OPENFRAMEWORKS_LEDSENDER_H
