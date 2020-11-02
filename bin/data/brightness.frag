#version 410

uniform sampler2D abstract_texture;
uniform float brightness;

in vec2 fragUV;
out vec4 outColor;

void main(){
	vec4 text = texture(abstract_texture, fragUV);
	text *= brightness;
	outColor = text;
}