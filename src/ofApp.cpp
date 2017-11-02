#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    // keycode init
    rainForce = false;
    
    // particle init
    wordNum = 500;
    letterNum = 1000;
    velocityValue = 20;
    
    words = {"sad", "mad", "scared", "peaceful", "powerful", "confused", "rejected", "helpless", "submissive", "insecure","anxious", "excited", "sensuous", "energetic", "cheerful" "creative", "hopeful", "aware", "proud", "respected", "appreciated", "important", "faithful", "nurturing", "trusting", "loving", "intimate", "thoughtful", "content", "tired", "bored", "lonely", "depressed", "ashamed", "guilty", "hurt", "hostile", "angry", "selfish", "hateful", "critical"};
    
    letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    
    for (int i = 0; i < wordNum; i++){
        particle myParticle;
        myParticle.setLetterPos = false;
        myParticle.selectedWord = words[ofRandom(words.size())];
        float vx = ofRandom(-velocityValue*8, velocityValue*8);
        float vy = ofRandom(-velocityValue,velocityValue);
        float vz = ofRandom(velocityValue*5,velocityValue*8);
        myParticle.setInitialCondition(ofGetWindowSize()[0]/2,ofGetWindowHeight()/2, -7000, vx, vy, vz);
        particles.push_back(myParticle);
    }
    
    for (int i = 0; i < letterNum; i++){
        particle myParticle;
        myParticle.setLetterPos = false;
        myParticle.selectedWord = letters[ofRandom(letters.size())];
        float vx = ofRandom(-velocityValue*8, velocityValue*8);
        float vy = ofRandom(-velocityValue,velocityValue);
        float vz = ofRandom(velocityValue*5,velocityValue*8);
        myParticle.setInitialCondition(ofGetWindowSize()[0]/2,ofGetWindowHeight()/2, -7000, vx, vy, vz);
        particles.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // big bang
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addDampingForce();
        //particles[i].addRepulsionForce(mouseX, mouseY, 500, 1);
        //particles[i].addAttractionForce(mouseX, mouseY, 500, 2);
        //particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
        //particles[i].addClockwiseForce(mouseX, mouseY, 200, 5);
        particles[i].update();
    }
    
    // make it rain
    if(rainForce) {
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            particles[i].addForce(-0.03,0.02, 0.02);
            //particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 2);
            particles[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 50, 10);
    
    //        cam.begin();
    if(!rainForce) {
        
        for (int i = 0; i < wordNum; i++){
            particles[i].draw();
        }
    }
    
    if(rainForce) {
        for (int i = wordNum; i < letterNum+wordNum; i++){
            particles[i].draw();
        }
    }
    //        cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // make it rain
    rainForce = !rainForce;
//    particles.erase(particles.begin(), particles.begin()+wordNum-1);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
