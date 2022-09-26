// include: bmi-error.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_ERROR_H
#define _BMI_INTERNAL_ERROR_H

#ifdef _BMI_USE_INTERNAL
void bmi_set_error(const char* error);
#endif

const char* bmi_last_error(void);

#define BMI_SUCCESS 0
#define BMI_FAILURE 1
#define BMI_BUG 2

// NULL
#include <stddef.h>
#define BMI_PTR_FAILURE NULL

#define _BMI_THIRD(x, y, z, ...) z
#define _BMI_SELECT(x, y, ...) _BMI_THIRD(__VA_ARGS__, x, y, ~)

#define _BMI_IS_FAILABLE_bmi_buffer_overdraw_buffer ~, ~
#define _BMI_IS_FAILABLE_bmi_buffer_new ~, ~
#define _BMI_IS_FAILABLE_bmi_buffer_from_file ~, ~
#define _BMI_IS_FAILABLE_bmi_buffer_to_file ~, ~
#define _BMI_IS_FAILABLE_bmi_buffer_to_ppm ~, ~
#define _BMI_IS_FAILABLE_bmi_buffer_to_bmp ~, ~

#define BMI_IS_FAILABLE(func) _BMI_SELECT(1, 0, _BMI_IS_FAILABLE_##func)

#endif /* _BMI_INTERNAL_ERROR_H */
