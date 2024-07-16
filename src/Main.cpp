#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GraphingCalculator.h"
#include "Renderer.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    //Using OpenGL 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 1024, "GRAPHING CALCULATOR", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    GraphingCalculator calculator;

    char typ;
    std::string function;
    int a, b, c, d;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        calculator.draw_axes();
        //INPUT
        std::cout << "Enter type of function:\n   't'- trigonometric\n   'l' - linear\n   'q' - quadratic\n   'c' - cubic\n   'p' - power\n   'e' - exponential\n   'L' - logarithmic\n   'm' - modulus\n";
        std::cin >> typ;

        switch (typ)
        {
        case 't':
            std::cout << "Enter the type of trigonometric function\nf(x): ";
            std::cin >> function;
            calculator.draw_trigo_function(function);
            break;
        case 'l':
            std::cout << "f(x) = ax+b\n Enter a and b: ";
            std::cin >> a >> b;
            calculator.draw_linear_function(a, b);
            break;
        case 'q':
            std::cout << "f(x) = ax^2+bx+c\n Enter a,b,c: ";
            std::cin >> a >> b >> c;
            calculator.draw_quadratic_function(a, b, c);
            break;
        case 'c':
            std::cout << "f(x) = ax^3+bx^2+cx+d\n  Enter a,b,c,d: ";
            std::cin >> a >> b >> c >> d;
            calculator.draw_cubic_function(a, b, c, d);
            break;
        case 'p':
            std::cout << "f(x) = x^a\n Enter a: ";
            std::cin >> a;
            calculator.draw_power_function(a);
            break;
        case 'e':
            std::cout << "f(x) = a^x\n Enter a: ";
            std::cin >> a;
            calculator.draw_exponential_function(a);
            break;
        case 'L':
            std::cout << "f(x) = log_a(x)\n Enter base i.e, a: ";
            std::cin >> a;
            calculator.draw_log_function(a);
            break;
        case 'm':
            std::cout << "f(x) = |ax+b|\n Enter a and b: ";
            std::cin >> a >> b;
            calculator.draw_mod_function(a, b);
            break;
        default:
            std::cout << "Invalid input\n Nothing will be drawn on the axes\n";
            break;
        }
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        

        std::cout << "Enter B if you want to clear the screen and plot another curve\n";
        std::cout << "Enter Q if you want to quit\n";
        std::cin >> typ;

        if (typ == 'B')
        {
            continue;
        }
        else if (typ == 'Q')
        {
            std::cout << "Bye Have a Great Day\n";
            break;
        }

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}