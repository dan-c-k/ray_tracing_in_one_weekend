#ifndef COLOR_H // how do tese ifdef and define statements work
#define COLOR_H

#include "vec3.h" // why is this a string?

#include <iostream> // why is this in brackets?

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
	auto r = pixel_color.x(); // what does auto mean again?
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	//[0,1] --> [0,255]
	int rbyte = int(255.999 * r); // don't understand this mapping
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	//Write out the pixel color
	out << rbyte << " " << gbyte << " " << bbyte << "\n"; // why just out here? not std:out?
}

#endif 
