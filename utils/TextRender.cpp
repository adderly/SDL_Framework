#include"TextRender.h"


TextureRender::TextureRender() {}
TextureRender::TextureRender(std::string txt)
{
    init();
    this->text = txt;
}
TextureRender::TextureRender(SDL_Surface* main)
{
    init();
    this->tmp = main;
}
TextureRender::TextureRender(SDL_Surface* surface,const std::string TextureRender,int fontsize)
{

    //init();
    this->tmp = surface;
    this->text = text;
    this->fontSize = fontsize;
}
TextureRender::TextureRender(SDL_Surface *surface,const std::string text,SDL_Color color)
{
    this->tmp = surface;
    this->text = text;
    this->textColor = color;
}
SDL_Surface* TextureRender::generate(const std::string text)
{
    tmp = TTF_RenderText_Solid(font,text.c_str(),textColor);
    return tmp;
}
SDL_Surface* TextureRender::generate(const std::string text,int size)
{
    tmp = TTF_RenderText_Solid(font,text.c_str(),textColor);
    return tmp;
}
SDL_Surface* TextureRender::generate(SDL_Surface *texture,const std::string text)
{
    tmp = texture;
    tmp = TTF_RenderText_Solid(font,text.c_str(),textColor);
    return tmp;
}
SDL_Surface* TextureRender::generate(SDL_Surface *texture,const std::string text,int size)
{

    tmp = texture;
    stringstream ss;
    ss << "Oh My Goodness, an error "<< TTF_GetError();
    if(font == NULL) saveLog(ss.str() );

    tmp = TTF_RenderText_Solid(font,text.c_str(),textColor);

    return tmp;
}
SDL_Surface* TextureRender::generate()
{
    tmp = TTF_RenderText_Solid(font,text.c_str(),textColor);
    return tmp;
}

void TextureRender::init()
{
    textColor = {255,255,0,200};

    try
    {
        if(TTF_Init()==-1)
        {
            throw 3;
        }
        loadResources();
    }
    catch(...)
    {
        saveLog("Could Not Init TTF");
        std::terminate();
    }

}
void TextureRender::loadResources()
{
    try
    {
        font = TTF_OpenFont("resources/font/Ubuntu-B.ttf", 45);

    }
    catch(...)
    {
        if(font == NULL) saveLog("Error Opening Font File @TextRender.LoadResoureces");
        //std::terminate();
    }


}
void TextureRender::freeResources()
{
    TTF_CloseFont(font);
    font = NULL;
    TTF_Quit();
}
TextureRender::~TextureRender() {}



