/** @file
    Internationalization support for rtl_433.

    Copyright (C) 2025 rtl_433 contributors

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef INCLUDE_I18N_H_
#define INCLUDE_I18N_H_

// Build-time language selection via CMake
#ifndef RTL_433_LANG
#define RTL_433_LANG "en"
#endif

// Language macros - check if Turkish is enabled
#if defined(RTL_433_LANG_TR)
#define I18N_TR(str, tr_str) tr_str
#else
#define I18N_TR(str, tr_str) str
#endif

// Main translation macro - use as: I18N("English text", "Turkish text")
#define I18N(str, tr_str) I18N_TR(str, tr_str)

// For marking strings (no translation needed)
#define N_(str) (str)

#endif // INCLUDE_I18N_H_
