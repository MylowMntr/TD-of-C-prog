#define sizeCarre 3

int carre[sizeCarre][sizeCarre] = 
    {{2,7,6},
    {9,5,1},
    {4,3,8}
};

void isMagic(int carre[sizeCarre][sizeCarre]){
    int i = 0;
    int j = 0;
    if ((carre[i][j] + carre[i][j+1] + carre[i][j+2]) == (carre[i+1][j] + carre[i+1][j+1] + carre[i+1][j+2]) == (carre[i+2][j] + carre[i+2][j+1] + carre[i+2][j+2])){
        printf("Ligne OK");
    };
    if ((carre[i][j] + carre[i+1][j] + carre[i+2][j]) == (carre[i][j+1] + carre[i+1][j+1] + carre[i+2][j+1]) == (carre[i][j+2] + carre[i+1][j+2] + carre[i+2][j+2])){
        printf("Colonne OK");
    };
}

void main(){
    isMagic(carre);
}