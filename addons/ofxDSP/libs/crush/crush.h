/*
 *  Crush.h
 *  DecimatorExample
 *
 *  Created by Joshua Batty on 8/06/12.
 *  Copyright 2012 BMP. All rights reserved.
 *
 */

#ifndef _OFCRUSH_H
#define _OFCRUSH_H

//--------------------------------------------------------------
class crush
{
	public:
		crush()
		{
			bits = 16;
			rate = 0.5;
			y = 0;
			cnt = 0;
		}
	
		//DECIMATOR
		float decimate(float i);
		void  setValues(int bits, float rate);
	
		int bits;	
		float rate;
		long int m;
		float y, cnt;
};

#endif
