#version 140

uniform mat4 projection_matrix = mat4(
        2/800.0, 0.0, 0.0, 0.0,
        0.0, 2/600.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        -1.0, -1.0, 0.0, 1.0
        );
uniform mat4 modelview_matrix = mat4(
        200.0, 0.0, 0.0, 0.0,
        0.0, 200.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        200.0, 200.0, 0.0, 1.0
        );

in vec3 position;
in vec2 texCoords;
out vec2 _texCoords;

void main(void) {
        gl_Position = projection_matrix * modelview_matrix * vec4(position, 1.0);
        _texCoords = texCoords;
}
