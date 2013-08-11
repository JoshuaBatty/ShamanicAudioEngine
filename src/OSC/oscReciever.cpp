/*
 *  oscReciever.cpp
 *  oscReceiveExample
 *
 *  Created by Alice Hobday on 23/06/12.
 *  Copyright 2012 BMP. All rights reserved.
 *
 */

#include "oscReciever.h"


//--------------------------------------------------------------
void oscReciever::setup(AudioSampler *_audioSample1){
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);
	
	current_msg_string = 0;
    
    audioSample1 = _audioSample1;

}


//--------------------------------------------------------------
void oscReciever::update(){
	
	//OSC stuff
	// hide old messages
	for(int i = 0; i < NUM_MSG_STRINGS; i++){
		if(timers[i] < ofGetElapsedTimef()){
			msg_strings[i] = "";
		}
	}

	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		
       cout << "sample 2 reverb =" << audioSample1->bReverb << endl;
        
		// check for Varp9 message
		if(m.getAddress() == "/pads1"){
			audioSample1->bReverb    = m.getArgAsInt32(0);
			audioSample1->bFilter    = m.getArgAsInt32(1);
			audioSample1->bPan       = m.getArgAsInt32(2);
			audioSample1->bFx        = m.getArgAsInt32(3);
		} else{
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for(int i = 0; i < m.getNumArgs(); i++){
				// get the argument type
				msg_string += m.getArgTypeName(i);
				msg_string += ":";
				// display the argument - make sure we get the right type
				if(m.getArgType(i) == OFXOSC_TYPE_INT32){
					msg_string += ofToString(m.getArgAsInt32(i));
				}
				else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
					msg_string += ofToString(m.getArgAsFloat(i));
				}
				else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
					msg_string += m.getArgAsString(i);
				}
				else{
					msg_string += "unknown";
				}
			}
			// add to the list of strings to display
			msg_strings[current_msg_string] = msg_string;
			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
			// clear the next line
			msg_strings[current_msg_string] = "";
		}
		
	}
	
}

//--------------------------------------------------------------
void oscReciever::draw(){
	
	string buf[4];
	buf[0] = "audioSample2->bReverb" + audioSample1->bReverb;
//	ofDrawBitmapString(buf[0], 10, 20);

	
}
