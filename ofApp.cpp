#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	for (int len = 10; len < 350; len += 10) {

		int noise_deg = ofNoise(len * 0.005 - ofGetFrameNum() * 0.01) * 720;

		ofBeginShape();
		for (int deg = noise_deg; deg <= noise_deg + 200; deg++) {

			int param = (deg + 45) / 90;
			ofPoint point;

			switch (param % 4) {

			case 0:

				ofVertex(ofPoint(len, ofMap((deg + 45) % 90, 0, 89, -len, len)));
				break;
			case 1:

				ofVertex(ofPoint(ofMap((deg + 45) % 90, 0, 89, len, -len), len));
				break;
			case 2:

				ofVertex(ofPoint(-len, ofMap((deg + 45) % 90, 0, 89, len, -len)));
				break;
			case 3:

				ofVertex(ofPoint(ofMap((deg + 45) % 90, 0, 89, -len, len), -len));
				break;
			}

		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}