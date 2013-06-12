//
//  audio.cpp
//  emptyExample
//
//  Created by Joshua Batty on 21/02/13.
//
//

#include "audioBinaural.h"

//-------------------------------------------------------------
AudioBinaural::~AudioBinaural() {

}

//--------------------------------------------------------------
void AudioBinaural::setSampleRate( int rate )
{
	sampleRate = rate;
}

//--------------------------------------------------------------
void AudioBinaural::setup()
{
	/* This is stuff you always need.*/
	sampleRate 			= 44100; /* Sampling Rate */
	initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
	volume				= 0.279f;
	
	lAudioOut.assign(initialBufferSize, 0.0);
	rAudioOut.assign(initialBufferSize, 0.0);

	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);

    //Binaural
    osc1Pitch = 54.0f;
    osc2Pitch = 0.10f;
    
}

//--------------------------------------------------------------
void AudioBinaural::updateParams(float _volume, float _pitch, float _offset)
{
    volume = _volume;
    osc1Pitch = _pitch;
    osc2Pitch = _offset;
}

//--------------------------------------------------------------
void AudioBinaural::audioRequested (float * output, int numFrames, int nChannels)
{
    for (int i = 0; i < numFrames; i++){
        //BINAURAL
        OSCout = sine1.sinebuf(abs(osc1Pitch)) * sine2.sinebuf(abs(osc2Pitch))*1.21;

        //play result
        mymix.stereo(OSCout, outputs, 0.5/3.0);

         //   cout << "myMix = " << OSCout+REVERB1out << endl;

        output[i*nChannels    ] = outputs[0] * volume; /* You may end up with lots of outputs. add them here */
        output[i*nChannels + 1] = outputs[1] * volume;

    }		
}
