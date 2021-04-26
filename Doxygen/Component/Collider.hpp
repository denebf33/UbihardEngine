#ifndef Collider_hpp
#define Collider_hpp

#include <cstdio>
#include <vector>

#include "Vector2.hpp"
#include "Component.hpp"

/**
 * @struct Contact
 * @brief infomation of collides
 */
struct Contact {
    GameObject* other = nullptr;
    int numOfPoints = 0;
    std::vector<Vector2> points;
};

/**
 * @class Collider
 * @brief collider component of game objects.
 */
class Collider : public Component
{
public:
    /**
     *@brief Constructor
     */
    Collider();
    /**
     *@brief Destructor
     */
    ~Collider();
    /**
     * \brief Empty Update
     * @param dt
     */
    void Update(int dt) override;
    /**
     * \brief Empty render
     */
    void Render() override;
    
    //--------------exposed to users--------------
    /**
     * Get the contact list of current object
     *
     * @return contact list
     */
    std::vector<Contact> GetContactList();
    /**
     * \brief Get the contact list of sensors that collide with the game object
     *
     * @return contact list
     */
    std::vector<Contact> GetSensorContactList();
    /**
     * /brief Set the collision scale of the object
     * i.e. the collision size in physical world is size * scale
     *
     * @param scale
     */
    void SetScale(float scale);
    /**
     * /brief Get the collision scale of the object
     *
     * @return scale
     */
    float GetScale(bool isTrigger) const;
    /**
     * \brief Set if the object is trigger or not
     * Set whether this gameObject collide with other, collider won't collide with trigger
     *
     * @param isSensor
     */
    void SetSensor(bool isSensor);

    
private:
    float m_scale = 1.0f;
    bool m_isSensor = false;
};

#endif /* Collider_hpp */
