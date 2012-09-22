#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<iostream>
#include<sstream>
#include<string>
#include"Log.h"




#ifndef TEXT_H
#define TEXT_H
class TextureRender
{
    SDL_Color textColor;
    std::string fontLocation;
    std::string text;
    int fontSize;
    bool bold;

public:
    TTF_Font*    font;
    SDL_Surface* tmp;

    TextureRender();
    TextureRender(std::string txt);
    TextureRender(SDL_Surface* main);
    TextureRender(SDL_Surface *texture,const std::string text,int size);
    TextureRender(SDL_Surface *texture,const std::string text,SDL_Color color);
    SDL_Surface* generate();
    SDL_Surface* generate(const std::string text);
    SDL_Surface* generate(const std::string text,int size);
    SDL_Surface* generate(SDL_Surface *texture,const std::string text);
    SDL_Surface* generate(SDL_Surface *texture,const std::string text,int size);
    SDL_Surface* getSurface()
    {
        return this->tmp;
    }
    void init();
    void loadResources();
    void freeResources();
    void setFontLocation(std::string location)
    {
        this->fontLocation = location;
    }
    void setSurface(SDL_Surface* surface)
    {
        this->tmp = surface;
    }
    void setSize(int size)
    {
        this->fontSize = size;
    }
    int getSize()
    {
        return this->fontSize;
    }
    ~TextureRender();
};
#endif


