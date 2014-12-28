#version 140

in vec2 _texCoords;

uniform sampler2D textureID;

void main() {
        gl_FragColor = texture(textureID, _texCoords);
}
