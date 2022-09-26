// include: bmi-geometry.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_GEOMETRY_H
#define _BMI_INTERNAL_GEOMETRY_H

#include "bmi-file.h"
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint32_t x;
    uint32_t y;
} bmi_point;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
} bmi_rect;

// Constructors for point and rectangle structs
#define BMI_POINT(_x, _y) \
    ((bmi_point){ .x = (_x), .y = (_y) })
#define BMI_RECT(_x, _y, _w, _h) \
    ((bmi_rect){ .x = (_x), .y = (_y), .width = (_w), .height = (_h) })

// Clips the specified point to the given bounds
void bmi_clip_point(bmi_point* point, const bmi_rect bounds);

// Clips the specified rectangle to the given bounds
void bmi_clip_rect(bmi_rect* rect, const bmi_rect bounds);

typedef enum {
    BMI_RECT_EDGE_LEFT,
    BMI_RECT_EDGE_RIGHT,
    BMI_RECT_EDGE_TOP,
    BMI_RECT_EDGE_BOTTOM,
} bmi_rect_edge;

// Prints a debug description of the specified point to the given file
void bmi_dump_point(FILE* dest, const bmi_point point);

// Prints a debug description of the specified rect to the given file
void bmi_dump_rect(FILE* dest, const bmi_rect rect);

// Insets the specified rectangle by the given amount from the specified edge
void bmi_inset_rect(bmi_rect* rect, uint32_t delta, bmi_rect_edge edge);

// Sets the specified edge of the specified rectangle to the given amount
void bmi_set_rect(bmi_rect* rect, uint32_t width, bmi_rect_edge edge);

#endif /* _BMI_INTERNAL_GEOMETRY_H */
