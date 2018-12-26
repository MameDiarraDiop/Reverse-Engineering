#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*extensionfic(char*nomficin){
    int i,j;
    i=0;
while(i<=strlen(nomficin)&&nomficin[i]!='.'){
        i=i+1;
    }
if(i>strlen(nomficin)){
        printf("Le fichier n'a pas d'extension");
    }
else{
char *extension=NULL;
extension=(char *)malloc(strlen(nomficin));
for(j=i+1;j<strlen(nomficin);j++){
    strncat(extension,&nomficin[j],1);
}
return extension;
}
}

void validitedunfichierxml(char*nomficin){
  //Création d'une variable contenant la commande de vérification de la validité du fichier xml
    char*test=NULL;
   //Initialisation de cette variable
    test=(char *)malloc((strlen("xml val --well-formed -e")+strlen(nomficin))+1);
    strcpy(test,"xml val --well-formed -e ");
    strcat(test,nomficin);
//Vérification syntaxique du document
system(test); printf("syntaxiquement\n");
//Test par rapport à une DTD interne
system(test);printf("valide par rapport a son DTD");
//Par rapport à une DTD externe
//system("xml val --dtd document.dtd -e document.xml");
}

void traitementtypeetextension(char*extension,char*type,char*nomficin){
if(strcmp(type,"xml")!=0 &&strcmp(type,"json")!=0){
    printf("Le type du fichier doit etre soit xml soit json\n");
}
else if(strcmp(extension,"xml")!=0 &&strcmp(extension,"json")!=0){
    printf("L'extension du fichier doit etre soit xml soit json\n");
}
else if(strcmp(extension,type)!=0){
    printf("Vous avez indique %s donc l'extension du fichier doit etre .%s\n",type,type);
}
else{
    validitedunfichierxml(nomficin);
}
}

 //Fonction de recupération du typ
char* recuperationtype(char*argv[],int argc){
  int i;
  char*type=NULL;
  i=1;
  while(i<argc && strcmp(argv[i],"-i")!=0){
       i=i+1;
        }
  if(strcmp(argv[i],"-i")==0){type=argv[i+1];}
  else{
            printf("Vous devez imperativement indiquer le type de votre document");
        }
  return type;
}

//Fonction de vérification du paramétre -t
int verificationdet(char*argv[],int argc){
int i;int trace;
 i=1;
    while(i<argc&&strcmp(argv[i],"-t")!=0){
         i=i+1;
        }
      if(strcmp(argv[i],"-t")==0){trace=1;}
        else{
            trace=0;
        }
        return trace;
}

  //Fonction de récupération de l'url si on importe les données avec un flux http
  char* recuperationurl(char*argv[],int argc){
    int i; char*urlhttp=NULL;
    i=1;
    while(i<argc&&strcmp(argv[i],"-h")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-h")==0){urlhttp=argv[i+1];}
    else{
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
        }
    return urlhttp;
  }

 //Fonction de récupération du nom du fichier texte d'entrée
 char* recuperationficin(char*argv[],int argc){
 char *nomficin=NULL; int i;
   i=1;
    while(i<argc&&strcmp(argv[i],"-f")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-f")==0){nomficin=argv[i+1];}
    else{
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
 }
 return nomficin;
 }

  //Fonction de récupération du nom du fichier de sortie
  char* recuperationficout(char*argv[],int argc){
   int i; char*nomficout=NULL;
   i=1;
   while(i<argc&&strcmp(argv[i],"-o")!=0){
            i=i+1;
        }
   if(strcmp(argv[i],"-o")==0){nomficout=argv[i+1];}
   else{
    printf("Vous devez imperativement donner le nom de votre fichier d'entree");
  }
  return nomficout;
  }

int main(int argc,char *argv[]){
    int i;char*type;int trace;char*urlhttp=NULL;char*nomficin=NULL;char*nomficout=NULL;

    type=recuperationtype(argv,argc);

    trace=verificationdet(argv,argc);

    urlhttp=recuperationurl(argv,argc);

    nomficin=recuperationficin(argv,argc);

    nomficout=recuperationficout(argv,argc);
    //Vérification et récupération des valeurs prises en entrée
    printf("%s\n",type);printf("%d\n",trace);printf("%s\n",urlhttp);printf("%s\n",nomficin);printf("%s\n",nomficout);
    //Extension du fichier d'entrée
    printf("%s\n",extensionfic(nomficin));
    //Verification et traitement de l'extension
    traitementtypeetextension(extensionfic(nomficin),type,nomficin);

    }
