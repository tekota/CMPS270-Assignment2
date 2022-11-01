#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph{
    public:
        Graph(const vector<int> &start, const vector<int> &end){
            if (start.size() != end.size()){  //throws error if start and end are not of the same size
                throw invalid_argument("The vectors are of different lengths and cannot be used to create a graph");
            }
            for (int i = 0; i < start.size(); i++){ 
                adj[start[i]].push_back(end[i]);
            }
        }

        // numOutgoing function
        // requires: a node which is found in the table
        // effects: returns the number of outgoing edges from the node
        int numOutgoing(const int node) const{
            if (adj.find(node) == adj.end()){    // this checks if the node is present in the graph or not
                throw invalid_argument("This node id isn't found in the graph"); //throws an error when not found
            }
            return adj.at(node).size();
        }


        // hasCycle function
        // requires: a node in the graph, a vector of the already visited nodes, and a vector of nodes in the current path
        // effects: returns a vector of the first cycle
        vector<int> hasCycle(int node, vector<bool> &visited, vector<int> &path){
            visited[node] = true;
            vector<int> list;
            path.push_back(node);
            for (int i = 0; i < adj[node].size(); i++)   //for every node that it adjacent to that node
            {
                if (!visited[adj[node][i]])  
                {
                    list = hasCycle(adj[node][i], visited, path);
                }
                else
                {
                    for (int j = 0; j < path.size(); j++)   //for every node in the path
                    {
                        if (path[j] == adj[node][i]) //if the node is in path
                        {
                            for (int k = j; k < path.size(); k++)   //for each node in path after the node in path
                            {
                                list.push_back(path[k]); //add to list
                            }
                            list.push_back(adj[node][i]); //add the node in path to list
                            return list;
                        }
                    }
                }
            }
            path.pop_back();    //remove node from path
            return list;    
        }


        // &adjacent function
        // requires: a node which is found in the table
        // effects: returns a list of all the nodes that are adjacent to the node
        const vector<int> &adjacent(const int node) const{
            if (adj.find(node) == adj.end()){        //checks if the node is in the graph
                throw invalid_argument("This node id isn't found in the graph");
            }
            return adj.at(node);
        }

    private:
        map<int, vector<int> > adj;

 };


int main(){
    // vector<int> start = {0,0,0,4,4,3}; 
    // vector<int> end = {1,2,3,3,1,1};

    vector<int> start, end;
    start.push_back(0);
    start.push_back(0);
    start.push_back(0);
    start.push_back(4);
    start.push_back(4);
    start.push_back(3);

    end.push_back(1);
    end.push_back(2);
    end.push_back(3);
    end.push_back(3);
    end.push_back(1);
    end.push_back(1);


    Graph g(start, end);

    cout<<"numOutgoing tester: "<<endl;
    cout << g.numOutgoing(0) << endl;       //3
    cout << g.numOutgoing(0) << endl;       //3
    cout << g.numOutgoing(0) << endl;       //3
    cout << g.numOutgoing(4) << endl;       //2
    cout << g.numOutgoing(4) << endl;       //2
    cout << g.numOutgoing(3) << endl;       //1

    cout<<"adjacent tester: "<<endl;
    cout << g.adjacent(0)[0] << endl;       //1
    cout << g.adjacent(0)[1] << endl;       //2
    cout << g.adjacent(0)[2] << endl;       //3
    cout << g.adjacent(4)[0] << endl;       //3
    cout << g.adjacent(4)[1] << endl;       //1
    cout << g.adjacent(3)[0] << endl;       //1


    vector<bool> visited(9);
    vector<int> path;
    vector<int> list = g.hasCycle(1, visited, path);


    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;   

     
    return 0;
}
