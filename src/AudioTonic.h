//
//  AudioTonic.h
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 29/07/13.
//
//


#pragma once
#include "ofSoundUnit.h"
#include "ofMain.h"
#include "ofxTonic.h"

using namespace Tonic;

class AudioTonic : public ofSoundSource{
	
	public :
	void setup();
    void triggerFMparams();

    //Need these three methods.
    void audioRequested (float * output, int numFrames, int nChannels);
    void setSampleRate( int rate );
	string getName() { return "soundSourceTonic"; }
    
	int	sampleRate;
	float volume;
    
    //TONIC AUDIO
    ofxTonicSynth synth;
    
    Generator osc1, osc2;
    float Volume, CarrierPitch, CarrierOffset, ModIndex, ModLfoAmt, ModLfoSpeed, AmpLfoAmt, AmpLfoSpeed;

};
