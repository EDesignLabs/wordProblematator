/*
 *  drawing.cpp
 *
 *  Created by Ryan Raffa on 4/4/13.
 *
 */

#ifndef _drawing
#define _drawing


#include "ofMain.h"

class drawing {
	
	public:
    
        void setup();
        void update(ofTouchEventArgs &touch);
		void draw();
		void reset();
    
        vector <ofPoint> thePoints;
    

};

#endif
