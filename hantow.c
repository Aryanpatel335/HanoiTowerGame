#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int peg1[9] = {0, 0,0, 0, 0, 0, 0, 0, 0};
int peg2[9] = {0, 0,0, 0, 0, 0, 0, 0, 0};
int peg3[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void displaypegs(){
    
    printf("\n");
    printf("\n");
    int w;
    // for(w = 8; w>=0; w-- ){
    //     printf("%d %d %d \n", peg1[w],peg2[w],peg3[w]);
    // }
    for(w=8;w>=0;w--){
        switch (peg1[w]){
            case 0:
                printf("             |             ");
                break;      
            case 1:      
                printf("            +|+            ");
                break;      
            case 2:      
                printf("           ++|++           ");
                break;      
            case 3:      
                printf("          +++|+++          ");
                break;      
            case 4:      
                printf("         ++++|++++         ");
                break;      
            case 5:      
                printf("        +++++|+++++        ");
                break;      
            case 6:      
                printf("       ++++++|++++++       ");
                break;      
            case 7:      
                printf("      +++++++|+++++++      ");
                break;      
            case 8:      
                printf("     ++++++++|++++++++     ");
                break;      
            case 9:      
                printf("    +++++++++|+++++++++    ");
                break;
            
        }
        
        
        switch (peg2[w]){
            case 0:
                printf("             |             ");
                break;      
            case 1:      
                printf("            +|+            ");
                break;      
            case 2:      
                printf("           ++|++           ");
                break;      
            case 3:      
                printf("          +++|+++          ");
                break;      
            case 4:      
                printf("         ++++|++++         ");
                break;      
            case 5:      
                printf("        +++++|+++++        ");
                break;      
            case 6:      
                printf("       ++++++|++++++       ");
                break;      
            case 7:      
                printf("      +++++++|+++++++      ");
                break;      
            case 8:      
                printf("     ++++++++|++++++++     ");
                break;      
            case 9:      
                printf("    +++++++++|+++++++++    ");
               
                break;
            
        }
        
        switch (peg3[w]){
            case 0:
                printf("             |             ");
                break;      
            case 1:      
                printf("            +|+            ");
                break;      
            case 2:      
                printf("           ++|++           ");
                break;      
            case 3:      
                printf("          +++|+++          ");
                break;      
            case 4:      
                printf("         ++++|++++         ");
                break;      
            case 5:      
                printf("        +++++|+++++        ");
                break;      
            case 6:      
                printf("       ++++++|++++++       ");
                break;      
            case 7:      
                printf("      +++++++|+++++++      ");
                break;      
            case 8:      
                printf("     ++++++++|++++++++     ");
                break;      
            case 9:      
                printf("    +++++++++|+++++++++    ");
                break;
           
        }
        printf("\n");
        
        
        

    }
    printf("   XXXXXXXXXXXXXXXXXXXXX      XXXXXXXXXXXXXXXXXXXXX      XXXXXXXXXXXXXXXXXXXXX ");
    printf("\n");
}

void move(int pegA[9], int pegB[9]){
    //from peg A to peg B
    int i,j;
    for(i = 0; pegA[i]!=0; i++);
    int temp = pegA[i-1];
    pegA[i-1] = 0;
    

    for(j=0; pegB[j]!=0; j++);
    
    pegB[j] = temp;
    
    displaypegs();
    sleep(1);


}

void hantow(int nod, int beg[9], int end[9], int helper[9]){
     if(nod==1){
        move(beg,end);
        return;
    }
    hantow(nod - 1, beg,helper,end);
    move(beg,end);
    hantow(nod - 1, helper,end,beg);
}

int main(int argc, char* argv[] ){
    if (argc != 2) {
       if(argc == 1){
            printf("Not enough command line arguments \n");
            return 0;
            
        }
     printf("Too many command line arguments\n");
        
        return 0;
    }
    int* ptr;
    //this will be user input
    int n =atoi(argv[1]);
    if (n <=9 && n>0){
        int i;
        for(i =0; i<9;i++){
            if(n==0){
                break;
            }
            ptr = &peg1[i]; 
            *(peg1+i) = n;
            --n;

        }
        displaypegs();
        int nod = atoi(argv[1]);
        hantow(nod,peg1,peg2,peg3);
        printf("Done\n");
        return 0;
    }
    else{
        printf("Incorrect argument \n");

        return 0;

    } 
}