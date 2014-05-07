#define debug_print(...) \
            if (DEBUG) { \
				fprintf(stderr, "%s:%d:%s(): ", __FILE__, __LINE__, __func__); \
				fprintf(stderr, ##__VA_ARGS__); \
			}
