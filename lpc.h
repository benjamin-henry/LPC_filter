//#ifndef LPC_FILTER_H
// #define LPC_FILTER_H

#include <Arduino.h>

class LPC {
    public:
        LPC(float fs, float fc);
        ~LPC();

        void calcul_alpha();
        void filter(float& val);
    
    private:
        int _fs;
        int _fc;
        float _alpha;
        float _past_val;
};

// #endif