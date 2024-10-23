public class merge {
    static void merge(int[] array, int l, int m, int r) {
        int nl = m - l + 1;
        int nr = r - m;

        int[] larr = new int[nl];
        int[] rarr = new int[nr];

        for (int i = 0; i < nl; i++)
            larr[i] = array[l + i];

        for (int j = 0; j < nr; j++)
            rarr[j] = array[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < nl && j < nr) {
            if (larr[i] <= rarr[j]) {
                array[k] = larr[i];
                i++;
            } else {
                array[k] = rarr[j];
                j++;
            }
            k++;
        }
        while (i < nl) {
            array[k] = larr[i];
            i++;
            k++;
        }
        while (j < nr) {
            array[k] = rarr[j];
            j++;
            k++;
        }
    }

    static void mergeSort(int[] array, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);
            merge(array, l, m, r);
        }
    }

}
