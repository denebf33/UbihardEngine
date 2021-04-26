#ifndef GameObject_hpp
#define GameObject_hpp

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
#include <box2d/box2d.h>

#include "Component.hpp"
#include "Transform.hpp"
#include "SpriteRenderer.hpp"
#include "Animator.hpp"
#include "Collider.hpp"
#include "ResourceManager.hpp"
#include "PhysicsEngine.hpp"

/**
 * @class GameObject
 * @brief class of all game objects
 */
class GameObject{
public:
    GameObject();
    
    /**
     * \brief Constructor
     * @param *renderer current renderer
     * @param *physicsEngine current physics engine
     */
    GameObject(SDL_Renderer* renderer, PhysicsEngine* physicsEngine);
    
    ~GameObject();
    
    /**
     * @brief called in the first frame.
     */
    void Start();
    
    /**
     * \brief called every frame
     * @param dt delta time of frames
     */
    void Update(int dt);
    
    /**
     * @brief Draw the object
     */
    void Render();
    
    /**
     * \brief Get the renderer of this game object
     * @return renderer of this object
     */
    SDL_Renderer* GetRenderer();
    
    /**
     * \brief Set renderer of this object
     * @param renderer target renderer
     */
    void SetRenderer(SDL_Renderer* renderer);
    
    /**
     *@brief whether the gameObject is destroyed
     */
    bool m_Destroied = false;
    //--------------exposed to uesrs--------------
    /**
     *@brief add component to this gameObject
     *@param component compoenet
     */
    void AddComponent(Component* component);
    /**
     *@brief Destroy a gameObject, but not release the memory until game ends
     */
    void Destroy();
    /**
     *@brief get a certain type of component from this gameObject
     */
    template <typename T>
    T& GetComponent()
    {
        T* t = nullptr;
        for(Component* component : m_components)
        {
            if(typeid( dynamic_cast<T*>(component)).name() == typeid(T*).name())
            {
                //return dynamic_cast<T*>(&component);
                t = dynamic_cast<T*>(component);
                break;
            }
        }
        return *t;
    }
    
    /**
     * \brief Get transform component of current object
     * @return pointer to a transform component
     */
    Transform* GetTransform();
    
    /**
     * \brief Get sprite renderer component
     * @return pointer to a sprite renderer component
     */
    SpriteRenderer* GetSpriteRenderer();
    
    /**
     * \brief Get animator component
     * @return pointer to a animator component
     */
    Animator* GetAnimator();

    /**
     * \brief Get collider component
     * @return pointer to a collider component
     */
    Collider* GetCollider();
    
    std::string tag = "";///the tag of this gameOjbect
    
    /**
     * \brief Set the physical body of the object
     *
     * @param body
     */
    void SetPhysicalBody(b2Body* body);
    
    /**
     * \brief Get the physical body
     *
     * @return physical body
     */
    b2Body* GetPhysicalBody();
    
    /**
     * \brief Get the physical engine
     *
     * @return physical engine
     */
    PhysicsEngine* GetPhysicalEngine();
    
    /**
     * \brief set sensor state of the physics engine
     * @param flag target sensor state
     */
    void SetSensor(bool flag);

private:
    std::vector<Component*> m_components;///< All components of this game object.
    Transform* m_Transform;///< Transform component of this game object.
    SpriteRenderer* m_SpriteRenderer;///<Sprite renderer component of this game object.
    Animator* m_Animator;///< Animator component of this game object.
    Collider* m_Collider;///< Collider component of this game object.

    SDL_Renderer* m_Renderer;///<Current spriterenderer.

    b2Body* m_body = nullptr;///<Physical body of this game object.
    PhysicsEngine* m_physicalEngine = nullptr;///<Current physical engine.
};

#endif /* GameObject_hpp */
