/*
 *  midiFighter.h
 *  InputExample
 *
 *  Created by Joshua Batty on 5/08/12.
 *  Copyright 2012 Buffer Music Production. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class livid : public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
	string NoteOnOff;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	
	ofxMidiOut midiOut;
	int channel, note, velocity;
	
	//Midi Fighter Variables
	int mfSlider1,mfSlider2;
	int mfKnob1,mfKnob2;
	bool mfButton[16];
	bool mfToggle[4];
	
	/*Livid Variables*/
	
	//Knobs Bank 1
	int knobsB1[12];
    
	//Knobs Bank 2
	int knobsB2[12];
	bool bKnobsB2[12];
    
	//Knobs Bank 3
	int knobsB3[12];
	
	//Sliders
	int sliders[8];
	
	//Middle Buttons
	bool buttons[16];
	
	//Buttons Row 1
	bool buttonsR1[16];
    
	//Buttons Row 2
	bool buttonsR2[16];
	
	int i;
    
};
