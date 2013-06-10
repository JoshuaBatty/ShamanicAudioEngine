//
//  tween.h
//  oscReceiveExample
//
//  Created by Joshua Batty on 7/05/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxTween.h"
#include "audioSample.h"
#include "audioBinaural.h"

class Tween {
	
	public :
	void setup(AudioSampler *_audioSample);
    void update();
    void trigger();
    void trigger2();
    void trigger3();
    void catchTempVariables();
    
    AudioSampler  *audioSample;
    
    ofxTween tweenVolume;
    ofxTween tweenPitch;
    ofxTween tweenSpeed;
    ofxTween tweenGrainLength;
    ofxTween tweenOverlaps;
    ofxTween tweenRandomGrainPitch;
    ofxTween tweenRandomGrainSize;
    ofxTween tweenDelayTime;
    ofxTween tweenDelayFeedback;
    ofxTween tweenCutoff;
    ofxTween tweenLfoSpeed;
    ofxTween tweenLfoAmp;
    ofxTween tweenBits;
    ofxTween tweenRate;
    ofxTween tweenReverbSize;
    ofxTween tweenReverbDryWet;
    
    
    float tempVolume;
    float tempPitch;
    float tempSpeed;
    float tempGrainLength;
    float tempOverlaps;
    float tempRandomGrainPitch;
    float tempRandomGrainSize;
    float tempDelayTime;
    float tempDelayFeedback;
    float tempCutoff;
    float tempLfoSpeed;
    float tempLfoAmp;
    float tempReverbSize;
    float tempReverbDryWet;
    float tempRate;
    int   tempBits;
    
    ofxEasingElastic	easingsine;
    
    unsigned delay, duration;
    
};
