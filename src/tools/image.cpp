/*
 *  image.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "image.h"

////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void image::reset() {
    
    delete theImage;
    
    printf(" image reset ended \n");
    
}

//------------------------------------------------------------------
void image::setup() {
    
    theImage = new ofImage;
    
    theImage->loadImage("images/cells.png");
    
    printf(" image setup started \n");

//-----------------------------------------------
//sample section

    printf(" image setup ended \n");

}

		 
//------------------------------------------------------------------        
void image::update(ofTouchEventArgs &touch) {
    
}


//------------------------------------------------------------------
void image::draw() {
    
    theImage->draw((ofGetWidth()/2)-(theImage->width/2), ofGetHeight()/3 + 125);
    
}
