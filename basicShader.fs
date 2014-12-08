#version 330

// in vec4 color;

out vec4 fragColor;

uniform vec3 color;

void main() {
  fragColor = vec4(color,1);
}
