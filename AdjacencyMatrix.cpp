#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n)
{
	numOfVertex = n;
	matrix = new float* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new float[n];
	MakeEmptyGraph();
}
AdjacencyMatrix::~AdjacencyMatrix()
{
	if (matrix)
	{
		for (int i = 0; i < numOfVertex; i++)
			delete matrix[i];
		delete matrix;
	}
}
void AdjacencyMatrix::MakeEmptyGraph()
{
	for (int i = 0; i < numOfVertex; i++)
	{
		for (int j = 0; j < numOfVertex; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INFINITY; 
		}
	}
}
bool AdjacencyMatrix::IsAdjacent(int u, int v)
{
	if (matrix[u][v] != INFINITY)
		return true;
	return false;
}
List* AdjacencyMatrix::GetAdjList(int u)
{
	List* res = new List;
	for (int i = 0; i < numOfVertex; i++)
	{
		if ((matrix[u][i] != INFINITY) && (u != i))
			res->AddItemToTail(i, matrix[u][i]);
	}
	return res;
}
void AdjacencyMatrix::AddEdge(int u, int v, float c)
{
	if (u > numOfVertex || v > numOfVertex || c < 0 || u == v) //edges are not in the range / weight is negative / self edge
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	if (IsAdjacent(u, v)) //edge already exist
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	matrix[u][v] = c;
}
void AdjacencyMatrix::RemoveEdge(int u, int v)
{
	matrix[u][v] = INFINITY;
}
void AdjacencyMatrix::PrintMat() 
{
	cout << "    1    2    3    4    5    6    7";
	for (int i = 0; i < numOfVertex; i++)
	{
		cout << endl;
		cout << "_____________________________________" << endl << i + 1;
		for (int j = 0; j < numOfVertex; j++)
		{
			cout << fixed << setprecision(1) << setfill(' ');
			cout << '|' << setw(4) << matrix[i][j];
		}
		cout << '|';
	}
}