#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
	ofEnableAlphaBlending();
    	
    //Setup audio stuff
    int bufferSize		= 512;
	int sampleRate 		= 44100;
    
    loadBox1X = 340;
    loadBox1Y = 10;
    
    audioSample1.setup("shamanic_drum_short.wav");
    soundStream.setup(2, 0, sampleRate, bufferSize, 4);
	soundStream.setOutput(this);
    
    //Record Audio output
    myWavWriter.setFormat(2, sampleRate, 16);
	bIsRecording = false;
    
    mixer.addInputFrom(&audioSample1);
    tween1.setup(&audioSample1);

    gui.setup(&tween1, &audioSample1);
    
    timeline.setup(&gui, &audioSample1);
    
    //Shaders
	shader.load("shaders/strobe");

#ifdef _USE_MIDI
    mLivid.setup();
#endif
    
    osc.setup(&audioSample1);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    timeline.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    osc.update();
    
    //IF USE MIDI
#ifdef _USE_MIDI
    //Livid Stuff
    //Set volume for each sample
    mLivid.update();
    
    audioSample1.volume = ofMap(mLivid.sliders[4],0,127,0.0,0.99);

    audioSample1.updateParams(ofMap(mLivid.knobsB1[0],0,127,0.0,8.0), ofMap(mLivid.sliders[0],0,127,-2.0,2.0), ofMap(mLivid.knobsB1[1],0,127,0.025,0.49), ofMap(mLivid.knobsB1[2],0,127,1,6), ofMap(mLivid.knobsB3[0],0,127,0.0,0.5), ofMap(mLivid.knobsB3[1],0,127,0.0,0.5));

    
    //Panning
    if(audioSample1.bPan==true){
        audioSample1.setPanning(ofMap(mLivid.knobsB2[0],0,127,0.0,1.0), ofMap(mLivid.knobsB2[1],0,127,0.0,1.0), ofMap(mLivid.knobsB2[2],0,127,0.0,1.0));
    } else {
        //        audioSample1.setPanning(audioSample1.pan, audioSample1.panLfoSpeed, audioSample1.panLfoAmp);
    }
    
    //Filter
    if(audioSample1.bFilter==true){
        audioSample1.setFilter(ofMap(mLivid.knobsB2[0],0,127,10.0,10000.0), ofMap(mLivid.knobsB2[1],0,127,0.0,200.0), ofMap(mLivid.knobsB2[2],0,127,0.0,3000.0));
    } else {
        //        audioSample1.setFilter(audioSample1.cutoff1, audioSample1.lfoSpeed1, audioSample1.lfoAmp1);
    }
    
    //Reverb
    if(audioSample1.bReverb==true){
        audioSample1.reverb(ofMap(mLivid.knobsB2[0],0,127,0.0,1.0), ofMap(mLivid.knobsB2[1],0,127,0.0,1.0));
    } else {
        //        audioSample1.reverb(audioSample1.reverbDryWet, audioSample1.reverbSize);
    }
    
    //FX
    if(audioSample1.bFx==true){
        audioSample1.delay(ofMap(mLivid.knobsB2[0],0,127,10.0,10000.0),ofMap(mLivid.knobsB2[1],0,127,0.0,0.95));
        audioSample1.decimate(audioSample1.bits, ofMap(mLivid.knobsB2[2],0,127,1.0,0.0));
    } else {
        //        audioSample1.delay(audioSample1.delayTime1,audioSample1.delayFeedback1);
        //        audioSample1.decimate(audioSample1.bits, audioSample1.rate);
    }

#else
    // ELSE USE GUI
    //Panning
        audioSample1.setPanning(audioSample1.pan, audioSample1.panLfoSpeed, audioSample1.panLfoAmp);

    //Filter
        audioSample1.setFilter(audioSample1.cutoff1, audioSample1.lfoSpeed1, audioSample1.lfoAmp1);

    //Reverb
        audioSample1.reverb(audioSample1.reverbDryWet, audioSample1.reverbSize);

    //FX
        audioSample1.delay(audioSample1.delayTime1,audioSample1.delayFeedback1);
        audioSample1.decimate(audioSample1.bits, audioSample1.rate);

#endif
    
    tween1.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor( 122 , 200 , 255 ) ;
	ofFill();
    
    shader.begin();
    shader.setUniform1f("time", 0 );
//    shader.setUniform1f("time", ofGetElapsedTimef()*(0.04 * 6.0) );
    shader.setUniform2f("resolution", ofGetWidth() , ofGetHeight() ) ;
    shader.setUniform2f("mouse", 0.5, mouseY/ofGetHeight());
    shader.setUniform1f("direction", ofMap(mouseY,0,ofGetHeight(),0.0,3.0) );

    ofPushMatrix();
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    shader.end();
    
    osc.draw();
    
    gui.drawData();
    timeline.draw();
    
    ofNoFill();
    if(mouseY>=loadBox1Y && mouseY<=loadBox1Y+30 && mouseX>=loadBox1X && mouseX<=loadBox1X+300){
        ofSetColor(255,0,0);
        ofRect(loadBox1X,loadBox1Y,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(loadBox1X,loadBox1Y,300,30);
    }

    
    ofSetColor(255);
    ofDrawBitmapString(ofToString("Drag n Drop Sample"), loadBox1X+80, loadBox1Y+20);
    
    cout << " mouseY = " << mouseY << endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

 //   tween1.trigger();
 //   tween2.trigger();
 //   tween3.trigger();
 //   tween4.trigger();
    
    if(key == 'h'){
        gui.gui1->toggleVisible();
        gui.gui2->toggleVisible();
        gui.gui6->toggleVisible();
    }
    
    if(key == 'r'){
		bIsRecording =! bIsRecording;
		if(bIsRecording){
			bool b = myWavWriter.open(ofToDataPath("test.wav"), WAVFILE_WRITE);
			cout<<"startRecording open "<<b<<endl;
		}else{
			printf("stop recording!\n");
			myWavWriter.close();
		}
	}


}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){

    cout << "file name = " << info.files[0] << endl;

    string file = info.files[0];
    
    dragPt = info.position;

    if(dragPt.y>=loadBox1Y && dragPt.y<=590 && dragPt.x>=loadBox1X && dragPt.x<=loadBox1X+300){
        audioSample1.clear1();
        audioSample1.load1(file);
    }
}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    mixer.audioRequested(output, bufferSize, nChannels);
    
    if(bIsRecording){
		myWavWriter.write(output, bufferSize*nChannels);
	}
}
