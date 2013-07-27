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
void Gui::setup(Tween *_tween1, Tween *_tween2, Tween *_tween3, Tween *_tween4, AudioBinaural *_audioBinaural, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4)
{
    curPreset = 1;
    guiOffset = 50;
    int guiWidth = 15;
    int guiCanvasLength = 690;
    
    tween1 = _tween1;
    tween2 = _tween2;
    tween3 = _tween3;
    tween4 = _tween4;
    audioBinaural = _audioBinaural;
    audioSample1 = _audioSample1;
    audioSample2 = _audioSample2;
    audioSample3 = _audioSample3;
    audioSample4 = _audioSample4;

    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    
    //BINARUAL
    guiBinaural = new ofxUICanvas(0,0,length+xInit*2.0,180);
    guiBinaural->addWidgetDown(new ofxUILabel("SHAMANIC AUDIO ENGINE", OFX_UI_FONT_MEDIUM));
    guiBinaural->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    guiBinaural->addSpacer(length, dim/5);
    
    guiBinaural->addLabel("BINARUAL");
    guiBinaural->addSlider("CarrierPitch", 30.0, 300.0, audioBinaural->osc1Pitch, 270, guiWidth);
    guiBinaural->addSlider("CarrierOffset", 0.0, 14.0, audioBinaural->osc2Pitch, 270, guiWidth);
    guiBinaural->addSlider("Binaural_B", 0.0, 1.0, audioBinaural->volume, 270, guiWidth);
    guiBinaural->addSpacer(length, dim/5);
    
    //VOLUME
    gui1 = new ofxUICanvas(0,180,length+xInit*2.0,330);
    gui1->addWidgetDown(new ofxUILabel("VOLUME", OFX_UI_FONT_MEDIUM));
    gui1->addSlider("Volume1", 0.0, 1.0, audioSample1->volume, 40, 150);
    gui1->addWidgetRight(new ofxUISlider("Volume2", 0.0, 1.0, audioSample2->volume, 40, 150));
    gui1->addWidgetRight(new ofxUISlider("Volume3", 0.0, 1.0, audioSample3->volume, 40, 150));
    gui1->addWidgetRight(new ofxUISlider("Volume4", 0.0, 1.0, audioSample4->volume, 40, 150));
    gui1->addSpacer(length, dim/5);
    
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
    
    // SINGING BOWLS
    gui3 = new ofxUICanvas(10+(length+xInit)*2.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui3->addWidgetDown(new ofxUILabel("SAMPLE 2", OFX_UI_FONT_MEDIUM));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("GRANULAR");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH2"));
    gui3->addWidgetRight(new ofxUISlider("pitch2", 0.0, 8.0, audioSample2->pitch1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED2"));
    gui3->addWidgetRight(new ofxUISlider("speed2", -2.0, 2.0, audioSample2->speed1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE2"));
    gui3->addWidgetRight(new ofxUISlider("grainLength2", 0.025, 0.49, audioSample2->grainLength1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS2"));
    gui3->addWidgetRight(new ofxUISlider("overlaps2", 1, 6, audioSample2->overlaps1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH2"));
    gui3->addWidgetRight(new ofxUISlider("randomGrainPitch2", 0.0, 0.50, audioSample2->randomGrainPitch1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE2"));
    gui3->addWidgetRight(new ofxUISlider("randomGrainSize2", 0.0, 0.05, audioSample2->randomGrainSize1, 270, guiWidth));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("FILTER");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF2"));
    gui3->addWidgetRight(new ofxUISlider("Cutoff2", 0.0, 10000.0, audioSample2->cutoff1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO2"));
    gui3->addWidgetRight(new ofxUISlider("LfoSpeed2", 0.0, 200.0, audioSample2->lfoSpeed1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUISlider("LfoAmp2", 0.0, 3000.0, audioSample2->lfoAmp1, 270, guiWidth));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("DELAY");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME2"));
    gui3->addWidgetRight(new ofxUISlider("DelayTime2", 10.0, 3000.0, audioSample2->delayTime1, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK2"));
    gui3->addWidgetRight(new ofxUISlider("DelayFeedback2", 0.0, 0.95, audioSample2->delayFeedback1, 270, guiWidth));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("CRUSH");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS2"));
    gui3->addWidgetRight(new ofxUISlider("Bits2", 32.0, 0.0, audioSample2->bits, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT2"));
    gui3->addWidgetRight(new ofxUISlider("Rate2", 1.0, 0.0, audioSample2->rate, 270, guiWidth));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("REVERB");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY2"));
    gui3->addWidgetRight(new ofxUISlider("ReverbSize2", 0.0, 1.0, audioSample2->reverbSize, 270, guiWidth));
//    gui3->addWidgetRight(new ofxUISlider("ReverbDamp2", 0.0, 1.0, audioSample2->reverbDamp, 270, guiWidth));
//    gui3->addWidgetRight(new ofxUISlider("ReverbWidth2", 0.0, 1.0, audioSample2->reverbWidth, 270, guiWidth));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET2"));
    gui3->addWidgetRight(new ofxUISlider("ReverbDryWet2", 0.0, 1.0, audioSample2->reverbDryWet, 270, guiWidth));
    gui3->addSpacer(length, dim/5);
    
    // THROAT SINGING
    gui4 = new ofxUICanvas(10+(length+xInit)*3.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui4->addWidgetDown(new ofxUILabel("SAMPLE 3", OFX_UI_FONT_MEDIUM));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("GRANULAR");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH3"));
    gui4->addWidgetRight(new ofxUISlider("pitch3", 0.0, 8.0, audioSample3->pitch1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED3"));
    gui4->addWidgetRight(new ofxUISlider("speed3", -2.0, 2.0, audioSample3->speed1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE3"));
    gui4->addWidgetRight(new ofxUISlider("grainLength3", 0.025, 0.49, audioSample3->grainLength1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS3"));
    gui4->addWidgetRight(new ofxUISlider("overlaps3", 1, 6, audioSample3->overlaps1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH3"));
    gui4->addWidgetRight(new ofxUISlider("randomGrainPitch3", 0.0, 0.50, audioSample3->randomGrainPitch1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE3"));
    gui4->addWidgetRight(new ofxUISlider("randomGrainSize3", 0.0, 0.05, audioSample3->randomGrainSize1, 270, guiWidth));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("FILTER");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF3"));
    gui4->addWidgetRight(new ofxUISlider("Cutoff3", 0.0, 10000.0, audioSample3->cutoff1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO3"));
    gui4->addWidgetRight(new ofxUISlider("LfoSpeed3", 0.0, 200.0, audioSample3->lfoSpeed1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUISlider("LfoAmp3", 0.0, 3000.0, audioSample3->lfoAmp1, 270, guiWidth));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("DELAY");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME3"));
    gui4->addWidgetRight(new ofxUISlider("DelayTime3", 10.0, 3000.0, audioSample3->delayTime1, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK3"));
    gui4->addWidgetRight(new ofxUISlider("DelayFeedback3", 0.0, 0.95, audioSample3->delayFeedback1, 270, guiWidth));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("CRUSH");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS3"));
    gui4->addWidgetRight(new ofxUISlider("Bits3", 32.0, 0.0, audioSample3->bits, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT3"));
    gui4->addWidgetRight(new ofxUISlider("Rate3", 1.0, 0.0, audioSample3->rate, 270, guiWidth));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("REVERB");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY3"));
    gui4->addWidgetRight(new ofxUISlider("ReverbSize3", 0.0, 1.0, audioSample3->reverbSize, 270, guiWidth));
//    gui4->addWidgetRight(new ofxUISlider("ReverbDamp3", 0.0, 1.0, audioSample3->reverbDamp, 270, guiWidth));
//    gui4->addWidgetRight(new ofxUISlider("ReverbWidth3", 0.0, 1.0, audioSample3->reverbWidth, 270, guiWidth));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET3"));
    gui4->addWidgetRight(new ofxUISlider("ReverbDryWet3", 0.0, 1.0, audioSample3->reverbDryWet, 270, guiWidth));
    gui4->addSpacer(length, dim/5);
    
    // ICAROS
    gui5 = new ofxUICanvas(10+(length+xInit)*4.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui5->addWidgetDown(new ofxUILabel("SAMPLE 4", OFX_UI_FONT_MEDIUM));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("GRANULAR");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH4"));
    gui5->addWidgetRight(new ofxUISlider("pitch4", 0.0, 8.0, audioSample4->pitch1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED4"));
    gui5->addWidgetRight(new ofxUISlider("speed4", -2.0, 2.0, audioSample4->speed1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE4"));
    gui5->addWidgetRight(new ofxUISlider("grainLength4", 0.025, 0.49, audioSample4->grainLength1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS4"));
    gui5->addWidgetRight(new ofxUISlider("overlaps4", 1, 6, audioSample4->overlaps1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH4"));
    gui5->addWidgetRight(new ofxUISlider("randomGrainPitch4", 0.0, 0.50, audioSample4->randomGrainPitch1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE4"));
    gui5->addWidgetRight(new ofxUISlider("randomGrainSize4", 0.0, 0.05, audioSample4->randomGrainSize1, 270, guiWidth));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("FILTER");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF4"));
    gui5->addWidgetRight(new ofxUISlider("Cutoff4", 0.0, 10000.0, audioSample4->cutoff1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO4"));
    gui5->addWidgetRight(new ofxUISlider("LfoSpeed4", 0.0, 200.0, audioSample4->lfoSpeed1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUISlider("LfoAmp4", 0.0, 3000.0, audioSample4->lfoAmp1, 270, guiWidth));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("DELAY");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME4"));
    gui5->addWidgetRight(new ofxUISlider("DelayTime4", 10.0, 3000.0, audioSample4->delayTime1, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK4"));
    gui5->addWidgetRight(new ofxUISlider("DelayFeedback4", 0.0, 0.95, audioSample4->delayFeedback1, 270, guiWidth));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("CRUSH");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS4"));
    gui5->addWidgetRight(new ofxUISlider("Bits4", 32.0, 0.0, audioSample4->bits, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT4"));
    gui5->addWidgetRight(new ofxUISlider("Rate4", 1.0, 0.0, audioSample4->rate, 270, guiWidth));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("REVERB");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY4"));
    gui5->addWidgetRight(new ofxUISlider("ReverbSize4", 0.0, 1.0, audioSample4->reverbSize, 270, guiWidth));
 //   gui5->addWidgetRight(new ofxUISlider("ReverbDamp4", 0.0, 1.0, audioSample4->reverbDamp, 270, guiWidth));
 //   gui5->addWidgetRight(new ofxUISlider("ReverbWidth4", 0.0, 1.0, audioSample4->reverbWidth, 270, guiWidth));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET4"));
    gui5->addWidgetRight(new ofxUISlider("ReverbDryWet4", 0.0, 1.0, audioSample4->reverbDryWet, 270, guiWidth));
    gui5->addSpacer(length, dim/5);
    
    ////
    gui6 = new ofxUICanvas(10+(length+xInit)*5.0,0,length+xInit*2.0,ofGetHeight());
    gui6->addWidgetDown(new ofxUILabel("THROAT SINGING", OFX_UI_FONT_MEDIUM));
    gui6->addSpacer(length, dim/5);
    
    //PRESETS
    gui7 = new ofxUICanvas(0,380,length+xInit*2.0,guiCanvasLength-380);
    gui7->addWidgetDown(new ofxUILabel("PRESETS", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetDown(new ofxUISpacer(length, 2));
    gui7->addLabelButton("SAVE PRESET", true, length-xInit);

    vector<string> hnames; hnames.push_back("1"); hnames.push_back("2"); hnames.push_back("3"); hnames.push_back("4"); hnames.push_back("5"); hnames.push_back("6"); hnames.push_back("7"); hnames.push_back("8");
    ofxUIRadio *radio = (ofxUIRadio *) gui7->addWidgetDown(new ofxUIRadio(dim, dim, "PRESET SELECT", hnames, OFX_UI_ORIENTATION_HORIZONTAL));
    radio->activateToggle("PRESETS");
    
    gui7->addWidgetDown(new ofxUILabel("DELAY", OFX_UI_FONT_MEDIUM));
    gui7->addWidgetRight(new ofxUINumberDialer(0, 10000, 1000, 1, "TWEEN_DURATION", OFX_UI_FONT_MEDIUM));
    
  	gui7->addWidgetDown(new ofxUISpacer(length, 2));
    
    //Listener
    ofAddListener(guiBinaural->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui1->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui2->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui3->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui4->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui5->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui6->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui7->newGUIEvent, this, &Gui::guiEvent);

    //Padding
    guiBinaural->setDrawPadding(true);
    gui1->setDrawPadding(true);
    gui2->setDrawPadding(true);
    gui3->setDrawPadding(true);
    gui4->setDrawPadding(true);
    gui1->setDrawWidgetPadding(true);
    gui2->setDrawWidgetPadding(true);
    gui3->setDrawWidgetPadding(true);
    gui4->setDrawWidgetPadding(true);
    
    //XML preset loading
    gui1->loadSettings("GUI/guiSettingsVolume.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.xml");
    

    bUseSpeedMaster = true;
    bUseSpeed1 = true;
    bUseSpeed2 = true;
    bUseSpeed3 = true;
    bUseSpeed4 = true;
    bUsePitchMaster = true;
    bUsePitch1 = true;
    bUsePitch2 = true;
    bUsePitch3 = true;
    bUsePitch4 = true;
    bUseGrainSizeMaster = true;
    bUseGrainSize1 = true;
    bUseGrainSize2 = true;
    bUseGrainSize3 = true;
    bUseGrainSize4 = true;
    bUseOverlapsMaster = true;
    bUseOverlaps1 = true;
    bUseOverlaps2 = true;
    bUseOverlaps3 = true;
    bUseOverlaps4 = true;
    bUseRandomGrainSizeMaster = true;
    bUseRandomGrainSize1 = true;
    bUseRandomGrainSize2 = true;
    bUseRandomGrainSize3 = true;
    bUseRandomGrainSize4 = true;
    bUseRandomGrainPitchMaster = true;
    bUseRandomGrainPitch1 = true;
    bUseRandomGrainPitch2 = true;
    bUseRandomGrainPitch3 = true;
    bUseRandomGrainPitch4 = true;
    
    
    //DSP
    bUseCutoffMaster = true;
    bUseCutoff1 = true;
    bUseCutoff2 = true;
    bUseCutoff3 = true;
    bUseCutoff4 = true;
    bUseCutoffLFOMaster = true;
    bUseCutoffLFO1 = true;
    bUseCutoffLFO2 = true;
    bUseCutoffLFO3 = true;
    bUseCutoffLFO4 = true;
    bUseCrushMaster = true;
    bUseCrush1 = true;
    bUseCrush2 = true;
    bUseCrush3 = true;
    bUseCrush4 = true;
    bUseBitsMaster = true;
    bUseBits1 = true;
    bUseBits2 = true;
    bUseBits3 = true;
    bUseBits4 = true;
    bUseDelayTimeMaster = true;
    bUseDelayTime1 = true;
    bUseDelayTime2 = true;
    bUseDelayTime3 = true;
    bUseDelayTime4 = true;
    bUseDelayFeedbackMaster = true;
    bUseDelayFeedback1 = true;
    bUseDelayFeedback2 = true;
    bUseDelayFeedback3 = true;
    bUseDelayFeedback4 = true;
    bUseReverbDecayMaster = true;
    bUseReverbDecay1 = true;
    bUseReverbDecay2 = true;
    bUseReverbDecay3 = true;
    bUseReverbDecay4 = true;
    bUseReverbDryWetMaster = true;
    bUseReverbDryWet1 = true;
    bUseReverbDryWet2 = true;
    bUseReverbDryWet3 = true;
    bUseReverbDryWet4 = true;
    
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
        gui3->saveSettings("GUI/guiSettingsAudio2.1.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.1.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.1.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 2){
        gui1->saveSettings("GUI/guiSettingsVolume.2.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.2.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.2.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.2.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.2.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 3){
        gui1->saveSettings("GUI/guiSettingsVolume.3.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.3.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.3.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.3.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.3.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 4){
        gui1->saveSettings("GUI/guiSettingsVolume.4.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.4.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.4.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.4.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.4.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 5){
        gui1->saveSettings("GUI/guiSettingsVolume.5.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.5.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.5.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.5.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.5.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 6){
        gui1->saveSettings("GUI/guiSettingsVolume.6.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.6.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.6.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.6.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.6.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 7){
        gui1->saveSettings("GUI/guiSettingsVolume.7.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.7.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.7.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.7.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.7.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 8){
        gui1->saveSettings("GUI/guiSettingsVolume.8.xml");
        gui2->saveSettings("GUI/guiSettingsAudio1.8.xml");
        gui3->saveSettings("GUI/guiSettingsAudio2.8.xml");
        gui4->saveSettings("GUI/guiSettingsAudio3.8.xml");
        gui5->saveSettings("GUI/guiSettingsAudio4.8.xml");
    }


    else if(name == "1"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 1;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.1.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.1.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.1.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "2"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 2;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.2.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.2.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.2.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "3"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 3;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.3.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.3.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.3.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "4"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 4;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.4.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.4.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.4.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "5"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 5;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.5.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.5.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.5.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "6"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 6;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.6.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.6.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.6.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "7"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 7;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.7.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.7.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.7.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    else if(name == "8"){
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        curPreset = 8;
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
        gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.8.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.8.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.8.xml");
        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        cout << " curPreset = " << curPreset << endl;
	}
    
    else if(name == "TWEEN_DURATION"){
        ofxUINumberDialer *number = (ofxUINumberDialer *) e.widget;
        tween1->duration = number->getValue();
        tween2->duration = number->getValue();
        tween3->duration = number->getValue();
        tween4->duration = number->getValue();
    }
    
    //TIMELINE GUI TOGGLES
    else if(e.widget->getName() == "USESPEED1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseSpeed1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USESPEED2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseSpeed2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USESPEED3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseSpeed3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USESPEED4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseSpeed4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEPITCH1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUsePitch1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEPITCH2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUsePitch2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEPITCH3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUsePitch3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEPITCH4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUsePitch4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEGRAINSIZE1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseGrainSize1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEGRAINSIZE2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseGrainSize2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEGRAINSIZE3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseGrainSize3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEGRAINSIZE4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseGrainSize4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEOVERLAPS1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseOverlaps1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEOVERLAPS2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseOverlaps2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEOVERLAPS3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseOverlaps3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEOVERLAPS4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseOverlaps4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USERANDOMGRAINSIZE1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainSize1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINSIZE2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainSize2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINSIZE3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainSize3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINSIZE4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainSize4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USERANDOMGRAINPITCH1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainPitch1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINPITCH2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainPitch2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINPITCH3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainPitch3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USERANDOMGRAINPITCH4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseRandomGrainPitch4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECUTOFF1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoff1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFF2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoff2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFF3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoff3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFF4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoff4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECUTOFFLFO1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoffLFO1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFFLFO2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoffLFO2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFFLFO3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoffLFO3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECUTOFFLFO4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCutoffLFO4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USECRUSHAMOUNT1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCrush1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECRUSHAMOUNT2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCrush2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECRUSHAMOUNT3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCrush3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USECRUSHAMOUNT4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseCrush4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEBITS1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseBits1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEBITS2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseBits2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEBITS3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseBits3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEBITS4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseBits4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEDELAYTIME1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayTime1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYTIME2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayTime2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYTIME3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayTime3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYTIME4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayTime4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEDELAYFEEDBACK1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayFeedback1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYFEEDBACK2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayFeedback2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYFEEDBACK3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayFeedback3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEDELAYFEEDBACK4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseDelayFeedback4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEREVERBDECAY1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDecay1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDECAY2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDecay2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDECAY3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDecay3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDECAY4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDecay4 = toggle->getValue();
    }
    
    else if(e.widget->getName() == "USEREVERBDRYWET1")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDryWet1 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDRYWET2")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDryWet2 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDRYWET3")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDryWet3 = toggle->getValue();
    }
    else if(e.widget->getName() == "USEREVERBDRYWET4")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bUseReverbDryWet4 = toggle->getValue();
    }

    
    //SLIDERS
    else if(name == "CarrierPitch")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioBinaural->osc1Pitch = slider->getScaledValue();
	}
    else if(name == "CarrierOffset")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioBinaural->osc2Pitch = slider->getScaledValue();
	}
    else if(name == "Binaural_B")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioBinaural->volume = slider->getScaledValue();
	}
    else if(name == "Volume1")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample1->volume = slider->getScaledValue();
	}
    else if(name == "Volume2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->volume = slider->getScaledValue();
	}
    else if(name == "Volume3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->volume = slider->getScaledValue();
	}
    else if(name == "Volume4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->volume = slider->getScaledValue();
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
    
    //SINGING BOWLS
    //GRANULAR
    else if(name == "speed2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->speed1 = slider->getScaledValue();
	}
	else if(name == "pitch2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->pitch1 = slider->getScaledValue();
	}
    else if(name == "grainLength2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->grainLength1 = slider->getScaledValue();
	}
    else if(name == "overlaps2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->overlaps1 = slider->getScaledValue();
	}
    else if(name == "randomGrainPitch2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->randomGrainPitch1 = slider->getScaledValue();
	}
    else if(name == "randomGrainSize2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->randomGrainSize1 = slider->getScaledValue();
	}
    //DSP
    else if(name == "Cutoff2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->cutoff1 = slider->getScaledValue();
	}
    else if(name == "LfoSpeed2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->lfoSpeed1 = slider->getScaledValue();
	}
    else if(name == "LfoAmp2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->lfoAmp1 = slider->getScaledValue();
	}
    else if(name == "ReverbDryWet2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->reverbDryWet = slider->getScaledValue();
	}
    else if(name == "ReverbSize2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->reverbSize = slider->getScaledValue();
	}
    else if(name == "ReverbDamp2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->reverbDamp = slider->getScaledValue();
	}
    else if(name == "ReverbWidth2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->reverbWidth = slider->getScaledValue();
	}
    else if(name == "Bits2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->bits = slider->getScaledValue();
	}
    else if(name == "Rate2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->rate = slider->getScaledValue();
	}
    else if(name == "DelayTime2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->delayTime1 = slider->getScaledValue();
	}
    else if(name == "DelayFeedback2")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample2->delayFeedback1 = slider->getScaledValue();
	}
    
    //THROAT SINGING
    //GRANULAR
    else if(name == "speed3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->speed1 = slider->getScaledValue();
	}
	else if(name == "pitch3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->pitch1 = slider->getScaledValue();
	}
    else if(name == "grainLength3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->grainLength1 = slider->getScaledValue();
	}
    else if(name == "overlaps3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->overlaps1 = slider->getScaledValue();
	}
    else if(name == "randomGrainPitch3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->randomGrainPitch1 = slider->getScaledValue();
	}
    else if(name == "randomGrainSize3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->randomGrainSize1 = slider->getScaledValue();
	}
    //DSP
    else if(name == "Cutoff3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->cutoff1 = slider->getScaledValue();
	}
    else if(name == "LfoSpeed3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->lfoSpeed1 = slider->getScaledValue();
	}
    else if(name == "LfoAmp3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->lfoAmp1 = slider->getScaledValue();
	}
    else if(name == "ReverbDryWet3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->reverbDryWet = slider->getScaledValue();
	}
    else if(name == "ReverbSize3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->reverbSize = slider->getScaledValue();
	}
    else if(name == "ReverbDamp3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->reverbDamp = slider->getScaledValue();
	}
    else if(name == "ReverbWidth3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->reverbWidth = slider->getScaledValue();
	}
    else if(name == "Bits3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->bits = slider->getScaledValue();
	}
    else if(name == "Rate3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->rate = slider->getScaledValue();
	}
    else if(name == "DelayTime3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->delayTime1 = slider->getScaledValue();
	}
    else if(name == "DelayFeedback3")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample3->delayFeedback1 = slider->getScaledValue();
	}
    
    //ICAROS
    //GRANULAR
    else if(name == "speed4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->speed1 = slider->getScaledValue();
	}
	else if(name == "pitch4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->pitch1 = slider->getScaledValue();
	}
    else if(name == "grainLength4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->grainLength1 = slider->getScaledValue();
	}
    else if(name == "overlaps4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->overlaps1 = slider->getScaledValue();
	}
    else if(name == "randomGrainPitch4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->randomGrainPitch1 = slider->getScaledValue();
	}
    else if(name == "randomGrainSize4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->randomGrainSize1 = slider->getScaledValue();
	}
    //DSP
    else if(name == "Cutoff4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->cutoff1 = slider->getScaledValue();
	}
    else if(name == "LfoSpeed4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->lfoSpeed1 = slider->getScaledValue();
	}
    else if(name == "LfoAmp4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->lfoAmp1 = slider->getScaledValue();
	}
    else if(name == "ReverbDryWet4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->reverbDryWet = slider->getScaledValue();
	}
    else if(name == "ReverbSize4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->reverbSize = slider->getScaledValue();
	}
    else if(name == "ReverbDamp4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->reverbDamp = slider->getScaledValue();
	}
    else if(name == "ReverbWidth4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->reverbWidth = slider->getScaledValue();
	}
    else if(name == "Bits4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->bits = slider->getScaledValue();
	}
    else if(name == "Rate4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->rate = slider->getScaledValue();
	}
    else if(name == "DelayTime4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->delayTime1 = slider->getScaledValue();
	}
    else if(name == "DelayFeedback4")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioSample4->delayFeedback1 = slider->getScaledValue();
	}
    
}

//--------------------------------------------------------------
void Gui::triggerPreset1(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("1");
    button->setValue(_value1);
    curPreset = 1;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.1.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.1.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.1.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset2(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("2");
    button->setValue(_value1);
    curPreset = 2;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.2.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.2.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.2.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset3(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("3");
    button->setValue(_value1);
    curPreset = 3;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.3.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.3.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.3.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset4(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("4");
    button->setValue(_value1);
    curPreset = 4;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.4.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.4.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.4.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset5(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("5");
    button->setValue(_value1);
    curPreset = 5;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.5.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.5.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.5.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset6(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("6");
    button->setValue(_value1);
    curPreset = 6;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.6.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.6.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.6.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset7(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("7");
    button->setValue(_value1);
    curPreset = 7;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.7.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.7.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.7.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
void Gui::triggerPreset8(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("8");
    button->setValue(_value1);
    curPreset = 8;
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
    gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.8.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.8.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.8.xml");
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
}
//--------------------------------------------------------------
void Gui::setBinVolume(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("Binaural_B");
    slider->setValue(_value1);
    audioBinaural->volume = slider->getScaledValue();
}
void Gui::setBinPitch(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("CarrierPitch");
    slider->setValue(_value1);
    audioBinaural->osc1Pitch = slider->getScaledValue();
}
void Gui::setBinOffset(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("CarrierOffset");
    slider->setValue(_value1);
    audioBinaural->osc2Pitch = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setVolume1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui1->getWidget("Volume1");
    slider->setValue(_value1);
    audioSample1->volume = slider->getScaledValue();
}
void Gui::setVolume2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui1->getWidget("Volume2");
    slider->setValue(_value1);
    audioSample2->volume = slider->getScaledValue();
}
void Gui::setVolume3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui1->getWidget("Volume3");
    slider->setValue(_value1);
    audioSample3->volume = slider->getScaledValue();
}
void Gui::setVolume4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui1->getWidget("Volume4");
    slider->setValue(_value1);
    audioSample4->volume = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setSpeed1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("speed1");
    slider->setValue(_value1);
    audioSample1->speed1 = slider->getScaledValue();
}
void Gui::setSpeed2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("speed2");
    slider->setValue(_value1);
    audioSample2->speed1 = slider->getScaledValue();
}
void Gui::setSpeed3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("speed3");
    slider->setValue(_value1);
    audioSample3->speed1 = slider->getScaledValue();
}
void Gui::setSpeed4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("speed4");
    slider->setValue(_value1);
    audioSample4->speed1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setPitch1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("pitch1");
    slider->setValue(_value1);
    audioSample1->pitch1 = slider->getScaledValue();
}
void Gui::setPitch2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("pitch2");
    slider->setValue(_value1);
    audioSample2->pitch1 = slider->getScaledValue();
}
void Gui::setPitch3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("pitch3");
    slider->setValue(_value1);
    audioSample3->pitch1 = slider->getScaledValue();
}
void Gui::setPitch4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("pitch4");
    slider->setValue(_value1);
    audioSample4->pitch1 = slider->getScaledValue();
}


//--------------------------------------------------------------
void Gui::setRandomGrainPitch1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("randomGrainPitch1");
    slider->setValue(_value1);
    audioSample1->randomGrainPitch1 = slider->getScaledValue();
}
void Gui::setRandomGrainPitch2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("randomGrainPitch2");
    slider->setValue(_value1);
    audioSample2->randomGrainPitch1 = slider->getScaledValue();
}
void Gui::setRandomGrainPitch3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("randomGrainPitch3");
    slider->setValue(_value1);
    audioSample3->randomGrainPitch1 = slider->getScaledValue();
}
void Gui::setRandomGrainPitch4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("randomGrainPitch4");
    slider->setValue(_value1);
    audioSample4->randomGrainPitch1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setGrainSize1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("grainLength1");
    slider->setValue(_value1);
    audioSample1->grainLength1 = slider->getScaledValue();
}
void Gui::setGrainSize2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("grainLength2");
    slider->setValue(_value1);
    audioSample2->grainLength1 = slider->getScaledValue();
}
void Gui::setGrainSize3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("grainLength3");
    slider->setValue(_value1);
    audioSample3->grainLength1 = slider->getScaledValue();
}
void Gui::setGrainSize4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("grainLength4");
    slider->setValue(_value1);
    audioSample4->grainLength1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setRandomGrainSize1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("randomGrainSize1");
    slider->setValue(_value1);
    audioSample1->randomGrainSize1 = slider->getScaledValue();
}
void Gui::setRandomGrainSize2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("randomGrainSize2");
    slider->setValue(_value1);
    audioSample2->randomGrainSize1 = slider->getScaledValue();
}
void Gui::setRandomGrainSize3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("randomGrainSize3");
    slider->setValue(_value1);
    audioSample3->randomGrainSize1 = slider->getScaledValue();
}
void Gui::setRandomGrainSize4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("randomGrainSize4");
    slider->setValue(_value1);
    audioSample4->randomGrainSize1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setOverlaps1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("overlaps1");
    slider->setValue(_value1);
    audioSample1->overlaps1 = slider->getScaledValue();
}
void Gui::setOverlaps2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("overlaps2");
    slider->setValue(_value1);
    audioSample2->overlaps1 = slider->getScaledValue();
}
void Gui::setOverlaps3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("overlaps3");
    slider->setValue(_value1);
    audioSample3->overlaps1 = slider->getScaledValue();
}
void Gui::setOverlaps4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("overlaps4");
    slider->setValue(_value1);
    audioSample4->overlaps1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setCutoff1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("Cutoff1");
    slider->setValue(_value1);
    audioSample1->cutoff1 = slider->getScaledValue();
}
void Gui::setCutoff2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("Cutoff2");
    slider->setValue(_value1);
    audioSample2->cutoff1 = slider->getScaledValue();
}
void Gui::setCutoff3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("Cutoff3");
    slider->setValue(_value1);
    audioSample3->cutoff1 = slider->getScaledValue();
}
void Gui::setCutoff4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("Cutoff4");
    slider->setValue(_value1);
    audioSample4->cutoff1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setLfoSpeed1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("LfoSpeed1");
    slider->setValue(_value1);
    audioSample1->lfoSpeed1 = slider->getScaledValue();
}
void Gui::setLfoSpeed2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("LfoSpeed2");
    slider->setValue(_value1);
    audioSample2->lfoSpeed1 = slider->getScaledValue();
}
void Gui::setLfoSpeed3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("LfoSpeed3");
    slider->setValue(_value1);
    audioSample3->lfoSpeed1 = slider->getScaledValue();
}
void Gui::setLfoSpeed4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("LfoSpeed4");
    slider->setValue(_value1);
    audioSample4->lfoSpeed1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setLfoAmp1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("LfoAmp1");
    slider->setValue(_value1);
    audioSample1->lfoAmp1 = slider->getScaledValue();
}
void Gui::setLfoAmp2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("LfoAmp2");
    slider->setValue(_value1);
    audioSample2->lfoAmp1 = slider->getScaledValue();
}
void Gui::setLfoAmp3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("LfoAmp3");
    slider->setValue(_value1);
    audioSample3->lfoAmp1 = slider->getScaledValue();
}
void Gui::setLfoAmp4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("LfoAmp4");
    slider->setValue(_value1);
    audioSample4->lfoAmp1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setRate1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("Rate1");
    slider->setValue(_value1);
    audioSample1->rate = slider->getScaledValue();
}
void Gui::setRate2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("Rate2");
    slider->setValue(_value1);
    audioSample2->rate = slider->getScaledValue();
}
void Gui::setRate3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("Rate3");
    slider->setValue(_value1);
    audioSample3->rate = slider->getScaledValue();
}
void Gui::setRate4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("Rate4");
    slider->setValue(_value1);
    audioSample4->rate = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setDelayTime1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("DelayTime1");
    slider->setValue(_value1);
    audioSample1->delayTime1 = slider->getScaledValue();
}
void Gui::setDelayTime2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("DelayTime2");
    slider->setValue(_value1);
    audioSample2->delayTime1 = slider->getScaledValue();
}
void Gui::setDelayTime3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("DelayTime3");
    slider->setValue(_value1);
    audioSample3->delayTime1 = slider->getScaledValue();
}
void Gui::setDelayTime4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("DelayTime4");
    slider->setValue(_value1);
    audioSample4->delayTime1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setDelayFeedback1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("DelayFeedback1");
    slider->setValue(_value1);
    audioSample1->delayFeedback1 = slider->getScaledValue();
}
void Gui::setDelayFeedback2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("DelayFeedback2");
    slider->setValue(_value1);
    audioSample2->delayFeedback1 = slider->getScaledValue();
}
void Gui::setDelayFeedback3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("DelayFeedback3");
    slider->setValue(_value1);
    audioSample3->delayFeedback1 = slider->getScaledValue();
}
void Gui::setDelayFeedback4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("DelayFeedback4");
    slider->setValue(_value1);
    audioSample4->delayFeedback1 = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setReverbDecay1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("ReverbSize1");
    slider->setValue(_value1);
    audioSample1->reverbSize = slider->getScaledValue();
}
void Gui::setReverbDecay2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("ReverbSize2");
    slider->setValue(_value1);
    audioSample2->reverbSize = slider->getScaledValue();
}
void Gui::setReverbDecay3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("ReverbSize3");
    slider->setValue(_value1);
    audioSample3->reverbSize = slider->getScaledValue();
}
void Gui::setReverbDecay4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("ReverbSize4");
    slider->setValue(_value1);
    audioSample4->reverbSize = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setReverbDryWet1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("ReverbDryWet1");
    slider->setValue(_value1);
    audioSample1->reverbDryWet = slider->getScaledValue();
}
void Gui::setReverbDryWet2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("ReverbDryWet2");
    slider->setValue(_value1);
    audioSample2->reverbDryWet = slider->getScaledValue();
}
void Gui::setReverbDryWet3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("ReverbDryWet3");
    slider->setValue(_value1);
    audioSample3->reverbDryWet = slider->getScaledValue();
}
void Gui::setReverbDryWet4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("ReverbDryWet4");
    slider->setValue(_value1);
    audioSample4->reverbDryWet = slider->getScaledValue();
}


//--------------------------------------------------------------
void Gui::drawData(){
    
    //Data vis
    //Page 1
    
     string buf[4];     
     buf[1] = "Speed 1: " + ofToString(audioSample1->speed1, 4);
     ofDrawBitmapString(buf[1], 1630, 140);
     buf[1] = "Speed 2: " + ofToString(audioSample2->speed1, 4);
     ofDrawBitmapString(buf[1], 1630, 170);
     buf[1] = "Speed 3: " + ofToString(audioSample3->speed1, 4);
     ofDrawBitmapString(buf[1], 1630, 200);
     buf[1] = "Speed 4: " + ofToString(audioSample4->speed1, 4);
     ofDrawBitmapString(buf[1], 1630, 230);
    
     buf[1] = "Pitch 1: " + ofToString(audioSample1->pitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 270);
     buf[1] = "Pitch 2: " + ofToString(audioSample2->pitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 300);
     buf[1] = "Pitch 3: " + ofToString(audioSample3->pitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 330);
     buf[1] = "Pitch 4: " + ofToString(audioSample4->pitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 360);
    
     buf[1] = "GrainSize 1: " + ofToString(audioSample1->grainLength1, 4);
     ofDrawBitmapString(buf[1], 1630, 440);
     buf[1] = "GrainSize 2: " + ofToString(audioSample2->grainLength1, 4);
     ofDrawBitmapString(buf[1], 1630, 470);
     buf[1] = "GrainSize 3: " + ofToString(audioSample3->grainLength1, 4);
     ofDrawBitmapString(buf[1], 1630, 500);
     buf[1] = "GrainSize 4: " + ofToString(audioSample4->grainLength1, 4);
     ofDrawBitmapString(buf[1], 1630, 530);
    
     buf[1] = "GrainOverlaps 1: " + ofToString(audioSample1->overlaps1, 4);
     ofDrawBitmapString(buf[1], 1630, 570);
     buf[1] = "GrainOverlaps 2: " + ofToString(audioSample2->overlaps1, 4);
     ofDrawBitmapString(buf[1], 1630, 600);
     buf[1] = "GrainOverlaps 3: " + ofToString(audioSample3->overlaps1, 4);
     ofDrawBitmapString(buf[1], 1630, 630);
     buf[1] = "GrainOverlaps 4: " + ofToString(audioSample4->overlaps1, 4);
     ofDrawBitmapString(buf[1], 1630, 660);
    
     buf[1] = "Ran Grain Size 1: " + ofToString(audioSample1->randomGrainSize1, 4);
     ofDrawBitmapString(buf[1], 1630, 700);
     buf[1] = "Ran Grain Size 2: " + ofToString(audioSample2->randomGrainSize1, 4);
     ofDrawBitmapString(buf[1], 1630, 730);
     buf[1] = "Ran Grain Size 3: " + ofToString(audioSample3->randomGrainSize1, 4);
     ofDrawBitmapString(buf[1], 1630, 760);
     buf[1] = "Ran Grain Size 4: " + ofToString(audioSample4->randomGrainSize1, 4);
     ofDrawBitmapString(buf[1], 1630, 790);
    
     buf[1] = "Ran Grain Pitch 1: " + ofToString(audioSample1->randomGrainPitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 830);
     buf[1] = "Ran Grain Pitch 2: " + ofToString(audioSample2->randomGrainPitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 860);
     buf[1] = "Ran Grain Pitch 3: " + ofToString(audioSample3->randomGrainPitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 890);
     buf[1] = "Ran Grain Pitch 4: " + ofToString(audioSample4->randomGrainPitch1, 4);
     ofDrawBitmapString(buf[1], 1630, 920);
 
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
