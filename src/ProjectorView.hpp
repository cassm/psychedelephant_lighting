//
// Created by Cass May on 01/06/2018.
//

#ifndef OPENFRAMEWORKS_PROJECTORVIEW_HPP
#define OPENFRAMEWORKS_PROJECTORVIEW_HPP


#include "ofMain.h"
#include <string>
class ProjectorView : public ofBaseApp{
public:
//    ProjectorView(ofVideoPlayer *player_, float *brightness_) : player(player_), brightness(brightness_) {}
    ProjectorView(std::string *video_title_, float *brightness_, int *skew_, float *width_factor_) : last_title(""), video_title(video_title_), brightness(brightness_), skew(skew_), width_factor(width_factor_) {}
    void setup() override;
    void draw() override;
    void update() override;
private:
    std::string *video_title;
    std::string last_title;
    ofVideoPlayer player;
//    ofVideoPlayer *player;
    ofImage screen_mask;
    float *brightness;
    int *skew;
    float *width_factor;
};


#endif //OPENFRAMEWORKS_PROJECTORVIEW_HPP
