//
//  tween.cpp
//  oscReceiveExample
//
//  Created by Joshua Batty on 7/05/13.
//
//

#include "tween.h"


//--------------------------------------------------------------
void Tween::setup(AudioSampler *_audioSample)
{
    audioSample = _audioSample;
        
    //init temps
    tempVolume = audioSample->volume;
    tempPitch = audioSample->pitch1;
    tempSpeed = audioSample->speed1;
    tempGrainLength = audioSample->grainLength1;
    tempOverlaps = audioSample->overlaps1;
    tempRandomGrainPitch = audioSample->randomGrainPitch1;
    tempRandomGrainSize = audioSample->randomGrainSize1;
    tempDelayTime = audioSample->delayTime1;
    tempDelayFeedback = audioSample->delayFeedback1;
    tempCutoff = audioSample->cutoff1;
    tempLfoSpeed = audioSample->lfoSpeed1;
    tempLfoAmp = audioSample->lfoAmp1;
    tempReverbSize = audioSample->reverbSize;
    tempReverbDryWet = audioSample->reverbDryWet;
    tempRate = audioSample->rate;
    tempBits = audioSample->bits;
    
    //tween
    delay = 0;
	duration = 10000;
    easingType = 1;
}

//--------------------------------------------------------------
void Tween::setEasingType(int _easingType)
{
    easingType = _easingType;
}

//--------------------------------------------------------------
void Tween::update()
{
    //Volume
    if(tweenVolume.isRunning()){
        audioSample->volume=tweenVolume.update();
    }
    //Pitch
    if(tweenPitch.isRunning()){
        audioSample->pitch1=tweenPitch.update();
    }
    //Speed
    if(tweenSpeed.isRunning()){
        audioSample->speed1=tweenSpeed.update();
    }
    //GrainLength
    if(tweenGrainLength.isRunning()){
        audioSample->grainLength1=tweenGrainLength.update();
    }
    //Overlaps
    if(tweenOverlaps.isRunning()){
        audioSample->overlaps1=tweenOverlaps.update();
    }
    //Random Grain Pitch
    if(tweenRandomGrainPitch.isRunning()){
        audioSample->randomGrainPitch1=tweenRandomGrainPitch.update();
    }
    //Random Grain Length
    if(tweenRandomGrainSize.isRunning()){
        audioSample->randomGrainSize1=tweenRandomGrainSize.update();
    }
    //Delay Time
    if(tweenDelayTime.isRunning()){
        audioSample->delayTime1=tweenDelayTime.update();
    }
    //Delay Feedback
    if(tweenDelayFeedback.isRunning()){
        audioSample->delayFeedback1=tweenDelayFeedback.update();
    }
    //Cutoff
    if(tweenCutoff.isRunning()){
        audioSample->cutoff1=tweenCutoff.update();
    }
    //LFO Speed
    if(tweenLfoSpeed.isRunning()){
        audioSample->lfoSpeed1=tweenLfoSpeed.update();
    }
    //LFO Amp
    if(tweenLfoAmp.isRunning()){
        audioSample->lfoAmp1=tweenLfoAmp.update();
    }
    //Bits
    if(tweenBits.isRunning()){
        audioSample->bits=tweenBits.update();
    }
    //Rate
    if(tweenRate.isRunning()){
        audioSample->rate=tweenRate.update();
    }
    //Reverb Size
    if(tweenReverbSize.isRunning()){
        audioSample->reverbSize=tweenReverbSize.update();
    }
    //Reverb Dry Wet
    if(tweenReverbDryWet.isRunning()){
        audioSample->reverbDryWet=tweenReverbDryWet.update();
    }
}

//--------------------------------------------------------------
void Tween::trigger()
{
    tweenPitch.setParameters(10,easingLinear,ofxTween::easeOut,0.5,1.5,duration,delay);
    tweenSpeed.setParameters(10,easingLinear,ofxTween::easeOut,1.0,0.05,duration,delay);
    tweenGrainLength.setParameters(10,easingLinear,ofxTween::easeOut,0.025,0.4,duration,delay);
    tweenOverlaps.setParameters(10,easingLinear,ofxTween::easeOut,1,3,duration,delay);
    tweenRandomGrainPitch.setParameters(10,easingLinear,ofxTween::easeOut,0.0,0.1,duration,delay);
    tweenRandomGrainSize.setParameters(10,easingLinear,ofxTween::easeOut,0.0,0.2,duration,delay);
    tweenDelayTime.setParameters(10,easingLinear,ofxTween::easeOut,0.0,1000.0,duration,delay);
    tweenDelayFeedback.setParameters(10,easingLinear,ofxTween::easeOut,0.0,0.7,duration,delay);
    tweenCutoff.setParameters(10,easingLinear,ofxTween::easeOut,5000.0,10000.0,duration,delay);
    tweenLfoSpeed.setParameters(10,easingLinear,ofxTween::easeOut,0.0,200.0,duration,delay);
    tweenLfoAmp.setParameters(10,easingLinear,ofxTween::easeOut,0.0,100.0,duration,delay);
    tweenBits.setParameters(10,easingLinear,ofxTween::easeOut,32.0,32.0,duration,delay);
    tweenRate.setParameters(10,easingLinear,ofxTween::easeOut,1.0,0.3,duration,delay);
    tweenReverbSize.setParameters(10,easingLinear,ofxTween::easeOut,0.0,0.5,duration,delay);
    tweenReverbDryWet.setParameters(10,easingLinear,ofxTween::easeOut,0.0,0.5,duration,delay);

}

