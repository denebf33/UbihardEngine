#ifndef TileMap_hpp
#define TileMap_hpp

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
#include <string>
#include <fstream>
#include <ostream>

#include "Vector2.hpp"
#include "Component.hpp"
#include "GameObject.hpp"
#include "document.h"
#include "filereadstream.h"


using namespace rapidjson;

/**
 * @class TileMap
 * @brief tilemap class
 */
class TileMap
{
public:
    
    /**
     * \brief constructor
     * @param renderer current renderer
     * @param scenePath path of the scene.json
     */
    TileMap(SDL_Renderer* renderer, std::string scenePath);
    ~TileMap();
    
    /**
     * \brief read map csv file
     * @param csvPath path of the tile map csv file
     */
    void ReadCSV(std::string csvPath);
    
    /**
     * \brief get tilemap texture
     * @return current tilemap texture
     */
    SDL_Texture* GetTexture();
    
    /**
     * \brief get src rect of certain type of tile
     * @param number tile type
     * @return src range of the tile
     */
    SDL_Rect GetRect(int number);
    
    std::vector<int> m_vTileNumber;///< All tiles.
    int m_totalNumber;///< number of tiles
    int m_mapCol;///< columns of tiles
    int m_mapRow;///< rows of tils
private:
    
    int m_tileWidth;///< width of each tile
    int m_tileHeight;///< height of each tile
    int m_sheetCol;///< columns of the sprite sheet
    int m_sheetRow;///< rows of the sprite shtt.
    SDL_Renderer* m_render;///< current renderer.
    SDL_Texture* m_texture;///< tile map texture
    
    
};


#endif /* TileMap_hpp */
