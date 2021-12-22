int partition (int arr[], int low, int high)
// {
//     int pivot = arr[high];    // pivot
//     int i = (low - 1);  // Index of smaller element
 
//     for (int j = low; j <= high- 1; j++)
//     {
//         // If current element is smaller than or equal to pivot
//         if (arr[j] <= pivot)
//         {
//             i++;    // increment index of smaller element

//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
   

//     int temp = arr[i+1];
//     arr[i+1] = arr[high];
//     arr[high] = temp;

//     return (i + 1);
// }