//--------------------------------------------------------------
void Tween::trigger2()
{
    if(easingType==1){
        tweenVolume.setParameters(1,easingLinear,ofxTween::easeOut,audioSample->volume,tempVolume,duration,delay);
        tweenPitch.setParameters(1,easingLinear,ofxTween::easeOut,audioSample->pitch1,tempPitch,duration,delay);
        tweenSpeed.setParameters(2,easingLinear,ofxTween::easeOut,audioSample->speed1,tempSpeed,duration,delay);
        tweenGrainLength.setParameters(3,easingLinear,ofxTween::easeOut,audioSample->grainLength1,tempGrainLength,duration,delay);
        tweenOverlaps.setParameters(4,easingLinear,ofxTween::easeOut,audioSample->overlaps1,tempOverlaps,duration,delay);
        tweenRandomGrainPitch.setParameters(5,easingLinear,ofxTween::easeOut,audioSample->randomGrainPitch1,tempRandomGrainPitch,duration,delay);
        tweenRandomGrainSize.setParameters(6,easingLinear,ofxTween::easeOut,audioSample->randomGrainSize1,tempRandomGrainSize,duration,delay);
        tweenDelayTime.setParameters(7,easingLinear,ofxTween::easeOut,audioSample->delayTime1,tempDelayTime,duration,delay);
        tweenDelayFeedback.setParameters(8,easingLinear,ofxTween::easeOut,audioSample->delayFeedback1,tempDelayFeedback,duration,delay);
        tweenCutoff.setParameters(9,easingLinear,ofxTween::easeOut,audioSample->cutoff1,tempCutoff,duration,delay);
        tweenLfoSpeed.setParameters(10,easingLinear,ofxTween::easeOut,audioSample->lfoSpeed1,tempLfoSpeed,duration,delay);
        tweenLfoAmp.setParameters(11,easingLinear,ofxTween::easeOut,audioSample->lfoAmp1,tempLfoAmp,duration,delay);
        tweenBits.setParameters(12,easingLinear,ofxTween::easeOut,audioSample->bits,tempBits,duration,delay);
        tweenRate.setParameters(13,easingLinear,ofxTween::easeOut,audioSample->rate,tempRate,duration,delay);
        tweenReverbSize.setParameters(14,easingLinear,ofxTween::easeOut,audioSample->reverbSize,tempReverbSize,duration,delay);
        tweenReverbDryWet.setParameters(15,easingLinear,ofxTween::easeOut,audioSample->reverbDryWet,tempReverbDryWet,duration,delay);
    } else if(easingType==2){
        tweenVolume.setParameters(1,easingExpo,ofxTween::easeOut,audioSample->volume,tempVolume,duration,delay);
        tweenPitch.setParameters(1,easingExpo,ofxTween::easeOut,audioSample->pitch1,tempPitch,duration,delay);
        tweenSpeed.setParameters(2,easingExpo,ofxTween::easeOut,audioSample->speed1,tempSpeed,duration,delay);
        tweenGrainLength.setParameters(3,easingExpo,ofxTween::easeOut,audioSample->grainLength1,tempGrainLength,duration,delay);
        tweenOverlaps.setParameters(4,easingExpo,ofxTween::easeOut,audioSample->overlaps1,tempOverlaps,duration,delay);
        tweenRandomGrainPitch.setParameters(5,easingExpo,ofxTween::easeOut,audioSample->randomGrainPitch1,tempRandomGrainPitch,duration,delay);
        tweenRandomGrainSize.setParameters(6,easingExpo,ofxTween::easeOut,audioSample->randomGrainSize1,tempRandomGrainSize,duration,delay);
        tweenDelayTime.setParameters(7,easingExpo,ofxTween::easeOut,audioSample->delayTime1,tempDelayTime,duration,delay);
        tweenDelayFeedback.setParameters(8,easingExpo,ofxTween::easeOut,audioSample->delayFeedback1,tempDelayFeedback,duration,delay);
        tweenCutoff.setParameters(9,easingExpo,ofxTween::easeOut,audioSample->cutoff1,tempCutoff,duration,delay);
        tweenLfoSpeed.setParameters(10,easingExpo,ofxTween::easeOut,audioSample->lfoSpeed1,tempLfoSpeed,duration,delay);
        tweenLfoAmp.setParameters(11,easingExpo,ofxTween::easeOut,audioSample->lfoAmp1,tempLfoAmp,duration,delay);
        tweenBits.setParameters(12,easingExpo,ofxTween::easeOut,audioSample->bits,tempBits,duration,delay);
        tweenRate.setParameters(13,easingExpo,ofxTween::easeOut,audioSample->rate,tempRate,duration,delay);
        tweenReverbSize.setParameters(14,easingExpo,ofxTween::easeOut,audioSample->reverbSize,tempReverbSize,duration,delay);
        tweenReverbDryWet.setParameters(15,easingExpo,ofxTween::easeOut,audioSample->reverbDryWet,tempReverbDryWet,duration,delay);
    } else if(easingType==3){
        tweenVolume.setParameters(1,easingCirc,ofxTween::easeOut,audioSample->volume,tempVolume,duration,delay);
        tweenPitch.setParameters(1,easingCirc,ofxTween::easeOut,audioSample->pitch1,tempPitch,duration,delay);
        tweenSpeed.setParameters(2,easingCirc,ofxTween::easeOut,audioSample->speed1,tempSpeed,duration,delay);
        tweenGrainLength.setParameters(3,easingCirc,ofxTween::easeOut,audioSample->grainLength1,tempGrainLength,duration,delay);
        tweenOverlaps.setParameters(4,easingCirc,ofxTween::easeOut,audioSample->overlaps1,tempOverlaps,duration,delay);
        tweenRandomGrainPitch.setParameters(5,easingCirc,ofxTween::easeOut,audioSample->randomGrainPitch1,tempRandomGrainPitch,duration,delay);
        tweenRandomGrainSize.setParameters(6,easingCirc,ofxTween::easeOut,audioSample->randomGrainSize1,tempRandomGrainSize,duration,delay);
        tweenDelayTime.setParameters(7,easingCirc,ofxTween::easeOut,audioSample->delayTime1,tempDelayTime,duration,delay);
        tweenDelayFeedback.setParameters(8,easingCirc,ofxTween::easeOut,audioSample->delayFeedback1,tempDelayFeedback,duration,delay);
        tweenCutoff.setParameters(9,easingCirc,ofxTween::easeOut,audioSample->cutoff1,tempCutoff,duration,delay);
        tweenLfoSpeed.setParameters(10,easingCirc,ofxTween::easeOut,audioSample->lfoSpeed1,tempLfoSpeed,duration,delay);
        tweenLfoAmp.setParameters(11,easingCirc,ofxTween::easeOut,audioSample->lfoAmp1,tempLfoAmp,duration,delay);
        tweenBits.setParameters(12,easingCirc,ofxTween::easeOut,audioSample->bits,tempBits,duration,delay);
        tweenRate.setParameters(13,easingCirc,ofxTween::easeOut,audioSample->rate,tempRate,duration,delay);
        tweenReverbSize.setParameters(14,easingCirc,ofxTween::easeOut,audioSample->reverbSize,tempReverbSize,duration,delay);
        tweenReverbDryWet.setParameters(15,easingCirc,ofxTween::easeOut,audioSample->reverbDryWet,tempReverbDryWet,duration,delay);
    } else if(easingType==4){
        tweenVolume.setParameters(1,easingElastic,ofxTween::easeOut,audioSample->volume,tempVolume,duration,delay);
        tweenPitch.setParameters(1,easingElastic,ofxTween::easeOut,audioSample->pitch1,tempPitch,duration,delay);
        tweenSpeed.setParameters(2,easingElastic,ofxTween::easeOut,audioSample->speed1,tempSpeed,duration,delay);
        tweenGrainLength.setParameters(3,easingElastic,ofxTween::easeOut,audioSample->grainLength1,tempGrainLength,duration,delay);
        tweenOverlaps.setParameters(4,easingElastic,ofxTween::easeOut,audioSample->overlaps1,tempOverlaps,duration,delay);
        tweenRandomGrainPitch.setParameters(5,easingElastic,ofxTween::easeOut,audioSample->randomGrainPitch1,tempRandomGrainPitch,duration,delay);
        tweenRandomGrainSize.setParameters(6,easingElastic,ofxTween::easeOut,audioSample->randomGrainSize1,tempRandomGrainSize,duration,delay);
        tweenDelayTime.setParameters(7,easingElastic,ofxTween::easeOut,audioSample->delayTime1,tempDelayTime,duration,delay);
        tweenDelayFeedback.setParameters(8,easingElastic,ofxTween::easeOut,audioSample->delayFeedback1,tempDelayFeedback,duration,delay);
        tweenCutoff.setParameters(9,easingElastic,ofxTween::easeOut,audioSample->cutoff1,tempCutoff,duration,delay);
        tweenLfoSpeed.setParameters(10,easingElastic,ofxTween::easeOut,audioSample->lfoSpeed1,tempLfoSpeed,duration,delay);
        tweenLfoAmp.setParameters(11,easingElastic,ofxTween::easeOut,audioSample->lfoAmp1,tempLfoAmp,duration,delay);
        tweenBits.setParameters(12,easingElastic,ofxTween::easeOut,audioSample->bits,tempBits,duration,delay);
        tweenRate.setParameters(13,easingElastic,ofxTween::easeOut,audioSample->rate,tempRate,duration,delay);
        tweenReverbSize.setParameters(14,easingElastic,ofxTween::easeOut,audioSample->reverbSize,tempReverbSize,duration,delay);
        tweenReverbDryWet.setParameters(15,easingElastic,ofxTween::easeOut,audioSample->reverbDryWet,tempReverbDryWet,duration,delay);
    } else if(easingType==5){
        tweenVolume.setParameters(1,easingBounce,ofxTween::easeOut,audioSample->volume,tempVolume,duration,delay);
        tweenPitch.setParameters(1,easingBounce,ofxTween::easeOut,audioSample->pitch1,tempPitch,duration,delay);
        tweenSpeed.setParameters(2,easingBounce,ofxTween::easeOut,audioSample->speed1,tempSpeed,duration,delay);
        tweenGrainLength.setParameters(3,easingBounce,ofxTween::easeOut,audioSample->grainLength1,tempGrainLength,duration,delay);
        tweenOverlaps.setParameters(4,easingBounce,ofxTween::easeOut,audioSample->overlaps1,tempOverlaps,duration,delay);
        tweenRandomGrainPitch.setParameters(5,easingBounce,ofxTween::easeOut,audioSample->randomGrainPitch1,tempRandomGrainPitch,duration,delay);
        tweenRandomGrainSize.setParameters(6,easingBounce,ofxTween::easeOut,audioSample->randomGrainSize1,tempRandomGrainSize,duration,delay);
        tweenDelayTime.setParameters(7,easingBounce,ofxTween::easeOut,audioSample->delayTime1,tempDelayTime,duration,delay);
        tweenDelayFeedback.setParameters(8,easingBounce,ofxTween::easeOut,audioSample->delayFeedback1,tempDelayFeedback,duration,delay);
        tweenCutoff.setParameters(9,easingBounce,ofxTween::easeOut,audioSample->cutoff1,tempCutoff,duration,delay);
        tweenLfoSpeed.setParameters(10,easingBounce,ofxTween::easeOut,audioSample->lfoSpeed1,tempLfoSpeed,duration,delay);
        tweenLfoAmp.setParameters(11,easingBounce,ofxTween::easeOut,audioSample->lfoAmp1,tempLfoAmp,duration,delay);
        tweenBits.setParameters(12,easingBounce,ofxTween::easeOut,audioSample->bits,tempBits,duration,delay);
        tweenRate.setParameters(13,easingBounce,ofxTween::easeOut,audioSample->rate,tempRate,duration,delay);
        tweenReverbSize.setParameters(14,easingBounce,ofxTween::easeOut,audioSample->reverbSize,tempReverbSize,duration,delay);
        tweenReverbDryWet.setParameters(15,easingBounce,ofxTween::easeOut,audioSample->reverbDryWet,tempReverbDryWet,duration,delay);
    }
}

//--------------------------------------------------------------
void Tween::catchTempVariables()
{
    tempVolume = audioSample->volume;
    tempPitch = audioSample->pitch1;
    tempSpeed = audioSample->speed1;
    tempGrainLength = audioSample->grainLength1;
    tempOverlaps = audioSample->overlaps1;
    tempRandomGrainPitch = audioSample->randomGrainPitch1;
    tempRandomGrainSize = audioSample->randomGrainSize1;
    tempDelayTime = audioSample->delayTime1;
    tempDelayFeedback = audioSample->delayFeedback1;
    tempCutoff = audioSample->cutoff1;
    tempLfoSpeed = audioSample->lfoSpeed1;
    tempLfoAmp = audioSample->lfoAmp1;
    tempReverbSize = audioSample->reverbSize;
    tempReverbDryWet = audioSample->reverbDryWet;
    tempRate = audioSample->rate;
    tempBits = audioSample->bits;
}
