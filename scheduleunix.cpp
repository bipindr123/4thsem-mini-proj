//Operating Systems project by Aakash Rai(1ds15cs009) and Bipin D R(1ds15cs029)
//Implementation of cpu scheduling algorithms
#include<iostream>
#include<stdio.h>

using namespace std;

class cpuschedule
{
    int n,Bu[20];
    float Twt,Awt,A[10],Wt[10],tt[10],ttt,w;
public:
    //Getting the No of processes & burst time
    void Getdata();
    //Shortest job First Algorithm
    void Sjf();
    //Shortest job First Algorithm with Preemption
    void SjfP();
    //Shortest job First Algorithm with NonPreemption
    void SjfNp();
    //Round Robin Algorithm
    void RoundRobin();
    //Priority Algorithm
    void Priority();
};


//structure of proceses
struct process{
    int arrival,priority,burst,wait,start,flag,completion,id;
}p[10],q[10],temp;

//p is the processes
//q is the ready queue

int top=-1,rear=0;

//puts given process into queue
void push(int i)
{
    ++top;
    q[top]=p[i];
}

//removes process from queue
void pop(int i)
{
    temp=q[rear];
    q[rear]=q[i];
    q[i]=temp;
    ++rear;
}

void welcome_screen()
{


    cout<<"                                  _              _       _ _             	\n";
    cout<<"                                 | |            | |     | (_)            	\n";
    cout<<"    ___ _ __  _   _      ___  ___| |__   ___  __| |_   _| |_ _ __   __ _ 	\n";
    cout<<"   / __| '_ | | | |    / __| / __| '_ | / _ || _` | | | | | | '_ | / _` |	\n";
    cout<<"  | (__| |_) | |_| |   |  __ | (__| | | |  __/ (_| | |_| | | | | | | (_| |	\n";
    cout<<"   |___| .__/ |__,_|    |___/|___|_| |_||___||__,_||__,_|_|_|_| |_||__, |	\n";
    cout<<"       | |                      (_) | | |                           __/ |	\n";
    cout<<"       |_| __ _  __ _  ___  _ __ _| |_| |__  _ __ ___  ___         |___/ 	\n";
    cout<<"          / _` |/ _` |/ _ || '__| | __| '_ || '_ ` _ || __|              	\n";
    cout<<"         | (_| | (_| | (_) | |  | | |_| | | | | | | | |__ |              	\n";
    cout<<"          |__,_||__, || __/|_|  |_||__|_| |_|_| |_| |_|___/              	\n";
    cout<<"                 __/ |                                                   	\n";
    cout<<"                |___/                                                    	\n";

    cout<<"\n\n\t\t\tOPERATING SYSTEMS PROJECT BY AKASH RAI AND BIPIN D R \t\t\t";
}


int prio()
{
    int i,n,total=0,max,b,j,k,wavg=0;
    float avg=0.0;
    top=-1,rear=0;

    //taking input
    cout<<"enter no of process ";
    cin>>n;
    for(i=0;i<n;++i)
    {
        cout<<"enter arrival, priority burst ";
        cin>>p[i].arrival>>p[i].priority>>p[i].burst;
    }

    //displaying the input
    cout<<"arrival priority burst\n";
    for(i=0;i<n;++i)
    {
        cout<<p[i].arrival<<"\t"<<p[i].priority<<"\t"<<p[i].burst<<"\n";
        total+=p[i].burst;
        p[i].wait=0;
        p[i].id=i+1;
    }


    for(i=0;i<=total;++i)
    {
        cout<<"\ntime: "<<i<<"\n";

        //puts the process into queue if it has arrived
        for(k=0;k<n;++k)
        {
            if(p[k].arrival==i)
            {
                push(k);

                cout<<"\n P"<<p[k].id<<" has arrived \n";
            }
        }

        //no elements in queue
        if(top<rear)
            continue;

        //only one element
        if(rear==top)
        {
            max=rear;
        }
        else
        {
            max = rear;
            for(j=rear+1;j<=top;++j)
            {
                //if the priority is equal, chooses on arrival time
                if(q[j].priority==q[max].priority&&q[j].arrival<q[max].arrival)
                    max=j;

                //choosing the max priority
                if(q[j].priority<q[max].priority)
                    max=j;

            }
        }

        //if the processes is completed
        if(q[max].burst==0)
        {
            q[max].completion = i;
            cout<<"\ncompletion : P"<<q[max].id<<" has completed in "<<q[max].completion<<"seconds";
            pop(max);
        }


        //the process is executed
        --q[max].burst;
        if(q[max].burst>=0)
            cout<<"\n P"<<q[max].id<<" is executing and remaining burst time is "<<q[max].burst;

        //increments waiting time for all processes that are not executed
        for(b=rear;b<=top;++b)
        {
            if(b!=max)
                ++q[b].wait;
        }



    }


    //calculation of waiting and throughput
    for(i=0;i<n;++i)
    {
        avg = avg + (q[i].completion-q[i].arrival);
        wavg = wavg+ q[i].wait;
    }
    cout<<"\n===============================================================================================\n";
    cout<<"\nthroughput time: "<<avg<<" avg throughput time: "<<avg/(float)n;
    cout<<"\n wait time "<<wavg<<" avg wait time "<<(float)wavg/(float)n<<endl;
    return 0;
}


