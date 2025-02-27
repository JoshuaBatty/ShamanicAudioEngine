//
//  AudioTonic.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 29/07/13.
//
//

#include "AudioTonic.h"


//--------------------------------------------------------------
void AudioTonic::setSampleRate( int rate )
{
	sampleRate = rate;
}

//--------------------------------------------------------------
void AudioTonic::setup()
{
	volume	= 0.0f;
//	volume	= 0.79f;
    
    //TONIC AUDIO STUFF
    ControlParameter volume = synth.addParameter("volume", -58.f).displayName("Volume (dbFS)").min(-60.f).max(0.f);
    ControlParameter carrierPitch = synth.addParameter("carrierPitch", 20.f).displayName("Carrier Pitch").min(20.f).max(32.f);
    ControlParameter carrierOffset = synth.addParameter("carrierOffset", 1.f).displayName("Carrier Offset").min(0.f).max(8.f);
    ControlParameter modIndex = synth.addParameter("modIndex", 0.25f).displayName("FM Amount").min(0.f).max(10.0f);
    ControlParameter modLfoAmt = synth.addParameter("modLfoAmt", 0.5f).displayName("Mod LFO Amount").min(0.f).max(4.f);
    ControlParameter modLfoSpeed = synth.addParameter("modLfoSpeed", 10.0f).displayName("Mod LFO Speed").min(0.f).max(20.f);
    ControlParameter ampLfoAmt = synth.addParameter("ampLfoAmt", 0.75f).displayName("Amp LFO Amount").min(0.f).max(1.f);
    ControlParameter ampLfoSpeed = synth.addParameter("ampLfoSpeed", 0.15f).displayName("Amp LFO Speed").min(0.f).max(20.f);
    
    Generator rCarrierFreq = ControlMidiToFreq().input(carrierPitch).smoothed();
    Generator rModFreq     = rCarrierFreq * 4.0f;

    float smoothTime = 0.1;
    
    osc1 = SineWave()
    .freq( rCarrierFreq
          + (
             SineWave().freq( rModFreq ) *
             rModFreq *
             (modIndex.smoothed(smoothTime) * (1.0f + SineWave().freq(modLfoSpeed.smoothed(smoothTime)) * modLfoAmt.smoothed(smoothTime) * 0.5f))
             )
          ) * (1.0f + SineWave().freq(ampLfoSpeed.smoothed(smoothTime)) * ampLfoAmt.smoothed(smoothTime) + 0.25) * ControlDbToLinear().input(volume).smoothed(smoothTime);
    
    osc2 = SineWave()
    .freq( rCarrierFreq + carrierOffset.smoothed(smoothTime)
          + (
             SineWave().freq( rModFreq ) *
             rModFreq *
             (modIndex.smoothed(smoothTime) * (1.0f + SineWave().freq(modLfoSpeed.smoothed(smoothTime)) * modLfoAmt.smoothed(smoothTime) * 0.5f))
             )
          ) * (1.0f + SineWave().freq(ampLfoSpeed.smoothed(smoothTime)) * ampLfoAmt.smoothed(smoothTime) + 0.25) * ControlDbToLinear().input(volume).smoothed(smoothTime);
    
    synth.setOutputGen(osc1 * osc2);

 //   synth.getOutputGen();
    
 //   synth.getParameters();
}

//--------------------------------------------------------------
void AudioTonic::triggerFMparams(){
    
    // set a parameter that we created when we defined the synth
    synth.setParameter("volume", Volume);
    synth.setParameter("carrierPitch", CarrierPitch);
    synth.setParameter("carrierOffset", CarrierOffset);
    synth.setParameter("modIndex", ModIndex);
    synth.setParameter("modLfoAmt", ModLfoAmt);
    synth.setParameter("modLfoSpeed", ModLfoSpeed);
    synth.setParameter("ampLfoAmt", AmpLfoAmt);
    synth.setParameter("ampLfoSpeed", AmpLfoSpeed);
    
}

//--------------------------------------------------------------
void AudioTonic::audioRequested (float * output, int numFrames, int nChannels)
{
    //Tonic
    synth.fillBufferOfFloats(output, numFrames, nChannels);
    
}
