#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

namespace Utils {


    static SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
    {
        SDL_Texture* newTexture = NULL;

        SDL_Surface* loadedSurface = IMG_Load(path.c_str());
        if (loadedSurface == NULL)
        {
            printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        }
        else
        {
            newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
            if (newTexture == NULL)
            {
                printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            }
            SDL_FreeSurface(loadedSurface);
        }

        return newTexture;
    }

}
