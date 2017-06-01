#pragma once

typedef unsigned char uchar;

namespace gui{
  struct color{
    uchar r, g, b;
    color(uchar r = 0, uchar g = 0, uchar b = 0) : r(r), g(g), b(b){}
  };
};
