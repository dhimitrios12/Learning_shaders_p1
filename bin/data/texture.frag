#version 410

uniform sampler2D abstract_texture;
in vec2 fragUV;

out vec4 outCol;

void main(){
	outCol = texture(abstract_texture, fragUV);
}