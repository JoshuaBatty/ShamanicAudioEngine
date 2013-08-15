#pragma once

#include "ofMain.h"
#include "audioSample.h"
#include "AudioTonicBinaural.h"
#include "AudioTonic.h"
#include "gui.h"
#include "guiBinaural.h"
#include "guiSampleLoad.h"

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
    AudioTonic audioTonic;
    AudioTonicBinaural audioTonicBinaural;

	AudioSampler audioSample1; //Drums
	AudioSampler audioSample2; //Bells
	AudioSampler audioSample3; //Throat
	AudioSampler audioSample4; //Icaros
   
    ofSoundMixer mixer;
    
    ofShader shader;
    ofShader shaderOptical;
    
    Gui gui;
    GuiBinaural guiBinaural;
    GuiSampleLoad guiSampleLoad;
    
    oscReciever osc;

    TweenSynth tweenSynth;
    Tween tween1;
    Tween tween2;
    Tween tween3;
    Tween tween4;
    
    ofPoint dragPt;
    
    int loadBox1X,loadBox2X,loadBox3X,loadBox4X;
    int loadBox1Y,loadBox2Y,loadBox3Y,loadBox4Y;

};
