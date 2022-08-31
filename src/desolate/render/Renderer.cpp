#include "Renderer.hpp"

#include <iostream>

namespace desolate
{
    void Renderer::Init(Window &window, RendererAPI api)
    {
        _init(window, api);
    }

    void Renderer::Destroy(Window &window, RendererAPI api)
    {
        _destroy(window, api);
    }

    void Renderer::_init(Window &window, RendererAPI api)
    {
        switch (api)
        {
        case OPENGL:
        {
            if (!glfwInit())
            {
                ErrorHandler::ThrowError("FATAL: failed to initalize glfw!", ErrorType::RUNTIME);
            }
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
            window.Init();
            GLFWCallbackWrapper::Init(window);
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

    void Renderer::_destroy(Window &window, RendererAPI api)
    {
        switch (api)
        {
        case OPENGL:
        {
            glfwMakeContextCurrent(nullptr);
            window.Destroy();
            GLFWCallbackWrapper::Destroy(window);
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

    void Renderer::Update(Window &window)
    {
        glfwPollEvents();
    }

    void Renderer::Render(Window& window, VertexArray &va, IndexBuffer &ib, std::unique_ptr<Shader> &shader)
    {

        glUseProgram(shader->GetID());
	    glBindVertexArray(va.GetID());

        glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
		glUseProgram(0);
    }
};