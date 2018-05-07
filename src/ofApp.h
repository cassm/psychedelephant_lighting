#pragma once

#include <ctime>
#include "ofMain.h"
#include "LedCylinder.hpp"
#include "LedHexagon.hpp"
#include "LedSender.hpp"

class ofApp : public ofBaseApp{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;

    bool switch_video;
    float cylinder_rotation;
    uint16_t  num_leds;
//    LedCylinder cylinder;
    std::vector<LedHexagon> hexes;
    LedSender hex_sender;
    ofVideoPlayer myPlayer;
    std::vector<std::string> videos;
    std::vector<std::string>::iterator video_it;

    ofImage proj;
};
