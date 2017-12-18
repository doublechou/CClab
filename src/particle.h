//
//  Particle.hpp
//  particlesAdvanced
//
//  Created by Jonathan Beilin on 11/6/17.
//

#ifndef Particle_h
#define Particle_h

#include <stdio.h>

#include "ofMain.h"

class Particle {
public:
    void reset();
    void update();
    void draw();
    void setup();

    void toggleMode();

    ofPoint position;
    ofPoint velocity;
    ofPoint force;
    float drag;

    ofImage slipper;

    bool isAttracting = true;


};

#endif /* Particle_hpp */
