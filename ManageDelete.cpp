#include"Manage.h"
bool Manage::removeEdge()
{
	cout << "������Ҫɾ���ıߵĵ�һ�������\n";
	int a;
	cin >> a;
	cout << "������Ҫɾ���ıߵĵڶ��������\n";
	int b;
	cin >> b;
	if (!check(a) || !check(b))
	{
		return false;
	}
	if (!Route.removeEdge(a, b))
	{
		cout << "�˱߲�����\n";
		return false;
	}
	cout << "ɾ���ɹ���\n";
	write2();
}
bool Manage::removeVertex()
{
	cout << "������ɾ�����ı��\n";
	int a;
	cin >> a;
	if (!check(a))
	{
		return false;
	}
	a = Route.getVertexPos(a);
	if (Route.removeVertex(a))
		cout << "ɾ���ɹ���\n\n";
	write1();
}
void Manage::empty()
{
	Route.NodeTable = new Vertex[1000];
	Route.numVertices = 0;
	Route.numEdges = 0;
}