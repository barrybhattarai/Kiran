#version 420 core
layout(location=0) in vec3 vPos;
layout(location = 1) in vec3 aColor;
uniform  mat4 transform;
out vec4 color;
void main()
{
    gl_Position = transform * vec4(vPos, 1.0);
    color = vec4(aColor, 1.0);

}