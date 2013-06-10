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
    
};
