#include <stdio.h>

int main() {
    // Declare variables
    FILE* infile;
    // Start nlines at 1 to account for no \n on last line
    int nlines = 1;
    char c;
    char header[50];
    float sumbel = 0, sumusa = 0, avgbel = 0, avgusa = 0;

    // open file and store in infile pointer
    infile = fopen("gasprices.txt", "r");
    if (!infile) {
        perror("fopen");
        return 1;
    }

    // count \n characters, results in number of lines - 1 (no \n on last line)
    for (c = getc(infile); c != EOF; c = getc(infile)) {
        if (c == '\n') {
            nlines++;
        }
    }
    rewind(infile);

    // declare arrays with nlines size
    float belarray[nlines], usarray[nlines];

    // fgets reads the header line and sets the infile pointer to line 2
    if (fgets(header, 50, infile) == NULL) {
        perror("fgets");
        return 1;
    }

    // iterate from second line to final line, store values in arrays 
    //and calculate sums for each country
    for (int i = 0; i < (nlines - 1); i++) {
        if (fscanf(infile, "%f %f%*[^\n]\n", &belarray[i], &usarray[i]) != 2) {
            perror("fscanf");
            return 1;
        }
        printf("Price %d: Belgium: $%1.2f, USA: $%1.2f\n", i + 1, belarray[i], usarray[i]);
        sumbel = sumbel + belarray[i];
        sumusa = sumusa + usarray[i];
    }

    // calculate and print average prices for each country
    avgbel = sumbel / (nlines - 1);
    printf("\nThe average price in Belgium is: $%1.2f\n", avgbel);

    avgusa = sumusa / (nlines - 1);
    printf("The average price in the USA is: $%1.2f\n", avgusa);
}