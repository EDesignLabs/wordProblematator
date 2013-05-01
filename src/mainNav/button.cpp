/*
 *  button.cpp
 *  Created by Ryan Raffa on 5/5/13.
 *
 */

#include "button.h"


//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofPoint offSet, string thisString, ofColor thisColor) {
    
    this->thisString = thisString;
    this->thisColor = thisColor;
    this->offSet = offSet;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);

//    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    
    pos.set(100, 100);

}


//------------------------------------------------------------------
void button::setup(ofPoint pos, ofPoint size, ofColor thisColor) {
    
    this->thisColor = thisColor;
    this->offSet = offSet;
    
    thisRectangle.set(pos.x, pos.y, size.x, size.y);
    
    //    thisRectangle.set(pos.x, pos.y, 625, 75);
    
    touching = false;
    selected = false;
    
    pos.set(100, 100);
    
}


//------------------------------------------------------------------
void button::update() {
    
}


//------------------------------------------------------------------
void button::draw() {

    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
}

//------------------------------------------------------------------
void button::draw(ofTrueTypeFont& basicFont) {
    
    if (touching) ofSetColor(255, 0, 0,250);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
    ofSetColor(0, 0, 0);
    basicFont.drawString(thisString, thisRectangle.x+offSet.x, thisRectangle.y+offSet.y);
    
}

//------------------------------------------------------------------
void button::drawNoColor() {
    
    if (touching) ofSetColor(90, 90, 90);
    else ofSetColor(thisColor);
    ofRect(thisRectangle);
    
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
    
    if (thisRectangle.inside(touch.x, touch.y) && touching) {
        //this is specific locations of selections made when lifting finger
        touching = false;
        selected = true;
    }

    //this is only checking if you lift your finger
    touching = false;
    
}

//------------------------------------------------------------------
void button::doubleTap(ofTouchEventArgs &touch) {
    
    
    
}
