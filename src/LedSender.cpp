//
// Created by Cass May on 26/04/2018.
//

#include "LedSender.hpp"

void LedSender::init(std::string port_str) {
    ofLogNotice("ofApp::setup") << "Opening serial port...";
    try {
        port.open(port_str);
        port.set_option(boost::asio::serial_port_base::baud_rate(115200));

        if (port.is_open()) {
            ofLogNotice("ofApp::setup") << "Serial port opened";
        } else {
            ofLogNotice("ofApp::setup") << "Could not open serial port";
        }
    }
    catch(const std::exception& e) {
        ofLogNotice("ofApp::setup") << "Error opening serial port: " << e.what();
    }

}

LedSender::~LedSender() {
    if (port.is_open()) {
        port.close();
    }
}

void LedSender::add_strand(uint8_t pin_, uint8_t channels_per_led_, uint16_t num_leds_) {
    auto it = find(strands.begin(), strands.end(), pin_);

    if (it != strands.end()) {
        strands.erase(it);
    }

    strand_info strinfo = { pin_,
                            channels_per_led_,
                            num_leds_,
                            ofPixels() };

    strands.push_back(strinfo);
}

struct strand_info {
    bool operator==(const int& a) const
    {
        return (pin == a);
    }

    int pin;
    int channels_per_led;
    int num_leds;
    ofPixels p;
};

void LedSender::setPixels(uint8_t pin_, const ofPixels &p_) {
    auto it = find(strands.begin(), strands.end(), pin_);

    if (it != strands.end()) {
        it->p = p_;
    }
}

void LedSender::send(uint8_t pin_) {
    auto it = find(strands.begin(), strands.end(), pin_);

    if (it != strands.end()) {
        if (port.is_open()) {
            uint8_t header[5];
            header[0] = '~'; // framesync char
            header[1] = pin_;
            header[2] = it->channels_per_led;
            header[3] = static_cast<uint8_t>(it->num_leds >> 8u);
            header[4] = static_cast<uint8_t>(it->num_leds & 0xff);

            boost::asio::write(port, boost::asio::buffer(header, 5));

            for (int i = 0; i < it->num_leds; i++) {
                uint8_t pixel[3];

                if (i < it->p.getWidth() - 1) {
                    ofColor col = it->p.getColor(static_cast<size_t>(i), 0);

                    pixel[0] = col.r;
                    pixel[1] = col.g;
                    pixel[2] = col.b;
                }
                else {
                    pixel[0] = 0x00;
                    pixel[1] = 0x00;
                    pixel[2] = 0x00;
                }

                // reserve frame sync byte
                for (unsigned char &j : pixel) {
                    if (j == '~') {
                        j++;
                    }

                }

                if (port.is_open()) {
                    port.write_some(boost::asio::buffer(pixel, 3));
                }
            }
        }
    }
}
