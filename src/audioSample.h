//
//  audio.h
//  emptyExample
//
//  Created by Joshua Batty on 21/02/13.
//
//


#pragma once

#include "ofSoundUnit.h"
#include "ofMain.h"
#include "ofxMaxim.h"
#include "maxiGrains.h"
#include <sys/time.h>
#include "time.h"			// Need by maxi to do granular stuff.....not sure if i need it in my testApp though
#include "ofxDSP.h"         //Custom DSP librray that contains reverb and decimate functions

typedef gaussianWinFunctor grainPlayerWin1;
typedef cosineWinFunctor grainPlayerWin2;
typedef triangleWinFunctor grainPlayerWin3;
typedef rectWinFunctor grainPlayerWin4;
typedef blackmanHarrisWinFunctor grainPlayerWin5;

class AudioSampler : public ofSoundSource{
	
	public :
	~AudioSampler();/* deconsructor is very useful */
	void setup(string _file);
	void setPosition(float _playPosition);
	void setFilter(float _cutoff, float _lfoSpeed1, float _lfoAmp1);
    void delay(float _delayTime, float _delayFeedback);
	void decimate(int _bits1, float _rate1);
	void reverb(float _wetness1, float _roomSize1);
	void setPanning(float _panPos, float _lfoSpeed, float _lfoAmp);
    void updateParams(float _pitch1, float _speed1, float _grainLength1, float _overlaps1, float _randomGrainPitch1, float _randomGrainSize1);
    
    void draw(int _x, int _y);
    
    //Need these three methods.
    void audioRequested (float * output, int numFrames, int nChannels);
    void setSampleRate( int rate );
	string getName() { return "soundSourceGranular"; }

    void load1(string _file);

	void clear1();

    double windowAmp1;
    double windowAmpDummy;

//	private :
	int		initialBufferSize; /* buffer size */
	int		sampleRate;

	float volume;
    float rightScale, leftScale;
    float pan;
    float panLfoSpeed, panLfoAmp;
	
    bool bReverb;
    bool bFilter;
    bool bPan;
    bool bFx;
    
	/* stick your maximilian stuff below */
	
	float playPosition;
	double wave1;
	double outputs[2];

    //GRANULAR
	maxiSample samp1; //Variables to play the samples
	
    maxiPitchStretch<grainPlayerWin1> *stretches1;
    maxiPitchStretch<grainPlayerWin2> *stretches2;
    maxiPitchStretch<grainPlayerWin3> *stretches3;
    maxiPitchStretch<grainPlayerWin4> *stretches4;
    maxiPitchStretch<grainPlayerWin5> *stretches5;
	maxiMix mymix;

	int counter;
	bool startAudio;
    bool bScrub;
    
    //Grain varibales
    float pitch1;
    float randomGrainPitch1;
    float randomGrainSize1;
    float speed1;
    float grainLength1;
    float overlaps1;
    
	//new variables
	int	  current;
	
	//DSP VARIABlES
	//Filter
	ofxMaxiFilter VCF1;
	double VCF1out;
    float cutoff1;
	
	//Delay
	ofxMaxiDelayline DELAY1;
	double DELAY1out;
    float delayTime1;
    float delayFeedback1;
	
	//FILTER LFO's
	ofxMaxiOsc LFO1;
	double LFO1out;
	float lfoAmp1;
	float lfoSpeed1;
	
	//GRAIN LFO's
	ofxMaxiOsc LFO4;
	double LFO4out;
	float grainLFO;
	float lfoAmp4;
	float lfoSpeed4;
	
	//OFX DSP Stuff
	
	//Reverb
	ofxReverb	reverb1;
	float REVERB1out;
	float reverbSize;
    float reverbDryWet;
    float reverbDamp;
    float reverbWidth;
    
	//Crush
	ofxCrush	crush1;
	double CRUSH1out;
    int bits;
    float rate;

};
