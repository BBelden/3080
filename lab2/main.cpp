/*
 This lab is due at 11:59pm November 4, 2013
 Submit the source code using the turnin program.
 Professor is pettey
 code is lab2
 
 For this lab, you will calculate the shortes path between two nodes using Dijkstra's algorithm.
 Notes:
 There will be no more than 6 nodes in the graph.
 The maximum weight on any arc is 10, so we will represent infinity as 100.
 The program should first ask for the number of nodes, then ask for the start node, then ask for the end node, and finally ask for the modified adjacency matrix. The nodes will be numbered 0 to n-1 where n is the number of nodes in the graph (to make it easier to program).
 The program should use one 2D array (adjacency matrix) and four 1D arrays (d, s, f, and one for the path).
 To make life easier, the path array mentioned in the previous bullet can be created by traversing the path backwards through the s array, and then the program can print the path array backwards so that the path is actually printed forwards (how's that for a confusing sentence!)
 
 Sample run
 
 Please input the number of nodes 6
 Please input the start node 0
 Please input the end node 5
 Please input the modified adjacency matrix:
100  3    8    4    100  10
3    100  100  6    100  100
8    100  100  100  7    100
4    6    100  100  1    3
100  100  7    1    100  1
10   100  100  3    1    100
 
 The length of the path from 0 to 5 is 6
 The path is 0 3 4 5
*/

#include <iostream>

int main(int argc, const char * argv[])
{
    const int MAX_SIZE = 10;
    int nodes = 0, start=0, end=0, current=0, value=0, path=0;
    int adjMatrix[MAX_SIZE][MAX_SIZE]={0};
    int sArray[MAX_SIZE]={0};
    int fArray[MAX_SIZE]={0};
    int dArray[MAX_SIZE]={100};
    int pathArray[MAX_SIZE]={0};
    bool visitedArray[MAX_SIZE]={0};
    
    std::cout << "Please input the number of nodes: " << std::endl;
    std::cin >> nodes;
    if (nodes < 1)
        return -1;
    std::cout << "Please input the start node: " << std::endl;
    std::cin >> start;
    std::cout << "Please input the end node: " << std::endl;
    std::cin >> end;
    std::cout << "Please input the modified adjacency matrix: " << std::endl;
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            std::cin >> adjMatrix[i][j];
    
    // prep the for loop
    for (int i = 0; i < nodes; i++)
        sArray[i]={start};
    fArray[0] = start;
    current = start;
    visitedArray[current]=1;
    for (int i=0; i < nodes; i++)
        dArray[i] = adjMatrix[current][i];

    for (int i=0; i < nodes; i++)
    {
        // add current node to f
        fArray[i] = current;
        
        // input work array for comparison
        for (int j=0; j<nodes; j++)
            workArray[j] = adjMatrix[current][j]+dArray[current];
        
        // compare work array with d, if work is less than d at any index,
        // set d to work at that index, update s if w < d
        for (int j=0; j<nodes; j++)
        {
            if (workArray[j] < dArray[j])
            {
                sArray[j] = current;
                dArray[j] = workArray[j];
            } // end if
        } // end for
    
        // find the lowest value in d in an index not already in f,
        // update current
        value = 100;
        for (int j=0; j<nodes; j++)
        {
            if (dArray[j] < value && visitedArray[j] == 0)
            {
                value = dArray[j];
                current = j;
            } // end if
        } // end for
        
        // mark index as visited
        visitedArray[current]=1;
   
    } // end for
    
    path = end;
    pathArray[0] = path;
    int i = 1;
    while (sArray[path] != start)
    {
        pathArray[i] = sArray[path];
        path = sArray[path];
        i++;
    }
    pathArray[i] = sArray[path];

    std::cout << "\nThe length of the path from " << start << " to " << end << " is " << dArray[end] << "\nThe path is ";
    while (i >= 0)
    {
        std::cout << pathArray[i] << " ";
        i--;
    }
    std::cout << std::endl << std::endl;

    return 0;
} // end main


/*
0   3   5   100 8   1   100 100
3   0   2   100 100 100 1   100
5   2   0   1   100 100 100 2
100 100 1   0   4   100 100 100
8   100 100 4   0   6   100 1
1   100 100 100 6   0   5   100
100 1   100 100 100 5   0   1
100 100 2   100 1   100 1   0
 */
