#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
	vector<GalleryElement*> items;
	for (int i = 0; i < 30; i++) {
		items.push_back(new MyCustomGridElement());
	}
	gallery = new GalleryGrid();

	gallery->setup(items);
}

//--------------------------------------------------------------
void ofApp::update(){
	gallery->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	gallery->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	gallery->keyPressed(key);
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
	gallery->mousePressed(x, y, button);
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
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

