#include "../EasyImage.h"
#include <vector>
#include <cmath>
#include <iostream>

void blocks(img::EasyImage& image, int w, int h, int nx, int ny, const std::vector<int>& colorwhite, const std::vector<int>& colorblack, bool invertcolors)
{
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int rectindex = (nx * (y / (h/ny))) + (x / (w/nx));
			bool white = (rectindex + (int) invertcolors) % 2;
			image(x,y).red = colorwhite[0] * white + colorblack[0] * !white;
            //std::cout << colorwhite[0] * white + colorblack[0] * !white << std::endl;
			image(x,y).green = colorwhite[1] * white + colorblack[1] * !white;
			image(x,y).blue = colorwhite[2] * white + colorblack[2] * !white;
		}
	}	
}
