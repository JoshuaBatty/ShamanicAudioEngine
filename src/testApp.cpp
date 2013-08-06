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
    loadBox2X = 660;
    loadBox3X = 980;
    loadBox4X = 1300;
    
    loadBox1Y = 10;
    loadBox2Y = 10;
    loadBox3Y = 10;
    loadBox4Y = 10;
    
    audioTonic.setup();
    audioBinaural.setup();
    audioSample1.setup("shamanic_drum_short.wav");
    audioSample2.setup("icaros2.wav");
    audioSample3.setup("singing_bells.wav");
    audioSample4.setup("psychedelics.wav");
    soundStream.setup(2, 0, sampleRate, bufferSize, 4);

	soundStream.setOutput(this);
    
    mixer.addInputFrom(&audioTonic);
    mixer.addInputFrom(&audioBinaural);
    mixer.addInputFrom(&audioSample1);
    mixer.addInputFrom(&audioSample2);
    mixer.addInputFrom(&audioSample3);
    mixer.addInputFrom(&audioSample4);
    
    tweenSynth.setup(&audioBinaural, &audioTonic);
    tween1.setup(&audioSample1);
    tween2.setup(&audioSample2);
    tween3.setup(&audioSample3);
    tween4.setup(&audioSample4);
    
    gui.setup(&tween1, &tween2, &tween3, &tween4, &audioSample1, &audioSample2, &audioSample3, &audioSample4);
    guiBinaural.setup(&tweenSynth, &audioBinaural, &audioTonic);
    timeline.setup(&gui, &guiBinaural, &audioSample1, &audioSample2, &audioSample3, &audioSample4, &audioBinaural);
    

    //Shaders
	shader.load("shaders/strobe");
	shaderOptical.load("shaders/optical");
    
#ifdef _USE_MIDI
    mLivid.setup(&gui, &guiBinaural, &audioSample1, &audioSample2, &audioSample3, &audioSample4);
#endif
    
    osc.setup(&audioSample1, &audioSample2, &audioSample3, &audioSample4);
    
    motion.setup(&gui, &mLivid);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    motion.update();
    
    timeline.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    osc.update();
    
    //IF USE MIDI

    //Livid Stuff
    //Set volume for each sample
  
/*

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


 */



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

    tweenSynth.update();
    tween1.update();
    tween2.update();
    tween3.update();
    tween4.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofEnableAlphaBlending();
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
    
    shaderOptical.begin();
    shaderOptical.setUniform1f("iGlobalTime", ofGetElapsedTimef() );
    shaderOptical.setUniform1f("speed", audioBinaural.osc2Pitch * 6.0 );
    shaderOptical.setUniform2f("iResolution", ofGetWidth() , ofGetHeight() ) ;
    shaderOptical.setUniform1f("direction", ofMap(mouseY,0,ofGetHeight(),0.0,3.0) );

    ofPushMatrix();
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    shaderOptical.end();

    ofDisableAlphaBlending();
 //   audioSample1.draw(30,loadBox2X);
 //   audioSample2.draw(30,650);
 //   audioSample3.draw(30,700);
 //   audioSample4.draw(30,750);
    
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
    
    if(mouseY>=loadBox2Y && mouseY<=loadBox2Y+30 && mouseX>=loadBox2X && mouseX<=loadBox2X+300){
        ofSetColor(255,0,0);
        ofRect(loadBox2X,loadBox2Y,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(loadBox2X,loadBox2Y,300,30);
    }
    
    if(mouseY>=loadBox3Y && mouseY<=loadBox3Y+30 && mouseX>=loadBox3X && mouseX<=loadBox3X+300){
        ofSetColor(255,0,0);
        ofRect(loadBox3X,loadBox3Y,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(loadBox3X,loadBox3Y,300,30);
    }
    
    if(mouseY>=loadBox4Y && mouseY<=loadBox4Y+30 && mouseX>=loadBox4X && mouseX<=loadBox4X+300){
        ofSetColor(255,0,0);
        ofRect(loadBox4X,loadBox4Y,300,30);
    } else {
        ofSetColor(255,255,0);
        ofRect(loadBox4X,loadBox4Y,300,30);
    }
        
    ofSetColor(255);
    ofDrawBitmapString(ofToString("Drag n Drop Sample"), loadBox1X+80, loadBox1Y+20);
    ofDrawBitmapString(ofToString("Drag n Drop Sample"), loadBox2X+80, loadBox2Y+20);
    ofDrawBitmapString(ofToString("Drag n Drop Sample"), loadBox3X+80, loadBox3Y+20);
    ofDrawBitmapString(ofToString("Drag n Drop Sample"), loadBox4X+80, loadBox4Y+20);
    
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
        gui.gui3->toggleVisible();
        gui.gui4->toggleVisible();
        gui.gui5->toggleVisible();
        gui.gui6->toggleVisible();
    }if (key == 'p') {
        gui.gui7->toggleVisible();
        guiBinaural.guiPresets->toggleVisible();
    }
    
    if(key == ','){
        timeline.synthTimeline.togglePlay();
    }
    
    if(key == '1'){
        audioSample1.current = 0;
        audioSample2.current = 0;
        audioSample3.current = 0;
        audioSample4.current = 0;
    } else if(key == '2'){
        audioSample1.current = 1;
        audioSample2.current = 1;
        audioSample3.current = 1;
        audioSample4.current = 1;
    } else if(key == '3'){
        audioSample1.current = 2;
        audioSample2.current = 2;
        audioSample3.current = 2;
        audioSample4.current = 2;
    } else if(key == '4'){
        audioSample1.current = 3;
        audioSample2.current = 3;
        audioSample3.current = 3;
        audioSample4.current = 3;
    } else if(key == '5'){
        audioSample1.current = 4;
        audioSample2.current = 4;
        audioSample3.current = 4;
        audioSample4.current = 4;
    }

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){

    cout << "file name = " << info.files[0] << endl;

    string file = info.files[0];
    
    dragPt = info.position;

  //  audioSample1.clear1();
 //   audioSample1.load1(file);
    
    if(dragPt.y>=loadBox1Y && dragPt.y<=590 && dragPt.x>=loadBox1X && dragPt.x<=loadBox1X+300){
        audioSample1.clear1();
        audioSample1.load1(file);
    }
    if(dragPt.y>=loadBox2Y && dragPt.y<=630 && dragPt.x>=loadBox2X && dragPt.x<=loadBox2X+300){
        audioSample2.clear1();
        audioSample2.load1(file);
    }
    if(dragPt.y>=loadBox3Y && dragPt.y<=670 && dragPt.x>=loadBox3X && dragPt.x<=loadBox3X+300){
        audioSample3.clear1();
        audioSample3.load1(file);
    }
    if(dragPt.y>=loadBox4Y && dragPt.y<=710 && dragPt.x>=loadBox4X && dragPt.x<=loadBox4X+300){
        audioSample4.clear1();
        audioSample4.load1(file);
    }
}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    mixer.audioRequested(output, bufferSize, nChannels);
}
