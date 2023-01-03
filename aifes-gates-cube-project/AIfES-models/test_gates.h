/**
  ******************************************************************************
  * @file           : test_gates.c
  * @brief          : Test neural networks, trained to represent logical gates.
  * @author			: paspf
  * @date			: 2023-01-02
  * @copyright		: paspf, GNU General Public License v3.0
  ******************************************************************************
  */

#ifndef TEST_GATES_G
#define TEST_GATES_G


void test_gates();

void test_and_gate_f32();
void test_nor_gate_f32();
void test_or_gate_f32();
void test_xnor_gate_f32();
void test_xor_gate_f32();

void test_and_gate_q7();
void test_nor_gate_q7();
void test_or_gate_q7();
void test_xnor_gate_q7();
void test_xor_gate_q7();


int float_prediction_to_binary_int(const float prediction);
int print_single_prediction(const float *x_input, const int y_ref, const int y_pred);
int predict(void (*model_inference)(float*, float *), const int* output_data_reference);

#endif // TEST_GATES_G
