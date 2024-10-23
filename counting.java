import java.util.Arrays;

public class counting {
    static int[] countingSort(int[] array) {
        int max_value = Arrays.stream(array).max().orElse(Integer.MAX_VALUE);
        int[] count = new int[max_value + 1];
        int[] output = new int[array.length];

        for (int num : array) {
            count[num]++;
        }

        for (int i = 1; i <= max_value; i++) {
            count[i] += count[i - 1];
        }

        for (int i = array.length - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        return output; // Retornar el array ordenado
    }

}