int nprio()
{
    int i,n,total=0,max,b,j,k,wavg=0;
    float avg=0.0;
    top=-1,rear=0;

    //taking input
    cout<<"enter no of process ";
    cin>>n;
    for(i=0;i<n;++i)
    {
        cout<<"enter arrival, priority burst ";
        cin>>p[i].arrival>>p[i].priority>>p[i].burst;
    }

    //displaying the input
    cout<<"\narrival priority burst\n";
    for(i=0;i<n;++i)
    {
        cout<<p[i].arrival<<"   \t   "<<p[i].priority<<"   \t   "<<p[i].burst<<"\n";
        total+=p[i].burst;
        p[i].flag=0;
        p[i].id=i+1;
    }


    for(i=0;i<=total;++i)
    {
        cout<<"\ntime: "<<i<<"\n";

        //puts the process into queue if it has arrived
        for(k=0;k<n;++k)
        {
            if(p[k].arrival<=i&&p[k].flag==0)
            {
                push(k);
                p[k].flag=1;
                cout<<"\n P"<<p[k].id<<" has arrrived \n";
            }
        }

        //no elements in queue
        if(top<rear)
            continue;

        //only one element
        if(rear==top)
        {
            max=rear;
        }
        else
        {
            max = rear;
            for(j=rear+1;j<=top;++j)
            {
                //if the priority is equal, chooses on arrival time
                if(q[j].priority==q[max].priority&&q[j].arrival<q[max].arrival)
                    max=j;

                //choosing the max priority
                if(q[j].priority<q[max].priority)
                {
                    max=j;
                }
            }
        }

        //if the processes is completed
        q[max].start=i; //stores the start time
        i=i+q[max].burst - 1; //updates the time
        q[max].completion=i+1; //stores completion time

        cout<<"\n P"<<q[max].id<<" has completed execution at "<<i+1<<" seconds ";
        pop(max);	//process is removed from queue

    }



    for(i=0;i<n;++i)
    {
        avg = avg + (q[i].completion-q[i].arrival);
        wavg = wavg+ (q[i].start-q[i].arrival);
    }
    cout<<"\n==========================================================================\n";
    cout<<"\nthroughput time: "<<avg<<" avg throughput time: "<<avg/(float)n;
    cout<<"\n wait time "<<wavg<<" avg wait time "<<(float)wavg/(float)n<<endl;
    return 0;
}

// Implementation file for Cpu scheduling
//Getting no of processes and Burst time
void cpuschedule::Getdata()
{
    int i;
    cout<<"Enter the no of processes:\n";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter The BurstTime for Process p"<<i<<"= ";
        cin>>Bu[i];
    }
}

