#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);

    ofxDatGuiTheme *inactive_theme = new NellieThemeInactive;
    ofxDatGuiTheme *active_theme = new NellieThemeActive;

    screen_gui_obj = ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
    screen_gui = GuiBlock("Screen", &screen_player, &screen_gui_obj, active_theme, inactive_theme);
    screen_gui_obj.onButtonEvent(this, &ofApp::onScreenButtonEvent);
//    screen_gui_obj.onSliderEvent(this, &ofApp::doNothing);
    screen_gui.add_video("    HX-01 Bonus 1", "hx-01-bonus-01.mp4", true);
    screen_gui.add_video("    HX-01 Bonus 2", "hx-01-bonus-02.mp4");
    screen_gui.add_video("    HX-01", "HX-01.mp4");
    screen_gui.add_video("    Electric Sheep", "big_sheep.mp4");
    screen_gui.add_video("    Shpongle Set", "shpongle.mp4");
    screen_gui.add_video("    Clip series", "big.mp4");
    screen_gui.add_brightness_slider();
    screen_gui_obj.setTheme(inactive_theme);

    lantern_gui_obj = ofxDatGui(0, screen_gui_obj.getHeight() + 20);
    lantern_gui = GuiBlock("Lanterns", &lantern_player, &lantern_gui_obj, active_theme, inactive_theme);
    lantern_gui_obj.onButtonEvent(this, &ofApp::onLanternButtonEvent);
//    lantern_gui_obj.onSliderEvent(this, &ofApp::doNothing);
    lantern_gui.add_video("    Fire", "fire_loop.mp4", true);
    lantern_gui.add_video("    HX-01 Bonus 1", "hx-01-bonus-01.mp4");
    lantern_gui.add_video("    Electric Sheep", "big_sheep.mp4");
    lantern_gui.add_video("    Smoke", "smoke.mp4");
    lantern_gui.add_video("    Swoosh", "swoosh.mp4");
    lantern_gui.add_brightness_slider();
    lantern_gui.update_theme();
    lantern_gui_obj.setTheme(inactive_theme);

    bunting_gui_obj = ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
    bunting_gui = GuiBlock("Bunting", &bunting_player, &bunting_gui_obj, active_theme, inactive_theme);
    bunting_gui_obj.onButtonEvent(this, &ofApp::onBuntingButtonEvent);
//    bunting_gui_obj.onSliderEvent(this, &ofApp::doNothing);
    bunting_gui.add_mode("    Set from screen", SET_FROM_SCREEN, true);
    bunting_gui.add_mode("    Set manually", SET_FROM_MANUAL);
    bunting_gui_obj.addColorPicker("Manual Color");
    bunting_gui_obj.onColorPickerEvent(this, &ofApp::onBuntingColorPickerEvent);
    bunting_gui.add_video("    HX-01 Bonus 1", "hx-01-bonus-01.mp4");
    bunting_gui.add_video("    HX-01 Bonus 2", "hx-01-bonus-02.mp4");
    bunting_gui.add_video("    HX-01", "HX-01.mp4");
    bunting_gui.add_video("    Electric Sheep", "big_sheep.mp4");
    bunting_gui.add_video("    Shpongle Set", "shpongle.mp4");
    bunting_gui.add_video("    Swoosh", "swoosh.mp4");
    bunting_gui_obj.setTheme(inactive_theme);

    palette.load("base_palette.png");

    cam.resetTransform();
    cam.setFov(60);
    cam.clearParent();
    cam.setPosition(0, 0, 450);

//    ofSetBackgroundColor(0, 0, 0);
//    screen_mask.load("projectionMaskBlack.png");
    ofSetBackgroundColor(32, 32, 32);
    screen_mask.load("projectionMaskGrey.png");

    num_leds = 150;

//    bunting_sender.init("/dev/tty.usbmodem364421");
//    lantern_sender.init("/dev/tty.usbmodem364541");
    lantern_sender.init("/dev/tty.usbmodem364421");
    bunting_sender.init("/dev/tty.usbmodem364541");

    float lantern_radius = 330;
    lanterns.emplace_back(LedCylinder(0, ofPoint(lantern_radius*sin(3.14/6), lantern_radius*cos(3.14/6)), 7.5, 35, 5*3.14/6, 13.9, num_leds));
    lantern_sender.set_num_leds(0, 150);
    lanterns.emplace_back(LedCylinder(1, ofPoint(330, 0), 7.5, 35, 3.14/2, 13.9, num_leds));
    lantern_sender.set_num_leds(1, 150);
    lanterns.emplace_back(LedCylinder(2, ofPoint(lantern_radius*sin(5*3.14/6), lantern_radius*cos(5*3.14/6)), 7.5, 35, 3.14/6, 13.9, num_leds));
    lantern_sender.set_num_leds(2, 150);
    lanterns.emplace_back(LedCylinder(3, ofPoint(lantern_radius*sin(7*3.14/6), lantern_radius*cos(7*3.14/6)), 7.5, 35, -3.14/6, 13.9, num_leds));
    lantern_sender.set_num_leds(3, 150);
    lanterns.emplace_back(LedCylinder(4, ofPoint(-330, 0), 7.5, 35, -3.14/2, 14.9, num_leds));
    lantern_sender.set_num_leds(4, 150);
    lanterns.emplace_back(LedCylinder(5, ofPoint(lantern_radius*sin(11*3.14/6), lantern_radius*cos(11*3.14/6)), 7.5, 35, -5*3.14, 13.9, num_leds));
    lantern_sender.set_num_leds(5, 150);


    int leds_per_strand = 43;
    bunting_strands.emplace_back(LedHexagon(0, 3, leds_per_strand, 250, 550));
    bunting_sender.set_num_leds(0, 3*leds_per_strand);
    bunting_strands.emplace_back(LedHexagon(1, 4, leds_per_strand, 350, 550));
    bunting_sender.set_num_leds(1, 4*leds_per_strand);
    bunting_strands.emplace_back(LedHexagon(2, 5, leds_per_strand, 450, 550));
    bunting_sender.set_num_leds(2, 5*leds_per_strand);
    bunting_strands.emplace_back(LedHexagon(3, 6, leds_per_strand, 550, 550));
    bunting_sender.set_num_leds(3, 6*leds_per_strand);
}

