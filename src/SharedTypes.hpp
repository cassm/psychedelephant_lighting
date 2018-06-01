//
// Created by Cass May on 11/05/2018.
//

#ifndef OPENFRAMEWORKS_SHAREDTYPES_HPP
#define OPENFRAMEWORKS_SHAREDTYPES_HPP

#include "ofMain.h"

enum SystemMode { SET_FROM_SCREEN,
                  SET_FROM_VIDEO,
                  SET_FROM_MANUAL,
                  SET_FROM_PALETTE_SMOOTH,
                  SET_FROM_PALETTE_SPARKLE,
};

struct ledInfo {
    ofPoint input_mapping; // indexed 0 -> 1
    ofPoint output_mapping; // indexed 0 -> 1

    float delta;
    float theta;

    ofColor color;
    ofColor last_color;

    ofColor sparkle_color;
    std::chrono::high_resolution_clock::time_point sparkle_time;
};

enum paletteMode {
    mode_concentric,
    mode_radial,
};

struct playerContainer {
    playerContainer() : player(new ofVideoPlayer), brightness(100), mode(SET_FROM_SCREEN), color(0) {}
    ~playerContainer() {if (player != NULL) delete player;}
    ofVideoPlayer *player;
    bool switch_video;
    std::string video_name;
    float brightness;
    SystemMode mode;
    ofColor color;
};

#endif //OPENFRAMEWORKS_SHAREDTYPES_HPP
