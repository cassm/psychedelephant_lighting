//
// Created by Cass May on 26/04/2018.
//

#include "LedSender.hpp"

void LedSender::init(std::string port_str_) {
    port_str = port_str_;
    previously_connected = false;
}

bool LedSender::check_for_connect() {
    if (previously_connected) {
        if (port.is_open()) {
            return true;
        }
        else {
            ofLogNotice("LedSender::init") << "Serial port connection lost on " << port_str;
            previously_connected = false;
            return false;
        }
    }
    else {
        if (port.is_open()) {
            return true; //weird case. Prob not possible
        }
        else {
            try {
                port.open(port_str);
                port.set_option(boost::asio::serial_port_base::baud_rate(115200));

                if (port.is_open()) {
                    ofLogNotice("LedSender::init") << "Serial port opened on " << port_str;
                    previously_connected = true;
                    return true;
                } else {
                    return false;
                }
            }
            catch(const std::exception& e) {
//                ofLogNotice("LedSender::init") << "Error opening serial port: " << e.what();
                return false;
            }
        }
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
    try {
        if (strip_id_ < num_strips) {
            uint8_t header[2];
            header[0] = '~'; // frame start char
            header[1] = strip_id_;

            if (check_for_connect()) boost::asio::write(port, boost::asio::buffer(header, 2));
            else return;

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

                if (check_for_connect()) boost::asio::write(port, boost::asio::buffer(pixel, 3));
                else return;
            }

            uint8_t footer[1] = {'|'};
            if (check_for_connect()) boost::asio::write(port, boost::asio::buffer(footer, 1));
            else return;
        }
    }
    catch(const std::exception& e) {
        port.close();
//                ofLogNotice("LedSender::init") << "Error writing to serial port: " << e.what();
    }
}
