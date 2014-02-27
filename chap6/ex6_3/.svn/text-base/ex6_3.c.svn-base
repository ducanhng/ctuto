
/*Ex 6_3: Write a cross-referencer that prints a list of all words in a document, and, for each word, a list of the line numbers on which it occurs. Remove noise words like "the", "and," and so on.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFF 1000
#define MAXWORD 100
int getch(void);
void ungetch(int);
int getword(char *, int);

char buff[MAXBUFF];
int buffindex;/*defaul external variable is 0, next free index of buffer*/
char word[MAXWORD];
int maxlength = 6;
char *strdup1(char *);
struct tnode 
{
	char *s;// store string
	int count;
	struct nodeline *line;	
	struct tnode *leftnode;
	struct tnode *rightnode;
};

struct nodeline
{
	int numbline;
	struct nodeline *nextline;
};

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, char *, int);
struct nodeline *addnodeline(struct nodeline *, int);
void treeprint(struct tnode *);
void treeprintline(struct nodeline *);
char *noisewords[] = 
{
	"a",
	"an",
	"and",
	"or",
	"the"
};

#define NWORDS sizeof(noisewords)/sizeof(noisewords[0])
int isnoiseword(char *, int, int);

int main(int argc, char *argv[])
{
	int c;
	struct tnode *root;
	root = NULL;

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		// check is letter and length of string
		if (isalpha(word[0]))
			root = addtree(root,word,c);
	}
	
	// print tree
	printf("--------------------------------------------\n");
	treeprint(root);
}
/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct nodeline *nodelinealloc(void)
{
	return (struct nodeline *) malloc(sizeof(struct nodeline));
}

char *strdup1(char *word)
{
	char *p;
	// +1 for /0
	p = malloc(strlen(word) + 1);
	if (p == NULL)
	{
		printf("Memory not available\n");
		return NULL;
	}
	strcpy(p,word);
	return p;
}

struct tnode *addtree(struct tnode *parent, char *word, int nline )
{
	if (parent == NULL)
	{
		parent = talloc();
		parent->s = strdup1(word);
		parent->count++;
		parent->line = addnodeline(parent->line, nline);
		parent->leftnode = parent->rightnode = NULL;
	}
	else
	{
		if (strcmp(parent->s, word) > 0)
			parent->leftnode = addtree(parent->leftnode, word, nline);
		else if (strcmp(parent->s, word) < 0)
			parent->rightnode = addtree(parent->rightnode, word, nline);
		else if (strcmp(parent->s, word) == 0)
		{
			parent->count++;
			parent->line = addnodeline(parent->line, nline);
		}
	}
	return parent;
}

struct nodeline *addnodeline(struct nodeline *parent, int nline)
{
	if (parent == NULL)
	{
		parent = nodelinealloc();
		parent->numbline = nline;
		parent->nextline = NULL;
	}
	else
	{
		if (nline != parent->numbline)
			parent->nextline = addnodeline(parent->nextline,nline);
	}
	// If haven't return why program don't throw the error :(. Because function default returning is void :)
	return parent;
}

void treeprintline(struct nodeline *node)
{
	if (node != NULL)
	{
		printf("  %d,",node->numbline);
		treeprintline(node->nextline);
	}	
}


void treeprint(struct tnode *root)
{
	if (root != NULL)
	{
		treeprint(root->leftnode);
		if (!isnoiseword(root->s, 0, NWORDS - 1))
		{
			printf("%s(%d)\t",root->s, root->count);
			treeprintline(root->line);
			printf("\n");
		}
		treeprint(root->rightnode);
	}
}


// get word and return the line that word appears.
int getword(char *word, int lim)
{
	static int currentline = 1;
	int c;
	char *w = word;
	
	while ((c = getch()) == ' ')
		;

	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		if (c == '\n')
			currentline++;
		*w = '\0';
		return c;
	}
	for (;--lim>0;w++)
	{
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			if (*w == EOF)
				return *w;
			break;
		}
	}
		
	*w = '\0';
	return currentline;
}

// use binary search algorithm and recursion.
int isnoiseword(char *w, int left, int right)
{
	int pivot;
	int c;
	if (left > right)
		return 0;
	pivot = (left + right)/2;
	if ((c = strcmp(w, noisewords[pivot])) == 0)
		return 1;
	else
	{
		if (c > 0)
			isnoiseword(w, pivot+1, right);
		else if (c < 0) 
			isnoiseword(w, left, pivot-1);
	}
}


// getch and ungetch routine
int getch(void)
{
	return (buffindex > 0) ? buff[--buffindex] : getchar();
}

void ungetch(int c)
{
	if (buffindex >= MAXBUFF)
		printf("Buffer Error: Buffer is over !\n");
	else 
		buff[buffindex++] = c;
}
