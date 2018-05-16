//
// Created by Cass May on 13/05/2018.
//

#include "GuiBlock.hpp"

//ofxDatGuiColorPicker* bunting_color_picker = bunting_gui_->addColorPicker("Color Picker");
//bunting_color_picker->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
//
//ofxDatGuiSlider* bunting_brightness_slider = bunting_gui_->addSlider("Brightness", 0, 100);
//bunting_brightness_slider->bind(bunting_brightness);

GuiBlock::GuiBlock(std::string label, playerContainer *player, ofxDatGui *gui) {
    player_ = player;
    gui_ = gui;
    gui_->addHeader(label, false);
}

void GuiBlock::processButtonEvent(ofxDatGuiToggle* toggle) {
    if (selectToggleIfPresent(toggle, video_toggles)) {
        cout << "video toggle pressed: " << toggle->getLabel() << endl;
        if (video_map.count(toggle->getLabel()) > 0) {
            player_->video_name = video_map[toggle->getLabel()];
            player_->switch_video = true;
        }
    }
    else if (selectToggleIfPresent(toggle, mode_toggles)) {
        cout << "mode toggle pressed: " << toggle->getLabel() << endl;
    }
}

bool GuiBlock::selectToggleIfPresent(ofxDatGuiToggle* toggle, std::vector<ofxDatGuiToggle*> toggles) {
    for (auto &current_toggle : toggles) {
        if (toggle == current_toggle) {
            // disable all other toggles
            for (auto &other_toggle : toggles) {
                if (other_toggle->getChecked() && other_toggle != current_toggle) {
                    other_toggle->setChecked(false);
                }
            }

            return true;
        }
    }

    return false;
}

//void GuiBlock::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
//{
//    manual_color = e.color;
//}

void GuiBlock::add_video(std::string label, std::string filename, bool selected) {
    if (video_toggles.size() == 0) {
        gui_->addLabel("Videos");
    }

    video_map[label] = filename;
    video_toggles.emplace_back(gui_->addToggle(label, selected));

    if (selected) {
        selectToggleIfPresent(video_toggles.back(), video_toggles);
        player_->video_name = video_map[video_toggles.back()->getLabel()];
        player_->switch_video = true;
    }
}

void GuiBlock::add_mode(std::string label, SystemMode mode, bool selected) {
    if (mode_toggles.size() == 0) {
        gui_->addLabel("Modes");
    }

    mode_map[label] = mode;
    mode_toggles.emplace_back(gui_->addToggle(label, selected));

    if (selected) {
        selectToggleIfPresent(mode_toggles.back(), mode_toggles);
//        player_->mode_name = mode_map[mode_toggles.back()->getLabel()];
//        player_->switch_mode = true;
    }
}

void GuiBlock::add_brightness_slider() {
    ofxDatGuiSlider* brightness_slider = gui_->addSlider("Brightness", 0, 100);
    brightness_slider->bind(player_->brightness);
}
