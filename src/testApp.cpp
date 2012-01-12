#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	frameByframe = false;
	
	
	for (int i = 0; i < 4; i++) {
	
		
		officeInts[i] = 0;
		shopInts[i] = 0;		
		
		officeNumeral[i].loadMovie("movies/numerals.mov");
		shopNumeral[i].loadMovie("movies/numerals.mov");
		
		officeNumeral[i].play();
		shopNumeral[i].play();
		
		officeNumeral[i].setPaused(true);		
		shopNumeral[i].setPaused(true);
		
		officeNumeral[i].firstFrame();
		shopNumeral[i].firstFrame();
		
		loadShopOfficeSounds();

	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	// if the count has changed from last time
	if (countChanged) {

		cout << "officeCount: " << ofToString(officeCount) << "\n";
		cout << "  shopCount: " << ofToString(shopCount) << "\n\n";

		// For each digit in the count number, split into an array of ints
		for (int i = 0; i < ofToString(officeCount).size(); i++) {
			char cntStr = ofToString(officeCount)[i];
			officeInts[(4 - ofToString(officeCount).size()) + i] = ofToInt(&cntStr);
		}		
		for (int i = 0; i < ofToString(shopCount).size(); i++) {
			char cntStr = ofToString(shopCount)[i];
			shopInts[(4 - ofToString(shopCount).size()) + i] = ofToInt(&cntStr);
		}
		
		// Output the ints for debugging purposes
		cout << "officeInts: [" << officeInts[0] << ", " << ofToString(officeInts[1]) << ", " << ofToString(officeInts[2]).c_str() << ", " << officeInts[3] << "] " << "\n";
		//cout << "  shopInts: [" << shopInts[0] << ", " << ofToString(shopInts[1]) << ", " << ofToString(shopInts[2]).c_str() << ", " << shopInts[3] << "] " << "\n";
		
		countChanged = !countChanged;
	}
	
	for (int i = 0; i < 4; i++) {
		
		cout << "i: " << ofToString(3) << " | destinationFrame: " << ofToString(officeInts[3] * NUMERAL_FRAMES) << "| frame: " << ofToString(officeNumeral[3].getCurrentFrame()) << " / " << ofToString(1.0f * officeNumeral[3].getTotalNumFrames()) << "\n";
		
		if (officeInts[i] * NUMERAL_FRAMES == 0) {
			if (officeNumeral[i].getCurrentFrame() == 0) {
				officeNumeral[i].setPaused(true);
			} else if (officeNumeral[i].getCurrentFrame() >= 99) {
				officeNumeral[i].setFrame(0);
			} else {
				officeNumeral[i].setPaused(false);
			}
		} else if (officeNumeral[i].getCurrentFrame() == officeInts[i] * NUMERAL_FRAMES) {
			officeNumeral[i].setPaused(true);
		} else {
			officeNumeral[i].setPaused(false);
		}

		if (shopInts[i] * NUMERAL_FRAMES == 0) {
			if (shopNumeral[i].getCurrentFrame() == 0) {
				shopNumeral[i].setPaused(true);
			} else if (shopNumeral[i].getCurrentFrame() >= 99) {
				shopNumeral[i].setFrame(0);
			} else {
				shopNumeral[i].setPaused(false);
			}			
		} else if (shopNumeral[i].getCurrentFrame() == shopInts[i] * NUMERAL_FRAMES) {
			shopNumeral[i].setPaused(true);
		} else {
			shopNumeral[i].setPaused(false);
		}

		officeNumeral[i].idleMovie();
		shopNumeral[i].idleMovie();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xFFFFFF);

	for (int i = 0; i < 4; i++) {
		officeNumeral[i].draw(ofGetWidth() - ( ( 4 - (i)) * ( officeNumeral[i].width ) ) - ( ( 4 - (i)) *  SPACING ) , SPACING );
		shopNumeral[i].draw(ofGetWidth() - ( ( 4 - (i)) * (shopNumeral[i].width ) ) - ( ( 4- (i)) *  SPACING ) , officeNumeral[i].height + ( 2 * SPACING ) );
	}	

    ofSetHexColor(0x000000);
    /*unsigned char * pixels = fingerMovie.getPixels();
    // let's move through the "RGB" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < 320; i+=8){
        for (int j = 4; j < 240; j+=8){
            unsigned char r = pixels[(j * 320 + i)*3];
            float val = 1 - ((float)r / 255.0f);
            ofCircle(400 + i,20+j,10*val);
        }
    }


    ofSetHexColor(0x000000);
	ofDrawBitmapString("press f to change",20,320);
    if(frameByframe) ofSetHexColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetHexColor(0x000000);

    ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);

    /*if(fingerMovie.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }*/
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch(key){
        case 'f':
            frameByframe=!frameByframe;
            //fingerMovie.setPaused(frameByframe);
			break;
        case OF_KEY_LEFT:
            //fingerMovie.previousFrame();
			break;
        case OF_KEY_RIGHT:
            //fingerMovie.nextFrame();
			break;
        case '0':
            //fingerMovie.firstFrame();
			break;
		case 'w':
			officeCount++;
			countChanged = true;
			playShopOfficeSound(false);
			break;
		case 's':
			shopCount++;
			countChanged = true;
			playShopOfficeSound(true);
			break;

    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        float speed = (2 * pct - 1) * 5.0f;
        //fingerMovie.setSpeed(speed);
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        //fingerMovie.setPosition(pct);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
       //fingerMovie.setPaused(true);
	}
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
        //fingerMovie.setPaused(false);
	}
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


void testApp::loadShopOfficeSounds(){
	
    shopDir.listDir("sounds/shopsfx/");
    officeDir.listDir("sounds/officesfx/");
    
    shopDir.sort();
    officeDir.sort();
    
    for (int i = 0; i < (int)shopDir.size(); i++){
        //load shop sound fx
		
        ofSoundPlayer shopSnd;
        shopSnd.loadSound(shopDir.getPath(i));
        shopSounds.push_back(shopSnd);
        cout << "shop sound: " << i << ": " << shopDir.getPath(i) << "\n";
    }
    for (int i = 0; i < (int)officeDir.size(); i++){
        //load shop sound fx
        ofSoundPlayer officeSnd;
        officeSnd.loadSound(officeDir.getPath(i));
        officeSounds.push_back(officeSnd);
        cout << "office sound " << i << ": " << officeDir.getPath(i) << "\n";
    }
    
    totalShopSounds = shopDir.size();
    totalOfficeSounds = officeDir.size();
    
}

void testApp::playShopOfficeSound(bool shop){
    
    if (shop){
        int ranShop = int(ofRandom(0, (shopDir.size() - 1)) );
		
        shopSounds[ranShop].play();
        cout << "playing shop sound :" << ranShop << "\n";
        
    } else { // office
        int ranOffice = int(ofRandom(0, (officeDir.size() - 1)) );
        officeSounds[ranOffice].play();
        cout << "playing office sound :" << ranOffice << "\n";
    }
    
}

