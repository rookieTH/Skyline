#version 330 core

in vec3 interpolateColor;

out vec3 color;

void main()
{
	color = interpolateColor; // vec3( 1.0, 0.0, 0.0 );
	  ///color = vec3(1,0,0); experiment kore dekhte hobe ektu
}
