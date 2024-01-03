#include <iostream>
#include "Config.h"
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;

int main(void) {

	cout << "LightWizard Version " << VERSION_MAJOR << endl;
	
	// IMAGE
	
	int image_width = 1920;
	int image_height = 1080;

	// RENDER SECTION
	
	// REDIRECT OUTPUT
	fstream file;
	file.open("render_output.ppm", std::ios::out);
	

	// BACKUP STREAMBUFFERS FOR COUT
	std::streambuf* stream_buff_cout = cout.rdbuf();
	
	std::streambuf* stream_buff_file = file.rdbuf();
	
	cout.rdbuf(stream_buff_file);
	
	// WRITE TO FILE
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	for (int j = 0; j < image_height; j++) {
	
		for (int i = 0; i < image_width; i++) {
		
			auto r = double(i) / (image_width-1);
			auto g = double(j) / (image_height-1);
			auto b = 0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			cout << ir << ' ' << ig << ' ' << ib << '\n';
		
		}
	
	}

	return 0;

}
