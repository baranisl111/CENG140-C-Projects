#include <stdio.h>
#include <string.h>

void slice(const char source[], int start, int end, char result[]) {
    int length = strlen(source);
    int i, j = 0;

    if (start < 0) {
        start = length + start;
        if (start < 0) start = 0;
    }
    if (end < 0) {
        end = length + end;
        if (end < 0) end = 0;
    }

    if (end > length) end = length;

    for (i = start; i < end; i++) {
        result[j++] = source[i];
    }
    result[j] = '\0'; 
}


char eslestirici(char char1,char char2,char char3)
{
    char array[4] = "";
    array[0] = char1;
    array[1] = char2;
    array[2] = char3;
    array[3] = '\0';
    if(strcmp(array,"UUU")==0 || strcmp(array,"UUC")==0) return 'f';
    else if(strcmp(array,"UUA")==0 || strcmp(array,"UUG")==0 || strcmp(array,"CUU")==0 || strcmp(array,"CUC")==0 || strcmp(array,"CUA")==0 || strcmp(array,"CUG")==0) return 'l';
    else if(strcmp(array,"AUU")==0 || strcmp(array,"AUC")==0 || strcmp(array,"AUA")==0) return 'i';
    else if(strcmp(array,"AUG")==0) return 'm';
    else if(strcmp(array,"GUU")==0 || strcmp(array,"GUC")==0 || strcmp(array,"GUA")==0 || strcmp(array,"GUG")==0) return 'v';
    else if(strcmp(array,"UCU")==0 || strcmp(array,"UCC")==0 || strcmp(array,"UCA")==0 || strcmp(array,"UCG")==0 || strcmp(array,"AGU")==0 || strcmp(array,"AGC")==0) return 's';
    else if(strcmp(array,"CCU")==0 || strcmp(array,"CCC")==0 || strcmp(array,"CCA")==0 || strcmp(array,"CCG")==0) return 'p';
    else if(strcmp(array,"ACU")==0 || strcmp(array,"ACC")==0 || strcmp(array,"ACA")==0 || strcmp(array,"ACG")==0) return 't';
    else if(strcmp(array,"GCU")==0 || strcmp(array,"GCC")==0 || strcmp(array,"GCA")==0 || strcmp(array,"GCG")==0) return 'a';
    else if(strcmp(array,"UAU")==0 || strcmp(array,"UAC")==0) return 'y';
    else if(strcmp(array,"CAU")==0 || strcmp(array,"CAC")==0) return 'h';
    else if(strcmp(array,"CAA")==0 || strcmp(array,"CAG")==0) return 'q';
    else if(strcmp(array,"AAU")==0 || strcmp(array,"AAC")==0) return 'n';
    else if(strcmp(array,"AAA")==0 || strcmp(array,"AAG")==0) return 'k';
    else if(strcmp(array,"GAU")==0 || strcmp(array,"GAC")==0) return 'd';
    else if(strcmp(array,"GAA")==0 || strcmp(array,"GAG")==0) return 'e';
    else if(strcmp(array,"UGU")==0 || strcmp(array,"UGC")==0) return 'c';
    else if(strcmp(array,"UGG")==0) return 'w';
    else if(strcmp(array,"CGU")==0 || strcmp(array,"CGC")==0 || strcmp(array,"CGA")==0 || strcmp(array,"CGG")==0 || strcmp(array,"AGA")==0 || strcmp(array,"AGG")==0) return 'r';
    else if(strcmp(array,"GGU")==0 || strcmp(array,"GGC")==0 || strcmp(array,"GGA")==0 || strcmp(array,"GGG")==0) return 'g';
    else return 'X';
}

int kontroldeg1=0;
int intron1i,intron1f,intron2i,intron2f;

void kontrol(char nuk[],char prot[])
{
    int lennukle=strlen(nuk),lenprot=strlen(prot);
    int a,b,c=0;
    while(lennukle >= 3*lenprot)
    {
        a=c;
        b=0;
        while(eslestirici(nuk[a],nuk[a+1],nuk[a+2])==prot[b] && lenprot > b)
        {
            if(prot[b+1]=='\0')
            {
                kontroldeg1 = 1;
                intron1f = c;
                intron2i = 3*lenprot+1;
                break;
            }
            a+=3;
            b+=1;
        }
        if(kontroldeg1==1) break;
        
        lennukle-=1;
        c+=1;

    }
}


