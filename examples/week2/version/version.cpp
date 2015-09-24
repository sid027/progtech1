#include "square.hpp"

#define SQUARE_VERSION_MAJOR "1"
#define SQUARE_VERSION_MINOR "1"
#define SQUARE_VERSION SQUARE_VERSION_MAJOR"."SQUARE_VERSION_MINOR

std::string square::version()
{
  return SQUARE_VERSION;
}
