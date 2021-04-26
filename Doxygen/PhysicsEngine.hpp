#ifndef FINALPROJECT_UBIHARD_PHYSICS_ENGINE_HPP
#define FINALPROJECT_UBIHARD_PHYSICS_ENGINE_HPP

#include <box2d/box2d.h>
#include <box2d/b2_body.h>
#include "Vector2.hpp"
#include "GameObject.hpp"

/**
 * \class PhysicsEngine
 * \brief This class is a wrapper class of box2d library, which provides a simulation of a physical world.
 */
class PhysicsEngine {
public:
    /**
     * \brief Default constructor
     */
    PhysicsEngine();
    /**
     * \brief Default destructor
     */
    ~PhysicsEngine();
    /**
     * \brief Sets gravity of the world
     *
     * @param gravity a vector represents direction and magnitude of the gravity
     */
    void SetGravity(Vector2 const& gravity);
    /**
     * \brief Sets the scale factor of the world. If the game is tile-based, it should numerically be the width of a tile.
     * It should be set before adding a game object in the world.
     *
     * @param scale
     */
    void SetScaleFactor(float scale);
    /**
     * /brief Set a static body as the tile
     *
     * @param gameObject
     */
    void AddTile(GameObject* gameObject);
    /**
    * \brief Adds a game object into the engine
    *
    * Adding a game object into the engine allows the engine to simulate physical effects
    * on the sprite. The simulation may modify the state of the sprite.
    * \param[in] sprite The sprite to be added.
    */
    void AddGameObject(GameObject* gameObject);
    /**
     * \brief Removes a game object from the engine
     *
     * Removing a game object from the engine stops the engine performing physical computation
     * on it.
     * \param[in] sprite The sprite to be removed.
     */
    void RemoveGameObject(GameObject* gameObject);
    /**
     * \brief Updates the state of everything in the engine into the next frame.
     * \warning the elapsed time has to be second unit (s)
     *
     * \param[in] duration The duration since the last frame.
     */
    void Update(float duration);
    /**
     * \brief Set the position of the body of the game object in the physical world
     *
     * @param gameObject
     * @param center
     */
    void SetPosition(GameObject* gameObject, Vector2 const& center) const;
    /**
     * \brief Get the center position of the body of the game object in the physical world
     *
     * @param gameObject
     * @return the position vector
     */
    Vector2 GetPosition(GameObject* gameObject) const;
    /**
     * \brief Set the size of the game object in the physical world
     *
     * @param gameObject
     * @param size
     */
    void SetSize(GameObject* gameObject, Vector2 const& size) const;
    /**
     * \brief Set the object as sensor or not
     *
     * @param gameObject
     * @param isSensor
     */
    static void SetSensor(GameObject* gameObject, bool isSensor);
    /**
     * \brief Set the object's density
     *
     * @param gameObject
     * @param density
     */
    static void SetDensity(GameObject* gameObject, float density);
    /**
     * \brief Set the object's friction
     *
     * @param gameObject
     * @param friction
     */
    static void SetFriction(GameObject* gameObject, float friction);
    /**
     * \brief Apply force to the object
     *
     * @param gameObject
     * @param force
     */
    static void ApplyForce(GameObject* gameObject, Vector2 const& force);
    /**
     * \brief Apply impulse to the object
     *
     * @param gameObject
     * @param impulse
     */
    static void ApplyImpulse(GameObject* gameObject, Vector2 const& impulse);
    /**
     * \brief Set the gravity scale of the object
     *
     * @param gameObject
     * @param scale
     */
    static void SetObjectGravityScale(GameObject* gameObject, float scale);
    /**
     * \brief Set the linear velocity of the object
     *
     * @param gameObject
     * @param v
     */
    static void SetObjectLinearVelocity(GameObject* gameObject, Vector2 v);
    /**
     * \brief Get the linear velocity of the object
     *
     * @param gameObject
     * @return velocity
     */
    static Vector2 GetObjectLinearVelocity(GameObject* gameObject);
    /**
     * \brief Get the contact list of a game object
     *
     * @param gameObject
     */
    std::vector<Contact> GetContactList(GameObject* gameObject) const;
    /**
     * \brief Get the contact list of sensors that collide with the game object
     *
     * @param gameObject
     * @return contact list
     */
    std::vector<Contact> GetSensorContactList(GameObject* gameObject) const;
    
private:
    float m_scale = 64.0f;///< Default scale of physics engine objects.
    b2World* m_world = nullptr;///< Pointer to physics world.
};


#endif //FINALPROJECT_UBIHARD_PHYSICS_ENGINE_HPP
