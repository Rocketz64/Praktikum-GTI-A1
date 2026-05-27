#include "textures.h"
#include "types.h"
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Instantiate texture variables
GLuint backgroundTexture;
GLuint backgroundTexture2;
GLuint backgroundTexture3;
GLuint groundTexture;
GLuint asteroidTexture;

void loadBackground() {
    int lebar, tinggi, channels;
    GLenum format;

    unsigned char* data = stbi_load("bg.jpg", &lebar, &tinggi, &channels, 0);
    if (data != NULL) {
        glGenTextures(1, &backgroundTexture);
        glBindTexture(GL_TEXTURE_2D, backgroundTexture);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
        format = (channels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, lebar, tinggi, 0, format, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
        printf("Background 1 loaded successfully.\n");
    } else {
        printf("Failed to load bg.jpg\n");
    }

    data = stbi_load("asteroidField.jpg", &lebar, &tinggi, &channels, 0);
    if (data != NULL) {
        glGenTextures(1, &backgroundTexture2);
        glBindTexture(GL_TEXTURE_2D, backgroundTexture2);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
        format = (channels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, lebar, tinggi, 0, format, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
        printf("Background 2 loaded successfully.\n");
    } else {
        printf("Failed to load asteroidField.jpg\n");
    }
    
    data = stbi_load("bg3.jpg", &lebar, &tinggi, &channels, 0); 
    if (data != NULL) {
        glGenTextures(1, &backgroundTexture3);
        glBindTexture(GL_TEXTURE_2D, backgroundTexture3);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
        format = (channels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, lebar, tinggi, 0, format, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
        printf("Background 3 loaded successfully.\n");
    } else {
        printf("Failed to load bg3.jpg\n");
    }
}

void loadAsteroidTexture() {
    int lebar, tinggi, c;
    unsigned char* data = stbi_load("ast.jpg", &lebar, &tinggi, &c, 0);
    if (data != NULL) {
        glGenTextures(1, &asteroidTexture);
        glBindTexture(GL_TEXTURE_2D, asteroidTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, lebar, tinggi, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    } else {
        printf("Gagal load texture asteroidnya\n");
    }
}

void loadGroundTexture() {
    int lebar, tinggi, c;
    unsigned char* data = stbi_load("ast.jpg", &lebar, &tinggi, &c, 0);
    if (data != NULL) {
        glGenTextures(1, &groundTexture);
        glBindTexture(GL_TEXTURE_2D, groundTexture);
        
        GLenum format = (c == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, lebar, tinggi, 0, format, GL_UNSIGNED_BYTE, data);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_image_free(data);
        printf("Ground surface texture loaded successfully.\n");
    } else {
        printf("Failed to load ground texture.\n");
    }
}
