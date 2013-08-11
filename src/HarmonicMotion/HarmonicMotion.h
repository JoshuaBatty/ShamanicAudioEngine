//
//  HarmonicMotion.h
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 4/08/13.
//
//

#pragma once

#include "ofMain.h"
#include "Wave.h"
#include "gui.h"
#include "livid.h"

class HarmonicMotion{
public:
    
    void setup(Gui *_gui, livid *_livid);
    void update();
    
    Gui *gui;
    livid *mLivid;
    
    //Harmonic Motion
    Wave grainSizeMotion1;
    Wave pitchMotion;
    Wave speedMotion;
};
