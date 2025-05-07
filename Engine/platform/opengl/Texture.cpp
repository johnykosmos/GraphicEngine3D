#include "glad/glad.h"
#include "Texture.hpp"

#include "stb_image/stb_image.h"

namespace eng {

    Texture::Texture(const char* sourcePath, const TextureSpec& spec){
        int width, height, nrChannels;
        unsigned char* data = stbi_load(sourcePath, &width, &height, &nrChannels, 0);
        if (!data) {
            return;
        }

        stbi_set_flip_vertically_on_load(true);

        glGenTextures(1, &id); 
        bind();

        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, spec.horizontalWrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, spec.verticalWrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, spec.minFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, spec.magFilter);

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }

    void Texture::bind() const {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, id);  
    }

    void Texture::unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);  
    }

    Texture::~Texture() {
        glDeleteTextures(1, &id);
    }

} // namespace eng
