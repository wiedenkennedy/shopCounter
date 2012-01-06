#pragma once

#include "ofMain.h"

#define SPACING 50

class testApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

	ofVideoPlayer	officeCount[4];
	ofVideoPlayer	shopCount[4];
	
	ofPoint	officeLocations[4];
	ofPoint shopLocations[4];
	
	bool                frameByframe;
	
};

