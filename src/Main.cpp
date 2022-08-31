#include <iostream>
#include <memory>
#include <cassert>
#include <exception>
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#endif

#include "desolate/include.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.hpp"

#include "desolate/util/opengl/Shader.hpp"
#include "desolate/util/opengl/VertexArray.hpp"
#include "desolate/util/opengl/Buffers.hpp"

#include "desolate/util/opengl/camera/OrthographicCamera.hpp"

#include "desolate/input/Input.hpp"
#include "desolate/render/Renderer.hpp"
#include "desolate/util/window/Window.hpp"

static bool running;

static int screen_width, screen_height;

static std::ofstream out;

const float ratio = (16.0f / 9.0f);
float zoom = 3.5f;

desolate::OrthographicCamera camera = desolate::OrthographicCamera(0.0f, 0.0f, 0.0f, 0.0f);

int main(int argc, char *argv[])
{
	running = false;
	screen_width = 1280;
	screen_height = 720;
	out.open("session.log");

	desolate::Window window("desolate Engine Test", screen_width, screen_height, 0);
	desolate::Renderer::Init(window, desolate::RendererAPI::OPENGL);

	//glfwSetScrollCallback(window, GLFWScrollCallback);
	//glfwSetFramebufferSizeCallback(window, GLFWFrambufferSizeCallback);

	{
		GLfloat texturedVertices[] = {
			 -1.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			 -0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
			 -0.5f,  0.5f,  1.0f, 2.0f, 0.0f,
			 -1.5f,  0.5f, -1.0f, 3.0f, 0.0f,

			  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
			  1.5f, -0.5f, -1.0f, 1.0f, 0.0f,
			  1.5f,  0.5f, -1.0f, 2.0f, 0.0f,
			  0.5f,  0.5f,  1.0f, 3.0f, 0.0f,

			  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
			 -0.5f, -0.5f, -1.0f, 1.0f, 0.0f,
			 -0.5f,  0.5f,  1.0f, 2.0f, 0.0f,
			  0.5f, -0.5f, -1.0f, 3.0f, 0.0f,
		};

		GLfloat coloredVertices[] = {
		   -1.5f, -0.5f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // bottom left
		   -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // bottom right
		   -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top right
		   -1.5f,  0.5f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top left

		    0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		    1.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		    1.5f,  0.5f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		    0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,

		    0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		   -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		   -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		    0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		};

		GLuint indices[] = {
			0, 1, 2,
			2, 3, 0,

			//4, 5, 6,
			//6, 7, 4,

			//8, 9, 10,
			//9, 11, 8,
		};

		desolate::VertexArray texturedVA;
		desolate::VertexBuffer texturedVB(texturedVertices, sizeof(texturedVertices));
		desolate::VertexBufferLayout texturedVBL;
		texturedVBL.Push(desolate::push_t::Float, 3, sizeof(float) * 5);
		texturedVBL.Push(desolate::push_t::Float, 2, sizeof(float) * 5);
		texturedVA.AddBuffer(texturedVB, texturedVBL);
		desolate::IndexBuffer ib(indices, 18);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		desolate::VertexArray coloredVA;
		desolate::VertexBuffer coloredVB(coloredVertices, sizeof(coloredVertices));
		desolate::VertexBufferLayout coloredVBL;
		coloredVBL.Push(desolate::push_t::Float, 3, sizeof(float) * 7);
		coloredVBL.Push(desolate::push_t::Float, 4, sizeof(float) * 7);
		coloredVA.AddBuffer(coloredVB, coloredVBL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib.GetID());

		auto texturedShader = desolate::Shader::LoadFromFiles("./assets/shaders/Textured.vert", "./assets/shaders/Textured.frag");
		auto coloredShader = desolate::Shader::LoadFromFiles("./assets/shaders/Colored.vert", "./assets/shaders/Colored.frag");

		camera = desolate::OrthographicCamera(-ratio * zoom, ratio * zoom, -zoom, zoom);
		glm::mat4 tansform = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glViewport(0, 0, screen_width, screen_height);

		double xoffset, yoffset;

		running = true;
		while (running)
		{
			desolate::Renderer::Update(window);
			window.GetMouse().Update();

			if (glfwWindowShouldClose(window.GetWindowHandle()))
			{
				running = false;
			}

			window.GetMouse().GetScrollOffset(xoffset, yoffset);
			zoom -= yoffset * 0.25f;
			zoom = std::max(zoom, 0.25f);
			camera.SetProjection(-ratio * zoom, ratio * zoom, -zoom, zoom);

			if (window.GetKeyboard().GetKeyPressed(GLFW_KEY_F11))
			{
				window.ChangeFullscreen();
				//window.GetKeyboard().SetKeyPressed(GLFW_KEY_F11, false);
			}

			texturedShader->SetUniformMat4x4("u_ViewProj", camera.GetViewProjectionMatrix());
			texturedShader->SetUniformMat4x4("u_Transform", tansform);

			coloredShader->SetUniformMat4x4("u_ViewProj", camera.GetViewProjectionMatrix());
			coloredShader->SetUniformMat4x4("u_Transform", tansform);

			glUseProgram(coloredShader->GetID());
			glBindVertexArray(coloredVA.GetID());

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

			desolate::Renderer::Render(window, coloredVA, ib, coloredShader);

			glUseProgram(texturedShader->GetID());
			glBindVertexArray(texturedVA.GetID());

			//glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

			glBindVertexArray(0);
			glUseProgram(0);

			glBindVertexArray(0);
			glUseProgram(0);

			glfwSwapBuffers(window.GetWindowHandle());
		}
	}

	glfwTerminate();

	return 0;
}

void GLFWErrorCallback(int error, const char *description)
{
	out << "[GLFW ERROR " << error << "]: " << description << std::endl;
	std::cerr << "[GLFW ERROR " << error << "]: " << description << std::endl;
}


#ifdef _WIN32
INT WINAPI WinMain(
	_In_	 HINSTANCE hInst,
	_In_opt_ HINSTANCE hPrevInst,
	_In_	 LPSTR lpCmdLine,
	_In_	 INT nCmdShow)
{
	int returnCode = main(__argc, __argv);
	out << "Application exited with return code (" << returnCode << ')' << std::endl;
	out.close();
	return returnCode;
}
#endif
