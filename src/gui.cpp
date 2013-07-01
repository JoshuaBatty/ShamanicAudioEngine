//
//  gui.cpp
//  emptyExample
//
//  Created by Joshua Batty on 22/02/13.
//
//

#include "gui.h"

//-------------------------------------------------------------
Gui::~Gui() {
    
}

//--------------------------------------------------------------
void Gui::setup(Tween *_tween1, AudioSampler *_audioSample1)
{
    curPreset = 1;
    guiOffset = 50;
    int guiWidth = 15;
    int guiCanvasLength = 690;
    
    tween1 = _tween1;
    audioSample1 = _audioSample1;

    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    
    //VOLUME
    gui1 = new ofxUICanvas(0,180,length+xInit*2.0,330);
    gui1->addWidgetDown(new ofxUILabel("VOLUME", OFX_UI_FONT_MEDIUM));
    gui1->addSlider("Sample1", 0.0, 1.0, audioSample1->volume, 40, 150);
    gui1->addSpacer(length, dim/5);
    
    gui1->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,45));
    gui1->setWidgetColor(OFX_UI_WIDGET_COLOR_OUTLINE, ofColor(255,0,0,100));
    gui1->setWidgetColor(OFX_UI_WIDGET_COLOR_OUTLINE_HIGHLIGHT, ofColor(10,255,200));
    gui1->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL, ofColor(255));
    gui1->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL_HIGHLIGHT, ofColor(255,10,100, 255));
    
    // DRUM
    gui2 = new ofxUICanvas(10+(length+xInit),guiOffset,length+xInit*2.0,guiCanvasLength);
    gui2->addWidgetDown(new ofxUILabel("SAMPLE 1", OFX_UI_FONT_MEDIUM));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("GRANULAR");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH1"));
    gui2->addWidgetRight(new ofxUISlider("pitch1", 0.0, 8.0, audioSample1->pitch1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED1"));
    gui2->addWidgetRight(new ofxUISlider("speed1", -2.0, 2.0, audioSample1->speed1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE1"));
    gui2->addWidgetRight(new ofxUISlider("grainLength1", 0.025, 0.49, audioSample1->grainLength1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS1"));
    gui2->addWidgetRight(new ofxUISlider("overlaps1", 1, 6, audioSample1->overlaps1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH1"));
    gui2->addWidgetRight(new ofxUISlider("randomGrainPitch1", 0.0, 0.50, audioSample1->randomGrainPitch1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE1"));
    gui2->addWidgetRight(new ofxUISlider("randomGrainSize1", 0.0, 0.05, audioSample1->randomGrainSize1, 270, guiWidth));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("FILTER");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF1"));
    gui2->addWidgetRight(new ofxUISlider("Cutoff1", 0.0, 10000.0, audioSample1->cutoff1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO1"));
    gui2->addWidgetRight(new ofxUISlider("LfoSpeed1", 0.0, 200.0, audioSample1->lfoSpeed1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUISlider("LfoAmp1", 0.0, 3000.0, audioSample1->lfoAmp1, 270, guiWidth));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("DELAY");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME1"));
    gui2->addWidgetRight(new ofxUISlider("DelayTime1", 10.0, 10000.0, audioSample1->delayTime1, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK1"));
    gui2->addWidgetRight(new ofxUISlider("DelayFeedback1", 0.0, 0.95, audioSample1->delayFeedback1, 270, guiWidth));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("CRUSH");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS1"));
    gui2->addWidgetRight(new ofxUISlider("Bits1", 32.0, 0.0, audioSample1->bits, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT1"));
    gui2->addWidgetRight(new ofxUISlider("Rate1", 1.0, 0.0, audioSample1->rate, 270, guiWidth));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("REVERB");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY1"));
    gui2->addWidgetRight(new ofxUISlider("ReverbSize1", 0.0, 1.0, audioSample1->reverbSize, 270, guiWidth));
//    gui2->addWidgetRight(new ofxUISlider("ReverbDamp1", 0.0, 1.0, audioSample1->reverbDamp, 270, guiWidth));
//    gui2->addWidgetRight(new ofxUISlider("ReverbWidth1", 0.0, 1.0, audioSample1->reverbWidth, 270, guiWidth));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET1"));
    gui2->addWidgetRight(new ofxUISlider("ReverbDryWet1", 0.0, 1.0, audioSample1->reverbDryWet, 270, guiWidth));
    gui2->addSpacer(length, dim/5);
    
    gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,45));
    gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_OUTLINE, ofColor(255,0,0,100));
    gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_OUTLINE_HIGHLIGHT, ofColor(10,255,200));
    gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL, ofColor(255));
    gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL_HIGHLIGHT, ofColor(255,10,100, 255));
    
    ////AUDIO RECORDING
    gui6 = new ofxUICanvas(0,380,length+xInit*2.0,guiCanvasLength-380);
   // gui6->addWidgetDown(new ofxUILabel("RECORD OUTPUT", OFX_UI_FONT_MEDIUM))
    gui6->addWidgetDown(new ofxUILabel("FILE NAME =", OFX_UI_FONT_MEDIUM));
    gui6->addWidgetRight(new ofxUITextInput("TEXT FILE NAME", "", 195));//->setAutoClear(false);
    gui6->addLabelToggle("RECORD", false, length-xInit);
    gui6->addSpacer(length, dim/5);
    
    //PRESETS
    gui7 = new ofxUICanvas(0,440,length+xInit*2.0,guiCanvasLength-440);
    gui7->addWidgetDown(new ofxUILabel("PRESETS", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetDown(new ofxUISpacer(length, 2));
    gui7->addLabelButton("SAVE PRESET", false, length-xInit);

    vector<string> hnames; hnames.push_back("1"); hnames.push_back("2"); hnames.push_back("3"); hnames.push_back("4"); hnames.push_back("5"); hnames.push_back("6"); hnames.push_back("7"); hnames.push_back("8");
    ofxUIRadio *radio = (ofxUIRadio *) gui7->addWidgetDown(new ofxUIRadio(dim, dim, "PRESET SELECT", hnames, OFX_UI_ORIENTATION_HORIZONTAL));
    radio->activateToggle("PRESETS");
    
    gui7->addWidgetDown(new ofxUILabel("DELAY", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetRight(new ofxUINumberDialer(0, 10000, 1000, 1, "TWEEN_DURATION", OFX_UI_FONT_MEDIUM));
    
  	gui7->addWidgetDown(new ofxUISpacer(length, 2));
    
    //Listener
    ofAddListener(gui1->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui2->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui6->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui7->newGUIEvent, this, &Gui::guiEvent);

    //Padding
    gui1->setDrawPadding(true);
    gui2->setDrawPadding(true);
    gui1->setDrawWidgetPadding(true);
    gui2->setDrawWidgetPadding(true);
    
    //XML preset loading
    gui1->loadSettings("GUI/guiSettingsVolume.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.xml");

    bUseSpeed1 = true;
    bUsePitch1 = true;
    bUseGrainSize1 = true;
    bUseOverlaps1 = true;
    bUseRandomGrainSize1 = true;
    bUseRandomGrainPitch1 = true;
    
    
    //DSP
    bUseCutoff1 = true;
    bUseCutoffLFO1 = true;
    bUseCrush1 = true;
    bUseBits1 = true;
    bUseDelayTime1 = true;
    bUseDelayFeedback1 = true;
    bUseReverbDecay1 = true;
    bUseReverbDryWet1 = true;
    
}


//--------------------------------------------------------------
void Gui::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
    //PRESET SAVING
    if(name == "SAVE PRESET" && curPreset == 1){
        gui1->saveSettings("GUI/guiSettingsVolume.1.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.1.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 2){
        gui1->saveSettings("GUI/guiSettingsVolume.2.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.2.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 3){
        gui1->saveSettings("GUI/guiSettingsVolume.3.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.3.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 4){
        gui1->saveSettings("GUI/guiSettingsVolume.4.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.4.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 5){
        gui1->saveSettings("GUI/guiSettingsVolume.5.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.5.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 6){
        gui1->saveSettings("GUI/guiSettingsVolume.6.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.6.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 7){
        gui1->saveSettings("GUI/guiSettingsVolume.7.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.7.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 8){
        gui1->saveSettings("GUI/guiSettingsVolume.8.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.8.xml");
    }


    else if(name == "1"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 1;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "2"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 2;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "3"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 3;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "4"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 4;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "5"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 5;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "6"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 6;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "7"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 7;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "8"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 8;
        tween1->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
        tween1->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    
    else if(name == "TWEEN_DURATION"){
        ofxUINumberDialer *number = (ofxUINumberDialer *) e.widget;
        tween1->duration = number->getValue();
    }
    
    //TIMELINE GUI TOGGLES
    else if(e.widget->getName() == "USESPEED1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseSpeed1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEPITCH1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUsePitch1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEGRAINSIZE1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseGrainSize1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEOVERLAPS1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseOverlaps1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USERANDOMGRAINSIZE1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainSize1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USERANDOMGRAINPITCH1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainPitch1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECUTOFF1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoff1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECUTOFFLFO1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoffLFO1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECRUSHAMOUNT1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCrush1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEBITS1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseBits1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEDELAYTIME1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayTime1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEDELAYFEEDBACK1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayFeedback1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEREVERBDECAY1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDecay1 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEREVERBDRYWET1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDryWet1 = toggle->getValue();
    }

    
    //DRUM
    //GRANULAR
    else if(name == "Sample1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->volume = slider->getScaledValue();
	}
    else if(name == "speed1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->speed1 = slider->getScaledValue();
	}
	else if(name == "pitch1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->pitch1 = slider->getScaledValue();
	}
    else if(name == "grainLength1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->grainLength1 = slider->getScaledValue();
	}
    else if(name == "overlaps1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->overlaps1 = slider->getScaledValue();
	}
    else if(name == "randomGrainPitch1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->randomGrainPitch1 = slider->getScaledValue();
	}
    else if(name == "randomGrainSize1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->randomGrainSize1 = slider->getScaledValue();
	}
    //DSP
    else if(name == "Cutoff1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->cutoff1 = slider->getScaledValue();
	}
    else if(name == "LfoSpeed1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->lfoSpeed1 = slider->getScaledValue();
	}
    else if(name == "LfoAmp1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->lfoAmp1 = slider->getScaledValue();
	}
    else if(name == "ReverbDryWet1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->reverbDryWet = slider->getScaledValue();
	}
    else if(name == "ReverbSize1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->reverbSize = slider->getScaledValue();
	}
    else if(name == "ReverbDamp1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->reverbDamp = slider->getScaledValue();
	}
    else if(name == "ReverbWidth1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->reverbWidth = slider->getScaledValue();
	}
    else if(name == "Bits1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->bits = slider->getScaledValue();
	}
    else if(name == "Rate1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->rate = slider->getScaledValue();
	}
    else if(name == "DelayTime1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->delayTime1 = slider->getScaledValue();
	}
    else if(name == "DelayFeedback1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->delayFeedback1 = slider->getScaledValue();
	}
    
}

//--------------------------------------------------------------
void Gui::drawData(){
    
    //Data vis
    //Page 1
    
     string buf[4];     
     buf[1] = "Speed 1: " + ofToString(audioSample1->speed1, 4);
     ofDrawBitmapString(buf[1], 1630, 140);
    
     buf[1] = "Pitch 1: " + ofToString(audioSample1->pitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 270);

     buf[1] = "GrainSize 1: " + ofToString(audioSample1->grainLength1, 4);
     ofDrawBitmapString(buf[1], 1630, 440);

     buf[1] = "GrainOverlaps 1: " + ofToString(audioSample1->overlaps1, 4);
     ofDrawBitmapString(buf[1], 1630, 570);

     buf[1] = "Ran Grain Size 1: " + ofToString(audioSample1->randomGrainSize1, 4);
     ofDrawBitmapString(buf[1], 1630, 700);

     buf[1] = "Ran Grain Pitch 1: " + ofToString(audioSample1->randomGrainPitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 830);

	//DSP PAGE 2
/*
    buf[0] = "GUI vs Timeline = ";
    ofDrawBitmapString(buf[0], 1430, 20);
    buf[1] = "Cutoff 1: " + ofToString(audioSample1->cutoff1, 4);
    ofDrawBitmapString(buf[1], 1430, guiWidth);
    buf[1] = "Cutoff 2: " + ofToString(audioSample2->cutoff1, 4);
    ofDrawBitmapString(buf[1], 1430, 70);
    buf[1] = "Cutoff 3: " + ofToString(audioSample3->cutoff1, 4);
    ofDrawBitmapString(buf[1], 1430, 100);
    
    buf[1] = "LFO Rate 1: " + ofToString(audioSample1->lfoSpeed1, 4);
    ofDrawBitmapString(buf[1], 1430, 1guiWidth);
    buf[1] = "LFO Rate 2: " + ofToString(audioSample2->lfoSpeed1, 4);
    ofDrawBitmapString(buf[1], 1430, 170);
    buf[1] = "LFO Rate 3: " + ofToString(audioSample3->lfoSpeed1, 4);
    ofDrawBitmapString(buf[1], 1430, 200);
    
    buf[1] = "LFO Amp 1: " + ofToString(audioSample1->lfoAmp1, 4);
    ofDrawBitmapString(buf[1], 1630, 1guiWidth);
    buf[1] = "LFO Amp 2: " + ofToString(audioSample2->lfoAmp1, 4);
    ofDrawBitmapString(buf[1], 1630, 170);
    buf[1] = "LFO Amp 3: " + ofToString(audioSample3->lfoAmp1, 4);
    ofDrawBitmapString(buf[1], 1630, 200);
    
    buf[1] = "Crush 1: " + ofToString(audioSample1->rate, 4);
    ofDrawBitmapString(buf[1], 1430, 2guiWidth);
    buf[1] = "Crush 2: " + ofToString(audioSample2->rate, 4);
    ofDrawBitmapString(buf[1], 1430, 270);
    buf[1] = "Crush 3: " + ofToString(audioSample3->rate, 4);
    ofDrawBitmapString(buf[1], 1430, 300);
    
    buf[1] = "Bits 1: " + ofToString(audioSample1->bits, 4);
    ofDrawBitmapString(buf[1], 1630, 2guiWidth);
    buf[1] = "Bits 2: " + ofToString(audioSample2->bits, 4);
    ofDrawBitmapString(buf[1], 1630, 270);
    buf[1] = "Bits 3: " + ofToString(audioSample3->bits, 4);
    ofDrawBitmapString(buf[1], 1630, 300);
    
    buf[1] = "DelayTime 1: " + ofToString(audioSample1->delayTime1, 4);
    ofDrawBitmapString(buf[1], 1430, 3guiWidth);
    buf[1] = "DelayTime 2: " + ofToString(audioSample2->delayTime1, 4);
    ofDrawBitmapString(buf[1], 1430, 370);
    buf[1] = "DelayTime 3: " + ofToString(audioSample3->delayTime1, 4);
    ofDrawBitmapString(buf[1], 1430, guiWidth0);
    
    buf[1] = "DelayFeedback 1: " + ofToString(audioSample1->delayFeedback1, 4);
    ofDrawBitmapString(buf[1], 1630, 3guiWidth);
    buf[1] = "DelayFeedback 2: " + ofToString(audioSample2->delayFeedback1, 4);
    ofDrawBitmapString(buf[1], 1630, 370);
    buf[1] = "DelayFeedback 3: " + ofToString(audioSample3->delayFeedback1, 4);
    ofDrawBitmapString(buf[1], 1630, guiWidth0);
    
    buf[1] = "ReverbDecay 1: " + ofToString(audioSample1->reverbSize, 4);
    ofDrawBitmapString(buf[1], 1430, 4guiWidth);
    buf[1] = "ReverbDecay 2: " + ofToString(audioSample2->reverbSize, 4);
    ofDrawBitmapString(buf[1], 1430, 470);
    buf[1] = "ReverbDecay 3: " + ofToString(audioSample3->reverbSize, 4);
    ofDrawBitmapString(buf[1], 1430, 500);
    
    buf[1] = "ReverbDryWet 1: " + ofToString(audioSample1->reverbDryWet, 4);
    ofDrawBitmapString(buf[1], 1630, 4guiWidth);
    buf[1] = "ReverbDryWet 2: " + ofToString(audioSample2->reverbDryWet, 4);
    ofDrawBitmapString(buf[1], 1630, 470);
    buf[1] = "ReverbDryWet 3: " + ofToString(audioSample3->reverbDryWet, 4);
    ofDrawBitmapString(buf[1], 1630, 500);
  */   

}
