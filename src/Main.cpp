#include <iostream>
#include <memory>
#include <cassert>
#include <exception>
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

#include "lacuna/util/opengl/Shader.h"
#include "lacuna/util/opengl/VertexArray.h"
#include "lacuna/util/opengl/Buffers.h"

#include "lacuna/util/opengl/camera/OrthographicCamera.h"

static bool running;

static int screen_width, screen_height;

static std::ofstream out;

const float ratio = (16.0f / 9.0f);
float zoom = 3.5f;

lacuna::OrthographicCamera camera = lacuna::OrthographicCamera(0.0f, 0.0f, 0.0f, 0.0f);

int main(int argc, char *argv[])
{
	running = false;
	GLFWwindow *window;
	screen_width = 1280;
	screen_height = 720;
	out.open("session.log");

	if (!glfwInit())
	{
		out << "FATAL ERROR: GLFW initialization failed!" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	
	window = glfwCreateWindow(screen_width, screen_height, "Hello, World!", NULL, NULL);
	if (!window)
	{
		out << "FATAL ERROR: GLFW window creation failed: " << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwGetWindowSize(window, &screen_width, &screen_height);
	{
		const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(window, (vidmode->width - screen_width) / 2, (vidmode->height - screen_height) / 2);
	}
	glfwShowWindow(window);

	glfwSetScrollCallback(window, GLFWScrollCallback);
	glfwSetFramebufferSizeCallback(window, GLFWFrambufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		out << "FATAL ERROR: GLAD initialization failed!" << std::endl;
		return -1;
	}

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
		   -1.5f, -0.5f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		   -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		   -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		   -1.5f,  0.5f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

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

			4, 5, 6,
			6, 7, 4,

			8, 9, 10,
			9, 11, 8,
		};

		lacuna::VertexArray texturedVA;
		lacuna::VertexBuffer texturedVB(texturedVertices, sizeof(texturedVertices));
		lacuna::VertexBufferLayout texturedVBL;
		texturedVBL.Push(lacuna::push_t::Float, 3, sizeof(float) * 5);
		texturedVBL.Push(lacuna::push_t::Float, 2, sizeof(float) * 5);
		texturedVA.AddBuffer(texturedVB, texturedVBL);
		lacuna::IndexBuffer ib(indices, 18);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		lacuna::VertexArray coloredVA;
		lacuna::VertexBuffer coloredVB(coloredVertices, sizeof(coloredVertices));
		lacuna::VertexBufferLayout coloredVBL;
		coloredVBL.Push(lacuna::push_t::Float, 3, sizeof(float) * 7);
		coloredVBL.Push(lacuna::push_t::Float, 4, sizeof(float) * 7);
		coloredVA.AddBuffer(coloredVB, coloredVBL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib.GetID());

		auto texturedShader = lacuna::Shader::LoadFromFiles("./assets/shaders/Textured.vert", "./assets/shaders/Textured.frag");
		auto coloredShader = lacuna::Shader::LoadFromFiles("./assets/shaders/Colored.vert", "./assets/shaders/Colored.frag");

		camera = lacuna::OrthographicCamera(-ratio * zoom, ratio * zoom, -zoom, zoom);
		glm::mat4 tansform = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glViewport(0, 0, screen_width, screen_height);

		running = true;
		while (running)
		{
			glfwPollEvents();

			if (glfwWindowShouldClose(window))
			{
				running = false;
			}

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

			texturedShader->SetUniformMat4x4("u_ViewProj", camera.GetViewProjectionMatrix());
			texturedShader->SetUniformMat4x4("u_Transform", tansform);

			coloredShader->SetUniformMat4x4("u_ViewProj", camera.GetViewProjectionMatrix());
			coloredShader->SetUniformMat4x4("u_Transform", tansform);

			glUseProgram(texturedShader->GetID());
			glBindVertexArray(texturedVA.GetID());

			//glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

			glBindVertexArray(0);
			glUseProgram(0);

			glUseProgram(coloredShader->GetID());
			glBindVertexArray(coloredVA.GetID());

			glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

			glBindVertexArray(0);
			glUseProgram(0);

			glfwSwapBuffers(window);
		}
	}

	glfwMakeContextCurrent(NULL);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void GLFWFrambufferSizeCallback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GLFWScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
	zoom -= yoffset * 0.25f;
	zoom = std::max(zoom, 0.25f);
	camera.SetProjection(-ratio * zoom, ratio * zoom, -zoom, zoom);
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
