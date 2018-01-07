#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include"SeqQueue.h"
#include"Graph.h"
using namespace std;
//�����ǹ����࣬���������Ҫ������
//1.���������ӹ�ϵ
//2.����ͼ��������Ե���Graph�ࣩ
//3.�����С������
//4.���·�ɱ�
//5.��ӵ�ͱ߹�ϵ�����ֻ��ӵ㣬��Ҫ���һ���飬��һ���㲻�ɴ�ʱ���������Ӧ��Ӧ��
//��������������ǵĴ���
//�����Ľӿ��������и���
class Manage
{
public:
	Graph Route;
	int path[1000];//���·��
	double dist[1000];
	bool GetInformation();//��Ҫ�����Ҷ�����Ϣ�Ƿ�ɹ�
	bool shortestpath();//���·��
	bool addVertex();//�½���㣬ҲҪ��д�ļ�Ŷ~
	bool addEdge();//���ﲻ�������Graph�ĺ�����ͬʱҲҪ��д�ļ�
	void write1();//д�� ���
	void write2();//д���
	bool check(int id);
	bool removeEdge();
	bool removeVertex();
	void empty();
	void print(Graph& G, int v, double dist[], int path[]);
	void ShortestPath(Graph& G, int v, int *path, double *dist);
};
