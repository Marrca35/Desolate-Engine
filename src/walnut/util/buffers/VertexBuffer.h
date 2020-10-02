#pragma once

#include <glad/glad.h>

#include "common/VertexBufferLayout.h"

namespace walnut {
	class VertexBuffer {
	public:
		VertexBuffer(const void *data, GLsizeiptr size);
		~VertexBuffer(void);

		inline GLuint GetID(void) const { return m_ID; }
	private:
		GLuint m_ID;
	};
}
