#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <libxml/parser.h>
#include <libxml/valid.h> 
#include <libxml/tree.h> 
enum {
 ERROR_OCCURED = -1, // Une erreur est survenue pendant la validation
 NOT_VALID = 0,      // Le document n'est pas valide
 VALID = 1           // Le document est valide
};

/*Cette fonction permet d'avoir tous les noeuds du fichier dans un tableau*/
int get_nodes(xmlNode *a_node,xmlNode*t[]) {
  xmlNode *cur_node = NULL; static int i=0;
  
  for(cur_node = a_node; cur_node; cur_node = cur_node->next) {
  if (cur_node->type == XML_ELEMENT_NODE) {
   //printf("Node name t[%d]= : %s\n",i, cur_node->name);
    t[i]=cur_node; i++;
		}
                
  get_nodes(cur_node->children,t);
	}
  return i;
}

/*Cette fonction permet d'avoir l'ensembles  des éléments et leurs fils s'ils en ont du fichier xml*/
void xml_Get_Node_Children(xmlNodePtr Node,xmlNode* noeud_enfants[][100],int j)
 {   int k=0;
      if(Node->type==XML_ELEMENT_NODE){ 
      int i=1;
      noeud_enfants[j][0]=Node;
      //printf("%s\n",noeud_enfants[j][0]->name);
      xmlNodePtr n;  
      n = Node->children;
      while(n){
           if(n->type==XML_ELEMENT_NODE){
           noeud_enfants[j][i]=(xmlNode*)n;
          //printf("\t%s\n",noeud_enfants[j][i]->name);
           n=n->next;
           i++;                         }
           else{
             n=n ->next;
               }  
              }
      noeud_enfants[j][i]=NULL;  }
     else{
      noeud_enfants[j][0]=NULL;
}     
      while(noeud_enfants[j][k]!=NULL){
         if(k==0)
         printf("%s\n",noeud_enfants[j][k]->name);
         else
         printf("\t%s\n",noeud_enfants[j][k]->name);
         k++;
                          }              
}

/*Cette fonction permet de faire l'extraction des entités et relations du fichier*/
void Extraction(xmlNode* t[],xmlNode*noeud_enfants[][100]){
 int i;
 for(i=0;t[i]!=NULL;i++){
 if(t[i]->type==XML_ELEMENT_NODE){
 xml_Get_Node_Children(t[i],noeud_enfants,i);
                                 }
                        }
}



/*Cette fonction sert à afficher un tableau t*/
void affichage(char t[]){
int i;
for(i=0;i<strlen(t);i++){
printf("%c",t[i]);
}
printf("\n");
}

int verification_trace(char*argv[],int argc){
 int i=0,nbre_t=0; int res;
while(i<=argc){
 if(argv[i]!=NULL){
  if(strcmp(argv[i],"-t")!=0){
   i++;                      }
  else{
    nbre_t++;
    i++;
      }                      
                  }
 else{
   break;}
              }
if(nbre_t>1){
    //printf("Erreur -t écrit %d fois\n",nbre_t);
    res=2;
}
else if(nbre_t==0){
   // printf("Pas de -t\n");
    res=0;
}
else if(nbre_t==1){
  //  printf("ya trace dh\n");
    res=1;    }
	return res;
}

