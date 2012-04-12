#pragma once

#include "ofMain.h"

#define SPACING 0
#define NUMERAL_FRAMES 10

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

	ofVideoPlayer	officeNumeral[4];
	ofVideoPlayer	shopNumeral[4];
	
	int officeInts[4];
	int shopInts[4];
	
	int numeralInPoints[10];
	
	int shopCount;
	int officeCount;
	
	bool countChanged;
	
	bool                frameByframe;
	
	//Sound Effects player
    
    ofDirectory shopDir;
    ofDirectory officeDir;
    
    vector<ofSoundPlayer> shopSounds;
    vector<ofSoundPlayer> officeSounds;
    
    int totalShopSounds;
    int totalOfficeSounds;
	
    void loadShopOfficeSounds();
    void playShopOfficeSound(bool shop);
	
};

