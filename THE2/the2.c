#include <stdio.h>
#include <stdlib.h>

int transform_name(const char *name)
{
    int i=0,sum=0;
    while(name[i] != '\0')
    {
        sum += (i+1) * (i+1) * (int) name[i];
        i++;
    }
    return sum;
}

int** initialize_storage(int IA_size, int DA_size, int** DA_sizes)
{
    int** storage = (int**) calloc(IA_size, sizeof(int*));
    int i;
    
    
    
    for (i = 0; i < IA_size; i++) 
    {
        storage[i] = (int*) calloc(DA_size, sizeof(int));
    }
    
    *DA_sizes = (int*) calloc(IA_size, sizeof(int));
    
    for (i = 0; i < IA_size; i++) 
    {
        (*DA_sizes)[i] = DA_size;
    }
    return storage;
}

void print_storage(int** storage, int IA_size, int* DA_sizes)
{
    int i,k;
    for(i=0; i < IA_size; i++)
    {
        printf("%d ->",i);
        for(k = 0; k < DA_sizes[i]; k++)
        {
            printf(" %d",storage[i][k]);
        }
        printf("\n");
    }
}

void insert(int** storage, int IA_size, const char* name, int* DA_sizes)
{
    int i=0;
    int ncode = transform_name(name);
    int index = ncode % IA_size;
    if(storage[index][DA_sizes[index]-1] != 0)
    {
        DA_sizes[index] *= 2;
        storage[index] = (int*) realloc(storage[index],DA_sizes[index] * sizeof(int));
        for (i = DA_sizes[index] / 2; i < DA_sizes[index]; i++)
        {
            storage[index][i] = 0;
        }
    }
    
    for(i = 0;;i++)
    {
        if(storage[index][i] == 0) 
        {
            storage[index][i] = ncode;
            break;
        }
    }
    
}

void insert2(int** storage, int IA_size, int name_code, int* DA_sizes)
{
    int i=0;
    int index = name_code % IA_size;
    if(storage[index][DA_sizes[index]-1] != 0)
    {
        DA_sizes[index] *= 2;
        storage[index] = (int*) realloc(storage[index],DA_sizes[index] * sizeof(int));
        for (i = DA_sizes[index] / 2; i < DA_sizes[index]; i++)
        {
            storage[index][i] = 0;
        }
    }
    
    for(i = 0;;i++)
    {
        if(storage[index][i] == 0) 
        {
            storage[index][i] = name_code;
            break;
        }
    }
}

void fill_new_storage(int** storage, int IA_size, int** new_storage, int *DA_sizes, int** new_DA_sizes)
{
    int i,j;
    for(i = 0; i < IA_size; i++)
    {
        for(j = 0; j < DA_sizes[i]; j++)
        {
            if (storage[i][j] != 0) insert2(new_storage, IA_size*2, storage[i][j], *new_DA_sizes);
        }
    }
    
}

void resize_IA(int*** storage, int* IA_size, int DA_size, int** DA_sizes)
{
    int sum = 0, i = 0;
    for(; i < (*IA_size); i++)
    {
        sum += (*DA_sizes)[i];
    }
    
    if((*IA_size) * DA_size * 1.5 <= sum)
    {
        int* yeni_DA_sizes;
        int** temp_storage;
        temp_storage = initialize_storage(2 * (*IA_size), DA_size, &yeni_DA_sizes);
        fill_new_storage(*storage, *IA_size, temp_storage, *DA_sizes, &yeni_DA_sizes);
        
        for(i = 0; i < (*IA_size); i++)
        {
            free((*storage)[i]);
        }
        free(*storage);
        free(*DA_sizes);
        
        *storage = temp_storage;
        *DA_sizes = yeni_DA_sizes;
        *IA_size *= 2;
    }
    
    
}

