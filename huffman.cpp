/*************************************************************
     ___________       _____|_____    /__  /__               *
      ____|____          /  |  \       __ / \/      ——    —— *
	______|______       /   |   \     __|_  /\       \____/  *
	                   |  |   |   |     |/  -|-              *
					                        -|-              *
										    -|-              *
**************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node;
typedef Node* pNode;
struct Node
{
	double rate;
	char c;
	pNode left, right, parent;
};

vector<Node> nodes;
vector<pNode> pn_vect;
int number_of_node = 0;
double average_bit_rate = 0;

//get rate and initial nodes
void get_rate(string &pre_str)
{
	int count, space_number = 0, ns = 0;
	bool flag = false;
	const int str_len = pre_str.length();
	Node tmp;
	size_t index1 = 0, len = 0;
	double sum;
	char no_space[1000];
	for (int pre = 0; pre < str_len; pre++, ns++)
	{
		while (pre_str[pre] == ' ')
			pre++;
		no_space[ns] = pre_str[pre];
	}
	string s = no_space;
	int ns_len = ns;
	sum = ns;
	while (index1 < ns_len)
	{
		flag = false;
		count = 1;
		for (auto ir = nodes.begin(); ir != nodes.end(); ir++)
		{
			if (s[index1] == ir->c || s[index1] == ir->c + 32 || s[index1] == ir->c - 32)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			index1++;
			continue;
		}
		if (index1 >= ns_len)
		{
			index1--;
			break;
		}
		size_t index2 = index1 + 1;
		while (index2 < ns_len)
		{
			if (s[index2] == s[index1] || s[index2] + 32 == s[index1] || s[index2] - 32 == s[index1])
				count++;
			index2++;
		}
		tmp.c = s[index1] < 97 ? (s[index1] + 32) : (s[index1]);
		tmp.rate = count / sum;
		tmp.left = tmp.right = tmp.parent = nullptr;
		nodes.push_back(tmp);
		index1++;
	}
	number_of_node = nodes.size();
}

void initial_node()
{
	pNode tmp = nullptr;
	for (size_t i = 0; i != nodes.size(); i++)
	{
		tmp = &nodes[i];
		pn_vect.push_back(tmp);
	}
}

void buildtree()
{
	int p0 = 0, p1 = 1, pi = 2;
	//选出最小的两个节点的索引 存于p0和p1
	while (pn_vect[p0] == nullptr)
		p0++;
	p1 = p0 + 1;
	while (pn_vect[p1] == nullptr)
		p1++;
	if (pn_vect[p0]->rate > pn_vect[p1]->rate)
	{
		p0 = p0 + p1;
		p1 = p0 - p1;
		p0 = p0 - p1;
	}

	pi = 1 + (p0>p1?p0:p1);
	if (number_of_node > 2)
	{
		//sort the two smallest index ,and nodes[p0].rate < nodes[p1].rate
		for (int n = 0; n < number_of_node; n++, pi++)
		{
			if (pi >= pn_vect.size())
				break;
			//while (pn_vect[pi] == nullptr)  here appears a bi problm... if pi=pn_size()-1, pi++ will out of range....
			while (pn_vect[pi] == nullptr && pi < pn_vect.size()-1)
			{
				pi++;
			}
			if (pi == pn_vect.size() - 1 && pn_vect[pi] == nullptr)
				break;
			//pi < p0 < p1 -----update
			if (pn_vect[pi]->rate <= pn_vect[p0]->rate)
			{
				p1 = p0;
				p0 = pi;
			}
			// p0 <= pi < p1 ------update,too
			else if (pn_vect[pi]->rate <= pn_vect[p1]->rate && pn_vect[p0]->rate <= pn_vect[pi]->rate)
			{
				p1 = pi;
			}
			else
				continue;
		}
	}

	//创建一个新的节点，将刚选出的两个节点结合
	pNode new_p = new Node();
	pn_vect[p0]->parent = pn_vect[p1]->parent = new_p;
	new_p->rate = pn_vect[p0]->rate + pn_vect[p1]->rate;
	new_p->parent = nullptr;
	new_p->c = 0;
	new_p->left = pn_vect[p0];
	new_p->right = pn_vect[p1];
	pn_vect[p1] = nullptr;
	pn_vect[p0] = new_p;
	number_of_node--;
}

void show_count_rate()
{
	auto ir = nodes.begin();

	for (int i = 0; ir != nodes.end(); ir++, i++)
	{
		if (i == 3)
		{
			cout << endl;
			i = 0;
		}
		cout << "字符:" << ir->c << "  频率:" << ir->rate << "   ";
	}
}

void huff_code()
{
	int i, num_node = nodes.size();
	//use one string to store all the huffman code, so it should be cleaned after we showed the huffman code 
	string code;
	pNode ir_child = nullptr;
	pNode ir_parent = nullptr;
	for(i = 0; i < num_node; i++)
	{
		code.erase(code.begin(), code.end());
		cout << nodes[i].c << ":";  //cleaned
		ir_child = &nodes[i];
		ir_parent = ir_child->parent;
		while (ir_parent != nullptr)
		{
			if (ir_child == ir_parent->right)
				code += '1';
			else
				code += '0';
			ir_child = ir_parent;
			ir_parent = ir_parent->parent;
		}
		//for (auto ir = code.end() - 1; ir >= code.begin(); ir--)
		for (int index = code.size()-1; index >= 0; index--)
		{
			cout << code[index];
		}
		cout << endl;
		average_bit_rate += nodes[i].rate * code.size();
	}
}

int main()
{
	string s;
	cout << "Please input:";
	getline(cin, s);
	get_rate(s);
	show_count_rate();
	initial_node();
	while (number_of_node > 1)
	{
		buildtree();
	}
	huff_code();
	cout << "average bit rate is:" << average_bit_rate << endl;
	return 0;
}