//First come First served Algorithm
int fcfs()
{
    int i,n,total=0,max,b,j,k,wavg=0;
    float avg=0.0;
    top=-1,rear=0;

    //taking input
    cout<<"enter no of process ";
    cin>>n;
    for(i=0;i<n;++i)
    {
        cout<<"enter arrival, priority burst ";
        cin>>p[i].arrival>>p[i].priority>>p[i].burst;
    }

    //displaying the input
    cout<<"\narrival priority burst\n";
    for(i=0;i<n;++i)
    {
        cout<<p[i].arrival<<"   \t   "<<p[i].priority<<"   \t   "<<p[i].burst<<"\n";
        total+=p[i].burst;
        p[i].flag=0;
        p[i].id=i+1;
    }


    for(i=0;i<=total;++i)
    {
        cout<<"\ntime: "<<i<<"\n";

        //puts the process into queue if it has arrived
        for(k=0;k<n;++k)
        {
            if(p[k].arrival<=i&&p[k].flag==0)
            {
                push(k);
                p[k].flag=1;
                cout<<"\n P"<<p[k].id<<" has arrrived \n";
            }
        }

        //no elements in queue
        if(top<rear)
            continue;

        //only one element
        if(rear==top)
        {
            max=rear;
        }
        else
        {
            max = rear;
            for(j=rear+1;j<=top;++j)
            {
                //if the arrival is equal, chooses on burst time
                if(q[j].arrival==q[max].arrival&&q[j].burst<q[max].burst)
                    max=j;

                //choosing the max priority
                if(q[j].arrival<q[max].arrival)
                {
                    max=j;
                }
            }
        }

        //if the processes is completed
        q[max].start=i; //stores the start time
        i=i+q[max].burst - 1; //updates the time
        q[max].completion=i+1; //stores completion time

        cout<<"\n P"<<q[max].id<<" has completed execution at "<<i+1<<" seconds ";
        pop(max);	//process is removed from queue

    }



    for(i=0;i<n;++i)
    {
        avg = avg + (q[i].completion-q[i].arrival);
        wavg = wavg+ (q[i].start-q[i].arrival);
    }
    cout<<"\n==========================================================================\n";
    cout<<"\nthroughput time: "<<avg<<" avg throughput time: "<<avg/(float)n;
    cout<<"\n wait time "<<wavg<<" avg wait time "<<(float)wavg/(float)n<<endl;
    return 0;
}

//Shortest job First Algorithm
void cpuschedule::Sjf()
{
    int i,j,temp,B[10];
    Twt=0.0;
    for(i=1;i<=n;i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=";
        cout<<B[i];
    }
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
            if(B[j-1]>B[j])
            {
                temp=B[j-1];
                B[j-1]=B[j];
                B[j]=temp;
            }
        }
    }

    Wt[1]=0;
    tt[1]=Bu[1];
    for(i=2;i<=n;i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
        tt[i]= Wt[i]+Bu[i];
    }
    ttt=0.0;
    //calculating Average Waiting Time
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        ttt=ttt+tt[i];
    }
    Awt=Twt/n;
    cout<<"\nTotal Waiting Time="<<Twt;
    cout<<"\nAverage Waiting Time="<<Awt<<" ";
    cout<<"\nTotal Arrival time="<<ttt;
    cout<<"\nAverage Arrival time="<<(ttt/n);
}

//Shortest job First Algorithm with NonPreemption

void cpuschedule::SjfNp()
{
    int i,B[10],Tt=0,temp,j;
    char S[10];
    float A[10],temp1,t;
    Twt=0.0;
    w=0.0;
    for(i=1;i<=n;i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"";
        cout<<B[i];
        S[i]='T';
        Tt=Tt+B[i];
        cout<<"\nEnter the Arrival Time for"<<i<<"th process=";
        cin>>A[i];
    }

    for(i=n;i>=1;i--)
    {
        for(j=3;j<=n;j++)
        {
            if(B[j-1]>B[j])
            {
                temp=B[j-1];
                temp1=A[j-1];
                B[j-1]=B[j];
                A[j-1]=A[j];
                B[j]=temp;
                A[j]=temp1;
            }
        }
    }
    //For the 1st process
    Wt[1]=0;
    w=w+B[1];
    t=w;
    S[1]='F';

    while(w<Tt)
    {
        i=2;
        while(i<=n)
        {
            if(S[i]=='T'&&A[i]<=t)
            {
                Wt[i]=w;
                S[i]='F';
                w=w+B[i];
                t=w;
                i=2;
            }
            else
                i++;
        }
    }

    for(i=1;i<=n;i++)
    {
        tt[i]=Wt[i]+Bu[i]-A[i];
    }

    ttt=0;
    //calculating average waiting Time
    for(i=1;i<=n;i++)
    {
        Twt=Twt+(Wt[i]-A[i]);
        ttt=ttt+tt[i];
    }
    Awt=Twt/n;
    cout<<"\nTotal Waiting Time="<<Twt<<" ";
    cout<<"\nAverage Waiting Time="<<Awt<<" ";
    cout<<"\nTotal Turnaroud Time="<<ttt;
    cout<<"\nAverage Turnaround Time="<<(ttt/n);
}

\

