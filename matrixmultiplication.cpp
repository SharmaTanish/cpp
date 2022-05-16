#include <iostream>
using namespace std;

int** bruteApproach(int** arr, int sr, int er, int sc, int ec){//need 4 more parameters for 2nd matrix
    if(sr==er && sc==ec){
        int** temp=new int*[1];
        // temp[0]=new int[1];
        temp[0][0]=arr[sr][sc]*arr[sr][sc];
        return temp;
    }


    //calculations of 8 multiplications (subproblems)
    int** a = bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    int** b = bruteApproach(arr,sr/2,er,sc,h(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    // bruteApproach(arr,sr,(er/2)-1,sc,(ec/2)-1);
    



    //calculating output matrix subparts
    int** c11=matrixAdd(a,b);




    //calculating output matrix using subparts

}

int main(){
    
    int n;
    cin >> n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int** out = bruteApproach(arr,0,n-1,0,n-1);
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << out[i][j] << " ";
        }
        cout << '\n';
    }
}























/*  FOR 2X2 MATRIX MULTIPLICATION ONLY (Direct without recursion)!!

#include<iostream>
using namespace std;


void insert(int x[2][2])
{
	int val;
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			cin>>val;
			x[i][j]=val;
		}
	}
}

void strassenMatrix (int a[2][2],int b[2][2], int c[2][2])
{
	int A11=a[0][0];
	int A12=a[0][1];
	int A21=a[1][0];
	int A22=a[1][1];
	
	int B11=b[0][0];
	int B12=b[0][1];
	int B21=b[1][0];
	int B22=b[1][1];
	
	
	int P1 = (A11+ A22)*(B11+B22); 
	int P2 = (A21 + A22) * B11;
	int P3 = A11 * (B12 - B22); 
	int P4 = A22 * (B21 - B11); 
	int P5 = (A11 + A12) * B22; 
	int P6 = (A21 - A11) * (B11 + B12);
	int P7 = (A12 - A22) * (B21 + B22); 

	int C11 = P1 + P4 - P5 + P7;
	int C12 = P3 + P5; 
	int C21 = P2 + P4; 
	int C22 = P1 + P3 - P2 + P6; 

	c[0][0]=C11;
	c[0][1]=C12;
	c[1][0]=C21;
	c[1][1]=C22;
	
	cout<<"\n";
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	int a[2][2],b[2][2],c[2][2];

	//insert values in the matrix a
	cout<<"\n a: \n";
	insert(a);
	//insert values in the matrix a
	cout<<"\n b: \n";
	insert(b);
	
	strassenMatrix (a,b,c);
    return 0;
}

*/