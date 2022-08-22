#ifndef __mouse_hpp_
#define __mouse_hpp_

#include "lacuna/util/window/Window.hpp"

namespace lacuna
{
    namespace input
    {
        class Mouse
        {
        public:
            Mouse(lacuna::Window& window) : window(window), raw(false), xpos(0), ypos(0) {}

            void ChangeRawInput();
            void SetPosition(double x, double y);

            double GetXPosition() { return xpos; }
            double GetYPosition() { return ypos; }
            bool GetRawInput() { return raw; }

        private:
            double xpos, ypos;
            bool raw;
            lacuna::Window& window;
        };
    }
}

#endif // __mouse_hpp_