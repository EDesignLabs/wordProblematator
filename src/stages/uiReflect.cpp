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
    delete currentPos;

}


////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiReflect::uiReflect() {
    

    
    //set initial values for state

    scrubBox = new button;
    currentPos = new button;
    
    ofPoint pos;
    ofPoint size;
    ofColor color;
    
    float scrubHeight;
    scrubHeight = 50;
    
    //main scrub box
    pos.set(0, ofGetHeight()-scrubHeight);
    size.set(ofGetWidth(), scrubHeight);
    color.set(170, 170, 170);
    scrubBox->setup(pos, size, color);

    //position indicator
    size.set(10, scrubHeight);
    color.set(0, 0, 170);
    currentPos->setup(pos, size, color);
    
    
    scrubLocation = new ofPoint;
    scrubLocation->set(0, 0);
    scrubPos.set(0, 0);
    
}



////////////////////////////////////////////////////////////////////
//      SET POINTS                                                //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::setPoints(vector <drawing> theDrawings) {
    
    drawThese.clear();
    scrubFeedback.clear();
    
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
    
    
    ofPoint mapTempPos;
    mapTempPos.y = 10;
    for (int i = 0; i < theDrawings.size(); i++){
        for (int h = 0; h < drawThese[i].thePoints.size(); h++){
            mapTempPos.x = ofMap(drawThese[i].thePoints[h].timeStamp, startTime, endTime, 0, ofGetWidth());
            mapTempPos.y *= -1;
            
            scrubFeedback.push_back(mapTempPos);
        }
    }
    
    for (int i = 0; i < scrubFeedback.size(); i++){
        scrubFeedback[i].y += ofGetHeight()-25;
    }
    
    printf(" endTime is: %d \n", endTime);
    printf(" scrubfeedback[0].x is: %f \n", scrubFeedback[0].x);
    printf(" scrubfeedback[0].y is: %f \n", scrubFeedback[0].y);
    
}



////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::update() {
    
    if (scrubBox->touching) {
        scrubPos.x = ofMap(scrubLocation->x, 0, ofGetWidth(), startTime, endTime);
        currentPos->update(*scrubLocation);
    }
    
}



////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiReflect::draw(ofTrueTypeFont& basicFont) {

    scrubBox->drawNoColor();
    currentPos->draw();
    
    ofSetColor(0, 0, 0);    
    for (int i = 0; i < drawThese.size(); i++) {
        drawThese[i].draw(scrubPos.x);
    } 
    
    if (scrubFeedback.size() > 0) {
        for (int i = 1; i < scrubFeedback.size(); i++) {
            ofLine(scrubFeedback[i-1].x, scrubFeedback[i-1].y, scrubFeedback[i].x, scrubFeedback[i].y);
        }
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

