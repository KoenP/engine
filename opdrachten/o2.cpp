#include "../EasyImage.h"
#include <vector>
#include <cmath>
#include <iostream>

void blocks(img::EasyImage& image, int w, int h, int nx, int ny, const std::vector<double>& colorwhite, const std::vector<double>& colorblack, bool invertcolors)
{
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int rectindex = (nx * (y / (h/ny))) + (x / (w/nx));
			bool white = 
			image(x,y).red = colorwhite[0] * (rectindex % 2);
		}
	}	
}
