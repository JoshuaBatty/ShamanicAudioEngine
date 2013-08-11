//
//  guiSampleLoad.h
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 11/08/13.
//
//


#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "audioSample.h"

class GuiSampleLoad {
	
	public :
	~GuiSampleLoad();/* deconsructor is very useful */
	void setup(AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4);
    
    AudioSampler  *audioSample1, *audioSample2, *audioSample3, *audioSample4;

    //Gui
    ofxUICanvas *guiSample1,*guiSample2,*guiSample3,*guiSample4;
	void guiEvent(ofxUIEventArgs &e);
    void drawData();
    
    ofxUIToggleMatrix *matrix1,*matrix2,*matrix3,*matrix4;
    vector<int> getToggleMatrixValues(string received_name , ofxUIEventArgs &e);
    int row[4];
    int col[4];
    bool val[4];

    
    void triggerSynthPreset1(int _value1); void triggerSynthPreset2(int _value1); void triggerSynthPreset3(int _value1); void triggerSynthPreset4(int _value1);
    void triggerSynthPreset5(int _value1); void triggerSynthPreset6(int _value1); void triggerSynthPreset7(int _value1); void triggerSynthPreset8(int _value1);
    
    int curPreset;
    int guiOffset;
    
};
