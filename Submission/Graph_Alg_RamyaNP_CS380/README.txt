All the algorithms take the number of vertices and edges as input. You also must input each edge in the for 0 1 [an edge from V0 to V1]

The adjecency matrix will be con structed from this. 
[All algorithms construct and use and adjecency matrix (int**)]
The algorithms implemented are:

1.) Welsh Powell:
	Takes an undirected unweighted graph as input.

2.) Fleury's Algorithm:
	Takes an undirected unweighted graph as input.[you dont have to input a new graph, it will use the same graph as welsh-powell]

3.) Max Bipartite Matching:
	Takes a directed unweighted bipartite graph as input. 
	It outputs the total number of vertices on the LHS that can be matched
	for example:
		if the number of vertices is 3, and there are 2 edges from V0 to V1 and from V0 to V2, the vertices in the LHS would be V0, and the maximum matching would be 1[1 of the vertices on the LHS can be matched with any vertice on the RHS]
[This is very akin to job matching and draws heavily on that]

4.)Boruvka's MST:
	Takes a directed weighted graph as input. 
	Outputs the edges included in the MST and the total weight of the MST


5.)Reverese Delete MST:
	Takes a directed weighted graph as input. 
	Outputs the edges included in the MST and the total weight of the MST

6.)Tarjan's Algorithm to find Strongly Connected Components:
	Takes a directed weighted graph as input. 
	Outputs the different Stronglly connected components [each component is seperated by \n and each vertice in the component is seperated by a comma]
	
7.)Solution to Chinese Postman Problem:
	Takes Undirected Weighted graph as input.
	Outputs the minimum cost to travel the graph [it finds the shortest path or circuitry that visits every edge of the graph at least once and its cost.]


	