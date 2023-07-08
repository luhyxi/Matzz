#include <stdio.h>

int main() {
    char expression[1000];
    int blnc = 0;
    int i = 0;
    scanf("%s", expression);
    
    while (expression[i] != '\0') {
        if (expression[i] == '(') {
            blnc++;
        } else if (expression[i] == ')') {
            blnc--;
            if (blnc < 0) break;
        }
        i++;
    }
    
    if (blnc == 0) {
        printf("correct\n");
    } else {
        printf("incorrect\n");   
    }
    return 0;
}
