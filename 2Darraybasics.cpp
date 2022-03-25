#include <iostream>

using namespace std;

int main()
{
    int studentMarks[3][3]={10,20,30,40,50,60,70,80,90};
        
        
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            cout<<studentMarks[i][j];
            cout<<"\n";
            
        }
    }
    
    cout<<"*********\n";
    
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
            cout<<*(studentMarks[i]+j);
            cout<<"\n";
            
        }
    }
    
    cout<<"*********\n";
    
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
            cout<<*(*(studentMarks+i)+j);
            cout<<"\n";
        }
    }
    
    

    return 0;
}


















//////////////////////////////////////////////////////////////


















/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int studentMarks[3][3]={10,20,30,40,50,60,70,80,90};
    int studentMarks1DArray[9]={10,20,30,40,50,60,70,80,90};
        
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
			cout<<"i="<<i<<", Address: "<<&(studentMarks[i][j])<<", Value: "<<studentMarks[i][j];   
		    cout<<"\n";
            
        }
    }
    
    cout<<"*********\n";
    
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
            cout<<*(studentMarks[i]+j);
            cout<<"\n";
            
        }
    }
    
    cout<<"*********\n";
    
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
            cout<<*(*(studentMarks+i)+j);
            cout<<"\n";
        }
    }
    
    
	cout<<"*********\n";
    
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            
            cout<<*(studentMarks+i+j);
            cout<<"\n";
        }
    }
    
    
	cout<<"*********\n";
    
    for (int i=0;i<=8;i++)
    {
        
		cout<<"i="<<i<<", Address: "<<(studentMarks1DArray+i)<<", Value: "<<*(studentMarks1DArray+i);   
        cout<<"\n";
    }
    
    return 0;
}













//////////////////////////////////////////////////////////////////











