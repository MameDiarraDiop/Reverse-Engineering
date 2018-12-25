#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*extensionfic(char*nomficin){
    int i,j,k;
    k=0;i=0;
while(i<=strlen(nomficin)&&nomficin[i]!='.'){
        i=i+1;
    }
if(i>strlen(nomficin)){
        printf("Le fichier n'a pas d'extension");
    }
else{
char tab[100];
char *extension=NULL;
for(j=i+1;j<=strlen(nomficin);j++){
    tab[k]=nomficin[j];
    k=k+1;
}
extension=tab;
return extension;
}
}

void traitementtypeetextension(char*extension,char*type){
if(strcmp(type,"xml")!=0 &&strcmp(type,"json")!=0){
    printf("Le type du fichier doit etre soit xml soit json");
}
else if(strcmp(extension,"xml")!=0 &&strcmp(extension,"json")!=0){
    printf("L'extension du fichier doit etre soit xml soit json");
}
else{
    if(strcmp(extension,type)!=0){
    printf("Vous avez indiqué %s donc l'extension du fichier doit etre .%s",type,type);
}
}
}



int main(int argc,char *argv[]){
    int i;
    char*type=NULL;int trace;char*urlhttp=NULL;char*nomficin=NULL;char*nomficout=NULL;
    //Recupération du type
    i=1;
    while(i<argc && strcmp(argv[i],"-i")!=0){
       i=i+1;
        }
    if(strcmp(argv[i],"-i")==0){type=argv[i+1];}
        else{
            printf("Vous devez impérativement indiquer le type de votre document");
        }
    //Vérification du paramétre -t
    i=1;
    while(i<argc&&strcmp(argv[i],"-t")!=0){
         i=i+1;
        }
      if(strcmp(argv[i],"-t")==0){trace=1;}
        else{
            trace=0;
        }

    //Récupération de l'url
    i=1;
    while(i<argc&&strcmp(argv[i],"-h")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-h")==0){urlhttp=argv[i+1];}
    else{
    printf("Vous devez impérativement donner le nom de votre fichier d'entrée");
  }

    //Récupération du nom du fichier d'entrée
    i=1;
    while(i<argc&&strcmp(argv[i],"-f")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-f")==0){nomficin=argv[i+1];}
    else{
    printf("Vous devez impérativement donner le nom de votre fichier d'entrée");
  }
    //Récupération du nom du fichier de sortie
    i=1;
   while(i<argc&&strcmp(argv[i],"-o")!=0){
            i=i+1;
        }
   if(strcmp(argv[i],"-o")==0){nomficout=argv[i+1];}
   else{
    printf("Vous devez impérativement donner le nom de votre fichier d'entrée");
  }
  printf("%s\n",type);printf("%d\n",trace);printf("%s\n",urlhttp);printf("%s\n",nomficin);printf("%s\n",nomficout);
    printf("%s",extensionfic(nomficin));
    traitementtypeetextension(extensionfic(nomficin),type);
    char*test=nomficin
//Syntaxe document
system("xml val --well-formed -e %s",&nomficin);
printf("%s est valide syntaxiquement",nomficin);
//Test par rapport à une DTD interne
system("xml  val --embed -e %s",&nomficin);
printf("%s est valide par rapport à son DTD",nomficin);
//Par rapport à une DTD externe
//system("xml val --dtd document.dtd -e document.xml")
    }
