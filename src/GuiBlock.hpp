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

class ofApp;

class GuiBlock {
public:
    GuiBlock() = default;
    GuiBlock(std::string label, playerContainer *player, ofxDatGui *gui);

    void processButtonEvent(ofxDatGuiToggle* toggle);

    void add_video(std::string label, std::string filename, bool selected=false);
    void add_mode(std::string label, SystemMode mode, bool selected=false);
    void add_brightness_slider();

public:
    bool selectToggleIfPresent(ofxDatGuiToggle* toggle, std::vector<ofxDatGuiToggle*> toggles);

    ofxDatGui *gui_;
    playerContainer *player_;

    std::vector<ofxDatGuiToggle*> video_toggles;
    std::vector<ofxDatGuiToggle*> mode_toggles;
    ofxDatGuiColorPicker* color_picker;

    std::map<std::string, std::string> video_map;
    std::map<std::string, SystemMode> mode_map;

    ofColor color;
};


#endif //OPENFRAMEWORKS_GUIBLOCK_HPP
