/*
 *  nav.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */
#ifndef _nav
#define _nav


#include "ofMain.h"

//for different navigating
#include "exercises.h"
#include "button.h"

class nav {
	
	public:
        void setup(ofTrueTypeFont& basicFontSmall, ofTrueTypeFont& basicFontMedium, ofTrueTypeFont& basicFontLarge);
		void update();
		void draw(ofTrueTypeFont& basicFont);

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);

        button             mathButton;
        button             scienceButton;
        button             historyButton;
        button             allButton;
    
        exercises*         mainExercises;

        bool    navStateToc;
        bool    navStateExercises;
    
        bool    endSplash;
    
        int     counter;
    
};

#endif
