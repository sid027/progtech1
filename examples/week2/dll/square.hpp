#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <string>

#ifdef _MSC_VER
  #ifdef BUILD_DLL
    #define DECLSPEC __declspec(dllexport)
  #else
    #define DECLSPEC __declspec(dllimport)
  #endif
#else
  #define DECLSPEC
#endif

namespace square {
  // just the function definition
  DECLSPEC double square(double);
  DECLSPEC std::string version();
}

#endif
