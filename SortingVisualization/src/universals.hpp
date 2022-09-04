#pragma once 
#include <string>


// COLORS 
#define WHITE	{ 0xFF, 0xFF, 0xFF, 0 }
#define RED     { 0xFF, 0, 0, 0 }
#define GREEN   { 0, 0xFF, 0, 0 } 
#define BLUE    { 0, 0, 0xFF, 0 } 
#define YELLOW  { 0xFF, 0xFF, 0, 0 } 

// VARIAABLES 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 720;
const int NUMBER_OF_ELEMENTS = 100;
const int HALF_ELEMENTS = NUMBER_OF_ELEMENTS / 2;
const int DELAY = 50;
const int ARROW_POS_INC = 100;

// TEXTURES 
const std::string ARROW_TEXTURE = "assets/arrow.png";
const std::string TTF_FONT = "assets/OpenSans-Semibold.ttf";
const std::string MAIN_MINU = "assets/main-minu.png";
