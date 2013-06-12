#pragma once

#include "ofMain.h"
#include "audioSample.h"
#include "audioBinaural.h"
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
	AudioBinaural audioBinaural;
    
	AudioSampler audioSample1; //Drums
	AudioSampler audioSample2; //Bells
	AudioSampler audioSample3; //Throat
	AudioSampler audioSample4; //Icaros
   
    ofSoundMixer mixer;
    
    ofShader shader;
    
    Gui gui;
    
    oscReciever osc;

    Tween tween1;
    Tween tween2;
    Tween tween3;
    Tween tween4;
    
    ofPoint dragPt;
    
    int loadBox1X,loadBox2X,loadBox3X,loadBox4X;
    int loadBox1Y,loadBox2Y,loadBox3Y,loadBox4Y;

};
