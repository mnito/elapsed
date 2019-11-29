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
    uint8_t h;
    uint8_t m;
    uint8_t s;
    uint8_t f;
} ELAPSED_TIMEPARTS;

ELAPSED_TIMEPARTS ELAPSED_format_time(int seconds, double fractional);
ELAPSED_TIMEPARTS ELAPSED_format_time_d(double seconds);
uint32_t ELAPSED_encode_formatted_time(ELAPSED_TIMEPARTS t);
ELAPSED_TIMEPARTS ELAPSED_decode_formatted_time(uint32_t v);
int ELAPSED_to_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t);
int ELAPSED_to_hh_mm_ss_string(char* buffer, ELAPSED_TIMEPARTS t);
int ELAPSED_to_string(char* buffer, ELAPSED_TIMEPARTS t);