//--------------------------------------------------------------

void ofApp::update(){
    screen_gui.update_theme();
    lantern_gui.update_theme();
    bunting_gui.update_theme();

    if (screen_player.switch_video) {
        if (screen_player.video_name != screen_player.player.getMoviePath()) {
            screen_player.player.load(screen_player.video_name);
            screen_player.player.setUseTexture(true);
            screen_player.player.play();
            screen_player.player.setVolume(0);
        }

        screen_player.switch_video = false;
    }
    if (lantern_player.switch_video) {
        if (lantern_player.video_name != lantern_player.player.getMoviePath()) {
            lantern_player.player.load(lantern_player.video_name);
            lantern_player.player.setUseTexture(true);
            lantern_player.player.play();
            lantern_player.player.setVolume(0);
        }

        lantern_player.switch_video = false;
    }
    if (bunting_player.switch_video) {
        if (bunting_player.video_name != bunting_player.player.getMoviePath()) {
            bunting_player.player.load(bunting_player.video_name);
            bunting_player.player.setUseTexture(true);
            bunting_player.player.play();
            bunting_player.player.setVolume(0);
        }

        bunting_player.switch_video = false;
    }

    screen_player.player.update();
    lantern_player.player.update();
    bunting_player.player.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    glEnable (GL_DEPTH_TEST);   // Enables Depth Testing

    cam.begin();

    ofRotateX(90); // work on the horizontal plane
    ofTranslate(0,0,-150); // raise roof

    ofSetColor(128,128,128);
    ofDrawCircle(ofPoint(0,0,350), 500); // draw floor
    ofSetColor(255,255,255);

    float screenDiameter = 168;
    float height = screenDiameter;
    float maskWidth = height / screen_mask.getHeight() * screen_mask.getWidth();
    float videoWidth = height / screen_player.player.getHeight() * screen_player.player.getWidth();

    if (screen_player.player.isLoaded()) {
        ofSetColor(255 * screen_player.brightness / 100);
        screen_player.player.draw(0 - videoWidth / 2, 0 - height / 2, videoWidth, height);
        ofSetColor(255);
    }
    screen_mask.draw(maskWidth / -2, height / -2, 0.125, maskWidth, height);
    screen_mask.draw(maskWidth / -2, height / -2, -0.125, maskWidth, height);

    int i = 1;

    for (auto &strand : bunting_strands) {
        if (bunting_player.mode == SET_FROM_SCREEN && screen_player.player.isLoaded()) {
            strand.setPixels(screen_player.player.getPixels());
        }
        else if (bunting_player.mode == SET_FROM_VIDEO && bunting_player.player.isLoaded()) {
            strand.setPixels(bunting_player.player.getPixels());
        }
        else if (bunting_player.mode == SET_FROM_MANUAL) {
            strand.setFromColor(bunting_player.color);
        }

        strand.render(ofPoint(0, 0, i++ * 10), 1, 550, static_cast<float>(bunting_player.brightness)/100);
        bunting_sender.setPixels(strand.get_strand_id(), strand.getPixels());
        bunting_sender.send(strand.get_strand_id(), static_cast<float>(bunting_player.brightness)/100);
    }

    for (auto &lantern : lanterns) {
        if (lantern_player.player.isLoaded()) {
            lantern.setPixels(lantern_player.player.getPixels());
        }
        lantern.render(ofPoint(0, 0, 60 + 35 / 2), 2, 1, static_cast<float>(lantern_player.brightness)/100);
        lantern_sender.setPixels(lantern.strand_id_, lantern.getPixels());
        lantern_sender.send(lantern.strand_id_, static_cast<float>(lantern_player.brightness)/100);
    }

    cam.end();

    glDisable (GL_DEPTH_TEST);   // Disables Depth Testing
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int kRotInc = 5;
    int kMoveInc = 10;

    switch (key) {
        case 'h':
            screen_player.switch_video = true;
            break;
        case 'c':
            lantern_player.switch_video = true;
            break;

        case OF_KEY_LEFT:
            cam.pan(kRotInc);
            break;
        case OF_KEY_RIGHT:
            cam.pan(-kRotInc);
            break;

        case OF_KEY_UP:
            cam.tilt(kRotInc);
            break;
        case OF_KEY_DOWN:
            cam.tilt(-kRotInc);
            break;

        case ',':
            cam.roll(kRotInc);
            break;
        case '.':
            cam.roll(-kRotInc);
            break;

        case 'a':
            cam.truck(-kMoveInc);
            break;
        case 'd':
            cam.truck(kMoveInc);
            break;

        case 'w':
            cam.dolly(-kMoveInc);
            break;
        case 's':
            cam.dolly(kMoveInc);
            break;

        case 'r':
            cam.boom(kMoveInc);
            break;
        case 'f':
            cam.boom(-kMoveInc);
            break;

        case 'z':
            cam.resetTransform();
            cam.setFov(60);
            cam.clearParent();
            cam.setPosition(0, 0, 450);
            break;
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
