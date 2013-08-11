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

    //Harmonic Motion
    grainSizeMotion1.setup(0.025,0.49);
    speedMotion.setup(-2.0, 2.0);
}


//--------------------------------------------------------------
void HarmonicMotion::update(){
    
    grainSizeMotion1.calculate(ofMap(mLivid->knobsB3[1],0,127,0.025,0.49), mLivid->knobsB1[1], mLivid->knobsB1[0], 126);
    gui->setGrainSize1(grainSizeMotion1.value1());

}
