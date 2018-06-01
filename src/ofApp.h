#pragma once

#include <ctime>
#include "ofMain.h"
#include "LedCylinder.hpp"
#include "LedHexagon.hpp"
#include "LedSender.hpp"
#include "GuiBlock.hpp"
#include "PaletteMapper.hpp"
#include "SharedTypes.hpp"
//#include "ofxGui.h"

class ofApp : public ofBaseApp{
public:
    ofApp(std::string *video_title_, float *parent_brightness_) : video_title(video_title_), parent_brightness(parent_brightness_) {}
//    ofApp(ofVideoPlayer *screen_player_, float *parent_brightness_) : parent_brightness(parent_brightness_) {screen_player.player = screen_player_;}
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

    void onGlobalButtonEvent(ofxDatGuiButtonEvent e) {
        ofxDatGuiTheme *inactive_theme = new NellieThemeInactive;
        ofxDatGuiTheme *active_theme = new NellieThemeActive;

        ofxDatGuiToggle *target = static_cast<ofxDatGuiToggle*>(e.target);

        if (target->getChecked()) {
            target->setTheme(active_theme);
        }
        else {
            target->setTheme(inactive_theme);
        }

        if (target->getLabel() == "    Radial") {
            paletteMapper.setMode(mode_radial);
            concentric->setChecked(false);
            concentric->setTheme(inactive_theme);
        }

        if (target->getLabel() == "    Concentric") {
            paletteMapper.setMode(mode_concentric);
            radial->setChecked(false);
            radial->setTheme(inactive_theme);
        }
    }

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

    ofCamera cam; // add mouse controls for camera movement

    PaletteMapper paletteMapper;

    std::string *video_title;

    ofxDatGui global_gui_obj;
    ofxDatGui global_brightness_gui_obj;
    ofxDatGuiToggle *simulate;
    ofxDatGuiToggle *concentric;
    ofxDatGuiToggle *radial;
    ofxDatGuiSlider* brightness_slider;
    float blend_factor;

    float *parent_brightness;

    float last_width;
    float last_height;

    float pattern_intensity;
    float sparkle_level;

    float global_brightness;

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
