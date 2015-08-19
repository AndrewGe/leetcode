There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
public:
   double fms(int A[], int m, int B[], int n, int k){
         //recursively half the search lenth
        if (m>n) {return fms(B,n,A,m,k);}
         
        if (m==0) { return B[k-1];}
        if (k==1) { return min(A[0],B[0]);}
        int pa = min(k/2,m);
        int pb = k-pa;
        if (A[pa-1]<=B[pb-1]) {return fms(A+pa,m-pa,B,n,k-pa);} // all elements before A+Pa are less than the kth one, thus, can be cut
        return fms(A,m,B+pb,n-pb,k-pb);  // all elements before B+, are less than the kth one, thus, cut
    }
 
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = m + n;
        if(total%2==1){
            return fms(A,m,B,n,total/2+1);
        }else{
            return (fms(A,m,B,n,total/2)+fms(A,m,B,n,total/2+1))/2;
        }
         
    }
    
    
    /*
    double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int i=0, j=0, median = m+n;
    double prev=0, last=0;

    if(median<2)
    {
        if (m == 0 && n == 0) return 0;
        if (m==1) return A[0];
        else return B[0];
    }

    while ( (i+j) <= (median/2) )
    {
        prev = last;
        if (i >= m) //如果A中的元素已经用完，直接取B数组
        {
            last=B[j];
            j++;
        }
        else if (j>=n) //同上
        {
            last = A[i];
            i++;
        }
        else if (A[i]<B[j]) //取A[i] 和 B[j] 中较小的
        {
            last = A[i];
            i++;
        }
        else
        {
            last=B[j];
            j++;
        }
    }

    if ((median & 1) == 0) //偶数个
        return (prev + last) / 2.0;
    else //奇数个
        return last;
}
    
    */
    
};
