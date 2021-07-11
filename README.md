This project was created as a part of Algorithms course.

The goal of the project is to implemenet a number of solutions to the problem of minimal paths from  a single origin to a single destination.

Each graph is implemented in 2 ways:
1. Adjacency Matrix
2. Adjacency List

There are three solutions for the problem:
1. Dijkstra’s shortest path algorithm using Minimum Priority Queue
2. Dijkstra’s shortest path algorithm using an unsorted array Priority Queue
3. Bellman–Ford algorithm

The input is a file (passed by command line arguments) that contains the number of vertices in the graph, the origin vertex, and the destination vertex.
The rest of the file contains a list of edges:
<origin vertex>, <destination vertex>, <the weight of the edge>

The program prints the weight of the shortest path between the origin vertex to the destintaion vertex.
