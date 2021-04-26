#ifndef Transform_hpp
#define Transform_hpp

#include <cstdio>
#include <iostream>

#include "Component.hpp"
#include "Vector2.hpp"

class PhysicsEngine;

/**
 * @class Transform
 * @brief transform component of game objects.
 */
class Transform : public Component
{
public:
    /**
     * /brief
     */
    Transform();
    /**
     *@brief Construction
     *@param pos position
     */
    Transform(Vector2 pos);
    /**
     *@brief Construction
     *@param x x of position
     *@param y yof position
     */
    Transform(float x, float y);
    /**
     *@brief Destruction
     */
    ~Transform();
    
    void Start() override;
    /**
     * / Update the position of game object according to that of physical world
     *
     * @param dt time elapsed
     */
    void Update(int dt) override;
    void Render() override;

    /**
     * /brief Set the position of the object in physical world
     *
     * @param p position
     */
    void SetPosition(Vector2 p);
    /**
     * /brief Get the position of the object
     *
     * @return position
     */
    Vector2 GetPosition() const;
    /**
     * /brief Apply force to the game object in physical world
     *
     * @param force
     */
    void ApplyForce(Vector2 force);
    /**
     * /brief Apply impulse to the game object in physical world
     *
     * @param impulse
     */
    void ApplyImpulse(Vector2 impulse);
    /**
     * Set the collision size
     *
     * @param size
     */
    void SetSize(Vector2 size);
    
    
    //--------------exposed to users--------------
    Vector2 scale;///scale of the gameObject, when it changes, both sprite and collider will change.
    Vector2 position;///position of the center of the gameObject

private:
    Vector2 m_center{0,0};
    Vector2 m_size{64.0f, 64.0f};
};

#endif /* Transform_hpp */
