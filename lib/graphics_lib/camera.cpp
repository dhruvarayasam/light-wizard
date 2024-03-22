#include <iostream>
#include <cmath>
#include "camera.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::ofstream;

Camera::Camera(int length, int width, shared_ptr<Scene> s, string filename) : res_length(length), res_width(width), scene(s), file(filename) {

    cout << "Scene compilation initialized at resolution " << length << " x " << width << "." << "\n";

    file << "P3" << "\n" << length << " " << width << "\n" << 255 << "\n";

    cout << "Output filestream opened successfully. Moving on to render." << endl;
}

void Camera::render() {

    /*
    KEEP IN MIND: WE HAVE TO SET LIGHTING RELATIVE TO RESOLUTION ALONG
    WITH OTHER SCALING OPERATIONS. 
    */

    Ray casted_ray {this->pos, Vec3 {0, 0, 0}};
    Plane plane = this->scene->get_plane();

    cout << "Render starting..." << endl;

    for (int z = this->res_length; z > 0; z--) {

        for (int x = 0; x < this->res_width; x++) {

            u_int32_t ret_color;
            Vec3 new_dest  = Vec3{x, 0, z+2} - this->pos; // raster image is 2 pixels above the plane 

            // Vec3 new_dest = Vec3 {x, 0, z+2};

            // check that new_dest is updated here if it is the zero vector
            casted_ray.set_dest(new_dest);

            // get closest intersection
            // closest intersection returns a pointer to a vector
            // also takes an argument for a pointer to intersected geometry, which will be populated if
            // ray intersects with geometry

            // first check for intersections w/ geometry
                // if intersection exists (and object is diffuse), generate a new ray towards the light; if unobstructed calculate and return color
                // if obstructed, then that point is in shadow
            // then check for intersections w/ plane --> color plane accordingly
            // if no intersections, then return background color of the scene


            shared_ptr<Geometry> intersected_geom;
            shared_ptr<Vec3> closest_poi = NULL;
            shared_ptr<Scene> s = this->scene;

            // check for the closest intersection here --> if there is one, populate intersected_geom and 
            // closest_geom_intersect w/ POI

            // if there is absolutely no intersection, check for plane intersection

            // if there is neither, then return background color
            vector<shared_ptr<Geometry>> scene_geometry = s->get_geometry();

            double min_dist = INT64_MAX;

            for (shared_ptr<Geometry> geom : scene_geometry) {

                shared_ptr<Vec3> curr_poi = geom->calculate_poi(casted_ray);

                if (curr_poi != NULL) {
                    
                    double dist = Operations::calculate_distance(this->pos, *closest_poi);

                    if (dist < min_dist) {

                        closest_poi = curr_poi;
                        intersected_geom = geom;
                        min_dist = dist;

                    }

                }

            }

            // now that we have the closest geometry that was intersected and its point of intersection, 
            // we can calculate the color that must be returned, based on reflection/refraction

            if (intersected_geom == NULL && !plane.intersect(casted_ray)) {

                output_to_file(this->scene->get_background_color());

            } else if (intersected_geom == NULL) {

                output_to_file(plane.get_plane_color()); // temporary measure, we will have to calculate exact shading of plane later on

            } else { // compute color of geometry here



            }
            


            



        }

    }

    cout << "Render finished." << endl;

    


}

u_int32_t Camera::trace(const Vec3& poi, shared_ptr<Geometry> intersected_geom, const Ray& ray, int depth) {

    return 0;

}

bool Camera::output_to_file(u_int32_t color) {

    int color_mask = 0x000000FF;

    u_int32_t red = (color >> 16) & color_mask;
    u_int32_t green = (color >> 8) & color_mask;
    u_int32_t blue = (color) & color_mask;

    this->file << red << ' ' << green << ' ' << blue << "\n";

    return true;

}