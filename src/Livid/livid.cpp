/*
 *  midiFighter.cpp
 *  InputExample
 *
 *  Created by Joshua Batty on 5/08/12.
 *  Copyright 2012 Buffer Music Production. All rights reserved.
 *
 */

#include "livid.h"

//--------------------------------------------------------------
void livid::setup(Gui *gui, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4) {
    
    Mgui = gui;
    audioSample1 = _audioSample1;
    audioSample2 = _audioSample2;
    audioSample3 = _audioSample3;
    audioSample4 = _audioSample4;
    
	// print input ports to console
	midiIn.listPorts(); // via instance
	midiOut.listPorts(); // via instance
    //ofxMidiIn::listPorts(); // via static as well
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	midiOut.openPort(0);	// by number
    //midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add midiFighter as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
	
	channel = 1;
	note = 0;
	velocity = 0;
	
	i = 0;
	
	//Init toggles
	for(int i = 0; i < 15; i++){
		buttons[i]=false;
		buttonsR1[i]=false;
		buttonsR2[i]=false;
	}
	for(int i = 0; i < 12; i++){
		bKnobsB2[i]=false;
	}
    
    //Init Midi
    
    //Binaural sub
    knobsB3[2] = 100;
    knobsB3[5] = 40;
    knobsB3[8] = 20;
    
    //Volume
    sliders[4] = 100;
    sliders[5] = 100;
    sliders[6] = 100;
    sliders[7] = 100;
    
    //Scrub
 //   sliders[4] = 64;
 //   sliders[5] = 64;
 //   sliders[6] = 64;
    
    //Grains
    //Pitch
    knobsB1[0] = 20;
    knobsB1[3] = 20;
    knobsB1[6] = 20;
    knobsB1[9] = 20;
    
    //Speed
    sliders[0] = 94;
    sliders[1] = 94;
    sliders[2] = 94;
    sliders[3] = 94;
    
    //GrainLength
    knobsB1[1] = 40;
    knobsB1[4] = 40;
    knobsB1[7] = 40;
    knobsB1[10] = 40;
    
    //Overlaps
    knobsB1[2] = 30;
    knobsB1[5] = 30;
    knobsB1[8] = 30;
    knobsB1[11] = 30;
    
    //Ran Grain Pitch
    knobsB3[0] = 0;
    knobsB3[3] = 0;
    knobsB3[6] = 0;
    knobsB3[9] = 0;
    
    //Ran Grain Length
    knobsB3[1] = 0;
    knobsB3[4] = 0;
    knobsB3[7] = 0;
    knobsB3[10] = 0;
    
    //FX
    knobsB2[0] = 0;
    knobsB2[1] = 0;
    knobsB2[2] = 0;
    knobsB2[3] = 0;
    knobsB2[4] = 0;
    knobsB2[5] = 0;
    knobsB2[6] = 0;
    knobsB2[7] = 0;
    knobsB2[8] = 0;
    knobsB2[9] = 0;
    knobsB2[10] = 0;
    knobsB2[11] = 0;
}

