#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    unsigned long long current_cases = n;
    int fake_data = 0;

    while (m--) {
        char operation[5];
        unsigned long long value;
        scanf("%s", operation);

        if (strcmp(operation, "Add") == 0) {
            scanf("%llu", &value);
            current_cases += value;
        } else if (strcmp(operation, "Sub") == 0) {
            scanf("%llu", &value);

            if (value > current_cases) {
                fake_data = 1;
            }

            current_cases -= value;
        } else if (strcmp(operation, "Query") == 0) {
            if (fake_data == 1) {
                printf("fake news!\n");
            } else {
                printf("%llu\n", current_cases);
            }
        }
    }

    return 0;
}