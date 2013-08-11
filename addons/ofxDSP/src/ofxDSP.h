/*
 *  ofxDSP
 *  created by: Joshua Paris Batty
 *  an addon that ties some juicy open source DSP code that i have found floating around
 *	for openFrameworks.
 *	freeverb the classic *free* reverb code is included as well as a bit reduction effect.
 *  more on the way, trying not to include anything that is covered my exiesting addons
 *  such as Maxi, but please to let me know if you know of any other juicy DSP goodness to 
 *  go in this package.
 */

#ifndef _OFDSP_H
#define _OFDSP_H


#include "revmodel.hpp" //Reverb include
#include "crush.h"		//downSample include

typedef revmodel	ofxReverb;
typedef crush		ofxCrush;

#endif
