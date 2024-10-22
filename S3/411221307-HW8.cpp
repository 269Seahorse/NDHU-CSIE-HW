#include <bits/stdc++.h>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
	Grid()
	{
		Grid(0);
	}
	Grid(int s)
	{
		state = s;
		dir[UP] = NULL;
		dir[DOWN] = NULL;
		dir[LEFT] = NULL;
		dir[RIGHT] = NULL;
	}
	Grid *getDir(int d) { return dir[d]; }
	int getState() { return state; }
	void setDir(int d, Grid *g) { dir[d] = g; }
	void setState(int s) { state = s;}
private:
	Grid *dir[4];
	int state;
};

struct List
{
public:
	List()
	{
		top = 0;
	}
	/*
	Insert an element from top
	*/
	void addElement(Grid *g)
	{
		if(top < SIZE * SIZE)
		{
			data[top] = g;
			top++;
		}
	}
	/*
	remove an element from top and return a pointer point to the element.
	If list is empty, return NULL.
	*/
	Grid *removeElement()
	{
		if(top > 0)
		{
			top--;
			return data[top];
		}
		return NULL;
	}
	void printPath()
	{
		int j;
		for(j = 1;j < top;j ++)
		{
			if(data[j] == data[j - 1]->getDir(UP))
			{
				cout<<"UP\n";
			}
			else if(data[j] == data[j - 1]->getDir(DOWN))
			{
				cout<<"DOWN\n";
			}
			else if(data[j] == data[j - 1]->getDir(LEFT))
			{
				cout<<"LEFT\n";
			}
			else if(data[j] == data[j - 1]->getDir(RIGHT))
			{
				cout<<"RIGHT\n";
			}
		}
	}
private:
	Grid *data[SIZE * SIZE];
	int top;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
	}
	/*
	function initMaze
	Alocate a 2-D link list with s * s sizes as the map of maze.
	Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
	The gird in left top is start point and right bottom is finish point.
	Randomly generate 20% wall in the maze.
	Make sure start point and finish point are 0

	動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
	節點中 0 的值表示可以移動的空間， 1 表示牆壁 
	左上角的位置表示起點，右下角的位置表示終點
	請在迷宮中加入 20% 的牆壁 
	然後確定起點跟終點都是可以移動的位置 
	*/
	void initMaze(int s) {
		srand(time(NULL));
		Grid *preRow, *curRow, *pre, *cur;
		maze = new Grid(0);
		curRow = maze;
		preRow = curRow;

		for (int j = 0; j < s; j++) {
			pre = curRow;
			for (int k = 1; k < s; k++) {
				cur = new Grid(rand() % 5 == 0 ? 1 : 0);
				pre->setDir(RIGHT, cur);
				cur->setDir(LEFT, pre);
				pre = cur;
				if(j > 0) {
					preRow = preRow->getDir(RIGHT);
					cur->setDir(UP, preRow);
					preRow->setDir(DOWN, cur);
				}
			}
			if (j < s - 1) {
				curRow = new Grid(rand() % 5 == 0 ? 1 : 0);
				while(preRow->getDir(LEFT) != NULL) preRow = preRow->getDir(LEFT);
				if(j != 0) preRow = preRow->getDir(DOWN);
				preRow->setDir(DOWN, curRow);
				curRow->setDir(UP, preRow);
			}
		}

		maze->setState(0);
		Grid* finish = maze;
		while (finish->getDir(DOWN) != nullptr) {
			finish = finish->getDir(DOWN);
		}
		while (finish->getDir(RIGHT) != nullptr) {
			finish = finish->getDir(RIGHT);
		}
		finish->setState(0);
	}
	/*
	function getPath
	This function will find a path between start point and finish point using BFS.
	Return a list containing the path information inside.
	If there is no path between two points, then the list will be empty.
	*/
	List* getPath() {
		queue<Grid*> q;
		map<Grid*, Grid*> parent;
		Grid* start = maze;
		Grid* finish = maze;
		List* path = new List();

		// Find the finish point
		while (finish->getDir(DOWN) != nullptr) {
			finish = finish->getDir(DOWN);
		}
		while (finish->getDir(RIGHT) != nullptr) {
			finish = finish->getDir(RIGHT);
		}

		// BFS initialization
		q.push(start);
		parent[start] = nullptr;
		Grid* current = q.front();
		// BFS loop
		while (!q.empty()) {
			current = q.front();

			// If we reached the finish point, reconstruct the path
			if (current == finish) {
				while (current != nullptr) {
					path->addElement(current);
					current = parent[current];
				}
				// Reverse the path to start from the beginning
				List* reversedPath = new List();
				while (Grid* g = path->removeElement()) {
					reversedPath->addElement(g);
				}
				return reversedPath;
			}

			// Explore neighbors
			for (int d = 0; d < 4; d++) {
				Grid* neighbor = current->getDir(d);
				if (neighbor != nullptr && neighbor->getState() == 0) {
					q.push(neighbor);
					parent[neighbor] = current;
				}
			}
			current->setState(-1);
			q.pop();
		}

		// If no path found, return an empty list
		return path;
	}
	void printMaze()
	{
		Grid *j = maze, *k;
		while(j != NULL)
		{
			k = j;
			while(k != NULL)
			{
				cout<<k->getState();
				k = k->getDir(RIGHT); 
			}
			cout<<endl;
			j = j->getDir(DOWN);
		}
	}
private:
	Grid *maze;
};

int main()
{
	Maze *maze = new Maze();
	maze->printMaze();
	maze->getPath()->printPath();
}
