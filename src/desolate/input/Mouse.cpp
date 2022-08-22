#include "Mouse.hpp"

#include "desolate/include.hpp"
#include "desolate/util/error/ErrorHandler.hpp"
#include "desolate/util/window/Window.hpp"

namespace desolate::input
{
    void Mouse::Update()
    {
        
    }

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
}