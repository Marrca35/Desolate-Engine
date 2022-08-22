#ifndef __vertex_buffer_hpp_
#define __vertex_buffer_hpp_

#include <glad/glad.h>

#include "common/VertexBufferLayout.hpp"

namespace desolate {
	class VertexBuffer {
	public:
		VertexBuffer(const void *data, GLsizeiptr size);
		~VertexBuffer(void);

		inline GLuint GetID(void) const { return m_ID; }
	private:
		GLuint m_ID;
	};
}
#endif // __vertex_buffer_hpp_
