#ifndef CYMRITE_HEADER_MACROS
#define CYMRITE_HEADER_MACROS

#define CYMRITE_CAT(a, b) CYMRITE_CAT_PRIM(a, b)

#define CYMRITE_CAT_PRIM(a, b) a ## b

#define CYMRITE_STRINGIFY(x) #x

#define CYMRITE_ERROR(x) printf("\033[0m%s:%d: \033[0;31merror:\033[0m %s\n", __FILE__, __LINE__, x);

#define CYMRITE_WARN(x) printf("\033[0m%s:%d: \033[0;35mwarning:\033[0m %s\n", __FILE__, __LINE__, x);

#define CYMRITE_LOG(x) printf("\033[0m%s:%d: %s\n", __FILE__, __LINE__, x);

#define CYMRITE_ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define CYMRITE_UNUSED(x) (void)(x)

#endif // CYMRITE_HEADER_MACROS
