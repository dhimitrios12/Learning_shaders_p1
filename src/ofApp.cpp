#include "ofApp.h"


void buildMesh(ofMesh&, float, float, glm::vec3);

//--------------------------------------------------------------
void ofApp::setup() {
	buildMesh(charMesh, 0.35f, 0.45f, glm::vec3(-0.0f, -0.25f, 0.0f));
	buildMesh(backgroundMesh, 1, 1, glm::vec3(0, 0, 0.5));
	buildMesh(frameMesh, 1, 1, glm::vec3(0, 0 , -0.1));
	ofDisableArbTex();
	//ofDisableAlphaBlending();
	ofEnableDepthTest();

	charImage.load("character.png");
	backgroundImage.load("background.jpg");
	frameImage.load("flare.png");
	charShader.load("passthrough_v2.vert", "alphaTest.frag");
	frameShader.load("passthrough_v2.vert", "flare.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	charShader.begin();
	charShader.setUniformTexture("shaderTexture", charImage, 0);
	charMesh.draw();

	charShader.setUniformTexture("shaderTexture", backgroundImage, 0);
	backgroundMesh.draw();
	charShader.end();

	frameShader.begin();
	frameShader.setUniformTexture("shaderTexture", frameImage, 0);
	frameMesh.draw();
	frameShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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

void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos) {
	float verts[] = {-w + pos.x, -h + pos.y, pos.z,
					-w + pos.x, h + pos.y, pos.z,
					w + pos.x, h + pos.y, pos.x,
					w + pos.x, -h + pos.y, pos.z};

	float uvs[] = {0,0 , 0,1, 1,1, 1,0};

	for (int i = 0; i < 4; i++) {
		int meshVertIndex = i * 3;
		int uvVertIndex = i * 2;

		mesh.addVertex(glm::vec3(verts[meshVertIndex], verts[meshVertIndex + 1], verts[meshVertIndex + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvVertIndex], uvs[uvVertIndex + 1]));
	}

	ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0};
	mesh.addIndices(indices, 6);
}
