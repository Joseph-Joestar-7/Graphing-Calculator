#include "GraphingCalculator.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include <iostream>
#include <vector>
#include <cmath>

GraphingCalculator::GraphingCalculator()
{
}

GraphingCalculator::~GraphingCalculator()
{
}

void GraphingCalculator::draw_axes()
{
    float vertices[] = {
        // X axis
        -1.0f, 0.0f,
         1.0f, 0.0f,

         // Y axis
          0.0f, -1.0f,
          0.0f,  1.0f,
     };

     unsigned int indices[] = {
         0, 1, // X axis
         2, 3  // Y axis
     };

     VertexArray va;
     VertexBuffer vb(vertices, 4 * 2 * sizeof(float));

     VertexBufferLayout layout;
     layout.push<float>(2);
     va.addBuffer(vb, layout);

     IndexBuffer ib(indices,4);

     Renderer renderer;
     Shader shader("res/Basic.shader");

     shader.bind();

     shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
     
     va.bind();
     ib.Bind();
     
     renderer.draw(va, ib, shader,GL_LINES);

     va.unBind();
     vb.unBind();
     ib.Unbind();
     shader.unBind();
}

//EVALUATION 
double GraphingCalculator::evaluate_trig_function(const std::string& function, double x)
{
    if (function == "sin(x)" || function == "sinx") return sin(x);
    if (function == "cos(x)" || function == "cosx") return cos(x);
    if (function == "tan(x)" || function == "tanx") return tan(x);
    if (function == "cosec(x)" || function == "cosecx") return 1 / sin(x);
    if (function == "sec(x)" || function == "secx") return 1 / cos(x);
    if (function == "cot(x)" || function == "cotx") return 1 / tan(x);
    std::cout << "Invalid Input!";
    return 0;
}

double GraphingCalculator::evaluate_linear_function(double x, double a, double b)
{
    return a * x + b;
}

double GraphingCalculator::evaluate_quadratic_function(double x, double a, double b, double c)
{
    return a * pow(x, 2) + b * x + c;
}

double GraphingCalculator::evaluate_power_function(double x, double n)
{
    return pow(x, n);
}

double GraphingCalculator::evaluate_exponential_function(double x, double a)
{
    return pow(a, x);
}

double GraphingCalculator::evaluate_cubic_function(double x, double a, double b, double c, double d)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double GraphingCalculator::evaluate_log_function(double x, double a)
{
    return log(x) / log(a);
}

double GraphingCalculator::evaluate_mod_function(double x, double a, double b)
{
    double val = a * x + b;
    return val > 0 ? val : -val;
}

//PLOTTING THE GRAPH
void GraphingCalculator::draw_trigo_function(const std::string& function)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_trig_function(function, x);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }

    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));

    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indices.data(), indices.size());

    Renderer renderer;
    Shader shader("res/Basic.shader");

    shader.bind();

    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);

    va.bind();
    ib.Bind();

    renderer.draw(va, ib, shader, GL_LINE_STRIP);

    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_linear_function(double a, double b)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_linear_function(x, a, b);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }

    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));

    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indices.data(), indices.size());

    Renderer renderer;
    Shader shader("res/Basic.shader");

    shader.bind();

    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);

    va.bind();
    ib.Bind();

    renderer.draw(va, ib, shader, GL_LINES);

    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_quadratic_function(double a, double b, double c)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_quadratic_function(x, a, b, c);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_cubic_function(double a, double b, double c, double d)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_cubic_function(x, a, b, c, d);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_power_function(double a)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_power_function(x,a);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_exponential_function(double a)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_exponential_function(x,a);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_log_function(double a)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_log_function(x,a);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}

void GraphingCalculator::draw_mod_function(double a, double b)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    // Generate vertices and indices
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        float y = evaluate_mod_function(x,a,b);
        vertices.push_back(x / 10.0);
        vertices.push_back(y / 10.0);
        indices.push_back(indices.size());
    }
    VertexArray va;
    VertexBuffer vb(vertices.data(), vertices.size() * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices.data(), indices.size());
    Renderer renderer;
    Shader shader("res/Basic.shader");
    shader.bind();
    shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
    va.bind();
    ib.Bind();
    renderer.draw(va, ib, shader, GL_LINE_STRIP);
    va.unBind();
    vb.unBind();
    ib.Unbind();
    shader.unBind();
}