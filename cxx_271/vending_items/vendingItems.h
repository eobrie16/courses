// ****************************************
// VendingItems.h
// ****************************************
class Item
{    
public:
// Make sure your constructors initialize your data.
// itemPrice and itemQuantity can be set to 0
// The default constructor should set itemName to "unknown"
    Item();
    Item(char name[]);

// The following setXxx methods allow you to set the appropriate
// variables
    void  setName( char name[]);      // sets itemName
    void  setPrice(int price);        // sets itemPrice
    void  setInventory(int quantity); // sets itemQuantity

// buyItem will reduce the quantity
    bool  buyItem();

// This routine returns "true" if name matches the characters
// in itemName.  Note that name can be a subset of itemName as
// long as all of the first characters in itemName match name
    bool  matchName(char name[]);

// print to cout the contents of the item.  This routine should be
// called in generating the output shown below:
    void  output();

private:
    static const int NAME_SIZE = 20;
    char itemName[NAME_SIZE];
    int itemQuantity;
    int itemPrice; // in pennies
};

class VendingItems
{
public:
// get the index of the item that matches the passed in name.  
// This routine should use the matchName method in the Item class
    int  getItemIndex(char name[]);

// This routine allows the entry at "index" to be replaced by
// the passed in Item class (entry)
    void setItem (Item entry, int index);

// This routine returns the Item class at "index"
    Item getItem (int index);

// Buy an item with the name of "selection"
    bool buyItem(char selection[]);

// returns total number of Items in the vending machine
    int  getNumItems();
    
private:
    static const int NUM_ITEMS = 10;

    Item itemList[NUM_ITEMS];
};

