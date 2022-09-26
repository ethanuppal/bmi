// src: bmi-file.c
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#define _BMI_USE_INTERNAL

// bmi_buffer_component_size
#include "bmi-file.h"

const char* bmi_version_string(const uint8_t version) {
    static char result[6] = { 0, '.', 0, '.', 0, 0 };
    result[0] = '0' + ((version >> 6) & 0x3);
    result[2] = '0' + ((version >> 3) & 0x7);
    result[4] = '0' + ((version >> 0) & 0x7);
    return result;
}

inline size_t bmi_buffer_content_size(const bmi_buffer* buffer) {
    return buffer->width * buffer->height * bmi_buffer_component_size(buffer);
}
