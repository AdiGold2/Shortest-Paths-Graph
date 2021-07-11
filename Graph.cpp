#include "Graph.h"
Graph::~Graph()
{
	if (list)
		delete list;
	if (matrix)
		delete matrix;
	if (distances)
		delete distances;
}
void Graph::AddEdge(int u, int v, float c)
{
	matrix->AddEdge(u - 1, v - 1, c);
	list->AddEdge(u - 1, v - 1, c);
}
void Graph::ReadGraphFromFile(const char* fileName)
{
	char inputString[MAXSIZE];			//temp input string
	int inputInt, edgeOne, edgeTwo;		//temp input int
	float inputWeight;					//temp input float
	ifstream infile(fileName);
	if (!infile)								//case invalid file name
	{
		cout << "Error with file" << endl;
		exit(-1);
	}
	for (int j = 0; j < 3; j++)
	{
		infile.getline(inputString, MAXSIZE);
		CheckInputVaildInt(inputString);
		inputInt = atoi(inputString);
		if (j == 0)
		{					//case it is the first line of file
			SetNumOfVertex(inputInt);
		}
		else								//case second/third line 
		{
			if ((inputInt <= GetNumOfVertex()) && (inputInt > -1))
			{
				if (j == 1)				//case it is line two
				{
					SetStartingVertex(inputInt);
				}
				else					//case it is line three
				{
					SetDestinationVertex(inputInt);
				}
			}
			else
			{
				cout << "invalid input" << endl;
				exit(1);
			}
		}
	}
	SetList(new AdjacencyList(GetNumOfVertex()));
	SetMatrix(new AdjacencyMatrix(GetNumOfVertex()));
	while (!infile.eof())    //looping file reading
	{
		if (!infile.good())
		{
			cout << "Error reading" << endl;
			exit(-1);
		}
		infile.getline(inputString, MAXSIZE, ' ');		//get first edge in three
		if (infile.eof())
			break;
		CheckInputVaildInt(inputString);
		edgeOne = atoi(inputString);
		infile.getline(inputString, MAXSIZE, ' ');		//get second edge in three
		CheckInputVaildInt(inputString);
		edgeTwo = atoi(inputString);
		infile.getline(inputString, MAXSIZE);			//get row weight
		CheckInputVaildFloat(inputString);
		inputWeight = atof(inputString);
		AddEdge(edgeOne, edgeTwo, inputWeight);
	}
	infile.close();
}
void Graph::CheckInputVaildInt(char* toCheck)
{
	if (strcmp(toCheck, "") == 0)     // case empty string
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	int i = 0;
	while (toCheck[i] != 0)
	{
		if ((toCheck[i] != ' ') && (!isdigit(toCheck[i])))	//case invalid num of vertecs
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		i++;
	}
}
void Graph::CheckInputVaildFloat(char* toCheck)
{
	int i = 0;
	while (toCheck[i] != 0)
	{
		if ((toCheck[i] != ' ') && (!isdigit(toCheck[i])) && (toCheck[i] != '.')) //case invalid float format
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		i++;
	}
}
void Graph::Init()
{
	if (!distances)
		distances = new float[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
	{
		distances[i] = INFINITY;
	}
	distances[startingVertex - 1] = 0;
}
void Graph::MatrixDijkstraHeap()
{
	Pair* arr = new Pair[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
	{
		arr[i].SetData(i);
		arr[i].SetKey(INFINITY);
	}
	arr[startingVertex - 1].SetKey(0);
	heap H(arr, numOfVertex);
	Init();
	while (!H.IsEmpty())
	{
		Pair u(H.DeleteMin());
		List* adjList = list->GetAdjList(u.GetData());
		Node* v = adjList->GetHead();
		while (v)
		{
			int vName = v->GetData();
			int uName = u.GetData();
			float u_v_weight = v->Getweight(), newWeight = distances[uName] + u_v_weight;
			if (distances[vName] > newWeight)
			{
				distances[vName] = newWeight;
				H.DecreaseKey(H.GetPlace(vName), newWeight);
			}
			v = v->GetNext();
		}
	}
	cout << "Matrix Dijkstra heap " << distances[destinationVertex - 1] << endl;
	delete[] arr;
}
void Graph::AdjacencyDijkstraHeap()
{
	Pair* arr = new Pair[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
	{
		arr[i].SetData(i);
		arr[i].SetKey(INFINITY);
	}
	arr[startingVertex - 1].SetKey(0);
	heap H(arr, numOfVertex);
	Init();
	while (!H.IsEmpty())
	{
		Pair u(H.DeleteMin());
		List* adjList = matrix->GetAdjList(u.GetData());
		Node* v = adjList->GetHead();
		while (v)
		{
			int vName = v->GetData();
			int uName = u.GetData();
			float u_v_weight = v->Getweight(), newWeight = distances[uName] + u_v_weight;
			if (distances[vName] > newWeight)
			{
				distances[vName] = newWeight;
				H.DecreaseKey(H.GetPlace(vName), newWeight);
			}
			v = v->GetNext();
		}
		delete adjList;
	}
	if (distances[destinationVertex - 1] == INFINITY)
	{
		cout << "No Route" << endl;
		exit(1);
	}
	cout << "Adjacency Dijkstra heap " << distances[destinationVertex - 1] << endl;
	delete[] arr;
}
void Graph::AdjacencyDijkstraArray()
{
	ArrayQueue Q(numOfVertex);
	Q.SetPairArrKey(startingVertex - 1, 0);
	Init();
	while (!Q.IsEmpty())
	{
		Pair u(Q.DeleteMin());
		List* adjList = list->GetAdjList(u.GetData());
		Node* v = adjList->GetHead();
		while (v)
		{
			int vName = v->GetData();
			int uName = u.GetData();
			float u_v_weight = v->Getweight(), newWeight = distances[uName] + u_v_weight;
			if (distances[vName] > newWeight)
			{
				distances[vName] = newWeight;
				Q.DecreaseKey(Q.GetPlace(vName), newWeight);
			}
			v = v->GetNext();
		}
		Q.UpdateMin();
	}
	cout << "Adjacency Dijkstra array " << distances[destinationVertex - 1] << endl;
}
void Graph::MatrixDijkstraArray()
{
	ArrayQueue Q(numOfVertex);
	Q.SetPairArrKey(startingVertex - 1, 0);
	Init();
	while (!Q.IsEmpty())
	{
		Pair u(Q.DeleteMin());
		List* adjList = matrix->GetAdjList(u.GetData());
		Node* v = adjList->GetHead();
		while (v)
		{
			int vName = v->GetData();
			int uName = u.GetData();
			float u_v_weight = v->Getweight(), newWeight = distances[uName] + u_v_weight;
			if (distances[vName] > newWeight)
			{
				distances[vName] = newWeight;
				Q.DecreaseKey(Q.GetPlace(vName), newWeight);
			}
			v = v->GetNext();
		}
		Q.UpdateMin();
	}
	cout << "Matrix Dijkstra array " << distances[destinationVertex - 1] << endl;
}
void Graph::MatrixBellmanFord()
{
	Init();
	for (int i = 0; i < numOfVertex - 1; i++)
	{
		for (int u = 0; u < numOfVertex; u++)
		{
			List* adjList = matrix->GetAdjList(u);
			Node* v = adjList->GetHead();
			while (v)
			{
				Relax(u, v->GetData(), v->Getweight());
				v = v->GetNext();
			}
		}
	}
	for (int u = 0; u < numOfVertex; u++)
	{
		List* adjList = matrix->GetAdjList(u);
		Node* v = adjList->GetHead();
		while (v)
		{
			if (Relax(u, v->GetData(), v->Getweight()) == true)
				cout << "there's a negative cycle in graph" << endl;
			v = v->GetNext();
		}	
	}
	cout << "Matrix Bellman Ford " << distances[destinationVertex - 1] << endl;
}
void Graph::AdjacencyBellmanFord()
{
	Init();
	for (int i = 0; i < numOfVertex - 1; i++)
	{
		for (int u = 0; u < numOfVertex; u++)
		{
			List* adjList = list->GetAdjList(u);
			Node* v = adjList->GetHead();
			while (v)
			{
				Relax(u, v->GetData(), v->Getweight());
				v = v->GetNext();
			}
		}
	}
	for (int u = 0; u < numOfVertex; u++)
	{
		List* adjList = matrix->GetAdjList(u);
		Node* v = adjList->GetHead();
		while (v)
		{
			if (Relax(u, v->GetData(), v->Getweight()) == true)
				cout << "there's a negative cycle in graph" << endl;
			v = v->GetNext();
		}
	}
	cout << "Adjacency Bellman Ford " << distances[destinationVertex - 1] << endl;
}
bool Graph::Relax(int u, int v, float c)
{
	if (distances[v] > distances[u] + c)
	{
		distances[v] = distances[u] + c;
		return true;
	}
	return false;
}