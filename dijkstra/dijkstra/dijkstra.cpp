#include<glut.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<time.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
#define INF INT_MAX
using namespace std;
#pragma warning(disable : 4996)
GLsizei wh = 1080, ww = 1080;
GLfloat size = 3.0;
int mincost = 0;
float PI = 3.14285714286;
int radius = 20;
int nodeCount = 0;
int maxNodes = 26;
int lineNodesCount = 0;
int sourceNodeCreated = 0;
int destinationNodeCreated = 0;
int dijkstraRun = 0;
int instruction = 1;
int** adjMatrix = 0;
int** adjMatrix1 = 0;
int counter = 0;
int start = 0;
int finish = 0;
int N = 0;
string s;
string s1;
int zl=0;
int mindist = 0;
int k = 0;
int* arr = 0;
int pos = 0;
int sr = 0;
int i1 = 0;
int i2 = 0;
class node
{
public:
	node()
	{};
	~node()
	{};
public:
	int computeDistance(struct node a, struct node b);
	int noRepeat(int x, int y);
	void getPerpendicularCoordinates(int* x, int* y);
	void writeDistance(const char* text, int x, int y);
	void writeDistance1(string text, int x, int y);
	void writeLabel(char text, int x, int y);
	void drawCircle(float cx, float cy, float r, float num_segments, char colorCharacter);
	void getMidPoint(int* midX, int* midY);
	void getMidPoint1(int* midX, int* midY);
	void drawLine1(char color, int i, int j);
	void drawLine(char color);
	int getMinimumDistanceNode(int* distanceFromSource, int* selected);
	void routeNodes(int n1, int n2);
	void dijkstra();
public:
	int id;
	int xCoordinate;
	int yCoordinate;
};
node B;
node nodes[100], lineNodes[2], sourceNode, destinationNode;
int node::computeDistance(struct node a, struct node b)
{
	return (int)(sqrt(pow(abs(a.xCoordinate - b.xCoordinate), 2) + pow(abs(a.yCoordinate - b.yCoordinate), 2)));
}
int node::noRepeat(int x, int y)
{
	if (!nodeCount)
		return 1;
	node temp;
	temp.xCoordinate = x;
	temp.yCoordinate = y;
	temp.id = nodeCount;
	for (int i = 0; i < nodeCount; i++)
	{
		if (computeDistance(temp, nodes[i]) < 2 * radius)
		{
			lineNodes[lineNodesCount] = nodes[i];
			return 0;
		}
	}
	return 1;
}
void node::getPerpendicularCoordinates(int* x, int* y)
{
	int x1, x2, y1, y2;

	x1 = lineNodes[0].xCoordinate;
	x2 = lineNodes[1].xCoordinate;
	y1 = lineNodes[0].yCoordinate;
	y2 = lineNodes[1].yCoordinate;

	float diff = (x2 - x1) ? 0.0001 : x2 - x1;

	float slope = ((float)(y2 - y1)) / (diff);

	float perpendicularSlope = -1 * (1 / slope);


	*x = *x -25;
	*y = *y + perpendicularSlope * (*x) -7;

}
void node::writeDistance(const char* text, int x, int y)
{
	if (instruction)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(1.0, 1.0, 0.0);
	glRasterPos2i(x, y);
	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
	glFlush();
}
void node::writeDistance1(string text, int x, int y)
{
	if (instruction)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(1.0, 1.0, 0.0);
	glRasterPos2i(x, y);
	int len = text.length();
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
	glFlush();
}
void node::writeLabel(char text, int x, int y)
{
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos2i(x, y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text);
}
void node::drawCircle(float cx, float cy, float r, float num_segments, char colorCharacter)
{
	counter = counter + 1;
	float theta, x, y;
	if (colorCharacter == 'N')
		writeLabel((char)49 + nodeCount, cx - 5, cy - 14);
	if (colorCharacter == 'N')
		glColor3f(1.0, 1.0, 1.0);
	if (colorCharacter == 'B')
		glColor3f(0.0, 0.0, 1.0);
	if (colorCharacter == 'R')
		glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments; i++) {
		theta = 2.0f * PI * i / num_segments;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
	glFlush();

}
void node::getMidPoint(int* midX, int* midY)
{
	int x = 0, y = 0;
	x= (lineNodes[0].xCoordinate + lineNodes[1].xCoordinate) / 2;
	x = (lineNodes[0].xCoordinate + x) / 2;
	*midX = x;
	y= (lineNodes[0].yCoordinate + lineNodes[1].yCoordinate) / 2;
	y= (lineNodes[0].yCoordinate + y) / 2;
	*midY = y;
}
void node::getMidPoint1(int* midX, int* midY)
{
	int x = 0, y = 0;
	x = (lineNodes[0].xCoordinate + lineNodes[1].xCoordinate) / 2;
	x = (lineNodes[1].xCoordinate + x) / 2;
	*midX = x;
	y = (lineNodes[0].yCoordinate + lineNodes[1].yCoordinate) / 2;
	y = (lineNodes[1].yCoordinate + y) / 2;
	*midY = y;
}
void node::drawLine1(char color,int i,int j)
{
	if (color == 'M')
	{
		glColor3f(0.5, 0.0, 0.0);
	}
	glBegin(GL_LINES);
	glVertex2f(lineNodes[0].xCoordinate, lineNodes[0].yCoordinate);
	glVertex2f(lineNodes[1].xCoordinate, lineNodes[1].yCoordinate);
	glEnd();
	int midX, midY, midX1, midY1, midX2, midY2;
	string distanceString, distanceString1;
	getMidPoint(&midX, &midY);
	getMidPoint1(&midX1, &midY1);
	int id1 = lineNodes[0].id;
	int id2 = lineNodes[1].id;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << adjMatrix1[i][j] << ' ';
		cout << endl;
	}
	int distance1= adjMatrix1[i1][i2];
	int distance = adjMatrix1[i2][i1];
	distanceString1 = to_string(distance);
	distanceString = to_string(distance1);
	getPerpendicularCoordinates(&midX, &midY);
	getPerpendicularCoordinates(&midX1, &midY1);
	writeDistance1(distanceString, midX, midY);
	writeDistance1(distanceString1, midX1, midY1);
	glFlush();
	writeLabel('1' + lineNodes[0].id, lineNodes[0].xCoordinate - 5, lineNodes[0].yCoordinate - 14);
	writeLabel('1' + lineNodes[1].id, lineNodes[1].xCoordinate - 5, lineNodes[1].yCoordinate - 14);
	glFlush();
}
void node::drawLine(char color)
{
	if (color == 'N' || color == 'R')
		glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	glVertex2f(lineNodes[0].xCoordinate, lineNodes[0].yCoordinate);
	glVertex2f(lineNodes[1].xCoordinate, lineNodes[1].yCoordinate);
	glEnd();
	glFlush();
	int midX, midY,midX1,midY1,midX2,midY2;
	char distanceString[10], distanceString1[10];
	getMidPoint(&midX, &midY);
	getMidPoint1(&midX1, &midY1);
	int id1 = lineNodes[0].id;
	int id2 = lineNodes[1].id;
	int distance1;
	int distance;
	cout << "distance " << id1+1 << " -> " << id2+1<<": ";
	cin >> distance1;
	cout << "distance " << id2 + 1 << " -> " << id1 + 1 << ": ";
	cin >> distance;
	adjMatrix[id1][id2] = distance1;
	adjMatrix[id2][id1] = distance;
	sprintf(distanceString1, "%d", distance);
	sprintf(distanceString, "%d", distance1);
	getPerpendicularCoordinates(&midX, &midY);
	getPerpendicularCoordinates(&midX1, &midY1);
	writeDistance(distanceString, midX, midY);
	writeDistance(distanceString1, midX1, midY1);
	glFlush();
	writeLabel('1' + lineNodes[0].id, lineNodes[0].xCoordinate - 5, lineNodes[0].yCoordinate - 14);
	writeLabel('1' + lineNodes[1].id, lineNodes[1].xCoordinate - 5, lineNodes[1].yCoordinate - 14);
	glFlush();
	if (color == 'N')
	{
		printf("\n");
		for (int i = 0; i < nodeCount; i++)
		{
			for (int j = 0; j < nodeCount; j++)
			{
				printf("%d \t", adjMatrix[i][j]);
			}
			printf("\n");
		}
	}
}
void myMouse(int btn, int state, int x, int y)
{
	if (instruction)
	{
		instruction = 0;
		glClear(GL_COLOR_BUFFER_BIT);
		B.writeDistance("Left mouse button - create node.", 5, 800);
		B.writeDistance("Select (left moouse button) two nodes to bind them together.", 5, 770);
		B.writeDistance("Use right mouse button to choose Start circle", 5, 740);
		B.writeDistance("Press ENTER to solve travelling salesman using branch and bound.", 5, 710);
		B.writeDistance("---------------------------------------------------------Create nodes under this line---------------------------------------------------------", 5, 680);
	}
	if (dijkstraRun)
	{
		return;
	}
	y = wh - y;
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (B.noRepeat(x, y))
		{
			if (nodeCount >= 26)
			{
				return;
			}
			B.drawCircle(x, y, radius, 200, 'N');
			lineNodesCount = 0;
			nodes[nodeCount].xCoordinate = x;
			nodes[nodeCount].yCoordinate = y;
			nodes[nodeCount].id = nodeCount;
			nodeCount++;
		}
		else
		{
			if (lineNodesCount == 1)
			{
				B.drawLine('N');
				lineNodesCount = 0;
			}
			else
			{
				lineNodesCount += 1;
			}
		}
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && (!sourceNodeCreated || !destinationNodeCreated))
	{
		if (nodeCount)
		{
			if (!B.noRepeat(x, y))
			{
				if (!sourceNodeCreated)
				{
					sourceNode = lineNodes[0];
					sourceNodeCreated = 1;
					k = sourceNode.id + 1;
					B.drawCircle(sourceNode.xCoordinate, sourceNode.yCoordinate, radius, 200, 'B');//начало

				}

			}
		}
	}

}
void myReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
	ww = w;
	wh = h;
}
void myInit()
{
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ww, 0, wh);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(5);
}
void display_hello()
{
	node A;
	A.writeDistance("Left mouse button - create node.", 5, 800);
	A.writeDistance("Select (left moouse button) two nodes to bind them together.", 5, 770);
	A.writeDistance("Use right mouse button to choose Start circle", 5, 740);
	A.writeDistance("Press ENTER to solve travelling salesman using branch and bound.", 5, 710);
	A.writeDistance("---------------------------------------------------------Create nodes under this line---------------------------------------------------------", 5, 680);
}
void myDisplay()
{
	display_hello();
	glFlush();

}
void fixAdjMatrix()
{
	cout << "count of citites: ";
	cin >> N;
	adjMatrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		adjMatrix[i] = new int[N];
	}
	adjMatrix1 = new int* [N];
	for (int i = 0; i < N; i++)
	{
		adjMatrix1[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			adjMatrix[i][j] = INF;
		}
	}
}
////////////////////////////////////
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
	void swap1(point D);
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
	arr = new int[2 * list.size()];
	pos = 0;
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
		arr[pos] = kp1;
		arr[pos + 1] = kp2;
		pos +=2;
	}
	sr = 2 * list.size();
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

