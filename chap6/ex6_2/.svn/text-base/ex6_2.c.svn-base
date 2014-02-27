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
	struct tnode *leftnode;
	struct tnode *rightnode;
};
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void treeprintbygroup(struct tnode *, int);
int mystrncmp(char *, char *, int);
int main(int argc, char *argv[])
{
	int c;
	struct tnode *root;
	root = NULL;
	if (argc > 3)
	{
		printf("Invalid option \n");
		printf("Usage pattern: getvar -n [number]\n");
		return;
	}
		
	while (argc-- > 0 && (*++argv)[0] == '-')
	{
		if (*++argv[0] != 'n')
	{
			printf("Invalid option \n");
			printf("Usage pattern: getvar -n [number]\n");
			return;
		}

		// set max length here
		// check argv is number
		if (isdigit((*++argv)[0]))
		{
			// Shouldn't use atoi() function because it haven't error checking
			// convert to number
			maxlength = atoi(argv[0]);
			break;
		}
	}

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		// check is letter and length of string
		if (isalpha(word[0]))
			root = addtree(root,word);
	}
	
	// print tree
	printf("Inputed %d first characters of string. The input tree:\n", maxlength);
	treeprint(root);
	printf("Group By Variable name\n");
	treeprintbygroup(root, maxlength);
}
/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
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

struct tnode *addtree(struct tnode *parent, char *word )
{
	if (parent == NULL)
	{
		parent = talloc();
		parent->s = strdup1(word);
		parent->count++;
		parent->leftnode = parent->rightnode = NULL;
	}
	else
	{
		if (strcmp(parent->s, word) > 0)
			parent->leftnode = addtree(parent->leftnode, word);
		else if (strcmp(parent->s, word) < 0)
			parent->rightnode = addtree(parent->rightnode, word);
		else if (strcmp(parent->s, word) == 0)
			parent->count++;
	}
	return parent;
}

void treeprint(struct tnode *root)
{
	if (root != NULL)
	{
		treeprint(root->leftnode);
		printf("%s(%d)\n",root->s, root->count);
		treeprint(root->rightnode);
	}
}

// refer solution from clc-wiki.net
void treeprintbygroup(struct tnode *p, int n)
{
	// Declare a previous node and flag to mark printed or not
        static struct tnode *previousnode;
	static int flagprintedprevious = 1;
	
	if (p != NULL)
	{
		treeprintbygroup(p->leftnode,n);
		if (previousnode != NULL)
		{
			//Compare previous node with current node
			if (mystrncmp(previousnode->s,p->s,n))
			{
				if (flagprintedprevious)
				{
					printf("%s(%d)\n",previousnode->s, previousnode->count);
					flagprintedprevious = 0;
				}
				printf("\t%s(%d)\n",p->s, p->count);
			}
			else
				flagprintedprevious = 1;
		}
		previousnode = p;
		treeprintbygroup(p->rightnode,n);
	}
}

// Compare two node in the first n characters. 
int mystrncmp(char *s1, char *s2, int n)
{
	int i;
	if (n == 0)
		return 0;
	for (i=0;*s1 == *s2 && *s1 != '\0' && i < n;i++,*s1++,*s2++)
		;
	if (i == n)
		return 1;
	return 0;
}

int getword(char *word, int lim)
{
	int c;
	char *w = word;
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		// if found comment notation, by pass it.
		// There are two cases: // or /* ... */
		if (c == '/')
		{
			// in case comment notation is forward (//)
			if ((c = getch()) == '/')
				while ((c = getch()) != '\n')
					;
			// in case comment notation is */
			else if (c == '*')
				while ((c = getch()) != '*' && c != EOF)
					if (getch() == '*')
						if (getch() == '/')
							break;
		}
		// if found string constants 
		if (c == '"')
			while ((c = getch()) != '"' && c != '\n' && c != EOF)
				;
		// if found preprocessor. Found some bugs in this lines, but don't have time to fix them. Wait me later ...
		if (c == '#')
			while ((c = getch()) != '\n' && c != EOF)
				;
		*w = '\0';
		return c;
	}
	for (;--lim>0;w++)
	{
		if (!isalnum(*w = getch()) && *w != '_')
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

// getch and ungetch routine
int getch(void)
{
	return buffindex > 0 ? buff[buffindex--] : getchar();
}

void ungetch(int c)
{
	if (buffindex > MAXBUFF)
		printf("Buffer Error: Buffer is over !\n");
	else 
		buff[buffindex++] = c;
}
