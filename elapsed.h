/**
 * Dual licensed under the MIT License and the Unlicense.
 * See LICENSE and UNLICENSE files included with this source file for the full
 * text of these licenses.
 *
 * Original Author: Michael P. Nitowski <mike@nitow.ski>
 */

#include <stdint.h>

#define ELAPSED_MAX_STR_LEN 12
#define ELAPSED_MAX_STR_SIZE ELAPSED_MAX_STR_LEN + 1

typedef struct ELAPSED_TIMEPARTS {
    u_int8_t h;
    u_int8_t m;
    u_int8_t s;
    u_int8_t f;
} ELAPSED_TIMEPARTS;

ELAPSED_TIMEPARTS ELAPSED_format_time(int seconds, double fractional);
ELAPSED_TIMEPARTS ELAPSED_format_time_d(double seconds);
u_int32_t ELAPSED_encode_formatted_time(ELAPSED_TIMEPARTS t);
ELAPSED_TIMEPARTS ELAPSED_decode_formatted_time(u_int32_t v);
int ELAPSED_to_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t);
int ELAPSED_to_hh_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t);
int ELAPSED_to_string(char* buffer, ELAPSED_TIMEPARTS t);
