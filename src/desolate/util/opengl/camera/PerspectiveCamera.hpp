#ifndef __perspective_camera_hpp_
#define __perspective_camera_hpp_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "desolate/util/window/Window.hpp"

namespace desolate
{
    class PerspectiveCamera
    {
    public:
        PerspectiveCamera()
            : position(glm::vec3(0.0f, 0.0f, 3.0f)), front(glm::vec3(0.0f, 0.0f, -1.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)),
              view(glm::lookAt(position, position + front, up)) {}

        void Update(Window& window);

        glm::mat4 GetViewProjection();

    private:
        glm::vec3 position, front, up;
        glm::mat4 view;
    };
}

#endif // __perspective_camera_hpp_