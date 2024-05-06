#include <iostream>
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

    cout << "Render starting..." << endl;

    for (int x = 0; x < this->res_length; x++) {

        for (int z = 10; z < this->res_width+10; z++) {

            u_int32_t ret_color = this->scene->get_background_color();

            // get closest intersection
            // closest intersection returns a pointer to a vector
            // also takes an argument for a pointer to intersected geometry, which will be populated if
            // ray intersects with geometry or the plane

            Vec3 dest {x, 0, z};
            shared_ptr<Geometry> intersected_geom;
            Ray casted_ray { this->pos, dest};
            shared_ptr<Vec3> closest_geom_intersect;
            Plane scene_plane = this->scene->get_plane();
            double min_dist;

            closest_geom_intersect = Operations::closest_geom_intersection(casted_ray, this->scene, intersected_geom);
            
            if (closest_geom_intersect != NULL) {

                min_dist = Operations::calculate_distance(*closest_geom_intersect, this->pos);
                // now we have the closest object hit, the distance to it and the point that it was intersected at

                // create shadow ray and call trace here

                Ray shadow_ray = {*closest_geom_intersect, this->scene->get_primary_light().get_position()};

                ret_color = trace(*closest_geom_intersect, intersected_geom, shadow_ray, 5);

            }

            // determine what was hit
            
            // if intersected_geom is NULL, no geometry was hit. 
            // therefore, we have to check for either plane intersection or none.

            this->output_to_file(ret_color);

        }

    }

    cout << "Render finished." << endl;

    


}

u_int32_t Camera::trace(const Vec3& poi, shared_ptr<Geometry> intersected_geom, const Ray& ray, int depth) {

    u_int32_t ret_val;

    Light scene_light = this->scene->get_primary_light();

    if (intersected_geom->get_reflective()) { // if the intersected geometry is reflective

        

    } else if (intersected_geom->get_refractive_ind() != 800) { // if the intersected geometry is refractive


    } else { 
        // this condition triggers if intersected geometry is not reflective or refractive. 
        // in this case, simply draw a ray to the light.
        // if blocked, the point is in shadow. if blocked by a reflective object call trace recursively

        // calculate a new ray to the light

        Vec3 direction = scene_light.get_position() - poi; // this is the direction vector
        bool in_shadow = false;
        shared_ptr<Geometry> obstruction;

        for (shared_ptr<Geometry> g : this->scene->get_geometry()) {

            shared_ptr<Vec3> intersect_pt = g->intersect(ray);

            obstruction = g;

            if (intersect_pt != NULL) {

                // this means that there is an intersection on the way to the light --> an obstruction

                in_shadow = true;
                break;

            }

        }

        if (!in_shadow) {

            ret_val = obstruction->get_color() * scene_light.get_luminosity();

        } else {

            ret_val = this->scene->get_background_color();

        }
    }

    return ret_val;

}

bool Camera::output_to_file(u_int32_t color) {

    int color_mask = 0x000000FF;

    int red = (color >> 16) & color_mask;
    int green = (color >> 8) & color_mask;
    int blue = (color) & color_mask;

    this->file << red << ' ' << green << ' ' << blue << "\n";

    return true;

}


