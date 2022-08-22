#ifndef __index_buffer_hpp_
#define __index_buffer_hpp_

#include <glad/glad.h>

namespace desolate {
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
#endif // __index_buffer_hpp_
