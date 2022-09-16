#version 330

varying vec3 new_color;

void main() {
  gl_FragColor = vec4(new_color, 1.0);
}
