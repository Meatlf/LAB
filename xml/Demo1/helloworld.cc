#include<mxml.h>
#include<stdio.h>
int main(){
	FILE* fp;
	mxml_node_t *tree,*node;
	
	fp = fopen("info.xml", "r");
	tree = mxmlLoadFile(NULL, fp,
			MXML_OPAQUE_CALLBACK);
	node = mxmlFindElement(tree, tree, "to", NULL, NULL,MXML_DESCEND);
       if(node == NULL)
       {
	       printf("Can not find element node!\n");
	       return -1;
       }	       
	fclose(fp);
	printf("%s\n","done");
	return 0;
}
