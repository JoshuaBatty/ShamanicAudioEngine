//
//  Wave.h
//  emptyExample
//
//  Created by Joshua Batty on 11/07/13.
//
//

#pragma once

#include "ofMain.h"

class Wave{
public:
    Wave(){
        speed = 0.2;
        position = 0.0;
        amplitude = 10.0;
        offset = 0.0f;
        period = 500.0;
    };
    
    void setup(float _min, float _max);
    void calculate(float _position, float _amp, float _speed, float _offset);
    void display();
    float value1();
    float value2();
    float value3();
    float value4();
    
    int xspacing; // How far apart should each horizontal location be spaced
    
    ofVec2f origin;          // Where does the wave's first point start
    float theta;       // Start angle at 0
    float period;            // How many pixels before the wave repeats
    float dx;                // Value for incrementing X, to be calculated as a function of period and xspacing
    float yvalues[4];         // Using an array to store height values for the wave (not entirely necessary)

    float amplitude;         // Height of wave
    float speed;
    float position;
    float offset;
    
private:
    float min,max;
    
};
