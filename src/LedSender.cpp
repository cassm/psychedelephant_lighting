//
// Created by Cass May on 26/04/2018.
//

#include "LedSender.hpp"

void LedSender::init(std::string port_str) {
    ofLogNotice("LedSender::init") << "Opening serial port...";
    try {
        port.open(port_str);
        port.set_option(boost::asio::serial_port_base::baud_rate(115200));

        if (port.is_open()) {
            ofLogNotice("LedSender::init") << "Serial port opened";
        } else {
            ofLogNotice("LedSender::init") << "Could not open serial port";
        }
    }
    catch(const std::exception& e) {
        ofLogNotice("LedSender::init") << "Error opening serial port: " << e.what();
    }

}

LedSender::~LedSender() {
    if (port.is_open()) {
        port.close();
    }
}

void LedSender::setPixels(uint8_t strip_id_, const ofPixels &p_) {
    if (strip_id_ < num_strips) {
        strands[strip_id_].p = p_;
    }
}

void LedSender::set_num_leds(uint8_t strip_id_, uint16_t num_leds_) {
    if (strip_id_ < num_strips) {
        strands[strip_id_].num_leds = num_leds_;
    }
}

void LedSender::send(uint8_t strip_id_, float brightness) {
    if (strip_id_ < num_strips) {
        if (port.is_open()) {
            uint8_t header[2];
            header[0] = '~'; // frame start char
            header[1] = strip_id_;

            boost::asio::write(port, boost::asio::buffer(header, 2));

            for (int i = 0; i < strands[strip_id_].num_leds; i++) {
                uint8_t pixel[3];

                if (i < strands[strip_id_].p.getWidth() - 1) {
                    ofColor col = strands[strip_id_].p.getColor(static_cast<size_t>(i), 0);

                    pixel[0] = col.r * brightness;
                    pixel[1] = col.g * brightness;
                    pixel[2] = col.b * brightness;
                }
                else {
                    pixel[0] = 0x00;
                    pixel[1] = 0x00;
                    pixel[2] = 0x00;
                }

                // reserve frame sync bytes
                for (unsigned char &j : pixel) {
                    if (j == '~' || j == '|') {
                        j++;
                    }
                }

                if (port.is_open()) {
                    boost::asio::write(port, boost::asio::buffer(pixel, 3));
                }
            }

            uint8_t footer[1] = {'|'};
            boost::asio::write(port, boost::asio::buffer(footer, 1));
        }
    }
}
