#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    int numParticles = 1500;
    slipper.load("images/slipper.png");



    for (int i = 0; i < numParticles; i++) {
        Particle newParticle;
        newParticle.reset();
        particles.push_back(newParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(10,10,10);

    for (int i = 0; i < particles.size(); i++) {
        //particles[i].draw();
//        if(i%3==0){
//            ofSetColor(255,255,0);
//            ofDrawRectangle(particles[i].position.x,particles[i].position.y,50,50);
//        }
//        if(i%3==1){
//            ofSetColor(255,0,0);
//            ofDrawRectangle(particles[i].position.x,particles[i].position.y,50,50);
//        }
//        if(i%3==2){
//            ofSetColor(255,255,255);
//            ofDrawRectangle(particles[i].position.x,particles[i].position.y,50,50);
//        }
       ofSetColor(255,255,255);
       slipper.draw(particles[i].position.x,particles[i].position.y,ofRandom(20,60),ofRandom(20,60));
       ofSetColor(0,0,0,10);
       ofDrawLine(ofGetMouseX()+25,ofGetMouseY()+25,particles[i].position.x,particles[i].position.y);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    for (int i = 0; i < particles.size(); i++) {
        particles[i].toggleMode();
    }
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
