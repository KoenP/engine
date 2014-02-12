#include "EasyImage.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>

void draw(img::EasyImage& image, int x, int y, const std::vector<int>& color)
{
	image(x, y).red = color[0];
	image(x, y).green = color[1];
	image(x, y).blue = color[2];
}

void draw_vertical(img::EasyImage& image, int x, int y1, int y2, const std::vector<int>& color)
{
	int biggesty = std::max(y1, y2);
	int smallesty = std::min(y1, y2);
	for (int y = smallesty; y < biggesty; y++) {
		draw(image, x, y, color);
	}
}

void draw_horizontal(img::EasyImage& image, int y, int x1, int x2, const std::vector<int>& color)
{
	int biggestx = std::max(x1, x2);
	int smallestx = std::min(x1, x2);
	for (int x = smallestx; x < biggestx; x++) {
		draw(image, x, y, color);
	}
}

void draw_small_pos_gradient(img::EasyImage& image, int x1, int y1, int x2, int y2)
{
	
	for (int x = x1
}

void draw_line(img::EasyImage& image, int x1, int y1, int x2, int y2, const std::vector<int>& color)
{
	int xdist = abs(x2 - x1);
	int ydist = abs(y2 - y1);
	if (xdist == 0) draw_vertical(image, x1, y1, y2, color);
	else if (ydist == 0) draw_horizontal(image, y1, x1, x2, color);
}
