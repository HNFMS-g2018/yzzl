#include <stdio.h>
#include "file_processor.h"

extern int process_file(void *processor)
{
	struct file_processor *pthis = (struct file_processor*)processor;
	FILE *fp = fopen(pthis->file_name, pthis->open_mode);
	int ret;

	if (fp == NULL)
		return 1;

	ret = pthis->process(fp, pthis);

	fclose(fp);

	return ret;
}
