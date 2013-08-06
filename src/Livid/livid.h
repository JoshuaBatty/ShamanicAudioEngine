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
#include "gui.h"
#include "guiBinaural.h"

class livid : public ofxMidiListener {
	
public:
	
	void setup(Gui *gui, GuiBinaural *_guiBinaural, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4);
	void draw();
	void exit();
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
	string NoteOnOff;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	
	ofxMidiOut midiOut;
	int channel, note, velocity;
	
    Gui *Mgui;
    GuiBinaural *MguiBinaural;
    AudioSampler  *audioSample1, *audioSample2, *audioSample3, *audioSample4;
	
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
    bool bIsTurningOn[16];
    bool bIsTurningOff[16];
    int buttonState[16];
    int buttonsState[4];

    //Bottom row 1
    bool bButtonsR1IsTurningOn[16];
    bool bButtonsR1IsTurningOff[16];
    bool buttonsR1[16];
    
    //Bottom row 2
    bool bButtonsR2IsTurningOn[16];
    bool bButtonsR2IsTurningOff[16];
    bool buttonsR2[16];
	
	int i;
    bool bSwitchMidi;
};
