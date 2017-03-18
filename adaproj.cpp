#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void user_input()
{
	string b[100];
	cout<<" enter the words you can make ";
}

void start()
{
	double duration=0;
	clock_t tstart = clock();
	while(duration<30)
	{

    /* Your algorithm here */

    duration = ( clock() - tstart ) / (double) CLOCKS_PER_SEC;

	//if(((int)duration%10.000)==0)
    //	cout<< duration <<'\n';
	}
	
	
	
}

int main () {
 string a[10000];
  int i=0;
  string line;
  ifstream myfile ("ren.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
      //if(i<10000)
		//a[i]=line;
	//cout<<a[i]<<endl;
	++i;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
// start();
  
  

  return 0;
}

