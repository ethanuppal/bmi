// include: bmi-util.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_UTIL_H
#define _BMI_INTERNAL_UTIL_H

#include "bmi-file.h"
#include "bmi-geometry.h"
#include "bmi-color.h"
#include <stdio.h>

// Returns the pixel at the given point in the BMI buffer
bmi_pixel bmi_buffer_get_pixel(const bmi_buffer* buffer, bmi_point point);

// Allocates a new BMI buffer to be freed initialized with the given attributes
bmi_buffer* bmi_buffer_new(uint32_t width, uint32_t height, uint32_t flags);

// Reads in and allocates a new BMI buffer from the given file
bmi_buffer* bmi_buffer_from_file(FILE* source);

// Saves the BMI buffer to a file
int bmi_buffer_to_file(FILE* dest, const bmi_buffer* buffer);

// Saves the BMI buffer to a file as a PPM
int bmi_buffer_to_ppm(FILE* dest, const bmi_buffer* buffer);

// Saves the BMI buffer to a file as a BMP
int bmi_buffer_to_bmp(FILE* dest, const bmi_buffer* buffer);

#endif /* _BMI_INTERNAL_UTIL_H */
