
#include <stdio.h>
#include <string.h>
#define MAXLINE 100
int getline1(char *, int);

void thu(char *v[]){
    char x =(*v)[0];//--> Correct
    char a =(*v)[0];//--> Correct

    char b =(*++v)[0];
    printf("b: %c \n",b);



}
int main(int argc, char *argv[])
    {

	char aname1[] = "blah blah";


//	char *s = "Toi la DA";
//	printf("s. %s\n", s);
    char *aname[4]={"Toi","lA","Tinh"};

	printf("0. %s\n",aname[0]);
	printf("1. %s\n",aname[1]);
	printf("2. %s\n",aname[2]);
	printf("3. %s\n",aname[3]);
char a =*++aname[1]; // aname[1] sẽ trỏ vào chuỗi thứ 2 là "là". Vậy *++(aname[1]) se trỏ vào phần tử thứ 2 của chuỗi đấy -> trỏ vào "a".
  //  printf("Ki tu nhan duoc: %c \n",a);

//	char blah[] = {"hihi"};
// Test auto mail here !
	
    thu(aname);

	return 0;
}



// return length of the line input and save in an array
int getline1(char *s, int maxlength)
{
	int c,len;
	len = 0;
	while ((c=getchar()) != EOF && c != '\n')
	{
		*s = c;
		++s;
		len++;
	}
	if (c == EOF)
		return c;
	if (c == '\n')
	{
		*s = c;
		++s;
		len++;
	}
	*s = '\0';
	return len;	
}
