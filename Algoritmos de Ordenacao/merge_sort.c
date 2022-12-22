void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2; // defines the current array in 2 parts .
        merge_sort(A, start, mid);   // sort the 1st part of array .
        merge_sort(A, mid + 1, end); // sort the 2nd part of array.

        // merge the both parts by comparing elements of both the parts.
        merge(A, start, mid, end);
    }
}