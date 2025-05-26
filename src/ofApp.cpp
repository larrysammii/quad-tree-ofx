#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofMath.h"
#include "ofRectangle.h"
#include "ofVec2f.h"
#include "quadtree.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofRectangle boundary(0, 0, ofGetWidth(), ofGetHeight());
	quadtree = std::make_unique<QuadTree>(boundary, 4);

	for (int i = 0; i < 300; i++) {

		ofVec2f point(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));

		quadtree->insert(point);
	};
}

//--------------------------------------------------------------
void ofApp::update() {
	ofVec2f point(
		ofRandom(0, ofGetWidth()),
		ofRandom(0, ofGetHeight()));
	quadtree->insert(point);
}

//--------------------------------------------------------------
void ofApp::draw() {
	quadtree->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	// ofVec2f point(x, y);
	// quadtree->insert(point);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
