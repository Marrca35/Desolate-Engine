add_executable(${PROJECT_NAME}

	# '/' sources

	"Main.cpp"
	
	# '/' headers

	"main.hpp"

	# '/lacuna' headers

	"lacuna/include.hpp"

	# '/lacuna/util/window' sources

	"lacuna/util/window/Window.cpp"
	"lacuna/input/GLFWCallbackWrapper.cpp"
	"lacuna/input/Mouse.cpp"
	"lacuna/input/Keyboard.cpp"

	# '/lacuna/util/window' headers

	"lacuna/util/window/Window.hpp"
	"lacuna/input/GLFWCallbackWrapper.hpp"
	"lacuna/input/Mouse.hpp"
	"lacuna/input/Keyboard.hpp"

	# '/lacuna/util/error' sources

	"lacuna/util/error/ErrorHandler.cpp"

	# '/lacuna/util/error' headers

	"lacuna/util/error/ErrorHandler.hpp"

	# '/lacuna/util/opengl' sources

	"lacuna/util/opengl/Shader.cpp"
	"lacuna/util/opengl/Texture.cpp"
	"lacuna/util/opengl/VertexArray.cpp"

	# '/lacuna/util/opengl' headers

	"lacuna/util/opengl/Shader.hpp"
	"lacuna/util/opengl/Texture.hpp"
	"lacuna/util/opengl/VertexArray.hpp"

	# '/lacuna/util/opengl/buffers' sources

	"lacuna/util/opengl/buffers/IndexBuffer.cpp"
	"lacuna/util/opengl/buffers/VertexBuffer.cpp"

	# '/lacuna/util/opengl/buffers' headers

	"lacuna/util/opengl/buffers/IndexBuffer.hpp"
	"lacuna/util/opengl/buffers/VertexBuffer.hpp"

	# '/lacuna/util/opengl/buffers/common' sources

	"lacuna/util/opengl/buffers/common/VertexBufferLayout.cpp"
	
	# '/lacuna/util/opengl/buffers/common' headers

	"lacuna/util/opengl/buffers/common/VertexBufferLayout.hpp"

	# '/lacuna/util/opengl/camera' sources

	"lacuna/util/opengl/camera/OrthographicCamera.cpp"

	# '/lacuna/util/opengl/camera' headers

	"lacuna/util/opengl/camera/OrthographicCamera.hpp"

	# '/lacuna/render' headers

	"lacuna/render/Renderer.hpp"

	# '/lacuna/render' sources

	"lacuna/render/Renderer.cpp"
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