#include "utils.h"

#define STB_IMAGE_IMPLEMENTATION
#include "3rd/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "3rd/stb/stb_image_write.h"


float* fmalloc(int n) {
    return (float*)malloc(sizeof(float) * n);
}


void imread(char *path, float **out_data, int *out_h, int *out_w, int *out_c) {
    // load image, memory order is HWC (RGB)
    // see stb_image.h: 170
    int h, w, c;
    unsigned char *buffer = stbi_load(path, &w, &h, &c, 0);

    float *data = fmalloc(h * w * c);
    for (int i = 0; i < h * w * c; ++i)
        data[i] = (float)buffer[i];
    free(buffer);

    *out_data = data, *out_h = h, *out_w = w, *out_c = c;
}


void imwrite(char *path, float *data, int h, int w, int c) {
    int n = h * w * c;
    unsigned char *buffer = (unsigned char*)malloc(n);
    
    for (int i = 0; i < n; i++) {
        if (data[i] < 0.f)
            buffer[i] = 0;
        else if (data[i] > 255.f)
            buffer[i] = 255.f;
        else
            buffer[i] = (unsigned char)data[i];
    }
    stbi_write_jpg(path, w, h, c, buffer, 0);
    free(buffer);
}