// A simple caesar cipher implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char caesarc(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + shift) % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + shift) % 26 + 'A';
    }
    else {
        return c;
    }
}

char caesard(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' - shift + 26) % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' - shift + 26) % 26 + 'A';
    }
    else {
        return c;
    }
}

int main(int argc, char** argv) {
    FILE* infile;
    FILE* outfile;
    char input[256];
    char output[256];
    int opt;
    int shift = 0;
    int shift_set = 0;
    int mode = 0; // 0 for none, 1 for encrypt, 2 for decrypt
    const char* infile_path = "message.txt";
    const char* outfile_path = "cipher.txt";

    while ((opt = getopt(argc, argv, "s:ed")) != -1) {
        switch (opt) {
        case 's':
            shift = atoi(optarg);
            shift_set = 1;
            break;
        case 'e':
            mode = 1;
            break;
        case 'd':
            mode = 2;
            break;
        case '?':
            fprintf(stderr, "Usage: %s [-s shift] [-e|d (encrypt|decrypt)] [input-file]\n", argv[0]);
            return 1;
        }
    }

    if (!shift_set || mode == 0) {
        fprintf(stderr, "Usage: %s [-s shift] [-e|d (encrypt|decrypt)] [input-file]\n", argv[0]);
        return 1;
    }

    if (optind < argc) {
        infile_path = argv[optind];
    }

    // open files and store in infile/outfile pointers
    infile = fopen(infile_path, "r");
    if (!infile) {
        perror("fopen");
        fclose(infile);
        return 1;
    }
    outfile = fopen(outfile_path, "w");
    if (!outfile) {
        perror("fopen");
        fclose(outfile);
        return 1;
    } 

    // read each line from infile, apply caesar cipher, and write to outfile

    while (fgets(input, sizeof(input), infile)) {
        size_t len = strlen(input);
        for (size_t i = 0; i < len; i++) {
            if (input[i] == '\n') {
                output[i] = '\n';
            } else if (mode == 1) {
                output[i] = caesarc(input[i], shift);
            } else {
                output[i] = caesard(input[i], shift);
            }
        }
        output[len] = '\0';
        fputs(output, outfile);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}