//main.cpp: 
#include "MyStream.h"
int main()
{
	char cinput[] = "A big buffer of text";
    int x=23;
    Myout << "Enter integer followed by some text\r\n";
    Myin >> x ;
	Myin >> cinput;
    Myout << "x=" << x ;
    Myout << " Text Entered=" << cinput;
    Myout << "\r\n";

    Myout << "\r\n*****************************\r\n";
    Myout << "    Reading input file one character at a time \r\n";
    Myout << "*****************************\r\n";
    Myifstream in("test.data");
    do
    {
       Myout << (char)in.get() ;        
    }while(in);
// *******************************
    const int BUFF_SIZE = 200;
    char cbuff[BUFF_SIZE+1];   

    Myout << "\r\n*****************************\r\n";
    Myout << "    Reading input file one line at a time \r\n";
    Myout << "*****************************\r\n";

    Myifstream in2("test.data");
    do
    {
       in2.getline(cbuff, BUFF_SIZE) ;  
       if (in2)Myout << (char *)cbuff ;         
    }while(in2);
// *******************************
    
    Myout << "\r\n*****************************\r\n";
    Myout << "    Reading input file one buffer at a time \r\n";
    Myout << "*****************************\r\n";

    Myifstream in3("test.data");
    do
    {
       if (in3.read(cbuff, BUFF_SIZE))
       {
            int nread = in3.gcount();
            if (nread >= 0)
                cbuff[nread]=0;
            Myout << cbuff ;   
       }
    }while(in3);




    Myout << "\r\n*****************************\r\n";
    Myout << "    Testing seekg \r\n";
    Myout << "*****************************\r\n";

    Myifstream in4("test.data");
    in4.seekg(100);
    in4.read(cbuff, BUFF_SIZE);
    int nread4 = in4.gcount();
    cbuff[nread4] = 0;
    Myout << cbuff;


    Myout << "\r\n*****************************\r\n";
    Myout << "    Testing Exceptions on errors \r\n";
    Myout << "*****************************\r\n";
    try
    {
        Myifstream in4("NonExistentantFile");
    }
    catch (MyException & e)
    {
        Myout << "Exception caught: " << e.getError() << "\r\n";
    }

    return 0;    
} 
