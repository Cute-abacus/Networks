#include"Manage.h"
bool Manage::removeEdge()
{
	cout << "请输入要删除的边的第一个结点编号\n";
	int a;
	cin >> a;
	cout << "请输入要删除的边的第二个结点编号\n";
	int b;
	cin >> b;
	if (!check(a) || !check(b))
	{
		return false;
	}
	if (!Route.removeEdge(a, b))
	{
		cout << "此边不存在\n";
		return false;
	}
	cout << "删除成功！\n";
	write2();
}
bool Manage::removeVertex()
{
	cout << "请输入删除结点的编号\n";
	int a;
	cin >> a;
	if (!check(a))
	{
		return false;
	}
	a = Route.getVertexPos(a);
	if (Route.removeVertex(a))
		cout << "删除成功！\n\n";
	write1();
}
void Manage::empty()
{
	Route.NodeTable = new Vertex[1000];
	Route.numVertices = 0;
	Route.numEdges = 0;
}