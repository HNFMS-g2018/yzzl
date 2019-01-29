#ifndef FILE_PROCESSOR_H_
#define FILE_PROCESSOR_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>

	struct file_processor {
		const char *file_name, *open_mode;
		int (*process)(FILE* fp, struct file_processor *pthis);
	};

	/*
	   W A R N I N G
	   processor的第一个元素必须为file_processor.
	   这里本该是``int process_file(file_processor *pthis)''
	   写成void可以在调用时更加方便.
	 */
	int process_file(void *processor);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* FILE_PROCESSOR_H_ */
