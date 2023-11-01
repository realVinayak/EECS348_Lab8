#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MONTH 12;
char *month_array[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

float *read_file(){
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    float *return_nums = (float*)malloc(sizeof(float)*12);
    int month_counter = 0;
    while (fscanf(fptr, "%f", return_nums + ((month_counter++))) && (month_counter <= 12));
    fclose(fptr);
    return return_nums;
}

void print_sales_report(const float * month_nums, int print_summary, char *msg, char *month[12]){
    printf("%s\n", msg);
    float sum = 0;
    float minimum = *month_nums;
    float maximum = 0;
    int month_counter = 0;
    printf("Month\tSales\n");
    int min_month =0;
    int max_month = 0;
    for (month_counter = 0; month_counter < 12; month_counter++){
        float current_val = *(month_nums + month_counter);
        printf("%s\t%f\n", month[month_counter], current_val);
        if (minimum > current_val){
            minimum = current_val;
            min_month = month_counter;
        }
        if (maximum < current_val){
            maximum = current_val;
            max_month = month_counter;
        }
        sum += *(month_nums + month_counter);
    }
    if (print_summary) {
        printf("Sales summary: \n");
        printf("Minimum sales: $%f\t (%s)\n", minimum, *(month + min_month));
        printf("Maximum sales: $%f\t(%s)\n", maximum, *(month + max_month));
        printf("Average sales: $%f\n", sum / 12);
    }
}

void print_sales_report_moving_average(const float * month_nums){
    int WINDOW = 6;
    printf("Six-Month Moving Average Report:\n");
    int window_start = 0;
    int window_stop = WINDOW;
    while (window_stop < 12){
        int _counter;
        float sum = 0;
        for (_counter = window_start; _counter < window_stop; _counter++){
            sum += *(month_nums + _counter);
        }
        printf("%s\t-\t%s\t%f\n",  *(month_array + window_start), *(month_array + window_stop), sum);
        window_start += 1;
        window_stop += 1;
    }
}
void printed_sort(float * month_nums){
    int num_pass = 11;
    int pass_counter = 0;
    char *_month_array[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (pass_counter = 0; pass_counter < num_pass; pass_counter++){
        int index = 0;
        for (index = 0; index <= num_pass - pass_counter - 1; index++){
            float current = month_nums[index];
            float next = month_nums[index+1];
            if (next > current) {
                *(month_nums + index + 1) = current;
                *(month_nums + index) = next;
                char *current_month = _month_array[index];
                _month_array[index] = _month_array[index+1];
                _month_array[index+1] = current_month;
            }
        }
    }
    print_sales_report(month_nums, 0, "Monthly Sales Report (Highest to Lowest)", _month_array);
}
int main(){
    float *month_nums = read_file();
    print_sales_report(month_nums, 1, "Monthly Sales Report", month_array);
    print_sales_report_moving_average(month_nums);
    printed_sort(month_nums);
    return 0;
}
