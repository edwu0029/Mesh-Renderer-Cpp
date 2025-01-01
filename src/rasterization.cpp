#include "rasterization.h"

vec4d perspective_divide(vec4d& a){
    vec4d res;

    double w = a.v[3];
    if(abs(w)>1E-9){ //Check not dividing by 0
        res.v[0] = a.v[0]/w;
        res.v[1] = a.v[1]/w;
        res.v[2] = a.v[2]/w;
    }
    return res;
}

void clip_waxis(std::vector<vec4d>& vertices, std::vector<vec4d>& new_vertices){
    //Clips so that all w<0 vertices are clipped (since they would be behind the camera)
    vec4d prev_vertex = vertices[vertices.size()-1];
    double prev_dot;
    if(prev_vertex.v[3]<W_CLIPPING_PLANE){ //Compare against 0.0001 to avoid divide by zero during perspective divide
        //Behind camera
        prev_dot = -1.0;
    }else{
        prev_dot = 1.0;
    }

    for(int i = 0;i<vertices.size();i++){
        vec4d cur_vertex = vertices[i];

        double cur_dot;
        if(cur_vertex.v[3]<W_CLIPPING_PLANE){
            cur_dot = -1.0;
        }else{
            cur_dot = 1.0;
        }

        if(prev_dot*cur_dot<0){ //Went from inside to outside, or outside to inside, so we crosse the clip plane
            //Add a intersection point
            double t = (W_CLIPPING_PLANE-prev_vertex.v[3])/
                        (prev_vertex.v[3]-cur_vertex.v[3]);
            vec4d intersection = (cur_vertex-prev_vertex)*t+prev_vertex;
            new_vertices.push_back(intersection);
        }

        if(cur_dot>0){
            new_vertices.push_back(cur_vertex);
        }

        //Update for next vertex
        prev_dot = cur_dot;
        prev_vertex = cur_vertex;

    }
}

void clip_axis(int axis, std::vector<vec4d>& vertices, std::vector<vec4d>& new_vertices){
    //Clips so that all w<0 vertices are clipped (since they would be behind the camera)
    vec4d prev_vertex = vertices[vertices.size()-1];
    double prev_dot;
    if(prev_vertex.v[axis]<prev_vertex.v[3]){
        //Behind camera
        prev_dot = -1.0;
    }else{
        prev_dot = 1.0;
    }

    for(int i = 0;i<vertices.size();i++){
        vec4d cur_vertex = vertices[i];

        double cur_dot;
        if(cur_vertex.v[axis]<cur_vertex.v[3]){
            cur_dot = -1.0;
        }else{
            cur_dot = 1.0;
        }

        if(prev_dot*cur_dot<0){ //Went from inside to outside, or outside to inside, so we crosse the clip plane
            //Add a intersection point
            double t = (prev_vertex.v[3]-prev_vertex.v[axis])/
                        ((prev_vertex.v[axis]-prev_vertex.v[3]) - (cur_vertex.v[axis]-cur_vertex.v[3]));
            vec4d intersection = (cur_vertex-prev_vertex)*t+prev_vertex;
            new_vertices.push_back(intersection);
        }

        if(cur_dot>0){
            new_vertices.push_back(cur_vertex);
        }

        //Update for next vertex
        prev_dot = cur_dot;
        prev_vertex = cur_vertex;

    }
}

void get_triangles_from_vertices(std::vector<vec4d>& vertices, std::vector<triangle4d>& tris){
    if(vertices.size()<3){
        //Can not create any triangles
        return;
    }

    vec4d common = vertices[0];
    for(int i = 2;i<vertices.size();i++){
        triangle4d tri = triangle4d(common, vertices[i-1], vertices[i]);
        tris.push_back(tri);
    }
}