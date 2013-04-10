/*
 *  mathOne.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _mathOne
#define _mathOne


#include "ofMain.h"
#include "ofxUI.h"
#include "drawing.h"
#include "image.h"
#include "text.h"


class mathOne {
	
	public:
    
        mathOne();
        ~mathOne();
    
		void update();
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
        void exit();

        vector <ofPoint> currentDrawing;
        
        //This is the drawing that is tracked and then pushed on the stack
        vector <drawing> drawThese;
        drawing thisDrawing;

        image thisImage;
        text* thisText;

        bool doText;
        bool doDrawing;
        bool doImage;
    
        char eventString[255];
        char timeString[255];
    
        //for text
        string theText;
    
        //UI
        ofxUICanvas *gui;
        void guiEvent(ofxUIEventArgs &e);

    
};

#endif
