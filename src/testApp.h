#pragma once

#include "ofMain.h"
#include "audioSample.h"
#include "WavFile.h"
#include "gui.h"
#include "livid.h"			// Livid Controler
#include "oscReciever.h"
#include "tween.h"
#include "mainTimeline.h"

//#define _USE_MIDI // uncomment to use GUI

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
    
    //Timeline
    MainTimeline timeline;
    
    //Audio out
    ofSoundStream soundStream;
    
	AudioSampler audioSample1; //Drums
   
    ofSoundMixer mixer;
    
    //Audio Recording
    WavFile myWavWriter;
    bool bIsRecording;
    
    ofShader shader;
    Gui gui;
    oscReciever osc;
    Tween tween1;
    
    ofPoint dragPt;
    
    int loadBox1X,loadBox1Y;

};
