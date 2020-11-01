#version 410

layout (location = 0) in vec3 position; // 1- Position
// 2- Color
// 3- Normal
layout (location = 3) in vec2 uvData; // 4- UV

out vec2 fragUV;

void main(){
	gl_Position = vec4(position, 1.0);
	fragUV = vec2(uvData.x, 1.0 - uvData.y);
}