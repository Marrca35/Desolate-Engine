#include "GLFWCallbackWrapper.hpp"

namespace lacuna {
    void GLFWCallbackWrapper::Init() {
        glfwSetErrorCallback(GLFWErrorCallback);
    }

    void GLFWCallbackWrapper::Destroy() {
        glfwSetErrorCallback(nullptr);
    }

    void GLFWCallbackWrapper::GLFWErrorCallback(int error, const char* description) {

    }
}