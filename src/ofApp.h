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

    struct playerContainer {
        ofVideoPlayer player;
        std::vector<std::string> videos;
        std::vector<std::string>::iterator it;
        bool switch_video;
    };

    uint16_t  num_leds;
    std::vector<LedCylinder> cylinders;
    std::vector<LedHexagon> hexes;
    LedSender hex_sender;
    LedSender cylinder_sender;
    playerContainer hex_player;
    playerContainer cylinder_player;

    ofImage proj;

    ofCamera cam; // add mouse controls for camera movement
};
