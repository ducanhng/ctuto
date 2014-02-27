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
int main()
{
	int c;
	struct tnode *root;
	root = NULL;
	while ((c = getword(word, MAXWORD)) != EOF)
	{
		//root = talloc(); why talloc is not here

		if (isalpha(word[0]))
		{
			// point to root
			root = addtree(root,word);
		}
	}
	
	printf("The tree have root is: %s\n",root->s);
	// print tree
	treeprint(root);
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
			parent->rightnode = addtree(parent->rightnode, word);
		else if (strcmp(parent->s, word) < 0)
			parent->leftnode = addtree(parent->leftnode, word);
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


