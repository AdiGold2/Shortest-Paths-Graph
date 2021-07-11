#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
#define MAXSIZE 128

int main(int argc, char* argv[])
{
	Graph G;
	G.ReadGraphFromFile(argv[1]);

	//*****AdjacencyDijkstraHeap*****//
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.AdjacencyDijkstraHeap();
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile(argv[2]);
	myfile << "Time taken by function AdjacencyDijkstraHeap is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;

	//*****AdjacencyDijkstraArray*****//
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.AdjacencyDijkstraArray();
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function AdjacencyDijkstraArray is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;

	//*****AdjacencyBellmanFord*****//
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.AdjacencyBellmanFord();
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function AdjacencyBellmanFord is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;
	
	//*****MatrixDijkstraHeap*****//
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.MatrixDijkstraHeap();
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function MatrixDijkstraHeap is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;

	//*****MatrixDijkstraArray*****//
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.MatrixDijkstraArray();
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function MatrixDijkstraArray is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;
	
	//*****MatrixBellmanFord*****//
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	G.MatrixBellmanFord();
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function MatrixBellmanFord is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;
	
	return 0;
}