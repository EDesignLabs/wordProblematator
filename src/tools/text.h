/*
 *  text.cpp
 *
 *  Created by Ryan Raffa on 4/8/13.
 *
 */

#ifndef _text
#define _text


#include "ofMain.h"

class text {
	
	public:
        
        text();
        ~text();

        void update();
		void draw(ofTrueTypeFont& basicFont);
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);

    
        string valueOne;
        ofPoint posOne;
    
        string valueTwo;
        ofPoint posTwo;
    
        string valueThree;
        ofPoint posThree;
    
        string valueFour;
        ofPoint posFour;
    
        bool insideOne;
        bool insideTwo;
        bool insideThree;
        bool insideFour;
    
        ofTrueTypeFont verdana16;


};

#endif
