#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int rect_width = 640, rect_height = 480;
    int w = 1, h = 1;
    scanf("%d; %d", &w, &h);
    bool val1 = rect_width % w != 0;
    bool val2 = rect_height % h != 0;
    printf("%d", w * val1 + h * val2);

    // здесь продолжайте программу

    return 0;
}