#include "ofApp.h"


void buildMesh(ofMesh&, float, float, glm::vec3);

//--------------------------------------------------------------
void ofApp::setup() {
	using namespace glm;
	buildMesh(charMesh, 0.35f, 0.45f, vec3(-0.2f, -0.25f, 0.0f));
	buildMesh(backgroundMesh, 1, 1, vec3(0, 0, 0.5));
	buildMesh(frameMesh, 1, 1, vec3(0, 0 , -0.1));
	buildMesh(sunRaysMesh, 1, 1, vec3(0, 0, -0.05));
	buildMesh(portalMesh, 0.45f, 0.5f, vec3(0.45f, -0.15f, 0.0f));
	ofDisableArbTex();
	ofEnableDepthTest();

	charImage.load("character.png");
	backgroundImage.load("background.jpg");
	frameImage.load("flare.png");
	sunRays.load("sunRays.png");
	portalImage.load("portal.png");
	charShader.load("passthrough_v2.vert", "alphaTest.frag");
	frameShader.load("passthrough_v2.vert", "flare.frag");
	portalShader.load("spriteSheet.vert", "flare.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	static float frame = 0.0f;
	frame = (frame > 15) ? 0.0f : frame + 0.2;
	glm::vec2 spriteSize = glm::vec2(0.25, 0.25);
	glm::vec2 spriteFrame = glm::vec2((int)frame % 4, (int)(frame/4) % 4);

	ofDisableBlendMode();
	ofEnableDepthTest();
	charShader.begin();
	charShader.setUniformTexture("shaderTexture", charImage, 0);
	charMesh.draw();

	charShader.setUniformTexture("shaderTexture", backgroundImage, 0);
	backgroundMesh.draw();
	charShader.end();

	ofDisableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
	portalShader.begin();
	portalShader.setUniformTexture("shaderTexture", portalImage, 0);
	portalShader.setUniform2f("size", spriteSize);
	portalShader.setUniform2f("offset", spriteFrame);
	portalMesh.draw();
	portalShader.end();

	frameShader.begin();
	frameShader.setUniformTexture("shaderTexture", frameImage, 0);
	frameMesh.draw();

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	frameShader.setUniformTexture("shaderTexture", sunRays, 0);
	sunRaysMesh.draw();
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
