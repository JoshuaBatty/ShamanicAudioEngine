//
//  mainTimeline.cpp
//  emptyExample
//
//  Created by Joshua Batty on 2/02/13.
//
//

#include "mainTimeline.h"


//--------------------------------------------------------------
void MainTimeline::setup(Gui *gui, AudioSampler *_audioSampler1){
    
    Mgui = gui;
    audioSampler1 = _audioSampler1;
    
    timeline.setup();
	timeline.setLoopType(OF_LOOP_NORMAL);
    timeline.setBPM(120.f);
	timeline.enableSnapToBPM(true);
	timeline.setShowBPMGrid(true);
	
    //Audio Sample for waveform
	timeline.addTrack("Track", &waveform);
	timeline.setTimecontrolTrack(&waveform);
//    waveform.loadSoundfile("digi_anemoneX2.wav");
    waveform.loadSoundfile("/Users/josh/Desktop/Media/Audio/silent.wav");
    timeline.setDurationInSeconds(waveform.getDuration());

    //SPEED
	timeline.setPageName("Speed");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("Speed1", "Speed1.xml", ofRange(0.0f, 5.0f));

    //PITCH
    timeline.addPage("Pitch", true);
	timeline.setPageName("Pitch");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("pitch1", "pitch1.xml", ofRange(0.0f, 8.0f));

    //GRANULAR
    timeline.addPage("Grain Size", true);
	timeline.setPageName("Grain Size");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("grainSize1", "grainSize1.xml", ofRange(0.01f, 0.25f));

    //OVERLAPS
    timeline.addPage("Overlaps", true);
	timeline.setPageName("Overlaps");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("overlaps1", "overlaps1.xml", ofRange(1, 10));

    //RANDOM GRAIN PITCH
    timeline.addPage("Ran Grain Pitch", true);
	timeline.setPageName("Ran Grain Pitch");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("ranGranPitch1", "ranGranPitch1.xml", ofRange(0.0, 4.0f));
    
    //RANDOM GRAIN SIZE
    timeline.addPage("Ran Grain Size", true);
	timeline.setPageName("Ran Grain Size");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("ranGranSize1", "ranGranSize1.xml", ofRange(0.0, 0.025f));
    
    ////////////////////////
    ////  Audio Timline ////
    ////////////////////////
    //AUDIO
	//LFO
    timeline.addPage("Cutoff", true);
    timeline.setPageName("Cutoff");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("cutoff1", "cutoff1.xml", ofRange(0, 10000));

    //Filter speed = 200......filter amp = 3000
	timeline.addPage("Filter LFO", true);
	timeline.setPageName("Filter LFO");
    timeline.addTrack("Track", &waveform);
    timeline.addLFO("lfoFilter1");

	//CRUSH AMOUNT
	timeline.addPage("Crush Amount", true);
	timeline.setPageName("Crush Amount");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("crushAmount1", "crushAmount1.xml", ofRange(0.0f, 1.0f));

    //CRUSH BITS
    timeline.addPage("Crush Bits", true);
	timeline.setPageName("Crush Bits");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("bits1", "bits1.xml", ofRange(0, 32));

	//DELAY TIME
	timeline.addPage("Delay Time", true);
	timeline.setPageName("Delay Time");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("delayTime1", "delayTime1.xml", ofRange(10, 3000));
    
    //DELAY FEEDBACK
	timeline.addPage("Delay Feedback", true);
	timeline.setPageName("Delay Feedback");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("delayFeedback1", "delayFeedback1.xml", ofRange(0.0f, 0.98f));

	//REVERB DECAY
	timeline.addPage("Reverb Decay", true);
	timeline.setPageName("Reverb Decay");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("reverbDecay1", "reverbDecay1.xml", ofRange(0.0f, 1.0f));
    
    //REVERB DRY/WET
	timeline.addPage("Reverb Dry/Wet", true);
	timeline.setPageName("Reverb Dry/Wet");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("reverbDryWet1", "reverbDryWet1.xml", ofRange(0.0f, 1.0f));

       timeline.getColor("defaultColors.xml");
  //  timeline.play();
}

//--------------------------------------------------------------
void MainTimeline::update(){
    
    ////////////////////////
    ////  Video Timline ////
    ////////////////////////

	//Speed
    if(Mgui->bUseSpeed1==false){
        audioSampler1->speed1 = (timeline.getValue("Speed1"));
    }

    //GrainSize
    if(Mgui->bUseGrainSize1==false){
        audioSampler1->grainLength1 = (timeline.getValue("grainSize1"));
    }

    //Grain Overlpas
    if(Mgui->bUseOverlaps1==false){
        audioSampler1->overlaps1 = (timeline.getValue("overlaps1"));
    }

    //Pitch
    if(Mgui->bUsePitch1==false){
        audioSampler1->pitch1 = (timeline.getValue("pitch1"));
    }

    //Random Grain Size
    if(Mgui->bUseRandomGrainSize1==false){
        audioSampler1->randomGrainSize1 = (timeline.getValue("ranGranSize1"));
    }

    //Random Grain Pitch
    if(Mgui->bUseRandomGrainPitch1==false){
        audioSampler1->randomGrainPitch1 = (timeline.getValue("ranGranPitch1"));
    }

    ////////////////////////
    ////  Audio Timline ////
    ////////////////////////
   
    //Cutoff
	//LFO Speed
    if(Mgui->bUseCutoffLFO1==false){
        audioSampler1->cutoff1 = (timeline.getValue("lfoFilter1"))*10000.0f;
    } else if(Mgui->bUseCutoff1==false){
    	audioSampler1->cutoff1 = (timeline.getValue("cutoff1"));
    }

	//Crush
    if(Mgui->bUseCrush1==false){
    	audioSampler1->rate = (timeline.getValue("crushAmount1"));
    }

	//Bits
    if(Mgui->bUseBits1==false){
    	audioSampler1->bits = (timeline.getValue("bits1"));
    }

	//DelayTime
    if(Mgui->bUseDelayTime1==false){
    	audioSampler1->delayTime1 = (timeline.getValue("delayTime1"));
    }

	//DelayFeedback
    if(Mgui->bUseDelayFeedback1==false){
    	audioSampler1->delayFeedback1 = (timeline.getValue("delayFeedback1"));
    }

	//Reverb Decay
    if(Mgui->bUseReverbDecay1==false){
    	audioSampler1->reverbSize = (timeline.getValue("reverbDecay1"));
    }

	//Reverb Dry/Wet
    if(Mgui->bUseReverbDryWet1==false){
    	audioSampler1->reverbDryWet = (timeline.getValue("reverbDryWet1"));
    }


}

//--------------------------------------------------------------
float MainTimeline::getCurrentTimeMillis(){
//    return timeline.getCurrentTimeMillis();
}


//--------------------------------------------------------------
void MainTimeline::draw(){
    ofVec2f offset = ofVec2f(0, 760);
    timeline.setOffset(offset);
    
 //   if(Mgui->bShowTimeline==true){
        timeline.draw();
 //   }
    
    
}

//--------------------------------------------------------------
void MainTimeline::play(){
	
	timeline.togglePlay();
}

//--------------------------------------------------------------
void MainTimeline::saveAutomation(){
    timeline.save();
}

//--------------------------------------------------------------
void MainTimeline::show(){
	
	timeline.show();
}

//--------------------------------------------------------------
void MainTimeline::hide(){
	
	timeline.hide();
}
