/**
 * Dual licensed under the MIT License and the Unlicense.
 * See LICENSE and UNLICENSE files included with this source file for the full
 * text of these licenses.
 *
 * Original Author: Michael P. Nitowski <mike@nitow.ski>
 */

#include <stdio.h>
#include <math.h>

#include "elapsed.h"

ELAPSED_TIMEPARTS ELAPSED_format_time(int seconds, double fractional) {
    ELAPSED_TIMEPARTS t;

    t.h = seconds / 3600;
    t.m = (seconds % 3600) / 60;
    t.s = seconds % 60;

    if (fractional > 0) {
        t.f = (int)(fractional * 100);
    } else {
        t.f = 0;
    }

    return t;
}

ELAPSED_TIMEPARTS ELAPSED_format_time_d(double seconds) {
    double full_seconds = 0;
    double fractional = modf(seconds, &full_seconds);
    return ELAPSED_format_time((int) full_seconds, fractional);
}

uint32_t ELAPSED_encode_formatted_time(ELAPSED_TIMEPARTS t) {
    return ((t.h << 8 | t.m) << 8 | t.s) << 8 | t.f;
}

ELAPSED_TIMEPARTS ELAPSED_decode_formatted_time(uint32_t v) {
    ELAPSED_TIMEPARTS t;

    t.h = (v >> 24) & 255;
    t.m = (v >> 16) & 255;
    t.s = (v >> 8) & 255;
    t.f = v & 255;

    return t;
}

int ELAPSED_to_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t) {
    if (t.f <= 0) {
        return sprintf(buffer, "%02d:%02d", t.m, t.s);
    }

    return sprintf(buffer, "%02d:%02d.%02d", t.m, t.s, t.f);
}

int ELAPSED_to_hh_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t) {
    if (t.f <= 0) {
        return sprintf(buffer, "%02d:%02d:%02d", t.h, t.m, t.s);
    }

    return sprintf(buffer, "%02d:%02d:%02d.%02d", t.h, t.m, t.s, t.f);
}

int ELAPSED_to_string(char* buffer, ELAPSED_TIMEPARTS t) {
    if(t.h <= 0) {
        return ELAPSED_to_mm_ss_string(buffer, t);
    }

    return ELAPSED_to_hh_mm_ss_string(buffer, t);
}
