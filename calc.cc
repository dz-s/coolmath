#include <nan.h>

double TruncateNumber(double In, unsigned int Digits)
{
    double f = pow(10, Digits);
    return ((int)(In * f)) / f;
}

NAN_METHOD(Div)
{
    if (!info[0]->IsNumber() || !info[1]->IsNumber())
    {
        Nan::ThrowTypeError("arguments must be a number!");
        return;
    }

    float a = (float)info[0]->NumberValue();
    float b = (float)info[1]->NumberValue();
    unsigned int precision = (unsigned int)info[2]->NumberValue();

    info.GetReturnValue().Set(TruncateNumber(a / b, precision));
}

NAN_MODULE_INIT(Initialize)
{
    NAN_EXPORT(target, Div);
}

NODE_MODULE(addon, Initialize);
