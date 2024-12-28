#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include "globals.h"

bool check_input(SDL_Event& event); //Returns false if a quit was initaited, returns true if event is a non-quit

#endif
