#version 440

in vec3 pos_world;
in vec3 normal_world;
in vec3 color;

uniform vec3 ambientLight;
uniform vec3 lightPos_world;
uniform vec3 eyePos_world;

out vec4 fragColor;


vec3 calcDiffuseLight(vec3 lightVec_world)
{
	float brightness = dot(lightVec_world, normalize(normal_world));
	vec3 diffuse = clamp(vec3(brightness, brightness, brightness), 0.0, 1.0);

	return diffuse;
}


vec3 calcSpecularLight(vec3 lightVec_world, int exponent)
{
	vec3 reflectLight = reflect(-lightVec_world, normal_world);
	vec3 eyeVec_world = normalize(eyePos_world - pos_world);
	float s = pow(dot(reflectLight, eyeVec_world), exponent);
	vec3 specular = clamp(vec3(0, 0, s), 0.0, 1.0);

	return specular;
}


void main()
{
	//Light calculations
	vec3 lightVec_world = normalize(lightPos_world - pos_world);
	vec3 lightColor = ambientLight + calcDiffuseLight(lightVec_world) + calcSpecularLight(lightVec_world, 64);

	fragColor = vec4(color * lightColor, 1.0);
}
