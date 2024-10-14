#include "color.h"
#include "vec3.h"
#include "ray.h" 

#include <iostream>

bool hit_sphere(const point3& center, double radius, const ray& r) {
	vec3 oc = center - r.origin();
	auto a = dot(r.direction(),r.direction());
	auto b = -2.0 * dot(r.direction(),oc);
	auto c = dot(oc,oc) - radius*radius;
	auto discriminant = b*b - 4*a*c;
	return (discriminant >= 0);
}

color ray_color(const ray& r) {

	if (hit_sphere(point3(0,0,-1),.5,r))
		return color(1,0,0);


	vec3 unit_direction = unit_vector(r.direction());
	auto a = (0.5)*(unit_direction.y()+1.0); // map from [-1,1] to [0,1]
	return ((1.0-a)*color(1.0,1.0,1.0)) + (a*color(0.5,0.7,1.0));
}

int main() {

	//Image

	auto aspect_ratio = 16.0 / 9.0;
	int img_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	int img_height = int(img_width / aspect_ratio);
	img_height = (img_height < 1) ? 1 : img_height;

	// Camera

	auto focal_length = 1.0;
	auto viewport_height = 2.0; // arbitrary
	auto viewport_width = viewport_height * (double(img_width)/img_height);
	auto camera_center = point3(0,0,0);

	// Calculate the vectors across the horizontal and  down the vertical viewport edges
	auto viewport_u = vec3(viewport_width,0,0);
	auto viewport_v = vec3(0,-viewport_height,0);

	// Calculate the delta vectors pixel to pixel;
	auto pixel_delta_u = viewport_u / viewport_width;
	auto pixel_delta_v = viewport_v / viewport_height;

	// Calculate the location of the upper left pixel;
	auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - (viewport_u/2) - (viewport_v/2); // top left corner of the viewport
	auto pixel_00_loc = viewport_upper_left + (0.5 * (pixel_delta_u+pixel_delta_v)); // center of the top left pixel

	// Render
	std::cout << "P3\n" << img_width << " " << img_height << "\n 255\n";

	for (int j = 0; j < img_height; j++) {
		std::clog << "\rScanlines remaining: " << (img_height - j) << " " << std::flush;
		for (int i = 0; i < img_width; i++) {
			auto pixel_center = pixel_00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			ray r(camera_center, ray_direction);

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color); // is this taking std:cout as an arg?
		}
	}

	std::clog <<"\rDone     \n";
}