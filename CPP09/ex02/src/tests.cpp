// // Insertion sort in C++

// #include <iostream>
// using namespace std;

// // Function to print an array
// void printArray(int array[], int size) {
//   for (int i = 0; i < size; i++) {
//     cout << array[i] << " ";
//   }
//   cout << endl;
// }

// void insertionSort(int array[], int size) {
//   for (int step = 1; step < size; step++) {
//     int key = array[step];
//     int j = step - 1;

//     // Compare key with each element on the left of it until an element smaller than
//     // it is found.
//     // For descending insertOrder, change key<array[j] to key>array[j].
//     while (key < array[j] && j >= 0) {
//       array[j + 1] = array[j];
//       --j;
//     }
//     array[j + 1] = key;
//   }
// }

// // Driver code
// int main() {
//   int data[] = {9, 5, 1, 4, 3};
//   int size = sizeof(data) / sizeof(data[0]);
//   insertionSort(data, size);
//   cout << "Sorted array in ascending insertOrder:\n";
//   printArray(data, size);
// }

// Jacobsthal ------------------------------
// int	Jacobsthal(int n)
// {
// 	if (n == 0)
// 		return (0);
// 	if (n == 1)
// 		return (1);
// 	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
// }

// static int	jacobsthal(int n)
// {
// 	int dp[n + 1];

// 	dp[0] = 0;
// 	dp[1] = 1;

// 	for (int i = 2; i <= n; i++)
// 		dp[i] = dp[i - 1] + 2 * dp[i - 2];
// 	return (dp[n]);
// }

// int main(void)
// {
// 	int n = 5;
// 	std::cout << Jacobsthal(n) << std::endl;
// 	return (0);
// }

