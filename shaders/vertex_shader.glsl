#version 420 core
layout(location=0) in vec2 vPos;
layout(location = 1) in vec3 aColor;
 out vec4 color;
void main()
 {
    gl_Position = vec4(vPos, 0.0, 1.0);
     color = vec4(aColor, 1.0);

}