void point::swap1(point D)
{
	setlocale(LC_ALL, "rus");
	int k1 = k - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			adjMatrix1[i][j] = adjMatrix[i][j];
		}
		cout << endl;
	}
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
	s1 = "";
	s1 = "Minimum distance from "+to_string(k)+" = " + to_string(D.solve(adjMatrix));
	cout << s1 << endl;
}
///////////////////////////////////
void beginDijkstra(unsigned char key, int x, int y)
{
	printf("%d\n", key);
	if (!sourceNodeCreated)
	{
		printf("Начальный и конечный узлы не выбраны\n");
		return;
	}
	if ((int)key == 13)
	{
		point D;
		dijkstraRun = 1;
		D.swap1(D);
		B.dijkstra();
	}
}

int main(int argc, char** argv)
{
	node B;
	setlocale(LC_ALL, "rus");
	fixAdjMatrix();
	glutInit(&argc, argv);
	glutInitWindowSize(ww, wh);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Задача Коммивояжера");
	myInit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(beginDijkstra);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
int node::getMinimumDistanceNode(int* distanceFromSource, int* selected)
{
	int minimumNode = -1;
	int minimumDistance = INF;
	for (int i = 0; i < nodeCount; i++)
	{
		if (selected[i] != 1 && distanceFromSource[i] < minimumDistance)
		{
			minimumNode = i;
			minimumDistance = distanceFromSource[i];
		}
	}
	return minimumNode;
}
void node::routeNodes(int n1, int n2)
{
	lineNodes[0] = nodes[n1];
	lineNodes[1] = nodes[n2];
	zl += 1;
	drawLine1('M',n1,n2);
}
void node::dijkstra()
{
	s = to_string(arr[0]);
	for (int i = 0; i < sr - 1; i++)
	{
		i1 = arr[i]-1;
		cout << "i1 = " << i1 << endl;
		i2 = arr[i + 1]-1;
		cout << i2 << "i2 = " << i2 << endl;
		routeNodes(arr[i]-1,arr[i+1]-1);
		if (arr[i + 1] != arr[i])
			s = s + "->" + to_string(arr[i + 1]);
	}
	cout << s << endl;
	B.writeDistance1(s, 800, 800);
	B.writeDistance1(s1, 800, 770);
}
