#include<stdio.h>
#include<malloc.h>
int main(){
	printf("input the route and the name of file\n");
	char * file;
	file=(char*)malloc(10*sizeof(char));
	gets(file);
	printf("file name:%s\n",file);
	int num=count(file);
	printf("\n%d",num);
	return 0;
}
int count(char * file){
	FILE *fp;
	char c;
	int num=0;//the num of ' '
	//printf("%s\n",file);
	//sprintf(file,file);
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("fail to open file");
		return -1;
	}
	
	while(!feof(fp)){
		if(feof(fp))break;
		c=fgetc(fp);
		if(c==' '){
			while(fgetc(fp)==' '){
				fgetc(fp);
			}
			num++;
		}
		//printf("%c",c);

	}
	fclose(fp);
	//char mytext[20];
	//fgets(mytext,20,fp);
	//printf("%s\n",mytext);
	//fclose(fp);
	return num+1;
}