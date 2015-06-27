#version 440

layout(location = 0) in vec3 vertexPos_model;
layout(location = 1) in vec3 vertexNormal_model;
layout(location = 2) in vec2 vertexUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 pos_world;
out vec3 normal_world;
out vec2 uv;


void main()
{
	gl_Position = (projection * view * model) * vec4(vertexPos_model, 1.0);

	pos_world = vec3(model * vec4(vertexPos_model, 1.0));
	normal_world = vec3(model * vec4(vertexNormal_model, 0.0));
	uv = vertexUV;
}

