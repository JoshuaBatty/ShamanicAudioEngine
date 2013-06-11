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
    
    audioBinaural.setup();
    audioSample1.setup("shamanic_drum_short.wav");
    audioSample2.setup("icaros2.wav");
    audioSample3.setup("singing_bells.wav");
    audioSample4.setup("psychedelics.wav");
    soundStream.setup(2, 0, sampleRate, bufferSize, 4);
	soundStream.setOutput(this);
    
    mixer.addInputFrom(&audioBinaural);
    mixer.addInputFrom(&audioSample1);
    mixer.addInputFrom(&audioSample2);
    mixer.addInputFrom(&audioSample3);
    mixer.addInputFrom(&audioSample4);
    
    tween1.setup(&audioSample1);
    tween2.setup(&audioSample2);
    tween3.setup(&audioSample3);
    tween4.setup(&audioSample4);
    
    gui.setup(&tween1, &tween2, &tween3, &tween4, &audioBinaural, &audioSample1, &audioSample2, &audioSample3, &audioSample4);
    
    timeline.setup(&gui, &audioSample1, &audioSample2, &audioSample3, &audioSample4, &audioBinaural);
    
    //Shaders
	shader.load("shaders/strobe");

#ifdef _USE_MIDI
    mLivid.setup();
#endif
    
    osc.setup(&audioSample1, &audioSample2, &audioSample3, &audioSample4);
    
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
    audioSample2.volume = ofMap(mLivid.sliders[5],0,127,0.0,0.99);
    audioSample3.volume = ofMap(mLivid.sliders[6],0,127,0.0,0.99);
    audioSample4.volume = ofMap(mLivid.sliders[7],0,127,0.0,0.99);
    
    //Set scrub position for each sample
    //   audioSample1.setPosition(ofMap(mLivid.sliders[4],0,127,0.0,0.99));
    //   audioSample2.setPosition(ofMap(mLivid.sliders[5],0,127,0.0,0.99));
    //   audioSample3.setPosition(ofMap(mLivid.sliders[6],0,127,0.0,0.99));
    
    audioSample1.updateParams(ofMap(mLivid.knobsB1[0],0,127,0.0,8.0), ofMap(mLivid.sliders[0],0,127,-2.0,2.0), ofMap(mLivid.knobsB1[1],0,127,0.025,0.49), ofMap(mLivid.knobsB1[2],0,127,1,6), ofMap(mLivid.knobsB3[0],0,127,0.0,0.5), ofMap(mLivid.knobsB3[1],0,127,0.0,0.5));
    audioSample2.updateParams(ofMap(mLivid.knobsB1[3],0,127,0.0,8.0), ofMap(mLivid.sliders[1],0,127,-2.0,2.0), ofMap(mLivid.knobsB1[4],0,127,0.025,0.49), ofMap(mLivid.knobsB1[5],0,127,1,6), ofMap(mLivid.knobsB3[3],0,127,0.0,0.5), ofMap(mLivid.knobsB3[4],0,127,0.0,0.5));
    audioSample3.updateParams(ofMap(mLivid.knobsB1[6],0,127,0.0,8.0), ofMap(mLivid.sliders[2],0,127,-2.0,2.0), ofMap(mLivid.knobsB1[7],0,127,0.025,0.49), ofMap(mLivid.knobsB1[8],0,127,1,6), ofMap(mLivid.knobsB3[6],0,127,0.0,0.5), ofMap(mLivid.knobsB3[7],0,127,0.0,0.5));
    audioSample4.updateParams(ofMap(mLivid.knobsB1[9],0,127,0.0,8.0), ofMap(mLivid.sliders[3],0,127,-2.0,2.0), ofMap(mLivid.knobsB1[10],0,127,0.025,0.49), ofMap(mLivid.knobsB1[11],0,127,1,6), ofMap(mLivid.knobsB3[9],0,127,0.0,0.5), ofMap(mLivid.knobsB3[10],0,127,0.0,0.5));
    
    audioBinaural.updateParams(ofMap(mLivid.knobsB3[2],0,127,0.0,0.99), ofMap(mLivid.knobsB3[5],0,127,30.0,150.0), ofMap(mLivid.knobsB3[8],0,127,0.0,14.0));
    
    //Panning
    if(audioSample1.bPan==true){
        audioSample1.setPanning(ofMap(mLivid.knobsB2[0],0,127,0.0,1.0), ofMap(mLivid.knobsB2[1],0,127,0.0,1.0), ofMap(mLivid.knobsB2[2],0,127,0.0,1.0));
    } else {
        //        audioSample1.setPanning(audioSample1.pan, audioSample1.panLfoSpeed, audioSample1.panLfoAmp);
    }
    if(audioSample2.bPan==true){
        audioSample2.setPanning(ofMap(mLivid.knobsB2[3],0,127,0.0,1.0), ofMap(mLivid.knobsB2[4],0,127,0.0,1.0), ofMap(mLivid.knobsB2[5],0,127,0.0,1.0));
    } else {
        //        audioSample2.setPanning(audioSample2.pan, audioSample2.panLfoSpeed, audioSample2.panLfoAmp);
    }
    if(audioSample3.bPan==true){
        audioSample3.setPanning(ofMap(mLivid.knobsB2[6],0,127,0.0,1.0), ofMap(mLivid.knobsB2[7],0,127,0.0,1.0), ofMap(mLivid.knobsB2[8],0,127,0.0,1.0));
    } else {
        //        audioSample3.setPanning(audioSample3.pan, audioSample3.panLfoSpeed, audioSample3.panLfoAmp);
    }
    if(audioSample4.bPan==true){
        audioSample4.setPanning(ofMap(mLivid.knobsB2[9],0,127,0.0,1.0), ofMap(mLivid.knobsB2[10],0,127,0.0,1.0), ofMap(mLivid.knobsB2[11],0,127,0.0,1.0));
    } else {
        //        audioSample4.setPanning(audioSample4.pan, audioSample4.panLfoSpeed, audioSample4.panLfoAmp);
    }
    
    //Filter
    if(audioSample1.bFilter==true){
        audioSample1.setFilter(ofMap(mLivid.knobsB2[0],0,127,10.0,10000.0), ofMap(mLivid.knobsB2[1],0,127,0.0,200.0), ofMap(mLivid.knobsB2[2],0,127,0.0,3000.0));
    } else {
        //        audioSample1.setFilter(audioSample1.cutoff1, audioSample1.lfoSpeed1, audioSample1.lfoAmp1);
    }
    if(audioSample2.bFilter==true){
        audioSample2.setFilter(ofMap(mLivid.knobsB2[3],0,127,10.0,10000.0), ofMap(mLivid.knobsB2[4],0,127,0.0,200.0), ofMap(mLivid.knobsB2[5],0,127,0.0,3000.0));
    } else {
        //        audioSample2.setFilter(audioSample2.cutoff1, audioSample2.lfoSpeed1, audioSample2.lfoAmp1);
    }
    if(audioSample3.bFilter==true){
        audioSample3.setFilter(ofMap(mLivid.knobsB2[6],0,127,10.0,10000.0), ofMap(mLivid.knobsB2[7],0,127,0.0,200.0), ofMap(mLivid.knobsB2[8],0,127,0.0,3000.0));
    } else {
        //        audioSample3.setFilter(audioSample3.cutoff1, audioSample3.lfoSpeed1, audioSample3.lfoAmp1);
    }
    if(audioSample4.bFilter==true){
        audioSample4.setFilter(ofMap(mLivid.knobsB2[9],0,127,10.0,10000.0), ofMap(mLivid.knobsB2[10],0,127,0.0,200.0), ofMap(mLivid.knobsB2[11],0,127,0.0,3000.0));
    } else {
        //        audioSample4.setFilter(audioSample4.cutoff1, audioSample4.lfoSpeed1, audioSample4.lfoAmp1);
    }
    
    //Reverb
    if(audioSample1.bReverb==true){
        audioSample1.reverb(ofMap(mLivid.knobsB2[0],0,127,0.0,1.0), ofMap(mLivid.knobsB2[1],0,127,0.0,1.0));
    } else {
        //        audioSample1.reverb(audioSample1.reverbDryWet, audioSample1.reverbSize);
    }
    if(audioSample2.bReverb==true){
        audioSample2.reverb(ofMap(mLivid.knobsB2[3],0,127,0.0,1.0), ofMap(mLivid.knobsB2[4],0,127,0.0,1.0));
    } else {
        //        audioSample2.reverb(audioSample2.reverbDryWet, audioSample2.reverbSize);
    }
    if(audioSample3.bReverb==true){
        audioSample3.reverb(ofMap(mLivid.knobsB2[6],0,127,0.0,1.0), ofMap(mLivid.knobsB2[7],0,127,0.0,1.0));
    } else {
        //        audioSample3.reverb(audioSample3.reverbDryWet, audioSample3.reverbSize);
    }
    if(audioSample4.bReverb==true){
        audioSample4.reverb(ofMap(mLivid.knobsB2[9],0,127,0.0,1.0), ofMap(mLivid.knobsB2[10],0,127,0.0,1.0));
    } else {
        //        audioSample4.reverb(audioSample4.reverbDryWet, audioSample4.reverbSize);
    }
    
    //FX
    if(audioSample1.bFx==true){
        audioSample1.delay(ofMap(mLivid.knobsB2[0],0,127,10.0,10000.0),ofMap(mLivid.knobsB2[1],0,127,0.0,0.95));
        audioSample1.decimate(audioSample1.bits, ofMap(mLivid.knobsB2[2],0,127,1.0,0.0));
    } else {
        //        audioSample1.delay(audioSample1.delayTime1,audioSample1.delayFeedback1);
        //        audioSample1.decimate(audioSample1.bits, audioSample1.rate);
    }
    if(audioSample2.bFx==true){
        audioSample2.delay(ofMap(mLivid.knobsB2[3],0,127,10.0,10000.0),ofMap(mLivid.knobsB2[4],0,127,0.0,0.95));
        audioSample2.decimate(audioSample2.bits, ofMap(mLivid.knobsB2[5],0,127,1.0,0.0));
    } else {
        //        audioSample2.delay(audioSample2.delayTime1,audioSample2.delayFeedback1);
        //        audioSample2.decimate(audioSample2.bits, audioSample2.rate);
    }
    if(audioSample3.bFx==true){
        audioSample3.delay(ofMap(mLivid.knobsB2[6],0,127,10.0,10000.0),ofMap(mLivid.knobsB2[7],0,127,0.0,0.95));
        audioSample3.decimate(audioSample3.bits, ofMap(mLivid.knobsB2[8],0,127,1.0,0.0));
    } else {
        //        audioSample3.delay(audioSample3.delayTime1,audioSample3.delayFeedback1);
        //        audioSample3.decimate(audioSample3.bits, audioSample3.rate);
    }
    if(audioSample4.bFx==true){
        audioSample4.delay(ofMap(mLivid.knobsB2[9],0,127,10.0,10000.0),ofMap(mLivid.knobsB2[10],0,127,0.0,0.95));
        audioSample4.decimate(audioSample4.bits, ofMap(mLivid.knobsB2[11],0,127,1.0,0.0));
    } else {
        //        audioSample4.delay(audioSample4.delayTime1,audioSample4.delayFeedback1);
        //        audioSample4.decimate(audioSample4.bits, audioSample4.rate);
    }

