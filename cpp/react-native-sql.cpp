#include "react-native-sql.h"
#include <sstream>

using namespace facebook;

void installSequel(jsi::Runtime &jsiRuntime, const char *string) {
	auto multiply = jsi::Function::createFromHostFunction(
			jsiRuntime, // JSI runtime instance
			jsi::PropNameID::forAscii(jsiRuntime, "multiply"), // Internal function name
			1, // Number of arguments in function
			// This is a C++ lambda function, the empty [] at the beginning is used to capture pointer/references so that they don't get de-allocated
			// Then you get another instance of the runtime to use inside the function, a "this" value from the javascript world, a pointer to the arguments (you can treat it as an array) and finally a count for the number of arguments
			// Finally the function needs to return a jsi::Value (read JavaScript value)
			[](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {

				// the jsi::Value has a lot of helper methods for you to manipulate the data
				if(!arguments[0].isNumber() || !arguments[1].isNumber()) {
					jsi::detail::throwJSError(runtime, "Non number arguments passed to sequel");
				}

				double res = arguments[0].asNumber() * arguments[1].asNumber();
				return jsi::Value(res);
			}
	);

	jsiRuntime.global().setProperty(jsiRuntime, "multiply", std::move(multiply));
}

void cleanUpSequel() {
	// intentionally left blank
}
