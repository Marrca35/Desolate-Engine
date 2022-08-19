add_executable(${PROJECT_NAME}

	# '/' sources

	"Main.cpp"
	
	# '/' headers

	"main.h"

	# '/lacuna/util/opengl' sources

	"lacuna/util/opengl/Renderer.cpp"
	"lacuna/util/opengl/Shader.cpp"
	"lacuna/util/opengl/Texture.cpp"
	"lacuna/util/opengl/VertexArray.cpp"

	# '/lacuna/util/opengl' headers

	"lacuna/util/opengl/Renderer.h"
	"lacuna/util/opengl/Shader.h"
	"lacuna/util/opengl/Texture.h"
	"lacuna/util/opengl/VertexArray.h"

	# '/lacuna/util/opengl/buffers' sources

	"lacuna/util/opengl/buffers/IndexBuffer.cpp"
	"lacuna/util/opengl/buffers/VertexBuffer.cpp"

	# '/lacuna/util/opengl/buffers' headers

	"lacuna/util/opengl/buffers/IndexBuffer.h"
	"lacuna/util/opengl/buffers/VertexBuffer.h"

	# '/lacuna/util/opengl/buffers/common' sources

	"lacuna/util/opengl/buffers/common/VertexBufferLayout.cpp"
	
	# '/lacuna/util/opengl/buffers/common' headers

	"lacuna/util/opengl/buffers/common/VertexBufferLayout.h"

	# '/lacuna/util/opengl/camera' sources

	"lacuna/util/opengl/camera/OrthographicCamera.cpp"

	# '/lacuna/util/opengl/camera' headers

	"lacuna/util/opengl/camera/OrthographicCamera.h"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${PROJECT_SOURCE_DIR}/deps/glfw/include"
	"${PROJECT_SOURCE_DIR}/deps/glad/include"
	"${PROJECT_SOURCE_DIR}/deps/glm"
	"${PROJECT_SOURCE_DIR}/deps/stb"
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