#else
    // ELSE USE GUI
    //Panning
        audioSample1.setPanning(audioSample1.pan, audioSample1.panLfoSpeed, audioSample1.panLfoAmp);
        audioSample2.setPanning(audioSample2.pan, audioSample2.panLfoSpeed, audioSample2.panLfoAmp);
        audioSample3.setPanning(audioSample3.pan, audioSample3.panLfoSpeed, audioSample3.panLfoAmp);
        audioSample4.setPanning(audioSample4.pan, audioSample4.panLfoSpeed, audioSample4.panLfoAmp);
    
    //Filter
        audioSample1.setFilter(audioSample1.cutoff1, audioSample1.lfoSpeed1, audioSample1.lfoAmp1);
        audioSample2.setFilter(audioSample2.cutoff1, audioSample2.lfoSpeed1, audioSample2.lfoAmp1);
        audioSample3.setFilter(audioSample3.cutoff1, audioSample3.lfoSpeed1, audioSample3.lfoAmp1);
        audioSample4.setFilter(audioSample4.cutoff1, audioSample4.lfoSpeed1, audioSample4.lfoAmp1);
    
    //Reverb
        audioSample1.reverb(audioSample1.reverbDryWet, audioSample1.reverbSize);
        audioSample2.reverb(audioSample2.reverbDryWet, audioSample2.reverbSize);
        audioSample3.reverb(audioSample3.reverbDryWet, audioSample3.reverbSize);
        audioSample4.reverb(audioSample4.reverbDryWet, audioSample4.reverbSize);

    //FX
        audioSample1.delay(audioSample1.delayTime1,audioSample1.delayFeedback1);
        audioSample1.decimate(audioSample1.bits, audioSample1.rate);
        audioSample2.delay(audioSample2.delayTime1,audioSample2.delayFeedback1);
        audioSample2.decimate(audioSample2.bits, audioSample2.rate);
        audioSample3.delay(audioSample3.delayTime1,audioSample3.delayFeedback1);
        audioSample3.decimate(audioSample3.bits, audioSample3.rate);
        audioSample4.delay(audioSample4.delayTime1,audioSample4.delayFeedback1);
        audioSample4.decimate(audioSample4.bits, audioSample4.rate);
