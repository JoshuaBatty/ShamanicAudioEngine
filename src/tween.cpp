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
void Tween::setEasings(ofxEasing *_easingType){
    tweenVolume.setParameters(1,*(_easingType),ofxTween::easeOut,tempVolume,audioSample->volume,duration,delay);
    tweenPitch.setParameters(1,*(_easingType),ofxTween::easeOut,tempPitch,audioSample->pitch1,duration,delay);
    tweenSpeed.setParameters(2,*(_easingType),ofxTween::easeOut,tempSpeed,audioSample->speed1,duration,delay);
    tweenGrainLength.setParameters(3,*(_easingType),ofxTween::easeOut,tempGrainLength,audioSample->grainLength1,duration,delay);
    tweenOverlaps.setParameters(4,*(_easingType),ofxTween::easeOut,tempOverlaps,audioSample->overlaps1,duration,delay);
    tweenRandomGrainPitch.setParameters(5,*(_easingType),ofxTween::easeOut,tempRandomGrainPitch,audioSample->randomGrainPitch1,duration,delay);
    tweenRandomGrainSize.setParameters(6,*(_easingType),ofxTween::easeOut,tempRandomGrainSize,audioSample->randomGrainSize1,duration,delay);
    tweenDelayTime.setParameters(7,*(_easingType),ofxTween::easeOut,tempDelayTime,audioSample->delayTime1,duration,delay);
    tweenDelayFeedback.setParameters(8,*(_easingType),ofxTween::easeOut,tempDelayFeedback,audioSample->delayFeedback1,duration,delay);
    tweenCutoff.setParameters(9,*(_easingType),ofxTween::easeOut,tempCutoff,audioSample->cutoff1,duration,delay);
    tweenLfoSpeed.setParameters(10,*(_easingType),ofxTween::easeOut,tempLfoSpeed,audioSample->lfoSpeed1,duration,delay);
    tweenLfoAmp.setParameters(11,*(_easingType),ofxTween::easeOut,tempLfoAmp,audioSample->lfoAmp1,duration,delay);
    tweenBits.setParameters(12,*(_easingType),ofxTween::easeOut,tempBits,audioSample->bits,duration,delay);
    tweenRate.setParameters(13,*(_easingType),ofxTween::easeOut,tempRate,audioSample->rate,duration,delay);
    tweenReverbSize.setParameters(14,*(_easingType),ofxTween::easeOut,tempReverbSize,audioSample->reverbSize,duration,delay);
    tweenReverbDryWet.setParameters(15,*(_easingType),ofxTween::easeOut,tempReverbDryWet,audioSample->reverbDryWet,duration,delay);
}
//--------------------------------------------------------------
void Tween::trigger2()
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
