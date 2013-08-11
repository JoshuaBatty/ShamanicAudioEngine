#pragma once

#include "ofMain.h"
#include "audioSample.h"
#include "audioBinaural.h"
#include "AudioTonic.h"
#include "gui.h"
#include "guiBinaural.h"
#include "HarmonicMotion.h"

#include "livid.h"			// Livid Controler
#include "oscReciever.h"
#include "tween.h"
#include "tweenSynth.h"

#include "mainTimeline.h"

#define _USE_MIDI // uncomment to use GUI

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void dragEvent(ofDragInfo dragInfo);
        void audioOut(float * output, int bufferSize, int nChannels);

#ifdef _USE_MIDI
    livid mLivid;
#endif
    
    //Harmonic Mtion
    HarmonicMotion motion;
    
    //Timeline
    MainTimeline timeline;
    
    //Audio out
    ofSoundStream soundStream;
	AudioBinaural audioBinaural;
    AudioTonic audioTonic;
	AudioSampler audioSample1; //Drums
   
    ofSoundMixer mixer;

    Gui gui;
    GuiBinaural guiBinaural;
    
    oscReciever osc;

    TweenSynth tweenSynth;
    Tween tween1;

    ofPoint dragPt;
    
    int loadBox1X;
    int loadBox1Y;

};
