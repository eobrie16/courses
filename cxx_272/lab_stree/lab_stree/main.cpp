#include <iostream>
#include "d_stree_new.h"
using namespace std;

int main()
{
    char input_char = '\0';
    string data = "qgpzbroiaznhvsdc";
    stree<char> demoStree;

//assigning data into stree
    int data_size = data.size();
    for(int i = 0; i < data_size; ++i)
        demoStree.insert(data[i]);

    cout << "TREE: " << data << endl;
    demoStree.displayTree(1);

    cout << endl << "enter letter or '\\' to quit : ";
    cin >> input_char;

    while(input_char != '\\')
    {
        cout << "Subtree size : " << demoStree.countInSubtree(input_char) 
            << endl;

        cout << endl << "enter letter or '\\' to quit : ";
        cin >> input_char;
    }

    cout << endl;
}