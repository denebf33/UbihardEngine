#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>

class GameObject;

/**
 * @class Component
 * @brief base class of components
 */
class Component{
public:
    /**
     *@brief Constructor
     */
    Component();
    /**
     *@brief Destructor
     */
    ~Component();
    
    /**
     *@brief run at the first frame of game
     */
    virtual void Start();
    
    /**
     *@brief run at each frame
     *@param dt duration time between each frame
     */
    virtual void Update(int dt);
    /**
     *@brief render on screen
     */
    virtual void Render();
    /**
     *@brief Get the owner of this component
     *@return owner as a GameObject
     */
    GameObject* gameObject();
    
    GameObject* owner = nullptr;
private:

};


#endif
