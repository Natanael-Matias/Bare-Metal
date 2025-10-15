#include <stdint.h>
#include <stdio.h>

uint32_t d_count = 300000;

int g_un_data1;
int g_un_data2 = 0;
int g_i_data = 0x55;
static int g_un_s_data;
static int g_i_s_data = 0x44;

int main(void){
    printf("data = %d, %d, %d, %d, %d\n", g_un_data1, g_un_data2, g_i_data, g_un_s_data, g_i_s_data);

    int l_un_data;
    int l_i_data = 0x98;
    static int l_un_s_data;
    static int l_i_s_data = 0x24;

    printf("sum = %d\n", l_un_data+l_i_data+l_un_s_data+l_i_s_data);
}