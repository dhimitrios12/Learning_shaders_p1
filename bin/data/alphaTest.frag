#version 410

uniform sampler2D shaderTexture;

in vec2 fragUV;
out vec4 outColor;

void main(){
	outColor = texture(shaderTexture, fragUV);
	if(outColor.a < 1.0) discard;
}