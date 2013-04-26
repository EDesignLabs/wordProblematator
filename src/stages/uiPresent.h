/*
 *  uiPresent.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _uiPresent
#define _uiPresent


#include "ofMain.h"
#include "drawing.h"
#include "image.h"
#include "text.h"

#include "ofxRetinaTrueTypeFont.h"


class uiPresent {
	
	public:
    
        uiPresent();
        ~uiPresent();
    
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

        char eventString[255];
        char timeString[255];
    
        //for text
        string theText;
    
        //uiPresent
        ofImage*     pencil;
        ofImage*     font;
        ofImage*     table;
        ofImage*     okSave;

        ofRectangle* pencilBox;
        ofRectangle* fontBox;
        ofRectangle* tableBox;
        ofRectangle* okSaveBox;
    
        bool*   pencilSelected;
        bool*   fontSelected;
        bool*   tableSelected;
        bool*   okSaveSelected;
    

};

#endif
