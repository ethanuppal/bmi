# Integrity

If a function fails, it will indicate failure in the return value and set an internal error indicator. A string representing the current internal error indicator can be retrieved through `bmi_last_error`.

The following functions can fail:

### `bmi_buffer_overdraw_buffer`

Success indicator `BMI_SUCCESS`  
Error indicator: `BMI_FAILURE`

### `bmi_buffer_get_pixel`

Success indicator: Anything not `BMI_PIXEL_INVALID`
Error indicator: `BMI_PIXEL_INVALID`

### `bmi_buffer_new`

Success indicator: Non-null pointer aligned to the guarantees of `malloc`.  
Error indicator: `BMI_PTR_FAILURE`

### `bmi_buffer_from_file`

Success indicator: Non-null pointer aligned to the guarantees of `malloc`.  
Error indicator: `BMI_PTR_FAILURE`

### `bmi_buffer_to_file`

Success indicator `BMI_SUCCESS`  
Error indicator: `BMI_FAILURE`

### `bmi_buffer_to_ppm`

Success indicator `BMI_SUCCESS`  
Error indicator: `BMI_FAILURE`

### `bmi_buffer_to_bmp`

Success indicator `BMI_SUCCESS`  
Error indicator: `BMI_FAILURE`

The following functions are unsafe to use in a multithreaded system without special caution:

### `bmi_version_string`

This function returns a read-only string valid until the function is called again (potentially with different arguments) again. To use this function safely, delay calling `bmi_version_string` until you have sufficiently processed this string, either by copying or other means.

### `bmi_last_error`

This function returns a read-only string valid until the BMI error indicator is set again. To use this function safely, delay calling any failable functions (listed above) until you have sufficiently processed this string, either by copying or other means.
