#include "../EasyImage.h"

void color_rectangle(img::EasyImage& image, int width, int height)
{
        for (int x = 0; x < width; x++)
        {
                for (int y = 0; y < height; y++)
                {
                        image(x, y).red = 256 * x / width;
                        image(x, y).green = 256 * y / height;  
                        image(x, y).blue = (x+y) * 256 / ((width+height)/2);
                }
        }
}
