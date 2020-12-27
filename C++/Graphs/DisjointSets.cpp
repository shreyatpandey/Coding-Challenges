//Taken from Tushar Roy's explanation
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<memory>

class Node
{
 public:
  long data;
  int rank; 
  Node*parent;
    
};

class DisjointSet
{
private:
    std::unordered_map<long, Node*> map ;
    
 public:
  /**
     * Create a set with only one element.
     */
     void makeSet(long data) 
     {
        Node* node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        map.emplace(data, node);
    }
    /*
     Combines two sets together to one.
     Does union by rank
     @return true if data1 and data2 are in different set before union else false.
    */
    bool Union(long data1, long data2) 
    {
        Node *node1 = map[data1];
        Node *node2 = map[data2];

        Node*parent1 = findSet(node1);
        Node*parent2 = findSet(node2);

        //if they are part of same set do nothing
        if (parent1->data == parent2->data) {
            return false;
        }

        //else whoever's rank is higher becomes parent of other
        if (parent1->rank >= parent2->rank) 
        {
            //increment rank only if both sets have same rank
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        } 
        else 
        {
            parent1->parent = parent2;
        }
        return true;
    }
    /**
     * Finds the representative of this set
     */
     long findSet(long data) 
     {
        return findSet(map[data])->data;
    }
    /**
     * Find the representative recursively and does path
     * compression as well.
     */
     Node* findSet(Node*node) 
     {
        Node* parent = node->parent;
        if (parent == node) 
        {
            return parent;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }
    
};

int main()
{
    std::unique_ptr<DisjointSet>ds (new DisjointSet) ;
    ds->makeSet(1) ;
    ds->makeSet(2);
    ds->makeSet(3);
    ds->makeSet(4);
    ds->makeSet(5);
    ds->makeSet(6);
    ds->makeSet(7);

    ds->Union(1, 2);
    ds->Union(2, 3);
    ds->Union(4, 5);
    ds->Union(6, 7);
    ds->Union(5, 6);
    ds->Union(3, 7);
    
    std::cout<<ds->findSet(1)<<std::endl;
    std::cout<<ds->findSet(2)<<std::endl;
    std::cout<<ds->findSet(3)<<std::endl;
    std::cout<<ds->findSet(4)<<std::endl;
    std::cout<<ds->findSet(5)<<std::endl;
    std::cout<<ds->findSet(6)<<std::endl;
    std::cout<<ds->findSet(7)<<std::endl;
    
    return 0;
}
