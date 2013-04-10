/*
 *  button.cpp
 *  Created by Ryan Raffa on 5/5/13.
 *
 */

#include "button.h"


//------------------------------------------------------------------
void button::setup(ofTrueTypeFont& basicFont, ofPoint pos, ofPoint size, string thisString) {
    
    this->basicFont = &basicFont;
    this->thisString = thisString;

    thisRectangle.set(pos.x, pos.y, size.x, size.y);

//    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    
    pos.set(100, 100);}


//------------------------------------------------------------------
void button::update() {
    
}


//------------------------------------------------------------------
void button::draw() {
    
    //    ofDrawBitmapString("rectPos is"+ofToString(rectangles[0].getPosition()), 520, 20);
    
    if (touching) ofSetColor(255, 0, 0,150);
    else ofSetColor(0, 0, 0, 150);
    ofRect(thisRectangle);
    
    ofSetColor(255, 255, 255, 150);
    basicFont->drawString(thisString, thisRectangle.x+25, thisRectangle.y+50);
    
}


//------------------------------------------------------------------
void button::touchingDown(ofTouchEventArgs &touch) {

    if (thisRectangle.inside(touch.x, touch.y)){
        touching = true;
    }
    
}

//------------------------------------------------------------------
void button::touchingMove(ofTouchEventArgs &touch) {
        
}


//------------------------------------------------------------------
void button::touchingUp(ofTouchEventArgs &touch) {
    
    //this is only checking if you lift your finger
    touching = false;

    if (thisRectangle.inside(touch.x, touch.y)) {
        //this is specific locations of selections made when lifting finger
        touching = false;
        selected = true;
    }
    
}

//------------------------------------------------------------------
void button::doubleTap(ofTouchEventArgs &touch) {
    
    
    
}
