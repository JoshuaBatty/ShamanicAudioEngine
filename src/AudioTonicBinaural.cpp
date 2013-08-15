//
//  AudioTonicBinaural.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 15/08/13.
//
//

#include "AudioTonicBinaural.h"



//--------------------------------------------------------------
void AudioTonicBinaural::setSampleRate( int rate )
{
	sampleRate = rate;
}

//--------------------------------------------------------------
void AudioTonicBinaural::setup()
{
    Volume = -8.0;
    CarrierPitch = 54.0;
    CarrierOffset = 0.1;
    
    //TONIC AUDIO STUFF
    ControlParameter volume = synth.addParameter("volume", -8.f).displayName("Volume (dbFS)").min(-60.f).max(0.f);
    ControlParameter carrierPitch = synth.addParameter("carrierPitch", 54.f).displayName("Carrier Pitch").min(20.f).max(92.f);
    ControlParameter carrierOffset = synth.addParameter("carrierOffset", 0.1f).displayName("Carrier Offset").min(0.f).max(8.f);

    float smoothTime = 0.1;

    Generator rCarrierFreq = carrierPitch.smoothed(smoothTime);
    Generator rCarrierOffset = carrierOffset.smoothed(smoothTime);
    

    osc1 = SineWave().freq(rCarrierFreq) * SineWave().freq(rCarrierOffset)* ControlDbToLinear().input(volume).smoothed(smoothTime);
    synth.setOutputGen(osc1);

}

//--------------------------------------------------------------
void AudioTonicBinaural::triggerFMparams(){
    
    // set a parameter that we created when we defined the synth
    synth.setParameter("volume", Volume);
    synth.setParameter("carrierPitch", CarrierPitch);
    synth.setParameter("carrierOffset", CarrierOffset);
    
}

//--------------------------------------------------------------
void AudioTonicBinaural::audioRequested (float * output, int numFrames, int nChannels)
{
    //Tonic
    synth.fillBufferOfFloats(output, numFrames, nChannels);
    
}
