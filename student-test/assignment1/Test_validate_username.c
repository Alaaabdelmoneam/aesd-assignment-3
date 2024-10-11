#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
 * This function should:
 *   1) Call the my_username() function in autotest-validate.c to get your hard-coded username.
 *   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
 *       the assignment autotest submodule at assignment-autotest/test/assignment1/
 *   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  
 *      See the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
 */
void test_validate_my_username()
{
    // Call the function to get the hard-coded username
    const char* str1 = my_username();
    
    // Obtain the username from the config file
    char* str2 = malloc_username_from_conf_file();

    // Check for NULL from malloc_username_from_conf_file
    TEST_ASSERT_NOT_NULL_MESSAGE(str2, "Failed to read username from config file!");

    // Verify that the two usernames are equal
    TEST_ASSERT_EQUAL_STRING_MESSAGE(str1, str2, "Strings don't match!");

    // Free allocated memory if necessary
   // free(str2);
}
