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

    
    valueOne = "each week was double the number of cells at the end of the previous week.";
    posOne.set(65, 88);
    
    valueTwo = "After week 1, there were 15.";
    posTwo.set(40, 111);
    
    valueThree = "After week 2, there were 30.";
    posThree.set(40, 136);
    
    valueFour = "After week 3, there were 60.";
    posFour.set(40, 160);
    
    printf(" text setup ended \n");
    
    verdana16.loadFont("verdana.ttf", 16, true, true);
    verdana16.setLineHeight(24.0f);
    verdana16.setLetterSpacing(0.96);
    
    insideOne = false;

}

		 
//------------------------------------------------------------------        
void text::update() {
    
    printf("posOne.x: %f \n", posOne.x);
    printf("posOne.x: %f \n", posOne.y);
    
    printf("posTwo.x: %f \n", posTwo.x);
    printf("posTwo.x: %f \n", posTwo.y);
    
    printf("posThree.x: %f \n", posThree.x);
    printf("posThree.x: %f \n", posThree.y);
    
    printf("posFour.x: %f \n", posFour.x);
    printf("posFour.x: %f \n", posFour.y);
    
}


//------------------------------------------------------------------
void text::draw(ofTrueTypeFont& basicFont) {

    basicFont.drawString(valueOne, posOne.x, posOne.y);
    basicFont.drawString(valueTwo, posTwo.x, posTwo.y);
    basicFont.drawString(valueThree, posThree.x, posThree.y);
    basicFont.drawString(valueFour, posFour.x, posFour.y);
    
}

//------------------------------------------------------------------
void text::touchingDown(ofTouchEventArgs &touch) {
    
    ofRectangle boxOne = verdana16.getStringBoundingBox(valueOne, posOne.x, posOne.y);
    ofRectangle boxTwo = verdana16.getStringBoundingBox(valueTwo, posTwo.x, posTwo.y);
    ofRectangle boxThree = verdana16.getStringBoundingBox(valueThree, posThree.x, posThree.y);
    ofRectangle boxFour = verdana16.getStringBoundingBox(valueFour, posFour.x, posFour.y);
    
    insideOne = boxOne.inside(touch.x,touch.y);
    insideTwo = boxTwo.inside(touch.x,touch.y);
    insideThree = boxThree.inside(touch.x,touch.y);
    insideFour = boxFour.inside(touch.x,touch.y);
    
    if (insideOne) {
        posOne.x = touch.x;
        posOne.y = touch.y;
    }

    if (insideTwo) {
        posTwo.x = touch.x;
        posTwo.y = touch.y;
    }

    if (insideThree) {
        posThree.x = touch.x;
        posThree.y = touch.y;
    }

    if (insideFour) {
        posFour.x = touch.x;
        posFour.y = touch.y;
    }

}

//------------------------------------------------------------------
void text::touchingMove(ofTouchEventArgs &touch) {
    
    if (insideOne) {
        posOne.x = touch.x;
        posOne.y = touch.y;
    }
    
    if (insideTwo) {
        posTwo.x = touch.x;
        posTwo.y = touch.y;
    }
    
    if (insideThree) {
        posThree.x = touch.x;
        posThree.y = touch.y;
    }
    
    if (insideFour) {
        posFour.x = touch.x;
        posFour.y = touch.y;
    }
    
}

//------------------------------------------------------------------
void text::touchingUp(ofTouchEventArgs &touch) {
    
    insideOne = false;
    insideTwo = false;
    insideThree = false;
    insideFour = false;
    
}

