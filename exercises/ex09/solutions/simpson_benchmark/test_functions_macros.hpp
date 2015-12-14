/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.2
 */

#ifndef SIMPSON_TEST_FUNCTIONS_MACROS_
#define SIMPSON_TEST_FUNCTIONS_MACROS_


#ifdef F1
    #define FUNCTION_TO_INTEGRATE(x) (0.0)
    #define INTEGRAL(x) (0.0)
    #define FUNCTION_TO_INTEGRATE_NAME "0.0"
    #define FUNCTION_NUMBER 1
#elif F2
    #define FUNCTION_TO_INTEGRATE(x) (1.0)
    #define INTEGRAL(x) (x)
    #define FUNCTION_TO_INTEGRATE_NAME "1.0"
    #define FUNCTION_NUMBER 2
#elif F3
    #define FUNCTION_TO_INTEGRATE(x) (x)
    #define INTEGRAL(x) ((x)*(x)/2.0)
    #define FUNCTION_TO_INTEGRATE_NAME "x"
    #define FUNCTION_NUMBER 3
#elif F4
    #define FUNCTION_TO_INTEGRATE(x) ((x)*(x))
    #define INTEGRAL(x) ((x)*(x)*(x)/3.0)
    #define FUNCTION_TO_INTEGRATE_NAME "x*x"
    #define FUNCTION_NUMBER 4
#elif F5
    #include<cmath>
    #define FUNCTION_TO_INTEGRATE(x) (std::sin(x))
    #define INTEGRAL(x) (-std::cos(x))
    #define FUNCTION_TO_INTEGRATE_NAME "sin(x)"
    #define FUNCTION_NUMBER 5
#elif F6
    #include<cmath>
    #define FUNCTION_TO_INTEGRATE(x) (std::sin(5.*(x)))
    #define INTEGRAL(x) (-0.2*std::cos(5.*(x)))
    #define FUNCTION_TO_INTEGRATE_NAME "sin(5x)"
    #define FUNCTION_NUMBER 6
#else
    #error Define function to be integrated: F1,F2,...,F6
#endif


#endif //SIMPSON_TEST_FUNCTIONS_MACROS_
