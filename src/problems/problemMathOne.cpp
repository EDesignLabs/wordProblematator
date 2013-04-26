/*
 *  problemMathOne.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "problemMathOne.h"




////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMathOne::~problemMathOne() {

    delete create;

}



////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
problemMathOne::problemMathOne(ofTrueTypeFont& basicFontSmall, ofTrueTypeFont& basicFontMedium, ofTrueTypeFont& basicFontLarge) {
        
 
//-----------------------------------------------    
//setup math problem one
    
    create = new uiCreate(basicFontSmall);
    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    questionButtonImage.loadImage("images/ui/glyphicons_194_circle_question_mark.png");
    
    size.set(questionButtonImage.getWidth()+20, questionButtonImage.getHeight()+20);
    pos.set(ofGetWidth()-46, 0);
    offSet.set(15, 32);
    
    color.set(170, 170, 170);
    questionButton.setup(basicFontLarge, pos, size, offSet, "", color);
    
    ofPoint posTwo;
    posTwo.set(46, 0);
    size.set(312, 46);
    color.set(200, 52, 70);
    createButton.setup(basicFontLarge, posTwo, size, offSet, "1. Create", color);
    
    ofPoint posThree;
    posThree.set(358, 0);
    color.set(68, 116, 176);
    reflectButton.setup(basicFontLarge, posThree, size, offSet, "2. Reflect", color);
    
    ofPoint posFour;
    posThree.set(670, 0);
    color.set(230, 224, 47);
    presentButton.setup(basicFontLarge, posThree, size, offSet, "3. Present", color);
    
    navStateCreate = true;
    navStateReflect = false;
    navStatePresent = false;
    navStateQuestion = false;
    
    printf(" problemMathOne Setup ended \n ");

}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------        
void problemMathOne::update() {
    
    
//-----------------------------------------------
//NAV state is sorted out
    
    if (createButton.selected) {
        navStateReflect = false;
        navStatePresent = false;
        navStateQuestion = false;
        navStateCreate = true;
        createButton.selected=false;
    }
    
    if (reflectButton.selected) {
        navStateCreate = false;
        navStatePresent = false;
        navStateQuestion = false;
        navStateReflect = true;
        reflectButton.selected=false;
    }
    
    if (presentButton.selected) {
        navStateCreate = false;
        navStateReflect = false;
        navStateQuestion = false;
        navStatePresent = true;
        presentButton.selected=false;
    }
    
    if (questionButton.selected) {        
        navStateCreate = false;
        navStateReflect = false;
        navStatePresent = false;
        navStateQuestion = true;
        questionButton.selected=false;
    }
    
//-----------------------------------------------
//What is done based on NAV state

    if (navStateCreate) {
        create->update();
    }
    
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMathOne::draw(ofTrueTypeFont& basicFont) {

    if (navStateCreate) create->draw(basicFont);
    
//-----------------------------------------------
//Feedback
    
    if (navStateCreate) basicFont.drawString("create selected", ofGetWidth()/2, 60);
    if (navStateReflect) basicFont.drawString("reflect selected", ofGetWidth()/2, 60);
    if (navStatePresent) basicFont.drawString("present selected", ofGetWidth()/2, 60);
    if (navStateQuestion) basicFont.drawString("question selected", ofGetWidth()/2, 60);

//-----------------------------------------------
//Button UI

    createButton.draw();
    reflectButton.draw();
    presentButton.draw();
    questionButton.draw();
    
    ofEnableAlphaBlending();
    questionButtonImage.draw(ofGetWidth()-35, 10);
    ofDisableAlphaBlending();
    
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void problemMathOne::touchingDown(ofTouchEventArgs &touch) {

    createButton.touchingDown(touch);
    reflectButton.touchingDown(touch);
    presentButton.touchingDown(touch);
    questionButton.touchingDown(touch);
    
    if (navStateCreate) create->touchingDown(touch);

}

//------------------------------------------------------------------
void problemMathOne::touchingMove(ofTouchEventArgs &touch) {
    
    createButton.touchingMove(touch);
    reflectButton.touchingMove(touch);
    presentButton.touchingMove(touch);
    questionButton.touchingMove(touch);

    if (navStateCreate) create->touchingMove(touch);

}

//------------------------------------------------------------------
void problemMathOne::touchingUp(ofTouchEventArgs &touch) {
    
    createButton.touchingUp(touch);
    reflectButton.touchingUp(touch);
    presentButton.touchingUp(touch);
    questionButton.touchingUp(touch);

    if (navStateCreate) create->touchingUp(touch);

}

//------------------------------------------------------------------
void problemMathOne::doubleTap(ofTouchEventArgs &touch) {

    createButton.doubleTap(touch);
    reflectButton.doubleTap(touch);
    presentButton.doubleTap(touch);
    questionButton.doubleTap(touch);

    if (navStateCreate) create->doubleTap(touch);
    
}

    

