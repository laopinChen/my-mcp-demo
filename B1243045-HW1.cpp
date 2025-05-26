//B1243045���~�a
//HW1 
#include<iostream>
using namespace std;
int main(){
	int n=0;
	cout<<"input value:";
	cin>>n;
	int i = 0; 
	int j = (n+1)/2;
	printf("\n");
	int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
	for(int num=1;num<=n*n;num++){
		//cout<<"i:"<<i<<" j:"<<j<<" num:"<<num<<"n:"<<n<<endl;
		if (num % n == 1){
        	i++;
        }else{
        	i--;
			j--;
		}
		if(i == 0){
			i = n;
		}
		if(j == 0){
			j = n;
		}
		matrix[i-1][j-1] = num;
	}
	for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            printf("%2d ", matrix[p][q]);
        }
        printf("\n");
    }
	system("pause");
	return 0;
}

