#pragma once
#include <string>
#include "Renderer.h"
#include "Shader.h"
class GraphingCalculator
{
public:
    GraphingCalculator();
    ~GraphingCalculator();
    void draw_axes();

    //Evaluating the functions
    double evaluate_trig_function(const std::string& function, double x);
    double evaluate_linear_function(double x, double a, double b);
    double evaluate_quadratic_function(double x, double a, double b, double c);
    double evaluate_power_function(double x, double n);
    double evaluate_exponential_function(double x, double a);
    double evaluate_cubic_function(double x, double a, double b, double c, double d);
    double evaluate_log_function(double x, double a);
    double evaluate_mod_function(double x, double a, double b);

    //Drawing the functions
    void draw_trigo_function(const std::string& function);
    void draw_linear_function(double a, double b);
    void draw_quadratic_function(double a, double b, double c);
    void draw_cubic_function(double a, double b, double c, double d);
    void draw_power_function(double a);
    void draw_exponential_function(double a);
    void draw_log_function(double a);
    void draw_mod_function(double a, double b);
};