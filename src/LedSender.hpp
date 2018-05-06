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

const int num_strips = 8;

class LedSender {
public:
    LedSender() : port(io) {};
    ~LedSender();
    void init(std::string port_str);
    void setPixels(uint8_t strip_id_, const ofPixels &p_);
    void set_num_leds(uint8_t strip_id_, uint16_t num_leds_);
    void send(uint8_t strip_id_);
//    void start_read();
//    void handle_read(const boost::system::error_code& ec);

private:
    struct strand_info {
        uint16_t num_leds;
        ofPixels p;
    };

    strand_info strands[num_strips];

    boost::asio::io_service io;
    boost::asio::serial_port port;
};


#endif //OPENFRAMEWORKS_LEDSENDER_H
