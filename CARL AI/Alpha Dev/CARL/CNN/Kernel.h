#pragma once
#include "../Types/Activation.h"
#include <vector>
#include <string>

const std::string filterString[] = { "ONExONE", "ONExTHREE", "ONExN", "THREExONE", "NxONE", "THREExTHREE", "FIVExFIVE", "SEVENxSEVEN", "ELEVENxELEVEN" };
const std::string filterStyleString[] = { "Ascending", 
                                          "Negative Gradient", 
                                          "Gradient", 
                                          "Vertical Gradient", 
                                          "Inverse Gradient", 
                                          "Vertical Inverse Gradient", 
                                          "Top Left Gradient", "Bottom_Left_Gradiant", 
                                          "Guassian", 
                                          "Balanced Gaussian",
                                          "Negative Guassian",
                                          "Modified Guassian",
                                          "Conical" };

typedef enum FilterDimensions {
        ONExONE,
        ONExTHREE,
        ONExN,
        THREExONE,
        NxONE,
        THREExTHREE,
        FIVExFIVE,
        SEVENxSEVEN,
        ELEVENxELEVEN
} FilterDimensions;

typedef enum FilterStyle {
        ASCENDING_FILTER,
        NEGATIVE_ASCENDING_FILTER,
        GRADIENT_FILTER,
        VERTICAL_GRADIENT_FILTER,
        INVERSE_GRADIENT_FILTER,
        VERTICAL_INVERSE_GRADIENT_FILTER,
        TOP_LEFT_GRADIENT_FILTER,
        BOTTOM_LEFT_GRADIENT_FILTER,
        GAUSSIAN_FILTER,
        BALANCED_GAUSSIAN_FILTER,
        NEGATIVE_GAUSSIAN_FILTER,
        MODIFIED_GAUSSIAN_FILTER,
        CONICAL_FILTER
} FilterStyle;

typedef struct Filter {
    std::vector<std::vector<float>> weights;
    int rows = 0;
    int columns = 0;
} Filter;


class Kernel {
    public:
        Kernel();
        Kernel(Activation);
        Kernel(FilterStyle);
        Kernel(Activation, FilterStyle);
        Kernel(FilterDimensions);
        Kernel(FilterDimensions, FilterStyle);
        Kernel(FilterDimensions, int);
        Kernel(FilterDimensions, int, FilterStyle);
        Kernel(Activation, FilterDimensions);
        Kernel(Activation, FilterDimensions, int);
        Kernel(Activation, FilterDimensions, FilterStyle);
        Kernel(Activation, FilterDimensions, int, FilterStyle);

        ~Kernel();

        void print();
        int getRows();
        int getColumns();
        FilterDimensions getDimensions();
        std::vector<std::vector<float>> getWeights();
        Activation getActivationType();
        FilterStyle getFilterStyle();
        void setStride(int);
        void setFilterStyle(FilterStyle);
        void setFilterDimensions(FilterDimensions);
        void setFilterDimensions(FilterDimensions, int);
        void setActivationType(Activation);
        void adjustDimensions(FilterDimensions);
        void adjustDimensions(FilterDimensions, int);
        float getMax(std::vector<std::vector<float>>);
        float getMaxMean(std::vector<std::vector<float>>);
        float getProductSum(std::vector<std::vector<float>>);
        float getSum(std::vector<std::vector<float>>);
        float getSumMean(std::vector<std::vector<float>>);
        float getMeanSum(std::vector<std::vector<float>>);
        float getMean(std::vector<std::vector<float>>);

    private:
        void populateFilter(FilterStyle);
        int stride = 0;
        Filter filter;
        FilterStyle style;
        FilterDimensions dimensions;
        Activation activation_type;
};