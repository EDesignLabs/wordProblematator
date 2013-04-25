/*
 *  text.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "text.h"

////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
text::~text() {
    
    printf(" text reset ended \n");
    
}

//------------------------------------------------------------------
text::text() {
    
    printf(" text setup started \n");
    
    verdana16.loadFont("verdana.ttf", 16, true, true);
    verdana16.setLineHeight(24.0f);
    verdana16.setLetterSpacing(0.96);
    
    printf(" text setup ended \n");

}

		 
//------------------------------------------------------------------        
void text::update() {
        
}


//------------------------------------------------------------------
void text::draw(ofTrueTypeFont& basicFont) {

}

//------------------------------------------------------------------
void text::touchingDown(ofTouchEventArgs &touch) {
    
}

//------------------------------------------------------------------
void text::touchingMove(ofTouchEventArgs &touch) {

}

//------------------------------------------------------------------
void text::touchingUp(ofTouchEventArgs &touch) {
    
}

