#include <stdio.h>
#include <stdlib.h> 

//�������2022�� �ƺ��� 202231041024

//���ڼ��� 
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
        	//�ַ���(����) 
            if (ch == ' ' || ch == '\n' || ch == '\t') {
                inWord = 0;
            } else if (inWord == 0) {
                inWord = 1;
                count++;
            }
        }
    }else{
    	printf("û��ָ����������!");
    	//ֱ���˳����� 
		exit(1); 
	} 
    return count;
}
int main(int argc, char *argv[]) {
	//ͨ�����������ж��û������Ƿ�淶 
	if(argc == 1){
		printf("û������ָ������![parameter] [input_file_name]\n");
	} else if(argc == 3){
		//ֻ��ģʽ���ļ� 
		FILE *file = fopen(argv[2], "r");
		//�ж��ļ��Ƿ���� 
		if(file == NULL){
			printf("ָ���ļ�Ϊ��!");
			return 1; 
		}else{
			//argv[1][1] ֻ���ַ����� ����'-' 
			char op = argv[1][1];
			int count = Count(file, op);
			if(op == 'c') printf("�ַ���:%d", count); 
			if(op == 'w') printf("������:%d", count); 
		} 
	} else{
		printf("����Ĳ�����������,��������������![parameter] [input_file_name]\n");
	}
    return 0;
}
