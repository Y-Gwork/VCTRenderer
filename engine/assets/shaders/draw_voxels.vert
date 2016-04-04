#version 430

out vec4 albedo;

layout(binding = 0, rgba8) uniform readonly image3D voxelRadiance;

uniform uint volumeDimension;
uniform uint direction = 0;

void main()
{
	float volumeDimensionF = float(volumeDimension);

	vec3 position = vec3
	(
		gl_VertexID % volumeDimension,
		(gl_VertexID / volumeDimension) % volumeDimension,
		gl_VertexID / (volumeDimension * volumeDimension)
	);

	ivec3 texPos = ivec3(position.x + volumeDimension * direction, position.yz);

	albedo = imageLoad(voxelRadiance, ivec3(texPos));
	gl_Position = vec4(position, 1.0f);
}