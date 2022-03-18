#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

using namespace facebook;


void installSequel(jsi::Runtime &jsiRuntime, const char *string);
void cleanUpSequel();
#endif /* EXAMPLE_H */

