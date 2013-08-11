//
//  guiSampleLoad.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 11/08/13.
//
//

#include "guiSampleLoad.h"

//-------------------------------------------------------------
GuiSampleLoad::~GuiSampleLoad() {
    delete guiSample1;
    delete guiSample2;
    delete guiSample3;
    delete guiSample4;
}

//--------------------------------------------------------------
void GuiSampleLoad::setup(AudioSampler *_audioSample1, AudioSampler *_audioSample2, AudioSampler *_audioSample3, AudioSampler *_audioSample4)
{
    curPreset = 1;
    guiOffset = 0;
    int guiWidth = 15;
    int guiCanvasLength = 50;
    
    audioSample1 = _audioSample1;
    audioSample2 = _audioSample2;
    audioSample3 = _audioSample3;
    audioSample4 = _audioSample4;
    
    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    float tempGUIoffset = 180;
    
    // DRUM
    guiSample1 = new ofxUICanvas(10+(length+xInit),guiOffset,length+xInit*2.0,guiCanvasLength);
    guiSample1->addWidgetDown(new ofxUILabel("LOAD 1", OFX_UI_FONT_SMALL));    
    matrix1 = (ofxUIToggleMatrix*) guiSample1->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 6, "load 1"));// "AV MATRIX"));
    matrix1->setToggle(0, 0, true);
  	guiSample1->addWidgetDown(new ofxUISpacer(length, 2));
    
        // SINGING BOWLS
    guiSample2 = new ofxUICanvas(10+(length+xInit)*2.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    guiSample2->addWidgetDown(new ofxUILabel("LOAD 2", OFX_UI_FONT_SMALL));
    matrix2 = (ofxUIToggleMatrix*) guiSample2->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 6, "load 2"));// "AV MATRIX"));
    matrix2->setToggle(0, 0, true);
  	guiSample2->addWidgetDown(new ofxUISpacer(length, 2));
        
    // THROAT SINGING
    guiSample3 = new ofxUICanvas(10+(length+xInit)*3.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    guiSample3->addWidgetDown(new ofxUILabel("LOAD 3", OFX_UI_FONT_SMALL));
    matrix3 = (ofxUIToggleMatrix*) guiSample3->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 6, "load 3"));// "AV MATRIX"));
    matrix3->setToggle(0, 0, true);
    guiSample3->addSpacer(length, dim/5);
    
        // ICAROS
    guiSample4 = new ofxUICanvas(10+(length+xInit)*4.0,guiOffset,length+xInit*2.0,guiCanvasLength);
    guiSample4->addWidgetDown(new ofxUILabel("LOAD 4", OFX_UI_FONT_SMALL));
    matrix4 = (ofxUIToggleMatrix*) guiSample4->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 6, "load 4"));// "AV MATRIX"));
    matrix4->setToggle(0, 0, true);
    guiSample4->addSpacer(length, dim/5);
    
    //Listener
    ofAddListener(guiSample1->newGUIEvent, this, &GuiSampleLoad::guiEvent);
    ofAddListener(guiSample2->newGUIEvent, this, &GuiSampleLoad::guiEvent);
    ofAddListener(guiSample3->newGUIEvent, this, &GuiSampleLoad::guiEvent);
    ofAddListener(guiSample4->newGUIEvent, this, &GuiSampleLoad::guiEvent);
   
    
    //Padding
    guiSample1->setDrawPadding(true);
    guiSample2->setDrawPadding(true);
    guiSample3->setDrawPadding(true);
    guiSample4->setDrawPadding(true);

    
    //XML preset loading

    
}


