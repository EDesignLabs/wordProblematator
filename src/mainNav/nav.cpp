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
    ofPoint offSet;
    ofColor color;
    homeButton.loadImage("images/ui/glyphicons_020_home.png");
    
    pos.set(0, 0);
    size.set(homeButton.getWidth()+20, homeButton.getHeight()+20);
    offSet.set(25, 50);
    
    color.set(170, 170, 170);
    homeButtonRect.setup(basicFontLarge, pos, size, offSet, "", color);

    ofPoint posTwo;
    posTwo.set(50, 50);
    size.set(625, 75);
    mathButton.setup(basicFontLarge, posTwo, size, offSet, "Math Example", color);

    ofPoint posThree;
    posThree.set(50, 150);
    size.set(625, 75);
    scienceButton.setup(basicFontLarge, posThree, size, offSet, "Science Example", color);

    ofPoint posFour;
    posThree.set(50, 250);
    size.set(625, 75);
    historyButton.setup(basicFontLarge, posThree, size, offSet, "History Example", color);
    
    navStateToc = true;
    navStateExercises = false;

    printf(" NAV setup ended \n");
    
}
		 
//------------------------------------------------------------------
void nav::update(ofTrueTypeFont& basicFontSmall, ofTrueTypeFont& basicFontMedium, ofTrueTypeFont& basicFontLarge) {

    //depending on the selection made, a specific setup is run
    //when returning to TOC from monster, monster is reset

//    printf(" NAV update started \n");
    
    if (mathButton.selected) {
        mathExercises = new exercisesMath(basicFontSmall, basicFontMedium, basicFontLarge);
        navStateToc = false;
        navStateExercises = true;
        mathButton.selected=false;
    }

    if (scienceButton.selected) {
        mathExercises = new exercisesMath(basicFontSmall, basicFontMedium, basicFontLarge);
        navStateToc = false;
        navStateExercises = true;
        scienceButton.selected=false;
    }

    if (historyButton.selected) {
        mathExercises = new exercisesMath(basicFontSmall, basicFontMedium, basicFontLarge);
        navStateToc = false;
        navStateExercises = true;
        historyButton.selected=false;
    }

    
    if (homeButtonRect.selected) {
        
        if (navStateExercises) {
            navStateExercises = false;
            navStateToc = true;
            delete mathExercises;
            homeButtonRect.selected=false;
        }
    }

    //based on what state is active, update information is passed
    if (navStateExercises) {
        mathExercises->update();
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
        mathExercises->draw(basicFont);
        homeButtonRect.draw();
        
        ofEnableAlphaBlending();
            homeButton.draw(10, 10);
        ofDisableAlphaBlending();
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
        mathExercises->touchingDown(touch);
        homeButtonRect.touchingDown(touch);
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
        mathExercises->touchingMove(touch);
        homeButtonRect.touchingMove(touch);
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
        mathExercises->touchingUp(touch);
        homeButtonRect.touchingUp(touch);
    }
    
}

//------------------------------------------------------------------
void nav::doubleTap(ofTouchEventArgs &touch) {
    
}


