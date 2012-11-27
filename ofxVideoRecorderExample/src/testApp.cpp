#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_ERROR);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    vidRecorder.setup("testMovie.mov", vidGrabber.getWidth(), vidGrabber.getHeight(), 30);
//    vidRecorder.setupCustomOutput(vidGrabber.getWidth(), vidGrabber.getHeight(), 15, "-vcodec h264 -sameq -f mpegts udp://localhost:1234"); // with custom ffmpeg output string

    ofSetWindowShape(640,480);
}

void testApp::exit() {
    vidRecorder.close();
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew()) {
        vidRecorder.addFrame(vidGrabber.getPixelsRef());
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    vidGrabber.draw(0,0);
    char title[256];
    sprintf(title,"frames in queue: %d\nfps: %.2f", vidRecorder.getNumFramesInQueue(), ofGetFrameRate());
    ofDrawBitmapString(ofToString(title),20,20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='c')
        vidRecorder.close();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
