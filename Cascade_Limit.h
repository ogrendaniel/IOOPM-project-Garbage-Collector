#pragma once 
#include <stdio.h>

/**
 * @brief Set a upper limit on the number of objects that can be freed at once
 * @param limit The new limit
 */
void set_cascade_limit(size_t limit);

/**
 * @brief Get the cascade limit for the number of objects that can be freed at once
 * @return the current cascade limit
 */
size_t get_cascade_limit();