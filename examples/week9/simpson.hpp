#include <stdexcept>

// Simpson-Integration von Funktion f von a nach b mit N Schritten
// Rueckgabewert ist der Wert des Integrals

double simpson(double (*f)(double), double a, double b, unsigned int N);

