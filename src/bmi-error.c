// src: bmi-error.c
// Copyright (C) 2021 Ethan Uppal. All rights reserved.

#define _BMU_USE_INTERNAL

// bmi_set_error, bmi_last_error
#include "bmi-error.h"

static const char* bmi_error;

void bmi_set_error(const char* error) {
    bmi_error = error;
}

const char* bmi_last_error() {
    return bmi_error;
}
