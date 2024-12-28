#include "input_handler.h"

bool check_input(SDL_Event& event){
    //Poll the event
    SDL_PollEvent(&event);

    if(event.type==SDL_QUIT){ //Quit (X button of the window was pressed)
        return false;
    }else if(event.type==SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_w:
                mesh_translation_z += 0.5;
                break;
            case SDLK_s:
                mesh_translation_z -= 0.5;
                break;
            case SDLK_x: //TODO, temp quit key
                return false;
                break;
            case SDLK_1:
                mesh_angle_x+=0.1;
                break;
            case SDLK_2:
                mesh_angle_y+=0.1;
                break;
            case SDLK_3:
                mesh_angle_z+=0.1;
                break;
            default:
                break;
        }
    }
    return true;
}