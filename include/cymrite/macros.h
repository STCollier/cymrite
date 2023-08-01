#ifndef CYMRITE_HEADER_MACROS
#	define CYMRITE_HEADER_MACROS

#	define CYMRITE_CAT(a, b) CYMRITE_CAT_PRIM(a, b)

#	define CYMRITE_CAT_PRIM(a, b) a ## b

#	define CYMRITE_STRINGIFY(x) CYMRITE_STRINGIFY_PRIM(x)

#	define CYMRITE_STRINGIFY_PRIM(x) #x

#	define CYMRITE_ERROR(x) printf("\x1B[0m%s:%d: \x1B[0;31mERROR:\x1B[0m %s\n", __FILE__, __LINE__, x);

#	define CYMRITE_WARN(x) printf("\x1B[0m%s:%d: \x1B[0;35mWARNING:\x1B[0m %s\n", __FILE__, __LINE__, x);

#	define CYMRITE_LOG(x) printf("\x1B[0m%s:%d: %s\n", __FILE__, __LINE__, x);

#	define CYMRITE_ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

#	define CYMRITE_UNUSED(x) (void)(x)

#endif
