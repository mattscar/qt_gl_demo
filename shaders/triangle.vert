#version 330

attribute vec2 in_coords;
attribute vec3 in_color;
varying vec3 new_color;

vec2 offset[4] = vec2[4] (
  vec2(-0.5, -0.5), vec2(-0.5, 0.5),
  vec2(0.5, -0.5), vec2(0.5, 0.5));

void main(void) {

  // Apply the offset based on the instance
  gl_Position = vec4(in_coords + offset[gl_InstanceID], 0.0, 1.0);

  new_color = in_color;
}
