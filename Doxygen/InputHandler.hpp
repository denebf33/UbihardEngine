#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>
#include <iostream>
#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#elif defined(__APPLE__)
    #include <SDL2/SDL.h>
#else
    #include <SDL.h>
#endif

/**
 * @enum Keycode
 * @brief Enum of all input keyboard keys.
 */
enum KeyCode
{
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
    alpha0,alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7,alpha8,alpha9,
    Space,
    UpArrow,DownArrow,LeftArrow,RightArrow
};

/**
 * @enum MouseButton
 * @brief Enum of all input mouse buttons.
 */
enum MouseButton
{
    Left,Right
};

/**
 * @class InputHandler
 * @brief class to handle all the user inputs.
 */
class InputHandler
{
public:
    InputHandler(InputHandler const&) = default;
    InputHandler& operator=(InputHandler const&) = default;

    ~InputHandler() = default;

    /**
     * \brief Singleton instance
     */
    static InputHandler& GetInstance();
    
    /**
     * \brief Process key down event.
     * @param key enum of keys.
     */
    void KeyDown(int key);
    
    /**
     * \brief Process key up event.
     * @param key enum of keys.
     */
    void KeyUp(int key);
    
    /**
     * \brief Process mouse button down event.
     * @param key enum of mouse buttons.
     */
    void MouseDown(int button);
    
    /**
     * \brief Process mouse button down event.
     * @param key enum of mouse buttons.
     */
    void MouseUp(int button);
    
    /**
     * \brief Get key down state
     * @param key enum of keys.
     * @return whether the key is down.
     */
    bool QueryKeyDown(KeyCode key);
    
    /**
     * \brief Get key up state
     * @param key enum of keys.
     * @return whether the key is up.
     */
    bool QueryKeyUp(KeyCode key);
    
    /**
     * \brief Get mouse button down state
     * @param key enum of mouse buttons.
     * @return whether the mouse button is down.
     */
    bool QueryMouseDown(MouseButton button);
    
    /**
     * \brief Get mouse button up state
     * @param key enum of mouse buttons.
     * @return whether the mouse button is up.
     */
    bool QueryMouseUp(MouseButton button);
    
    //--------------exposed to users--------------
    /**
     * @brief Reset all signals to false.
     */
    void ResetInputSignal();
    
    /**
     * \brief Whether the certain key is down
     * @param key Enum of keys.
     * @return Whether the key is down.
     */
    bool GetKeyDown(KeyCode key);
    
    /**
     * \brief Whether the certain key is up
     * @param key Enum of keys.
     * @return Whether the key is up.
     */
    bool GetKeyUp(KeyCode key);

    /**
     * \brief Whether the certain mouse button is down
     * @param key Enum of mouse buttons.
     * @return Whether the mouse button is down.
     */
    bool GetMouseDown(MouseButton button);
    
    /**
     * \brief Whether the certain mouse button is up
     * @param key Enum of mouse buttons.
     * @return Whether the mouse button is up.
     */
    bool GetMouseUp(MouseButton button);
    
private:
    InputHandler() = default;

    bool m_KeyDown[41] = {false};///<All key down bools.
    bool m_KeyUp[41] = {false};///<All key up bools.
    
    bool m_MouseDown[2] = {false};///<All mouse button down bools.
    bool m_MouseUp[2] = {false};///<All mouse button up bools.
};



#endif /* Input_hpp */
