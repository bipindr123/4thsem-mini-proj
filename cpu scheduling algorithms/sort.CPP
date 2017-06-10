/*************************************************************
ADA MINI-PROJECT: Visualization of Sorting Algorithms in C++
--------------------------------------------------------------
Group Members			USN
--------------------------------------------------------------
Dhruthi Prakash			1DS15IS026
Jonathan Balasingh		1DS15IS033
Kinshuk Sood			1DS15IS040
MM Varsha			1DS15IS044
Nischal Tonthanahal		1DS15IS061
**************************************************************/

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
int xmax,ymax;
class graphics
{
	int gd,gm,xasp,yasp;
public:
	graphics()
	{
		gd=DETECT;
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		getaspectratio(&xasp,&yasp);
		cleardevice();
		setaspectratio(xasp,yasp);
		xmax=getmaxx();
		ymax=getmaxy();

	}
	~graphics()
	{
		clrscr();
		cleardevice();
		closegraph();
		nosound();
	}


}G;

class array
{
	int *a;
	int n;
public:
	array(int size)
	{
		a=new int[size];
		n=size;
		fill();
		clrscr();
		cleardevice();
		graph(a);
		delay(1000);
	}
	~array()
	{
		cleardevice();
		graph(a);
		delete a;
		nosound();
	}
	void swap(int&a,int&b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	void graph(int a[],int low=0,int high=ymax);
	void fill();

//SORTING ALGORITHMS
	void bubblesort();

	void selectionsort();

	int partition(int low,int high);
	void quicksort(int low,int high);

	void merge(int low,int mid,int high);
	void mergesort(int low,int high);

	void countsort(int exp);
	void radixsort();

	int is_sorted();
	void shuffle();
	void bogosort();
//PENDING
	void insertionsort();
	void heapsort();
	void stdsort();
	void stdstablesort();
	void shellsort();
	void cocktailshakersort();
	void gnomesort();
	void bitonicsort();

};
void array::graph(int a[],int low,int high)
{
	if(high==ymax)
		high=n;
	int i,j,pos=0,width,height;
	width=(xmax)/n;
	//cleardevice();
	for(i=0;i<n;i++,pos+=width)
	{
		if(i<low||i>high)
		{
			delay(100/n);
			continue;
		}
		height=ymax-a[i];
//		if(getpixel(pos+width/2,height)!=WHITE);
		{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			bar3d(pos,0,pos+width,ymax,0,1);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL,1+(a[i]%14));
			bar3d(pos,height,pos+width,ymax,0,1);
		}
	}
	//delay(100);
	if(kbhit())
		if(getch()==27)
			exit(0);
}
void array::fill()
{
	randomize();
	for(int i=0;i<n;i++)
	{
		a[i]=random(ymax);
	}
	shuffle();
}

void array::bubblesort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			sound(a[j]);
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
			graph(a,0,n-i-1);
		}
		//graph(a);
	}
}
void array::selectionsort()
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		sound(a[i]);
		min=i;
		for(j=i+1;j<n;j++)
		{
		    if(a[j]<a[min])
			min=j;
		}
		swap(a[min],a[i]);
		graph(a,i);
		//delay(100);
	}
}
int array::partition(int low,int high)
{
	int p,i,j,temp;
	p=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		sound(a[i]);
		while((a[i]<=p)&&(i<high))
		    i++;
		while((a[j]>p)&&(j>=low))
		    j--;
		if(i<j)
		{
		    swap(a[i],a[j]);
		    graph(a,low,high);
		}
		else
		{
		    swap(a[low],a[j]);
		    graph(a,low,high);
		    return j;
		}

	}
}
void array::quicksort(int low,int high)
{
	int s;
	if(low<high)
	{
		s=partition(low,high);
		quicksort(low,s-1);
		quicksort(s+1,high);
	}
}
void array::merge(int low,int mid,int high)
{
	int i,j,k;
	int*b=new int[n];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
		graph(b,low,high);
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
		graph(b,low,high);
	}
	while(j<=high)
	{
		b[k++]=a[j++];
		graph(b,low,high);
	}
	for(i=low;i<=high;i++)
	{
		a[i]=b[i];
		graph(a,low,high);
		sound(a[i]);
	}
	nosound();
}
void array::mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
		graph(a,low,high);
	}
}
void array::countsort(int exp)
{
	int *b=new int[n];
	int i,d,count[10]={0,0,0,0,0,0,0,0,0,0};
	for(i=0;i<n;i++)
		count[(a[i]/exp)%10]++;
	for(i=1;i<10;i++)
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--)
	{
		d=(a[i]/exp)%10;
//		sound(d);
		b[count[d]-1]=a[i];
//		graph(b);
		count[d]--;
	}
	for(i=0;i<n;i++)
		a[i]=b[i];
}
void array::radixsort()
{
	int i;
	int m=a[0];
	for(i=1;i<n;i++)
		if(a[i]>m)
			m=a[i];
	for(int exp=1;m/exp>0;exp*=10)
	{
		countsort(exp);
		graph(a);
	}
}
int array::is_sorted()
{
	for(int i=n-1;i>=1;i--)
		if(a[i]<a[i-1])
			return 0;
	return 1;
}
void array::shuffle()
{
	int i,k;
	randomize();
	for(i=0;i<n;i++)
	{
		sound(a[i]);
		k=random(n);
		swap(a[i],a[k]);
	}
}
void array::bogosort()
{
	while(!is_sorted())
	{
		shuffle();
		graph(a);
	}
}
void main()
{
	int n,ch=1;
	array *a;
	while(ch!=0)
	{
		clrscr();
		cleardevice();
		cout<<"Select Sorting Algorithm"<<endl
			<<"1.Bubble Sort"<<endl
			<<"2.Selection Sort"<<endl
			<<"3.Quick Sort"<<endl
			<<"4.Merge Sort"<<endl
			<<"5.Radix Sort"<<endl
			<<"6.Bogo Sort"<<endl
			<<"0.Exit"<<endl
			<<"\nEnter choice: ";
		cin>>ch;
		if(ch)
		{
			do
			{
				cout<<"Enter no. of elements(1-"<<ymax<<") ";
				cin>>n;
				if(n<=0||n>ymax)
					cout<<"Invalid size\n";
			}while(n<=0||n>ymax);
			a=new array(n);
		}
		switch(ch)
		{
			case 1:a->bubblesort();
				break;
			case 2:a->selectionsort();
				break;
			case 3:a->quicksort(0,n-1);
				break;
			case 4:a->mergesort(0,n-1);
				break;
			case 5:a->radixsort();
				break;
			case 6:a->bogosort();
				break;
			case 0:cout<<"Exiting...\n";
				break;
			default:cout<<"Invalid choice\n";
		}
		if(ch)
		{
			delete a;
			getch();
		}
	}
}
