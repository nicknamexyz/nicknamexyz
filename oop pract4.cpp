/*Write a C++ program that creates an output file, writes information to it, closes the file, open
  it again as an input file and read the information from the file.*/



#include<iostream>
#include<fstream>
using namespace std;

class test
{
public:
	void writedata();
	void readdata();
};
void test::writedata() {
    fstream fp;
    string input;

    // Open the file in output mode (write mode)
    fp.open("abc.txt", ios::out);

    // Prompt the user to enter a line of text and stop when the user inputs a period (.)
    cout << "Enter text to write to the file (end input with a dot '.' at the end):\n";
     cin.ignore();   // Clear the newline character left by previous cin
    getline(cin, input);  // Read an entire line of input from the user

    // Write the input to the file
    fp << input;

    // Close the file
    fp.close();
}
void test::readdata()
{
	fstream fp;
	char ch;
	fp.open("abc.txt",ios::in);  //open file for reading
ch=fp.get();
while(!fp.eof())
{
cout<<ch;
ch=fp.get(); 
}
fp.close();
}
int main()
{
  test ob;
  int ch;
  do
  {
   cout<<"\n1.Write\n2.Read";
   cout<<"\nEnter your choice= ";
   cin>>ch;
   switch(ch)
   {
    case 1:
	ob.writedata();
    break;
    case 2:
	ob.readdata();
    break;
   }
  }while(ch<3);
}


Output 
1.Write 
2.Read 
Enter your choice= 1 
xyz 
. 
1.Write 
2.Read 
Enter your choice= 2 
xyz 
1.Write 
2.Read 
Enter your choice=

