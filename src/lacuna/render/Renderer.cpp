#include "Renderer.hpp"

#include <iostream>

namespace lacuna {
        void Renderer::Init(Window& window, RendererAPI api) {
            switch (api) {
                case OPENGL:
                    {
                        if (!glfwInit()) {
                            ErrorHandler::ThrowError("FATAL: failed to initalize glfw!", ErrorType::RUNTIME);
                        }
                        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	                    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	                    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	                    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
                        window.Init();
                        glfwMakeContextCurrent(window.GetWindowHandle());
                        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	                    {
                            ErrorHandler::ThrowError("FATAL: failed to initialize glad!", ErrorType::RUNTIME);
	                    }
                        glfwShowWindow(window.GetWindowHandle());
                        break;
                    }
                case VULKAN:
                    {
                        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
                        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
                        window.Init();
                        break;
                    }
                case DIRECTX:
                    {
                        window.Init();
                    }
            }
        }
        void Renderer::Destroy(Window& window, RendererAPI api) {
            switch (api) {
                case OPENGL:
                    {
                        glfwMakeContextCurrent(nullptr);
                        window.Destroy();
                        glfwTerminate();
                        break;
                    }
                case VULKAN:
                    {
                        break;
                    }
                case DIRECTX:
                    {
                        break;
                    }
            }
        }
};