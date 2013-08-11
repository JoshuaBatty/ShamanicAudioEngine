//
//  guiBinaural.cpp
//  ShamanicAudioEngine
//
//  Created by Joshua Batty on 1/08/13.
//
//

#include "guiBinaural.h"


//-------------------------------------------------------------
GuiBinaural::~GuiBinaural() {
    delete guiBinaural;
    delete guiTonic;
    delete guiPresets;
}

//--------------------------------------------------------------
void GuiBinaural::setup(TweenSynth *_tweenSynth, AudioBinaural *_audioBinaural, AudioTonic *_audioTonic)
{
    curPreset = 1;
    guiOffset = 50;
    int guiWidth = 15;
    int guiCanvasLength = 690;
    
    tweenSynth = _tweenSynth;
    audioTonic = _audioTonic;
    audioBinaural = _audioBinaural;

    float dim = 16;
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    float tempGUIoffset = 180;
    
    //BINARUAL
    guiBinaural = new ofxUICanvas(0,0,length+xInit*2.0,180+tempGUIoffset);
    guiBinaural->addWidgetDown(new ofxUILabel("SHAMANIC AUDIO ENGINE", OFX_UI_FONT_MEDIUM));
    guiBinaural->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    guiBinaural->addSpacer(length, dim/5);
    
    guiBinaural->addLabel("BINARUAL");
    guiBinaural->addWidgetDown(new ofxUIRotarySlider(guiWidth*3, 30.0, 300.0, audioBinaural->osc1Pitch,"CarrierPitch"));
    guiBinaural->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 14.0, audioBinaural->osc2Pitch,"CarrierOffset"));
    guiBinaural->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 1.0, audioBinaural->volume,"Binaural_B"));
    //guiBinaural->addSlider("Binaural_B", 0.0, 1.0, audioBinaural->volume, 270, guiWidth);
    guiBinaural->addSpacer(length, dim/5);
    
    guiTonic = new ofxUICanvas(0,143,length+xInit*2.0,220);
    guiTonic->addLabel("FM SUB");

    guiTonic->addWidgetDown(new ofxUIRotarySlider(guiWidth*3, 0.0, 10.0, audioTonic->CarrierPitch,"carrierPitch"));
    guiTonic->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 10.0, audioTonic->CarrierOffset,"carrierOffset"));
    guiTonic->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, -60.0, 0.0, audioTonic->Volume,"volume"));
    
    guiTonic->addWidgetDown(new ofxUIRotarySlider(guiWidth*3, 0.001, 10.0, audioTonic->ModIndex,"modIndex"));
    guiTonic->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 4.0, audioTonic->ModLfoAmt,"modLfoAmt"));
    guiTonic->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 20.0, audioTonic->ModLfoSpeed,"modLfoSpeed"));
    
    guiTonic->addWidgetDown(new ofxUIRotarySlider(guiWidth*3, 0.0, 1.0, audioTonic->AmpLfoAmt,"ampLfoAmt"));
    guiTonic->addWidgetRight(new ofxUIRotarySlider(guiWidth*3, 0.0, 20.0, audioTonic->AmpLfoSpeed,"ampLfoSpeed"));
    guiTonic->addSpacer(length, dim/5);

    
    //PRESETS
    guiPresets = new ofxUICanvas(0,380+tempGUIoffset,length+xInit*2.0,guiCanvasLength-380);
    guiPresets->addWidgetDown(new ofxUILabel("SYNTH PRESETS", OFX_UI_FONT_MEDIUM));
    guiPresets->addWidgetDown(new ofxUISpacer(length, 2));
    guiPresets->addLabelButton("SAVE PRESET", true, length-xInit);
    
    vector<string> hnames; hnames.push_back("1"); hnames.push_back("2"); hnames.push_back("3"); hnames.push_back("4"); hnames.push_back("5"); hnames.push_back("6"); hnames.push_back("7"); hnames.push_back("8");
    ofxUIRadio *radio = (ofxUIRadio *) guiPresets->addWidgetDown(new ofxUIRadio(dim, dim, "PRESET SELECT", hnames, OFX_UI_ORIENTATION_HORIZONTAL));
    radio->activateToggle("PRESETS");
    
    guiPresets->addWidgetDown(new ofxUILabel("DELAY", OFX_UI_FONT_MEDIUM));
    guiPresets->addWidgetRight(new ofxUINumberDialer(0, 10000, 2, 1, "TWEEN_DURATION", OFX_UI_FONT_MEDIUM));
    
    guiPresets->addWidgetDown(new ofxUILabel("Tween Shape -", OFX_UI_FONT_MEDIUM));
    //  gui2->addWidgetRight(new ofxUILabel("circ", OFX_UI_FONT_SMALL));
    
    matrixTween = (ofxUIToggleMatrix*) guiPresets->addWidgetRight(new ofxUIToggleMatrix(dim*2, dim*2, 1, 5, "linr1 expo circ  bnce xtic"));// "AV MATRIX"));
    
    matrixTween->setToggle(0, 0, true);
  	guiPresets->addWidgetDown(new ofxUISpacer(length, 2));
    
    guiPresets->setVisible(true);
    
    //Listener
    ofAddListener(guiBinaural->newGUIEvent, this, &GuiBinaural::guiEvent);
    ofAddListener(guiTonic->newGUIEvent, this, &GuiBinaural::guiEvent);
    ofAddListener(guiPresets->newGUIEvent, this, &GuiBinaural::guiEvent);

    
    //Padding
    guiBinaural->setDrawPadding(true);
    guiPresets->setDrawPadding(true);
    guiTonic->setDrawPadding(true);
    
    //XML preset loading
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.0.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.0.xml");
    
        
}


