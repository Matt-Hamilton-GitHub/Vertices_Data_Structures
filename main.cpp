/*
Write a function that creates a dynamic sequential structure.
The structure contains the squares of N consecutive integers where N is a function parameter.
The integers range from one to N.
The function separates the squares into four sets with these restrictions:
1) the sums of the squares in the four sets are equal or nearly equal and
2) the function partitions squares for large values of N. The function returns the four partitions
*/

#include <iostream>
using namespace std;

struct squares
{
    int N;
    int arr[100];
};

void find_Indices(int, int *);//int npartition(int,int *);   // Function declaration

int main()
{
    struct squares s;
    int i,j,k,l,n1,n2,n3,n4;
    int a1[100],a2[100],a3[100],a4[100],a[100],b[100];

    cout << "Enter N : ";
    cin >> s.N;

    cout << "Enter "<< s.N <<" Numbers : ";
    for(i=0;i<s.N;i++)
    {
        cin>> s.arr[i];
        s.arr[i]=(s.arr[i]*s.arr[i]);
    }
    find_Indices(s.N,s.arr);

	system("pause");
    return 0;
}

void find_Indices(int n,int arr[100])
{
    int sum[100], k;
    int index_1, index_2, index_3, index;


    // calculating prefix sum from
    // 1 to i for each i.
    for (int i = 1, k = 0; i <= n; i++)
        sum[i] = sum[i-1] + arr[k++];

    long long ans = -(1e15);
    index_1 = index_2 = index_3 = -1;

    // iterating the loop from 0 to n
    // for all possibilities.
    for (int l = 0; l <= n; l++) {
        int index = 0;
        long long vmin = (1e15);

        // Here, we recalling the best
        // segment to end at position i.
        for (int r = l; r <= n; r++) {

            // taking the minimal prefix
            // sum from 0 to i inclusive.
            if (sum[r] < vmin) {
                vmin = sum[r];
                index = r;
            }

            // calculating the indices.
            if (sum[l] + sum[r] - vmin > ans)
            {
                ans = sum[l] + sum[r] - vmin;
                index_1 = l;
                index_2 = index;
                index_3 = r;
            }
        }
    }

    // Required indices.
    cout <<index_1<<index_2<<index_3;
}
