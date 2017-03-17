// ***********************************************
// vendingItems.cpp
// ***********************************************
#include <iostream>
using namespace std;
#include "vendingItems.h"


// Make sure your constructors initialize your data.
// itemPrice and itemQuantity can be set to 0
// The default constructor should set itemName to "unknown"
Item::Item()
{
	strcpy(itemName, "unknown");
    itemQuantity = 0;
    itemPrice = 0;
}
Item::Item(char name[])
{
	strcpy(itemName, name);
	itemQuantity = 0;
	itemPrice = 0;
}


// The following setXxx methods allow you to set the appropriate
// variables
void  Item::setName( char name[])
{
	strcpy(itemName, name);
}
void  Item::setPrice(int price)
{
	itemPrice = price;
}
void  Item::setInventory(int quantity)
{
	itemQuantity = quantity;
}
// buyItem will reduce the quantity
bool  Item::buyItem()
{
	if (itemQuantity > 0)
		itemQuantity--;
	else
		return false;
	return true;
}

// This routine returns "true" if name matches the characters
// in itemName.  Note that name can be a subset of itemName as
// long as all of the first characters in itemName match name
bool  Item::matchName(char name[])
{
	int len = strlen(name);
	for (int i=0; i<len; i++)
	{
		if (name[i] != itemName[i])
			return false;
	}

	return true;
}

// print to cout the contents of the item.  This routine should be
// called in generating the output shown below:
void  Item::output()
{
	cout << itemName << " quantity(" << itemQuantity << ") price(" << itemPrice << ")" << endl;
}


// get the index of the item that matches the passed in name.  
// This routine should use the matchName method in the Item class
int  VendingItems::getItemIndex(char name[])
{
	for (int i=0; i<NUM_ITEMS; i++)
		if (itemList[i].matchName(name))
			return i;

	return -1;
}

// This routine allows the entry at "index" to be replaced by
// the passed in Item class (entry)
void VendingItems::setItem (Item entry, int index)
{
	if (index>=0 && index<NUM_ITEMS)
		itemList[index] = entry;
}

// This routine returns the Item class at "index"
Item VendingItems::getItem (int index)
{
	if (index>=0 && index<NUM_ITEMS)
		return itemList[index];
}

// Buy an item with the name of "selection"
bool VendingItems::buyItem(char selection[])
{
	int index = getItemIndex(selection);
	if (itemList[index].buyItem())
		return true;
	else
		return false;
}

// returns total number of Items in the vending machine
int  VendingItems::getNumItems()
{
        return NUM_ITEMS;
}
