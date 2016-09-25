#include "jfstr.h"
#include <stdio.h>
#include <stdlib.h>

void jfstrinit(struct jfstring *jf, const char* src)
{
	int i = 0;
	while(src[i] != '\0')
		++i;
	jf->length = i;
	jf->s = (char*)malloc(sizeof(char) * ++i);
	if(jf->s == NULL)
	{
		fprintf(stderr, "Failed to malloc!");
		exit(0);
	}
	i = 0;
	while((jf->s[i] = src[i]) != '\0')
	{
		++i;
	}
	jf->s[++i] = '\0';
}

struct jfstring* jfstrcpy(struct jfstring *dest, struct jfstring *src)
{
	if(!src->s)
	{
		printf("Error: source string is NULL!");
		return dest;
	}
	if(dest->length <= src->length)
	{
		free(dest->s);
		dest->s = (char*)malloc(sizeof(char) * (src->length + 1));
	}
	int i = 0;
	while(dest->s[i] = src->s[i])
		++i;
	dest->s[++i] = '\0'; 
	dest->length = src->length;
	return dest; 
}

struct jfstring* jfstrncpy(struct jfstring *dest, struct jfstring *src, int n)
{
	int i;
	if(!src->s)
	{
		printf("Error: source string is NULL!");
		return dest;
	}
	if(n > src->length)
	{
		printf("Error: srouce has no enough character!\n");
		exit(0);
	}
	if(dest->length < n)
	{
		free(dest->s);
		dest->s = (char*)malloc(sizeof(char) * (n + 1));
	}

	for(i = 0; i < n; i++)
	{
		dest->s[i] = src->s[i];
	}
	dest->s[i] = '\0'; 
	dest->length = n;
	return dest; 
}

int jfstrcmp(struct jfstring *a, struct jfstring *b)
{
	int i;
	for (i = 0; a->s[i] == b->s[i]; ++i)
	{
		if (a->s[i] == '\0')
			return 0;
	}
	return a->s[i] - b->s[i];
}


void jfsetstr(struct jfstring *str, char ch)
{
	int i = 0;
	while(str->s[i] != '\0')
		str->s[i++] = ch;
}
