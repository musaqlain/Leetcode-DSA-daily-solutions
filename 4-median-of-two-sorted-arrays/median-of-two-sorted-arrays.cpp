class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i=0, j=0;
        int n1=a.size(), n2=b.size();
        int n=(n1+n2);
        int ind2=n/2;
        int ind1=ind2-1;
        int ind1el=-1, ind2el=-1;
        int count=0;

        while (i<n1 && j<n2) {
            if (a[i]<b[j]) {
                if (count==ind1) ind1el=a[i];
                if (count==ind2) ind2el=a[i];
                count++, i++;
            } else {
                if (count==ind1) ind1el=b[j];
                if (count==ind2) ind2el=b[j];
                count++, j++;
            }
        }

        while (i<n1) {
            if (count==ind1) ind1el=a[i];
            if (count==ind2) ind2el=a[i];
            count++, i++;
        }

        while (j<n2) {
            if (count==ind1) ind1el=b[j];
            if (count==ind2) ind2el=b[j];
            count++, j++;
        }

        if (n%2 == 1) return ind2el;

        return (double)((double)(ind1el+ind2el))/2.0;
    }
};