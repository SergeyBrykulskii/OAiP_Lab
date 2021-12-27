// laba7 task8


#include <iostream>

using namespace std;

//void qs(int* a, int first, int last) {
//    if (first < last) {
//        int left = first, right = last, middle = a[(left + right) / 2];
//        do {
//            while (a[left] < middle)
//                left++;
//            while (a[right] > middle)
//                right--;
//            if (left <= right) {
//                int temp = a[left];
//                a[left] = a[right];
//                a[right] = temp;
//                left++;
//                right--;
//            } 
//        } while (left < right);
//        qs(a, first, right);
//        qs(a, left, last);
//    }
//    
//}

//void qs(int* a, int first, int last) {
//    if (first < last) {
//        int left = first, right = last, middle = a[(left + right) / 2];
//        do {
//            while (a[left] < middle)
//                left++;
//            while (a[right] > middle)
//                right--;
//            if (left <= right) {
//                int temp = a[left];
//                a[left] = a[right];
//                a[right] = temp;
//                right--;
//                left++;
//            }
//        } while (left < right);
//
//        qs(a, first, right);
//        qs(a, left, last);
//    }
//}

void qs(int* a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        } while (left < right);
        qs(a, first, right);
        qs(a, left, last);
    }

}
int main()
{
    int x[9] = { 12, 3, 5, 1, 45, 43, 67, 0, -2 };

    qs(x, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout << x[i] << " ";
    }

    return 0;
}
