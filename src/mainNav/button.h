/*
 *  button.h
 *  Created by Ryan Raffa on 5/5/13.
 *
 */
#ifndef _button
#define _button


#include "ofMain.h"

class button {
	
public:
    void setup(ofTrueTypeFont& basicFont, ofPoint pos, ofPoint size, string thisString, ofColor thisColor);
    void update();
    void draw();
    
    //tracking touch events
    void touchingDown(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    
    //buttons
    ofRectangle    thisRectangle;
    
    //button color
    ofColor        thisColor;
    
    //text for buttons
    ofTrueTypeFont* basicFont;                           //  Font used. May need to address alternative sizes.
    
    string          thisString;
    
    // used for touch fields on settings
    bool            touching;
    bool            selected;
    
    //used to shift the settings window around
    ofPoint         pos;
    
    
};

#endif
