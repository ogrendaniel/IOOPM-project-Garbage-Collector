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