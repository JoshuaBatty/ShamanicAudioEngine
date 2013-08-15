//
//  guiBinaural.h
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 1/08/13.
//
//


#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "AudioTonicBinaural.h"
#include "AudioTonic.h"
#include "tweenSynth.h"

class GuiBinaural {
	
	public :
	~GuiBinaural();/* deconsructor is very useful */
	void setup(TweenSynth *_tweenSynth, AudioTonicBinaural *_audioTonicBinaural, AudioTonic *_audioTonic);
    
    AudioTonic *audioTonic;
    AudioTonicBinaural *audioTonicBinaural;
    TweenSynth *tweenSynth;
    
    //Gui
    ofxUICanvas *guiBinaural, *guiTonic, *guiPresets;
	void guiEvent(ofxUIEventArgs &e);
    void drawData();

    ofxUIToggleMatrix *matrixTween;
    vector<int> getToggleMatrixValues(string received_name , ofxUIEventArgs &e);
    int row[1];
    int col[1];
    bool val[1];
    
    
    void setBinVolume(float _value1);
    void setBinPitch(float _value1);
    void setBinOffset(float _value1);
    void setSynthVolume(float _value1);
    void setSynthCarrierPitch(float _value1);
    void setSynthCarrierOffset(float _value1);
    void setSynthModIndex(float _value1);
    void setSynthModLfoAmt(float _value1);
    void setSynthModLfoSpeed(float _value1);
    void setSynthAmpLfoAmt(float _value1);
    void setSynthAmpLfoSpeed(float _value1);

    void triggerSynthPreset1(int _value1); void triggerSynthPreset2(int _value1); void triggerSynthPreset3(int _value1); void triggerSynthPreset4(int _value1);
    void triggerSynthPreset5(int _value1); void triggerSynthPreset6(int _value1); void triggerSynthPreset7(int _value1); void triggerSynthPreset8(int _value1);
    
    int curPreset;
    int guiOffset;

};
