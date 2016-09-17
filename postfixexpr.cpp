#include <iostream>
#include <string>
#include <locale>

using namespace std;

//postfix expression
string toPostfixExpr(string &s)
{
	int i = 0;
	char op;
	string pexpr("");
	while (i < s.size())
	{
		while (isdigit(s[i]))
			pexpr += s[i++];

		op = s[i];
		pexpr += " ";
		i++;
		while (isdigit(s[i]))
			pexpr += s[i++];

		pexpr += " ";
		pexpr += op;
	}
	return pexpr;
}
int main()
{
	string expr;
	string pexpr;
	cout << "input the expression:(q to quit)" << endl;

	while (1)
	{
		getline(cin, expr);

		if (expr[0] == 'q' || expr[0] == 'Q')
			break;

		pexpr = toPostfixExpr(expr);
		cout << pexpr << endl;
	}

	return 0;
}