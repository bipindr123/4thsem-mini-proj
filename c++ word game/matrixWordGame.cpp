//ADA PROJECT BY BIPIN D R AND AYUSH GOYAL
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
string properwords[10000],userwords[20],userin[100],temp[10000];
string bos;

int dictlen=0,userlen=0,properlen=0,combilen=0,ulen=0,templen=0;

void singleout()
{
	int flag=0;
	int j,k;
	for(j=0;j<templen;++j)
	{
		for(k=j+1;k<templen;++k)
		{
			if(temp[j].compare(temp[k])==0)
				flag=1;
		}
		if(flag==0)
		{
			properwords[properlen]=temp[j];
			++properlen;
		}
		flag=0;
	}
}


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
        	mid = (low+high)/2;
            if(dictiwords[mid].compare(combiwords[j])==0)
            {
                temp[templen]=dictiwords[mid];
                ++templen;
                break;
            }
            if(dictiwords[mid].compare(combiwords[j])>0)
                high = mid-1;
            else
                low = mid+1;
        }
    }
    
	singleout();
	cout<<"\nThe words that could be formed are: \n";
    for(j=0;j<properlen;++j)
    	cout<<properwords[j]<<" , ";
}

void lsearch()
{
	int n = properlen;
    int i=0,j=0;
    for(i=0;i<userlen;i++)
    {
        for(j=0;j<n;j++)
        {
            if(properwords[j].compare(userin[i])==0)
            {
                userwords[ulen]=properwords[j];
                ulen++;
            }
        }
    }

	cout<<"\n\n\n You have entered: \n";
    for(j=0;j<userlen;++j)
    {
    	cout<<userin[j]<<" ,";
    }
    cout<<"\n\nYOUR SCORE IS "<<ulen<<" OUT OF "<<properlen;
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


void start()
{
	double duration=0;
	clock_t tstart = clock();
	cout<<" enter the words you can make ";
	while(duration<30)
	{
	    cin>>userin[userlen];
        userlen++;

    /* Your algorithm here */

    duration = ( clock() - tstart ) / (double) CLOCKS_PER_SEC;

	}

}

int main ()
{

  int i=0,j=0;
  string line,line2;
  
  unsigned seed= time(0);
  srand(seed);

	cout<<"\n\n \t\t ADA PROJECT BY BIPIN D R AND AYUSH GOYAL\n\n ";
  ifstream myfile ("small.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    	if(line.size()>2)
		{
			dictiwords[dictlen]=line;
			++dictlen;
		}
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  f1.open("DFGH.txt");

//function to generate combinations
//	char boggle[M][N] = {{'g','i','z'},
//						{'u','e','k'},
//						{'q','s','e'}};

	char boggle[3][3];
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
				boggle[i][j] = 97 + rand()%26;
		}
	}
	findWords(boggle);
	cout<<endl;
	for(int j=0;j<M;j++)
    {
        for(int k=0;k<N;k++)
        {
            cout<<"    "<<boggle[j][k]<<"   ";
        }
        cout<<"\n";
    }

//storing combinations
    ifstream myfile2 ("DFGH.txt");
    i=0;
    if (myfile2.is_open())
    {
        while(getline(myfile2,line2))
        {
            //cout<<line2<<'\n';
            combiwords[combilen]=line2;
            ++combilen;
        }
        myfile2.close();
    }

	//cout << "Following words of dictionary are present\n";
	f1.close();
start();
bsearch();
lsearch();


  return 0;
}
