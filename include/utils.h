#ifndef TJURM_TEST_INCLUDE_UTILS_H_
#define TJURM_TEST_INCLUDE_UTILS_H_

// 读取路径为path的jpg图片
void imread(char *path, float **out_data, int *out_h, int *out_w, int *out_c);

// 将图片保存到path
void imwrite(char *path, float *data, int h, int w, int c);

// 分配一个长度为n的float数组
float* fmalloc(int n);

#endif