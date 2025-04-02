#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int setCharacter(char character[][3], int errorAcc) {
    char parts[6] = {'o', '_', '_', '|','/','|'};
    if (errorAcc == 1) {
        character[0][1] = parts[errorAcc - 1]; 
        return 1;
    
    };
    if (errorAcc == 2) {
        character[0][0] = parts[errorAcc - 1]; 
        return 1;
        
    }; 
    if (errorAcc == 3) {
        character[0][2] = parts[errorAcc - 1]; 
        return 1;
    
    };
    if (errorAcc == 4) {
        character[1][1] = parts[errorAcc - 1]; 
        return 1;
    
    };
    if (errorAcc == 5) {
        character[2][0] = parts[errorAcc - 1]; 
        return 1;
    
    };
    if (errorAcc == 6) {
        character[2][2] = parts[errorAcc - 1];
        return 1;
    } else {
        return 0;
    }
}

void printCharacter(char character[][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", character[i][j]);
        }        
        printf("\n");
    }
}

void revealSecretChar(char spacingSecretWord[7], char keyWord[7], char revealChar) {
    int i = 0;
    while(i < strlen(keyWord)) {
        if (keyWord[i] == revealChar) {
            spacingSecretWord[i] = keyWord[i];
            i++;
            continue;
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    int isGameEnd = 0;
    char character[3][3] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' ',
    };
    char spacingSecretWord[] = "_______";
    char keyWord[] = "abacaxi";
    int errorAcc = 0;
    while (errorAcc < 7) {
        int isErrorAllChars = 1;
        char charCandidate;
        printf("Escolha uma letra:");
        printf("\n");
        scanf("%c", &charCandidate);
        getchar();
        for (int i = 0; i < strlen(keyWord); i++) {
            if (keyWord[i] == charCandidate) {
                revealSecretChar(spacingSecretWord, keyWord, charCandidate);
                isErrorAllChars = 0;
                break;
            }
        }
        if (isErrorAllChars) {
            errorAcc++; 
            setCharacter(character, errorAcc);
            printCharacter(character);
        }    
        printf("%s", spacingSecretWord);

    }
}