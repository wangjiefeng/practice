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
		dest->s = (char*)realloc(dest->s, sizeof(char) * (src->length + 1));
	}
	char *tmpd = dest->s;
	char *tmps = src->s;
	while (*tmpd++ = *tmps++)
		;
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
		dest->s = (char*)realloc(dest->s, sizeof(char) * (n + 1));
	}
	char *tmpd = dest->s;
	char *tmps = src->s;
	for(i = 0; i < n; i++)
	{
		*tmpd++ = *tmps++;
	}
	*tmpd = '\0';
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
