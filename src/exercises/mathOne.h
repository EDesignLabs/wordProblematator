/*
 *  mathOne.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _mathOne
#define _mathOne


#include "ofMain.h"
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

        char eventString[255];
        char timeString[255];
    
        //for text
        string theText;
    
        //UI
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
