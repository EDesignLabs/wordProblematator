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
    void setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor);
    void setup(ofPoint pos, ofPoint size, ofColor thisColor);
    void update(ofPoint newPosition);
    void draw();
    void draw(ofTrueTypeFont& basicFont);
    void drawNoColor();
    
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
    
    //reuse info
    ofPoint         pos;
    
    ofPoint         offSet;
    
    
};

#endif
