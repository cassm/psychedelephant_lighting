#pragma once

#include <ctime>
#include "ofMain.h"
#include "LedCylinder.hpp"
#include "LedHexagon.hpp"
#include "LedSender.hpp"
#include "GuiBlock.hpp"
#include "SharedTypes.hpp"
//#include "ofxGui.h"

class ofApp : public ofBaseApp{
public:
    void setup() override;
//    void exit() override;
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

    void onScreenButtonEvent(ofxDatGuiButtonEvent e) {
        screen_gui.processButtonEvent(static_cast<ofxDatGuiToggle*>(e.target));
    }

    void onLanternButtonEvent(ofxDatGuiButtonEvent e) {
        lantern_gui.processButtonEvent(static_cast<ofxDatGuiToggle*>(e.target));
    }

    uint16_t  num_leds;
    std::vector<LedCylinder> lanterns;
    std::vector<LedHexagon> bunting_strands;
    LedSender bunting_sender;
    LedSender lantern_sender;
    playerContainer screen_player;
    playerContainer lantern_player;

    ofImage screen_mask;

    ofCamera cam; // add mouse controls for camera movement

    ofxDatGui lantern_gui_obj;
    GuiBlock lantern_gui;

    ofxDatGui screen_gui_obj;
    GuiBlock screen_gui;

//    ofxDatGui hex_gui;
//    std::vector<ofxDatGuiToggle*> hex_video_toggles;
    float hex_brightness;
//
//    ofxDatGui bunting_gui;
//    BuntingMode bunting_mode;
//    std::vector<ofxDatGuiToggle*> bunting_mode_toggles;
    float bunting_brightness;

};
