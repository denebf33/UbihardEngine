#ifndef SpriteRenderer_hpp
#define SpriteRenderer_hpp

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

#include <stdio.h>
#include <string>

#include "Transform.hpp"
#include "Component.hpp"
#include "Transform.hpp"

/**
 * @class SpriteRenderer
 * @brief sprite renderer component of game objects.
 */
class SpriteRenderer:public Component
{
public:
    void Start() override;
    void Update(int dt) override;
    void Render() override;
    /**
     *@brief Constructor
     */
    SpriteRenderer();
    /**
     *@brief Constructor
     *@param path path of the sprite, src defaults to the size of the entire sprite
     */
    SpriteRenderer(SDL_Renderer* renderer, std::string path);
    /**
     *@brief Constructor
     *@param t texture
     *@param rect which part of the sprite is rendered
     */
    SpriteRenderer(SDL_Texture* t, SDL_Rect rect);
    /**
     *@brief Constructor
     *@param renderer renderer
     */
    SpriteRenderer(SDL_Renderer* renderer);
    /**
     *@brief Destructor
     */
    ~SpriteRenderer();
    /**
     *@brief set the texture and the src rect
     *@param t texture
     *@param rect src rect
     */
    void SetSpriteDetail(SDL_Texture* t, SDL_Rect rect);
    
    void SetSprite(std::string path);

    /**
     * \brief Get the destined sprite size, which is the size rendered on the screen
     *
     * @return sprite size
     */
    Vector2 GetSpriteSize();
    /**
     * \brief Set the sprite size
     *
     * @param size sprite size
     */
    void SetSpriteSize(Vector2 const& size);


    //--------------exposed to user--------------
    Vector2 position;///relative position to the gameObject
    Vector2 size;///size of the sprite
    
    
private:
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_texture;
    SDL_Rect src{0, 0, 64, 64};
    SDL_Rect des{0, 0, 64, 64};
};

#endif /* SpriteRenderer_hpp */
