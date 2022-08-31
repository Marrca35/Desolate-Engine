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
            Keyboard(desolate::Window& window) : /*window(window),*/ keyPressed(GLFW_KEY_LAST), keyRepeated(GLFW_KEY_LAST)
            {
                for (int i = 0; i < keyPressed.size(); ++i)
                {
                    keyPressed[i] = false;
                }
            }
            
            void SetKeyPressed(int key, bool value) { keyPressed[key] = value; }
            void SetKeyRepeated(int key, bool value) { keyRepeated[key] = value; }
            bool GetKeyRepeated(int key) { return keyRepeated[key]; }
            bool GetKeyPressed(int key) { return keyPressed[key]; }
        private:
            //desolate::Window& window;
            std::vector<bool> keyPressed;
            std::vector<bool> keyRepeated;
        };
    }
}

#endif // __keyboard_hpp_