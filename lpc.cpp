#include "lpc.h"

LPC::LPC(float fs, float fc) {
    _fs = fs;
    _fc = fc;
    _past_val = 0.;
    _alpha = 1.;
    calcul_alpha();
}

LPC::~LPC() {}

void LPC::calcul_alpha() {
    const float k = 2. * PI * _fc / _fs;
    _alpha = cos(k) - 1. + sqrt(cos(k) * cos(k) - 4. * cos(k) + 3. );
}

void LPC::filter(float& val) {
    val = _alpha * val + (1 - _alpha) * _past_val;
    _past_val = val;
}