//--------------------------------------------------------------
void livid::draw() {
	
    
	ofSetColor(0);
	
	// draw the last recieved message contents to the screen
	text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
	ofDrawBitmapString(text.str(), 20, 20);
	text.str(""); // clear
	
	text << "channel: " << midiMessage.channel;
	ofDrawBitmapString(text.str(), 20, 34);
	text.str(""); // clear
	
	text << "pitch: " << midiMessage.pitch;
	ofDrawBitmapString(text.str(), 20, 48);
	text.str(""); // clear
	ofRect(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "velocity: " << midiMessage.velocity;
	ofDrawBitmapString(text.str(), 20, 96);
	text.str(""); // clear
	ofRect(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "control: " << midiMessage.control;
	ofDrawBitmapString(text.str(), 20, 144);
	text.str(""); // clear
	ofRect(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "value: " << midiMessage.value;
	ofDrawBitmapString(text.str(), 20, 192);
	text.str(""); // clear
	if(midiMessage.status == MIDI_PITCH_BEND) {
		ofRect(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
	}
	else {
		ofRect(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
	}
	
	text << "delta: " << midiMessage.deltatime;
	ofDrawBitmapString(text.str(), 20, 240);
	text.str(""); // clear
	
    
	
}

//--------------------------------------------------------------
void livid::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void livid::newMidiMessage(ofxMidiMessage& msg) {
	
	// make a copy of the latest message
	midiMessage = msg;
    
    NoteOnOff = ofxMidiMessage::getStatusString(midiMessage.status);
	
	////////////////////////////////////
	//			KNOBS BANK 1		  //
	////////////////////////////////////
	
	if(midiMessage.control == 1){
		knobsB1[0] = midiMessage.value;
        Mgui->setPitch1(ofMap(knobsB1[0],0,127,0.0,8.0));
	}
	if(midiMessage.control == 2){
		knobsB1[1] = midiMessage.value;
        Mgui->setGrainSize1(ofMap(knobsB1[1],0,127,0.025,0.49));
	}
	if(midiMessage.control == 3){
		knobsB1[2] = midiMessage.value;
        Mgui->setOverlaps1(ofMap(knobsB1[2],0,127,1,6));
	}
    
	if(midiMessage.control == 5){
		knobsB1[3] = midiMessage.value;
        Mgui->setPitch2(ofMap(knobsB1[3],0,127,0.0,8.0));
	}
	if(midiMessage.control == 6){
		knobsB1[4] = midiMessage.value;
        Mgui->setGrainSize2(ofMap(knobsB1[4],0,127,0.025,0.49));
	}
	if(midiMessage.control == 7){
		knobsB1[5] = midiMessage.value;
        Mgui->setOverlaps2(ofMap(knobsB1[5],0,127,1,6));
	}
    
	if(midiMessage.control == 9){
		knobsB1[6] = midiMessage.value;
        Mgui->setPitch3(ofMap(knobsB1[6],0,127,0.0,8.0));
	}
	if(midiMessage.control == 10){
		knobsB1[7] = midiMessage.value;
        Mgui->setGrainSize3(ofMap(knobsB1[7],0,127,0.025,0.49));
	}
	if(midiMessage.control == 11){
		knobsB1[8] = midiMessage.value;
        Mgui->setOverlaps3(ofMap(knobsB1[8],0,127,1,6));
	}
	
	if(midiMessage.control == 13){
		knobsB1[9] = midiMessage.value;
        Mgui->setPitch4(ofMap(knobsB1[9],0,127,0.0,8.0));
	}
	if(midiMessage.control == 14){
		knobsB1[10] = midiMessage.value;
        Mgui->setGrainSize4(ofMap(knobsB1[10],0,127,0.025,0.49));
	}
	if(midiMessage.control == 15){
		knobsB1[11] = midiMessage.value;
        Mgui->setOverlaps4(ofMap(knobsB1[11],0,127,1,6));
	}
	
	////////////////////////////////////
	//			KNOBS BANK 2		  //
	////////////////////////////////////
	
	if(midiMessage.control == 48){
		knobsB2[0] = midiMessage.value;
        if(audioSample1->bFilter==true){
            Mgui->setCutoff1(ofMap(knobsB2[0],0,127,10.0,10000.0));
        } else if(audioSample1->bReverb==true){
            Mgui->setReverbDryWet1(ofMap(knobsB2[0],0,127,0.0,1.0));
        } else if(audioSample1->bFx==true){
            Mgui->setDelayTime1(ofMap(knobsB2[0],0,127,10.0,10000.0));
        }
	}
	if(midiMessage.control == 49){
		knobsB2[1] = midiMessage.value;
        if(audioSample1->bFilter==true){
            Mgui->setLfoSpeed1(ofMap(knobsB2[1],0,127,0.0,200.0));
        } else if(audioSample1->bReverb==true){
            Mgui->setReverbDecay1(ofMap(knobsB2[1],0,127,0.0,1.0));
        } else if(audioSample1->bFx==true){
            Mgui->setDelayFeedback1(ofMap(knobsB2[1],0,127,0.0,1.0));
        }
	}
	if(midiMessage.control == 50){
		knobsB2[2] = midiMessage.value;
        if(audioSample1->bFilter==true){
            Mgui->setLfoAmp1(ofMap(knobsB2[2],0,127,0.0,3000.0));
        } else if(audioSample1->bFx==true){
            Mgui->setRate1(ofMap(knobsB2[2],0,127,1.0,0.0));
        }
	}
	
	if(midiMessage.control == 51){
		knobsB2[3] = midiMessage.value;
        if(audioSample2->bFilter==true){
            Mgui->setCutoff2(ofMap(knobsB2[3],0,127,10.0,10000.0));
        } else if(audioSample2->bReverb==true){
            Mgui->setReverbDryWet2(ofMap(knobsB2[3],0,127,0.0,1.0));
        } else if(audioSample2->bFx==true){
            Mgui->setDelayTime2(ofMap(knobsB2[3],0,127,10.0,10000.0));
        }
	}
	if(midiMessage.control == 52){
		knobsB2[4] = midiMessage.value;
        if(audioSample2->bFilter==true){
            Mgui->setLfoSpeed2(ofMap(knobsB2[4],0,127,0.0,200.0));
        } else if(audioSample2->bReverb==true){
            Mgui->setReverbDecay2(ofMap(knobsB2[4],0,127,0.0,1.0));
        } else if(audioSample2->bFx==true){
            Mgui->setDelayFeedback2(ofMap(knobsB2[4],0,127,0.0,1.0));
        }
	}
	if(midiMessage.control == 53){
		knobsB2[5] = midiMessage.value;
        if(audioSample2->bFilter==true){
            Mgui->setLfoAmp2(ofMap(knobsB2[5],0,127,0.0,3000.0));
        } else if(audioSample2->bFx==true){
            Mgui->setRate2(ofMap(knobsB2[5],0,127,1.0,0.0));
        }
	}
	
	if(midiMessage.control == 54){
		knobsB2[6] = midiMessage.value;
        if(audioSample3->bFilter==true){
            Mgui->setCutoff3(ofMap(knobsB2[6],0,127,10.0,10000.0));
        } else if(audioSample3->bReverb==true){
            Mgui->setReverbDryWet3(ofMap(knobsB2[6],0,127,0.0,1.0));
        } else if(audioSample3->bFx==true){
            Mgui->setDelayTime3(ofMap(knobsB2[6],0,127,10.0,10000.0));
        }
	}
	if(midiMessage.control == 55){
		knobsB2[7] = midiMessage.value;
        if(audioSample3->bFilter==true){
            Mgui->setLfoSpeed3(ofMap(knobsB2[7],0,127,0.0,200.0));
        } else if(audioSample3->bReverb==true){
            Mgui->setReverbDecay3(ofMap(knobsB2[7],0,127,0.0,1.0));
        } else if(audioSample3->bFx==true){
            Mgui->setDelayFeedback3(ofMap(knobsB2[7],0,127,0.0,1.0));
        }
	}
	if(midiMessage.control == 56){
		knobsB2[8] = midiMessage.value;
        if(audioSample3->bFilter==true){
            Mgui->setLfoAmp3(ofMap(knobsB2[8],0,127,0.0,3000.0));
        } else if(audioSample3->bFx==true){
            Mgui->setRate3(ofMap(knobsB2[8],0,127,1.0,0.0));
        }
	}
	
	if(midiMessage.control == 57){
		knobsB2[9] = midiMessage.value;
        if(audioSample4->bFilter==true){
            Mgui->setCutoff4(ofMap(knobsB2[9],0,127,10.0,10000.0));
        } else if(audioSample4->bReverb==true){
            Mgui->setReverbDryWet4(ofMap(knobsB2[9],0,127,0.0,1.0));
        } else if(audioSample4->bFx==true){
            Mgui->setDelayTime4(ofMap(knobsB2[9],0,127,10.0,10000.0));
        }
	}
	if(midiMessage.control == 58){
		knobsB2[10] = midiMessage.value;
        if(audioSample4->bFilter==true){
            Mgui->setLfoSpeed4(ofMap(knobsB2[10],0,127,0.0,200.0));
        } else if(audioSample4->bReverb==true){
            Mgui->setReverbDecay4(ofMap(knobsB2[10],0,127,0.0,1.0));
        } else if(audioSample4->bFx==true){
            Mgui->setDelayFeedback4(ofMap(knobsB2[10],0,127,0.0,1.0));
        }
	}
	if(midiMessage.control == 59){
		knobsB2[11] = midiMessage.value;
        if(audioSample4->bFilter==true){
            Mgui->setLfoAmp4(ofMap(knobsB2[11],0,127,0.0,3000.0));
        } else if(audioSample4->bFx==true){
            Mgui->setRate4(ofMap(knobsB2[11],0,127,1.0,0.0));
        }
	}
	
	////////////////////////////////////
	//			KNOBS BANK 3		  //
	////////////////////////////////////
	
	if(midiMessage.control == 17){
		knobsB3[0] = midiMessage.value;
        Mgui->setRandomGrainSize1(ofMap(knobsB3[0],0,127,0.0,0.5));
	}
	if(midiMessage.control == 18){
		knobsB3[1] = midiMessage.value;
        Mgui->setRandomGrainPitch1(ofMap(knobsB3[1],0,127,0.0,0.5));
	}
	if(midiMessage.control == 19){
		knobsB3[2] = midiMessage.value;
        Mgui->setBinVolume(ofMap(knobsB3[2],0,127,0.0,0.99));
	}
	
	if(midiMessage.control == 21){
		knobsB3[3] = midiMessage.value;
        Mgui->setRandomGrainSize2(ofMap(knobsB3[3],0,127,0.0,0.5));
	}
	if(midiMessage.control == 22){
		knobsB3[4] = midiMessage.value;
        Mgui->setRandomGrainPitch2(ofMap(knobsB3[4],0,127,0.0,0.5));
	}
	if(midiMessage.control == 23){
		knobsB3[5] = midiMessage.value;
        Mgui->setBinPitch(ofMap(knobsB3[5],0,127,30.0,150.0));
	}
	
	if(midiMessage.control == 25){
		knobsB3[6] = midiMessage.value;
        Mgui->setRandomGrainSize3(ofMap(knobsB3[6],0,127,0.0,0.5));
	}
	if(midiMessage.control == 26){
		knobsB3[7] = midiMessage.value;
        Mgui->setRandomGrainPitch3(ofMap(knobsB3[7],0,127,0.0,0.5));
	}
	if(midiMessage.control == 27){
		knobsB3[8] = midiMessage.value;
        Mgui->setBinOffset(ofMap(knobsB3[8],0,127,0.0,14.0));
	}
	
	if(midiMessage.control == 29){
		knobsB3[9] = midiMessage.value;
        Mgui->setRandomGrainSize4(ofMap(knobsB3[9],0,127,0.0,0.5));
	}
	if(midiMessage.control == 30){
		knobsB3[10] = midiMessage.value;
        Mgui->setRandomGrainPitch4(ofMap(knobsB3[10],0,127,0.0,0.5));
	}
	if(midiMessage.control == 31){
		knobsB3[11] = midiMessage.value;
	}
	
	//Knob 1
	if(midiMessage.pitch == 48 && midiMessage.velocity == 64){
		bKnobsB2[0] = true;
	} else if(midiMessage.pitch == 48 && midiMessage.velocity == 0){
		bKnobsB2[0] = false;
	}
	
	//Knob 2
	if(midiMessage.pitch == 49 && midiMessage.velocity == 64){
		bKnobsB2[1] = true;
	} else if((midiMessage.pitch == 49) && midiMessage.velocity == 0){
		bKnobsB2[1] = false;
	}
	
	//Knob 3
	if(midiMessage.pitch == 50 && midiMessage.velocity == 64){
		bKnobsB2[2] = true;
	} else if((midiMessage.pitch == 50) && midiMessage.velocity == 0){
		bKnobsB2[2] = false;
	}
	
	//Knob 4
	if(midiMessage.pitch == 51 && midiMessage.velocity == 64){
		bKnobsB2[3] = true;
	} else if((midiMessage.pitch == 51) && midiMessage.velocity == 0){
		bKnobsB2[3] = false;
	}
	
	//Knob 5
	if(midiMessage.pitch == 52 && midiMessage.velocity == 64){
		bKnobsB2[4] = true;
	} else if((midiMessage.pitch == 52) && midiMessage.velocity == 0){
		bKnobsB2[4] = false;
	}
	
	//Knob 6
	if(midiMessage.pitch == 53 && midiMessage.velocity == 64){
		bKnobsB2[5] = true;
	} else if((midiMessage.pitch == 53) && midiMessage.velocity == 0){
		bKnobsB2[5] = false;
	}
	
	//Knob 7
	if(midiMessage.pitch == 54 && midiMessage.velocity == 64){
		bKnobsB2[6] = true;
	} else if((midiMessage.pitch == 54) && midiMessage.velocity == 0){
		bKnobsB2[6] = false;
	}
	
	//Knob 8
	if(midiMessage.pitch == 55 && midiMessage.velocity == 64){
		bKnobsB2[7] = true;
	} else if((midiMessage.pitch == 55) && midiMessage.velocity == 0){
		bKnobsB2[7] = false;
	}
	
	//Knob 9
	if(midiMessage.pitch == 56 && midiMessage.velocity == 64){
		bKnobsB2[8] = true;
	} else if((midiMessage.pitch == 56) && midiMessage.velocity == 0){
		bKnobsB2[8] = false;
	}
	
	//Knob 10
	if(midiMessage.pitch == 57 && midiMessage.velocity == 64){
		bKnobsB2[9] = true;
	} else if((midiMessage.pitch == 57) && midiMessage.velocity == 0){
		bKnobsB2[9] = false;
	}
	
	//Knob 11
	if(midiMessage.pitch == 58 && midiMessage.velocity == 64){
		bKnobsB2[10] = true;
	} else if((midiMessage.pitch == 58) && midiMessage.velocity == 0){
		bKnobsB2[10] = false;
	}
	
	//Knob 12
	if(midiMessage.pitch == 59 && midiMessage.velocity == 64){
		bKnobsB2[11] = true;
	} else if((midiMessage.pitch == 59) && midiMessage.velocity == 0){
		bKnobsB2[11] = false;
	}
	
	////////////////////////////////////
	//			SLIDERS				  //
	////////////////////////////////////
	
	if(midiMessage.control == 4){
		sliders[0] = midiMessage.value;
        Mgui->setSpeed1(ofMap(sliders[0],0,127,-2.0,2.0));
	}
	if(midiMessage.control == 8){
		sliders[1] = midiMessage.value;
        Mgui->setSpeed2(ofMap(sliders[1],0,127,-2.0,2.0));
	}
	if(midiMessage.control == 12){
		sliders[2] = midiMessage.value;
        Mgui->setSpeed3(ofMap(sliders[2],0,127,-2.0,2.0));
	}
	if(midiMessage.control == 16){
		sliders[3] = midiMessage.value;
        Mgui->setSpeed4(ofMap(sliders[3],0,127,-2.0,2.0));
	}
    
	if(midiMessage.control == 20){
		sliders[4] = midiMessage.value;
        Mgui->setVolume1(ofMap(sliders[4],0,127,0.0,0.99));
	}
	if(midiMessage.control == 24){
		sliders[5] = midiMessage.value;
        Mgui->setVolume2(ofMap(sliders[5],0,127,0.0,0.99));
	}
	if(midiMessage.control == 28){
		sliders[6] = midiMessage.value;
        Mgui->setVolume3(ofMap(sliders[6],0,127,0.0,0.99));
	}
	if(midiMessage.control == 32){
		sliders[7] = midiMessage.value;
        Mgui->setVolume4(ofMap(sliders[7],0,127,0.0,0.99));
	}
	
	////////////////////////////////////
	//			MF TOGGLES			  //
	////////////////////////////////////
	
	//Toggle 1
	if(midiMessage.pitch == 4 && midiMessage.velocity == 64){
		mfToggle[0] = true;
	} else if((midiMessage.pitch == 4) && midiMessage.velocity == 0){
		mfToggle[0] = false;
	}
	
	//Toggle 2
	if(midiMessage.pitch == 5 && midiMessage.velocity == 64){
		mfToggle[1] = true;
	} else if((midiMessage.pitch == 5) && midiMessage.velocity == 0){
		mfToggle[1] = false;
	}
	
	//Toggle 3
	if(midiMessage.pitch == 6 && midiMessage.velocity == 64){
		mfToggle[2] = true;
	} else if((midiMessage.pitch == 6) && midiMessage.velocity == 0){
		mfToggle[2] = false;
	}
	
	//Toggle 4
	if(midiMessage.pitch == 7 && midiMessage.velocity == 64){
		mfToggle[3] = true;
	} else if((midiMessage.pitch == 7) && midiMessage.velocity == 0){
		mfToggle[3] = false;
	}
	
	////////////////////////////////////
	//		    MIDDLE BUTTONS		  //
	////////////////////////////////////
	
	//Button 1
	if(midiMessage.pitch == 0 && midiMessage.velocity == 64){
		buttons[0] = true;
	} else if(midiMessage.pitch == 0 && midiMessage.velocity == 0){
		buttons[0] = false;
	}
	
	//Button 2
	if(midiMessage.pitch == 4 && midiMessage.velocity == 64){
		buttons[1] = true;
	} else if((midiMessage.pitch == 4) && midiMessage.velocity == 0){
		buttons[1] = false;
	}
	
	//Button 3
	if(midiMessage.pitch == 8 && midiMessage.velocity == 64){
		buttons[2] = true;
	} else if((midiMessage.pitch == 8) && midiMessage.velocity == 0){
		buttons[2] = false;
	}
	
	//Button 4
	if(midiMessage.pitch == 12 && midiMessage.velocity == 64){
		buttons[3] = true;
	} else if((midiMessage.pitch == 12) && midiMessage.velocity == 0){
		buttons[3] = false;
	}
	
	//Button 5
	if(midiMessage.pitch == 1 && midiMessage.velocity == 64){
		buttons[4] = true;
	} else if((midiMessage.pitch == 1) && midiMessage.velocity == 0){
		buttons[4] = false;
	}
	
	//Button 6
	if(midiMessage.pitch == 5 && midiMessage.velocity == 64){
		buttons[5] = true;
	} else if((midiMessage.pitch == 5) && midiMessage.velocity == 0){
		buttons[5] = false;
	}
	
	//Button 7
	if(midiMessage.pitch == 9 && midiMessage.velocity == 64){
		buttons[6] = true;
	} else if((midiMessage.pitch == 9) && midiMessage.velocity == 0){
		buttons[6] = false;
	}
	
	//Button 8
	if(midiMessage.pitch == 13 && midiMessage.velocity == 64){
		buttons[7] = true;
	} else if((midiMessage.pitch == 13) && midiMessage.velocity == 0){
		buttons[7] = false;
	}
	
	//Button 9
	if(midiMessage.pitch == 2 && midiMessage.velocity == 64){
		buttons[8] = true;
	} else if((midiMessage.pitch == 2) && midiMessage.velocity == 0){
		buttons[8] = false;
	}
	
	//Button 10
	if(midiMessage.pitch == 6 && midiMessage.velocity == 64){
		buttons[9] = true;
	} else if((midiMessage.pitch == 6) && midiMessage.velocity == 0){
		buttons[9] = false;
	}
	
	//Button 11
	if(midiMessage.pitch == 10 && midiMessage.velocity == 64){
		buttons[10] = true;
	} else if((midiMessage.pitch == 10) && midiMessage.velocity == 0){
		buttons[10] = false;
	}
	
	//Button 12
	if(midiMessage.pitch == 14 && midiMessage.velocity == 64){
		buttons[11] = true;
	} else if((midiMessage.pitch == 14) && midiMessage.velocity == 0){
		buttons[11] = false;
	}
	
	//Button 13
	if(midiMessage.pitch == 3 && midiMessage.velocity == 64){
		buttons[12] = true;
	} else if((midiMessage.pitch == 3) && midiMessage.velocity == 0){
		buttons[12] = false;
	}
	
	//Button 14
	if(midiMessage.pitch == 7 && midiMessage.velocity == 64){
		buttons[13] = true;
	} else if((midiMessage.pitch == 7) && midiMessage.velocity == 0){
		buttons[13] = false;
	}
	
	//Button 15
	if(midiMessage.pitch == 11 && midiMessage.velocity == 64){
		buttons[14] = true;
	} else if((midiMessage.pitch == 11) && midiMessage.velocity == 0){
		buttons[14] = false;
	}
	
	//Button 16
	if(midiMessage.pitch == 15 && midiMessage.velocity == 64){
		buttons[15] = true;
	} else if((midiMessage.pitch == 15) && midiMessage.velocity == 0){
		buttons[15] = false;
	}
	
    
	////////////////////////////////////
	//		    BUTTONS ROW 1		  //
	////////////////////////////////////
    
	//Button 1
	if(midiMessage.pitch == 16 && midiMessage.velocity == 64){
		buttonsR1[0] = true;
	} else if(midiMessage.pitch == 16 && midiMessage.velocity == 0){
		buttonsR1[0] = false;
	}
	
	midiOut.sendNoteOn(channel, 16,  0);
    /*
     switch(buttonsR1[0]){
     case true:
     i++;
     break;
     }
     
     if(i%2==0)
     midiOut.sendNoteOn(channel, 16,  20);
     if(i%2==1)
     midiOut.sendNoteOn(channel, 16,  0);
     */
	
	
	//Button 2
	if(midiMessage.pitch == 17 && midiMessage.velocity == 64){
		buttonsR1[1] = true;
	} else if((midiMessage.pitch == 17) && midiMessage.velocity == 0){
		buttonsR1[1] = false;
	}
	
	//Button 3
	if(midiMessage.pitch == 18 && midiMessage.velocity == 64){
		buttonsR1[2] = true;
	} else if((midiMessage.pitch == 18) && midiMessage.velocity == 0){
		buttonsR1[2] = false;
	}
	
	//Button 4
	if(midiMessage.pitch == 19 && midiMessage.velocity == 64){
		buttonsR1[3] = true;
	} else if((midiMessage.pitch == 19) && midiMessage.velocity == 0){
		buttonsR1[3] = false;
	}
	
	//Button 5
	if(midiMessage.pitch == 20 && midiMessage.velocity == 64){
		buttonsR1[4] = true;
	} else if((midiMessage.pitch == 20) && midiMessage.velocity == 0){
		buttonsR1[4] = false;
	}
	
	//Button 6
	if(midiMessage.pitch == 21 && midiMessage.velocity == 64){
		buttonsR1[5] = true;
	} else if((midiMessage.pitch == 21) && midiMessage.velocity == 0){
		buttonsR1[5] = false;
	}
	
	//Button 7
	if(midiMessage.pitch == 22 && midiMessage.velocity == 64){
		buttonsR1[6] = true;
	} else if((midiMessage.pitch == 22) && midiMessage.velocity == 0){
		buttonsR1[6] = false;
	}
	
	//Button 8
	if(midiMessage.pitch == 23 && midiMessage.velocity == 64){
		buttonsR1[7] = true;
	} else if((midiMessage.pitch == 23) && midiMessage.velocity == 0){
		buttonsR1[7] = false;
	}
	
	//Button 9
	if(midiMessage.pitch == 24 && midiMessage.velocity == 64){
		buttonsR1[8] = true;
	} else if((midiMessage.pitch == 24) && midiMessage.velocity == 0){
		buttonsR1[8] = false;
	}
	
	//Button 10
	if(midiMessage.pitch == 25 && midiMessage.velocity == 64){
		buttonsR1[9] = true;
	} else if((midiMessage.pitch == 25) && midiMessage.velocity == 0){
		buttonsR1[9] = false;
	}
	
	//Button 11
	if(midiMessage.pitch == 26 && midiMessage.velocity == 64){
		buttonsR1[10] = true;
	} else if((midiMessage.pitch == 26) && midiMessage.velocity == 0){
		buttonsR1[10] = false;
	}
	
	//Button 12
	if(midiMessage.pitch == 27 && midiMessage.velocity == 64){
		buttonsR1[11] = true;
	} else if((midiMessage.pitch == 27) && midiMessage.velocity == 0){
		buttonsR1[11] = false;
	}
	
	//Button 13
	if(midiMessage.pitch == 28 && midiMessage.velocity == 64){
		buttonsR1[12] = true;
	} else if((midiMessage.pitch == 28) && midiMessage.velocity == 0){
		buttonsR1[12] = false;
	}
	
	//Button 14
	if(midiMessage.pitch == 29 && midiMessage.velocity == 64){
		buttonsR1[13] = true;
	} else if((midiMessage.pitch == 29) && midiMessage.velocity == 0){
		buttonsR1[13] = false;
	}
	
	//Button 15
	if(midiMessage.pitch == 30 && midiMessage.velocity == 64){
		buttonsR1[14] = true;
	} else if((midiMessage.pitch == 30) && midiMessage.velocity == 0){
		buttonsR1[14] = false;
	}
	
	//Button 16
	if(midiMessage.pitch == 31 && midiMessage.velocity == 64){
		buttonsR1[15] = true;
	} else if((midiMessage.pitch == 31) && midiMessage.velocity == 0){
		buttonsR1[15] = false;
	}
	
	////////////////////////////////////
	//		    BUTTONS ROW 2		  //
	////////////////////////////////////
	
	//Button 1
	if(midiMessage.pitch == 32 && midiMessage.velocity == 64){
		buttonsR2[0] = true;
	} else if(midiMessage.pitch == 32 && midiMessage.velocity == 0){
		buttonsR2[0] = false;
	}
	
	//Button 2
	if(midiMessage.pitch == 33 && midiMessage.velocity == 64){
		buttonsR2[1] = true;
	} else if((midiMessage.pitch == 33) && midiMessage.velocity == 0){
		buttonsR2[1] = false;
	}
	
	//Button 3
	if(midiMessage.pitch == 34 && midiMessage.velocity == 64){
		buttonsR2[2] = true;
	} else if((midiMessage.pitch == 34) && midiMessage.velocity == 0){
		buttonsR2[2] = false;
	}
	
	//Button 4
	if(midiMessage.pitch == 35 && midiMessage.velocity == 64){
		buttonsR2[3] = true;
	} else if((midiMessage.pitch == 35) && midiMessage.velocity == 0){
		buttonsR2[3] = false;
	}
	
	//Button 5
	if(midiMessage.pitch == 36 && midiMessage.velocity == 64){
		buttonsR2[4] = true;
	} else if((midiMessage.pitch == 36) && midiMessage.velocity == 0){
		buttonsR2[4] = false;
	}
	
	//Button 6
	if(midiMessage.pitch == 37 && midiMessage.velocity == 64){
		buttonsR2[5] = true;
	} else if((midiMessage.pitch == 37) && midiMessage.velocity == 0){
		buttonsR2[5] = false;
	}
	
	//Button 7
	if(midiMessage.pitch == 38 && midiMessage.velocity == 64){
		buttonsR2[6] = true;
	} else if((midiMessage.pitch == 38) && midiMessage.velocity == 0){
		buttonsR2[6] = false;
	}
	
	//Button 8
	if(midiMessage.pitch == 39 && midiMessage.velocity == 64){
		buttonsR2[7] = true;
	} else if((midiMessage.pitch == 39) && midiMessage.velocity == 0){
		buttonsR2[7] = false;
	}
	
	//Button 9
	if(midiMessage.pitch == 40 && midiMessage.velocity == 64){
		buttonsR2[8] = true;
	} else if((midiMessage.pitch == 40) && midiMessage.velocity == 0){
		buttonsR2[8] = false;
	}
	
	//Button 10
	if(midiMessage.pitch == 41 && midiMessage.velocity == 64){
		buttonsR2[9] = true;
	} else if((midiMessage.pitch == 41) && midiMessage.velocity == 0){
		buttonsR2[9] = false;
	}
	
	//Button 11
	if(midiMessage.pitch == 42 && midiMessage.velocity == 64){
		buttonsR2[10] = true;
	} else if((midiMessage.pitch == 42) && midiMessage.velocity == 0){
		buttonsR2[10] = false;
	}
	
	//Button 12
	if(midiMessage.pitch == 43 && midiMessage.velocity == 64){
		buttonsR2[11] = true;
	} else if((midiMessage.pitch == 43) && midiMessage.velocity == 0){
		buttonsR2[11] = false;
	}
	
	//Button 13
	if(midiMessage.pitch == 44 && midiMessage.velocity == 64){
		buttonsR2[12] = true;
	} else if((midiMessage.pitch == 44) && midiMessage.velocity == 0){
		buttonsR2[12] = false;
	}
	
	//Button 14
	if(midiMessage.pitch == 45 && midiMessage.velocity == 64){
		buttonsR2[13] = true;
	} else if((midiMessage.pitch == 45) && midiMessage.velocity == 0){
		buttonsR2[13] = false;
	}
	
	//Button 15
	if(midiMessage.pitch == 46 && midiMessage.velocity == 64){
		buttonsR2[14] = true;
	} else if((midiMessage.pitch == 46) && midiMessage.velocity == 0){
		buttonsR2[14] = false;
	}
	
	//Button 16
	if(midiMessage.pitch == 47 && midiMessage.velocity == 64){
		buttonsR2[15] = true;
	} else if((midiMessage.pitch == 47) && midiMessage.velocity == 0){
		buttonsR2[15] = false;
	}

}

