#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundColor(0, 0, 0);
//    proj.load("projectionMaskBlack.png");
    ofSetBackgroundColor(32, 32, 32);
    proj.load("projectionMaskGrey.png");

    hex_player.videos.emplace_back("HX-01.mp4");
    hex_player.videos.emplace_back("hx-01-bonus-01.mp4");
    hex_player.videos.emplace_back("hx-01-bonus-02.mp4");
    hex_player.videos.emplace_back("big_sheep.mp4");
    hex_player.videos.emplace_back("shpongle.mp4");

    cylinder_player.videos.emplace_back("fire_loop.mp4");
    cylinder_player.videos.emplace_back("hx-01-bonus-01.mp4");
    cylinder_player.videos.emplace_back("big_sheep.mp4");
    cylinder_player.videos.emplace_back("smoke.mp4");
    cylinder_player.videos.emplace_back("swoosh.mp4");

//    videos.emplace_back("lava_lamp_green_ae_blur.mp4");
//    videos.emplace_back("smoke.mp4");
//    videos.emplace_back("big.mp4");
//    videos.emplace_back("warp.mp4");
//    videos.emplace_back("pulsate.mp4");
//    videos.emplace_back("pshooo.mp4");
//    videos.emplace_back("ripple.mp4");
//    videos.emplace_back("wobble.mp4");
//    videos.emplace_back("swoosh.mp4");
//    videos.emplace_back("hors.mp4");

    hex_player.it = hex_player.videos.begin();
    cylinder_player.it = cylinder_player.videos.begin();

    hex_player.switch_video = false;
    cylinder_player.switch_video = false;

    num_leds = 150;

    hex_sender.init("/dev/tty.usbmodem364421");
    cylinder_sender.init("/dev/tty.usbmodem364541");

    float cylinder_radius = 330;
    cylinders.emplace_back(LedCylinder(0, ofPoint(cylinder_radius*sin(3.14/6), cylinder_radius*cos(3.14/6)), 7.5, 35, 5*3.14/6, 13.9, num_leds));
    cylinder_sender.set_num_leds(0, 150);
    cylinders.emplace_back(LedCylinder(1, ofPoint(330, 0), 7.5, 35, 3.14/2, 13.9, num_leds));
    cylinder_sender.set_num_leds(1, 150);
    cylinders.emplace_back(LedCylinder(2, ofPoint(cylinder_radius*sin(5*3.14/6), cylinder_radius*cos(5*3.14/6)), 7.5, 35, 3.14/6, 13.9, num_leds));
    cylinder_sender.set_num_leds(2, 150);
    cylinders.emplace_back(LedCylinder(3, ofPoint(cylinder_radius*sin(7*3.14/6), cylinder_radius*cos(7*3.14/6)), 7.5, 35, -3.14/6, 13.9, num_leds));
    cylinder_sender.set_num_leds(3, 150);
    cylinders.emplace_back(LedCylinder(4, ofPoint(-330, 0), 7.5, 35, -3.14/2, 14.9, num_leds));
    cylinder_sender.set_num_leds(4, 150);
    cylinders.emplace_back(LedCylinder(5, ofPoint(cylinder_radius*sin(11*3.14/6), cylinder_radius*cos(11*3.14/6)), 7.5, 35, -5*3.14, 13.9, num_leds));
    cylinder_sender.set_num_leds(5, 150);

    hex_player.player.load(*hex_player.it);
    hex_player.player.setUseTexture(true);
//    hex_player.player.setVolume(0);
//    hex_player.player.setSpeed(0);
    hex_player.player.play();

    cylinder_player.player.load(*cylinder_player.it);
    cylinder_player.player.setUseTexture(true);
    cylinder_player.player.setVolume(0);
//    cylinder_player.setSpeed(0);
    cylinder_player.player.play();

    int leds_per_strand = 43;
    hexes.emplace_back(LedHexagon(0, 3, leds_per_strand, 250, 550));
    hex_sender.set_num_leds(0, 3*leds_per_strand);
    hexes.emplace_back(LedHexagon(1, 4, leds_per_strand, 350, 550));
    hex_sender.set_num_leds(1, 4*leds_per_strand);
    hexes.emplace_back(LedHexagon(2, 5, leds_per_strand, 450, 550));
    hex_sender.set_num_leds(2, 5*leds_per_strand);
    hexes.emplace_back(LedHexagon(3, 6, leds_per_strand, 550, 550));
    hex_sender.set_num_leds(3, 6*leds_per_strand);
}

//--------------------------------------------------------------
void ofApp::update(){
    hex_player.player.update();
    cylinder_player.player.update();

    if (hex_player.switch_video) {
        hex_player.it++;
        if (hex_player.it == hex_player.videos.end()) {
            hex_player.it = hex_player.videos.begin();
        }
        hex_player.player.load(*hex_player.it);
        hex_player.player.setUseTexture(true);
        hex_player.player.play();

        hex_player.switch_video = false;
    }
    if (cylinder_player.switch_video) {
        cylinder_player.it++;
        if (cylinder_player.it == cylinder_player.videos.end()) {
            cylinder_player.it = cylinder_player.videos.begin();
        }
        cylinder_player.player.load(*cylinder_player.it);
        cylinder_player.player.setUseTexture(true);
        cylinder_player.player.play();

        cylinder_player.switch_video = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    cam.begin();


    cam.setDistance(400); // start at the edge of the dome
    ofRotateX(90); // work on the horizontal plane
    ofTranslate(0,0,-150); // raise roof

    ofSetColor(128,128,128);
    ofDrawCircle(ofPoint(0,0,500), 500); // draw floor
    ofSetColor(255,255,255);

    ofTranslate(camOffset); // move with wsad

    float screenDiameter = 168;
    float height = screenDiameter;
    float maskWidth = height / proj.getHeight() * proj.getWidth();
    float videoWidth = height / hex_player.player.getHeight() * hex_player.player.getWidth();

    hex_player.player.draw(0 - videoWidth / 2, 0 - height / 2, videoWidth, height);
    proj.draw(maskWidth / -2, height / -2, 0.125, maskWidth, height);
    proj.draw(maskWidth / -2, height / -2, -0.125, maskWidth, height);

    int i = 1;

    for (auto &hex : hexes) {
        hex.setPixels(hex_player.player.getPixels());
        hex.render(ofPoint(0, 0, i++ * 10), 1, 550);
        hex_sender.setPixels(hex.get_strand_id(), hex.getPixels());
        hex_sender.send(hex.get_strand_id());
    }

    for (auto &cylinder : cylinders) {
        cylinder.setPixels(cylinder_player.player.getPixels());
        cylinder.render(ofPoint(0, 0, 60 + 35 / 2), 2, 1);
        cylinder_sender.setPixels(cylinder.strand_id_, cylinder.getPixels());
        cylinder_sender.send(cylinder.strand_id_);
    }

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'h') {
        hex_player.switch_video = true;
    }
    else if (key == 'c') {
        cylinder_player.switch_video = true;
    }
    else if (key == 'w') {
        camOffset.y += 20;
    }
    else if (key == 's') {
        camOffset.y -= 20;
    }
    else if (key == 'a') {
        camOffset.x += 20;
    }
    else if (key == 'd') {
        camOffset.x -= 20;
    }
    else if (key == 'r') {
        cam.setOrientation(ofVec3f(0,0,0));
        camOffset = ofPoint(0,0,0);
    }

    ofRotateX(90); // work on the horizontal plane
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
