#pragma once
void printArray(const float*, int);
void inputArray(float*, int);
void saveArrayToFile(const float*, int, FILE*);
void loadArrayFromFile(float* a, int* colCount, FILE* fp);
void print2DArray(const float**, int, int);
void input2DArray(float**, int, int);
float* createDynamicArr(int);
float** create2DynamicArr(int, int);
void save2DArrayToFile(const float**, int, int, FILE*);
void load2DArrayFromFile(float** a, int* rowCount, int* colCount, FILE* fp);
void getArrayDimension(FILE* fp, int* rowCount, int* colCount);