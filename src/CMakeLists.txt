add_executable(${PROJECT_NAME}

	# '/' sources

	"Main.cpp"
	
	# '/' headers

	"main.h"

	# '/lacuna/util' sources

	"lacuna/util/Renderer.cpp"
	"lacuna/util/Shader.cpp"
	"lacuna/util/Texture.cpp"
	"lacuna/util/VertexArray.cpp"

	# '/lacuna/util' headers

	"lacuna/util/Renderer.h"
	"lacuna/util/Shader.h"
	"lacuna/util/Texture.h"
	"lacuna/util/VertexArray.h"

	# '/lacuna/util/buffers' sources

	"lacuna/util/buffers/IndexBuffer.cpp"
	"lacuna/util/buffers/VertexBuffer.cpp"

	# '/lacuna/util/buffers' headers

	"lacuna/util/buffers/IndexBuffer.h"
	"lacuna/util/buffers/VertexBuffer.h"

	# '/lacuna/util/buffers/common' sources

	"lacuna/util/buffers/common/VertexBufferLayout.cpp"
	
	# '/lacuna/util/buffers/common' headers

	"lacuna/util/buffers/common/VertexBufferLayout.h"

	# '/lacuna/util/camera' sources

	"lacuna/util/camera/OrthographicCamera.cpp"

	# '/lacuna/util/camera' headers

	"lacuna/util/camera/OrthographicCamera.h"
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
target_link_libraries(${PROJECT_NAME} PRIVATE GL glad glfw3 m Xrandr Xi X11 Xxf86vm pthread dl Xinerama Xcursor)