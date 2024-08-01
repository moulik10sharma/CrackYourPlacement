class Solution {
public:
    int segregate(int arr[], int size) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] <= 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
        return j;
    }
    int findMissingPositive(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            int x = abs(arr[i]);
            if (x - 1 < size && arr[x - 1] > 0)
                arr[x - 1] = -arr[x - 1];
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] > 0)
                return i + 1;
        }
        return size + 1;
    }
    int missingNumber(int arr[], int size) {
        int shift = segregate(arr, size);
        int arr2Size = size - shift;
        int arr2[arr2Size];
        for (int i = 0; i < arr2Size; i++) {
            arr2[i] = arr[i + shift];
        }
        return findMissingPositive(arr2, arr2Size);
    }
};