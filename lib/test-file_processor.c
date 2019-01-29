#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "file_processor.h"

struct write_data_to_file {
	struct file_processor base;
	const char *msg;
};

int write_data(FILE *fp, struct file_processor *pthis)
{
	fputs(((struct write_data_to_file*)pthis)->msg, fp);
	return 0;
}

#define new_write_data_to_file(file, msg) {\
	{ \
		file, "w", \
		write_data \
	}, \
	msg \
}

int main(void)
{
	FILE *tmp;
	const char *msg = "hello, world";
	const char *tmpfile = "/tmp/tmp-file-luotianyi-is-the-best.txt";
	char rbuf[256];

	/*
	   用模板方式来写入文件
	 */
	struct write_data_to_file wd = new_write_data_to_file(tmpfile, msg);

	if (process_file(&wd)) {
		fprintf(stderr, "%s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	/*
	   然后再用传统方式来看一看效果.
	 */
	tmp = fopen(tmpfile, "r");
	if (tmp == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
	} else {
		rbuf[0] = '\0';
		if (fgets(rbuf, sizeof(rbuf), tmp) == NULL)
			fprintf(stderr, "%s\n", strerror(errno));
		else
			assert(strcmp(rbuf, msg) == 0);
		fclose(tmp);
	}
	printf("write:%s\nread :%s\n", msg, rbuf);
	remove(tmpfile);
	return 0;
}