//--------------------------------------------------------------
void GuiBinaural::guiEvent(ofxUIEventArgs &e)
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

    
    
    //TWEEN SHAPE
    if(row[0]==0 && col[0]==0 && val[0]==1){
        tweenSynth->setEasingType(1);
        matrixTween->setToggle(1, 0, false);
        matrixTween->setToggle(2, 0, false);
        matrixTween->setToggle(3, 0, false);
        matrixTween->setToggle(4, 0, false);
    } else if(row[0]==1 && col[0]==0 && val[0]==1){
        tweenSynth->setEasingType(1);
        matrixTween->setToggle(0, 0, false);
        matrixTween->setToggle(2, 0, false);
        matrixTween->setToggle(3, 0, false);
        matrixTween->setToggle(4, 0, false);
    } else if(row[0]==2 && col[0]==0 && val[0]==1){
        tweenSynth->setEasingType(1);
        matrixTween->setToggle(0, 0, false);
        matrixTween->setToggle(1, 0, false);
        matrixTween->setToggle(3, 0, false);
        matrixTween->setToggle(4, 0, false);
    } else if(row[0]==3 && col[0]==0 && val[0]==1){
        tweenSynth->setEasingType(1);
        matrixTween->setToggle(0, 0, false);
        matrixTween->setToggle(1, 0, false);
        matrixTween->setToggle(2, 0, false);
        matrixTween->setToggle(4, 0, false);
    } else if(row[0]==4 && col[0]==0 && val[0]==1){
        tweenSynth->setEasingType(1);
        matrixTween->setToggle(0, 0, false);
        matrixTween->setToggle(1, 0, false);
        matrixTween->setToggle(2, 0, false);
        matrixTween->setToggle(3, 0, false);
    }
    
    
    
    //PRESET SAVING
    if(name == "SAVE PRESET" && curPreset == 1){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.1.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.1.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 2){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.2.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.2.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 3){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.3.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.3.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 4){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.4.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.4.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 5){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.5.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.5.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 6){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.6.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.6.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 7){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.7.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.7.xml");
    }
    else if(name == "SAVE PRESET" && curPreset == 8){
        guiBinaural->saveSettings("GUI/guiSettingsBinaural1.8.xml");
        guiTonic->saveSettings("GUI/guiSettingsTonic1.8.xml");
    }
    
    
    else if(name == "1"){
        curPreset = 1;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.1.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.1.xml");
        tweenSynth->trigger2();
	}
    else if(name == "2"){
        curPreset = 2;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.2.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.2.xml");
        tweenSynth->trigger2();
	}
    else if(name == "3"){
        curPreset = 3;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.3.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.3.xml");
        tweenSynth->trigger2();
	}
    else if(name == "4"){
        curPreset = 4;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.4.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.4.xml");
        tweenSynth->trigger2();
	}
    else if(name == "5"){
        curPreset = 5;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.5.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.5.xml");
        tweenSynth->trigger2();
	}
    else if(name == "6"){
        curPreset = 6;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.6.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.6.xml");
        tweenSynth->trigger2();
	}
    else if(name == "7"){
        curPreset = 7;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.7.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.7.xml");
        tweenSynth->trigger2();
	}
    else if(name == "8"){
        curPreset = 8;
        tweenSynth->catchTempVariables();
        guiBinaural->loadSettings("GUI/guiSettingsBinaural1.8.xml");
        guiTonic->loadSettings("GUI/guiSettingsTonic1.8.xml");
        tweenSynth->trigger2();
	}
    
    else if(name == "TWEEN_DURATION"){
        ofxUINumberDialer *number = (ofxUINumberDialer *) e.widget;
        tweenSynth->duration = number->getValue();
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

    
     //FM SUB MACHINE
    if(name == "carrierPitch")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->CarrierPitch = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name== "carrierOffset")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->CarrierOffset = slider->getScaledValue();
        audioTonic->triggerFMparams();
    }
    else if(name == "modIndex")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->ModIndex = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name == "modLfoAmt")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->ModLfoAmt = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name == "modLfoSpeed")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->ModLfoSpeed = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name == "ampLfoAmt")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->AmpLfoAmt = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name == "ampLfoSpeed")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->AmpLfoSpeed = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    else if(name == "volume")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		audioTonic->Volume = slider->getScaledValue();
        audioTonic->triggerFMparams();
	}
    
}

