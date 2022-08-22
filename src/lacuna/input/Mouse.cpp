#include "Mouse.hpp"

#include "lacuna/include.hpp"
#include "lacuna/util/error/ErrorHandler.hpp"

namespace lacuna::input
{
    void Mouse::ChangeRawInput()
    {
        raw = !raw;
        if (glfwRawMouseMotionSupported())
        {
            glfwSetInputMode(window.GetWindowHandle(), GLFW_CURSOR, raw);
        }
        else
        {
            ErrorHandler::ThrowError("Raw input not supported!", ErrorType::INVALID_ARGUMENT);
        }
    }

    void Mouse::SetPosition(double x, double y)
    {
        xpos = x;
        ypos = y;
    }
}