#endif
    
    tween1.update();
    tween2.update();
    tween3.update();
    tween4.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor( 122 , 200 , 255 ) ;
	ofFill();
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef()*(audioBinaural.osc2Pitch * 6.0) );
    shader.setUniform2f("resolution", ofGetWidth() , ofGetHeight() ) ;
    shader.setUniform2f("mouse", 0.5, mouseY/ofGetHeight());
    shader.setUniform1f("direction", ofMap(mouseY,0,ofGetHeight(),0.0,3.0) );

    ofPushMatrix();
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    shader.end();
    
 //   audioSample1.draw(30,600);
 //   audioSample2.draw(30,650);
 //   audioSample3.draw(30,700);
 //   audioSample4.draw(30,750);
    
    osc.draw();
    
    gui.drawData();
    timeline.draw();
    
//    ofNoFill();
    if(mouseY>=560 && mouseY<=590 && mouseX>=10 && mouseX<=310){
        ofSetColor(255,0,0);
        ofRect(10,560,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(10,560,300,30);
    }
    
    if(mouseY>=600 && mouseY<=630 && mouseX>=10 && mouseX<=310){
        ofSetColor(255,0,0);
        ofRect(10,600,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(10,600,300,30);
    }
    
    if(mouseY>=640 && mouseY<=670 && mouseX>=10 && mouseX<=310){
        ofSetColor(255,0,0);
        ofRect(10,640,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(10,640,300,30);
    }
    
    if(mouseY>=680 && mouseY<=710 && mouseX>=10 && mouseX<=310){
        ofSetColor(255,0,0);
        ofRect(10,680,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(10,680,300,30);
    }
    
    cout << " mouseY = " << mouseY << endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

 //   tween1.trigger();
 //   tween2.trigger();
 //   tween3.trigger();
 //   tween4.trigger();
    
    gui.gui1->toggleVisible();
    gui.gui2->toggleVisible();
    gui.gui3->toggleVisible();
    gui.gui4->toggleVisible();
    gui.gui5->toggleVisible();
    gui.gui6->toggleVisible();


}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){

    cout << "file name = " << info.files[0] << endl;

    string file = info.files[0];
    
    dragPt = info.position;

  //  audioSample1.clear1();
 //   audioSample1.load1(file);
    
    if(dragPt.y>=560 && dragPt.y<=590 && dragPt.x>=10 && dragPt.x<=310){
        audioSample1.clear1();
        audioSample1.load1(file);
    }
    if(dragPt.y>=600 && dragPt.y<=630 && dragPt.x>=10 && dragPt.x<=310){
        audioSample2.clear1();
        audioSample2.load1(file);
    }
    if(dragPt.y>=640 && dragPt.y<=670 && dragPt.x>=10 && dragPt.x<=310){
        audioSample3.clear1();
        audioSample3.load1(file);
    }
    if(dragPt.y>=680 && dragPt.y<=710 && dragPt.x>=10 && dragPt.x<=310){
        audioSample4.clear1();
        audioSample4.load1(file);
    }
}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    mixer.audioRequested(output, bufferSize, nChannels);
}
