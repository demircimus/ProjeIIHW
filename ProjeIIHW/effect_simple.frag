#version 120

uniform sampler2D fbo_texture;
uniform sampler2D rampImage;
varying vec2 f_texcoord;

void main(void) {
    vec2 texcoord = f_texcoord;
	vec3 Color1 = texture2D(fbo_texture, texcoord).xyz;
	vec3 Color2;

	//need cast.
	Color2.r = texture2D(rampImage, vec2(Color1.r, 1)).r;
	Color2.g = texture2D(rampImage, vec2(Color1.g, 1)).g;
	Color2.b = texture2D(rampImage, vec2(Color1.b, 1)).b;

    gl_FragColor = vec4(Color2, 1);
}