/*Cette fonction permet la récupartion du nom du fichier de sortie donné par l'utilisateur*/
int recuperation_fic_output(char*argv[],int argc,char nomficout[]){
 int i=0,j,nbre_o=0; char* nom=NULL;int res;
while(i<=argc){
 if(argv[i]!=NULL){
  if(strcmp(argv[i],"-o")!=0){
   i++;                      }
  else{
    nom=argv[i+1];
    nbre_o++;
    i++;
      }                      
                  }
 else{
   break;}
              }
if(nbre_o>1){
    //printf("Vous avez écrit -o  %d fois.Indiquez un seul fichier.\n",nbre_o);
    res= 2;
}
else if(nbre_o==0){
    //printf("Pas de -o\n");
    res= 0;
}
else if(nbre_o==1){
    if(nom!=NULL){
   // printf("ya fichier sortie dh\n");
    for(j=0;j<strlen(nom);j++){
      nomficout[j]=nom[j];
                              }
    nomficout[j]='\0';  
    res= 1;    }
    else{
    //printf("Donner le nom du fichier de sortie\n");
     res= -1;}
}
return res;
}
/*Cette fonction permet de récupérer le type du fichier fourni en entrée*/
int recuperation_type(char*argv[],int argc,char argu[]){
int i=0,j,nbre_i=0; char *type=NULL;int res;
while(i<=argc){
 if(argv[i]!=NULL){
  if(strcmp(argv[i],"-i")!=0){
   i++;                      }
  else{
    type=argv[i+1];
    nbre_i++;
    i++;
      }                      
                  }
 else{
   break;
     }
               }
if(nbre_i>1){
  //  printf("indiquez un seul type\n");
    res= 2;
}
else if(nbre_i==0){
    //printf("Pas de -i\n");
    res= 0;
}
else if(nbre_i==1){
    if(type!=NULL){
   // printf("ya type dh\n");
    for(j=0;j<strlen(type);j++){
      argu[j]=type[j];
                               }
    argu[j]='\0';
    res= 1;
                  } 
    else{
     // printf("Donnez le type\n");
      res=1;}
}
return res;
}
/*Cette fonction sert à récupérer le nom du fichier d'entrée donné par l'utilisateur*/
int recuperation_fic_input(char*argv[],int argc,char nomficin[]){
 int i=0,j,nbre_f=0; char* nom=NULL; int res;
while(i<=argc){
 if(argv[i]!=NULL){
  if(strcmp(argv[i],"-f")!=0){
   i++;                      }
  else{
    nom=argv[i+1];
    nbre_f++;
    i++;
      }                      
                  }
 else{
   break;}
              }
if(nbre_f>1){
  //  printf("indiquez un seul fichier\n");
    res= 2;
}
else if(nbre_f==0){
 //   printf("Pas de -f\n");
    res= 0;
}
else if(nbre_f==1){
    if(nom!=NULL){
   // printf("ya fichier dh\n");
    for(j=0;j<strlen(nom);j++){
      nomficin[j]=nom[j];
                              }
    nomficin[j]='\0'; 
    printf("%s",nomficin); 
    res= 1;    }
    else{
//     printf("Donner le nom du fichier\n");
     res= -1;}
}
return res;
}
/*Cette fonction permet de récuperer l'extension d'un fichier*/
int extension_fic(char nomficin[],char extension[]){
 int i,j,k;i=0;
 while(nomficin[i]!='\0'&&nomficin[i]!='.')
  i=i+1;
 if(nomficin[i]=='\0'){
//        printf("Le fichier n'a pas d'extension\n");
        return 0;}
 else{
  k=0;
  for(j=i+1;nomficin[j]!='\0';j++){
   extension[k]=nomficin[j];
   k++;
                                   }
 extension[k] = '\0';
// printf("Le fichier aun extension\n");
 return 1;
    }
}
/*Cette fonction sert à comparer deux tableaux a et b*/
int comparaison(char a[],char b[]){
 int i,res;
 for(i=0;a[i]!='\0'&&b[i]!='\0';i++){
   if(a[i]==b[i])
     res=1;  
   else
     res=0;                               
}
 return res; 
}
/*Cette fonction sert à vérifier si l'extension du fichier vaut xml*/
int traitement_extension_ficin(char extension_ficin[]){
 if(comparaison(extension_ficin,"xml")==1){
  //  printf("L'extension du fichier est bien xml\n");
    return 1;                       }
 else{
    //printf("L'extension du fichier doit etre xml");
    return 0;
     }
}

/*Cette fonction sert à vérifier si l'extension du fichier vaut xml*/
int traitement_extension_ficout(char extension_ficout[]){
 if(comparaison(extension_ficout,"svg")==1){
    //printf("L'extension du fichier est bien svg\n");
    return 1;                       }
 else{
    //printf("L'extension du fichier doit etre svg");
    return 0;
     }
}
                                                                     
