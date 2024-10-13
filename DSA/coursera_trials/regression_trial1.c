#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float w = 0, b = 0;

float predict(int x){
    return w*x + b;
}

float cost_function(int* arr_x, int* arr_y, int m){
    float sum = 0;
    for(int i = 0; i < m; i++)
        sum += pow(predict(arr_x[i]) - arr_y[i], 2);
    return (1.0 / (2 * m)) * sum;
}

void opt_gradient_descent(int *arr_x, int* arr_y, int m, float alpha){
    float derivative_w = 0, derivative_b = 0;
    for(int i = 0; i < m; i++)
        derivative_w += (predict(arr_x[i]) - arr_y[i]) * arr_x[i];
    derivative_w = derivative_w / m;

    for(int i = 0; i < m; i++)
        derivative_b += (predict(arr_x[i]) - arr_y[i]);
    derivative_b = derivative_b / m;

    w -= alpha * derivative_w;
    b -= alpha * derivative_b;
}

void update(int* arr_x, int* arr_y, int m, float alpha){
    float prev_w, prev_b;
    float current_cost = cost_function(arr_x, arr_y, m);
    
    while(true){
        prev_w = w;
        prev_b = b;

        opt_gradient_descent(arr_x, arr_y, m, alpha);

        float new_cost = cost_function(arr_x, arr_y, m);
        if (new_cost >= current_cost){
            w = prev_w;
            b = prev_b;
            break;
        }
        current_cost = new_cost;
    }
}

int main(){
    int X_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Y_arr[10] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 10};

    float alpha = 0.05;

    update(X_arr, Y_arr, 10, alpha);
    float num = predict(5);
    printf("Prediction for x=11: %f\n", num);
    printf("f(x) = (%f)*x + (%f)",w,b);

    return 0;
}
