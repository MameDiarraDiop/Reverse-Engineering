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
    printf("Vous avez indique %s donc l'extension du fichier doit etre .%s",type,type);
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
            printf("Vous devez imperativement indiquer le type de votre document");
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
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
  }

    //Récupération du nom du fichier d'entrée
    i=1;
    while(i<argc&&strcmp(argv[i],"-f")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-f")==0){nomficin=argv[i+1];}
    else{
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
  }
    //Récupération du nom du fichier de sortie
    i=1;
   while(i<argc&&strcmp(argv[i],"-o")!=0){
            i=i+1;
        }
   if(strcmp(argv[i],"-o")==0){nomficout=argv[i+1];}
   else{
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
  }
  //Vérification et récupération des valeurs pris en entrée
  printf("%s\n",type);printf("%d\n",trace);printf("%s\n",urlhttp);printf("%s\n",nomficin);printf("%s\n",nomficout);
   //Extension du fichier d'entrée
    printf("%s\n",extensionfic(nomficin));
    //Verification et traitement de l'extension
    traitementtypeetextension(extensionfic(nomficin),type);
    //Création d'une variable contenant la commande de vérification de la validité du fichier xml
    char*test=NULL;
   //Initialisation de cette variable
    test=(char *)malloc((strlen("xml val --well-formed -e")+strlen(nomficin))+1);
    strcpy(test,"xml val --well-formed -e ");
    strcat(test,nomficin);
//Vérification syntaxique du document
system(test); printf("syntaxiquement");
//Test par rapport à une DTD interne
system(test);printf("valide par rapport à son DTD");
//Par rapport à une DTD externe
//system("xml val --dtd document.dtd -e document.xml")
    }
