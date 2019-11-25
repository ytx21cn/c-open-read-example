#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SOURCE "test.txt"
#define START_BYTE 2
#define READ_BYTES 5
#define READ_RESULT "34567"

int main() {
	int new_fd = open(SOURCE, O_RDONLY);
	if (new_fd == -1) {
		exit(-1);
	}

	char buf[READ_BYTES * 2];
	memset(buf, 0, sizeof(buf));
	lseek(new_fd, START_BYTE, SEEK_SET);
	read(new_fd, buf, READ_BYTES);

	assert(strncmp(READ_RESULT, buf, READ_BYTES+1) == 0);
	printf("read: %s\n", buf); // shall be "34567"

	return 0;
}
