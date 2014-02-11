#include "EasyImage.h"
#include "ini_configuration.hh"
#include "opdrachten/o1.cpp"
#include "opdrachten/o2.cpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<int> color_doubletuple_to_inttuple(const std::vector<double> doublecolor) {
    std::vector<int> intcolor(3);
    for (int i = 0; i < 3; i++) intcolor[i] = (int) (doublecolor[i] * 255.0);
    return intcolor;
}

img::EasyImage generate_image(const ini::Configuration &configuration)
{
	std::string type = configuration["General"]["type"].as_string_or_die();
	int width = configuration["ImageProperties"]["width"].as_int_or_die(); 
	int height = configuration["ImageProperties"]["height"].as_int_or_die(); 
	//width = 256; height=256;
	img::EasyImage generatedimg = img::EasyImage(width, height);
	
	if (type == "IntroColorRectangle") {
		color_rectangle(generatedimg, width, height);
	} else if (type == "IntroBlocks") {
		int nx = configuration["BlockProperties"]["nrXBlocks"].as_int_or_die();
		int ny = configuration["BlockProperties"]["nrYBlocks"].as_int_or_die();
		std::vector<double> colorwhite = configuration["BlockProperties"]["colorWhite"].as_double_tuple_or_die();
		std::vector<double> colorblack = configuration["BlockProperties"]["colorBlack"].as_double_tuple_or_die();
		bool invertcolors = configuration["BlockProperties"]["invertColors"].as_bool_or_die();
		blocks(generatedimg, width, height, nx, ny, color_doubletuple_to_inttuple(colorwhite), color_doubletuple_to_inttuple(colorblack), invertcolors);
	}
		
	return generatedimg;
}

int main(int argc, char const* argv[])
{
        int retVal = 0;
        try
        {
                for(int i = 1; i < argc; ++i)
                {
                        ini::Configuration conf;
                        try
                        {
                                std::ifstream fin(argv[i]);
                                fin >> conf;
                                fin.close();
                        }
                        catch(ini::ParseException& ex)
                        {
                                std::cerr << "Error parsing file: " << argv[i] << ": " << ex.what() << std::endl;
                                retVal = 1;
                                continue;
                        }

                        img::EasyImage image = generate_image(conf);
                        if(image.get_height() > 0 && image.get_width() > 0)
                        {
                                std::string fileName(argv[i]);
                                std::string::size_type pos = fileName.rfind('.');
                                if(pos == std::string::npos)
                                {
                                        //filename does not contain a '.' --> append a '.bmp' suffix
                                        fileName += ".bmp";
                                }
                                else
                                {
                                        fileName = fileName.substr(0,pos) + ".bmp";
                                }
                                try
                                {
                                        std::ofstream f_out(fileName.c_str(),std::ios::trunc | std::ios::out | std::ios::binary);
                                        f_out << image;

                                }
                                catch(std::exception& ex)
                                {
                                        std::cerr << "Failed to write image to file: " << ex.what() << std::endl;
                                        retVal = 1;
                                }
                        }
                        else
                        {
                                std::cout << "Could not generate image for " << argv[i] << std::endl;
                        }
                }
        }
        catch(const std::bad_alloc &exception)
        {
    		//When you run out of memory this exception is thrown. When this happens the return value of the program MUST be '100'.
    		//Basically this return value tells our automated test scripts to run your engine on a pc with more memory.
    		//(Unless of course you are already consuming the maximum allowed amount of memory) 
    		//If your engine does NOT adhere to this requirement you risk losing points because then our scripts will 
		//mark the test as failed while in reality it just needed a bit more memory
                std::cerr << "Error: insufficient memory" << std::endl;
                retVal = 100;
        }
        return retVal;
}
