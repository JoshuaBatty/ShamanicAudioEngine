/*
 *  oscReciever.h
 *  oscReceiveExample
 *
 *  Created by Alice Hobday on 23/06/12.
 *  Copyright 2012 BMP. All rights reserved.
 *
 */

#include "ofxOsc.h"
#include "ofMain.h"
#include "audioSample.h"

// listen on port 9999
#define PORT 9999
#define NUM_MSG_STRINGS 20

class oscReciever {
public:
	
	void setup(AudioSampler *_audioSample1);
	void update();
	void draw();
	
	ofTrueTypeFont font;
	ofxOscReceiver receiver;
	
	int current_msg_string;
	string msg_strings[NUM_MSG_STRINGS];
	float timers[NUM_MSG_STRINGS];
    
    AudioSampler  *audioSample1;

};

