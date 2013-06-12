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
	void setup(Tween *_tween1, Tween *_tween2, Tween *_tween3, Tween *_tween4, AudioBinaural *_audioBinaural, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4);

    AudioBinaural *audioBinaural;
    AudioSampler  *audioSample1, *audioSample2, *audioSample3, *audioSample4;
    Tween *tween1, *tween2, *tween3, *tween4;
    //Gui
    ofxUICanvas *guiBinaural, *gui1, *gui2, *gui3, *gui4, *gui5, *gui6, *gui7;
	void guiEvent(ofxUIEventArgs &e);
    void drawData();
    
    int curPreset;
    int guiOffset;
    
    //Master Page
    bool bUseSpeedMaster, bUseSpeed1, bUseSpeed2, bUseSpeed3, bUseSpeed4;
    bool bUsePitchMaster, bUsePitch1, bUsePitch2, bUsePitch3, bUsePitch4;
    bool bUseJitterMaster, bUseJitter1, bUseJitter2, bUseJitter3, bUseJitter4;
    bool bUseJitterQuantizeMaster, bUseJitterQuantize1, bUseJitterQuantize2, bUseJitterQuantize3, bUseJitterQuantize4;;
    bool bUseGrainSizeMaster, bUseGrainSize1, bUseGrainSize2, bUseGrainSize3, bUseGrainSize4;
    bool bUseOverlapsMaster, bUseOverlaps1, bUseOverlaps2, bUseOverlaps3, bUseOverlaps4;
    bool bUseRandomGrainSizeMaster, bUseRandomGrainSize1, bUseRandomGrainSize2, bUseRandomGrainSize3, bUseRandomGrainSize4;
    bool bUseRandomGrainPitchMaster, bUseRandomGrainPitch1, bUseRandomGrainPitch2, bUseRandomGrainPitch3, bUseRandomGrainPitch4;
    //DSP
    bool bUseCutoffMaster, bUseCutoff1, bUseCutoff2, bUseCutoff3, bUseCutoff4;
    bool bUseCutoffLFOMaster, bUseCutoffLFO1, bUseCutoffLFO2, bUseCutoffLFO3, bUseCutoffLFO4;
    bool bUseCrushMaster, bUseCrush1, bUseCrush2, bUseCrush3, bUseCrush4;
    bool bUseBitsMaster, bUseBits1, bUseBits2, bUseBits3, bUseBits4;
    bool bUseDelayTimeMaster, bUseDelayTime1, bUseDelayTime2, bUseDelayTime3, bUseDelayTime4;
    bool bUseDelayFeedbackMaster, bUseDelayFeedback1, bUseDelayFeedback2, bUseDelayFeedback3, bUseDelayFeedback4;
    bool bUseReverbDecayMaster, bUseReverbDecay1, bUseReverbDecay2, bUseReverbDecay3, bUseReverbDecay4;
    bool bUseReverbDryWetMaster, bUseReverbDryWet1, bUseReverbDryWet2, bUseReverbDryWet3, bUseReverbDryWet4;
    
};
