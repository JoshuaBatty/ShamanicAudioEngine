//
//  HarmonicMotion.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 4/08/13.
//
//

#include "HarmonicMotion.h"

//--------------------------------------------------------------
void HarmonicMotion::setup(Gui *_gui, livid *_livid){

    gui = _gui;
    mLivid = _livid;
    
    /*
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
    */
    
    //Harmonic Motion
    grainSizeMotion1.setup(0.025,0.49);
    grainSizeMotion2.setup(0.025,0.49);
    grainSizeMotion3.setup(0.025,0.49);
    grainSizeMotion4.setup(0.025,0.49);
    speedMotion.setup(-2.0, 2.0);
}


//--------------------------------------------------------------
void HarmonicMotion::update(){
    
    grainSizeMotion1.calculate(ofMap(mLivid->knobsB3[1],0,127,0.025,0.49), mLivid->knobsB1[1], mLivid->knobsB1[0], 126);
    grainSizeMotion2.calculate(ofMap(mLivid->knobsB3[4],0,127,0.025,0.49), mLivid->knobsB1[4], mLivid->knobsB1[3], 126);
    grainSizeMotion3.calculate(ofMap(mLivid->knobsB3[7],0,127,0.025,0.49), mLivid->knobsB1[7], mLivid->knobsB1[6], 126);
    grainSizeMotion4.calculate(ofMap(mLivid->knobsB3[10],0,127,0.025,0.49), mLivid->knobsB1[10], mLivid->knobsB1[9], 126);
    gui->setGrainSize1(grainSizeMotion1.value1());
    gui->setGrainSize2(grainSizeMotion2.value1());
    gui->setGrainSize3(grainSizeMotion3.value1());
    gui->setGrainSize4(grainSizeMotion4.value1());
    /*
    speedMotion.calculate(1.0, .020, 2.0, 4.0);
    gui->setSpeed1(speedMotion.value1());
    gui->setSpeed2(speedMotion.value2());
    gui->setSpeed3(speedMotion.value3());
    gui->setSpeed4(speedMotion.value4());
    */
}
