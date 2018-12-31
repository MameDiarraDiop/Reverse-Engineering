#include<stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpathInternals.h>
// cette fonction (récursive) affiche le nom de tous les éléments du document XML
static void print_element_names(xmlNode *a_node)
{
    xmlNode *cur_node = NULL;
    xmlNode *cur_nodep = NULL;
    for(cur_node = a_node; cur_node; cur_node = cur_node->next) 
    {
        if (cur_node->type == XML_ELEMENT_NODE) 
       {
           
            if(cur_nodep->name!=cur_node->name)
            printf("node type: Element, name: %s\n", cur_node->name);
 cur_nodep=cur_node->next;
        }        
print_element_names(cur_node->children);
    }

}
 

int main() {
       xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
 
    doc = xmlReadFile("test.xml", NULL, 0);
    if (doc == NULL)     { printf("Parse erreur ! ");
return 1;
}
    /* Get the root element node */
root_element = xmlDocGetRootElement(doc);
print_element_names(root_element);


    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}
