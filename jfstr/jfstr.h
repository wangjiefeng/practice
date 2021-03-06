#ifndef _JFSTR_H
#define _JFSTR_H

struct jfstring
{
	char *s;
	int length;
};

void jfstrinit(struct jfstring *jf, const char* src);
struct jfstring* jfstrcpy(struct jfstring *dest, struct jfstring *src);
struct jfstring* jfstrncpy(struct jfstring *dest, struct jfstring *src, int n);
int jfstrcmp(struct jfstring *a, struct jfstring *b);
void jfsetstr(struct jfstring *str, char ch);

#endif
