// include: bmi-file.h
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#ifndef _BMI_INTERNAL_FILE_H
#define _BMI_INTERNAL_FILE_H

#include <stdint.h>
#include <stddef.h>

#define BMI_TEXTUAL_SHORT "bmi"
#define BMI_TEXTUAL_LONG "bitmap image"

#define BMI_HEADER_0 0x42
#define BMI_HEADER_1 0x4d
#define BMI_HEADER_2 0x49

#define BMI_VERSION_0_0_0 0x00
#define BMI_VERSION_1_0_0 0x40
#define BMI_VERSION_CURRENT BMI_VERSION_0_0_0

#define BMI_VERSION_PACK(maj, min, pat) \
    ((uint8_t)((maj) << 6 | (min) << 3 | (pat)))

#define BMI_VERSION_IS_CURRENT(ver) ((ver) == BMI_VERSION_CURRENT)
#define BMI_VERSION_IS_OUTDATED(ver) ((ver) < BMI_VERSION_CURRENT)
#define BMI_VERSION_IS_LATER(ver) ((ver) > BMI_VERSION_CURRENT)

// Returns a read-only textual description of the packed version
const char* bmi_version_string(const uint8_t version);

typedef enum {
    BMI_FL_IS_GRAYSCALE = 1 << 0
} bmi_flags;

typedef struct {
    uint8_t header[3];
    uint8_t version[1];
    uint32_t width;
    uint32_t height;
    uint32_t flags;
    uint8_t contents[];
} bmi_buffer;

#define BMI_FILE_IS_VALID(buffer) ((buffer).header[0] == BMI_HEADER_0 \
                                   && (buffer).header[1] == BMI_HEADER_1 \
                                   && (buffer).header[2] == BMI_HEADER_2)

// Returns the total size, in bytes, of the BMI's contents
size_t bmi_buffer_content_size(const bmi_buffer* buffer);

#ifdef _BMI_USE_INTERNAL
#define BMI_COMPONENT_SIZE_FROM_FL(fl) (((fl) & BMI_FL_IS_GRAYSCALE) ? 1 : 3)

#define bmi_buffer_component_size(buffer) \
    BMI_COMPONENT_SIZE_FROM_FL(buffer->flags)

#define BMI_GET_INDEX(buffer, x, y) \
    (((buffer)->width * (y) + (x)) * bmi_buffer_component_size(buffer))

#endif

#endif /* _BMI_INTERNAL_FILE_H */
