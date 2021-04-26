#ifndef Animator_hpp
#define Animator_hpp

#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#elif defined(__APPLE__)
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#else
    #include <SDL.h>
    #include <SDL_image.h>
#endif

#include <cstdio>
#include <vector>

#include "Component.hpp"
#include "ResourceManager.hpp"
#include "document.h"
#include "filereadstream.h"


using namespace rapidjson;
/**
 * @enum AnimationModel
 * @brief animation model
 */
enum AnimationModel
{
    single,///play the animation once
    loop///play the animation
};

/**
 * @class Animator
 * @brief class of animator component.
 */
class Animator:public Component
{
public:
    Animator();
    /**
     * @brief construtor of animator class
     * @param renderer current renderer
     */
    Animator(SDL_Renderer* renderer);
    
    void Start() override;
    void Update(int dt) override;
    void Render() override;
    /**
     *@brief read animations file form a path
     */
    void GetAnimations(std::string path);
    
    //void GetAnimations(rapidjson::Document document);
    
    std::vector<SDL_Rect> m_Frames;///< rects to locate each frame
    
    int m_CurrentFrame;///< current animation frame
    int m_StartFrame;///< start frame of current animation
    int m_LastFrame;///< last frame of current animation
    int m_AnimationFPS;///< animation update time
    int m_lastTime;///< time counter
    int m_Timer;///< time counter

    //--------------exposed to uesrs--------------
    /**
     *@brief start the animation with specific model
     *@param name the name of the animation
     *@param model animation model
     */
    void StartAnimation(std::string name, AnimationModel model);
    /**
     *@brief get the name of current animation
     */
    std::string GetCurrentAnimation();
    /**
     *@brief stop the current animation
     */
    void StopAnimation();
    /**
     *@brief continue playing the current animation
     */
    void ContinueAnimation();
    
private:
    SDL_Renderer* m_renderer;///<current renderer
    SDL_Texture* m_texture;///< animation texture
    AnimationModel m_model;///< animation mode
    int m_spriteWidth;///< width of each sprite
    int m_spriteHeight;///< height of each sprite
    int m_col;///< cols of sprites
    int m_row;///< rows of sprites
    bool m_stop;///< stop updateing
    std::string m_currentAnimation;///< current animation name
    rapidjson::Document m_document;///< animation information json file
};



#endif /* Animator_hpp */
