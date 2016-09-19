#include <iostream>
#include <string>
#include <locale>
#include <vector>

using namespace std;

struct op{
	char Relation;//set 'C' if has child and set 'P' if has parent, either of them set 'N'
	string value;
	op *left, *right;
};

void preprocess(vector<string> &vecoprs, vector<op*> &vecopts, string &s)
{
	int i = 0;
	string singal("");
	while (i < s.size())
	{
		singal.clear();
		if (isdigit(s[i]))
		{
			while (isdigit(s[i]))
				singal += s[i++];
			vecoprs.push_back(singal);
		}
		else
		{
			op *opt = new op();
			opt->value = s[i];
			opt->Relation = 'N';
			vecopts.push_back(opt);
			i++;
		}
	}
}

void toPostfixExpr(vector<string> vecoprs, vector<op*> vecopts)
{
	int iopt = 0, i = 0, j = 0, c_count = 0, p_count = 0;
	bool flag = false;
	while (!flag)
	{
		flag = false;
		j = 0;
		c_count = 0;
		p_count = 0;
		for (; j < vecopts.size(); j++)
		{
			if (vecopts[j]->Relation == 'C')
				c_count++;
			if (vecopts[j]->Relation == 'P')
				p_count++;
		}
		if (c_count == 1 && p_count == vecopts.size() - 1)
			break;
		iopt = 0;
		while (vecopts[iopt]->Relation == 'C' || vecopts[iopt]->Relation == 'P')
			iopt++; 
		if (vecopts[iopt]->value == "+" || vecopts[iopt]->value == "-")//process *, / first
		{
			i = iopt + 1;
			while (i < vecopts.size())
			{
				if (vecopts[i]->value == "*" || vecopts[i]->value == "/")
				{
					if (vecopts[i]->Relation == 'C' || vecopts[i]->Relation == 'P')
					{
						i++;
						continue;
					}
					iopt = i;
					break;
				}
				i++;
			}
		}
		//left
		if (vecoprs[iopt] == "N")
		{
			i = 1;
			while (vecopts[iopt-i]->Relation == 'P' && iopt - i >= 0)
			{
				i++;
			}
			vecopts[iopt]->left = vecopts[iopt-i];
			vecopts[iopt - i]->Relation = 'P';
		}
		else
		{
			op *op1 = new op();
			op1->value = vecoprs[iopt];
			vecopts[iopt]->left = op1;
			vecoprs[iopt] = "N";
		}
		//right
		if (vecoprs[iopt + 1] == "N")
		{
			i = 1;
			while (vecopts[iopt + i]->Relation == 'P' && iopt + i < vecopts.size())
			{
				i++;
			}
			vecopts[iopt]->right = vecopts[iopt + i];
			vecopts[iopt + i]->Relation = 'P';
		}
		else
		{
			op *op2 = new op();
			op2->value = vecoprs[iopt + 1];
			vecopts[iopt]->right = op2;
			vecoprs[iopt + 1] = "N";
		}

		vecopts[iopt]->Relation = 'C';
	}
}

void showPostExpr(op *exprTree)
{
	if (!exprTree)
		return;
	showPostExpr(exprTree->left);
	showPostExpr(exprTree->right);
	cout << exprTree->value;
}

int main()
{
	int i = 0;
	string expr;
	op * tree = nullptr;
	vector<op*> vecopts;//store operators
	vector<string> vecoprs;//store oprands

	while (1)
	{
		vecoprs.clear();
		vecopts.clear();
		cout << "input the expression:(q to quit)" << endl;
		getline(cin, expr);

		if (expr[0] == 'q' || expr[0] == 'Q')
			break;
		preprocess(vecoprs, vecopts, expr);
		toPostfixExpr(vecoprs, vecopts);
		tree = vecopts[i];
		while (tree->Relation != 'C')
			tree = vecopts[++i];
		cout << "Postfix Expression: ";
		showPostExpr(tree);
		cout << endl;
	}

	return 0;
}