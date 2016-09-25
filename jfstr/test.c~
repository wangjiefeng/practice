#include <stdio.h>
#include "jfstr.h"

int main()
{
	struct jfstring str;
	str.length = 0;
	jfstrinit(&str, "HelloWorld");
	printf("str : %s\n", str.s);
	struct jfstring str2;
	jfstrinit(&str2, "foobar!");
	printf("str2 : %s\n", str2.s);
	jfstrcpy(&str2, &str);
	printf("str2 : %s\n", str2.s);
	jfstrncpy(&str2, &str, 5);
	printf("str2 : %s\n", str2.s);
	return 0;
}
