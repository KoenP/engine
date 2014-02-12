#include "../EasyImage.h"

void quartercircle(img::EasyImage& image, int w, int h, int nlines, const img::Color& color)
{
	image.draw_line(1, 1, 1, h-1, color);
	image.draw_line(1, h-1, w-1, h-1, color);
	
}


