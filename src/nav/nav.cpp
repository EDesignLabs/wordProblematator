/*
 *  nav.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#include "nav.h"


//------------------------------------------------------------------
void nav::setup(ofTrueTypeFont& basicFontSmall, ofTrueTypeFont& basicFontMedium, ofTrueTypeFont& basicFontLarge) {

    printf(" NAV setup started \n");
    
    ofPoint pos;
    ofPoint size;
    size.set(150, 75);
    pos.set(ofGetWidth()-size.x, ofGetHeight()-size.y);
    allButton.setup(basicFontLarge, pos, size, "TOC");

    ofPoint posTwo;
    posTwo.set(50, 50);
    size.set(625, 75);
    mathButton.setup(basicFontLarge, posTwo, size, "Math Example");

    ofPoint posThree;
    posThree.set(50, 150);
    size.set(625, 75);
    scienceButton.setup(basicFontLarge, posThree, size, "Science Example");

    ofPoint posFour;
    posThree.set(50, 250);
    size.set(625, 75);
    historyButton.setup(basicFontLarge, posThree, size, "History Example");
    
    navStateToc = true;
    navStateExercises = false;

    counter = 0;
    
    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update() {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");
    
    if (mathButton.selected) {
        mainExercises = new exercises();
        navStateToc = false;
        navStateExercises = true;
        mathButton.selected=false;
    }

    if (scienceButton.selected) {
        mainExercises = new exercises();
        navStateToc = false;
        navStateExercises = true;
        scienceButton.selected=false;
    }

    if (historyButton.selected) {
        mainExercises = new exercises();
        navStateToc = false;
        navStateExercises = true;
        historyButton.selected=false;
    }

    
    if (allButton.selected) {
        
        if (navStateExercises) {
            navStateExercises = false;
            navStateToc = true;
            delete mainExercises;
            allButton.selected=false;
        }
    }

    //based on what state is active, update information is passed
    if (navStateExercises) {
        mainExercises->update();
    }
    
//    printf(" NAV udpate ended \n");
    
}


//------------------------------------------------------------------
void nav::draw(ofTrueTypeFont& basicFont) {

    if (navStateToc) {
        mathButton.draw();
        scienceButton.draw();
        historyButton.draw();
    }

    if (navStateExercises) {
        mainExercises->draw(basicFont);
        allButton.draw();
    }

}

//------------------------------------------------------------------
void nav::touchingDown(ofTouchEventArgs &touch) {
    
    if (navStateToc) {
        mathButton.touchingDown(touch);
        scienceButton.touchingDown(touch);
        historyButton.touchingDown(touch);
    }
    
    if (navStateExercises) {
        mainExercises->touchingDown(touch);
        allButton.touchingDown(touch);
    }
    
}

//------------------------------------------------------------------
void nav::touchingMove(ofTouchEventArgs &touch) {
    if (navStateToc) {
        mathButton.touchingMove(touch);
        scienceButton.touchingMove(touch);
        historyButton.touchingMove(touch);
    }
    
    if (navStateExercises) {
        mainExercises->touchingMove(touch);
        allButton.touchingMove(touch);
    }

}

//------------------------------------------------------------------
void nav::touchingUp(ofTouchEventArgs &touch) {

    if (navStateToc) {
        mathButton.touchingUp(touch);
        scienceButton.touchingUp(touch);
        historyButton.touchingUp(touch);
    }
    
    if (navStateExercises) {
        mainExercises->touchingUp(touch);
        allButton.touchingUp(touch);
    }
    
}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