//Shortest job First Algorithm with Preemption
void cpuschedule::SjfP()
{
    int i,j,m,Wt[10],k,B[10],A[10],Tt=0,Wtm[10],temp;
    char S[20],start[20];
    int max=0,Time=0,min;
    float Twt=0.0,Awt;
    for(i=1;i<=n;i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process P"<<i<<"="<<B[i];
        if(B[i]>max)
            max=B[i];
        Wt[i]=0;
        S[i]='T';
        start[i]='F';
        Tt=Tt+B[i];
        cout<<"\nEnter the Arrival Time for"<<i<<"th process=	";
        cin>>A[i];
        if(A[i]>Time)
            Time=A[i];
    }
    int w=0,flag=0,t=0;
    i=1;
    while(t<Time)
    {       w=0;

        if(A[i]<=t && B[i]!=0)
        {
            if(flag==0)
            {
                Wt[i]=Wt[i]+w;
            }
            B[i]=B[i]-1;
            if(B[i]==0)
                S[i]='F';
            start[i]='T';
            t++;
            w=w+1;
            if(S[i]!='F')
            {
                j=1;flag=1;
                while(j<=n && flag!=0)
                {
                    if(S[j]!='F' && B[i]>B[j] && A[j]<=t && i!=j )
                    {
                        flag=0;
                        Wt[i]=Wt[i]-w;
                        i=j;
                    }
                    else
                    {
                        flag=1;
                    }
                    j++;
                }
            }
            else
            {
                i++;
                j=1;
                while(A[j]<=t &&j<=n)
                {
                    if(B[i]>B[j] && S[j]!='F')
                    {
                        flag=0;
                        i=j;
                    }
                    j++;
                }
            }
        }
        else
        if(flag==0)
            i++;
    }

    while(w<Tt)
    {
        min=max+1;
        i=1;
        while(i<=n)
        {
            if(min>B[i] && S[i]=='T')
            {
                min=B[i];
                j=i;
            }
            i++;
        }
        i=j;
        if(w==Time && start[i]=='T')
        {
            w=w+B[i];
            S[i]='F';
        }
        else
        {
            Wt[i]=Wt[i]+w;
            w=w+B[i];
            S[i]='F';
        }
    }
    for(i=1;i<=n;i++)
    {
        Wt[i]=Wt[i]-A[i];
        tt[i]=Wt[i]+Bu[i];
    }
    //Calculating Average Waiting time
    ttt=0.0;
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        ttt=ttt+tt[i];
    }
    Awt=Twt/n;
    cout<<"\nTotal Waiting Time="<<Twt;
    cout<<"\nAverage Waiting Time="<<Awt;
    cout<<"\nTotal Turnaroud Time="<<ttt;
    cout<<"\nAverage Turnaround Time="<<(ttt/n);



}

//Round Robin Algorithm
void cpuschedule::RoundRobin()
{     int count,j,n,time,remain,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d",&n);
    remain=n;
    for(count=0;count<n;count++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d",&time_quantum);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(time=0,count=0;remain!=0;)
    {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0)
        {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(at[count+1]<=time)
            count++;
        else
            count=0;
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}


//Application file for cpu Scheduling
int main()
{
    int ch,cho;
    cpuschedule c;
    welcome_screen();
    do
    {
        cout<<"\nMENU\n";
        cout<<"1.Getting BurstTime\n";
        cout<<"2.FirstComeFirstServed\n";
        cout<<"3.ShortestJobFirst\n";
        cout<<"4.RoundRobin\n";
        cout<<"5.Priority\n";
        cout<<"6.EXIT\n";
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                c.Getdata();
                break;
            case 2:
                cout<<"FIRST COME FIRST SERVED SCHEDULING\n";
                fcfs();
                break;
            case 3:
                cout<<"SHORTEST JOB FIRST SCHEDULING\n";
                do
                {
                    cout<<"\n1.SJF-Normal\n";
                    cout<<"2.SJF-Preemptive\n";
                    cout<<"3.SJF-NonPreemptive\n";
                    cout<<"4.EXIT\n";
                    cout<<"Enter your choice\n";
                    cin>>cho;
                    switch(cho)
                    {
                        case 1:
                            c.Sjf();
                            break;
                        case 2:
                            c.SjfP();
                            break;
                        case 3:
                            c.SjfNp();
                            break;
                        case 4:
                            break;
                    }
                }while(cho<=3);
                break;
            case 4:
                cout<<"ROUND ROBIN SCHEDULING\n";
                c.RoundRobin();
                break;
            case 5:
                cout<<" PRIORITY SCHEDULING\n";
                do
                {
                    cout<<"\n1.Priority preemptive\n";
                    cout<<"2.Priority Non-Preemptive\n";
                    cout<<"4.EXIT\n";
                    cout<<"Enter your choice\n";
                    cin>>cho;
                    switch(cho)
                    {
                        case 1:
                            prio();
                            break;
                        case 2:
                            nprio();
                            break;
                        case 3:
                            break;
                    }
                }while(cho<=2);
                break;

            case 6:
                break;
        }
    }while(ch<=5);
    return 1;
}