/**
  ******************************************************************************
  * @file           : test_gates.c
  * @brief          : Test neural networks, trained to represent logical gates.
  * @author			: paspf
  * @date			: 2023-04-01
  * @copyright		: paspf, GNU General Public License v3.0
  ******************************************************************************
  */

#include "test_gates.h"

#include "AIfES-and-gate-float/aifes_e_f32_fnn.h"
#include "AIfES-and-gate-q7/aifes_e_q7_fnn.h"
#include "AIfES-nor-gate-float/aifes_e_f32_fnn.h"
#include "AIfES-nor-gate-q7/aifes_e_q7_fnn.h"
#include "AIfES-or-gate-float/aifes_e_f32_fnn.h"
#include "AIfES-or-gate-q7/aifes_e_q7_fnn.h"
#include "AIfES-xnor-gate-float/aifes_e_f32_fnn.h"
#include "AIfES-xnor-gate-q7/aifes_e_q7_fnn.h"
#include "AIfES-xor-gate-float/aifes_e_f32_fnn.h"
#include "AIfES-xor-gate-q7/aifes_e_q7_fnn.h"

/* Test data */
const uint32_t len_input_data = 4;
float input_data[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };

/* Reference output data */
const int output_data_and_gate[] = { 0, 0, 0, 1 };
const int output_data_nor_gate[] = { 1, 1, 1, 0 };
const int output_data_or_gate[] = { 0, 1, 1, 1 };
const int output_data_xor_gate[] = { 0, 1, 1, 0 };
const int output_data_xnor_gate[] = { 1, 0, 0, 1 };

/**
 * @fn void test_gates()
 * @brief Run tests for all gates.
 *
 */
void test_gates()
{
    test_and_gate_f32();
    test_and_gate_q7();
    test_nor_gate_f32();
    test_nor_gate_q7();
    test_or_gate_f32();
    test_or_gate_q7();
    test_xnor_gate_f32();
    test_xnor_gate_q7();
    test_xor_gate_f32();
    test_xor_gate_q7();
}

/**
 * @fn void test_and_gate_f32()
 * @brief Run predictions on the and gate model.
 *
 */
void test_and_gate_f32()
{
    printf("test_and_gate_f32\n");
    predict(aifes_e_and_gate_f32_fnn_inference, output_data_and_gate);
}

/**
 * @fn void test_and_gate_q7()
 * @brief Run predictions with q7 quantization on the and gate model.
 *
 */
void test_and_gate_q7()
{
    printf("test_and_gate_q7\n");
    predict(aifes_e_and_gate_q7_fnn_inference, output_data_and_gate);
}

/**
 * @fn void test_nor_gate_f32()
 * @brief Run predictions on the nor gate model.
 *
 */
void test_nor_gate_f32()
{
    printf("test_nor_gate_f32\n");
    predict(aifes_e_nor_gate_f32_fnn_inference, output_data_nor_gate);
}

/**
 * @fn void test_nor_gate_q7()
 * @brief Run predictions with q7 quantization on the nor gate model.
 *
 */
void test_nor_gate_q7()
{
    printf("test_nor_gate_q7\n");
    predict(aifes_e_nor_gate_q7_fnn_inference, output_data_nor_gate);
}

/**
 * @fn void test_or_gate_f32()
 * @brief Run predictions on the or gate model.
 *
 */
void test_or_gate_f32()
{
    printf("test_or_gate_f32\n");
    predict(aifes_e_or_gate_f32_fnn_inference, output_data_or_gate);
}

/**
 * @fn void test_or_gate_q7()
 * @brief Run predictions with q7 quantization on the or gate model.
 *
 */
void test_or_gate_q7()
{
    printf("test_or_gate_q7\n");
    predict(aifes_e_or_gate_q7_fnn_inference, output_data_or_gate);
}

/**
 * @fn void test_xnor_gate_f32()
 * @brief  Run predictions on the xnor gate model.
 *
 */
void test_xnor_gate_f32()
{
    printf("test_xnor_gate_f32\n");
    predict(aifes_e_xnor_gate_f32_fnn_inference, output_data_xnor_gate);
}

/**
 * @fn void test_xnor_gate_q7()
 * @brief Run predictions with q7 quantization on the xnor gate model.
 *
 */
void test_xnor_gate_q7()
{
    printf("test_xnor_gate_q7\n");
    predict(aifes_e_xnor_gate_q7_fnn_inference, output_data_xnor_gate);
}

/**
 * @fn void test_xor_gate_f32()
 * @brief Run predictions on the xor gate model.
 *
 */
void test_xor_gate_f32()
{
    printf("test_xor_gate_f32\n");
    predict(aifes_e_xor_gate_f32_fnn_inference, output_data_xor_gate);
}

/**
 * @fn void test_xor_gate_q7()
 * @brief Run predictions with q7 quantization on the xor gate model.
 *
 */
void test_xor_gate_q7()
{
    printf("test_xor_gate_q7\n");
    predict(aifes_e_xor_gate_q7_fnn_inference, output_data_xor_gate);
}


/**
 * @fn int float_prediction_to_binary_int(float)
 * @brief Convert float value to binary int value (0 or 1).
 * If prediction > 0.5 -> return 1
 * Else -> return 0
 *
 * @param prediction Float value to convert.
 * @return Int value, 0 or 1.
 */
int float_prediction_to_binary_int(const float prediction) {
    if (prediction > 0.5) {
        return 1;
    }
    return 0;
}

/**
 * @fn void print_single_prediction(float*, int, int)
 * @brief Print out a single prediction.
 *
 * @param x_input x-network input.
 * @param y_ref   y-network reference.
 * @param y_pred_float  y-network output as float.
 * @param y_pred_int y-network output as int.
 * @return 1 if y_pred matches y_ref.
 */
int print_single_prediction(const float *x_input, const int y_ref, const float y_pred_float, const int y_pred_int) {
    if (y_ref == y_pred_int) {
        printf("|[%.1f, %.1f]|[%d]| -> %f -> Pass\n", x_input[0], x_input[1],
                y_ref, y_pred_float);
        return 1;
    }
    printf("|[%.1f, %.1f]|[%d]| -> %f -> Fail\n", x_input[0], x_input[1],
            y_ref, y_pred_float);
    return 0;
}

/**
 * @fn predict
 * @brief predict_f32 Perform predictions for all entries in the input_data dataset using the given model.
 * @param model_inference model inference function, generated by AIfES converter.
 * @param output_data_reference Reference output data.
 * @return 1 if all predictions match the reference in the test data set.
 */
int predict(void (*model_inference)(float*, float *), const int* output_data_reference) {
    int ret = 1;
    // Iterate through all rows in the input data set.
    for (uint32_t i = 0; i < len_input_data; i++) {
        // Perform prediction.
        float y_pred;
        model_inference(input_data[i], &y_pred);

        int y_int = float_prediction_to_binary_int(y_pred);
        if (print_single_prediction(input_data[i], output_data_reference[i], y_pred, y_int) == 0) {
            // Set return value to 0 if a prediction does not match its reference.
            ret = 0;
        }
    }
    return ret;
}

