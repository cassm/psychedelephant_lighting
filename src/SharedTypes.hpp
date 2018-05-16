//
// Created by Cass May on 11/05/2018.
//

#ifndef OPENFRAMEWORKS_SHAREDTYPES_HPP
#define OPENFRAMEWORKS_SHAREDTYPES_HPP

struct playerContainer {
    playerContainer() { brightness = 100; }
    ofVideoPlayer player;
    bool switch_video;
    std::string video_name;
    float brightness;
};

enum SystemMode { SET_FROM_SCREEN,
                   SET_FROM_MANUAL,
};

#endif //OPENFRAMEWORKS_SHAREDTYPES_HPP
