#include "PerspectiveCamera.hpp"

#include "desolate/input/Input.hpp"

namespace desolate
{
    void PerspectiveCamera::Update(Window& window)
    {
        input::Keyboard& k = window.GetKeyboard();
        if (k.GetKeyPressed(GLFW_KEY_W)) {
            position += 0.05f * front;
        } else if (k.GetKeyPressed(GLFW_KEY_S)) {
            position -= 0.05f * front;
        }
    }
}