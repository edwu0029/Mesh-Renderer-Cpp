#include "display.h"

bool display_init() {
    window_width = 640;
    window_height = 480;
    pixel_buffer = (uint32_t*)malloc(window_width*window_height*sizeof(uint32_t));

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Error initializing SDL\n"
                        "SDL_Error %s\n", SDL_GetError());
        return false;
    }
    //Create Window
    window = SDL_CreateWindow("Mesh Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_BORDERLESS);
    if(!window){
        fprintf(stderr, "Error initializing SDL Window\n"
                        "SDL_Error %s\n", SDL_GetError());
    }
    //Create the surface
    surface = SDL_GetWindowSurface(window);

    return true;
}

uint32_t rgba_to_uint32(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

void set_pixel(int x, int y, uint32_t colour){
    pixel_buffer[y*window_width + x] = colour;
}
void draw_line(int x1, int y1, int x2, int y2, uint32_t colour){
    double dx = x2-x1, dy = y2-y1;
    double step;
    if(abs(dx)>abs(dy)){
        step = abs(dx);
    }else{
        step = abs(dy);
    }
    dx/=step;
    dy/=step;

    double x = x1, y = y1;
    for(int i = 0;i<=step;i++){
        set_pixel(round(x), round(y), colour);
        x+=dx;
        y+=dy;
    }
}


void display_quit(){
    free(pixel_buffer);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void display_present() {
    memcpy(surface->pixels, pixel_buffer, window_width*window_height*sizeof(uint32_t));
    SDL_UpdateWindowSurface(window);
}

void set_blackout(){
    //Fill all bits in pixel array with black
    for(int y = 0;y<window_height;y++){
        for(int x = 0;x<window_width;x++){
            set_pixel(x, y, rgba_to_uint32(0, 0, 0, 255));
        }
    }
}