//--------------------------------------------------------------
void GuiBinaural::triggerSynthPreset1(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("1");
    button->setValue(_value1);
    curPreset = 1;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.1.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.1.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset2(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("2");
    button->setValue(_value1);
    curPreset = 2;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.2.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.2.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset3(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("3");
    button->setValue(_value1);
    curPreset = 3;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.3.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.3.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset4(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("4");
    button->setValue(_value1);
    curPreset = 4;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.4.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.4.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset5(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("5");
    button->setValue(_value1);
    curPreset = 5;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.5.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.5.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset6(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("6");
    button->setValue(_value1);
    curPreset = 6;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.6.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.6.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset7(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("7");
    button->setValue(_value1);
    curPreset = 7;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.7.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.7.xml");
    tweenSynth->trigger2();
}
void GuiBinaural::triggerSynthPreset8(int _value1){
    ofxUILabelButton *button = (ofxUILabelButton *) guiPresets->getWidget("8");
    button->setValue(_value1);
    curPreset = 8;
    tweenSynth->catchTempVariables();
    guiBinaural->loadSettings("GUI/guiSettingsBinaural1.8.xml");
    guiTonic->loadSettings("GUI/guiSettingsTonic1.8.xml");
    tweenSynth->trigger2();
}
//--------------------------------------------------------------
void GuiBinaural::setBinVolume(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("Binaural_B");
    slider->setValue(_value1);
    audioBinaural->volume = slider->getScaledValue();
}
void GuiBinaural::setBinPitch(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("CarrierPitch");
    slider->setValue(_value1);
    audioBinaural->osc1Pitch = slider->getScaledValue();
}
void GuiBinaural::setBinOffset(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiBinaural->getWidget("CarrierOffset");
    slider->setValue(_value1);
    audioBinaural->osc2Pitch = slider->getScaledValue();
}

//--------------------------------------------------------------
void GuiBinaural::setSynthVolume(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("volume");
    slider->setValue(_value1);
    audioTonic->Volume = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthCarrierPitch(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("carrierPitch");
    slider->setValue(_value1);
    audioTonic->CarrierOffset = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthCarrierOffset(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("carrierOffset");
    slider->setValue(_value1);
    audioTonic->CarrierOffset = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthModIndex(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("modIndex");
    slider->setValue(_value1);
    audioTonic->ModIndex = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthModLfoAmt(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("modLfoAmt");
    slider->setValue(_value1);
    audioTonic->ModLfoAmt = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthModLfoSpeed(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("modLfoSpeed");
    slider->setValue(_value1);
    audioTonic->ModLfoSpeed = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthAmpLfoAmt(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("ampLfoAmt");
    slider->setValue(_value1);
    audioTonic->AmpLfoAmt = slider->getScaledValue();
    audioTonic->triggerFMparams();
}
void GuiBinaural::setSynthAmpLfoSpeed(float _value1){
    ofxUISlider *slider = (ofxUISlider *) guiTonic->getWidget("ampLfoSpeed");
    slider->setValue(_value1);
    audioTonic->AmpLfoSpeed = slider->getScaledValue();
    audioTonic->triggerFMparams();
}

//--------------------------------------------------------------
vector<int> GuiBinaural::getToggleMatrixValues(string received_name , ofxUIEventArgs &e){
    
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
void GuiBinaural::drawData(){
    
}
