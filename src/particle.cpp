//
//  Particle.cpp
//  particlesAdvanced
//
//  Created by Jonathan Beilin on 11/6/17.
//

#include "particle.h"


void Particle::reset() {

    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    velocity.x =0;
    velocity.y=0;

//    velocity.x = ofRandom(-3.9, 3.9);
//    velocity.y = ofRandom(-3.9, 3.9);


    force = ofPoint(0, 0);
}

void Particle::update() {
    velocity+=force;
    if (isAttracting) {
        // Get mouse coords, save to
        // attractPoint
        ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());

        // calculate force
        // then normalize it
        force.x = ofRandom(-2,2);
        force.y = ofRandom(-2,2);

        // apply drag to velocity
        // apply force to velocity
        velocity= (attractPoint-position)/8;
        velocity += force;

    } else {
        ofPoint repulsePoint = ofPoint(ofGetMouseX(), ofGetMouseY());
        force = repulsePoint - position;

        float distance = force.length();
        force.normalize();

//        if (distance < 150) {
//            velocity -= force * 0.6;
//        }
    }

    // update position
    position += velocity;

}

void Particle::draw() {
    if (isAttracting) {
        ofSetColor(255, 63, 180);
    } else {
        ofSetColor(208, 255, 63);
    }


    slipper.draw(position.x,position.y,100,100);
    //ofDrawCircle(position.x, position.y, 50.0);
}

void Particle::toggleMode() {
    isAttracting = !isAttracting;
    reset();
}
