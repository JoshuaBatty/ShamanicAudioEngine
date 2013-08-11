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
    delete gui1;
    delete gui2;
    delete gui7;
    
}

//--------------------------------------------------------------
void Gui::setup(Tween *_tween1, AudioSampler *_audioSample1)
{
    curPreset = 1;
    guiOffset = 50;
    int guiWidth = 15;
    int guiCanvasLength = 710;
    
    tween1 = _tween1;
    audioSample1 = _audioSample1;

    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    float tempGUIoffset = 180;
    
    //VOLUME
    gui1 = new ofxUICanvas(0,187+tempGUIoffset,length+xInit*2.0,330);
    gui1->addWidgetDown(new ofxUILabel("VOLUME", OFX_UI_FONT_MEDIUM));
    gui1->addSlider("Volume1", 0.0, 1.0, audioSample1->volume, 40, 150);
    gui1->addSpacer(length, dim/5);
    
    // DRUM
    gui2 = new ofxUICanvas(10+(length+xInit),guiOffset,length+xInit*2.0,guiCanvasLength);
    gui2->addWidgetDown(new ofxUILabel("SAMPLE 1", OFX_UI_FONT_MEDIUM));
    gui2->addSpacer(length, dim/5);

    gui2->addWidgetDown(new ofxUILabel("Grain Window -", OFX_UI_FONT_SMALL));
    matrix1 = (ofxUIToggleMatrix*) gui2->addWidgetRight(new ofxUIToggleMatrix(dim*1.5, dim*1.5, 1, 5, "GrainWindow1"));// "GRAIN WINDOW 1"));
    matrix1->setToggle(0, 0, true);
  	gui2->addWidgetDown(new ofxUISpacer(length, 2));
    
    gui2->addLabel("GRANULAR");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 8.0, audioSample1->pitch1, "slider.png", "pitch1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, -2.0, 2.0, audioSample1->speed1, "slider.png", "speed1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.025, 0.49, audioSample1->grainLength1, "slider.png", "grainLength1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1, 6, audioSample1->overlaps1, "slider.png", "overlaps1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.50, audioSample1->randomGrainPitch1, "slider.png", "randomGrainPitch1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.05, audioSample1->randomGrainSize1, "slider.png", "randomGrainSize1"));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("FILTER");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample1->cutoff1, "slider.png", "Cutoff1"));

    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 200.0, audioSample1->lfoSpeed1, "slider.png", "LfoSpeed1"));
    gui2->addWidgetDown(new ofxUIImageSlider(length-xInit, guiWidth, 0.0, 3000.0, audioSample1->lfoAmp1, "slider.png", "LfoAmp1"));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("DELAY");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample1->delayTime1, "slider.png", "DelayTime1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.95, audioSample1->delayFeedback1, "slider.png", "DelayFeedback1"));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("CRUSH");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 32.0, 0.0, audioSample1->bits, "slider.png", "Bits1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1.0, 0.0, audioSample1->rate, "slider.png", "Rate1"));
    gui2->addSpacer(length, dim/5);
    
    gui2->addLabel("REVERB");
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample1->reverbSize, "slider.png", "ReverbSize1"));
    gui2->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET1"));
    gui2->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample1->reverbDryWet, "slider.png", "ReverbDryWet1"));
    gui2->addSpacer(length, dim/5);
    
        
    //PRESETS
    gui7 = new ofxUICanvas(0,380+tempGUIoffset,length+xInit*2.0,guiCanvasLength-380);
    gui7->addWidgetDown(new ofxUILabel("GRAIN PRESETS", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetDown(new ofxUISpacer(length, 2));
    gui7->addLabelButton("SAVE PRESET", true, length-xInit);

    vector<string> hnames; hnames.push_back("1"); hnames.push_back("2"); hnames.push_back("3"); hnames.push_back("4"); hnames.push_back("5"); hnames.push_back("6"); hnames.push_back("7"); hnames.push_back("8");
    ofxUIRadio *radio = (ofxUIRadio *) gui7->addWidgetDown(new ofxUIRadio(dim, dim, "PRESET SELECT", hnames, OFX_UI_ORIENTATION_HORIZONTAL));
    radio->activateToggle("PRESETS");
    
    gui7->addWidgetDown(new ofxUILabel("DELAY", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetRight(new ofxUINumberDialer(0, 10000, 1000, 1, "TWEEN_DURATION", OFX_UI_FONT_MEDIUM));
    
    gui7->addWidgetDown(new ofxUILabel("Tween Shape -", OFX_UI_FONT_MEDIUM));
    //  gui2->addWidgetRight(new ofxUILabel("circ", OFX_UI_FONT_SMALL));
    
    matrixTween = (ofxUIToggleMatrix*) gui7->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 5, "linr1 expo circ  bnce xtic"));// "AV MATRIX"));
    
    matrixTween->setToggle(0, 0, true);
  	gui7->addWidgetDown(new ofxUISpacer(length, 2));
        
    //Listener
    ofAddListener(gui1->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui2->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui7->newGUIEvent, this, &Gui::guiEvent);

    //Padding
    gui1->setDrawPadding(true);
    gui2->setDrawPadding(true);
    gui1->setDrawWidgetPadding(true);
    gui2->setDrawWidgetPadding(true);
    
    //XML preset loading
    gui1->loadSettings("GUI/guiSettingsVolume.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.xml");

    gui7->setVisible(false);
    
    bUseSpeedMaster = true;
    bUseSpeed1 = true;
    bUsePitchMaster = true;
    bUsePitch1 = true;
    bUseGrainSizeMaster = true;
    bUseGrainSize1 = true;
    bUseOverlapsMaster = true;
    bUseOverlaps1 = true;
    bUseRandomGrainSizeMaster = true;
    bUseRandomGrainSize1 = true;
    bUseRandomGrainPitchMaster = true;
    bUseRandomGrainPitch1 = true;
    
    
    //DSP
    bUseCutoffMaster = true;
    bUseCutoff1 = true;
    bUseCutoffLFOMaster = true;
    bUseCutoffLFO1 = true;
    bUseCrushMaster = true;
    bUseCrush1 = true;
    bUseBitsMaster = true;
    bUseBits1 = true;
    bUseDelayTimeMaster = true;
    bUseDelayTime1 = true;
    bUseDelayFeedbackMaster = true;
    bUseDelayFeedback1 = true;
    bUseReverbDecayMaster = true;
    bUseReverbDecay1 = true;
    bUseReverbDryWetMaster = true;
    bUseReverbDryWet1 = true;
    
}


//--------------------------------------------------------------
void Gui::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	
    /***********
	 * AV MATRIX
	 *////////////
    
     //Get the Value for each toggle
     if(ofIsStringInString(e.widget->getName(), "linr1 expo circ  bnce xtic"))  /// this is the name of the matrix you want to grab events...
     {
     vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
     row[0] = res[0];
     col[0] = res[1];
     val[0] = (bool) res[2];
     }
     else if(ofIsStringInString(e.widget->getName(), "GrainWindow1"))
     {
         vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
         row[1] = res[0];
         col[1] = res[1];
         val[1] = (bool) res[2];
     }
    
     
     //TWEEN SHAPE
     if(row[0]==0 && col[0]==0 && val[0]==1){
         tween1->setEasingType(1);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==1 && col[0]==0 && val[0]==1){
         tween1->setEasingType(2);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==2 && col[0]==0 && val[0]==1){
         tween1->setEasingType(3);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==3 && col[0]==0 && val[0]==1){
         tween1->setEasingType(4);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==4&& col[0]==0 && val[0]==1){
         tween1->setEasingType(5);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(3, 0, false);
     }
    
    //GRAIN WINDOW PLAYER 1
    if(row[1]==0 && col[1]==0 && val[1]==1){
        audioSample1->setGrainWindow(0);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
    } else if(row[1]==1 && col[1]==0 && val[1]==1){
        audioSample1->setGrainWindow(1);
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
    } else if(row[1]==2 && col[1]==0 && val[1]==1){
        audioSample1->setGrainWindow(2);
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
    } else if(row[1]==3 && col[1]==0 && val[1]==1){
        audioSample1->setGrainWindow(3);
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(4, 0, false);
    } else if(row[1]==4 && col[1]==0 && val[1]==1){
        audioSample1->setGrainWindow(4);
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
    }
    
      
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
        curPreset = 1;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
        tween1->trigger2();
	}
    else if(name == "2"){
        curPreset = 2;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
        tween1->trigger2();  
	}
    else if(name == "3"){
        curPreset = 3;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
        tween1->trigger2();      
	}
    else if(name == "4"){
        curPreset = 4;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
        tween1->trigger2();      
	}
    else if(name == "5"){
        curPreset = 5;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
        tween1->trigger2();
	}
    else if(name == "6"){
        curPreset = 6;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
        tween1->trigger2();
	}
    else if(name == "7"){
        curPreset = 7;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
        tween1->trigger2();      
	}
    else if(name == "8"){
        curPreset = 8;
        tween1->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
        tween1->trigger2();     
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
    
    //SLIDERS
    else if(name == "Volume1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->volume = slider->getScaledValue();
	}
    
    //DRUM
    //GRANULAR
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
void Gui::triggerPreset1(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("1");
    button->setValue(_value1);
    curPreset = 1;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
    tween1->trigger2();
}
void Gui::triggerPreset2(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("2");
    button->setValue(_value1);
    curPreset = 2;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
    tween1->trigger2();
}
void Gui::triggerPreset3(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("3");
    button->setValue(_value1);
    curPreset = 3;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
    tween1->trigger2();
}
void Gui::triggerPreset4(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("4");
    button->setValue(_value1);
    curPreset = 4;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
    tween1->trigger2();   
}
void Gui::triggerPreset5(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("5");
    button->setValue(_value1);
    curPreset = 5;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
    tween1->trigger2();  
}
void Gui::triggerPreset6(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("6");
    button->setValue(_value1);
    curPreset = 6;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
    tween1->trigger2(); 
}
void Gui::triggerPreset7(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("7");
    button->setValue(_value1);
    curPreset = 7;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
    tween1->trigger2();
}
void Gui::triggerPreset8(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("8");
    button->setValue(_value1);
    curPreset = 8;
    tween1->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
    tween1->trigger2();
}

//--------------------------------------------------------------
void Gui::setVolume1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui1->getWidget("Volume1");
    slider->setValue(_value1);
    audioSample1->volume = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setSpeed1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("speed1");
    slider->setValue(_value1);
    audioSample1->speed1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setPitch1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("pitch1");
    slider->setValue(_value1);
    audioSample1->pitch1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setRandomGrainPitch1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("randomGrainPitch1");
    slider->setValue(_value1);
    audioSample1->randomGrainPitch1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setGrainSize1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("grainLength1");
    slider->setValue(_value1);
    //audioSample1->grainLength1 = slider->getScaledValue();
    audioSample1->setGrainSize(slider->getScaledValue());
}
//--------------------------------------------------------------
void Gui::setRandomGrainSize1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("randomGrainSize1");
    slider->setValue(_value1);
    audioSample1->randomGrainSize1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setOverlaps1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("overlaps1");
    slider->setValue(_value1);
    audioSample1->overlaps1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setCutoff1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("Cutoff1");
    slider->setValue(_value1);
    audioSample1->cutoff1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setLfoSpeed1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("LfoSpeed1");
    slider->setValue(_value1);
    audioSample1->lfoSpeed1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setLfoAmp1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("LfoAmp1");
    slider->setValue(_value1);
    audioSample1->lfoAmp1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setRate1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("Rate1");
    slider->setValue(_value1);
    audioSample1->rate = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setDelayTime1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("DelayTime1");
    slider->setValue(_value1);
    audioSample1->delayTime1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setDelayFeedback1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("DelayFeedback1");
    slider->setValue(_value1);
    audioSample1->delayFeedback1 = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setReverbDecay1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("ReverbSize1");
    slider->setValue(_value1);
    audioSample1->reverbSize = slider->getScaledValue();
}
//--------------------------------------------------------------
void Gui::setReverbDryWet1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("ReverbDryWet1");
    slider->setValue(_value1);
    audioSample1->reverbDryWet = slider->getScaledValue();
}
//--------------------------------------------------------------
vector<int> Gui::getToggleMatrixValues(string received_name , ofxUIEventArgs &e){
    
    ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
    bool val = toggle->getValue();
    
    vector<string> result1 = ofSplitString(received_name, ",");
    vector<string> result2 = ofSplitString(result1[1], ")");
    vector<string> result3 = ofSplitString(result1[0], "(");
    
    string srow = result3[1];
    string scol = result2[0];
    
    int row = ofToInt(srow);
    int col = ofToInt(scol);
    
    //cout << srow << scol << val << endl;
    vector<int> vresult;
    vresult.push_back(row);
    vresult.push_back(col);
    vresult.push_back((int)val);
    
    //cout << vresult[0] << " " <<vresult[1] <<" " << vresult[2] << endl;
    
    return vresult;
    
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
