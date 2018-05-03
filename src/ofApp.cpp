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

    uint16_t num_leds = 150;
    cylinder.init(28, 350, 13.9, num_leds);
    sender.init("/dev/tty.usbmodem364541");
    sender.add_strand(7, 4, num_leds);

    myPlayer.load(*video_it);
    myPlayer.setUseTexture(true);
    myPlayer.setVolume(0);
    myPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cylinder.setPixels(myPlayer.getPixels());
    cylinder.render(ofPoint((float)ofGetWidth()/2, (float)ofGetHeight()/2, 0), 5);
    sender.setPixels(7, cylinder.getPixels());
    sender.send(7);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        video_it++;
        if (video_it == videos.end()) {
            video_it = videos.begin();
        }
        myPlayer.load(*video_it);
        myPlayer.setUseTexture(true);
        myPlayer.play();
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
