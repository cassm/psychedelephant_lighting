#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    videos.emplace_back("fire_loop.mp4");
    videos.emplace_back("lava_lamp_green_ae_blur.mp4");
    videos.emplace_back("fier_blur.mp4");
    videos.emplace_back("big_sheep_blur.mp4");
    videos.emplace_back("smoke.mp4");
    videos.emplace_back("fier.mp4");
    videos.emplace_back("big_sheep.mp4");
    videos.emplace_back("shpongle.mp4");
    videos.emplace_back("big.mp4");
    videos.emplace_back("warp.mp4");
    videos.emplace_back("pulsate.mp4");
    videos.emplace_back("pshooo.mp4");
    videos.emplace_back("ripple.mp4");
    videos.emplace_back("wobble.mp4");
    videos.emplace_back("swoosh.mp4");
    videos.emplace_back("hors.mp4");

    video_it = videos.begin();

    switch_video = false;

    num_leds = 150;
    cylinder_rotation = 0;
    sender.init("/dev/tty.usbmodem364541");

    sender.set_num_leds(2, num_leds);

    myPlayer.load(*video_it);
    myPlayer.setUseTexture(true);
    myPlayer.setVolume(0);
    myPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    myPlayer.update();

    if (switch_video) {
        video_it++;
        if (video_it == videos.end()) {
            video_it = videos.begin();
        }
        myPlayer.load(*video_it);
        myPlayer.setUseTexture(true);
        myPlayer.play();

        switch_video = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cylinder.init(28, 350, cylinder_rotation, 13.9, num_leds);
    cylinder.setPixels(myPlayer.getPixels());
    cylinder.render(ofPoint((float)ofGetWidth()/2, (float)ofGetHeight()/2, 0), 5, 1);
    sender.setPixels(2, cylinder.getPixels());
    sender.send(2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    float rotationIncrement = 3.14 / 18; // 10 degrees

    if (key == ' ') {
        switch_video = true;
    }
    else if (key == OF_KEY_RIGHT) {
        cylinder_rotation -= rotationIncrement;
    }
    else if (key == OF_KEY_LEFT) {
        cylinder_rotation += rotationIncrement;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
