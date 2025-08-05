int main() 
{
    int n;
    scanf("%d", &n);
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;
            
            int layer = top;
            if (left < layer) layer = left;
            if (bottom < layer) layer = bottom;
            if (right < layer) layer = right;

            int val = n - layer;
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}