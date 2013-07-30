//
//  audio.h
//  emptyExample
//
//  Created by Joshua Batty on 21/02/13.
//
//


#pragma once
#include "ofSoundUnit.h"
#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxTonic.h"

using namespace Tonic;

class AudioBinaural : public ofSoundSource{
	
	public :
	~AudioBinaural();/* deconsructor is very useful */
	void setup();
    void updateParams(float _volume, float _pitch, float _offset);
    
    //Need these three methods.
    void audioRequested (float * output, int numFrames, int nChannels);
    void setSampleRate( int rate );
	string getName() { return "soundSourceGranular"; }
    
//	private :
	int		initialBufferSize; /* buffer size */
	int		sampleRate;
	
	float volume;
	
	/* stick your maximilian stuff below */

	double outputs[2];
    maxiMix mymix;

    //BINAURAL
	ofxMaxiOsc sine1, sine2;
	double OSCout;
    float osc1Pitch, osc2Pitch;
    
    //TONIC AUDIO

};
