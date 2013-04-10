/*
 *  mathOne.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "mathOne.h"



//------------------------------------------------------------------
mathOne::~mathOne() {
    
    thisImage.reset();
    exit();
    delete thisText;
}


//------------------------------------------------------------------
mathOne::mathOne() {
    
    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
    
    sprintf(eventString, "touch = (%2.0f, %2.0f - id %i)", 0.0, 0.0, 0.0);

    thisImage.setup();
    thisText = new text();
    
    gui = new ofxUICanvas(10,ofGetHeight()/3+5,320,120);

    vector<string> vnames;
    vnames.push_back("Text");
    vnames.push_back("Draw");
    vnames.push_back("Image");
    gui->addLabel("Select Tool", OFX_UI_FONT_MEDIUM);
    ofxUIRadio *radio = gui->addRadio("VR", vnames, OFX_UI_ORIENTATION_VERTICAL);
    radio->activateToggle("Text");

    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&mathOne::guiEvent);
    
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));

    doText      = true;
    doDrawing   = false;
    doImage     = false;

    theText = "In a cellular regeneration experiment, Jaydon Laboratory found that for cells\nput in containers with a particular growth medium, the number of cells at the end\nof each week was double the number of cells at the end of the previous week.\nAfter week 1, there were 15.\nAfter week 2, there were 30.\nAfter week 3, there were 60.\nHow many cells were there after 7 weeks?";

    
}



//------------------------------------------------------------------
void mathOne::update() {

    if (doText) {
        thisText->update();
    }

        
}


//------------------------------------------------------------------
void mathOne::draw(ofTrueTypeFont& basicFont) {

    ofSetColor(255, 0, 0, 100);
    ofRect(0, ofGetHeight()/3, ofGetWidth(), 5);
    
    sprintf (timeString, "time: %0.2i:%0.2i:%0.2i \nelapsed time %i", ofGetHours(), ofGetMinutes(), ofGetSeconds(), ofGetElapsedTimeMillis());
	
    ofSetHexColor(0xffffff);
	basicFont.drawString(timeString, 10,ofGetHeight()-90);
	basicFont.drawString(eventString, 10,ofGetHeight()-20);
    
    ofEnableAlphaBlending();
    
    if (doText) {
        basicFont.drawString(theText, 40, 40);
        thisText->draw(basicFont);
    }
    
    if (doDrawing) {

        basicFont.drawString(theText, 40, 40);
    
        for (int i = 0; i < drawThese.size(); i++) {
            drawThese[i].draw();
        }
        
        if (currentDrawing.size()>0) {
            for (int i = 1; i < currentDrawing.size(); i++) {
                ofLine(currentDrawing[i-1].x, currentDrawing[i-1].y, currentDrawing[i].x, currentDrawing[i].y);
            }
        }
    }
    
    if (doImage) {
        basicFont.drawString(theText, 40, 40);
        thisImage.draw();
    }
    
    
    ofDisableAlphaBlending();

}

//------------------------------------------------------------------
void mathOne::touchingDown(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchDown = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    if (doText) {
        thisText->touchingDown(touch);
    }

    
    if (doDrawing) {

        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        if (currentPos.y > ofGetHeight()/3) {
            currentDrawing.push_back(currentPos);
            thisDrawing.update(touch);
        }
    }
}

//------------------------------------------------------------------
void mathOne::touchingMove(ofTouchEventArgs &touch) {

    sprintf(eventString, "touchMoved = (%2.0f, %2.0f - id %i)", touch.x, touch.y, touch.id);
    
    if (doText) {
        thisText->touchingMove(touch);
    }
    
    if (doDrawing) {
        ofPoint currentPos;
        currentPos.x = touch.x;
        currentPos.y = touch.y;

        if (currentPos.y > ofGetHeight()/3) {
            currentDrawing.push_back(currentPos);
            thisDrawing.update(touch);
        }
    }
    
}

//------------------------------------------------------------------
void mathOne::touchingUp(ofTouchEventArgs &touch) {

 	sprintf(eventString, "touchUp = (%2.0f, %2.0f - id %i)",touch.x, touch.y, touch.id);
    
    if (doText) {
        thisText->touchingUp(touch);
    }

    if (doDrawing) {
        currentDrawing.clear();
        drawThese.push_back(thisDrawing);
        thisDrawing.reset();
    }

}

//------------------------------------------------------------------
void mathOne::doubleTap(ofTouchEventArgs &touch) {


}

//--------------------------------------------------------------
void mathOne::guiEvent(ofxUIEventArgs &e) {
	string name = e.widget->getName();
	int kind = e.widget->getKind();

    if(kind == OFX_UI_WIDGET_TOGGLE) {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        cout << name << "\t value: " << toggle->getValue() << endl;

        if (name == "Text") {
            //use draw tool
            doText = true;
            doDrawing = false;
            doImage = false;
            printf(" Text gui task called \n");
        }

        if (name == "Draw") {
            //use draw tool
            doText = false;
            doDrawing = true;
            doImage = false;
            printf(" Drawing gui task called \n");
        }

        else if (name == "Image") {
            //use image tool
            printf(" Image gui task called \n");
            doText = false;
            doDrawing = false;
            doImage = true;
        }

    }

}


//--------------------------------------------------------------
void mathOne::exit() {

    delete gui;

}

