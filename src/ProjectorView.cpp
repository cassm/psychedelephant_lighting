//
// Created by Cass May on 01/06/2018.
//

#include "ProjectorView.hpp"

void ProjectorView::setup() {
    ofSetBackgroundColor(0, 0, 0);
    screen_mask.load("projectionMaskBlack.png");
}

void ProjectorView::update() {
    if (*video_title != last_title) {
        last_title = *video_title;
        player.load(*video_title);
//            screen_player.player->setUseTexture(true);
        player.play();
        player.setVolume(0);
    }
    player.update();
}

void ProjectorView::draw() {
    int proj_skew = *skew;
//    int proj_skew = -252;
    glDisable (GL_DEPTH_TEST);   // Enables Depth Testing
    float height = ofGetHeight();
    float maskWidth = height / screen_mask.getHeight() * screen_mask.getWidth() * *width_factor;
    float videoWidth = height / player.getHeight() * player.getWidth() * *width_factor;

    ofSetColor(255 * *brightness);
    player.draw((ofGetWidth() + proj_skew - videoWidth) / 2, 0, videoWidth, height);
    ofSetColor(255);
    screen_mask.draw((ofGetWidth() + proj_skew - maskWidth) / 2, 0, maskWidth, height);
}
