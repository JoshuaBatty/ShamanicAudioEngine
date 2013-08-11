//
//  mainTimeline.h
//  emptyExample
//
//  Created by Joshua Batty on 2/02/13.
//
//

#include "ofMain.h"
#include "ofxTimeline.h"
#include "gui.h"
#include "guiBinaural.h"
#include "ofxTLAudioTrack.h"
#include "audioBinaural.h"
#include "audioSample.h"

#ifndef _MAINTIMELINE
#define _MAINTIMELINE


class MainTimeline {
	
	public :
	
	void setup(Gui *gui, GuiBinaural *_guiBinaural, AudioSampler *_audioSampler1, AudioBinaural *_audioBinaural);
	void update();
    float getCurrentTimeMillis();
    void saveAutomation();
    void bangFired(ofxTLBangEventArgs& bang);
	void draw();
	void play();
	void show();
	void hide();
	
	ofxTimeline timeline;
    ofxTimeline synthTimeline;
	ofxTLAudioTrack waveform;

    Gui *Mgui;
    GuiBinaural *MguiBinaural;
    AudioBinaural *audioBinaural;
    AudioSampler *audioSampler1;

    
	private :
    
};
#endif