#include<stdio.h>
#include<string.h>
//Fonction de comparaison du type aprés -i et de l'extension du fichier
int compextettype(char *input,char *type){
int i,j,k;
k=0; i=0;
//Recherche du '.' dans le nom du fichier
while(i<=strlen(input)&&input[i]!='.'){
        i=i+1;
    }

//Si le point n'est pas trouvé on retourne 2
    if(i>strlen(input)){
        return 2;
    }
//sinon on crée un tableau extension contenant l'extension du fichier
    else{
char extension[strlen(input)-i];
//Initialisation du tableau extension
for(j=i+1;j<=strlen(input);j++){
    extension[k]=input[j];
    k=k+1;
}
//On compare ensuite l'extension et le type fourni en argument
if(strcmp(extension,type)==0){
//On retourne 1 si le type fourni en argument correspond à l'extension du fichier
    return 1;
}
else{
//On retourne 0 si le type fourni en argument ne correspond pas à l'extension du fichier
    return 0;
}
}
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
    printf("%d",recuperationextension(argv[7],argv[2]));
}
