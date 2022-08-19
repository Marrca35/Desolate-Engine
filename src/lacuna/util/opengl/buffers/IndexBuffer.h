#pragma once

#include <glad/glad.h>

namespace lacuna {
	class IndexBuffer {
	public:
		IndexBuffer(const GLuint *data, GLint count);
		~IndexBuffer(void);

		inline GLuint GetID(void) const { return m_ID; }
		inline GLuint GetCount(void) const { return m_Count; }
	private:
		GLuint m_ID, m_Count;
	};
}
