#include "../EasyImage.h"
#include <vector>
#include <cmath>
#include <iostream>

void blocks(img::EasyImage& image, int w, int h, int nx, int ny, const std::vector<double>& colorwhite, const std::vector<double>& colorblack, bool invertcolors)
{
	std::cout << "test" << std::endl;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			//int rectindex = (nx * (y / (h/ny))) + (x / (w/nx));
			int rectindex = x / w + nx * (y / h);
			image(x,y).red = 255 * (rectindex % 2);
		}
	}	
}
