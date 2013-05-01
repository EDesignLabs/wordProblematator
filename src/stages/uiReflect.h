/*
 *  uiReflect.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _uiReflect
#define _uiReflect


#include "ofMain.h"

#include "button.h"
#include "drawing.h"
#include "image.h"
#include "text.h"

class uiReflect {
	
	public:
    
        uiReflect();
        ~uiReflect();
    
        void setPoints(vector <drawing> theDrawings);
		void update();
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
        void exit();

        //This is the drawing that is tracked and then pushed on the stack
        vector <drawing> drawThese;
    
        int              startTime;
        int              endTime;
    
        //uiReflect
        button*          scrubBox;
        ofPoint*         scrubLocation;
        ofPoint*         scrubPos;
    

    
};

#endif
