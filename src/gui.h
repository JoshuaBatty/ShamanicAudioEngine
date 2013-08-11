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
#include "tween.h"

class Gui {
	
	public :
	~Gui();/* deconsructor is very useful */
	void setup(Tween *_tween1, AudioSampler *_audioSample1);

    AudioSampler  *audioSample1;
    Tween *tween1;
    //Gui
    ofxUICanvas *gui1, *gui2, *gui7;
	void guiEvent(ofxUIEventArgs &e);
    void drawData();

 //   vector<ofxUIToggle *> toggles1;
 //   vector<ofxUIToggle *> toggles2;
 //   vector<ofxUIToggle *> toggles3;
 //   vector<ofxUIToggle *> toggles4;
 //   vector<ofxUIToggle *> togglesTween;
    ofxUIToggleMatrix *matrix1;
    ofxUIToggleMatrix *matrix2;
    ofxUIToggleMatrix *matrix3;
    ofxUIToggleMatrix *matrix4;
    ofxUIToggleMatrix *matrixTween;
    vector<int> getToggleMatrixValues(string received_name , ofxUIEventArgs &e);
    int row[5];
    int col[5];
    bool val[5];


    void setVolume1(float _value1);
    void setSpeed1(float _value1);
    void setPitch1(float _value1);
    void setRandomGrainPitch1(float _value1);
    void setGrainSize1(float _value1);
    void setRandomGrainSize1(float _value1);
    void setOverlaps1(float _value1); 
    void setCutoff1(float _value1); 
    void setLfoSpeed1(float _value1);
    void setLfoAmp1(float _value1); 
    void setRate1(float _value1);
    void setDelayTime1(float _value1); 
    void setDelayFeedback1(float _value1); 
    void setReverbDecay1(float _value1);
    void setReverbDryWet1(float _value1);
  
//    void setPanPosition1(float _value1); void setPanPosition2(float _value1); void setPanPosition3(float _value1); void setPanPosition4(float _value1);
//    void setPanLfoSpeed1(float _value1); void setPanLfoSpeed2(float _value1); void setPanLfoSpeed3(float _value1); void setPanLfoSpeed4(float _value1);
//    void setPanLfoAmp1(float _value1); void setPanLfoAmp2(float _value1); void setPanLfoAmp3(float _value1); void setPanLfoAmp4(float _value1);
    void triggerPreset1(int _value1); void triggerPreset2(int _value1); void triggerPreset3(int _value1); void triggerPreset4(int _value1);
    void triggerPreset5(int _value1); void triggerPreset6(int _value1); void triggerPreset7(int _value1); void triggerPreset8(int _value1);
    
    int curPreset;
    int guiOffset;
    
    //Master Page
    bool bUseSpeedMaster, bUseSpeed1;
    bool bUsePitchMaster, bUsePitch1;
    bool bUseJitterMaster, bUseJitter1;
    bool bUseJitterQuantizeMaster, bUseJitterQuantize1;
    bool bUseGrainSizeMaster, bUseGrainSize1;
    bool bUseOverlapsMaster, bUseOverlaps1;
    bool bUseRandomGrainSizeMaster, bUseRandomGrainSize1;
    bool bUseRandomGrainPitchMaster, bUseRandomGrainPitch1;
    //DSP
    bool bUseCutoffMaster, bUseCutoff1;
    bool bUseCutoffLFOMaster, bUseCutoffLFO1;
    bool bUseCrushMaster, bUseCrush1;
    bool bUseBitsMaster, bUseBits1;
    bool bUseDelayTimeMaster, bUseDelayTime1;
    bool bUseDelayFeedbackMaster, bUseDelayFeedback1;
    bool bUseReverbDecayMaster, bUseReverbDecay1;
    bool bUseReverbDryWetMaster, bUseReverbDryWet1;
    
};
