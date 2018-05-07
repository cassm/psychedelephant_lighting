#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundColor(0, 0, 0);
//    proj.load("projectionMaskBlack.png");
    ofSetBackgroundColor(32, 32, 32);
    proj.load("projectionMaskGrey.png");

    videos.emplace_back("big_sheep.mp4");
    videos.emplace_back("hx-01-00.mp4");
    videos.emplace_back("hx-01-01.mp4");
    videos.emplace_back("hxv1410.mp4");
    videos.emplace_back("lava_lamp_green_ae_blur.mp4");
    videos.emplace_back("smoke.mp4");
    videos.emplace_back("shpongle.mp4");
    videos.emplace_back("big.mp4");
    videos.emplace_back("warp.mp4");
    videos.emplace_back("pulsate.mp4");
    videos.emplace_back("pshooo.mp4");
    videos.emplace_back("ripple.mp4");
    videos.emplace_back("wobble.mp4");
    videos.emplace_back("swoosh.mp4");
    videos.emplace_back("hors.mp4");
    videos.emplace_back("fire_loop.mp4");

    video_it = videos.begin();

    switch_video = false;

    num_leds = 150;
    cylinder_rotation = 0;

    hex_sender.init("/dev/tty.usbmodem364421");

    myPlayer.load(*video_it);
    myPlayer.setUseTexture(true);
    myPlayer.setVolume(0);
    myPlayer.setSpeed(0);
    myPlayer.play();

    int leds_per_strand = 43;
    hexes.emplace_back(LedHexagon(0, 3, leds_per_strand, 2.5, 5.5));
    hex_sender.set_num_leds(0, 3*leds_per_strand);
    hexes.emplace_back(LedHexagon(1, 4, leds_per_strand, 3.5, 5.5));
    hex_sender.set_num_leds(1, 4*leds_per_strand);
    hexes.emplace_back(LedHexagon(2, 5, leds_per_strand, 4.5, 5.5));
    hex_sender.set_num_leds(2, 5*leds_per_strand);
    hexes.emplace_back(LedHexagon(3, 6, leds_per_strand, 5.5, 5.5));
    hex_sender.set_num_leds(3, 6*leds_per_strand);
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
    float screenDiameter = 1.68;
    float height = ofGetHeight() / 5.5 * screenDiameter;
    float maskWidth = height/proj.getHeight() * proj.getWidth();
    float videoWidth = height/myPlayer.getHeight() * myPlayer.getWidth();

    myPlayer.draw(ofGetWidth()/2 - videoWidth/2, ofGetHeight()/2 - height/2, videoWidth, height);
    proj.draw(ofGetWidth()/2 - maskWidth/2, ofGetHeight()/2 - height/2, maskWidth, height);

//    cylinder.init(28, 350, cylinder_rotation, 13.9, num_leds);
//    cylinder.setPixels(myPlayer.getPixels());
//    cylinder.render(ofPoint((float)ofGetWidth()/2, (float)ofGetHeight()/2, 0), 5, 1);

    for (auto &hex : hexes) {
        hex.setPixels(myPlayer.getPixels());
        hex.render(ofPoint((float)(ofGetWidth() - ofGetHeight())/2, 0, 0), 2, (float)ofGetHeight());
        hex_sender.setPixels(hex.get_strand_id(), hex.getPixels());
        hex_sender.send(hex.get_strand_id());
    }
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
