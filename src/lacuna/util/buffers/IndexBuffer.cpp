#include "IndexBuffer.h"

#include <glad/glad.h>

namespace lacuna {
	IndexBuffer::IndexBuffer(const GLuint *data, GLint count) : m_Count(count)
	{
		glCreateBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
	}
	IndexBuffer::~IndexBuffer(void)
	{
		glDeleteBuffers(1, &m_ID);
	}
}
