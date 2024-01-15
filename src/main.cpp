#include <iostream>
#include <fstream>
#include "Config.h"
#include "../lib/graphics_lib/camera.h"
#include "../lib/graphics_lib/scene.h"
#include "../lib/graphics_lib/vec3.h"

using std::cout;
using std::endl;
using std::fstream;

int main(void) {


	cout << R"(
 _       _________ _______          _________         _________ _______  _______  _______  ______  
( \      \__   __/(  ____ \|\     /|\__   __/|\     /|\__   __// ___   )(  ___  )(  ____ )(  __  \ 
| (         ) (   | (    \/| )   ( |   ) (   | )   ( |   ) (   \/   )  || (   ) || (    )|| (  \  )
| |         | |   | |      | (___) |   | |   | | _ | |   | |       /   )| (___) || (____)|| |   ) |
| |         | |   | | ____ |  ___  |   | |   | |( )| |   | |      /   / |  ___  ||     __)| |   | |
| |         | |   | | \_  )| (   ) |   | |   | || || |   | |     /   /  | (   ) || (\ (   | |   ) |
| (____/\___) (___| (___) || )   ( |   | |   | () () |___) (___ /   (_/\| )   ( || ) \ \__| (__/  )
(_______/\_______/(_______)|/     \|   )_(   (_______)\_______/(_______/|/     \||/   \__/(______/ 
                                                                                                   
)" << "\n";

	cout << R"(           .

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

	cout << "\n\033[31m\e[1mVersion " << VERSION_MAJOR << "." << VERSION_MINOR <<  " by Dhruva Rayasam" << "\e[0m\n";

	cout << "\nArtwork credit: Row on ASCII Art Archive\n" << endl;

	Vec3 v1{1, 2, 3};
    Vec3 v2{2, 3, 4};

    Vec3 v3 = v1 + v2;

    cout << v3 << endl;

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
