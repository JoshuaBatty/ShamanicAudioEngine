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

    
    audioTonic.setup();
    audioBinaural.setup();
    audioSample1.setup("shamanic_drum_short.wav");

    
    mixer.addInputFrom(&audioTonic);
    mixer.addInputFrom(&audioBinaural);
    mixer.addInputFrom(&audioSample1);
    
    tweenSynth.setup(&audioBinaural, &audioTonic);
    tween1.setup(&audioSample1);
    
    gui.setup(&tween1,&audioSample1);
    guiBinaural.setup(&tweenSynth, &audioBinaural, &audioTonic);
    timeline.setup(&gui, &guiBinaural, &audioSample1, &audioBinaural);
    
    soundStream.setup(2, 0, sampleRate, bufferSize, 4);
    
	soundStream.setOutput(this);

#ifdef _USE_MIDI
    mLivid.setup(&gui, &guiBinaural, &audioSample1);
#endif
    
    osc.setup(&audioSample1);
    
    motion.setup(&gui, &mLivid);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //motion.update();
    
    timeline.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    osc.update();

    //Panning
        audioSample1.setPanning(audioSample1.pan, audioSample1.panLfoSpeed, audioSample1.panLfoAmp);

    //Filter
        audioSample1.setFilter(audioSample1.cutoff1, audioSample1.lfoSpeed1, audioSample1.lfoAmp1);

    //Reverb
        audioSample1.reverb(audioSample1.reverbDryWet, audioSample1.reverbSize);

    //FX
        audioSample1.delay(audioSample1.delayTime1,audioSample1.delayFeedback1);
        audioSample1.decimate(audioSample1.bits, audioSample1.rate);

    tweenSynth.update();
    tween1.update();


}

//--------------------------------------------------------------
void testApp::draw(){
	    
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
 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

    if(key == 'h'){
        gui.gui1->toggleVisible();
        gui.gui2->toggleVisible();
        gui.gui7->toggleVisible();
        guiBinaural.guiBinaural->toggleVisible();
        guiBinaural.guiTonic->toggleVisible();
        guiBinaural.guiPresets->toggleVisible();

        timeline.hide();
        timeline.synthTimeline.hide();
    }if (key == 'p') {
        gui.gui7->toggleVisible();
        guiBinaural.guiPresets->toggleVisible();
    }
    
    if(key == ','){
        timeline.synthTimeline.togglePlay();
    }
    
    if(key == '1'){
        audioSample1.current = 0;
    } else if(key == '2'){
        audioSample1.current = 1;
    } else if(key == '3'){
        audioSample1.current = 2;
    } else if(key == '4'){
        audioSample1.current = 3;
    } else if(key == '5'){
        audioSample1.current = 4;
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
}
