#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//If you want a landscape oreintation 
	iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT);
	
    verdana12.loadFont("verdana.ttf", 12, true, true);
    verdana12.setLineHeight(24.0f);
    verdana12.setLetterSpacing(0.96);

    verdana16.loadFont("verdana.ttf", 16, true, true);
    verdana16.setLineHeight(24.0f);
    verdana16.setLetterSpacing(0.96);

    verdana22.loadFont("verdana.ttf", 22, true, true);
    verdana22.setLineHeight(24.0f);
    verdana22.setLetterSpacing(0.96);

    theNav.setup(verdana12, verdana16, verdana22);

}

//--------------------------------------------------------------
void testApp::update(){
    
    theNav.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofBackground(255, 255, 255);
    theNav.draw(verdana12);
    
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    
    theNav.touchingDown(touch);
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    
    theNav.touchingMove(touch);
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

    theNav.touchingUp(touch);
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

    theNav.doubleTap(touch);
    
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    sprintf(eventString, "alert - orientation change to %i", newOrientation);
}

