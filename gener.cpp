#include <cstdio>
#include <cstdlib>
#include <ctime>
#define ran(x) (rand()%x)
int n,m;
char str[100];
int main(int argc, char const *argv[])
{                  
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    scanf("%s", str);                                   
    FILE *file = fopen(str, "w");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fprintf(file, "%d ", ran(100));
        }
        fprintf(file,"\n");
    }
    return 0;
}
