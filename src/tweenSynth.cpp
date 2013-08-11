//
//  tweenSynth.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 31/07/13.
//
//

#include "tweenSynth.h"


//--------------------------------------------------------------
void TweenSynth::setup(AudioBinaural *_audioBinaural, AudioTonic *_audioTonic)
{
    audioBinaural = _audioBinaural;
    audioTonic = _audioTonic;

    //init temps
    tempBinVolume = audioBinaural->volume;
    tempBinOscPitch = audioBinaural->osc1Pitch;
    tempBinOscOffset = audioBinaural->osc2Pitch;
    
    tempSynthVolume = audioTonic->Volume;
    tempSynthCarrierPitch = audioTonic->CarrierPitch;
    tempSynthCarrierOffset = audioTonic->CarrierOffset;
    tempSynthModIndex = audioTonic->ModIndex;
    tempSynthModLfoAmt = audioTonic->ModLfoAmt;
    tempSynthModLfoSpeed = audioTonic->ModLfoSpeed;
    tempSynthAmpLfoAmt = audioTonic->AmpLfoAmt;
    tempSynthAmpLfoSpeed = audioTonic->AmpLfoSpeed;

    //tween
    delay = 0;
	duration = 0;
    easingType = 1;

}

//--------------------------------------------------------------
void TweenSynth::setEasingType(int _easingType)
{
    easingType = _easingType;
}

//--------------------------------------------------------------
void TweenSynth::update()
{
    /////////////////////////////////////////////////
    ///////////////// BINAURAL //////////////////////
    /////////////////////////////////////////////////
    //Volume
    if(tweenBinVolume.isRunning()){
        audioBinaural->volume=tweenBinVolume.update();
    }
    //Pitch
    if(tweenBinOscPitch.isRunning()){
        audioBinaural->osc1Pitch=tweenBinOscPitch.update();
    }
    //Offset
    if(tweenBinOscOffset.isRunning()){
        audioBinaural->osc2Pitch=tweenBinOscOffset.update();
    }
    /////////////////////////////////////////////////
    ///////////////// FM TONIC //////////////////////
    /////////////////////////////////////////////////
    //Volume
    if(tweenSynthVolume.isRunning()){
        audioTonic->volume=tweenSynthVolume.update();
        audioTonic->triggerFMparams(); // TRIGGER TONIC TO TWEEN .... UPDATE PARAMS
    }
    //Carrier Pitch
    if(tweenSynthCarrierPitch.isRunning()){
        audioTonic->CarrierPitch=tweenSynthCarrierPitch.update();
    }
    //Carrier Offset
    if(tweenSynthCarrierOffset.isRunning()){
        audioTonic->CarrierOffset=tweenSynthCarrierOffset.update();
    }
    //Mod Index
    if(tweenSynthModIndex.isRunning()){
        audioTonic->ModIndex=tweenSynthModIndex.update();
    }
    //Mod LFO Amount
    if(tweenSynthModLfoAmt.isRunning()){
        audioTonic->ModLfoAmt=tweenSynthModLfoAmt.update();
    }
    //Mod LFO Speed
    if(tweenSynthModLfoSpeed.isRunning()){
        audioTonic->ModLfoSpeed=tweenSynthModLfoSpeed.update();
    }
    //Amp LFO Amount
    if(tweenSynthAmpLfoAmt.isRunning()){
        audioTonic->AmpLfoAmt=tweenSynthAmpLfoAmt.update();
    }
    //Amp LFO Speed
    if(tweenSynthAmpLfoSpeed.isRunning()){
        audioTonic->AmpLfoSpeed=tweenSynthAmpLfoSpeed.update();
    }

}

//--------------------------------------------------------------
void TweenSynth::setEasings(ofxEasing *_easingType){
    tweenBinVolume.setParameters(1,*(_easingType),ofxTween::easeOut,tempBinVolume,audioBinaural->volume,duration,delay);
    tweenBinOscPitch.setParameters(1,*(_easingType),ofxTween::easeOut,tempBinOscPitch,audioBinaural->osc1Pitch,duration,delay);
    tweenBinOscOffset.setParameters(2,*(_easingType),ofxTween::easeOut,tempBinOscOffset,audioBinaural->osc2Pitch,duration,delay);
    tweenSynthVolume.setParameters(3,*(_easingType),ofxTween::easeOut,tempSynthVolume,audioTonic->Volume,duration,delay);
    tweenSynthCarrierPitch.setParameters(4,*(_easingType),ofxTween::easeOut,tempSynthCarrierPitch,audioTonic->CarrierPitch,duration,delay);
    tweenSynthCarrierOffset.setParameters(5,*(_easingType),ofxTween::easeOut,tempSynthCarrierOffset,audioTonic->CarrierOffset,duration,delay);
    tweenSynthModIndex.setParameters(6,*(_easingType),ofxTween::easeOut,tempSynthModIndex,audioTonic->ModIndex,duration,delay);
    tweenSynthModLfoAmt.setParameters(7,*(_easingType),ofxTween::easeOut,tempSynthModLfoAmt,audioTonic->ModLfoAmt,duration,delay);
    tweenSynthModLfoSpeed.setParameters(8,*(_easingType),ofxTween::easeOut,tempSynthModLfoSpeed,audioTonic->ModLfoSpeed,duration,delay);
    tweenSynthAmpLfoAmt.setParameters(9,*(_easingType),ofxTween::easeOut,tempSynthAmpLfoAmt,audioTonic->AmpLfoAmt,duration,delay);
    tweenSynthAmpLfoSpeed.setParameters(10,*(_easingType),ofxTween::easeOut,tempSynthAmpLfoSpeed,audioTonic->AmpLfoSpeed,duration,delay);
}
//--------------------------------------------------------------
void TweenSynth::trigger2()
{
    if(easingType==1){
        setEasings(dynamic_cast<ofxEasing*>(&easingLinear));
        cout << "easing tyoe Lin" << endl;
    } else if(easingType==2){
        setEasings(dynamic_cast<ofxEasing*>(&easingExpo));
        cout << "easing tyoe Expo" << endl;
    } else if(easingType==3){
        setEasings(dynamic_cast<ofxEasing*>(&easingCirc));
        cout << "easing tyoe Circ" << endl;
    } else if(easingType==4){
        setEasings(dynamic_cast<ofxEasing*>(&easingElastic));
        cout << "easing tyoe Elastic" << endl;
    } else if(easingType==5){
        setEasings(dynamic_cast<ofxEasing*>(&easingBounce));
        cout << "easing tyoe Bounce" << endl;
    }
    
}

//--------------------------------------------------------------
void TweenSynth::catchTempVariables()
{
    tempBinVolume = audioBinaural->volume;
    tempBinOscPitch = audioBinaural->osc1Pitch;
    tempBinOscOffset = audioBinaural->osc2Pitch;
    
    tempSynthVolume = audioTonic->Volume;
    tempSynthCarrierPitch = audioTonic->CarrierPitch;
    tempSynthCarrierOffset = audioTonic->CarrierOffset;
    tempSynthModIndex = audioTonic->ModIndex;
    tempSynthModLfoAmt = audioTonic->ModLfoAmt;
    tempSynthModLfoSpeed = audioTonic->ModLfoSpeed;
    tempSynthAmpLfoAmt = audioTonic->AmpLfoAmt;
    tempSynthAmpLfoSpeed = audioTonic->AmpLfoSpeed;

}
