#include "tgaimage.h"
#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
  /* 
     m is the slope of the line
     y increases by m every time x increases by 1
   */
  float m = (y1-y0) / (float)(x1-x0);
  std::cout << m << std::endl;

  float y = y0;
  
  for (int x=0; x<=x1; x++){
    y += m;
    image.set(x, y, color);
  }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(13, 20, 80, 40, image, white);
    line(10, 35, 50, 40, image, red);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}

