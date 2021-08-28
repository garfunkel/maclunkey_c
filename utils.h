#ifndef _UTILS_H_
#define _UTILS_H_

#define FALSE 0
#define TRUE 1
#define MAX_PARTICIPANTS 8
#define HEARTBEAT_INTERVAL 5

#define log_error_x(type, id, err) \
	fprintf(stderr, "%s: %s:%s:%d: %s: %s\n", type, __FILE__, __func__, __LINE__, error_to_string(id), err)

#define log_error_xf(type, id, fmt, ...)                                                                              \
	char *__log_string = NULL;                                                                                        \
	asprintf(&__log_string, fmt, __VA_ARGS__);                                                                        \
	fprintf(stderr, "%s: %s:%s:%d: %s: %s\n", type, __FILE__, __func__, __LINE__, error_to_string(id), __log_string); \
	free(__log_string);                                                                                               \
	__log_string = NULL

#define log_x(type, msg) fprintf(stderr, "%s: %s:%s:%d: %s\n", type, __FILE__, __func__, __LINE__, msg)

#define log_xf(type, fmt, ...)                                                               \
	char *__log_string = NULL;                                                               \
	asprintf(&__log_string, fmt, __VA_ARGS__);                                               \
	fprintf(stderr, "%s: %s:%s:%d: %s\n", type, __FILE__, __func__, __LINE__, __log_string); \
	free(__log_string);                                                                      \
	__log_string = NULL

#define log_fatal(id, err)         \
	log_error_x("FATAL", id, err); \
	exit(id)

#define log_fatalf(id, fmt, ...) log_error_xf("FATAL", id, fmt, __VA_ARGS__)

#define log_error(id, err) log_error_x("ERROR", id, err)
#define log_errorf(id, fmt, ...) log_error_xf("ERROR", id, fmt, __VA_ARGS__)

#ifdef DEBUG
	#define log_warning(msg) log_x("WARNING", msg)
	#define log_warningf(fmt, ...) log_xf("WARNING", fmt, __VA_ARGS__)
	#define log_info(msg) log_x("INFO", msg)
	#define log_infof(fmt, ...) log_xf("INFO", fmt, __VA_ARGS__)
#else
	#define log_warning(msg)
	#define log_warningf(fmt, ...)
	#define log_info(msg)
	#define log_infof(fmt, ...)
#endif

#endif
