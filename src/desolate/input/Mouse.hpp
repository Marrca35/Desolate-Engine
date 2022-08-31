#ifndef __mouse_hpp_
#define __mouse_hpp_

//#include "desolate/util/window/Window.hpp"

namespace desolate
{
    class Window;

    namespace input
    {
        class Mouse
        {
        public:
            Mouse(desolate::Window &window) : window(window), raw(false), xpos(0), ypos(0) {}

            void Update();

            void ChangeRawInput();
            void SetPosition(double x, double y)
            {
                xpos = x;
                ypos = y;
            }
            void SetScrollOffset(double xof, double yof)
            {
                xoffset = xof;
                yoffset = yof;
            }

            void GetPosition(double &xpos, double &ypos)
            {
                xpos = this->xpos;
                ypos = this->ypos;
            }

            void GetScrollOffset(double &xoffset, double &yoffset)
            {
                xoffset = this->xoffset;
                yoffset = this->yoffset;
                this->xoffset = 0;
                this->yoffset = 0;
            }
            bool GetRawInput() { return raw; }

        private:
            double xpos, ypos, xoffset, yoffset;
            bool raw;
            desolate::Window &window;
        };
    }
}

#endif // __mouse_hpp_