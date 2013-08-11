/*
 *  crush.cpp
 *  decimatorExample
 *
 *  Created by Joshua Batty on 8/06/12.
 *  Copyright 2012 BMP. All rights reserved.
 *
 */
#include "crush.h"

void crush::setValues(int _bits, float _rate){
	bits = _bits;
	rate = _rate;
}

float crush::decimate(float i)
{
	float quantum = powf( 2.0f, bits );
	
	m = 1<<(bits-1);
	
	cnt+=rate;
	if(cnt>=1){
		cnt-=1;
		
		//SMOOTH
		//	y = floorf( i * quantum ) / quantum;
		//STEP
		y=(long int)(i*m)/(float)m;
	}
	return y;
}