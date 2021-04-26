#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_mixer.h>
#elif defined(__APPLE__)
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
    #include <SDL2_ttf/SDL_ttf.h>
    #include <SDL2_mixer/SDL_mixer.h>
#else
    #include <SDL.h>
    #include <SDL_image.h>
    #include <SDL_mixer.h>
    #include <SDL_ttf.h>
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <map>

#include "document.h"
#include "filereadstream.h"

using namespace rapidjson;

/**
 * @class ResourceManager
 * @brief manager of all kind of reasources.
 */
class ResourceManager
{
public:
    
    ResourceManager();
    ~ResourceManager();
    
    /**
     * @brief Singleton instance.
     */
    static ResourceManager& GetInstance();
    
    /**
     * \brief Read and save .json file of the scene.
     * @param sceneJson path of the scene json file.
     */
    void ReadSceneJson(std::string sceneJson);
    
    /**
     * \brief Read and save .json file of animations.
     * @param path path of the animation json file.
     */
    void ReadAnimationJson(std::string path);
    
    /**
     * \brief Get name of a certain resource.
     * @param path path of the resource
     * @return name of the resource
     */
    std::string GetName(std::string path);
    
    /**
     * \brief load a texture
     * @param path path of the picture.
     */
    void LoadTexture(std::string path);
    
    /**
     * \brief load a music
     * @param path path of the music
     */
    void LoadMusic(std::string path);
    
    /**
     * \brief get a texture
     * @param path path to the picture
     * @return corresponding texture
     */
    SDL_Texture* GetTextureByPath(std::string path);
    
    /**
     * \brief get a music
     * @param path path to the music
     * @return corresponding music
     */
    Mix_Chunk* GetMusicByPath(std::string path);
    
    SDL_Renderer* m_renderer;///< Current renderer
private:
    static ResourceManager* instance;///< Singleton instance
    
    std::map<std::string, SDL_Texture*> m_TextureMap;///< All textures
    std::map<std::string, Mix_Chunk*> m_ChunkMap;///< All musics.
};



#endif /* ResourceManager_hpp */
