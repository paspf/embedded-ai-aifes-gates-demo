/**
  ******************************************************************************
  * @file           : test_mnist.c
  * @brief          : Test neural networks, trained to represent logical gates.
  * @author			: paspf
  * @date			: 2023-04-01
  * @copyright		: paspf, GNU General Public License v3.0
  ******************************************************************************
  */

#include "test_mnist.h"
#include "AIfES-mnist-dense-q7/aifes_e_q7_fnn.h"

const uint32_t len_input_data = 4;
extern float mnist_number_0[784];
extern float mnist_number_1[784];
extern float mnist_number_2[784];
extern float mnist_number_3[784];
extern float mnist_number_4[784];
extern float mnist_number_5[784];
extern float mnist_number_6[784];
extern float mnist_number_7[784];
extern float mnist_number_8[784];
extern float mnist_number_9[784];
static const size_t y_pred_len = 10;
static float y_pred[10];

/**
 * @fn argmax(float*, size_t)
 * @brief argmax Returns the indice of the maximum value in arr.
 * @param arr Array.
 * @param len Length of the array.
 * @return Indice of the maximum value.
 */
int argmax(float* arr, size_t len) {
    float max = arr[0];
    int max_index = 0;
    for(size_t i = 0; i < len; i++) {
        if(arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}

/**
 * @fn test_mnist()
 * @brief test_mnist Run mnist tests.
 */
void test_mnist()
{
    test_mnist_dense_q7();
}

/**
 * @fn test_mnist_dense_q7()
 * @brief test_mnist_dense_q7
 * Run a prediction for each number and print the result.
 */
void test_mnist_dense_q7()
{
    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_0, y_pred);
    printf("Reference: %d Predicted: %d\n", 0, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_1, y_pred);
    printf("Reference: %d Predicted: %d\n", 1, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_2, y_pred);
    printf("Reference: %d Predicted: %d\n", 2, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_3, y_pred);
    printf("Reference: %d Predicted: %d\n", 3, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_4, y_pred);
    printf("Reference: %d Predicted: %d\n", 4, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_5, y_pred);
    printf("Reference: %d Predicted: %d\n", 5, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_6, y_pred);
    printf("Reference: %d Predicted: %d\n", 6, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_7, y_pred);
    printf("Reference: %d Predicted: %d\n", 7, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_8, y_pred);
    printf("Reference: %d Predicted: %d\n", 8, argmax(y_pred, y_pred_len));

    aifes_e_mnist_dense_q7_fnn_inference(mnist_number_9, y_pred);
    printf("Reference: %d Predicted: %d\n", 9, argmax(y_pred, y_pred_len));
}



