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
	duration = 10000;
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
void TweenSynth::trigger2()
{

    if(easingType==1){
        tweenBinVolume.setParameters(1,easingLinear,ofxTween::easeOut,audioBinaural->volume,tempBinVolume,duration,delay);
        tweenBinOscPitch.setParameters(1,easingLinear,ofxTween::easeOut,audioBinaural->osc1Pitch,tempBinOscPitch,duration,delay);
        tweenBinOscOffset.setParameters(2,easingLinear,ofxTween::easeOut,audioBinaural->osc2Pitch,tempBinOscOffset,duration,delay);
        tweenSynthVolume.setParameters(3,easingLinear,ofxTween::easeOut,audioTonic->Volume,tempSynthVolume,duration,delay);
        tweenSynthCarrierPitch.setParameters(4,easingLinear,ofxTween::easeOut,audioTonic->CarrierPitch,tempSynthCarrierPitch,duration,delay);
        tweenSynthCarrierOffset.setParameters(5,easingLinear,ofxTween::easeOut,audioTonic->CarrierOffset,tempSynthCarrierOffset,duration,delay);
        tweenSynthModIndex.setParameters(6,easingLinear,ofxTween::easeOut,audioTonic->ModIndex,tempSynthModIndex,duration,delay);
        tweenSynthModLfoAmt.setParameters(7,easingLinear,ofxTween::easeOut,audioTonic->ModLfoAmt,tempSynthModLfoAmt,duration,delay);
        tweenSynthModLfoSpeed.setParameters(8,easingLinear,ofxTween::easeOut,audioTonic->ModLfoSpeed,tempSynthModLfoSpeed,duration,delay);
        tweenSynthAmpLfoAmt.setParameters(9,easingLinear,ofxTween::easeOut,audioTonic->AmpLfoAmt,tempSynthAmpLfoAmt,duration,delay);
        tweenSynthAmpLfoSpeed.setParameters(10,easingLinear,ofxTween::easeOut,audioTonic->AmpLfoSpeed,tempSynthAmpLfoSpeed,duration,delay);
    } else if(easingType==2){
        tweenBinVolume.setParameters(1,easingExpo,ofxTween::easeOut,audioBinaural->volume,tempBinVolume,duration,delay);
        tweenBinOscPitch.setParameters(1,easingExpo,ofxTween::easeOut,audioBinaural->osc1Pitch,tempBinOscPitch,duration,delay);
        tweenBinOscOffset.setParameters(2,easingExpo,ofxTween::easeOut,audioBinaural->osc2Pitch,tempBinOscOffset,duration,delay);
        tweenSynthVolume.setParameters(3,easingExpo,ofxTween::easeOut,audioTonic->Volume,tempSynthVolume,duration,delay);
        tweenSynthCarrierPitch.setParameters(4,easingExpo,ofxTween::easeOut,audioTonic->CarrierPitch,tempSynthCarrierPitch,duration,delay);
        tweenSynthCarrierOffset.setParameters(5,easingExpo,ofxTween::easeOut,audioTonic->CarrierOffset,tempSynthCarrierOffset,duration,delay);
        tweenSynthModIndex.setParameters(6,easingExpo,ofxTween::easeOut,audioTonic->ModIndex,tempSynthModIndex,duration,delay);
        tweenSynthModLfoAmt.setParameters(7,easingExpo,ofxTween::easeOut,audioTonic->ModLfoAmt,tempSynthModLfoAmt,duration,delay);
        tweenSynthModLfoSpeed.setParameters(8,easingExpo,ofxTween::easeOut,audioTonic->ModLfoSpeed,tempSynthModLfoSpeed,duration,delay);
        tweenSynthAmpLfoAmt.setParameters(9,easingExpo,ofxTween::easeOut,audioTonic->AmpLfoAmt,tempSynthAmpLfoAmt,duration,delay);
        tweenSynthAmpLfoSpeed.setParameters(10,easingExpo,ofxTween::easeOut,audioTonic->AmpLfoSpeed,tempSynthAmpLfoSpeed,duration,delay);
    } else if(easingType==3){
        tweenBinVolume.setParameters(1,easingCirc,ofxTween::easeOut,audioBinaural->volume,tempBinVolume,duration,delay);
        tweenBinOscPitch.setParameters(1,easingCirc,ofxTween::easeOut,audioBinaural->osc1Pitch,tempBinOscPitch,duration,delay);
        tweenBinOscOffset.setParameters(2,easingCirc,ofxTween::easeOut,audioBinaural->osc2Pitch,tempBinOscOffset,duration,delay);
        tweenSynthVolume.setParameters(3,easingCirc,ofxTween::easeOut,audioTonic->Volume,tempSynthVolume,duration,delay);
        tweenSynthCarrierPitch.setParameters(4,easingCirc,ofxTween::easeOut,audioTonic->CarrierPitch,tempSynthCarrierPitch,duration,delay);
        tweenSynthCarrierOffset.setParameters(5,easingCirc,ofxTween::easeOut,audioTonic->CarrierOffset,tempSynthCarrierOffset,duration,delay);
        tweenSynthModIndex.setParameters(6,easingCirc,ofxTween::easeOut,audioTonic->ModIndex,tempSynthModIndex,duration,delay);
        tweenSynthModLfoAmt.setParameters(7,easingCirc,ofxTween::easeOut,audioTonic->ModLfoAmt,tempSynthModLfoAmt,duration,delay);
        tweenSynthModLfoSpeed.setParameters(8,easingCirc,ofxTween::easeOut,audioTonic->ModLfoSpeed,tempSynthModLfoSpeed,duration,delay);
        tweenSynthAmpLfoAmt.setParameters(9,easingCirc,ofxTween::easeOut,audioTonic->AmpLfoAmt,tempSynthAmpLfoAmt,duration,delay);
        tweenSynthAmpLfoSpeed.setParameters(10,easingCirc,ofxTween::easeOut,audioTonic->AmpLfoSpeed,tempSynthAmpLfoSpeed,duration,delay);
    } else if(easingType==4){
        tweenBinVolume.setParameters(1,easingElastic,ofxTween::easeOut,audioBinaural->volume,tempBinVolume,duration,delay);
        tweenBinOscPitch.setParameters(1,easingElastic,ofxTween::easeOut,audioBinaural->osc1Pitch,tempBinOscPitch,duration,delay);
        tweenBinOscOffset.setParameters(2,easingElastic,ofxTween::easeOut,audioBinaural->osc2Pitch,tempBinOscOffset,duration,delay);
        tweenSynthVolume.setParameters(3,easingElastic,ofxTween::easeOut,audioTonic->Volume,tempSynthVolume,duration,delay);
        tweenSynthCarrierPitch.setParameters(4,easingElastic,ofxTween::easeOut,audioTonic->CarrierPitch,tempSynthCarrierPitch,duration,delay);
        tweenSynthCarrierOffset.setParameters(5,easingElastic,ofxTween::easeOut,audioTonic->CarrierOffset,tempSynthCarrierOffset,duration,delay);
        tweenSynthModIndex.setParameters(6,easingElastic,ofxTween::easeOut,audioTonic->ModIndex,tempSynthModIndex,duration,delay);
        tweenSynthModLfoAmt.setParameters(7,easingElastic,ofxTween::easeOut,audioTonic->ModLfoAmt,tempSynthModLfoAmt,duration,delay);
        tweenSynthModLfoSpeed.setParameters(8,easingElastic,ofxTween::easeOut,audioTonic->ModLfoSpeed,tempSynthModLfoSpeed,duration,delay);
        tweenSynthAmpLfoAmt.setParameters(9,easingElastic,ofxTween::easeOut,audioTonic->AmpLfoAmt,tempSynthAmpLfoAmt,duration,delay);
        tweenSynthAmpLfoSpeed.setParameters(10,easingElastic,ofxTween::easeOut,audioTonic->AmpLfoSpeed,tempSynthAmpLfoSpeed,duration,delay);
    } else if(easingType==5){
        tweenBinVolume.setParameters(1,easingBounce,ofxTween::easeOut,audioBinaural->volume,tempBinVolume,duration,delay);
        tweenBinOscPitch.setParameters(1,easingBounce,ofxTween::easeOut,audioBinaural->osc1Pitch,tempBinOscPitch,duration,delay);
        tweenBinOscOffset.setParameters(2,easingBounce,ofxTween::easeOut,audioBinaural->osc2Pitch,tempBinOscOffset,duration,delay);
        tweenSynthVolume.setParameters(3,easingBounce,ofxTween::easeOut,audioTonic->Volume,tempSynthVolume,duration,delay);
        tweenSynthCarrierPitch.setParameters(4,easingBounce,ofxTween::easeOut,audioTonic->CarrierPitch,tempSynthCarrierPitch,duration,delay);
        tweenSynthCarrierOffset.setParameters(5,easingBounce,ofxTween::easeOut,audioTonic->CarrierOffset,tempSynthCarrierOffset,duration,delay);
        tweenSynthModIndex.setParameters(6,easingBounce,ofxTween::easeOut,audioTonic->ModIndex,tempSynthModIndex,duration,delay);
        tweenSynthModLfoAmt.setParameters(7,easingBounce,ofxTween::easeOut,audioTonic->ModLfoAmt,tempSynthModLfoAmt,duration,delay);
        tweenSynthModLfoSpeed.setParameters(8,easingBounce,ofxTween::easeOut,audioTonic->ModLfoSpeed,tempSynthModLfoSpeed,duration,delay);
        tweenSynthAmpLfoAmt.setParameters(9,easingBounce,ofxTween::easeOut,audioTonic->AmpLfoAmt,tempSynthAmpLfoAmt,duration,delay);
        tweenSynthAmpLfoSpeed.setParameters(10,easingBounce,ofxTween::easeOut,audioTonic->AmpLfoSpeed,tempSynthAmpLfoSpeed,duration,delay);
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
