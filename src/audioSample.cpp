//
//  audio.cpp
//  emptyExample
//
//  Created by Joshua Batty on 21/02/13.
//
//

#include "audioSample.h"

//-------------------------------------------------------------
AudioSampler::~AudioSampler() {
	delete stretches1;
	delete stretches2;
	delete stretches3;
	delete stretches4;
	delete stretches5;
}

//--------------------------------------------------------------
void AudioSampler::setSampleRate( int rate )
{
	sampleRate = rate;
}

//--------------------------------------------------------------
void AudioSampler::setup(string _file)
{
	/* This is stuff you always need.*/
	sampleRate 			= 44100; /* Sampling Rate */
	initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
	volume				= 0.009f;

   // ofSetDataPathRoot(_file);
    //samples
    samp1.load(ofToDataPath(_file));
//	samp1.load(_file);
    stretches1 = new maxiPitchStretch<grainPlayerWin1>(&samp1);
    stretches2 = new maxiPitchStretch<grainPlayerWin2>(&samp1);
    stretches3 = new maxiPitchStretch<grainPlayerWin3>(&samp1);
    stretches4 = new maxiPitchStretch<grainPlayerWin4>(&samp1);	
    stretches5 = new maxiPitchStretch<grainPlayerWin5>(&samp1);

	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);


    bReverb = true;
    bFilter = false;
    bPan = false;
    bFx = false;
    
    bScrub = false;
	startAudio = true;
	playPosition = 0;
	current = 0;
    
    leftScale = 0.5;
    rightScale = -0.5;
    pan = 0.5;
    panLfoSpeed = 0.0;
    panLfoAmp = 1.0;
    
    //grains
    pitch1 = 1.0;
    speed1 = 1.0;
    grainLength1 = 0.25;
    overlaps1 = 3.0;
    randomGrainPitch1 = 0.0;
    randomGrainSize1 = 0.0;
    
    //delay
    delayTime1 = 10.0f;
    delayFeedback1 = 0.10f;
    
    //cutoff
    cutoff1 = 10000.0;
    
    //crush
    bits = 32;
    rate = 0.5;
    
    //Reverb
    reverbDamp = 0.1;
    reverbWidth = 0.99;
    
    //ofEvents listener setup
    //ofAddListener(ofEvents().update, this, &AudioSampler::reverb(1.0,1.0);

}

//--------------------------------------------------------------
void AudioSampler::load1(string _file)
{
    //samples
	samp1.load(_file);
//	samp1.load(_file + ".wav");
}

//--------------------------------------------------------------
void AudioSampler::setGrainWindow(int _windowType)
{
    current = _windowType;
}
//--------------------------------------------------------------
void AudioSampler::clear1()
{
    samp1.reset();
    samp1.clear();
}

//--------------------------------------------------------------
void AudioSampler::updateParams(float _pitch1, float _speed1, float _grainLength1, float _overlaps1, float _randomGrainPitch1, float _randomGrainSize1)
{
    pitch1 = _pitch1;
    speed1 = _speed1;
    grainLength1 = _grainLength1;
    overlaps1 = _overlaps1;
    randomGrainPitch1 = _randomGrainPitch1;
    randomGrainSize1 = _randomGrainSize1;
}

//--------------------------------------------------------------
void AudioSampler::setFilter(float _cutoff, float _lfoSpeed1, float _lfoAmp1)
{
    cutoff1 = _cutoff;
    
	//LFO's
	LFO1out = LFO1.sinebuf(ofGetElapsedTimef()*_lfoSpeed1);
	LFO1out = (LFO1out+1)*_lfoAmp1;//filter1 cutoff
}

//--------------------------------------------------------------
void AudioSampler::setPosition(float _playPosition)
{
	playPosition = _playPosition;
}

//--------------------------------------------------------------
void AudioSampler::delay(float _delayTime, float _delayFeedback)
{
	delayTime1 = _delayTime;
    delayFeedback1 = _delayFeedback;
}

//--------------------------------------------------------------
void AudioSampler::decimate(int _bits1, float _rate1)
{
	//update decimate values
	crush1.setValues(_bits1,_rate1);
}

