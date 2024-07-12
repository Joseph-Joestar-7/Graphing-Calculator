#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;

// Hard-coded projection matrix for orthographic projection
const mat4 projection = mat4(
    vec4(2.0 / (1.0 - (-1.0)), 0.0, 0.0, 0.0),
    vec4(0.0, 2.0 / (1.0 - (-1.0)), 0.0, 0.0),
    vec4(0.0, 0.0, -2.0 / (1.0 - (-1.0)), 0.0),
    vec4(-(1.0 + (-1.0)) / (1.0 - (-1.0)), -(1.0 + (-1.0)) / (1.0 - (-1.0)), -(1.0 + (-1.0)) / (1.0 - (-1.0)), 1.0)
);

// Hard-coded model view matrix (identity matrix)
const mat4 modelView = mat4(
    vec4(1.0, 0.0, 0.0, 0.0),
    vec4(0.0, 1.0, 0.0, 0.0),
    vec4(0.0, 0.0, 1.0, 0.0),
    vec4(0.0, 0.0, 0.0, 1.0)
);


void main()
{
    gl_Position = projection* modelView * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core
out vec4 FragColor;

uniform vec4 uColor; 

void main()
{
    FragColor = uColor;
}