/*Cette fonction sert à vérifier si le type du fichier donné est bien xml*/
int traitement_type_ficin(char type[]){
 if(comparaison(type,"xml")==0){
    //printf("Le type du fichier doit etre xml \n");
    return 0 ;
                               }
 else{
    //printf("Le type du fichier est bien xml \n");
    return 1;
     }
                                 }
/*Cette fonction permet la récupération de l'url du fichier si le mode d'importation est par flux http*/
int recuperation_url(char*argv[],int argc,char urlhttp[]){
 int i=0,j,nbre_h=0; char* url=NULL;int res;
while(i<=argc){
 if(argv[i]!=NULL){
  if(strcmp(argv[i],"-h")!=0){
   i++;                      }
  else{
    url=argv[i+1];
    nbre_h++;
    i++;
      }                      
                  }
 else{
   break;}
              }
if(nbre_h>1){
//    printf("indiquez un seul fichier\n");
    res= 2;
}
else if(nbre_h==0){
  //  printf("Pas de -h\n");
    res= 0;
}
else if(nbre_h==1){
    if(url!=NULL){
//    printf("ya fichier dh\n");
    for(j=0;j<strlen(url);j++){
      urlhttp[j]=url[j];
                              }
    urlhttp[j]='\0';  
    return 1;    }
    else{
    // printf("Donner l'url\n");
     res= -1;}
}
return res;
}

/*Combine l'ensemble des fonctions définies pour tester la validité de la commande*/
int test_des_args(int recup_type,int recup_ext_ficin,int recup_ext_ficout,int test_ext_ficin,int test_ext_ficout,int test_type,int local,int t,int flux,int sortie)
  {
 if(recup_type==1){
   if(test_type==1){
     if(local==1){
       if(flux==1){
        // printf("Un seul mode d'importation des donnees est permi\n");
         return 0;
	                } 
       else{
		if(flux==2) {
			//printf("Vous avez spécifié deux urls.\n"); 
		    return 13;}
		else if(flux==-1) {
			//printf("Vous devez donner apres le -h l'urls.\n"); 
			return 14;}
        else if(recup_ext_ficin==1){
         if(test_ext_ficin==1){
          if(sortie==1){
           if(recup_ext_ficout==1){
            if(test_ext_ficout==1){
             if(t==1){
          //    printf("Informations récupérées avec demande de trace\n");
              return 1;
			 }  
             else{
            //  printf("Informations récupérées sans demande de trace\n");
              return 2;
			 }            
			}                  
            else{
              //printf("L'extension du fichier doit etre svg\n");
              return 3;
			}
		   }
           else{
			   
           // printf("Le fichier de sortie n'a pas d'extension\n");
            return 4;
		   }
               
		  }                
          else{
           if(sortie==2){
           // printf("Vous avez spécifié plusieurs fichiers de sortie\n");
            return 5;   
		   }
           else{
          //  printf("Vous n'avez pas spécifié votre fichier de sortie\n");
            return 6;
		   }
		  } 
		 }
         else{
        //  printf("L'extension du fichier doivent etre xml\n");
          return 7;
		 }
		}
	   
        else{
       //  printf("Le fichier d'entree n'a pas d'extension\n"); 
		 return 8;}
            }  }
      else{
       if(flux==1){
       // printf("Les donnees sont importees par flux http\n");
	   return 9;}
        else{
       // printf("Les donnees ne sont pas spécifiees\n");
        return 10;
	   }
	    }
   }  
      else{
      // printf("Le type  doit etre xml\n");
	   return 11;}
	   
	   
      }
	 else{
     // printf("Il n'y aucun type indiqué\n");
	  return 12;}        
  }



/**
 * Fonction de validation d'un arbre DOM à l'aide d'une DTD
 **/
