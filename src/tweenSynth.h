//
//  tweenSynth.h
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 31/07/13.
//
//


#pragma once

#include "ofMain.h"
#include "ofxTween.h"
#include "audioTonic.h"
#include "audioTonicBinaural.h"

class TweenSynth {
	
	public :
	void setup(AudioTonicBinaural *_audioTonicBinaural, AudioTonic *_audioTonic);
    void update();
    void trigger2();
    void setEasingType(int _easingType);
    void setEasings(ofxEasing *_easingType);

    void catchTempVariables();
    
    AudioTonicBinaural  *audioTonicBinaural;
    AudioTonic     *audioTonic;
    
    ofxTween tweenBinVolume;
    ofxTween tweenBinOscPitch;
    ofxTween tweenBinOscOffset;
    
    ofxTween tweenSynthVolume;
    ofxTween tweenSynthCarrierPitch;
    ofxTween tweenSynthCarrierOffset;
    ofxTween tweenSynthModIndex;
    ofxTween tweenSynthModLfoAmt;
    ofxTween tweenSynthModLfoSpeed;
    ofxTween tweenSynthAmpLfoAmt;
    ofxTween tweenSynthAmpLfoSpeed;

    float tempBinVolume;
    float tempBinOscPitch;
    float tempBinOscOffset;
    
    float tempSynthVolume;
    float tempSynthCarrierPitch;
    float tempSynthCarrierOffset;
    float tempSynthModIndex;
    float tempSynthModLfoAmt;
    float tempSynthModLfoSpeed;
    float tempSynthAmpLfoAmt;
    float tempSynthAmpLfoSpeed;
    
    //    ofxEasingElastic	easingsine;
    int easingType;
    ofxEasingLinear  easingLinear;
    ofxEasingExpo	 easingExpo;
    ofxEasingCirc    easingCirc;
    ofxEasingElastic easingElastic;
    ofxEasingBounce  easingBounce;
    
    unsigned delay, duration;
    
};
