/*
 *  exercises.h
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _exercises
#define _exercises


#include "ofMain.h"

//#include "exerciseFrame.h"
#include "mathOne.h"

class exercises {
	
	public:
        
        exercises();
        ~exercises();
    
        void update();
		void draw(ofTrueTypeFont& basicFont);

        void next();
        void switchScene();
        void updateWhichScene();

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);


//-----------------------------------------------    
//Math Problems
    
        mathOne* problemOne;

        
};

#endif
