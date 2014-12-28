#include "Program.hpp"

class GameProgram: public Program {
private:
        template<typename T>
        const GLuint getUniform(const T) const;
public:
        const GLuint projection_matrix_uniform;
        const GLuint modelview_matrix_uniform;
        GameProgram();
};
