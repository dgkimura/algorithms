#define MAX(a, b) (a) < (b) ? (b) : (a)

int
ComputeMaximumSubArray(const int *SubArray,
                       const int Length) {
    int i, overall_max = 0, current_max = 0;

    for (i = 0; i < Length; i++) {
        current_max = MAX(SubArray[i], current_max + SubArray[i]);
        overall_max = MAX(current_max, overall_max);
    }

    return overall_max;
}
