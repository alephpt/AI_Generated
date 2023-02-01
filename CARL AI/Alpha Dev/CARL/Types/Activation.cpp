#include "Activation.h"
#include <math.h>
#include <stdio.h>

static const float pi = 3.1415926f;

// SIGMOIDS //
static inline float sigmoid(float x) {
    return 1.0f / (1.0f + expf(-x));
}

static inline float sigmoid_derivative(float x) {
    float s = sigmoid(x);
    return s * (1.0f - s);
}


// TANH //

static inline float tanh_activation(float x) {
    return (expf(x) - expf(-x)) / (expf(x) + expf(-x));
}

static inline float tanh_derivative(float x) {
    return 1.0f - powf(tanh_activation(x), 2.0f);
}


// RELU //
static inline float relu(float x) {
    if (x < 0) { return 0.0f; }
    return x;
}

static inline float relu_derivative(float x) {
    if (x < 0) { return 0.0f; }
    return 1.0f;
}


// LEAKY_RELU //

static inline float leaky_relu(float x, float alpha) {
    if (x > 0) { return x; }
    else { return alpha * x; }
}

static inline float leaky_relu_derivative(float x, float alpha) {
    if (x > 0) { return 1.0f; }
    else { return alpha; }
}



 // SOFTPLUS //
static inline float softplus(float x) {
    return logf(1.0f + expf(x));
}


static inline float softplus_derivative(float x) {
    return 1.0f / (1.0f + expf(-x));
}

// SOFTMAX //

static inline float softmax(float x) {
    return expf(x) / (expf(x) + 1.0f);
}

static inline float softmax_derivative(float x) {
    float s = softmax(x);
    return s * (1.0f - s);
}



 // GAUSSIAN //

static inline float gaussian(float x) {
    float mean = 0.0f;
    float standard_deviation = 1.0f;

    return (1.0f / (standard_deviation * sqrtf(2.0f * pi))) * expf(-0.5f * powf((x - mean) / standard_deviation, 2.0f));
}

static inline float gaussian_derivative(float x) {
    return -x * expf(-x * x / 2.0f) / sqrtf(2.0f * pi);
}

// ACTIVATION FUNCTIONS //

float activation(Activation activation_type, float output) {
    if (activation_type == SIGMOID_DERIVATIVE) {
        return sigmoid_derivative(output);
    }
    else if (activation_type == TANH_DERIVATIVE) {
        return tanh_derivative(output);;
    }
    else if (activation_type == RELU_DERIVATIVE) {
        return relu_derivative(output);
    }
    else if (activation_type == LEAKY_RELU_DERIVATIVE) {
        return leaky_relu_derivative(output, 0.01f);
    }
    else if (activation_type == SOFTPLUS_DERIVATIVE) {
        return softplus_derivative(output);
    }
    else if (activation_type == SOFTMAX_DERIVATIVE) {
        return softmax_derivative(output);
    }
    else if (activation_type == GAUSSIAN_DERIVATIVE) {
        return gaussian_derivative(output);
    } else
    if (activation_type == SIGMOID) {
        return sigmoid(output);
    }
    else if (activation_type == TANH) {
        return tanh_activation(output);;
    }
    else if (activation_type == RELU) {
        return relu(output);
    }
    else if (activation_type == LEAKY_RELU) {
        return leaky_relu(output, 0.01f);
    }
    else if (activation_type == SOFTPLUS) {
        return softplus(output);
    }
    else if (activation_type == SOFTMAX) {
        return softmax(output);
    }
    else if (activation_type == GAUSSIAN) {
        return gaussian(output);
    }
    else {
        printf("ACTIVATION ERROR: Invalid activation type\n");
        return 0;
    }
}

