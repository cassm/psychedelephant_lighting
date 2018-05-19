//
// Created by Cass May on 11/05/2018.
//

#ifndef OPENFRAMEWORKS_SHAREDTYPES_HPP
#define OPENFRAMEWORKS_SHAREDTYPES_HPP

#include "ofMain.h"

enum SystemMode { SET_FROM_SCREEN,
                  SET_FROM_VIDEO,
                  SET_FROM_MANUAL,
                  SMOOTH_PALETTE,
};

struct playerContainer {
    playerContainer() : brightness(100), mode(SET_FROM_SCREEN), color(0) {}
    ofVideoPlayer player;
    bool switch_video;
    std::string video_name;
    float brightness;
    SystemMode mode;
    ofColor color;
};

#endif //OPENFRAMEWORKS_SHAREDTYPES_HPP
