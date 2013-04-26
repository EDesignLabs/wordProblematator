/*
 *  uiCreate.cpp
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#include "uiCreate.h"


////////////////////////////////////////////////////////////////////
//      RESET                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiCreate::~uiCreate() {
    
    thisImage.reset();
    exit();
    delete thisText;

    //uiCreate elements
    delete pencil;
    delete font;
    delete table;
    delete okSave;

    delete pencilSelected;
    delete fontSelected;
    delete tableSelected;
    delete okSaveSelected;
    
}

////////////////////////////////////////////////////////////////////
//      SETUP                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
uiCreate::uiCreate(ofTrueTypeFont& basicFont) {
    
    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
    
    sprintf(eventString, "touch = (%2.0f, %2.0f - id %i)", 0.0, 0.0, 0.0);

    thisImage.setup();
    thisText = new text();
    
    //load uiCreate images
    pencil = new ofImage;
    font = new ofImage;
    table = new ofImage;
    okSave = new ofImage;
    
    pencil->loadImage("images/ui/glyphicons_030_pencil.png");
    font->loadImage("images/ui/glyphicons_100_font.png");
    table->loadImage("images/ui/glyphicons_119_table.png");
    okSave->loadImage("images/ui/glyphicons_206_ok_2.png");
    
    //set initial values for state
    pencilSelected = new bool;
    fontSelected = new bool;
    tableSelected = new bool;
    okSaveSelected = new bool;
    
    *pencilSelected = true;
    *fontSelected = false;
    *tableSelected = false;
    *okSaveSelected = false;

    
    ofPoint pos;
    ofPoint size;
    ofPoint offSet;
    ofColor color;
    
    size.set(pencil->getWidth()+20, pencil->getHeight()+20);
    pos.set(0, 300);
    offSet.set(0, 0);
    
    color.set(170, 170, 170);
    pencilButton.setup(basicFont, pos, size, offSet, "", color);
    
    ofPoint posTwo;
    posTwo.set(0, 345);
    fontButton.setup(basicFont, posTwo, size, offSet, "", color);
    
    ofPoint posThree;
    posThree.set(0, 390);
    tableButton.setup(basicFont, posThree, size, offSet, "", color);
    
    ofPoint posFour;
    posThree.set(0, 435);
    okSaveButton.setup(basicFont, posThree, size, offSet, "", color);
        
    theText = "Nick's daughter Penny has 25 dimes. She likes to arrange them\ninto three piles, putting an odd number of dimes into each pile. In\nhow many ways could she do this?\nSolve this problem before continuing. ";

    
}


////////////////////////////////////////////////////////////////////
//      UPDATE                                                    //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::update() {

    //-----------------------------------------------
    //NAV state is sorted out
    
    if (pencilButton.selected) {
        *fontSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *pencilSelected = true;
        pencilButton.selected=false;
    }
    
    if (fontButton.selected) {
        *pencilSelected = false;
        *tableSelected = false;
        *okSaveSelected = false;
        *fontSelected = true;
        fontButton.selected=false;
    }
    
    if (tableButton.selected) {
        *pencilSelected = false;
        *fontSelected = false;
        *okSaveSelected = false;
        *tableSelected = true;
        tableButton.selected=false;
    }
    
    if (okSaveButton.selected) {
        *pencilSelected = false;
        *fontSelected = false;
        *tableSelected = false;
        *okSaveSelected = true;
        okSaveButton.selected=false;
    }

    
    if (*fontSelected) {
        thisText->update();
    }

        
}


////////////////////////////////////////////////////////////////////
//      DRAW                                                      //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::draw(ofTrueTypeFont& basicFont) {

    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
	
    ofSetHexColor(0x000000);
	basicFont.drawString(timeString, 10,ofGetHeight()-90);
	basicFont.drawString(eventString, 10,ofGetHeight()-20);
    
//-----------------------------------------------
//The Question

    basicFont.drawString(theText, 10, 100);
    thisText->draw(basicFont);
    
    
//-----------------------------------------------
//What is created

    for (int i = 0; i < drawThese.size(); i++) {
        drawThese[i].draw();
    }
    
    
//-----------------------------------------------
//Tools
        
    if (*fontSelected) {
        basicFont.drawString("text selected", 10, ofGetHeight()/3);
    }
    
    if (*pencilSelected) {
        basicFont.drawString("pencil selected", 10, ofGetHeight()/3);
                
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
    }
    
    if (*tableSelected) {
        basicFont.drawString("table selected", 10, ofGetHeight()/3);
    }

    if (*okSaveSelected) {
        basicFont.drawString("ok save selected", 10, ofGetHeight()/3);
    }

    
//-----------------------------------------------
//Tool Button UI

    pencilButton.draw();
    fontButton.draw();
    tableButton.draw();
    okSaveButton.draw();
    
    ofSetHexColor(0x000000);
    
    ofEnableAlphaBlending();
    pencil->draw(10, 310);
    font->draw(10, 355);
    table->draw(10, 400);
    okSave->draw(10, 445);
    ofDisableAlphaBlending();
    
}


////////////////////////////////////////////////////////////////////
//      TOUCH                                                     //
////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------
void uiCreate::touchingDown(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchDown = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    pencilButton.touchingDown(touch);
    fontButton.touchingDown(touch);
    tableButton.touchingDown(touch);
    okSaveButton.touchingDown(touch);
    
    if (*fontSelected) thisText->touchingDown(touch);
    
    if (*pencilSelected) {

        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }
}

//------------------------------------------------------------------
void uiCreate::touchingMove(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchMoved = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    pencilButton.touchingMove(touch);
    fontButton.touchingMove(touch);
    tableButton.touchingMove(touch);
    okSaveButton.touchingMove(touch);

    if (*fontSelected) thisText->touchingMove(touch);
    
    if (*pencilSelected) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        currentDrawing.push_back(currentPos);
        thisDrawing.update(touch);
    }
    
}

//------------------------------------------------------------------
void uiCreate::touchingUp(ofTouchEventArgs &touch) {

 	sprintf(eventString, "touchUp = (%2.0f, %2.0f - id %i)",touch.x, touch.y, touch.id);
    
    pencilButton.touchingUp(touch);
    fontButton.touchingUp(touch);
    tableButton.touchingUp(touch);
    okSaveButton.touchingUp(touch);

    if (*fontSelected) thisText->touchingUp(touch);

    if (*pencilSelected) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }
    
}


//------------------------------------------------------------------
void uiCreate::doubleTap(ofTouchEventArgs &touch) {

    pencilButton.doubleTap(touch);
    fontButton.doubleTap(touch);
    tableButton.doubleTap(touch);
    okSaveButton.doubleTap(touch);

}

//--------------------------------------------------------------
void uiCreate::exit() {


}

