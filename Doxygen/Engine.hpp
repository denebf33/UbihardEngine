/**@mainpage  Ubihard engine
* <table>
* <tr><th>Project  <td>Ubihard engine
* <tr><th>Author   <td>JunfengZhou, Wu lyu, Yibo Zhao, Ziqing Mao
* </table>
* @section show Project details
* This project consists of a game engine library that supports users to use to create their own game, and a graphical user interface for users to manage and modify their project, along with some useful tools for users to build their games.
*
**********************************************************************************
*/
#ifndef Engine_hpp
#define Engine_hpp

#include <cstdio>
#include <iostream>
#include <vector>

#include "GraphicsEngineRenderer.hpp"
#include "InputHandler.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Transform.hpp"
#include "SpriteRenderer.hpp"
#include "Collider.hpp"
#include "PhysicsEngine.hpp"
#include "TileMap.hpp"
#include "ResourceManager.hpp"

/**
 * @class Engine
 * @brief class of the game engine
 */
class Engine{
public:
    /**
     *@brief Constructor of Engine
     */
    Engine();
    /**
     *@brief Destructor
     */
    ~Engine();
    /**
     *@brief Input engine
     */
    void Input();
    /**
     *@brief Per frame update
     */
    void Update(int dt);
    /**
     *@brief Per frame render. Renders everything
     */
    void Render();
    /**
     *@brief Main Game Loop that runs forever
     */
    void MainGameLoop();
    /**
     *@brief Initialization and shutdown pattern. Explicitly call 'Start' to launch the engine
     */
    void Start();
    /**
     *@brief Initialization and shutdown pattern. Explicitly call 'Shutdown' to terminate the engine
     */
    void Shutdown();

    /**
     *@brief Request to startup the Graphics Subsystem
     */
    void InitializeGraphicsSubSystem();

    /**
     *@brief Create a gameObject with script in the engine
     *@param path path of the script file
     */
    void CreateGameObject(std::string path);
    
    /**
     *@brief Create an empty gameObject in the engine
     */
    GameObject* CreateObject();
    
    /**
     * /brief Create a static game object
     * i.e. immovable, ignorant to gravity
     *
     * @return
     */
    GameObject* CreateStaticObject();
    /**
     *@brief Create the tilemap
     */
    void CreateTileMap(std::string scenePath);
    /**
     *@brief Create the background picture
     */
    void CreateBackGround();
    
    /**
     *@brief Return whether should quit the eingine
     */
    bool IsQuit();

    /**
     * \brief Sets gravity of the world
     *
     * @param gravity a vector represents direction and magnitude of the gravity
     */
    void SetGravity(Vector2 gravity);
    /**
     * \brief Sets the scale factor of the world. If the game is tile-based, it should numerically be the width of a tile.
     * It should be set before adding a game object in the world.
     *
     * @param scale
     */
    void SetScaleFactor(float scale);
    /**
     * /brief Halt the engine for some time
     *
     * @param time
     */
    void Halt(int time);
    /**
     * /brief Set the gravity scale for an object
     *
     * @param obj game object
     * @param scale gravity scale
     */
    void SetObjectGravityScale(GameObject* obj, float scale);
    /**
     * /brief Set the velocity of the object
     *
     * @param obj game object
     * @param v velocity
     */
    void SetObjectLinearVelocity(GameObject* obj, Vector2 v);
    /**
     * \brief Get the velocity of the object
     *
     * @param obj game object
     * @return velocity
     */
    Vector2 GetObjectLinearVelocity(GameObject* obj);
    /**
     * \brief Set object density
     *
     * @param obj
     * @param density
     */
    void SetObjectDensity(GameObject* obj, float density);
    /**
     * \brief Set object friction
     *
     * @param obj
     * @param friction
     */
    void SetObjectFriction(GameObject* obj, float friction);
    
    /**
     * \brief Get a vector of game objects
     * @return a vector of all gameobjects
     */
    std::vector<GameObject*> GetGameObjects() {
        return m_gameObjects;
    }
    
    /**
     * \brief Remove a game object from the engine
     * @param obj
     */
    void DestroyGameObject(GameObject* obj);
    
    /**
     * \brief
     * @return a pointer to the physical engine
     */
    PhysicsEngine* GetPhysicalEngine();
    
private:
    // Engine Subsystem
    // Setup the Graphics Rendering Engine
    
    GraphicsEngineRenderer* m_renderer = nullptr;///< Pointer to current graphics engine renderer
    
    std::vector<GameObject*> m_gameObjects;///< Vector of all game objects
    
    
    TileMap* m_tileMap;///< Pointer to current scene tilemap
    //std::vector<Component*> m_components;
    
    //bool m_kLetter[26];
    //bool m_kNumber[10];
    //bool m_bMouse[2];
    
    bool quit;///< Bool to control whether to quit the main loop

    PhysicsEngine* m_physicsEngine = nullptr;///< Pointer to the physics engine
};

#endif /* Engine_hpp */
