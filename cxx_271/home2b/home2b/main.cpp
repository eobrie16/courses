// ***********************************************
// Main.cpp
// ***********************************************
#include <iostream>
using namespace std;
#include "vendingItems.h"

int main()
{
    int quantities[] = {2, 1, 20, 20, 15, 15, 15, 10, 20, 20};
    int prices[]     = {65, 65, 85, 95, 70, 50, 65, 85, 70, 65};
    char *names[]    = {"M&Ms", "Baby Ruth", "Peanuts",    "Gum", "Pretzels",
        "Chips","Licorice",  "Milk Duds",  "Butter Finger", "Fritos"};

    VendingItems stuff;
    int num = stuff.getNumItems();
    Item tempItem;

    for (int i=0; i < num; i++)
    {
        tempItem.setName(names[i]);
        tempItem.setPrice(prices[i]);
        tempItem.setInventory(quantities[i]);
        stuff.setItem(tempItem, i);
    }
    if (stuff.buyItem("M&Ms")) cout << "Bought M&Ms" << endl;
    if (stuff.buyItem("M&Ms")) cout << "Bought M&Ms" << endl;
    if (stuff.buyItem("M&Ms")) cout << "Bought M&Ms" << endl;
    if (stuff.buyItem("Baby Ruth")) cout << "Bought Baby Ruth" << endl;
    if (stuff.buyItem("Baby Ruth")) cout << "Bought Baby Ruth" << endl;
    if (stuff.buyItem("Gum"))  cout << "Bought Gum"  << endl;
    if (stuff.buyItem("Gum"))  cout << "Bought Gum"  << endl;
    if (stuff.buyItem("Gum"))  cout << "Bought Gum"  << endl;
    if (stuff.buyItem("Cashews")) cout << "Bought Cashews" << endl;

    for (int i=0; i < num; i++)
    {
        tempItem = stuff.getItem(i);
        cout <<"Item("<< i << ") = " ;
        tempItem.output();
        cout << endl;
    }

}