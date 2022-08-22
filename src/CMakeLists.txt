add_executable(${PROJECT_NAME}

	# '/' sources

	"Main.cpp"
	
	# '/' headers

	"main.hpp"

	# '/desolate' headers

	"desolate/include.hpp"

	# '/desolate/util/window' sources

	"desolate/util/window/Window.cpp"
	"desolate/input/GLFWCallbackWrapper.cpp"
	"desolate/input/Mouse.cpp"
	"desolate/input/Keyboard.cpp"

	# '/desolate/util/window' headers

	"desolate/util/window/Window.hpp"
	"desolate/input/GLFWCallbackWrapper.hpp"
	"desolate/input/Mouse.hpp"
	"desolate/input/Keyboard.hpp"

	# '/desolate/util/error' sources

	"desolate/util/error/ErrorHandler.cpp"

	# '/desolate/util/error' headers

	"desolate/util/error/ErrorHandler.hpp"

	# '/desolate/util/opengl' sources

	"desolate/util/opengl/Shader.cpp"
	"desolate/util/opengl/Texture.cpp"
	"desolate/util/opengl/VertexArray.cpp"

	# '/desolate/util/opengl' headers

	"desolate/util/opengl/Shader.hpp"
	"desolate/util/opengl/Texture.hpp"
	"desolate/util/opengl/VertexArray.hpp"

	# '/desolate/util/opengl/buffers' sources

	"desolate/util/opengl/buffers/IndexBuffer.cpp"
	"desolate/util/opengl/buffers/VertexBuffer.cpp"

	# '/desolate/util/opengl/buffers' headers

	"desolate/util/opengl/buffers/IndexBuffer.hpp"
	"desolate/util/opengl/buffers/VertexBuffer.hpp"

	# '/desolate/util/opengl/buffers/common' sources

	"desolate/util/opengl/buffers/common/VertexBufferLayout.cpp"
	
	# '/desolate/util/opengl/buffers/common' headers

	"desolate/util/opengl/buffers/common/VertexBufferLayout.hpp"

	# '/desolate/util/opengl/camera' sources

	"desolate/util/opengl/camera/OrthographicCamera.cpp"

	# '/desolate/util/opengl/camera' headers

	"desolate/util/opengl/camera/OrthographicCamera.hpp"

	# '/desolate/render' headers

	"desolate/render/Renderer.hpp"

	# '/desolate/render' sources

	"desolate/render/Renderer.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${PROJECT_SOURCE_DIR}/deps/glfw/include"
	"${PROJECT_SOURCE_DIR}/deps/glad/include"
	"${PROJECT_SOURCE_DIR}/deps/glm"
	"${PROJECT_SOURCE_DIR}/deps/stb"
	"${PROJECT_SOURCE_DIR}/src"
)
target_link_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_BINARY_DIR}/deps/glfw/src"
	"${CMAKE_BINARY_DIR}/deps/glad"
)
if (UNIX)
target_link_libraries(${PROJECT_NAME} PRIVATE GL glad glfw3 m Xrandr Xi X11 Xxf86vm pthread dl Xinerama Xcursor)
endif (UNIX)
if (WIN32)
target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw3 opengl32)
endif (WIN32)