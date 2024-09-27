#ifndef TJURM_TEST_INCLUDE_TESTS_H_
#define TJURM_TEST_INCLUDE_TESTS_H_

// 练习1，实现库函数strlen
int my_strlen(char *str);

// 练习2，实现库函数strcat
void my_strcat(char *str_1, char *str_2);

// 练习3，实现库函数strstr
char* my_strstr(char *s, char *p);

// 练习4，将彩色图片(rgb)转化为灰度图片
void rgb2gray(float *in, float *out, int h, int w);

// 练习5，实现图像处理算法 resize：缩小或放大图像
void resize(float *in, float *out, int h, int w, int c, float scale);

// 练习6，实现图像处理算法：直方图均衡化
void hist_eq(float *in, int h, int w);

#endif // TJURM_TEST_INCLUDE_TESTS_H_
