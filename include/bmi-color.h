// include: bmi-color.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_COLOR_H
#define _BMI_INTERNAL_COLOR_H

#include <stdint.h>

typedef uint32_t bmi_channel;
typedef uint32_t bmi_pixel;

#ifdef _BMI_PIXEL_NAMED_COMPONENT
#define bmi_component bmi_pixel
#endif

#define BMI_PIXEL_INVALID ((bmi_pixel)(-1LL))

// Packs components based on input values for RGB or grayscale
#define BMI_RGB(r, g, b) ((bmi_pixel)((r) | (g) << 8 | (b) << 16))
#define BMI_GRY(v) ((bmi_pixel)(v))

// Unpacks components
#define BMI_RGB_R(c) ((bmi_pixel)((c) & 0xFF))
#define BMI_RGB_G(c) ((bmi_pixel)((c) >> 8 & 0xFF))
#define BMI_RGB_B(c) ((bmi_pixel)((c) >> 16 & 0xFF))
#define BMI_GRY_V(c) ((bmi_pixel)((c) & 0xFF))

// Predefined colors
#define BMI_RGB_WHITE() BMI_RGB(255, 255, 255)
#define BMI_RGB_BLACK() BMI_RGB(0, 0, 0)

#define BMI_RGB_RED() BMI_RGB(255, 0, 0)
#define BMI_RGB_GREEN() BMI_RGB(0, 255, 0)
#define BMI_RGB_BLUE() BMI_RGB(0, 0, 255)

#define BMI_RGB_MAGENTA() BMI_RGB(255, 0, 255)
#define BMI_RGB_YELLOW() BMI_RGB(255, 255, 0)
#define BMI_RGB_CYAN() BMI_RGB(0, 255, 255)

#define BMI_RGB_ORANGE() BMI_RGB(255, 128, 0)

#define BMI_GRY_WHITE() BMI_GRY(255)
#define BMI_GRY_BLACK() BMI_GRY(0)

// Blends two RGB colors with the given intensities
bmi_pixel bmi_rgb_blend(bmi_pixel c0, uint32_t i0, bmi_pixel c1, uint32_t i1);

#endif /* _BMI_INTERNAL_COLOR_H */
