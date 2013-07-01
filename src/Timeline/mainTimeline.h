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
#include "ofxTLAudioTrack.h"
#include "audioBinaural.h"
#include "audioSample.h"

#ifndef _MAINTIMELINE
#define _MAINTIMELINE


class MainTimeline {
	
	public :
	
	void setup(Gui *gui, AudioSampler *_audioSampler1);
	void update();
    float getCurrentTimeMillis();
    void saveAutomation();
	void draw();
	void play();
	void show();
	void hide();
	
	ofxTimeline timeline;
	ofxTLAudioTrack waveform;

    Gui *Mgui;
    AudioSampler *audioSampler1;
    
	private :
    
};
#endif