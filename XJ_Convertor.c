#include<stdio.h>
#include<string.h>
void recuperationextension(char *x){
int i,j,k;
k=0; i=0;
while(i<strlen(x)&&x[i]!='.'){
        i=i+1;
    }
char extension[strlen(x)-i];
for(j=i+1;j<=strlen(x);j++){
    extension[k]=x[j];
    k=k+1;
}
printf("l'extension est %s",extension);
}
int main(int argc,char *argv[]){
    if(argc==10){
 if(strcmp(argv[1],"-i")==0&&strcmp(argv[3],"-t")==0&&strcmp(argv[4],"-h")==0&&strcmp(argv[6],"-f")==0&&strcmp(argv[8],"-o")==0){
  if(strcmp(argv[2],"xml")==0||strcmp(argv[2],"json")==0){
    printf("le type est ok et est %s\n",argv[2]);
 }
 else{
    printf("le type n'est pas connu\n");
 }


}
    }
    recuperationextension(argv[7]);
}
