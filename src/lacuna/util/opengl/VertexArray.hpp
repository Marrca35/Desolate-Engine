#ifndef __vertex_array_hpp_
#define __vertex_array_hpp_

#include <glad/glad.h>

namespace lacuna {
#ifndef __buffers
	class VertexBuffer;
	class VertexBufferLayout;
#endif
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout);

		inline GLuint GetID(void) const { return m_ID; }
	private:
		GLuint m_ID;
	};
}
#endif // __vertex_array_hpp_
