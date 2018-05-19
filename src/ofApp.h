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

    void onBuntingButtonEvent(ofxDatGuiButtonEvent e) {
        bunting_gui.processButtonEvent(static_cast<ofxDatGuiToggle*>(e.target));
    }

    void onBuntingColorPickerEvent(ofxDatGuiColorPickerEvent e)
    {
        bunting_player.color = e.color;
    }

    void doNothing(ofxDatGuiColorPickerEvent e)
    {
    }

    uint16_t  num_leds;

    ofImage palette;

    ofCamera cam; // add mouse controls for camera movement


    ofxDatGui screen_gui_obj;
    GuiBlock screen_gui;
    playerContainer screen_player;
    ofImage screen_mask;

    ofxDatGui lantern_gui_obj;
    GuiBlock lantern_gui;
    std::vector<LedCylinder> lanterns;
    LedSender lantern_sender;
    playerContainer lantern_player;

    ofxDatGui bunting_gui_obj;
    GuiBlock bunting_gui;
    std::vector<LedHexagon> bunting_strands;
    LedSender bunting_sender;
    playerContainer bunting_player;
};
