#pragma once
#include <stdio.h>
#include "Reference_Counting.h"

/**
 * @brief allocates memory for an object and sets the reference count to 0
 * @param bytes the number of bytes to allocate
 * @param destructor the function to call when the object should be freed
 * @return a pointer to the allocated memory
 */
obj *allocate(size_t bytes, function1_t destructor);

/**
 * @brief allocates memory for an array of objects and sets the reference count to 0
 * @param elements the number of elements to allocate
 * @param elem_size tjhe size of each element
 * @param destructor the function to call when the object should be freed
 * @return a pointer to the allocated memory for the array
 */
obj *allocate_array(size_t elements, size_t elem_size, function1_t destructor);

/**
 * @brief deallocates the memory of an object
 * @param object The object to be deallocated
 */
void deallocate(obj * object);