//
//  Wave.cpp
//  emptyExample
//
//  Created by Joshua Batty on 11/07/13.
//
//

#include "Wave.h"

//--------------------------------------------------------------
void Wave::setup(float _min, float _max){
    min = _min;
    max = _max;
    
    position = 0.0;
    amplitude = 0.0;
    speed = 0.0;
    offset = 0.0;
    
    xspacing = 48;
    theta = 0.0;

    dx = (TWO_PI / period) * xspacing;
}

//--------------------------------------------------------------
void Wave::calculate(float _position, float _amp, float _speed, float _offset){
    position = _position;
    amplitude = _amp;
    speed = _speed;
    offset = _offset;
    
    speed = ofMap(speed,0,127,0.0,0.5);
    offset = ofMap(offset,0,127,0.0,0.01);
    // Increment theta (try different values for 'angular velocity' here
    theta += speed;

    // For every x value, calculate a y value with sine function
    float x = theta;
    for (int i = 0; i < 4; i++) {
//        yvalues[i] = ofClamp(sin(x)*amplitude+position,min,max);
        yvalues[i] = ofClamp(sin(x)*ofMap(amplitude,0,127,min,max)+position,min,max);
   //     cout << "amp = " << amplitude << endl;

        x+=dx;
        dx+=offset; //This is my Line of code
    }
}

//--------------------------------------------------------------
void Wave::display(){
    // A simple way to draw the wave with an ellipse at each location
    for (int x = 0; x < 4; x++) {
        ofFill();
        ofSetColor(0,50);
        ofEllipse(origin.x+x*xspacing,origin.y+yvalues[x],48,48);
    }
}

//--------------------------------------------------------------
float Wave::value1(){
    return origin.y+yvalues[0];
}

//--------------------------------------------------------------
float Wave::value2(){
    return origin.y+yvalues[1];
}

//--------------------------------------------------------------
float Wave::value3(){
    return origin.y+yvalues[2];
}

//--------------------------------------------------------------
float Wave::value4(){
    return origin.y+yvalues[3];
}