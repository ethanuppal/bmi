// include: bmi-draw.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_DRAW_H
#define _BMI_INTERNAL_DRAW_H

#include "bmi-file.h"
#include "bmi-geometry.h"
#include "bmi-color.h"

// Draws a pixel at the specified coordinates
void bmi_buffer_draw_point(bmi_buffer* buffer, bmi_point point,
                           bmi_pixel pixel);

// Fills a rectangle in the specified bounds
void bmi_buffer_fill_rect(bmi_buffer* buffer, bmi_rect bounds,
                          bmi_pixel pixel);

// Strokes a rectangle in the specified bounds with specified thickness
void bmi_buffer_stroke_rect(bmi_buffer* buffer, bmi_rect bounds,
                            uint32_t thickness, bmi_pixel pixel);

// Fills an ellipse in the specified bounds
void bmi_buffer_fill_ellipse(bmi_buffer* buffer, bmi_rect bounds,
                             bmi_pixel pixel);

// Strokes a line between the specified points with specified thickness
void bmi_buffer_stroke_line(bmi_buffer* buffer, bmi_point start, bmi_point end,
                            uint32_t thickness, bmi_pixel pixel);

// Draws a BMI buffer in the specified bounds of another BMI buffer
int bmi_buffer_overdraw_buffer(bmi_buffer* buffer, bmi_rect region,
                               const bmi_buffer* layer);

#endif /* _BMI_INTERNAL_DRAW_H */
