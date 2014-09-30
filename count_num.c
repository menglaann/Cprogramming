#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define HASHNUMBER 60
typedef struct structCharHash{
	char *word;
	int number;
	struct structCharHash * next;
}charHash;
static charHash charHashTable[HASHNUMBER];
void insertWord(char * pword){
	printf("pword:%s\n",pword);
	char * lword=pword;
	int hashNum=calcWordHash(lword);
	charHash p=charHashTable[hashNum];

	if(p.word==NULL){
		charHash pc;
		pc.word=pword;
		//printf("pc.word:%s\n",pc.word);
		pc.number=1;
		pc.next=NULL;
		charHashTable[hashNum]=pc;
		//printf("this word  is %s ,and the number is %d\n",pc.word,pc.number);
		return ;
	}
	charHash *ppre=&charHashTable[hashNum];
	charHash *pcur=ppre;
	while(pcur!=NULL){
		if(strcmp(pcur->word,pword)==0){
			pcur->number+=1;
			//printf("this word  is %s ,and the number is %d\n",pcur->word,pcur->number);
			return;
		}
		//printf("this word  is %s ,and the number is %d\n",pcur->word,pcur->number);
		pcur=pcur->next;
		ppre=pcur;
	}
	charHash * pnewWord=(charHash *)malloc(sizeof(charHash));
	ppre->next=pnewWord;
}

int calcWordHash(char *pword){
	int ret = 0;
	while(*pword!='\0'){
		ret+=*pword;
		pword++;
	}
	printf("ret:%d\n",ret%HASHNUMBER);
	return ret%HASHNUMBER;
}

void initHashTable(){
	memset(charHashTable,0,sizeof(charHashTable));
}
int main(){
	initHashTable();
	printf("input the route and the name of file\n");
	char * file;
	file=(char*)malloc(10*sizeof(char));
	gets(file);
	printf("file name:%s\n",file);
	int num=count_num(file);
	printf("\n%d\n",num);
	int i=0;
	for (;i<HASHNUMBER;i++){
		charHash *pch = &charHashTable[i];			
		if (pch->word !=NULL){
			while(pch != NULL){
				printf("this word  is %s ,and the number is %d\n",pch->word,pch->number);
				pch= pch->next;
			}
		}

	    //printf("word is %s and number is %d \n",charHashTable[i].word,charHashTable[i].number);
	}
	free(file);
	file=NULL;
	return 0;
}
int count_num(char * filename){
	FILE *fp;
	char c;
	int num=0;//the num of ' '
	//printf("%s\n",file);
	//sprintf(file,file);
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("fail to open file");
		return -1;
	}
	
	/*while(!feof(fp)){
		if(feof(fp))break;
		c=fgetc(fp);
		if(c==' '){
			while(fgetc(fp)==' '){
				fgetc(fp);
			}
			num++;
		}
		//printf("%c",c);

	}*/
	char word[15];
	
	while(!feof(fp)){
		c=fgetc(fp);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z'){
			int i=0;
			for(;i<15;i++){
				word[i]='\0';
			}
			i=0;
			word[i]=c;
			i++;
			c=fgetc(fp);
			while(c>='a'&&c<='z'||c>='A'&&c<='Z'){
				word[i]=c;
				i++;
				c=fgetc(fp);
			}
			printf("%s\n",word);
			insertWord(word);
			num++;
		}
	}
	fclose(fp);
	//char mytext[20];
	//fgets(mytext,20,fp);
	//printf("%s\n",mytext);
	//fclose(fp);
	return num;

}