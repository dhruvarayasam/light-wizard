#include <iostream>
#include <fstream>
#include "Config.h"
#include "../lib/ray_lib/ray.h"


using std::cout;
using std::endl;
using std::fstream;

int main(void) {

	cout << "\nLightWizard Version " << VERSION_MAJOR << "\n";

	cout << R"(                  .

                   .
         /^\     .
    /\   "V"
   /__\   I      O  o
  //..\\  I     .
  \].`[/  I
  /l\/j\  (]    .  O
 /. ~~ ,\/I          .
 \\L__j^\/I       o
  \/--v}  I     o   .
  |    |  I   _________
  |    |  I c(`       ')o
  |    l  I   \.     ,/
_/j  L l\_!  _//^---^\\_ )" << "\n";

	cout << "\nArtwork credit: Row on ASCII Art Archive\n" << endl;

	Ray r1 {1.0f, 2.0f, 3.0f};
	Ray r2 {4.0f, 5.0f, 6.0f};

	Ray r3 = r1 - r2;

	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	

	// IMAGE
/*	
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
*/
	return 0;

}
