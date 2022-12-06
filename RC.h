#pragma once
#include <stdio.h>


/**
* @brief instead of writing void we give it a better name (obj)
*/
typedef void obj;

/**
 * @brief function1_t can be used as all functions which takes an obj * as argument and returns void
 */
typedef void(*function1_t)(obj *);

/** 
 *  @brief increments a objects reference count by 1
 *  @param object The object to which the reference count should be incremented
*/
void retain(obj * object);

/** 
 *  @brief decrements a objects reference count by 1, if the reference count reaches 0 the object is freed
 *  @param object The object to which the reference count should be decremented
*/
void release(obj * object);

/** 
 *  @brief gives the reference count of a object
 *  @param object The object to which the reference count should be returned
 *  @return The reference count of the object
*/
size_t rc(obj *);


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


/**
 * @brief frees all objects with a reference count of 0 despite the cascade limit
 */
void cleanup();

/**
 * @brief frees all memory allocated by the program
 */
void shutdown();

/**
 * @brief frees all the memory the given object has allocated
 * @param object the object to be freed
 */
void default_destructor(obj * object);

/**
 * @brief scans the object for pointers to other objects and calls release on all pointers found
 * @param object the object to be scanned
 */
void scan_objects_for_pointers(obj * object);