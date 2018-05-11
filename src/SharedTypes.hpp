//
// Created by Cass May on 11/05/2018.
//

#ifndef OPENFRAMEWORKS_SHAREDTYPES_HPP
#define OPENFRAMEWORKS_SHAREDTYPES_HPP

struct playerContainer {
    ofVideoPlayer player;
    std::vector<std::string> videos;
    std::vector<std::string>::iterator it;
    bool switch_video;
};

#endif //OPENFRAMEWORKS_SHAREDTYPES_HPP
