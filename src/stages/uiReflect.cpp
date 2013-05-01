/*
 *  uiReflect.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiReflect.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::~uiReflect() {
    
    //uiReflect elements
    delete scrubBox;
    delete scrubLocation;
    delete scrubPos;

}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::uiReflect() {
    

    
    //set initial values for state

    scrubBox = new button;
    
    ofPoint pos;
    ofPoint size;
    ofColor color;
    
    
    pos.set(0, ofGetHeight()-46);
    size.set(ofGetWidth(), 46);
    color.set(170, 170, 170);
    scrubBox->setup(pos, size, color);

    
    scrubLocation = new ofPoint;
    scrubLocation->set(0, 0);
    scrubPos = new ofPoint;
    scrubPos->set(0, 0);
    
}



////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::setPoints(vector <drawing> theDrawings) {
    
    drawThese.clear();
    
    for (int i=0; i < theDrawings.size(); i++) {
        
        //this is the vector of drawing
        drawThese.push_back(theDrawings[i]);
        
    }
    
    endTime = 0;
    endTime = drawThese[0].thePoints[0].timeStamp;
    //final elapsed time of final point
    startTime = drawThese[0].thePoints[0].timeStamp;
    int drawTheseAmount = drawThese.size()-1;
    int thePointsAmount = drawThese[drawTheseAmount].thePoints.size()-1;
    endTime = drawThese[drawTheseAmount].thePoints[thePointsAmount].timeStamp;
    
    printf(" endTime is: %d \n", endTime);
    
}



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::update() {

    
    if (scrubBox->touching) {
        scrubPos->x = ofMap(scrubLocation->x, 0, ofGetWidth(), startTime, endTime);
    }
    
}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::draw(ofTrueTypeFont& basicFont) {

    scrubBox->drawNoColor();
    
    ofSetColor(0, 0, 0);    
    for (int i = 0; i < drawThese.size(); i++) {
        drawThese[i].draw(scrubPos->x);
    } 
    
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::touchingDown(ofTouchEventArgs &touch) {
    
        scrubBox->touchingDown(touch);
        if (scrubBox->touching) scrubLocation->set(touch.x, touch.y);

        
}

//------------------------------------------------------------------
void uiReflect::touchingMove(ofTouchEventArgs &touch) {

        scrubBox->touchingMove(touch);
        if (scrubBox->touching) scrubLocation->set(touch.x, touch.y);
    
}

//------------------------------------------------------------------
void uiReflect::touchingUp(ofTouchEventArgs &touch) {

        scrubBox->touchingUp(touch);
        if (scrubBox->touching) scrubLocation->set(touch.x, touch.y);
    
}


//------------------------------------------------------------------
void uiReflect::doubleTap(ofTouchEventArgs &touch) {


}

//--------------------------------------------------------------
void uiReflect::exit() {


}

