#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define M 3
#define N 3
ofstream f1;

string dictiwords[100000],combiwords[20000];
string properwords[10000];
string bos;
// Let the given dictionary be following
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};

int dictlen=0,userlen=0,properlen=0,combilen=0;

void bsearch()
{
    int n = dictlen;
    int i=0,j=0;
    int low,high,mid;

    for(j=0;j<combilen;++j)
    {
        low = 0;
        high = n-1;
        mid = (low+high)/2;

        while(low<=high)
        {

            if(dictiwords[mid].compare(combiwords[j])==0)
            {
                properwords[properlen]=dictiwords[mid];
                ++properlen;
                cout<<"pro "<<properwords[properlen-1];
            }
            if(dictiwords[mid].compare(combiwords[j])>0)
                high = mid-1;
            else
                low = mid+1;
        }
    }

    for(j=0;j<properlen;++j)
        cout<<properwords[j]<<endl;
    cout<<"ths is printed";
}

// A recursive function to print all words present on boggle
void findWordsUtil(char boggle[M][N], bool visited[M][N], int i,
				int j, string &str)
{
	// Mark current cell as visited and append current character
	// to str
	visited[i][j] = true;
	str = str + boggle[i][j];

	// If str is present in dictionary, then print it
		//cout << str << endl;


    f1<<str<< endl;

	// Traverse 8 adjacent cells of boggle[i][j]
	for (int row=i-1; row<=i+1 && row<M; row++)
	for (int col=j-1; col<=j+1 && col<N; col++)
		if (row>=0 && col>=0 && !visited[row][col])
		findWordsUtil(boggle,visited, row, col, str);

	// Erase current character from string and mark visited
	// of current cell as false
	str.erase(str.length()-1);
	visited[i][j] = false;
}

// Prints all words present in dictionary.
void findWords(char boggle[M][N])
{
	// Mark all characters as not visited
	bool visited[M][N] = {{false}};

	// Initialize current string
	string str = "";

	// Consider every character and look for all words
	// starting with this character
	for (int i=0; i<M; i++)
	for (int j=0; j<N; j++)
			findWordsUtil(boggle, visited, i, j, str);
}

/*void user_input()
{
	string userin[100];
	cout<<" enter the words you can make ";
	cin>>userin[i];
	i++;

}*/

void start()
{
	double duration=0;
	string userin[100];
	int i=0;
	clock_t tstart = clock();
	cout<<" enter the words you can make ";
	while(duration<10)
	{
	    cin>>userin[i];
        userlen++;

    /* Your algorithm here */

    duration = ( clock() - tstart ) / (double) CLOCKS_PER_SEC;

	//if(((int)duration%10.000)==0)
    //	cout<< duration <<'\n';
	}



}

int main ()
{

  int i=0;
  string line,line2;

  ifstream myfile ("ren.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
		dictiwords[i]=line;
	//cout<<a[i]<<endl;
	++dictlen;
    }
    myfile.close();
  }
  else cout << "Unable to open file";

//function to generate combinations
	char boggle[M][N] = {{'G','I','Z'},
						{'U','E','K'},
						{'Q','S','E'}};
	for(int j=0;j<M;j++)
    {
        for(int k=0;k<N;k++)
        {
            cout<<"    "<<boggle[j][k]<<"   ";
        }
        cout<<"\n";
    }

//storing combinations
    f1.open("DFGH.txt",ios::app);
    ifstream myfile2 ("DFGH.txt");
    i=0;
    if (myfile2.is_open())
    {
        while(getline(myfile2,line2))
        {
            //cout<<line2<<'\n';
            combiwords[i]=line2;
            //cout<<b[i]<<endl;
            ++combilen;
        }
        myfile2.close();
    }

	//cout << "Following words of dictionary are present\n";
	findWords(boggle);
	f1.close();
start();
cout<<dictlen<<"   "<<combilen;
bsearch();


  return 0;
}

