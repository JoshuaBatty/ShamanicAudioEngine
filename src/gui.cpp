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
    delete gui3;
    delete gui4;
    delete gui5;
    delete gui6;
    delete gui7;
    
}

//--------------------------------------------------------------
void Gui::setup(Tween *_tween1, Tween *_tween2, Tween *_tween3, Tween *_tween4, AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4)
{
    curPreset = 1;
    guiOffset = 50;
    int guiWidth = 15;
    int guiCanvasLength = 840;
    
    tween1 = _tween1;
    tween2 = _tween2;
    tween3 = _tween3;
    tween4 = _tween4;
    audioSample1 = _audioSample1;
    audioSample2 = _audioSample2;
    audioSample3 = _audioSample3;
    audioSample4 = _audioSample4;

    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    float tempGUIoffset = 180;
    
    //VOLUME
    gui1 = new ofxUICanvas(0,187+tempGUIoffset,length+xInit*2.0,330);
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
    
    gui2->addLabel("PANNING");
    gui2->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample1->pan, "slider.png", "PanPos1"));
    gui2->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample1->panLfoAmp, "slider.png", "PanLfoAmp1"));
    gui2->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample1->panLfoSpeed, "slider.png", "PanLfoSpeed1"));
    gui2->addSpacer(length, dim/5);
    
    // SINGING BOWLS
    gui3 = new ofxUICanvas(10+(length+xInit)*2.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui3->addWidgetDown(new ofxUILabel("SAMPLE 2", OFX_UI_FONT_MEDIUM));
    gui3->addSpacer(length, dim/5);
    
    gui3->addWidgetDown(new ofxUILabel("Grain Window -", OFX_UI_FONT_SMALL));
    matrix2 = (ofxUIToggleMatrix*) gui3->addWidgetRight(new ofxUIToggleMatrix(dim*1.5, dim*1.5, 1, 5, "GrainWindow2"));// "GRAIN WINDOW 2"));
    matrix2->setToggle(0, 0, true);
  	gui3->addWidgetDown(new ofxUISpacer(length, 2));
    
    gui3->addLabel("GRANULAR");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 8.0, audioSample2->pitch1, "slider.png", "pitch2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, -2.0, 2.0, audioSample2->speed1, "slider.png", "speed2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.025, 0.49, audioSample2->grainLength1, "slider.png", "grainLength2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1, 6, audioSample2->overlaps1, "slider.png", "overlaps2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.50, audioSample2->randomGrainPitch1, "slider.png", "randomGrainPitch2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.05, audioSample2->randomGrainSize1, "slider.png", "randomGrainSize2"));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("FILTER");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample2->cutoff1, "slider.png", "Cutoff2"));
    
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 200.0, audioSample2->lfoSpeed1, "slider.png", "LfoSpeed2"));
    gui3->addWidgetDown(new ofxUIImageSlider(length-xInit, guiWidth, 0.0, 3000.0, audioSample2->lfoAmp1, "slider.png", "LfoAmp2"));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("DELAY");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample2->delayTime1, "slider.png", "DelayTime2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.95, audioSample2->delayFeedback1, "slider.png", "DelayFeedback2"));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("CRUSH");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 32.0, 0.0, audioSample2->bits, "slider.png", "Bits2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1.0, 0.0, audioSample2->rate, "slider.png", "Rate2"));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("REVERB");
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample2->reverbSize, "slider.png", "ReverbSize2"));
    gui3->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET2"));
    gui3->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample2->reverbDryWet, "slider.png", "ReverbDryWet2"));
    gui3->addSpacer(length, dim/5);
    
    gui3->addLabel("PANNING");
    gui3->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample2->pan, "slider.png", "PanPos2"));
    gui3->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample2->panLfoAmp, "slider.png", "PanLfoAmp2"));
    gui3->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample2->panLfoSpeed, "slider.png", "PanLfoSpeed2"));
    gui3->addSpacer(length, dim/5);
    
    // THROAT SINGING
    gui4 = new ofxUICanvas(10+(length+xInit)*3.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui4->addWidgetDown(new ofxUILabel("SAMPLE 3", OFX_UI_FONT_MEDIUM));
    gui4->addSpacer(length, dim/5);
    
    gui4->addWidgetDown(new ofxUILabel("Grain Window -", OFX_UI_FONT_SMALL));
    matrix3 = (ofxUIToggleMatrix*) gui4->addWidgetRight(new ofxUIToggleMatrix(dim*1.5, dim*1.5, 1, 5, "GrainWindow3"));// "GRAIN WINDOW 3"));
    matrix3->setToggle(0, 0, true);
  	gui4->addWidgetDown(new ofxUISpacer(length, 2));
    
    gui4->addLabel("GRANULAR");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 8.0, audioSample3->pitch1, "slider.png", "pitch3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, -2.0, 2.0, audioSample3->speed1, "slider.png", "speed3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.025, 0.49, audioSample3->grainLength1, "slider.png", "grainLength3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1, 6, audioSample3->overlaps1, "slider.png", "overlaps3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.50, audioSample3->randomGrainPitch1, "slider.png", "randomGrainPitch3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.05, audioSample3->randomGrainSize1, "slider.png", "randomGrainSize3"));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("FILTER");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample3->cutoff1, "slider.png", "Cutoff3"));
    
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 200.0, audioSample3->lfoSpeed1, "slider.png", "LfoSpeed3"));
    gui4->addWidgetDown(new ofxUIImageSlider(length-xInit, guiWidth, 0.0, 3000.0, audioSample3->lfoAmp1, "slider.png", "LfoAmp3"));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("DELAY");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample3->delayTime1, "slider.png", "DelayTime3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.95, audioSample3->delayFeedback1, "slider.png", "DelayFeedback3"));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("CRUSH");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 32.0, 0.0, audioSample3->bits, "slider.png", "Bits3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1.0, 0.0, audioSample3->rate, "slider.png", "Rate3"));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("REVERB");
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample3->reverbSize, "slider.png", "ReverbSize3"));
    gui4->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET3"));
    gui4->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample3->reverbDryWet, "slider.png", "ReverbDryWet3"));
    gui4->addSpacer(length, dim/5);
    
    gui4->addLabel("PANNING");
    gui4->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample3->pan, "slider.png", "PanPos3"));
    gui4->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample3->panLfoAmp, "slider.png", "PanLfoAmp3"));
    gui4->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample3->panLfoSpeed, "slider.png", "PanLfoSpeed3"));
    gui4->addSpacer(length, dim/5);
    
    // ICAROS
    gui5 = new ofxUICanvas(10+(length+xInit)*4.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    gui5->addWidgetDown(new ofxUILabel("SAMPLE 4", OFX_UI_FONT_MEDIUM));
    gui5->addSpacer(length, dim/5);
    
    gui5->addWidgetDown(new ofxUILabel("Grain Window -", OFX_UI_FONT_SMALL));
    matrix4 = (ofxUIToggleMatrix*) gui5->addWidgetRight(new ofxUIToggleMatrix(dim*1.5, dim*1.5, 1, 5, "GrainWindow4"));// "GRAIN WINDOW 4"));
    matrix4->setToggle(0, 0, true);
  	gui5->addWidgetDown(new ofxUISpacer(length, 2));
    
    gui5->addLabel("GRANULAR");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEPITCH4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 8.0, audioSample4->pitch1, "slider.png", "pitch4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USESPEED4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, -2.0, 2.0, audioSample4->speed1, "slider.png", "speed4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEGRAINSIZE4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.025, 0.49, audioSample4->grainLength1, "slider.png", "grainLength4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEOVERLAPS4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1, 6, audioSample4->overlaps1, "slider.png", "overlaps4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINPITCH4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.50, audioSample4->randomGrainPitch1, "slider.png", "randomGrainPitch4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USERANDOMGRAINSIZE4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.05, audioSample4->randomGrainSize1, "slider.png", "randomGrainSize4"));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("FILTER");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFF4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample4->cutoff1, "slider.png", "Cutoff4"));
    
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECUTOFFLFO4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 200.0, audioSample4->lfoSpeed1, "slider.png", "LfoSpeed4"));
    gui5->addWidgetDown(new ofxUIImageSlider(length-xInit, guiWidth, 0.0, 3000.0, audioSample4->lfoAmp1, "slider.png", "LfoAmp4"));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("DELAY");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYTIME4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 10000.0, audioSample4->delayTime1, "slider.png", "DelayTime4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEDELAYFEEDBACK4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 0.95, audioSample4->delayFeedback1, "slider.png", "DelayFeedback4"));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("CRUSH");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEBITS4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 32.0, 0.0, audioSample4->bits, "slider.png", "Bits4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USECRUSHAMOUNT4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 1.0, 0.0, audioSample4->rate, "slider.png", "Rate4"));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("REVERB");
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDECAY4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample4->reverbSize, "slider.png", "ReverbSize4"));
    gui5->addWidgetDown(new ofxUIImageToggle(dim*2, dim*2, true, "GUI/play.png", "USEREVERBDRYWET4"));
    gui5->addWidgetRight(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample4->reverbDryWet, "slider.png", "ReverbDryWet4"));
    gui5->addSpacer(length, dim/5);
    
    gui5->addLabel("PANNING");
    gui5->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample4->pan, "slider.png", "PanPos4"));
    gui5->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample4->panLfoAmp, "slider.png", "PanLfoAmp4"));
    gui5->addWidgetDown(new ofxUIImageSlider(270, guiWidth, 0.0, 1.0, audioSample4->panLfoSpeed, "slider.png", "PanLfoSpeed4"));
    gui5->addSpacer(length, dim/5);
    
    ////
    gui6 = new ofxUICanvas(10+(length+xInit)*5.0,0,length+xInit*2.0,ofGetHeight());
    gui6->addWidgetDown(new ofxUILabel("THROAT SINGING", OFX_UI_FONT_MEDIUM));
    gui6->addSpacer(length, dim/5);
    
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
    ofAddListener(gui3->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui4->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui5->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui6->newGUIEvent, this, &Gui::guiEvent);
    ofAddListener(gui7->newGUIEvent, this, &Gui::guiEvent);

    //Padding
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
     else if(ofIsStringInString(e.widget->getName(), "GrainWindow2"))
     {
         vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
         row[2] = res[0];
         col[2] = res[1];
         val[2] = (bool) res[2];
     }
     else if(ofIsStringInString(e.widget->getName(), "GrainWindow3"))
     {
         vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
         row[3] = res[0];
         col[3] = res[1];
         val[3] = (bool) res[2];
     }
     else if(ofIsStringInString(e.widget->getName(), "GrainWindow4"))
     {
         vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
         row[4] = res[0];
         col[4] = res[1];
         val[4] = (bool) res[2];
     }
    
     
     //TWEEN SHAPE
     if(row[0]==0 && col[0]==0 && val[0]==1){
         tween1->setEasingType(1);
         tween2->setEasingType(1);
         tween3->setEasingType(1);
         tween4->setEasingType(1);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==1 && col[0]==0 && val[0]==1){
         tween1->setEasingType(2);
         tween2->setEasingType(2);
         tween3->setEasingType(2);
         tween4->setEasingType(2);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==2 && col[0]==0 && val[0]==1){
         tween1->setEasingType(3);
         tween2->setEasingType(3);
         tween3->setEasingType(3);
         tween4->setEasingType(3);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(3, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==3 && col[0]==0 && val[0]==1){
         tween1->setEasingType(4);
         tween2->setEasingType(4);
         tween3->setEasingType(4);
         tween4->setEasingType(4);
         matrixTween->setToggle(0, 0, false);
         matrixTween->setToggle(1, 0, false);
         matrixTween->setToggle(2, 0, false);
         matrixTween->setToggle(4, 0, false);
     } else if(row[0]==4&& col[0]==0 && val[0]==1){
         tween1->setEasingType(5);
         tween2->setEasingType(5);
         tween3->setEasingType(5);
         tween4->setEasingType(5);
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
    
    //GRAIN WINDOW PLAYER 2
    if(row[2]==0 && col[2]==0 && val[2]==1){
        audioSample2->setGrainWindow(0);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
    } else if(row[2]==1 && col[2]==0 && val[2]==1){
        audioSample2->setGrainWindow(1);
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
    } else if(row[2]==2 && col[2]==0 && val[2]==1){
        audioSample2->setGrainWindow(2);
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
    } else if(row[2]==3 && col[2]==0 && val[2]==1){
        audioSample2->setGrainWindow(3);
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(4, 0, false);
    } else if(row[2]==4 && col[2]==0 && val[2]==1){
        audioSample2->setGrainWindow(4);
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
    }
    
    //GRAIN WINDOW PLAYER 3
    if(row[3]==0 && col[3]==0 && val[3]==1){
        audioSample3->setGrainWindow(0);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
    } else if(row[3]==1 && col[3]==0 && val[3]==1){
        audioSample3->setGrainWindow(1);
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
    } else if(row[3]==2 && col[3]==0 && val[3]==1){
        audioSample3->setGrainWindow(2);
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
    } else if(row[3]==3 && col[3]==0 && val[3]==1){
        audioSample3->setGrainWindow(3);
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(4, 0, false);
    } else if(row[3]==4 && col[3]==0 && val[3]==1){
        audioSample3->setGrainWindow(4);
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
    }
    
    //GRAIN WINDOW PLAYER 4
    if(row[4]==0 && col[4]==0 && val[4]==1){
        audioSample4->setGrainWindow(0);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
    } else if(row[4]==1 && col[4]==0 && val[4]==1){
        audioSample4->setGrainWindow(1);
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
    } else if(row[4]==2 && col[4]==0 && val[4]==1){
        audioSample4->setGrainWindow(2);
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
    } else if(row[4]==3 && col[4]==0 && val[4]==1){
        audioSample4->setGrainWindow(3);
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(4, 0, false);
    } else if(row[4]==4 && col[4]==0 && val[4]==1){
        audioSample4->setGrainWindow(4);
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
    }
    
    
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
        curPreset = 1;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.1.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.1.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.1.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "2"){
        curPreset = 2;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.2.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.2.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.2.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "3"){
        curPreset = 3;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.3.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.3.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.3.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "4"){
        curPreset = 4;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.4.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.4.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.4.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "5"){
        curPreset = 5;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.5.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.5.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.5.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "6"){
        curPreset = 6;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.6.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.6.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.6.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "7"){
        curPreset = 7;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.7.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.7.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.7.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
	}
    else if(name == "8"){
        curPreset = 8;

        tween1->catchTempVariables();
        tween2->catchTempVariables();
        tween3->catchTempVariables();
        tween4->catchTempVariables();
        gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
        gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
        gui3->loadSettings("GUI/guiSettingsAudio2.8.xml");
        gui4->loadSettings("GUI/guiSettingsAudio3.8.xml");
        gui5->loadSettings("GUI/guiSettingsAudio4.8.xml");
        tween1->trigger2();
        tween2->trigger2();
        tween3->trigger2();
        tween4->trigger2();
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
    //Panning
    else if(name == "PanPos1"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample1->pan = slider->getScaledValue();
    } else if(name == "PanLfoAmp1"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample1->panLfoAmp = slider->getScaledValue();
    } else if(name == "PanLfoSpeed1"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample1->panLfoSpeed = slider->getScaledValue();
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
    //Panning
    else if(name == "PanPos2"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample2->pan = slider->getScaledValue();
    } else if(name == "PanLfoAmp2"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample2->panLfoAmp = slider->getScaledValue();
    } else if(name == "PanLfoSpeed2"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample2->panLfoSpeed = slider->getScaledValue();
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
    //Panning
    else if(name == "PanPos3"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample3->pan = slider->getScaledValue();
    } else if(name == "PanLfoAmp3"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample3->panLfoAmp = slider->getScaledValue();
    } else if(name == "PanLfoSpeed3"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample3->panLfoSpeed = slider->getScaledValue();
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
    //Panning
    else if(name == "PanPos4"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample4->pan = slider->getScaledValue();
    } else if(name == "PanLfoAmp4"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample4->panLfoAmp = slider->getScaledValue();
    } else if(name == "PanLfoSpeed4"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        audioSample4->panLfoSpeed = slider->getScaledValue();
    }
    
}

//--------------------------------------------------------------
void Gui::triggerPreset1(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("1");
    button->setValue(_value1);
    curPreset = 1;

    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.1.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.1.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.1.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.1.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.1.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();

}
void Gui::triggerPreset2(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("2");
    button->setValue(_value1);
    curPreset = 2;
    
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.2.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.2.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.2.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.2.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.2.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();

}
void Gui::triggerPreset3(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("3");
    button->setValue(_value1);
    curPreset = 3;
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.3.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.3.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.3.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.3.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.3.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
}
void Gui::triggerPreset4(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("4");
    button->setValue(_value1);
    curPreset = 4;
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.4.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.4.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.4.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.4.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.4.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
}
void Gui::triggerPreset5(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("5");
    button->setValue(_value1);
    curPreset = 5;
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.5.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.5.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.5.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.5.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.5.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
}
void Gui::triggerPreset6(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("6");
    button->setValue(_value1);
    curPreset = 6;
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.6.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.6.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.6.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.6.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.6.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
}
void Gui::triggerPreset7(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("7");
    button->setValue(_value1);
    curPreset = 7;
    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.7.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.7.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.7.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.7.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.7.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
}
void Gui::triggerPreset8(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) gui7->getWidget("8");
    button->setValue(_value1);
    curPreset = 8;

    tween1->catchTempVariables();
    tween2->catchTempVariables();
    tween3->catchTempVariables();
    tween4->catchTempVariables();
    gui1->loadSettings("GUI/guiSettingsVolume.8.xml");
    gui2->loadSettings("GUI/guiSettingsAudio1.8.xml");
    gui3->loadSettings("GUI/guiSettingsAudio2.8.xml");
    gui4->loadSettings("GUI/guiSettingsAudio3.8.xml");
    gui5->loadSettings("GUI/guiSettingsAudio4.8.xml");
    tween1->trigger2();
    tween2->trigger2();
    tween3->trigger2();
    tween4->trigger2();
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
void Gui::setPanPosition1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("PanPos1");
    slider->setValue(_value1);
    audioSample1->pan = slider->getScaledValue();
}
void Gui::setPanPosition2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("PanPos2");
    slider->setValue(_value1);
    audioSample2->pan = slider->getScaledValue();
}
void Gui::setPanPosition3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("PanPos3");
    slider->setValue(_value1);
    audioSample3->pan = slider->getScaledValue();
}
void Gui::setPanPosition4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("PanPos4");
    slider->setValue(_value1);
    audioSample4->pan = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setPanLfoSpeed1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("PanLfoSpeed1");
    slider->setValue(_value1);
    audioSample1->panLfoSpeed = slider->getScaledValue();
}
void Gui::setPanLfoSpeed2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("PanLfoSpeed2");
    slider->setValue(_value1);
    audioSample2->panLfoSpeed = slider->getScaledValue();
}
void Gui::setPanLfoSpeed3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("PanLfoSpeed3");
    slider->setValue(_value1);
    audioSample3->panLfoSpeed = slider->getScaledValue();
}
void Gui::setPanLfoSpeed4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("PanLfoSpeed4");
    slider->setValue(_value1);
    audioSample4->panLfoSpeed = slider->getScaledValue();
}

