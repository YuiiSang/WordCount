#include <stdio.h>
#include <stdlib.h> 
//软件工程2022级 唐浩天 202231041024


int Count(FILE *f, char op) {
	int count = 0;
    char ch;
    if (op == 'c') {
        while ((ch = fgetc(f)) != EOF) {
            count++;
        }
    } else if (op == 'w') {
        int inWord = 0;
        while ((ch = fgetc(f)) != EOF) {
            if (ch == ' ' || ch == '\n' || ch == '\t') {
                inWord = 0;
            } else if (inWord == 0) {
                inWord = 1;
                count++;
            }
        }
    }else{
    	printf("没有指定参数操作!");
		exit(1); 
	} 
    return count;
}
int main(int argc, char *argv[]) {
	if(argc == 1){
		printf("没有输入指定参数![parameter] [input_file_name]\n");
	} else if(argc == 3){
		FILE *file = fopen(argv[2], "r");
		if(file == NULL){
			printf("指定文件为空!");
			return 1; 
		}else{
			char op = argv[1][1];
			int count = Count(file, op);
			if(op == 'c') printf("字符数:%d", count); 
			if(op == 'w') printf("单词数:%d", count); 
		} 
	} else{
		printf("输入的参数个数不对,请输入两个参数![parameter] [input_file_name]\n");
	}
    return 0;
}
