//
//  mainTimeline.cpp
//  emptyExample
//
//  Created by Joshua Batty on 2/02/13.
//
//

#include "mainTimeline.h"


//--------------------------------------------------------------
void MainTimeline::setup(Gui *gui, AudioSampler *_audioSampler1, AudioSampler *_audioSampler2, AudioSampler *_audioSampler3, AudioSampler *_audioSampler4, AudioBinaural *_audioBinaural){
    
    Mgui = gui;
    audioBinaural = _audioBinaural;
    audioSampler1 = _audioSampler1;
    audioSampler2 = _audioSampler2;
    audioSampler3 = _audioSampler3;
    audioSampler4 = _audioSampler4;
    
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

	timeline.addPage("Speed", true);
	timeline.setPageName("Speed");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("Speed1", "Speed1.xml", ofRange(0.0f, 5.0f));
	timeline.addCurves("Speed2", "Speed2.xml", ofRange(0.0f, 5.0f));
	timeline.addCurves("Speed3", "Speed3.xml", ofRange(0.0f, 5.0f));
	timeline.addCurves("Speed4", "Speed4.xml", ofRange(0.0f, 5.0f));

    timeline.addPage("Pitch", true);
	timeline.setPageName("Pitch");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("pitch1", "pitch1.xml", ofRange(0.0f, 8.0f));
	timeline.addCurves("pitch2", "pitch2.xml", ofRange(0.0f, 8.0f));
	timeline.addCurves("pitch3", "pitch3.xml", ofRange(0.0f, 8.0f));
	timeline.addCurves("pitch4", "pitch4.xml", ofRange(0.0f, 8.0f));

    //GRANULAR
    timeline.addPage("Grain Size", true);
	timeline.setPageName("Grain Size");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("grainSize1", "grainSize1.xml", ofRange(0.01f, 0.25f));
	timeline.addCurves("grainSize2", "grainSize2.xml", ofRange(0.01f, 0.25f));
	timeline.addCurves("grainSize3", "grainSize3.xml", ofRange(0.01f, 0.25f));
	timeline.addCurves("grainSize4", "grainSize4.xml", ofRange(0.01f, 0.25f));

    timeline.addPage("Overlaps", true);
	timeline.setPageName("Overlaps");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("overlaps1", "overlaps1.xml", ofRange(1, 10));
	timeline.addCurves("overlaps2", "overlaps2.xml", ofRange(1, 10));
	timeline.addCurves("overlaps3", "overlaps3.xml", ofRange(1, 10));
	timeline.addCurves("overlaps4", "overlaps4.xml", ofRange(1, 10));

    timeline.addPage("Random Grain", true);
	timeline.setPageName("Random Grain");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("ranGranSize1", "ranGranSize1.xml", ofRange(0.0, 0.025f));
	timeline.addCurves("ranGranPitch1", "ranGranPitch1.xml", ofRange(0.0, 4.0f));
	timeline.addCurves("ranGranPitch2", "ranGranPitch2.xml", ofRange(0.0, 4.0f));
	timeline.addCurves("ranGranPitch3", "ranGranPitch3.xml", ofRange(0.0, 4.0f));
	timeline.addCurves("ranGranPitch4", "ranGranPitch4.xml", ofRange(0.0, 4.0f));

    ////////////////////////
    ////  Audio Timline ////
    ////////////////////////
    //AUDIO
	//LFO
    timeline.addPage("Cutoff", true);
    timeline.setPageName("Cutoff");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("cutoff1", "cutoff1.xml", ofRange(0, 10000));
	timeline.addCurves("cutoff2", "cutoff2.xml", ofRange(0, 10000));
	timeline.addCurves("cutoff3", "cutoff3.xml", ofRange(0, 10000));
	timeline.addCurves("cutoff4", "cutoff4.xml", ofRange(0, 10000));

    //Filter speed = 200......filter amp = 3000
	timeline.addPage("Filter LFO", true);
	timeline.setPageName("Filter LFO");
    timeline.addTrack("Track", &waveform);
    timeline.addLFO("lfoFilter1");
    timeline.addLFO("lfoFilter2");
    timeline.addLFO("lfoFilter3");
    timeline.addLFO("lfoFilter4");

	//CRUSH
	timeline.addPage("Crush", true);
	timeline.setPageName("Crush");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("crushAmount1", "crushAmount1.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("crushAmount2", "crushAmount2.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("crushAmount3", "crushAmount3.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("crushAmount4", "crushAmount4.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("bits1", "bits1.xml", ofRange(0, 32));
	timeline.addCurves("bits2", "bits2.xml", ofRange(0, 32));
	timeline.addCurves("bits3", "bits3.xml", ofRange(0, 32));
	timeline.addCurves("bits4", "bits4.xml", ofRange(0, 32));

	//DELAY
	timeline.addPage("Delay", true);
	timeline.setPageName("Delay");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("delayTime1", "delayTime1.xml", ofRange(10, 3000));
	timeline.addCurves("delayTime2", "delayTime2.xml", ofRange(10, 3000));
	timeline.addCurves("delayTime3", "delayTime3.xml", ofRange(10, 3000));
	timeline.addCurves("delayTime4", "delayTime4.xml", ofRange(10, 3000));
	timeline.addCurves("delayFeedback1", "delayFeedback1.xml", ofRange(0.0f, 0.98f));
	timeline.addCurves("delayFeedback2", "delayFeedback2.xml", ofRange(0.0f, 0.98f));
	timeline.addCurves("delayFeedback3", "delayFeedback3.xml", ofRange(0.0f, 0.98f));
	timeline.addCurves("delayFeedback4", "delayFeedback4.xml", ofRange(0.0f, 0.98f));

	//REVERB
	timeline.addPage("Reverb", true);
	timeline.setPageName("Reverb");
    timeline.addTrack("Track", &waveform);
	timeline.addCurves("reverbDecay1", "reverbDecay1.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDecay2", "reverbDecay2.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDecay3", "reverbDecay3.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDecay4", "reverbDecay4.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDryWet1", "reverbDryWet1.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDryWet2", "reverbDryWet2.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDryWet3", "reverbDryWet3.xml", ofRange(0.0f, 1.0f));
	timeline.addCurves("reverbDryWet4", "reverbDryWet4.xml", ofRange(0.0f, 1.0f));

       timeline.getColor("defaultColors.xml");
  //  timeline.play();
}

//--------------------------------------------------------------
void MainTimeline::update(){
    
    ////////////////////////
    ////  Video Timline ////
    ////////////////////////

	//Speed
    if(Mgui->bUseSpeed1==false || Mgui->bUseSpeedMaster==false){
        audioSampler1->speed1 = (timeline.getValue("Speed1"));
    }
    if(Mgui->bUseSpeed2==false || Mgui->bUseSpeedMaster==false){
        audioSampler2->speed1 = (timeline.getValue("Speed2"));
    }
    if(Mgui->bUseSpeed3==false || Mgui->bUseSpeedMaster==false){
        audioSampler3->speed1 = (timeline.getValue("Speed3"));
    }
    if(Mgui->bUseSpeed4==false || Mgui->bUseSpeedMaster==false){
        audioSampler4->speed1 = (timeline.getValue("Speed4"));
    }

    //GrainSize
    if(Mgui->bUseGrainSize1==false || Mgui->bUseGrainSizeMaster==false){
        audioSampler1->grainLength1 = (timeline.getValue("grainSize1"));
    }
    if(Mgui->bUseGrainSize2==false || Mgui->bUseGrainSizeMaster==false){
        audioSampler2->grainLength1 = (timeline.getValue("grainSize2"));
    }
    if(Mgui->bUseGrainSize3==false || Mgui->bUseGrainSizeMaster==false){
        audioSampler3->grainLength1 = (timeline.getValue("grainSize3"));
    }
    if(Mgui->bUseGrainSize4==false || Mgui->bUseGrainSizeMaster==false){
        audioSampler4->grainLength1 = (timeline.getValue("grainSize4"));
    }

    //Grain Overlpas
    if(Mgui->bUseOverlaps1==false || Mgui->bUseOverlapsMaster==false){
        audioSampler1->overlaps1 = (timeline.getValue("overlaps1"));
    }
    if(Mgui->bUseOverlaps2==false || Mgui->bUseOverlapsMaster==false){
        audioSampler2->overlaps1 = (timeline.getValue("overlaps2"));
    }
    if(Mgui->bUseOverlaps3==false || Mgui->bUseOverlapsMaster==false){
        audioSampler3->overlaps1 = (timeline.getValue("overlaps3"));
    }
    if(Mgui->bUseOverlaps4==false || Mgui->bUseOverlapsMaster==false){
        audioSampler4->overlaps1 = (timeline.getValue("overlaps4"));
    }

    //Pitch
    if(Mgui->bUsePitch1==false || Mgui->bUsePitchMaster==false){
        audioSampler1->pitch1 = (timeline.getValue("pitch1"));
    }
    if(Mgui->bUsePitch2==false || Mgui->bUsePitchMaster==false){
        audioSampler2->pitch1 = (timeline.getValue("pitch2"));
    }
    if(Mgui->bUsePitch3==false || Mgui->bUsePitchMaster==false){
        audioSampler3->pitch1 = (timeline.getValue("pitch3"));
    }
    if(Mgui->bUsePitch4==false || Mgui->bUsePitchMaster==false){
        audioSampler4->pitch1 = (timeline.getValue("pitch4"));
    }

    //Random Grain Size
    if(Mgui->bUseRandomGrainSize1==false || Mgui->bUseRandomGrainSizeMaster==false){
        audioSampler1->randomGrainSize1 = (timeline.getValue("ranGranSize1"));
    }
    if(Mgui->bUseRandomGrainSize2==false || Mgui->bUseRandomGrainSizeMaster==false){
        audioSampler2->randomGrainSize1 = (timeline.getValue("ranGranSize2"));
    }
    if(Mgui->bUseRandomGrainSize3==false || Mgui->bUseRandomGrainSizeMaster==false){
        audioSampler3->randomGrainSize1 = (timeline.getValue("ranGranSize3"));
    }
    if(Mgui->bUseRandomGrainSize4==false || Mgui->bUseRandomGrainSizeMaster==false){
        audioSampler4->randomGrainSize1 = (timeline.getValue("ranGranSize4"));
    }

    //Random Grain Pitch
    if(Mgui->bUseRandomGrainPitch1==false || Mgui->bUseRandomGrainPitchMaster==false){
        audioSampler1->randomGrainPitch1 = (timeline.getValue("ranGranPitch1"));
    }
    if(Mgui->bUseRandomGrainPitch2==false || Mgui->bUseRandomGrainPitchMaster==false){
        audioSampler2->randomGrainPitch1 = (timeline.getValue("ranGranPitch2"));
    }
    if(Mgui->bUseRandomGrainPitch3==false || Mgui->bUseRandomGrainPitchMaster==false){
        audioSampler3->randomGrainPitch1 = (timeline.getValue("ranGranPitch3"));
    }
    if(Mgui->bUseRandomGrainPitch4==false || Mgui->bUseRandomGrainPitchMaster==false){
        audioSampler4->randomGrainPitch1 = (timeline.getValue("ranGranPitch4"));
    }

    ////////////////////////
    ////  Audio Timline ////
    ////////////////////////
/*    
    //Cutoff
	//LFO Speed
    if(Mgui->bUseCutoffLFO1==false || Mgui->bUseCutoffLFOMaster==false){
        myData->cutoff1 = (timeline.getValue("lfoFilter1"))*10000.0f;
    } else if(Mgui->bUseCutoff1==false || Mgui->bUseCutoffMaster==false){
    	myData->cutoff1 = (timeline.getValue("cutoff1"));
    }

	//Crush
    if(Mgui->bUseCrush1==false || Mgui->bUseCrushMaster==false){
    	myData->crushAmount1 = (timeline.getValue("crushAmount1"));
    }

	//Bits
    if(Mgui->bUseBits1==false || Mgui->bUseBitsMaster==false){
    	myData->crushBits1 = (timeline.getValue("bits1"));
    }

	//DelayTime
    if(Mgui->bUseDelayTime1==false || Mgui->bUseDelayTimeMaster==false){
    	myData->delayTime1 = (timeline.getValue("delayTime1"));
    }

	//DelayFeedback
    if(Mgui->bUseDelayFeedback1==false || Mgui->bUseDelayFeedbackMaster==false){
    	myData->delayFeedback1 = (timeline.getValue("delayFeedback1"));
    }

	//Reverb Decay
    if(Mgui->bUseReverbDecay1==false || Mgui->bUseReverbDecayMaster==false){
    	myData->reverbDecay1 = (timeline.getValue("reverbDecay1"));
    }

	//Reverb Dry/Wet
    if(Mgui->bUseReverbDryWet1==false || Mgui->bUseReverbDryWetMaster==false){
    	myData->reverbDryWet1 = (timeline.getValue("reverbDryWet1"));
    }
*/

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
