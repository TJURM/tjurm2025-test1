#include "utils.h"
#include "tests.h"
#include <iostream>
#include <cstring>




void test_rgb2gray() {
    std::cout << "开始测试函数 << rgb2gray >> ..." << std::endl;
    char *path = "../images/rgb2gray/input.jpg";
    float *img;
    int h, w, c;

    imread(path, &img, &h, &w, &c);
    std::cout << "读取图片images/rgb2gray/input.jpg，高度为" << h << "，高度为" << w
              << "，通道数为" << c
              << std::endl;

    float *gray = fmalloc(h * w);
    rgb2gray(img, gray, h, w);

    char *out_path = "../images/rgb2gray/output.jpg";
    imwrite(out_path, gray, h, w, 1);
    std::cout << "使用你的代码产生的灰度图片已经保存为images/rgb2gray/output.jpg"
              << std::endl
              << "可以与images/rgb2gray/answer.jpg进行比较，看结果是否正确"
              << std::endl;

    free(gray), free(img);
    std::cout << std::endl << std::endl;
}

void test_strlen() {
    std::cout << "开始测试函数 << my_strlen >> ..." << std::endl;
    char *strs[] = {
        "123456", "", "hello world!"
    };

    bool pass = true;
    for (int i = 0; i < 3; i++)
        if (strlen(strs[i]) != my_strlen(strs[i])) {
            std::cout << "未通过，错误的输入为" << strs[i] << std::endl;
            pass = false;
            break;
        }

    if (pass) {
        std::cout << "通过" << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void test_strcat() {
    std::cout << "开始测试函数 << my_strcat >> ..." << std::endl;

    int n = 2000;
    // 来源：电影《绿皮书》
    char str1[n] =
    "Dear Dolores\n"
    "When I think of you, I'm reminded of the beautiful plains of Iowa. The distance \n"
    "between us is breaking my spirit. My time and experiences without you are meaningless\n"
    "to me. ";

    char str2[n] =
    "Falling in love with you was the easiest thing I have ever done. Nothing \n"
    "matters to me but you. And everyday I am alive, I'm aware of this. I loved you the day \n"
    "I met you, I love you today... And I will love you to rest of my life.";

    char str1_tmp[n], str2_tmp[n];
    strcpy(str1_tmp, str1), strcpy(str2_tmp, str2);

    strcat(str1, str2);
    my_strcat(str1_tmp, str2_tmp);

    if (!strcmp(str1, str1_tmp)) {
        std::cout << "通过" << std::endl;
    } else {
        std::cout << "未通过" << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void test_strstr() {
    std::cout << "开始测试函数 << my_strstr >> ..." << std::endl;

    char *s = "jaldjqionekqnwjsfjdviozdfaier234WDAJdlDAKDie3j";
    char *p[] = {"wjsfjdvioz", "qqqqq",  "j"};

    bool pass = true;
    for (int i = 0; i < 3; i++)
        if (strstr(s, p[i]) != my_strstr(s, p[i])) {
            std::cout << "未通过，错误的子串为" << p[i] << std::endl;
            pass = false;
            break;
        }

    if (pass) {
        std::cout << "通过" << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void test_hist_eq() {
    std::cout << "开始测试函数 << hist_eq >> ..." << std::endl;
    char *path = "../images/hist_eq/input.jpg";
    float *img;
    int h, w, c;

    imread(path, &img, &h, &w, &c);
    std::cout << "读取图片images/hist_eq/input.jpg，高度为" << h << "，高度为" << w
              << "，通道数为" << c
              << std::endl;

    hist_eq(img, h, w);

    char *out_path = "../images/hist_eq/output.jpg";
    imwrite(out_path, img, h, w, 1);
    std::cout << "使用你的代码产生的结果已经保存为images/hist_eq/output.jpg"
              << std::endl
              << "可以与images/hist_eq/answer.jpg进行比较，看结果是否正确"
              << std::endl;

    free(img);
    std::cout << std::endl << std::endl;
}


void test_resize() {
    char *path = "../images/resize/input.jpg";
    float *img;
    int h, w, c;

    imread(path, &img, &h, &w, &c);
    std::cout << "读取图片images/resize/input.jpg，高度为" << h << "，高度为" << w
              << std::endl;

    float scales[2] = {2.0 / 3, 2};
    for (int i = 0; i < 2; i++) {
        float scale = scales[i];
        int new_w = w * scale, new_h = h * scale;
        std::cout << "将图片 resize 为原来的" << scale << "倍，即" << new_h << ", " << new_w
                << std::endl;
        float *resized = fmalloc(new_h * new_w * c);
        resize(img, resized, h, w, c, scale);

        char out_path[] = "../images/resize/output .jpg";
        out_path[23] = '0' + i;
        imwrite(out_path, resized, new_h, new_w, c);
        std::cout << "使用你的代码产生的图片已经保存为"
                  << out_path << std::endl;

        free(resized);
    }
    free(img);
}

int main() {
    std::cout << "开始测试函数 << my_strlen >> ..." << std::endl;
    test_strlen();
    std::cout << "开始测试函数 << my_strcat >> ..." << std::endl;
    test_strcat();
    std::cout << "开始测试函数 << my_strstr >> ..." << std::endl;
    test_strstr();
    std::cout << "开始测试函数 << rgb2gray >> ..." << std::endl;
    test_rgb2gray();
    std::cout << "开始测试函数 << resize >> ..." << std::endl;
    test_resize();
    std::cout << "开始测试函数 << hist_eq >> ..." << std::endl;
    test_hist_eq();
    return 0;
}
