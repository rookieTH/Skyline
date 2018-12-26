#version 330 core

in vec3 interpolateColor;// = vec3(0.0f,0.50f,0.0f);

out vec3 color;

void main()
{
	color = interpolateColor; // vec3( 1.0, 0.0, 0.0 );
}
