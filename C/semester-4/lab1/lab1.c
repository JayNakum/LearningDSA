#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    char filePath[100], c;

    printf("Enter the filepath to open: \n");
    scanf("%s", filePath);

    fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file :(\n");
        exit(0);
    }

    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}
