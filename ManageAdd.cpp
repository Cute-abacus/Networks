#include"Manage.h"
bool Manage::addVertex()
{
	cout << "��˼��" << endl;
	Vertex a;
	cout << "������Ҫ��ӽ��ı�ţ�" << endl;
	cin >> a.id;
	if (Route.getVertexPos(a.id) != -1)
	{
		cout << "�ý���Ѵ��ڣ�\n";
		return false;
	}
	cout << "������Ҫ��ӽ������ƣ�" << endl;
	cin >> a.name;
	Route.insertVertex(a);
	write1();
	return true;
}
/*��д�ķ�ʽ���ļ�����ͼ�н����forѭ����ʽд���ļ�����������id��name
ʵ����ͼ�Ľ��ĸ���
�ر��ļ�*/
void Manage::write1()
{
	ofstream infile; 
	infile.open("vertex.txt");  
	for (int i = 0; i < Route.NumberOfVertices(); i++)
	{
		infile << Route.NodeTable[i].name << ' ' << Route.NodeTable[i].id << '\n';
	}
	infile.close();
}
bool Manage::addEdge()
{
	int b, c;
	double cost;
	cout << "������Ҫ��ӱߵĽ��1�ı�ţ�" << endl;
	cin >> b;
	cout << "������Ҫ��ӵıߵĽ��2�ı�ţ�" << endl;
	cin >> c;
	if (!check(b) || !check(c))
	{
		return false;
	}
	cout << "������ߵ�Ȩֵ��" << endl;
	cin >> cost;
	Route.insertEdge(b, c, cost);
	write2();
}
/*��д�ķ�ʽ���ļ�����ͼ�еı���forѭ����ʽд���ļ��������ߵ�id����Ȩֵ
ʵ��ͼ�ıߵĸ���
�ر��ļ�*/
void Manage::write2()
{
	ofstream infile;
	infile.open("Edge.txt");
	for (int i = 0; i < Route.NumberOfVertices(); i++)
	{
		Edge *current = Route.NodeTable[i].adj;
		while (current != NULL)
		{
			infile << Route.NodeTable[i].id << ' ';
			infile << Route.getvalue(current->dest) << ' ' << current->cost << '\n';
			current = current->link;
		}
	}
	infile.close();
}
/*�����ӽ����ʱ·�ɱ����Ƿ��Ѵ��ڸý����*/
bool Manage::check(int id)
{
	if (Route.getVertexPos(id) == -1)
	{
		cout << "·�ɱ������޸ý�㣡\n\n";
		cout << "�Ƿ���Ӹý�㣿\n\n";
		cout << "1.��      2.��\n\n";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:cout << "����ʧ��,�������޷�ʶ���ָ��\n\n"; return false;
		case 1: {
			Vertex a;
			a.id = id;
			cout << "������Ҫ��ӽ������ƣ�\n\n" << endl;
			cin >> a.name;
			Route.insertVertex(a);
			write1();
		}break;
		case 2:cout << "���������棡\n\n"; return false;
		}
	}
	return true;
}