int main() 
{
    int kontrolforeslestirici=0;
    char gene_input[3010]="";
    char protein_input[2910]="";
    int i=0,j=0,k=0;
    int a=3,b=0,c=0,d,e,f,g;
    char gene_input_conv[3010]="";
    int len;
    char bas,son;
    int lengen,lenpro;
    char nuk[3010];
    char pro[2910];
    int stopkod;
    
    while(1)
    {
        scanf("%c",&gene_input[i]);
        if(gene_input[i]== '.') break;
        if(gene_input[i] != 'T'&& gene_input[i] != 'A' && gene_input[i] != 'C' &&gene_input[i] != 'G') continue;
        i+=1;
    }
    while(1)
    {
        scanf("%c",&protein_input[j]);
        if(protein_input[j]== '.') break;
        if(protein_input[j]== ' ' || protein_input[j]== '\n') continue;
        j+=1;
    }
    
    
    while(gene_input[k] != '.')
    {
        if(gene_input[k]=='A') gene_input_conv[k]='U';
        if(gene_input[k]=='C') gene_input_conv[k]='G';
        if(gene_input[k]=='G') gene_input_conv[k]='C';
        if(gene_input[k]=='T') gene_input_conv[k]='A';
        k+=1;
    }
    
    protein_input[strlen(protein_input)-1] = '\0';
    len = strlen(gene_input_conv);
    if(gene_input_conv[len-3]=='U' && gene_input_conv[len-2]=='A' && (gene_input_conv[len-1]=='A' || gene_input_conv[len-1]=='G')) 
    {gene_input_conv[len-3]='\0'; len -= 3;stopkod=1;}
    if(gene_input_conv[len-3]=='U' && gene_input_conv[len-2]=='G' && gene_input_conv[len-1]=='A')
    {gene_input_conv[len-3]='\0'; len -= 3;stopkod=1;}
    
    bas = eslestirici(gene_input_conv[0],gene_input_conv[1],gene_input_conv[2]);
    son = eslestirici(gene_input_conv[len-3],gene_input_conv[len-2],gene_input_conv[len-1]);
    
    if(bas != protein_input[0] || son != protein_input[strlen(protein_input)-1] || stopkod==0) printf("NONE");
    else
    {
        lengen=strlen(gene_input_conv);
        lenpro=strlen(protein_input);
        while(lenpro>=a)
    {
        
        if(eslestirici(gene_input_conv[b],gene_input_conv[b+1],gene_input_conv[b+2]) == protein_input[c])
        {
            
            strcpy(nuk,"");
            strcpy(pro,"");
            slice(gene_input_conv,b+4,-4,nuk);
            slice(protein_input,c+1,-1,pro);
            kontrol(nuk,pro);
            if(kontroldeg1==1) break;
            
        }
        else
        {
            kontrolforeslestirici=1;
            break;
        }
        if(kontroldeg1==1) break;
        a+=1;
        b+=3;
        c+=1;
    }
    if(kontroldeg1==1)
    {
        intron1i=b+3;
        intron1f+=intron1i;
        intron2i+=intron1f;
        intron2f=lengen-4;
        printf("%d %d %d %d",intron1i,intron1f,intron2i,intron2f);

    }
    else
    {
    if(kontrolforeslestirici == 0)
    {
        a=4;
        b=6;
        c=2;
        while(lenpro >=a && eslestirici(gene_input_conv[lengen-b],gene_input_conv[lengen-(b-1)],gene_input_conv[lengen-(b-2)])==protein_input[lenpro-c])
        {
            d=0;
            e=0;
            f=a;
            while(lenpro>=f)
            {
                if(eslestirici(gene_input_conv[d],gene_input_conv[d+1],gene_input_conv[d+2]) == protein_input[e])
                {
                    strcpy(nuk,"");
                    strcpy(pro,"");
                    slice(gene_input_conv,d+4,-3*(a-2)-1,nuk);
                    slice(protein_input,e+1,-(a-2),pro);
                    kontrol(nuk,pro);
                    if(kontroldeg1==1)
                    {
                        intron1i=d+3;
                        intron1f+=intron1i;
                        intron2i+=intron1f;
                        intron2f=lengen-3*(a-2)-1;
                        printf("%d %d %d %d",intron1i,intron1f,intron2i,intron2f);
                        break;
                    }     
                }
                f+=1;
                d+=3;
                e+=1;

            }
            if(kontroldeg1==1)break;
            a+=1;
            b+=3;
            c+=1;
        }
        if(kontroldeg1==0) printf("NONE");
    }
    else if(kontrolforeslestirici==1)
    {
        d=6;
        e=2;
        f=3*c+1;
        g=c;

        while (lenpro >= c+3 && eslestirici(gene_input_conv[lengen-d],gene_input_conv[lengen-(d-1)],gene_input_conv[lengen-(d-2)])==protein_input[lenpro-e])
        {
            strcpy(nuk,"");
            strcpy(pro,"");
            slice(gene_input_conv,f,-(3*e+1),nuk);
            slice(protein_input,g,-e,pro);
            kontrol(nuk,pro);
            if(kontroldeg1==1)
            {
                intron1i=f-1;
                intron1f+=intron1i;
                intron2i+=intron1f;
                intron2f=lengen-d-1;
                printf("%d %d %d %d",intron1i,intron1f,intron2i,intron2f);
                break;
            }
            c+=1;
            d+=3;
            e+=1;
        }
        if(kontroldeg1==0) printf("NONE");
        
    }
    
    }
        
    }
    
    
    return 0;
}