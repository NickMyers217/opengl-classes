#version 440

in vec3 pos_world;
in vec3 color;
in vec3 normal;

uniform vec3 ambientLight;
uniform vec3 lightPos_world;

out vec4 fragColor;


void main()
{
	// Diffuse
	vec3 lightVec = normalize(lightPos_world - pos_world);
	float brightness = clamp(dot(lightVec, normal), 0.0, 1.0);
	vec3 diffuse = vec3(brightness, brightness, brightness);

	// Total light
	vec3 lightColor = diffuse + ambientLight;

	fragColor = vec4(color * lightColor, 1.0);
}
