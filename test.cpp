#include"Manage.h"
using namespace std;
int main()
{
	cout << "*************************欢迎使用路由表生成系统*************************\n\n";
	Manage master;
	while (1)
	{
		cout << "*************************请按照功能序号选择功能*************************\n\n";
		cout << "\t\t**1.显示路由表\t\t 2.新建结点**\n\n";
		cout << "\t\t**3.新建路径  \t\t 4.删除结点**\n\n";
		cout << "\t\t**5.删除路径  \t\t 6.退    出**\n\n";
		cout << "************************************************************************\n\n";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:cout << "无此功能\n\n"; break;
		case 1:if (master.Route.numVertices == 0)
		{
			master.empty();
			master.GetInformation();
		} master.shortestpath(); break;
		case 2:if (master.Route.numVertices == 0)
		{
			master.empty();
			master.GetInformation();
		}
			master.addVertex(); break;
		case 3:if (master.Route.numVertices == 0)
		{
			master.empty();
			master.GetInformation();
		}master.addEdge(); break;
		case 4:if (master.Route.numVertices == 0)
		{
			master.empty();
			master.GetInformation();
		}master.removeVertex(); break;
		case 5:if (master.Route.numVertices == 0)
		{
			master.empty();
			master.GetInformation();
		}master.removeEdge(); break;
		case 6:system("pause"); exit(0);
			break;
		}
	}
	
}