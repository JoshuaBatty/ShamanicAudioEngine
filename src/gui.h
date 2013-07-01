//
//  gui.h
//  emptyExample
//
//  Created by Joshua Batty on 22/02/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "audioSample.h"
#include "audioBinaural.h"
#include "tween.h"

class Gui {
	
	public :
	~Gui();/* deconsructor is very useful */
	void setup(Tween *_tween1, AudioSampler *_audioSample1);

    AudioSampler  *audioSample1;
    Tween *tween1;
    //Gui
    ofxUICanvas *guiBinaural, *gui1, *gui2, *gui6, *gui7;
	void guiEvent(ofxUIEventArgs &e);
    void drawData();
    
    int curPreset;
    int guiOffset;
    
    //Master Page
    bool bUseSpeed1;
    bool bUsePitch1;
    bool bUseJitter1;
    bool bUseJitterQuantize1;
    bool bUseGrainSize1;
    bool bUseOverlaps1;
    bool bUseRandomGrainSize1;
    bool bUseRandomGrainPitch1;
    //DSP
    bool bUseCutoff1;
    bool bUseCutoffLFO1;
    bool bUseCrush1;
    bool bUseBits1;
    bool bUseDelayTime1;
    bool bUseDelayFeedback1;
    bool bUseReverbDecay1;
    bool bUseReverbDryWet1;
    
};
