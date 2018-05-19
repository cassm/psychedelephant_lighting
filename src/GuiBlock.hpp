//
// Created by Cass May on 13/05/2018.
//

#ifndef OPENFRAMEWORKS_GUIBLOCK_HPP
#define OPENFRAMEWORKS_GUIBLOCK_HPP

#include "ofMain.h"
#include "ofxDatGui.h"
#include "SharedTypes.hpp"
#include <string>
#include <vector>
#include <map>
#include <themes/ofxDatGuiTheme.h>

class ofApp;

class NellieThemeInactive : public ofxDatGuiThemeCharcoal {
public:
    NellieThemeInactive(){
        font.size = 10;
        font.file = "/Library/fonts/Verdana.ttf";
        color.slider.fill = hex(0xf44b39);
        color.backgroundOnMouseDown = hex(0x28292E);
        color.backgroundOnMouseOver = hex(0x28292E);

//        layout.width = 400;
        init();
    }
};

class NellieThemeActive : public NellieThemeInactive {
public:
    NellieThemeActive(){
        color.background = hex(0xf44b39);
        color.backgroundOnMouseDown = hex(0xf44b39);
        color.backgroundOnMouseOver = hex(0xf44b39);
        color.label = hex(0xfdf8c3);
        init();
    }
};

class GuiBlock {
public:
    GuiBlock() = default;
    GuiBlock(std::string label, playerContainer *player, ofxDatGui *gui, ofxDatGuiTheme *active_theme, ofxDatGuiTheme *inactive_theme);

    void processButtonEvent(ofxDatGuiToggle* toggle);

    void add_video(std::string label, std::string filename, bool selected=false);
    void add_mode(std::string label, SystemMode mode, bool selected=false);
    void add_brightness_slider();
    void update_theme();

public:
    bool selectToggleIfPresent(ofxDatGuiToggle* toggle, std::vector<ofxDatGuiToggle*> toggles);
    void deselectAllToggles(std::vector<ofxDatGuiToggle*> toggles);

    ofxDatGui *gui_;
    playerContainer *player_;

    std::vector<ofxDatGuiToggle*> video_toggles;
    std::vector<ofxDatGuiToggle*> palette_toggles;
    std::vector<ofxDatGuiToggle*> mode_toggles;
    ofxDatGuiColorPicker* color_picker;

    std::map<std::string, std::string> video_map;
    std::map<std::string, std::string> palette_map;
    std::map<std::string, SystemMode> mode_map;

    ofColor color;

    ofxDatGuiTheme *active_theme_;
    ofxDatGuiTheme *inactive_theme_;
};


#endif //OPENFRAMEWORKS_GUIBLOCK_HPP
