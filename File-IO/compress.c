#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fd = fopen("decompressed.txt", "r");
	if(!fd){
		printf("Fail to open the file:\n");
		return 1;
	}

	fseek(fd, 0, SEEK_END);
	size_t file_size = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	char * buf = malloc(file_size + 1);
	if(!buf){
		printf("Memory allocation failed!\n");
		return 1;
	}

	buf[file_size] = '\0';

	fread(buf, 1, file_size, fd);
	printf("%s", buf);

	fclose(fd);

	char * src = malloc(file_size + 1);
	if(!src){
		printf("Memory allocation failed!\n");
		return 1;
	}
	src[file_size] = '\0';

	int i = 0;
	int j = 0;
	int count = 0;

	while(buf[i]){
		++count;
		if(buf[i + 1] && buf[i] != buf[i + 1]){
			src[j++] = count + '0';
			src[j++] = buf[i];
			count = 0;
		}
		++i;
	}
	src[j] = '\0';
	printf("%s\n", src);
	
	fd = fopen("compressed.txt","w");

	fwrite(src, 1, strlen(src), fd);

	fclose(fd);

	free(src);
	free(buf);
	return 0;
}

















