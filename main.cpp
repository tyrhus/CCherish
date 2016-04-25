#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "./misc/trim.cpp"
#include "./src/CTerm.cpp"
#include "./src/CTermTree.cpp"
#include "./src/CPriority.cpp"
#include "./src/CPriorityHeap.cpp"

using namespace std;

struct termRecord
{
  string    termKey;
  float     termPriority;
};

termRecord*  parseRecord(termRecord* rec, string entry)
{
  transform(entry.begin(), entry.end(), entry.begin(), ::tolower);
  trim(entry);

  return rec;
}

int main(int argc, char const *argv[]) {

  string  k, p;
  termRecord *entry = new termRecord;
  ifstream myfile (argv[1]);

  //CTerm *DTree = new CTerm("mariana gedrova");
  AVLtree<string> DTree;
  CPriorityHeap<string> PTree(11);

  //DTree->remove(DTree, "root");
  while ( getline(myfile,k,',') )
    {     getline (myfile,p);
          trim(k); trim(p);
          transform(k.begin(), k.end(), k.begin(), ::tolower);

      entry->termKey      = k;
      entry->termPriority = ::atof(p.c_str());

      //CPriority<string> temp(entry->termKey, entry->termPriority);

      PTree.insert(entry->termKey, entry->termPriority);

      DTree.insert(entry->termKey);
      cout << endl;

      cout << entry->termKey << " with a priority of " << entry->termPriority << endl;
      DTree.printInOrder();
      //CTerm *left = DTree->findMin(DTree);
      //cout << "Minimal node: " << left->key << endl;
    }


    //in_order_traversal(DTree);
    cout << endl;


    int min = 0;
    while (min < 10)
    {
      string delKey = DTree.findMin();
      cout << min << ": " << delKey << endl;
      DTree.printInOrder();
      cout << endl;
      DTree.deleteKey(delKey);

      //DTree->remove(DTree, left->key);
      min++;
    }





  myfile.close();


  return 0;
}
