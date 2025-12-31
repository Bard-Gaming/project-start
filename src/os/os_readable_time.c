/*
** EPITECH PROJECT, 2025
** Module: OS
** File description:
** Implementation for
** os_readable_time
*/

#include <project_starter/os.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))


static const char *weekdays[7] = {
    "Sun", "Mon", "Tue",
    "Wed", "Thu", "Fri",
    "Sat"
};

static const char *months[12] = {
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec",
};

/**
 * Returns a string representing
 * the current OS time in a human-
 * readable format.
 *
 * The returned pointer must not
 * be free()d by the user, and
 * subsequent calls might modify
 * the string.
 *
 */
char *os_readable_time(void)
{
    static char readable_time[] = "Mon Jan 01 42:42:42 1337";
    time_t cur_time = time(NULL);
    struct tm *time_info = localtime(&cur_time);

    snprintf(
        readable_time,
        ARRAY_LEN(readable_time),
        "%s %s %0.2d %0.2d:%0.2d:%0.2d %4d",
        weekdays[time_info->tm_wday],
        months[time_info->tm_mon],
        time_info->tm_mday,
        time_info->tm_hour,
        time_info->tm_min,
        time_info->tm_sec,
        time_info->tm_year + 1900  // fix offset
    );

    return readable_time;
}
