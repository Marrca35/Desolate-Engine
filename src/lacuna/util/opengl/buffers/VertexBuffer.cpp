#include "VertexBuffer.h"

#include <glad/glad.h>

namespace lacuna {
	VertexBuffer::VertexBuffer(const void *data, GLsizeiptr size)
	{
		glCreateBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	VertexBuffer::~VertexBuffer(void)
	{
		glDeleteBuffers(1, &m_ID);
	}
}
