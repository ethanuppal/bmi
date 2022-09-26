// src: bmi-color.c
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#define _BMI_USE_INTERNAL

#include "bmi-color.h"

#define _u32(...) ((uint32_t)(__VA_ARGS__))

bmi_pixel bmi_rgb_blend(bmi_pixel c0, uint32_t i0, bmi_pixel c1, uint32_t i1) {
    const bmi_channel red = (_u32(BMI_RGB_R(c0)) * _u32(i0)
                             + _u32(BMI_RGB_R(c1)) * _u32(i1)) / 256;
    const bmi_channel green = (_u32(BMI_RGB_G(c0)) * _u32(i0)
                               + _u32(BMI_RGB_G(c1)) * _u32(i1)) / 256;
    const bmi_channel blue = (_u32(BMI_RGB_B(c0)) * _u32(i0)
                              + _u32(BMI_RGB_B(c1)) * _u32(i1)) / 256;
    return BMI_RGB(red, green, blue);
}
