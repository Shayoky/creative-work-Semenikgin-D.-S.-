#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
using namespace std;
#define INF INT_MAX
int N = 0;
int k = 0;
int* arr = 0;
class point
{
public:
	point()
	{};
	~point()
	{};
public:
	point* newNode(int** parentMatrix, vector<pair<int, int>> const& path, int level, int i, int j);
	void rowReduction(int** reducedMatrix, int* row);
	void columnReduction(int** reducedMatrix, int* col);
	int calculateCost(int** reducedMatrix);
	void printPath(vector<pair<int, int>> const& list);
	int solve(int** adjMatrix);
	void swap();
private:
	vector<pair<int, int>> path;
	int** reducedMatrix;
	int cost;
	int vertex;
	int level;
};

point* point::newNode(int** parentMatrix, vector<pair<int, int>> const& path, int level, int i, int j)
{
	point* node = new point;
	node->path = path;
	if (level != 0)
		node->path.push_back(make_pair(i, j));
	node->reducedMatrix = new int* [N];
	for (int i = 0; i < N; i++)
		node->reducedMatrix[i] = new int[N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			node->reducedMatrix[i][j] = parentMatrix[i][j];
		}
	}
	for (int k = 0; level != 0 && k < N; k++)
	{
		node->reducedMatrix[i][k] = INF;
		node->reducedMatrix[k][j] = INF;
	}
	node->reducedMatrix[j][0] = INF;
	node->level = level;
	node->vertex = j;
	return node;
}
void point::rowReduction(int** reducedMatrix, int* row)
{
	fill_n(row, N, INF);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (reducedMatrix[i][j] < row[i])
				row[i] = reducedMatrix[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (reducedMatrix[i][j] != INF && row[i] != INF)
				reducedMatrix[i][j] -= row[i];
}
void point::columnReduction(int** reducedMatrix, int* col)
{
	fill_n(col, N, INF);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (reducedMatrix[i][j] < col[j])
				col[j] = reducedMatrix[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (reducedMatrix[i][j] != INF && col[j] != INF)
				reducedMatrix[i][j] -= col[j];
	return;
}
int point::calculateCost(int** reducedMatrix)
{
	int cost = 0;
	int* row = new int[N];
	rowReduction(reducedMatrix, row);
	int* col = new int[N];
	columnReduction(reducedMatrix, col);
	for (int i = 0; i < N; i++)
		cost += (row[i] != INT_MAX) ? row[i] : 0,
		cost += (col[i] != INT_MAX) ? col[i] : 0;

	return cost;
}
void point::printPath(vector<pair<int, int>> const& list)
{
	int kp1, kp2 = 0;
	for (int i = 0; i < list.size(); i++)
	{
		kp1 = list[i].first + 1;
		kp2 = list[i].second + 1;
		if (kp1 == 1 && k != 1)
		{
			kp1 = k;
		}
		else if (kp1 == k && k != 1)
		{
			kp1 = 1;
		}
		if (kp2 == 1 && k != 1)
		{
			kp2 = k;
		}
		if (kp2 == k && k != 1)
		{
			kp2 = 1;
		}
		if (i == list.size() - 1)
		{
			kp2 = k;
		}
		cout << kp1 << " -> " << kp2 << endl;
	}
}
int point::solve(int** adjMatrix)
{
	struct comp {
		bool operator()(const point* lhs, const point* rhs) const
		{
			return lhs->cost > rhs->cost;
		}
	};
	priority_queue<point*, std::vector<point*>, comp> pq;
	vector<pair<int, int>> v;
	point* root = newNode(adjMatrix, v, 0, -1, 0);
	root->cost = calculateCost(root->reducedMatrix);
	pq.push(root);
	while (!pq.empty())
	{
		point* min = pq.top();
		pq.pop();
		int i = min->vertex;
		if (min->level == N - 1)
		{
			min->path.push_back(make_pair(i, 0));
			printPath(min->path);
			return min->cost;
		}
		for (int j = 0; j < N; j++)
		{
			if (min->reducedMatrix[i][j] != INF)
			{
				point* child = newNode(min->reducedMatrix, min->path,
					min->level + 1, i, j);
				child->cost = min->cost + min->reducedMatrix[i][j]
					+ calculateCost(child->reducedMatrix);
				pq.push(child);
			}
		}
		delete min;
	}
}

void point::swap()
{
	point A;
	setlocale(LC_ALL, "rus");
	cout << "Точка отправки: ";
	cin >> k;
	cout << "k = " << k << endl;
	int k1 = k - 1;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		swap(adjMatrix[k1][i], adjMatrix[0][i]);
	}
	for (int l = 0; l < N; l++)
	{
		swap(adjMatrix[l][0], adjMatrix[l][k1]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << adjMatrix[i][j] << ' ';
		cout << endl;
	}
	cout << "\n\nTotal Cost is " << A.solve(adjMatrix);
	return 0;
}