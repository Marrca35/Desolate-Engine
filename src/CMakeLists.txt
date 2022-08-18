add_executable(${PROJECT_NAME}

	# '/' sources

	"Main.cpp"
	
	# '/' headers

	"main.h"

	# '/walnut/util' sources

	"walnut/util/Renderer.cpp"
	"walnut/util/Shader.cpp"
	"walnut/util/Texture.cpp"
	"walnut/util/VertexArray.cpp"

	# '/walnut/util' headers

	"walnut/util/Renderer.h"
	"walnut/util/Shader.h"
	"walnut/util/Texture.h"
	"walnut/util/VertexArray.h"

	# '/walnut/util/buffers' sources

	"walnut/util/buffers/IndexBuffer.cpp"
	"walnut/util/buffers/VertexBuffer.cpp"

	# '/walnut/util/buffers' headers

	"walnut/util/buffers/IndexBuffer.h"
	"walnut/util/buffers/VertexBuffer.h"

	# '/walnut/util/buffers/common' sources

	"walnut/util/buffers/common/VertexBufferLayout.cpp"
	
	# '/walnut/util/buffers/common' headers

	"walnut/util/buffers/common/VertexBufferLayout.h"

	# '/walnut/util/camera' sources

	"walnut/util/camera/OrthographicCamera.cpp"

	# '/walnut/util/camera' headers

	"walnut/util/camera/OrthographicCamera.h"
)
target_include_directories(${PROJECT_NAME} PRIVATE
#	"${PROJECT_SOURCE_DIR}/deps/glfw/include"
	"${PROJECT_SOURCE_DIR}/deps/glad/include"
#	"${PROJECT_SOURCE_DIR}/deps/glm"
)
target_link_directories(${PROJECT_NAME} PRIVATE
#	"${CMAKE_BINARY_DIR}/deps/glfw/src"
	"${CMAKE_BINARY_DIR}/deps/glad"
)
target_link_libraries(${PROJECT_NAME} PRIVATE GL glad glfw m Xrandr Xi X11 Xxf86vm pthread dl Xinerama Xcursor)