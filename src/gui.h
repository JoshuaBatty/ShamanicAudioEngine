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
	void setup(Tween *_tween1, Tween *_tween2, Tween *_tween3, Tween *_tween4, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4);

    AudioSampler  *audioSample1, *audioSample2, *audioSample3, *audioSample4;
    Tween *tween1, *tween2, *tween3, *tween4;
    //Gui
    ofxUICanvas *gui1, *gui2, *gui3, *gui4, *gui5, *gui6, *gui7;
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


    void setVolume1(float _value1); void setVolume2(float _value1); void setVolume3(float _value1); void setVolume4(float _value1);
    void setSpeed1(float _value1); void setSpeed2(float _value1); void setSpeed3(float _value1); void setSpeed4(float _value1);
    void setPitch1(float _value1); void setPitch2(float _value1); void setPitch3(float _value1); void setPitch4(float _value1);
    void setRandomGrainPitch1(float _value1); void setRandomGrainPitch2(float _value1); void setRandomGrainPitch3(float _value1); void setRandomGrainPitch4(float _value1);
    void setGrainSize1(float _value1); void setGrainSize2(float _value1); void setGrainSize3(float _value1); void setGrainSize4(float _value1);
    void setRandomGrainSize1(float _value1); void setRandomGrainSize2(float _value1); void setRandomGrainSize3(float _value1); void setRandomGrainSize4(float _value1);
    void setOverlaps1(float _value1); void setOverlaps2(float _value1); void setOverlaps3(float _value1); void setOverlaps4(float _value1);
    void setCutoff1(float _value1); void setCutoff2(float _value1); void setCutoff3(float _value1); void setCutoff4(float _value1);
    void setLfoSpeed1(float _value1); void setLfoSpeed2(float _value1); void setLfoSpeed3(float _value1); void setLfoSpeed4(float _value1);
    void setLfoAmp1(float _value1); void setLfoAmp2(float _value1); void setLfoAmp3(float _value1); void setLfoAmp4(float _value1);
    void setRate1(float _value1); void setRate2(float _value1); void setRate3(float _value1); void setRate4(float _value1);
    void setDelayTime1(float _value1); void setDelayTime2(float _value1); void setDelayTime3(float _value1); void setDelayTime4(float _value1);
    void setDelayFeedback1(float _value1); void setDelayFeedback2(float _value1); void setDelayFeedback3(float _value1); void setDelayFeedback4(float _value1);
    void setReverbDecay1(float _value1); void setReverbDecay2(float _value1); void setReverbDecay3(float _value1); void setReverbDecay4(float _value1);
    void setReverbDryWet1(float _value1); void setReverbDryWet2(float _value1); void setReverbDryWet3(float _value1); void setReverbDryWet4(float _value1);
  
    void setPanPosition1(float _value1); void setPanPosition2(float _value1); void setPanPosition3(float _value1); void setPanPosition4(float _value1);
    void setPanLfoSpeed1(float _value1); void setPanLfoSpeed2(float _value1); void setPanLfoSpeed3(float _value1); void setPanLfoSpeed4(float _value1);
    void setPanLfoAmp1(float _value1); void setPanLfoAmp2(float _value1); void setPanLfoAmp3(float _value1); void setPanLfoAmp4(float _value1);
    
    void triggerPreset1(int _value1); void triggerPreset2(int _value1); void triggerPreset3(int _value1); void triggerPreset4(int _value1);
    void triggerPreset5(int _value1); void triggerPreset6(int _value1); void triggerPreset7(int _value1); void triggerPreset8(int _value1);
    
    int curPreset;
    int guiOffset;
    
    //Master Page
    bool bUseSpeedMaster, bUseSpeed1, bUseSpeed2, bUseSpeed3, bUseSpeed4;
    bool bUsePitchMaster, bUsePitch1, bUsePitch2, bUsePitch3, bUsePitch4;
    bool bUseJitterMaster, bUseJitter1, bUseJitter2, bUseJitter3, bUseJitter4;
    bool bUseJitterQuantizeMaster, bUseJitterQuantize1, bUseJitterQuantize2, bUseJitterQuantize3, bUseJitterQuantize4;;
    bool bUseGrainSizeMaster, bUseGrainSize1, bUseGrainSize2, bUseGrainSize3, bUseGrainSize4;
    bool bUseOverlapsMaster, bUseOverlaps1, bUseOverlaps2, bUseOverlaps3, bUseOverlaps4;
    bool bUseRandomGrainSizeMaster, bUseRandomGrainSize1, bUseRandomGrainSize2, bUseRandomGrainSize3, bUseRandomGrainSize4;
    bool bUseRandomGrainPitchMaster, bUseRandomGrainPitch1, bUseRandomGrainPitch2, bUseRandomGrainPitch3, bUseRandomGrainPitch4;
    //DSP
    bool bUseCutoffMaster, bUseCutoff1, bUseCutoff2, bUseCutoff3, bUseCutoff4;
    bool bUseCutoffLFOMaster, bUseCutoffLFO1, bUseCutoffLFO2, bUseCutoffLFO3, bUseCutoffLFO4;
    bool bUseCrushMaster, bUseCrush1, bUseCrush2, bUseCrush3, bUseCrush4;
    bool bUseBitsMaster, bUseBits1, bUseBits2, bUseBits3, bUseBits4;
    bool bUseDelayTimeMaster, bUseDelayTime1, bUseDelayTime2, bUseDelayTime3, bUseDelayTime4;
    bool bUseDelayFeedbackMaster, bUseDelayFeedback1, bUseDelayFeedback2, bUseDelayFeedback3, bUseDelayFeedback4;
    bool bUseReverbDecayMaster, bUseReverbDecay1, bUseReverbDecay2, bUseReverbDecay3, bUseReverbDecay4;
    bool bUseReverbDryWetMaster, bUseReverbDryWet1, bUseReverbDryWet2, bUseReverbDryWet3, bUseReverbDryWet4;
    
};
