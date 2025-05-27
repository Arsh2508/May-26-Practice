#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fd = fopen("compressed.txt", "r");
	if(!fd){
		printf("Failed to open the file!\n");
		return 1;
	}

	fseek(fd, 0, SEEK_END);
	size_t file_size = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	char* buf = malloc(file_size + 1);
	if(!buf){
		printf("Memory allocation failed!\n");
		return 1;
	}
	buf[file_size] = '\0';

	fread(buf, 1, file_size, fd);

	size_t src_size = 0;
	for(size_t i = 0; i < file_size; ++i){
		if(buf[i] >= '0' && buf[i] <= '9'){
			src_size += (buf[i] - '0');
		}
	}
	
	char * src = malloc(src_size + 1);
	if(!src){
		printf("Memeory allocation failed!\n");
		return 1;
	}

	int i = 0;
	int j = 0;
	while(buf[i + 1] != '\0'){
		int count = buf[i++] - '0';
		while(count > 0){
			src[j++] = buf[i];
			--count;
		}
		++i;
	}
	src[j] = '\0';
	
	printf("%s\n", src);
	fclose(fd);

	fd = fopen("decompressed.txt", "w");
	if(!fd){
		printf("Failed to open the file!\n");
		return 1;
	}

	fwrite(src, 1, src_size, fd);

	fclose(fd);

	free(src);
	free(buf);
	return 0;
}