//--------------------------------------------------------------
void GuiSampleLoad::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	
    /***********
	 * AV MATRIX
	 *////////////
    
    //Get the Value for each toggle
    if(ofIsStringInString(e.widget->getName(), "load 1"))  /// this is the name of the matrix you want to grab events...
    {
        vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
        row[0] = res[0];
        col[0] = res[1];
        val[0] = (bool) res[2];
        
        cout << "row = " << row[0] << "col = " << col[0] << "val = " << val[0] << endl;
    }
    else if(ofIsStringInString(e.widget->getName(), "load 2"))
    {
        vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
        row[1] = res[0];
        col[1] = res[1];
        val[1] = (bool) res[2];
    }
    else if(ofIsStringInString(e.widget->getName(), "load 3"))
    {
        vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
        row[2] = res[0];
        col[2] = res[1];
        val[2] = (bool) res[2];
    }
    else if(ofIsStringInString(e.widget->getName(), "load 4"))
    {
        vector<int> res =  getToggleMatrixValues(e.widget->getName(), e);
        row[3] = res[0];
        col[3] = res[1];
        val[3] = (bool) res[2];
    }
    
    
    
    //SAMPLE LOAD PLAYER 1
    if(row[0]==0 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("ayahuasca.wav");
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
        matrix1->setToggle(5, 0, false);
    } else if(row[0]==1 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("ayahuasca2.wav");
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
        matrix1->setToggle(5, 0, false);
    } else if(row[0]==2 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("ayahuasca3.wav");
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
        matrix1->setToggle(5, 0, false);
    } else if(row[0]==3 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("icaros1.wav");
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(4, 0, false);
        matrix1->setToggle(5, 0, false);
    } else if(row[0]==4 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("icaros2.wav");
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(5, 0, false);
    } else if(row[0]==5 && col[0]==0 && val[0]==1){
        audioSample1->clear1();
        audioSample1->load1("shamanic_drum_short.wav");
        matrix1->setToggle(0, 0, false);
        matrix1->setToggle(1, 0, false);
        matrix1->setToggle(2, 0, false);
        matrix1->setToggle(3, 0, false);
        matrix1->setToggle(4, 0, false);
    }
    
    //SAMPLE LOAD PLAYER 2
    if(row[1]==0 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("ayahuasca.wav");
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
        matrix2->setToggle(5, 0, false);
    } else if(row[1]==1 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("ayahuasca2.wav");
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
        matrix2->setToggle(5, 0, false);
    } else if(row[1]==2 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("ayahuasca3.wav");
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
        matrix2->setToggle(5, 0, false);
    } else if(row[1]==3 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("icaros1.wav");
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(4, 0, false);
        matrix2->setToggle(5, 0, false);
    } else if(row[1]==4 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("icaros2.wav");
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(5, 0, false);
    } else if(row[1]==5 && col[1]==0 && val[1]==1){
        audioSample2->clear1();
        audioSample2->load1("shamanic_drum_short.wav");
        matrix2->setToggle(0, 0, false);
        matrix2->setToggle(1, 0, false);
        matrix2->setToggle(2, 0, false);
        matrix2->setToggle(3, 0, false);
        matrix2->setToggle(4, 0, false);
    }
    
    //SAMPLE LOAD PLAYER 3
    if(row[2]==0 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("singing_bells.wav");
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
        matrix3->setToggle(5, 0, false);
    } else if(row[2]==1 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("ayahuasca2.wav");
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
        matrix3->setToggle(5, 0, false);
    } else if(row[2]==2 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("ayahuasca3.wav");
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
        matrix3->setToggle(5, 0, false);
    } else if(row[2]==3 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("icaros1.wav");
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(4, 0, false);
        matrix3->setToggle(5, 0, false);
    } else if(row[2]==4 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("requiem_1.wav");
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(5, 0, false);
    } else if(row[2]==5 && col[2]==0 && val[2]==1){
        audioSample3->clear1();
        audioSample3->load1("requiem_2.wav");
        matrix3->setToggle(0, 0, false);
        matrix3->setToggle(1, 0, false);
        matrix3->setToggle(2, 0, false);
        matrix3->setToggle(3, 0, false);
        matrix3->setToggle(4, 0, false);
    }
    
    //SAMPLE LOAD PLAYER 4
    if(row[3]==0 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("psychedelics.wav");
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
        matrix4->setToggle(5, 0, false);
    } else if(row[3]==1 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("Whole_Tone_Demented_Rise.wav");
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
        matrix4->setToggle(5, 0, false);
    } else if(row[3]==2 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("CombinationSpawns.wav");
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
        matrix4->setToggle(5, 0, false);
    } else if(row[3]==3 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("Oscillator droplets.wav");
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(4, 0, false);
        matrix4->setToggle(5, 0, false);
    } else if(row[3]==4 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("endless_rise.wav");
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(5, 0, false);
    } else if(row[3]==5 && col[3]==0 && val[3]==1){
        audioSample4->clear1();
        audioSample4->load1("jed_sound1.wav");
        matrix4->setToggle(0, 0, false);
        matrix4->setToggle(1, 0, false);
        matrix4->setToggle(2, 0, false);
        matrix4->setToggle(3, 0, false);
        matrix4->setToggle(4, 0, false);
    }

    
        
}

/*

//--------------------------------------------------------------
void GuiSampleLoad::triggerSynthPreset1(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("1");
    button->setValue(_value1);
    curPreset = 1;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.1.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.1.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset2(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("2");
    button->setValue(_value1);
    curPreset = 2;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.2.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.2.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset3(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("3");
    button->setValue(_value1);
    curPreset = 3;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.3.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.3.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset4(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("4");
    button->setValue(_value1);
    curPreset = 4;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.4.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.4.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset5(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("5");
    button->setValue(_value1);
    curPreset = 5;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.5.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.5.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset6(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("6");
    button->setValue(_value1);
    curPreset = 6;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.6.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.6.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset7(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("7");
    button->setValue(_value1);
    curPreset = 7;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.7.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.7.xml");
    tweenSynth->trigger2();
}
void GuiSampleLoad::triggerSynthPreset8(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("8");
    button->setValue(_value1);
    curPreset = 8;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.8.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.8.xml");
    tweenSynth->trigger2();
}

 */

//--------------------------------------------------------------
vector<int> GuiSampleLoad::getToggleMatrixValues(string received_name , ofxUIEventArgs &e){
    
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
    
    //   cout << vresult[0] << " " <<vresult[1] <<" " << vresult[2] << endl;
    
    return vresult;
    
}

//--------------------------------------------------------------
void GuiSampleLoad::drawData(){
    
}