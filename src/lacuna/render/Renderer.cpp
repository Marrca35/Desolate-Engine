#include "Renderer.hpp"
#include "Window.hpp"

namespace lacuna {
        Renderer::Renderer(RendererAPI api, Window& window) : api(api), window(window) { }
        void Renderer::Init() {
            switch (api) {
                case RendererAPI::OPENGL:
                    {
                        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	                    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	                    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	                    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
                        window.Init();
                        break;
                    }
                case RendererAPI::VULKAN:
                    {
                        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
                        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
                        window.Init();
                        break;
                    }
                case RendererAPI::DIRECTX:
                    {
                        window.Init();
                    }
            }
        }
        void Renderer::Destroy() {
            switch (api) {

            }
        }
};