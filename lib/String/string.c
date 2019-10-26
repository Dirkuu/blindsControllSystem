#ifndef STRING
#define STRING


char * floatToString(float variable) {
    static char result[0];
    sprintf(result, "%f", variable);
    return result;
}

void println(char *arrayOfChars) {
    for (char i = 0; i < sizeof(*arrayOfChars); ++i) {
        printf(&arrayOfChars[i]);
    }

    printf("\n");

    return;
}


#endif