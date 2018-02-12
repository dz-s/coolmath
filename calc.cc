#include <nan.h>

double truncate(double d, unsigned int precision)
{
    double f = pow(10, precision);
    return ((long int)(d * f)) / f;
}

NAN_METHOD(div)
{
    if (!info[0]->IsNumber() || !info[1]->IsNumber())
    {
        Nan::ThrowTypeError("arguments must be a number!");
        return;
    }

    double a = (double)info[0]->NumberValue();
    double b = (double)info[1]->NumberValue();
    unsigned int precision = (unsigned int)info[2]->NumberValue();

    info.GetReturnValue().Set(truncate((double)(a / b), precision));
}

NAN_METHOD(mult)
{
    if (!info[0]->IsNumber() || !info[1]->IsNumber())
    {
        Nan::ThrowTypeError("arguments must be a number!");
        return;
    }

    double a = (double)info[0]->NumberValue();
    double b = (double)info[1]->NumberValue();
    unsigned int precision = (unsigned int)info[2]->NumberValue();

    info.GetReturnValue().Set(truncate((double)(a * b), precision));
}

NAN_MODULE_INIT(Initialize)
{
    NAN_EXPORT(target, div);
}

NODE_MODULE(addon, Initialize);
