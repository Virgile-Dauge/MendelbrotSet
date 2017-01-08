#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
  img.setColor(ofColor::black);
  maxIterations = 100;
  pMin = -1.2;
  pMax = 1.2;
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto px = 0; px < ofGetWidth(); px++) {
    for (auto py = 0; py < ofGetHeight(); py++) {
      // std::cout << "(" << px << "," << py << ")"<< "\n";
      int iteration = 0;
      float x = ofMap(px, 0, ofGetWidth(), pMin, pMax);
      float y = ofMap(py, 0, ofGetHeight(), pMin, pMax);
      float const x0 = x;
      float const y0 = y;
      while (x * x + y * y < 16 && iteration < maxIterations) {
        float xx = x * x - y * y;
        float yy = 2 * x * y;
        x = xx + 0.285;
        // x = xx + x0;
        y = yy + 0.01;
        // y = yy + y0;
        iteration++;
      }
      // the range of each of the arguments here is 0..255 so we map i and j to
      // that range.
      ofColor c = ofColor(0); // c is black
      if (iteration != maxIterations) {
        c.setHsb(ofMap(iteration, 0, maxIterations, 0, 255), 200, 230);
        // c.setHsb(
        //     ofMap(sqrt(ofMap(iteration, 0, maxIterations, 0, 1)), 0, 1, 0,
        //     255),
        //     220, 200);
      }

      img.setColor(px, py, c);
    }
  }
  // pMin += 0.01;
  // pMax -= 0.01;
  img.update();
}

//--------------------------------------------------------------
void ofApp::draw() { img.draw(0, 0); }

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
  img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
