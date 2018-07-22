/**
 * Dual licensed under the MIT License and the Unlicense.
 * See LICENSE and UNLICENSE files included with this source file for the full
 * text of these licenses.
 *
 * Original Author: Michael P. Nitowski <mike@nitow.ski>
 */

#include <stdio.h>
#include <signal.h>
#include <time.h>

#include "elapsed.h"

#define NANOSECONDS_IN_SECOND 1000000000.0;
#define CLEAR_LINE "\r"

#define SLEEP_NANOSECONDS 24000000

void hide_cursor() {
    printf("\x1B[?25l");
}

void restore_cursor() {
    printf("\x1B[?25h");
}

volatile static int exit_requested = 0;

void request_exit() {
    exit_requested = 1;
}

int main(int argc, char* args[]) {
    struct timespec start, interval, sleep_interval;
    ELAPSED_TIMEPARTS et;
    char ets[ELAPSED_MAX_STR_SIZE];
    int seconds_interval;
    double fractional;

    if(clock_gettime(CLOCK_MONOTONIC, &start) < 0) {
        fprintf(stderr, "Failed to retrieve start time -- exiting.\n");
        return 1;
    }

    sleep_interval.tv_sec = 0;
    sleep_interval.tv_nsec = SLEEP_NANOSECONDS;

    signal(SIGINT, request_exit);
    signal(SIGTERM, request_exit);
    hide_cursor();

    while(!exit_requested) {
        clock_gettime(CLOCK_MONOTONIC, &interval);
        seconds_interval = interval.tv_sec - start.tv_sec;
        fractional = interval.tv_nsec / NANOSECONDS_IN_SECOND;

        et = ELAPSED_format_time(seconds_interval, fractional);
        ELAPSED_to_string(ets, et);
        printf("\r%s ", ets);
        fflush(stdout);
        nanosleep(&sleep_interval, NULL);
    }

    printf("\n");
    restore_cursor();
}
