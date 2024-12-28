#include "vector.h"
#include "matrix.h"
#include "display.h"
#include "camera.h"
#include "triangle.h"

#include "globals.h"
#include "input_handler.h"

#define TINYOBJLOADER_IMPLEMENTATION 
#include "tiny_obj_loader.h"

#include <vector>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    //Parse the command line args
    if(argc<2){
        fprintf(stderr, "Not enough command line args!\n");
        exit(0);
    }
    std::string file_name = argv[1];

    // Load .obj mesh using tiny obj loader
    std::string mesh_path = "./meshes/"+file_name;
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;

    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, nullptr, &warn, &err, mesh_path.c_str());
    if(ret){
        printf("Worked!\n");
    }else{
        printf("Not good\n");
    }

    std::vector<triangle> triangles;

    //Loop shapes
    for (size_t s = 0;s<shapes.size();s++) {
      //Loop faces
      size_t index_offset = 0;
      for (size_t f = 0;f<shapes[s].mesh.num_face_vertices.size();f++) {
        size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

        triangle tri;
        //Loop vertices in the face (Using default setings, which means all faces are triangles)
        for (size_t v = 0;v<fv;v++) {
          // access to vertex
          tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

          tinyobj::real_t vx = attrib.vertices[3*size_t(idx.vertex_index)+0];
          tinyobj::real_t vy = attrib.vertices[3*size_t(idx.vertex_index)+1];
          tinyobj::real_t vz = attrib.vertices[3*size_t(idx.vertex_index)+2];

          tri.vertices[v] = vec3d(vx, vy, vz);

        }
        triangles.push_back(tri);
        index_offset += fv;
      }
    }



    //Load display
    if(!display_init()){
        exit(0);
    }
    double aspect_ratio = window_width/window_height;

    camera camera;
    camera.position = vec3d(0, 0, 0);
    camera.u = vec3d(1, 0, 0);
    camera.v = vec3d(0, 1, 0);
    camera.w = vec3d(0, 0, 1);

    vec3d target = vec3d(mesh_translation_x, mesh_translation_y, mesh_translation_z);

    bool running = true;
    SDL_Event e;

    while(running){

        //Loop trough all triangles
        for(size_t i = 0;i<triangles.size();i++){

            std::vector<vec4d>converted_vecs;

            //Perform Model-View-Projection calculations per vertex
            for(int j = 0;j<3;j++){
                vec4d original_v = vec3d_to_vec4d(triangles[i].vertices[j]);

                //Model
                mat4d rot_x = mat4d_create_rotation_x(mesh_angle_x);
                mat4d rot_y = mat4d_create_rotation_y(mesh_angle_y);
                mat4d rot_z = mat4d_create_rotation_z(mesh_angle_z);

                mat4d rot_mat = rot_x.mat4d_mult(rot_y).mat4d_mult(rot_z);

                mat4d model_mat = mat4d_create_translation(mesh_translation_x, mesh_translation_y, mesh_translation_z).mat4d_mult(rot_mat);
                vec4d model = model_mat.vec4d_mult(original_v);

                //View
                mat4d view_mat = mat4d_create_view(camera.position, target, camera.u);
                vec4d view = view_mat.vec4d_mult(model);

                //Projection
                mat4d perspective_mat4d = mat4d_create_perspective(M_PI/2, aspect_ratio, 1, 30); //TODO, hardcoded values
                vec4d converted = apply_perspective(perspective_mat4d, view);

                //Perform adjustments on the converted components to screen coordinates
                converted = converted+vec4d(1, 1, 0, 0);
                converted.v[0] = converted.v[0]*(window_width/2);
                converted.v[1] = converted.v[1]*(window_height/2);

                converted_vecs.push_back(converted);
            }
            if(converted_vecs[0].v[2] <0.0 && converted_vecs[1].v[2] <0.0 && converted_vecs[2].v[2] <0.0){
                continue;
            }

            //Draw the triangle
            draw_line(converted_vecs[0].v[0], converted_vecs[0].v[1], converted_vecs[1].v[0], converted_vecs[1].v[1], rgba_to_uint32(255, 0, 0, 255));
            draw_line(converted_vecs[1].v[0], converted_vecs[1].v[1], converted_vecs[2].v[0], converted_vecs[2].v[1], rgba_to_uint32(255, 0, 0, 255));
            draw_line(converted_vecs[2].v[0], converted_vecs[2].v[1], converted_vecs[0].v[0], converted_vecs[0].v[1], rgba_to_uint32(255, 0, 0, 255));
        }
        //Update after drawing all triangles
        display_present();

        set_blackout();

        running = check_input(e);
    }
    display_quit();
    return 0;
}