int validation_dtd(xmlDocPtr doc, xmlDtd* dtd, int afficher_erreurs) {
    int ret;
    xmlValidCtxtPtr vctxt;

    // Traitement de la DTD
    if (dtd == NULL) {
        return ERROR_OCCURED;
    }
    // Création du contexte de validation
    if ((vctxt = xmlNewValidCtxt()) == NULL) {
        xmlFreeDtd(dtd);
        return ERROR_OCCURED;
    }
    // Affichage des erreurs de validation
    if (afficher_erreurs) {
        vctxt->userData = (void *) stderr;
        vctxt->error = (xmlValidityErrorFunc) fprintf;
        vctxt->warning = (xmlValidityWarningFunc) fprintf;
    }
    // Validation
    ret = xmlValidateDtd(vctxt, doc, dtd);
    // Libération de la mémoire
    xmlFreeValidCtxt(vctxt);
    xmlFreeDtd(dtd);                           
    return ret;
}




int main(int argc,char*argv[]){
char type[50];
char nomficin[50];
char nomficout[50];
char extension_ficin[50];
char extension_ficout[50];
char urlhttp[50];
int recup_local,recup_flux,recup_sortie,recup_type,recup_t,recup_extension_in,recup_extension_out,test_ext_ficin,test_ext_ficout,test_type;
int args;
if(argc<=10){
recup_sortie=recuperation_fic_output(argv,argc,nomficout);
recup_type=recuperation_type(argv,argc,type);
recup_local=recuperation_fic_input(argv,argc,nomficin);
recup_extension_in=extension_fic(nomficin,extension_ficin);
recup_extension_out=extension_fic(nomficout,extension_ficout);
recup_flux=recuperation_url(argv,argc,urlhttp);
test_ext_ficin=traitement_extension_ficin(extension_ficin);
test_ext_ficout=traitement_extension_ficout(extension_ficout);
test_type=traitement_type_ficin(type);
recup_t=verification_trace(argv,argc);
args=test_des_args(recup_type,recup_extension_in,recup_extension_out,test_ext_ficin,test_ext_ficout,test_type,recup_local,recup_t,recup_flux,recup_sortie);
switch (args)
{
case 0: printf("Un seul mode d'importation des donnees est permi.\n"); break;
case 13: printf("Vous avez tenté de spécifie deux url http\n");break;
case 14: printf("Veuillez indiquez l'url http aprés le -h.\n"); break;
case 3:printf("L'extension du fichier doit etre svg\n"); break;
case  4:printf("Le fichier de sortie n'a pas d'extension\n");break;
case 5:printf("Vous avez spécifié plusieurs fichiers de sortie\n"); break;
case 6:printf("Vous n'avez pas spécifié votre fichier de sortie\n");break;
case 7:printf("L'extension du fichier doivent etre xml\n");break;
case 8:printf("Le fichier d'entree n'a pas d'extension\n"); break;
case 9:  printf("Les donnees sont importees par flux http\n");break;
case 10: printf("Les donnees ne sont pas spécifiees\n");break;
case 11:printf("Le type  doit etre xml\n");break;
case 12:printf("Il n'y aucun type indiqué\n");break;
case 1  : {
           int affic_erreurs=0;
           printf("Informations récupérées avec demande de trace\n");
           /*Parsing DTD*/
           xmlDtd* dtd=NULL;
           dtd=xmlParseDTD(NULL,(const xmlChar*)"doc1.dtd");
           /*Parsing Doc*/
           xmlDoc* doc=NULL;
           doc = xmlReadFile(nomficin, NULL, 0);
           if (doc == NULL){
            printf("Parse erreur ! ");
            return 1;
                            }
           /*Avoir l'élément racine*/
           xmlNode* root=NULL;
           root=xmlDocGetRootElement(doc);
           /*Test de validation*/
           int i=validation_dtd(doc,dtd,affic_erreurs);
           printf("%d",i);
           xmlNode* t[100];
           /*Test de get_nodes*/
           get_nodes(root,t);
           /*Test de Extraction*/
           xmlNode* enfants[100][100];
           Extraction(t,enfants);
           break;
           
          }
case 2: printf("Informations récupérées sans demande de trace\n");break;
}}
else {
 printf("Vous avez donné des informations inutiles\n");
}
return 0;
}
