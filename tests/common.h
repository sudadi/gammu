#ifndef _test_common_h_
#define _test_common_h_

#include <stdlib.h>

/**
 * Common functions for test.
 */

#define test_result(val) \
{ \
	if (!(val)) {\
        fprintf(stderr, "Test \"%s\" failed!\n", ""#val); \
        exit(2); \
    } \
}

#define test_string(expected, actual) \
{ \
    if (strcmp(expected, actual) != 0) { \
        fprintf(stderr, "Test \"%s\" == \"%s\" failed!\n", ""#expected, ""#actual); \
        for (size_t i = 0; i <= strlen(expected); i++) { \
            fprintf(stderr, "\\x%02X, \\x%02X\n", (unsigned char)expected[i], actual[i]); \
        } \
        exit(2); \
    } \
}

#define gammu_test_result(error, text) \
{ \
	if (error != ERR_NONE) {\
		fprintf(stderr, "%s\n", GSM_ErrorString(error)); \
        fprintf(stderr, "Test \"%s\" failed!\n", text); \
        exit(2); \
    } \
}

#define gammu_test_result_code(error, text, expect) \
{ \
	if (error != expect) {\
		fprintf(stderr, "%s\n", GSM_ErrorString(error)); \
        fprintf(stderr, "Test \"%s\" failed!\n", text); \
        exit(2); \
    } \
}

#endif
