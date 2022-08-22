#ifndef __keyboard_hpp_
#define __keyboard_hpp_

#include <vector>

#include "desolate/include.hpp"

namespace desolate
{
    class Window;
    
    namespace input
    {
        class Keyboard
        {
        public:
            Keyboard(desolate::Window& window) : /*window(window),*/ keyPressed(GLFW_KEY_LAST)
            {
                for (int i = 0; i < keyPressed.size(); ++i)
                {
                    keyPressed[i] = false;
                }
            }
            
            void SetKeyPressed(int key, bool value) { keyPressed[key] = value; }
            bool GetKeyPressed(int key) { return keyPressed[key]; }
        private:
            //desolate::Window& window;
            std::vector<bool> keyPressed;
        };
    }
}

#endif // __keyboard_hpp_