//--------------------------------------------------------------
void Gui::setPanLfoAmp1(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui2->getWidget("PanLfoAmp1");
    slider->setValue(_value1);
    audioSample1->panLfoAmp = slider->getScaledValue();
}
void Gui::setPanLfoAmp2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("PanLfoAmp2");
    slider->setValue(_value1);
    audioSample2->panLfoAmp = slider->getScaledValue();
}
void Gui::setPanLfoAmp3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("PanLfoAmp3");
    slider->setValue(_value1);
    audioSample3->panLfoAmp = slider->getScaledValue();
}
void Gui::setPanLfoAmp4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("PanLfoAmp4");
    slider->setValue(_value1);
    audioSample4->panLfoAmp = slider->getScaledValue();
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
    //audioSample1->grainLength1 = slider->getScaledValue();
    audioSample1->setGrainSize(slider->getScaledValue());
}
void Gui::setGrainSize2(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui3->getWidget("grainLength2");
    slider->setValue(_value1);
//    audioSample2->grainLength1 = slider->getScaledValue();
    audioSample2->setGrainSize(slider->getScaledValue());

}
void Gui::setGrainSize3(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui4->getWidget("grainLength3");
    slider->setValue(_value1);
  //  audioSample3->grainLength1 = slider->getScaledValue();
    audioSample3->setGrainSize(slider->getScaledValue());

}
void Gui::setGrainSize4(float _value1){
    ofxUISlider *slider = (ofxUISlider *) gui5->getWidget("grainLength4");
    slider->setValue(_value1);
  //  audioSample4->grainLength1 = slider->getScaledValue();
    audioSample4->setGrainSize(slider->getScaledValue());

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