//--------------------------------------------------------------
void AudioSampler::reverb(float _wetness1, float _roomSize1)
{	
	reverb1.setroomsize(_roomSize1);
	reverb1.setwet(_wetness1);
	reverb1.setdry(1.0f - _wetness1);
	reverb1.setdamp(reverbDamp);
	reverb1.setwidth(reverbWidth);
    
}

//--------------------------------------------------------------
void AudioSampler::setPanning(float _panPos, float _lfoSpeed, float _lfoAmp)
{
    pan = _panPos;
    panLfoSpeed = _lfoSpeed;
    panLfoAmp = _lfoAmp;
    
    //FIX THE LFO AMP BUG
    leftScale = ofMap(((1- sin(ofGetFrameNum()*panLfoSpeed)/2) - pan),0.0,1.0,0.0,1.0);//pan-(_lfoAmp*-1.0),pan+_lfoAmp);
	rightScale = ((sin(ofGetFrameNum()*panLfoSpeed)/2) + pan);// _lfoAmp;
    
//    leftScale = ((1- sin(ofGetFrameNum()*_lfoSpeed)/2) - pan);// _lfoAmp;
//	rightScale = ((sin(ofGetFrameNum()*_lfoSpeed)/2) + pan);// _lfoAmp;
    
//    leftScale = (1- sin(ofGetFrameNum()*_lfoSpeed)/2) - 0.5;
//	rightScale = (sin(ofGetFrameNum()*_lfoSpeed)/2) + 0.5;

 //   cout << "rightscale = " << rightScale << endl;
 //   cout << "leftscale = " << leftScale << endl;
}

//--------------------------------------------------------------
void AudioSampler::setGrainSize(float _grainSize){
    grainLength1 = _grainSize;
}

//--------------------------------------------------------------
void AudioSampler::draw(int _x, int _y)
{
    int width = 200;
    
    ofSetColor(255,0,0);
    ofNoFill();
    ofRect(_x, _y, width, 40);
    
    ofSetColor(255);
    ofFill();
    ofRect(_x+(pan*width), _y, ofMap(leftScale,0.0,1.0,-width/2,width/2), 40);
}
//--------------------------------------------------------------
void AudioSampler::audioRequested (float * output, int numFrames, int nChannels)
{

		for (int i = 0; i < numFrames; i++){
          //  stretches1[current]->setPosition(playPosition);
            switch (current) {
                case 0:
                    wave1 = stretches1->play(&windowAmp1,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches2->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches3->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches4->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches5->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    break;
                    
                case 1:
                    wave1 = stretches2->play(&windowAmp1,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches1->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches3->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches4->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches5->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    break;
                    
                case 2:
                    wave1 = stretches3->play(&windowAmp1,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches1->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches2->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches4->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches5->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    break;
                    
                case 3:
                    wave1 = stretches4->play(&windowAmp1,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches1->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches2->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches3->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches5->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    break;
                    
                case 4:
                    wave1 = stretches5->play(&windowAmp1,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches1->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches2->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches3->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    stretches4->play(&windowAmpDummy,(pitch1*(ofRandom(randomGrainPitch1)+1)), speed1, ofClamp(grainLength1+randomGrainSize1,0.025,0.49), overlaps1);
                    break;
                    
                default:
                    break;
            }
            
            //Add some juicy DSP
			DELAY1out = DELAY1.dl(wave1,delayTime1,delayFeedback1);
            
            VCF1out=VCF1.lores(DELAY1out+wave1,cutoff1+LFO1out, 1.0f);
            
            CRUSH1out=crush1.decimate(VCF1out);
			
            //REVERB
			float left1 = (CRUSH1out) * leftScale;
			float right1 = (CRUSH1out) * rightScale;
            
			REVERB1out=reverb1.process(&left1, &right1, 1, 1)*volume;

			//play result
            mymix.stereo(REVERB1out, outputs, 0.5/3.0);

         //   cout << "myMix = " << OSCout+REVERB1out << endl;

			output[i*nChannels    ] = outputs[0] * volume * leftScale; /* You may end up with lots of outputs. add them here */
			output[i*nChannels + 1] = outputs[1] * volume * rightScale;

		}		
}
