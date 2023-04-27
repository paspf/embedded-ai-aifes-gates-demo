/*
  www.aifes.ai
  https://github.com/Fraunhofer-IMS/AIfES_for_Arduino
  
  You can find more AIfES tutorials here:
  https://create.arduino.cc/projecthub/aifes_team 

  AIfES-Express: Configuration file automatically generated from Keras

  Paste the following code into your project and insert your inputs/features:
  ---------------------------------------------------------------------------  
    float input_data[784]; // AIfES input data
    float output_data[10]; // AIfES output data

    aifes_e_mnist_dense_q7_fnn_inference((float*)input_data,(float*)output_data);
  ---------------------------------------------------------------------------

  Copyright (C) 2022  Fraunhofer Institute for Microelectronic Circuits and Systems.
  All rights reserved.
  AIfES-Converter is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.
  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <aifes.h>
#include "aifes_e_q7_weights.h"

#ifndef AIFES_E_Q7_MNIST_DENSE_FNN
#define AIFES_E_Q7_MNIST_DENSE_FNN

#define DATASETS 1
#define FNN_LAYERS 4

void aifes_e_mnist_dense_q7_fnn_inference(float* input_data, float* output_data)
{
  uint32_t FNN_structure[FNN_LAYERS] = {784, 32, 16, 10};
  
  uint16_t input_shape[] = {DATASETS, (uint16_t)FNN_structure[0]};
  aitensor_t input_tensor = AITENSOR_2D_F32(input_shape, input_data);    

  uint16_t output_shape[] = {DATASETS, (uint16_t)FNN_structure[FNN_LAYERS - 1]};    // Definition of the output shape
  aitensor_t output_tensor = AITENSOR_2D_F32(output_shape, output_data);
  
  AIFES_E_activations FNN_activations[] = {AIfES_E_relu, AIfES_E_relu, AIfES_E_softmax};
  
  AIFES_E_model_parameter_fnn_f32 FNN;
  FNN.layer_count = FNN_LAYERS;
  FNN.fnn_structure = FNN_structure;
  FNN.fnn_activations = FNN_activations;
  FNN.flat_weights = (void*) model_mnist_dense_parameters;

  AIFES_E_inference_fnn_q7(&input_tensor,&FNN,&output_tensor);
}

#endif // AIFES_E_F32_FNN
