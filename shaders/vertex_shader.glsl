#version 420
layout(location=0) in vec2 vPos;
out vec4 color;
void main()
 {
    gl_Position = vec4(vPos, 0.0, 1.0);
     color = vec4(vPos, 1, 1);

}