/*
 *  drawing.cpp
 *
 *  Created by Ryan Raffa on 4/4/13.
 *
 */

#include "drawing.h"

////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void drawing::reset() {
    
    thePoints.clear();
    
    printf(" drawing reset ended \n");
    
}

//------------------------------------------------------------------
void drawing::setup() {
    
    printf(" drawing setup started \n");

//-----------------------------------------------
//sample section

    printf(" drawing setup ended \n");

}

		 
//------------------------------------------------------------------        
void drawing::update(ofTouchEventArgs &touch) {
    
    ofPoint newLocation;
    newLocation.x = touch.x;
    newLocation.y = touch.y;
    
    if (newLocation.y > ofGetHeight()/3) {
        thePoints.push_back(newLocation);
    }

}


//------------------------------------------------------------------
void drawing::draw() {
    
    if (thePoints.size() > 0) {
        for (int i = 1; i < thePoints.size(); i++) {
            ofLine(thePoints[i-1].x, thePoints[i-1].y, thePoints[i].x, thePoints[i].y);
        }
    }
}
